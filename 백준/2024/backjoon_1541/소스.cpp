#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

    char string[100];
    char before_op;
    char op;
    int i;
    int sum;
    int before_num;
    int num;
    int bracket_sum;
    int bracket;
    scanf("%s", string);

    num = 0;
    sum = 0;
    bracket_sum = 0;
    before_op = 0;
    op = 0;
    for (i = 0; i < strlen(string); i++) {
        //����
        if (string[i] >= '0' && string[i] <= '9') {
            num *= 10;
            num += string[i] - 48;
            //������ �Ǵ� ��ȣ 
        }
        else if (string[i] == '+') {

            //��ȣ�� ���� ���°� ���� �����ڰ� -�� ��ȣ�ȿ� ���� �� ���ڸ� �ִ°Ű� +�� ��ȣ ���� ���� ���� ���Ѵ� 
            if (bracket == 1) {
                if (before_op == '+') {
                    bracket_sum += num;
                }
                else if (before_op == '-') {
                    bracket_sum += num;
                }
                //��ȣ�� ���� ���¸� ������ +�� ���Դٴ� �ſ��� + �� + ���ְ� -�� - ���ش� �����ڰ� ������ ù ���ڿ��� sum�� �ش� ���ڷ� 
            }
            else {
                if (before_op == '+') {
                    sum += num;
                }
                else if (before_op != '-') {
                    sum = num;
                }

            }
            before_op = '+';
            num = 0;
            //-�� ������ ��� 
        }
        else if (string[i] == '-') {

            //���� �����ڰ� ���ų� -�� ó�� ������ ��� ��ȣ ���·� ����� ������ +������ �����ְ� �����ڰ� ������ sum�� ���ڸ� �־��ش� 
            if (bracket == 0) {
                bracket = 1;
                if (before_op == '+') {
                    sum += num;
                }
                else if (before_op != '-') {
                    sum = num;
                }
                //printf("sum : %d\n", sum);
                        //  ��ȣ�� ���� ���¿��ٸ� ��ȣ �ݰ� �� ��ȣ ���� ���� �ٽ� ��ȣ�� ���� 
            }
            else {

                if (before_op == '+') {
                    bracket_sum += num;
                }
                else if (before_op == '-') {
                    bracket_sum += num;
                }
                sum -= bracket_sum;
                //bracket = 0;
                bracket_sum = 0;
            }
            before_op = '-';
            num = 0;

        }


    }

    //printf("sum : %d\n", sum);
    //��ȣ�� ���� ���¿����� ������ ���ڸ� ��ȣ �� ������ ���ϰ� -���ְ� �ƴϸ� �����ش� 
    if (bracket == 1) {
        bracket_sum += num;
        sum -= bracket_sum;
        //printf("bracket_sum : %d\n", bracket_sum);
    }
    else {
        sum += num;

    }

    printf("%d", sum);
    return 0;
}