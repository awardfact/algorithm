#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//가중치와 넣은 순위 구조체 생성 
typedef struct printQT {

    int value;
    int input_seq;

}printQ;

printQ que[101];
int front = 0;
int rear = 0;


void push(int value, int input_seq) {
    rear = ++rear % 101;
    que[rear].value = value;
    que[rear].input_seq = input_seq;
}



printQ pop() {

    if (front != rear) {
        return que[++front % 101];
    }

}



int main() {
    int test_case;
    int n, docu_num, que_num;
    int input_num;
    printQ que_tmp;
    int que_value[101];
    int que_cnt;
    int i, j;
    int tmp;
    int seq;
    int end_flag;
    scanf("%d", &test_case);
    //테스트 케이스 반복
    for (i = 0; i < test_case; i++) {
        //문서 개수와 몇번째 큐에 있는지 받음
        scanf("%d %d", &docu_num, &que_num);
        front = 0;
        rear = 0;
        seq = 0;

        //숫자와 넣은 순서를 큐에 넣고 가중치들이 몇인지도 배열에 넣음 
        for (j = 0; j < docu_num; j++) {
            scanf("%d", &input_num);
            que_value[j] = input_num;
            push(input_num, j);

        }


        //큐에서 하나씩 빼서 가중치 더 큰거 있으면 큐에 다시 넣고 아니면 순서 증가시키고 찾으려는 넣은 순서인지 체크해서 맞으면 빠져나옴
        while (front != rear) {
            que_tmp = pop();
            end_flag = 0;
            for (j = 0; j < docu_num; j++) {

                if (que_tmp.value < que_value[j]) {
                    push(que_tmp.value, que_tmp.input_seq);
                    end_flag = 1;
                    break;
                }
            }


            if (end_flag == 1) {
                continue;
            }
            seq++;

            if (que_num == que_tmp.input_seq) {
                break;
            }
            que_value[que_tmp.input_seq] = 0;

        }

        printf("%d\n", seq);

    }


    return 0;
}

