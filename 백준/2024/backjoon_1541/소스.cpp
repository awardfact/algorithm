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
        //숫자
        if (string[i] >= '0' && string[i] <= '9') {
            num *= 10;
            num += string[i] - 48;
            //연산자 또는 괄호 
        }
        else if (string[i] == '+') {

            //괄호가 열린 상태고 이전 연산자가 -면 괄호안에 현재 그 숫자만 있는거고 +면 괄호 안의 값과 값을 더한다 
            if (bracket == 1) {
                if (before_op == '+') {
                    bracket_sum += num;
                }
                else if (before_op == '-') {
                    bracket_sum += num;
                }
                //괄호가 닫힌 상태면 이전에 +가 나왔다는 거여서 + 면 + 해주고 -면 - 해준다 연산자가 없으면 첫 숫자여서 sum을 해당 숫자로 
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
            //-가 나오는 경우 
        }
        else if (string[i] == '-') {

            //이전 연산자가 없거나 -가 처음 나오는 경우 괄호 상태로 만들고 이전에 +였으면 더해주고 연산자가 없으면 sum에 숫자를 넣어준다 
            if (bracket == 0) {
                bracket = 1;
                if (before_op == '+') {
                    sum += num;
                }
                else if (before_op != '-') {
                    sum = num;
                }
                //printf("sum : %d\n", sum);
                        //  괄호가 열린 상태였다면 괄호 닫고 그 괄호 값을 빼고 다시 괄호를 연다 
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
    //괄호가 열린 상태였으면 마지막 숫자를 괄호 안 값으로 더하고 -해주고 아니면 더해준다 
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