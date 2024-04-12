#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int stack[1000];
int top = -1;

void push(int a) {
    stack[++top] = a;


}

int pop() {

    if (top != -1) {
        return stack[top--];
    }
}


int main() {
    int i, j;
    int sum = 0;
    int tmp_sum;
    int pop_value;
    int bracket_cnt = 0;
    int before_value = 0;
    int before_tmp = 0;

    char chemical[101];

    scanf("%s", chemical);

    for (i = 0; i < strlen(chemical); i++) {

        //��ȣ�� ������ ��ȣ�� ���ÿ� �ְ� ��ȣ ������ ī��Ʈ���ش�
        if (chemical[i] == '(') {
            bracket_cnt++;
            push(9999999);
            continue;
        }

        //��ȣ�� ���� ���¿��� ���� �Ǵ� ��ȣ�� ������ ���� �����ش� 
        if (bracket_cnt == 0) {
            if (chemical[i] == 'H') {
                sum += 1;
                before_value = 1;
            }
            else if (chemical[i] == 'C') {
                sum += 12;
                before_value = 12;
            }
            else if (chemical[i] == 'O') {
                sum += 16;
                before_value = 16;
            }

            if (chemical[i] >= '0' && chemical[i] <= '9') {
                sum += before_value * (chemical[i] - 49);
                before_value = 0;

            }
            //�L ��ȣ�� ������ ���ÿ��� ���� ��ȣ�� ���ö����� ���� �����ְ� ��ȣ�� �� ������ �ٽ� ���ÿ� �ִ´�
        }
        else if (chemical[i] == ')') {
            tmp_sum = 0;
            pop_value = pop();
            while (pop_value != 9999999) {
                tmp_sum += pop_value;
                pop_value = pop();
            }
            bracket_cnt--;

            if (bracket_cnt == 0) {
                sum += tmp_sum;
            }
            else {
                push(tmp_sum);
            }


            before_value = tmp_sum;




            //��ȣ�� �ִ� ���¿��� ��ȣ�� ���ڰ� ������ ���ÿ� ���� �߰����ش�
        }
        else {
            if (chemical[i] == 'H') {
                push(1);
                before_value = 1;
            }
            else if (chemical[i] == 'C') {
                push(12);
                before_value = 12;
            }
            else if (chemical[i] == 'O') {
                push(16);
                before_value = 16;
            }
            else if (chemical[i] >= '0' && chemical[i] <= '9') {
                push(before_value * (chemical[i] - 49));
                before_value = 0;
            }
        }


    }

    printf("%d\n", sum);
    return 0;
}