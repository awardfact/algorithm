#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int que[200];
int front = 0;
int rear = 0;

void push(int num) {


    que[front++ % 100] = num;

}

int pop() {

    if (front != rear) {
        return que[rear++ % 100];
    }

}

int main() {

    int friends[101][101] = { 0, };
    int connect[101][101] = { 0, };
    int n, m, a, b;
    int step;
    int left;
    int i, j, k;
    int min, min_num, cnt, pop_value;
    int que_cnt, que_cnt_tmp;
    min = 1000001;
    //n,m�Է�
    scanf("%d %d", &n, &m);

    // for(i = 0; i < 101; i++){
    //     for(j = 0; j < 101; j++){

    //     }
    // }

    for (i = 0; i < m; i++) {
        //���� �Է�
        scanf("%d %d", &a, &b);
        //1�̸� ����
        friends[a][b] = 1;
        friends[b][a] = 1;

    }


    for (i = 1; i <= n; i++) {
        left = n - 1;
        cnt = 0;
        que_cnt = 0;
        step = 1;
        //printf("================================\n");
        //Ž���ؼ� ����Ǿ������� ������� ����� ���ÿ� ���� 
        for (j = 1; j <= n; j++) {

            if (friends[i][j] == 1 && j != i) {
                push(j);

                //printf("i j : %d %d", i, j);
                connect[i][j] = 1;
                que_cnt++;
                left--;
                cnt += step;

            }

        }

        //  printf("i : %d left : %d\n", i, left);
        step++;
        //���� �ȵ� ����� ����������
        while (left != 0) {
            // printf("i : %d left : %d\n", i, left);
            que_cnt_tmp = que_cnt;
            que_cnt = 0;
            //que�� ������ �ϳ��� ���鼭 i�� ���� �� �߰� que���� �� ����� ���� �������� ���� ��Ű�� que�� �� ��� �߰� 
            for (j = 0; j < que_cnt_tmp; j++) {
                pop_value = pop();

                for (k = 1; k <= n; k++) {
                    if (friends[pop_value][k] == 1 && connect[i][k] == 0 && k != i) {
                        push(k);
                        connect[i][k] = 1;
                        que_cnt++;
                        left--;
                        cnt += step;

                    }

                }

            }
            step++;

        }

        while (front != rear) {
            pop();
        }


        if (cnt < min) {
            min = cnt;
            min_num = i;
        }

    }

    printf("%d", min_num);



    return 0;
}