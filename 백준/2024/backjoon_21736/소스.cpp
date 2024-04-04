#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct schoolMapT {
    int n;
    int m;

    struct schoolMapT* after;

}schoolMap;

schoolMap que[30000];

int front = -1;
int rear = -1;

schoolMap* front_que;
schoolMap* rear_que;
schoolMap* tmp_que;


// void push(int n, int m){
//     front= ++front % 30000;
//     que[front].n = n;
//     que[front].m = m;


// }

void push(int n, int m) {

    tmp_que = (schoolMap*)malloc(sizeof(schoolMap));
    tmp_que->n = n;
    tmp_que->m = m;
    tmp_que->after = NULL;

    if (front_que == NULL) {
        front_que = tmp_que;

    }
    else {
        rear_que->after = tmp_que;

    }
    rear_que = tmp_que;

}

schoolMap* pop() {

    if (front_que != NULL) {
        tmp_que = front_que;
        front_que = front_que->after;
        return tmp_que;
        //return ;

    }
}





//void pop(schoolMap* a){

//     if(front != rear){
//         rear= ++rear % 30000;

//         a = &que[rear];
//         //return ;

//     }
// }



char moven[4] = { 1, -1,0,0 };
char movem[4] = { 0,0,1,-1 };


int main() {

    int n, m;
    int i, j;
    schoolMap* map_tmp;
    int cnt = 0;
    char map[601][601] = { 0, };
    char visit[601][601] = { 0, };



    scanf("%d %d", &n, &m);
    //입력
    for (i = 1; i <= n; i++) {
        getchar();
        for (j = 1; j <= m; j++) {
            scanf("%c", &map[i][j]);
            if (map[i][j] == 'I') {
                push(i, j);
                visit[i][j] = 1;
            }
        }

    }

    //큐에서 빼서 상하좌우 방문 안하고 벽이 아닌곳 방문해서 사람 아니면 cnt ++ 하고 다시 큐에 넣음
    while (front_que != NULL) {
        map_tmp = pop();

        //  printf(" %d %d\n", map_tmp->n, map_tmp->m);
        for (i = 0; i < 4; i++) {
            if (map_tmp->n + moven[i] >= 1 && map_tmp->n + moven[i] <= n &&
                map_tmp->m + movem[i] >= 1 && map_tmp->m + movem[i] <= m &&
                visit[map_tmp->n + moven[i]][map_tmp->m + movem[i]] == 0 &&
                map[map_tmp->n + moven[i]][map_tmp->m + movem[i]] != 'X') {

                visit[map_tmp->n + moven[i]][map_tmp->m + movem[i]] = 1;
                push(map_tmp->n + moven[i], map_tmp->m + movem[i]);
                if (map[map_tmp->n + moven[i]][map_tmp->m + movem[i]] == 'P') {
                    cnt++;

                }
            }

        }

        free(map_tmp);



    }

    if (cnt == 0) {
        printf("TT\n");
    }
    else {
        printf("%d\n", cnt);
    }


    return 0;
}


