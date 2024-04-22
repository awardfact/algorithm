#include <stdio.h>
#include <stdlib.h>
int visit[1000001] = { 0, };

typedef struct queT {

    int floor;
    int move_cnt;
    struct queT* after;


}que;


que* front_que;
que* rear_que;
que* tmp_que;

//큐 생성
void push(int floor, int move_cnt) {

    tmp_que = (que*)malloc(sizeof(que));

    tmp_que->floor = floor;
    tmp_que->move_cnt = move_cnt;
    tmp_que->after = NULL;
    if (front_que == NULL) {
        front_que = tmp_que;

    }
    else {
        rear_que->after = tmp_que;
    }

    rear_que = tmp_que;

}



que* pop() {

    if (front_que != NULL) {
        tmp_que = front_que;
        front_que = front_que->after;
        return tmp_que;

    }
    else {
        return NULL;
    }


}

int main() {

    int f, s, g, u, d;
    int cnt = 0;
    que* pop_que;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

    if (g == s) {
        printf("%d\n", cnt);
    }
    else {




        visit[s] = 1;

        if (s + u <= f) {
            push(s + u, 1);
            visit[s + u] = 1;
        }

        if (s - d > 0) {
            push(s - d, 1);

            visit[s - d] = 1;
        }


        //g를 찾을떄까지 너비우선 탐색 진행 
        while (front_que != NULL) {
            pop_que = pop();

            if (pop_que->floor != g) {
                if (pop_que->floor + u <= f && visit[pop_que->floor + u] == 0) {
                    push(pop_que->floor + u, pop_que->move_cnt + 1);
                    visit[pop_que->floor + u] = 1;
                }


                if (pop_que->floor - d > 0 && visit[pop_que->floor - d] == 0) {
                    push(pop_que->floor - d, pop_que->move_cnt + 1);
                    visit[pop_que->floor - d] = 1;
                }

            }
            else {
                cnt = pop_que->move_cnt;
                free(pop_que);
                pop_que = pop();
                while (pop_que != NULL) {
                    free(pop_que);
                    pop_que = pop();
                }
                break;
            }

            free(pop_que);


        }

        if (cnt == 0) {
            printf("use the stairs\n");

        }
        else {
            printf("%d\n", cnt);

        }

    }




    return 0;
}