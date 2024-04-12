#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct SharkBoxT {
    int n;
    int m;
    int cnt;

    struct SharkBoxT* after;

}SharkBox;

SharkBox* front_que;
SharkBox* rear_que;
SharkBox* tmp_que;

void push(int n, int m, int cnt) {
    tmp_que = (SharkBox*)malloc(sizeof(SharkBox));
    tmp_que->n = n;
    tmp_que->m = m;
    tmp_que->cnt = cnt;
    tmp_que->after = NULL;

    if (front_que == NULL) {
        front_que = tmp_que;
    }
    else {
        rear_que->after = tmp_que;
    }

    rear_que = tmp_que;

}

SharkBox* pop() {

    if (front_que != NULL) {
        tmp_que = front_que;
        front_que = front_que->after;
        return tmp_que;
    }
    else {
        return NULL;
    }


}

char moven[8] = { -1,-1,-1,0,0,1,1,1 };
char movem[8] = { -1,0,1,-1,1,-1,0,1 };

int main() {
    int n, m, i, j;
    SharkBox* pop_value;
    char box[50][50];
    char visit[50][50] = { 0, };
    int max_cnt = 0;

    scanf("%d %d", &n, &m);
    //입력
    getchar();

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%c ", &box[i][j]);
            //안전거리 최대값이여서 너비우선 탐색을 실행 상어 있는곳 큐에 넣고 방문처리
            if (box[i][j] == '1') {
                push(i, j, 0);
                visit[i][j] = 1;
            }

        }

    }


    //큐에서 하나씩 빼서 인접지역인데 방문 안한곳 있으면 거리 + 1 해서 다시 큐에 집어넣음
    while (front_que != NULL) {
        pop_value = pop();

        for (i = 0; i < 8; i++) {
            //   printf("%d %d \n", pop_value->n + moven[i] , pop_value->m + movem[i]);
            if (pop_value->n + moven[i] >= 0 && pop_value->n + moven[i] < n && pop_value->m + movem[i] >= 0 && pop_value->m + movem[i] < m && visit[pop_value->n + moven[i]][pop_value->m + movem[i]] == 0) {
                visit[pop_value->n + moven[i]][pop_value->m + movem[i]] = 1;
                push(pop_value->n + moven[i], pop_value->m + movem[i], pop_value->cnt + 1);
                if (pop_value->cnt + 1 > max_cnt) {
                    //  printf("%d %d\n", pop_value->n + moven[i] , pop_value->m + movem[i]);
                    max_cnt = pop_value->cnt + 1;
                }
            }
        }
        free(pop_value);
    }

    //최대거리 출력
    printf("%d\n", max_cnt);
    return 0;
}