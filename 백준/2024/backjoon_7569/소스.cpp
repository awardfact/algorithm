#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct queT {
    int n;
    int m;
    int h;
    int day;

    struct queT* after;

}que;

que* first_que = NULL;
que* current_que = NULL;
que* tmp_que = NULL;

void push(int m, int n, int h, int day) {

    tmp_que = (que*)malloc(sizeof(que));
    tmp_que->m = m;
    tmp_que->n = n;
    tmp_que->h = h;
    tmp_que->day = day;
    tmp_que->after = NULL;



    if (first_que == NULL) {
        first_que = tmp_que;
        current_que = tmp_que;
    }
    else {
        current_que->after = tmp_que;
        current_que = tmp_que;
    }
}


que* pop() {

    if (first_que != NULL) {
        tmp_que = first_que;
        first_que = first_que->after;
        return tmp_que;
    }
    else {
        return NULL;
    }
}


int mm[6] = { -1, 1, 0, 0, 0,0 };
int mn[6] = { 0, 0, 1, -1, 0,0 };
int mh[6] = { 0, 0, 0, 0, 1,-1 };


int main() {
    int i, j, k, n, m, h;
    char box[100][100][100] = { 0, };
    int no_grow = 0;
    int grow_day = 0;
    int int_tmp;

    que* pop_que = NULL;



    scanf("%d %d %d", &m, &n, &h);
    for (i = 0; i < h; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < m; k++) {
                scanf("%d ", &int_tmp);
                box[k][j][i] = int_tmp + 48;
                //안익은거 개수 체크
                if (box[k][j][i] == '0') {
                    no_grow++;
                    //익었으면 큐에 넣음 
                }
                else if (box[k][j][i] == '1') {
                    push(k, j, i, 0);
                }
            }
        }
    }

    //안익은거 있는경우 
    if (no_grow) {
        //첫번째로 익은 토마토가 있는곳에서 시작 
        while (first_que != NULL) {
            //큐에서 하나 빼서 너비우선 탐색 진행 
            pop_que = pop();
            for (i = 0; i < 6; i++) {
                if (pop_que->m + mm[i] >= 0 && pop_que->m + mm[i] < m && pop_que->n + mn[i] >= 0 && pop_que->n + mn[i] < n && pop_que->h + mh[i] >= 0 && pop_que->h + mh[i] < h && box[pop_que->m + mm[i]][pop_que->n + mn[i]][pop_que->h + mh[i]] == '0') {
                    no_grow--;
                    box[pop_que->m + mm[i]][pop_que->n + mn[i]][pop_que->h + mh[i]] = '1';
                    push(pop_que->m + mm[i], pop_que->n + mn[i], pop_que->h + mh[i], pop_que->day + 1);
                    if (grow_day < pop_que->day + 1) {
                        grow_day = pop_que->day + 1;

                    }
                }
            }
            free(pop_que);
        }


        if (no_grow) {
            printf("-1\n");
        }
        else {
            printf("%d\n", grow_day);

        }

        //안익은거 없는 경우 
    }
    else {
        printf("0\n");


    }





    return 0;
}


