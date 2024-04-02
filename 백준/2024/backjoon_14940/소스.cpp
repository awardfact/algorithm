#include <stdio.h>
#include <string.h>

typedef struct mapT {
    int n;
    int m;

}mapC;

mapC que[1000000];

int front = -1;
int rear = -1;
void push(int n, int m) {
    ++front;
    que[front].n = n;
    que[front].m = m;

}

mapC pop() {
    if (front != rear) {
        return que[++rear];
    }

}

char moven[4] = { -1, 1, 0, 0 };
char movem[4] = { 0, 0, -1, 1 };

int main() {

    char map[1000][1000];
    int distance[1000][1000] = { 0, };
    int n, m, i, j;
    int startx;
    int starty;
    mapC pop_area;
    int current_distance;

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf(" %c", &map[i][j]);
            if (map[i][j] == '2') {
                startx = i;
                starty = j;
            }
        }
    }

    // for(i = 0; i < n; i++){
    //     for(j= 0; j < m; j++){
    //         printf("%c ", map[i][j]);

    //     }
    //     printf("\n");
    // }

//시작점 큐에 넣음
    push(startx, starty);
    //큐에서 하나씩 빼면서 이동할 수 있는 곳 중에서 거리를 아직 측정 안한곳에 방문하여 거리를 측정해주고 다시 푸시 
    while (front != rear) {
        pop_area = pop();

        for (i = 0; i < 4; i++) {
            if (pop_area.n + moven[i] >= 0 && pop_area.n + moven[i] < n && pop_area.m + movem[i] >= 0 && pop_area.m + movem[i] < m && map[pop_area.n + moven[i]][pop_area.m + movem[i]] == '1' && distance[pop_area.n + moven[i]][pop_area.m + movem[i]] == 0) {
                distance[pop_area.n + moven[i]][pop_area.m + movem[i]] = distance[pop_area.n][pop_area.m] + 1;
                push(pop_area.n + moven[i], pop_area.m + movem[i]);

            }

        }


    }
    //거리 출력, 1인데 거리 0이면 -1출력
   // printf("\n\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (map[i][j] == '1' && distance[i][j] == 0) {
                printf("-1 ");
            }
            else {
                printf("%d ", distance[i][j]);
            }


        }
        printf("\n");
    }



    return 0;
}


