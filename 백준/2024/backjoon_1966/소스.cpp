#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����ġ�� ���� ���� ����ü ���� 
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
    //�׽�Ʈ ���̽� �ݺ�
    for (i = 0; i < test_case; i++) {
        //���� ������ ���° ť�� �ִ��� ����
        scanf("%d %d", &docu_num, &que_num);
        front = 0;
        rear = 0;
        seq = 0;

        //���ڿ� ���� ������ ť�� �ְ� ����ġ���� �������� �迭�� ���� 
        for (j = 0; j < docu_num; j++) {
            scanf("%d", &input_num);
            que_value[j] = input_num;
            push(input_num, j);

        }


        //ť���� �ϳ��� ���� ����ġ �� ū�� ������ ť�� �ٽ� �ְ� �ƴϸ� ���� ������Ű�� ã������ ���� �������� üũ�ؼ� ������ ��������
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

