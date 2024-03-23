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
    //노드를 입력받음
    for (i = 0; i < connect_num; i++) {
        scanf("%d %d", &num1, &num2);
        node[num1][num2] = 1;
        node[num2][num1] = 1;
    }

    //1번 방문하고 stack에 넣음 
    visit[1] = 1;
    push(1);
    //stack에서 하나씩 빼서 연결컴 감염시킴
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
