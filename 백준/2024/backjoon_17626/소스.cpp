#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


typedef struct squaresT {

    int left_num;
    int cnt;

}squares;

squares que[50000];

int front = -1;
int rear = -1;

void push(int num, int cnt) {
    que[++front].left_num = num;
    que[front].cnt = cnt;

}

squares pop() {

    if (front != rear) {
        return que[++rear];
    }
}

int main() {
    int n;
    squares tmp_sq;
    int i;
    int cnt;
    int end_flag = 0;
    char visit[50001] = { 0, };
    scanf("%d", &n);


    //입력받은 값 큐에 넣음
    push(n, 0);

    // printf("n : %d\n", n);
    while (front != rear) {

        i = 1;
        //큐에서 빼서  남은 값보다 작은 제곱수를 전부 큐에 넣고 제곱수와 남은 값이 같으면 반복 종료
        tmp_sq = pop();
        //    printf("tmp_sq : %d\n", tmp_sq.left_num);

        while (i * i <= tmp_sq.left_num) {


            //  printf("i : %d  left : %d\n", i * i, tmp_sq.left_num);
            if (i * i == tmp_sq.left_num) {
                cnt = tmp_sq.cnt + 1;
                end_flag = 1;
                break;
                //방문하지 않고 사용 제곱 수 수가 3개 이하인 경우만 넣음
            }
            else if (visit[tmp_sq.left_num - (i * i)] == 0 && tmp_sq.cnt <= 3) {

                // printf("in\n");
                push(tmp_sq.left_num - (i * i), tmp_sq.cnt + 1);
                visit[tmp_sq.left_num - (i * i)] = 1;
            }

            i++;

        }

        if (end_flag == 1) {

            cnt = tmp_sq.cnt + 1;
            break;
        }

    }






    printf("%d\n", cnt);

    return 0;
}


