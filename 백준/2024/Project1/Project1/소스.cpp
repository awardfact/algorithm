#include <stdio.h>
#include <stdlib.h>

int que[300001];
int front = 0;
int rear = 0;


void push(int num) {

    que[rear] = num;
    rear++;
}


int pop() {

    int num = que[front];
    front++;
    return num;

    //return 1;
}




int main() {
    int location[200001];
    int visit[200001];
    int n, m;
    int count = 0;
    int find = 0;
    int i = 0;
    int current = 0;
    int push_cnt = 0;
    int push_cnt2 = 0;
    scanf_s("%d %d", &n, &m);
    for (i = 0; i < 100001; i++) {

    }

    for (i = 0; i < 200001; i++) {
        location[i] = i;
        visit[i] = 0;
    }

    if (n == m) {
        // printf("%d\n", count);

    }
    else {

        if (n + 1 <= 100000) {
            push(location[n + 1]);
            push_cnt2++;
            visit[n + 1]++;
        }

        if (n - 1 >= 0 && visit[n - 1] == 0) {
            push(location[n - 1]);
            push_cnt2++;
            visit[n - 1]++;
        }

        if (n * 2 <= 200000 && visit[n * 2] == 0) {
            push(location[n * 2]);
            push_cnt2++;
            visit[n * 2]++;
        }

        count++;
        while (find != 1) {

            //printf("1\n");
            push_cnt = push_cnt2;
            push_cnt2 = 0;
         //   printf("push_cnt : %d\n", push_cnt);
            for (i = 0; i < push_cnt; i++) {
                current = pop();
                 // printf("current : %d\n", current);


                if (current == m) {
                    find = 1;
                    break;
                }

                if (current + 1 <= 100000 && visit[current + 1] == 0) {
                    push(location[current + 1]);
                    push_cnt2++;
                    visit[current + 1]++;
                }

                if (current - 1 >= 0 && visit[current - 1] == 0) {
                    push(location[current - 1]);
                    push_cnt2++;
                    visit[current - 1]++;
                }

                if (current * 2 <= 200000 && visit[current * 2] == 0) {
                    push(location[current * 2]);
                    push_cnt2++;
                    visit[current * 2]++;
                }



            }
             //  printf("count : %d\n", count);
            if (find != 1) {
                count++;
            }



        }


    }



    printf("%d\n", count);


    return 0;
}