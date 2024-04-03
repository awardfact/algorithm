#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct gameQueT {
    char area;
    int dice_cnt;
    struct gameQueT* after;
}gameQue;


gameQue* front_que;
gameQue* rear_que;
gameQue* tmp_que;


void push(int area, int dice_cnt) {
    tmp_que = (gameQue*)malloc(sizeof(gameQue));
    tmp_que->area = area;
    tmp_que->dice_cnt = dice_cnt;
    tmp_que->after = NULL;


    if (front_que == NULL) {
        front_que = tmp_que;
    }
    else {
        rear_que->after = tmp_que;
    }


    rear_que = tmp_que;

}

gameQue* pop() {

    if (front_que != NULL) {
        tmp_que = front_que;
        front_que = front_que->after;
        return tmp_que;

    }



}



char move[6] = { 1,2,3,4,5,6 };


int main() {

    int loop_cnt, snake_cnt;
    char move_map[101] = { 0, };
    int u, v;
    int dice_cnt = 0;
    gameQue* pop_que;
    char end_flag = 0;
    char visit[101] = { 0, };
    char i, j;

    scanf("%d %d", &loop_cnt, &snake_cnt);

    //��ٸ�, �� �Է�
    for (i = 0; i < loop_cnt; i++) {
        scanf("%d %d", &u, &v);
        move_map[u] = v;
    }
    for (i = 0; i < snake_cnt; i++) {
        scanf("%d %d", &u, &v);
        move_map[u] = v;
    }


    //1�� ��ġ ����
    push(1, 0);

    while (front_que != NULL) {
        pop_que = pop();
        dice_cnt++;
        //�ֻ����� 1���� 6���� ����
        for (i = 0; i < 6; i++) {
            //100�� ������ ���� 
            if (pop_que->area + move[i] == 100) {
                end_flag = 1;
                break;
            }

            //100 �̸��� ���� ������ ť�� ���� 
            if (pop_que->area + move[i] < 100 && visit[pop_que->area + move[i]] == 0) {

                //��ٸ� �Ǵ� ���� ������ �� ��ġ�� �̵� 
                if (move_map[pop_que->area + move[i]] != 0) {
                    push(move_map[pop_que->area + move[i]], pop_que->dice_cnt + 1);
                    visit[move_map[pop_que->area + move[i]]] = 1;

                    //������ ������ŭ �̵� 
                }
                else {
                    push(pop_que->area + move[i], pop_que->dice_cnt + 1);
                    visit[pop_que->area + move[i]] = 1;
                }


            }
        }




        //�������� �� Free
        if (end_flag == 1) {

            dice_cnt = pop_que->dice_cnt + 1;
            free(pop_que);
            while (front_que != NULL) {
                pop_que = pop();
                free(pop_que);
            }
            break;
        }

        //����� ť�� free
        free(pop_que);

    }

    printf("%d\n", dice_cnt);

    return 0;
}


