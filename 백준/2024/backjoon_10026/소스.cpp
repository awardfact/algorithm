#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct colorT {
    char x;
    char y;
    char color;


}colort;

int front = -1;
int rear = -1;
colort que[10000];


//�Ϲ� ���
void push(char color, char x, char y) {
    front = ++front % 10000;

    que[front].color = color;
    que[front].x = x;
    que[front].y = y;

}

//�����϶� Ǫ��
void push_color_drug(char color, char x, char y) {

    if (color == 'G') {
        color = 'R';
    }
    front = ++front % 10000;
    que[front].color = color;
    que[front].x = x;
    que[front].y = y;

}



colort pop() {

    if (front != rear) {
        return que[++rear % 10000];
    }

}

//���� �������ִ� �Լ�
char color_drugs_color(char(*color)[101], char x, char y, char color_drug) {

    char color_tmp = color[x][y];

    //�����̸� G�ϋ� R�� �ٲ��ְ� �ƴϸ� �׳� ������
    if (color_drug == 1) {
        if (color_tmp == 'G') {
            color_tmp = 'R';
        }

    }


    return color_tmp;



}


//�ʺ�켱 Ž��  ���� �Լ�
int bfs(int n, char(*visit)[100], char(*color)[101], char color_drug) {

    int i, j;
    colort color_tmp;

    int color_cnt = 0;
    void (*push_func)(char color, char x, char y);
    if (color_drug == 1) {
        push_func = push_color_drug;
    }
    else {
        push_func = push;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            //�湮 ���Ѱ��̸� ť�� ����

            //printf("color : %d %c\n", color[i][j],color[i][j]);
            if (visit[i][j] == 0) {
                color_cnt++;
                //printf("i : %d j : %d color : %c\n", i,j, color[i][j]);
                push_func(color[i][j], i, j);
                visit[i][j] = 1;
                while (front != rear) {
                    color_tmp = pop();
                    //���� ť�� ����

                    //printf("x : %d y :%d color : %c\n", color_tmp.x, color_tmp.y, color_tmp.color);

                    if (color_tmp.x - 1 >= 0 && visit[color_tmp.x - 1][color_tmp.y] == 0 && color_tmp.color == color_drugs_color(color, color_tmp.x - 1, color_tmp.y, color_drug)) {
                        push_func(color[color_tmp.x - 1][color_tmp.y], color_tmp.x - 1, color_tmp.y);
                        visit[color_tmp.x - 1][color_tmp.y] = 1;
                    }

                    //���� ť�� ����
                    if (color_tmp.x + 1 < n && visit[color_tmp.x + 1][color_tmp.y] == 0 && color_tmp.color == color_drugs_color(color, color_tmp.x + 1, color_tmp.y, color_drug)) {
                        push_func(color[color_tmp.x + 1][color_tmp.y], color_tmp.x + 1, color_tmp.y);
                        visit[color_tmp.x + 1][color_tmp.y] = 1;
                    }

                    //���� ť�� ����
                    if (color_tmp.y - 1 >= 0 && visit[color_tmp.x][color_tmp.y - 1] == 0 && color_tmp.color == color_drugs_color(color, color_tmp.x, color_tmp.y - 1, color_drug)) {
                        push_func(color[color_tmp.x][color_tmp.y - 1], color_tmp.x, color_tmp.y - 1);
                        visit[color_tmp.x][color_tmp.y - 1] = 1;
                    }

                    //�Ʒ��� ť�� ����
                    if (color_tmp.y + 1 < n && visit[color_tmp.x][color_tmp.y + 1] == 0 && color_tmp.color == color_drugs_color(color, color_tmp.x, color_tmp.y + 1, color_drug)) {
                        push_func(color[color_tmp.x][color_tmp.y + 1], color_tmp.x, color_tmp.y + 1);
                        visit[color_tmp.x][color_tmp.y + 1] = 1;
                    }
                }

            }
        }
    }


    return color_cnt;



}

int main() {

    int i, n, j;
    char visit[100][100] = { 0, };
    char color[100][101] = { 0, };
    int color_cnt;

    scanf("%d", &n);
    //�� �Է�
    // for(i = 0; i < n; i++){
    //     getchar();
    //     for(j= 0; j < n; j++){
    //         scanf("%c", color[i]);

    //     }
    // }

    for (i = 0; i < n; i++) {
        scanf("%s", color[i]);
    }

    // printf("%d\n", n);
     // for(i = 0; i < n; i++){
     //     for(j = 0; j < n; j++){
     //         printf("%c", color[i][j]);
     //     }
     //     printf("\n");
     // }
    front = -1;
    rear = -1;
    memset(visit, 0, sizeof(char) * 10000);
    color_cnt = bfs(n, visit, color, 0);


    printf("%d ", color_cnt);
    memset(visit, 0, sizeof(char) * 10000);
    front = -1;
    rear = -1;
    color_cnt = bfs(n, visit, color, 1);

    printf("%d\n", color_cnt);




    return 0;
}