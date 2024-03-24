#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int compare(const void* a, const void* b) {
    if (*(int*)a > *(int*)b) {
        return 1;
    }
    else if (*(int*)a == *(int*)b) {
        return 0;
    }
    else {
        return -1;
    }


}

//가중치와 넣은 순위 구조체 생성 
typedef struct houseT {

    int i;
    int j;

}houseij;

houseij que[626];
int front = 0;
int rear = 0;


void push(int i, int j) {
    rear = ++rear % 626;
    que[rear].i = i;
    que[rear].j = j;
}



houseij pop() {

    if (front != rear) {
        return que[++front % 626];
    }

}



int main() {
    int i, j;
    char house[26][26] = { 0, };
    int connect[26][26] = { 0, };
    int danji[326] = { 0, };
    int danji_cnt = 0;
    houseij house_tmp;
    int n;
    //크기 입력받음 
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", house[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            //집이 있고 단지 설정을 하지 않은 경우 
            if (house[i][j] == '1' && connect[i][j] == 0) {
                push(i, j);
                danji_cnt++;
                connect[i][j] = 1;
                danji[danji_cnt]++;
                while (front != rear) {
                    house_tmp = pop();

                    //위로 갈 수 있고 연결 안된 상태면 연결
                    if (house_tmp.i + 1 < n && connect[house_tmp.i + 1][house_tmp.j] == 0 && house[house_tmp.i + 1][house_tmp.j] == '1') {
                        push(house_tmp.i + 1, house_tmp.j);
                        connect[house_tmp.i + 1][house_tmp.j] = 1;
                        danji[danji_cnt]++;
                    }


                    //밑으로로 갈 수 있고 연결 안된 상태면 연결
                    if (house_tmp.i - 1 >= 0 && connect[house_tmp.i - 1][house_tmp.j] == 0 && house[house_tmp.i - 1][house_tmp.j] == '1') {
                        push(house_tmp.i - 1, house_tmp.j);
                        connect[house_tmp.i - 1][house_tmp.j] = 1;
                        danji[danji_cnt]++;
                    }

                    //오른쪽으로 갈 수 있고 연결 안된 상태면 연결
                    if (house_tmp.j + 1 < n && connect[house_tmp.i][house_tmp.j + 1] == 0 && house[house_tmp.i][house_tmp.j + 1] == '1') {
                        push(house_tmp.i, house_tmp.j + 1);
                        connect[house_tmp.i][house_tmp.j + 1] = 1;
                        danji[danji_cnt]++;
                    }

                    //왼쪽으로 갈 수 있고 연결 안된 상태면 연결
                    if (house_tmp.j - 1 >= 0 && connect[house_tmp.i][house_tmp.j - 1] == 0 && house[house_tmp.i][house_tmp.j - 1] == '1') {
                        push(house_tmp.i, house_tmp.j - 1);
                        connect[house_tmp.i][house_tmp.j - 1] = 1;
                        danji[danji_cnt]++;
                    }
                }


            }
        }
    }

    qsort(&danji[1], danji_cnt, sizeof(int), compare);

    printf("%d\n", danji_cnt);
    for (i = 1; i <= danji_cnt; i++) {
        printf("%d\n", danji[i]);
    }

    return 0;
}

