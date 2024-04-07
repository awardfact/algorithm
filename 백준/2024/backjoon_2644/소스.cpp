#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct RelationT {

    int x;
    int y;
    struct RelationT* after;
}Relation;



Relation* front_que;
Relation* rear_que;
Relation* tmp_que;

void push(int x, int y) {
    tmp_que = (Relation*)malloc(sizeof(Relation));
    tmp_que->x = x;
    tmp_que->y = y;
    tmp_que->after = NULL;

    if (front_que == NULL) {
        front_que = tmp_que;
    }
    else {
        rear_que->after = tmp_que;
    }

    rear_que = tmp_que;
}

Relation* pop() {

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
    int n;
    int findx, findy;
    int m, i, j;
    int x, y;
    int chon[101][101] = { 0, };
    char visit[101][101] = { 0, };
    Relation* pop_relation;
    scanf("%d", &n);
    scanf("%d %d", &findx, &findy);
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        //�Է¹��� ����� 1������ �����ϰ� �湮 üũ�ϰ� ť�� �ִ´� 
        if (visit[x][y] == 0) {
            chon[x][y] = 1;
            chon[y][x] = 1;
            push(x, y);
            visit[x][y] = 1;
            visit[y][x] = 1;

        }

    }


    while (front_que != NULL) {
        //ť���� ���踦 ���� 
        pop_relation = pop();
        for (i = 1; i <= n; i++) {

            // y�� ����Ǿ������� x�͵� ��������ش� �Ÿ��� x y + 1
            if (chon[pop_relation->y][i] == 1 && visit[pop_relation->x][i] == 0) {
                chon[pop_relation->x][i] = chon[pop_relation->x][pop_relation->y] + 1;
                chon[i][pop_relation->x] = chon[pop_relation->x][pop_relation->y] + 1;
                visit[pop_relation->x][i] = 1;
                visit[i][pop_relation->x] = 1;

                push(pop_relation->x, i);
            }
            //x�� ����Ǿ������� y�͵� ��������ش� 
            if (chon[pop_relation->x][i] == 1 && visit[pop_relation->y][i] == 0) {
                chon[pop_relation->y][i] = chon[pop_relation->x][pop_relation->y] + 1;
                chon[i][pop_relation->y] = chon[pop_relation->x][pop_relation->y] + 1;
                visit[pop_relation->y][i] = 1;
                visit[i][pop_relation->y] = 1;

                push(pop_relation->y, i);
            }


        }
        //�پ��� free
        free(pop_relation);

    }

    if (chon[findx][findy] == 0) {
        printf("-1\n");
    }
    else {
        printf("%d\n", chon[findx][findy]);
    }

    return 0;
}



