#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int stack[101];
int top = -1;

void push(int num) {

    stack[++top] = num;

}

int pop() {
    return stack[top--];
}


int main() {

    int com_num;
    int node[101][101] = { 0, };
    int visit[101] = { 0, };
    int virus_num = 0;
    int num1, num2;
    int connect_num;
    int i, j;

    scanf("%d %d", &com_num, &connect_num);
    //��带 �Է¹���
    for (i = 0; i < connect_num; i++) {
        scanf("%d %d", &num1, &num2);
        node[num1][num2] = 1;
        node[num2][num1] = 1;
    }

    //1�� �湮�ϰ� stack�� ���� 
    visit[1] = 1;
    push(1);
    //stack���� �ϳ��� ���� ������ ������Ŵ
    while (top >= 0) {
        num1 = pop();

        //printf("num : %d\n", num1);
        for (i = 2; i <= com_num; i++) {
            if (node[num1][i] == 1 && visit[i] != 1) {
                visit[i] = 1;
                push(i);
                virus_num++;
            }
        }


    }



    printf("%d\n", virus_num);
    return 0;
}
