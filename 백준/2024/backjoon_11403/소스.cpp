#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int que[10000];
int front = -1;
int rear = -1;

void push(int x) {
    que[++front] = x;


}

int pop() {
    if (front != rear) {
        return que[++rear];
    }
}

int main() {

    int n, i, j;
    char visit[100][100] = { 0, };
    char node[100][100];
    int pop_node;
    scanf("%d", &n);

    //�Է�
    for (i = 0; i < n; i++) {
        getchar();
        for (j = 0; j < n; j++) {
            scanf(" %c", &node[i][j]);
        }
    }


    //�ʺ�켱 Ž�� �����ϸ鼭 ����Ǿ��ִ� ���� 1�� ����
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (visit[i][j] == 0 && node[i][j] == '1') {
                visit[i][j] = 1;
                push(j);
            }
        }

        //i�� �����ߴ� ������ ���� �� ���� ����Ǿ��ִ� ��带 ����
        while (front != rear) {
            pop_node = pop();
            for (j = 0; j < n; j++) {
                if (visit[i][j] == 0 && node[pop_node][j] == '1') {
                    visit[i][j] = 1;
                    push(j);
                }
            }
        }


    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", visit[i][j]);
        }
        printf("\n");
    }


    return 0;
}