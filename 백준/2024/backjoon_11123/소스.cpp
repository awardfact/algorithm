#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct GridT {
    int h;
    int w;
    struct GridT* before;
    struct GridT* after;
}Grid;


Grid* tmp_stack;
Grid* top_stack;

void push(int h, int w) {
    tmp_stack = (Grid*)malloc(sizeof(Grid));
    tmp_stack->h = h;
    tmp_stack->w = w;
    tmp_stack->after = NULL;
    tmp_stack->before = NULL;


    if (top_stack == NULL) {
        top_stack = tmp_stack;

    }
    else {
        top_stack->after = tmp_stack;
        tmp_stack->before = top_stack;

    }

    top_stack = tmp_stack;


}


Grid* pop() {

    if (top_stack != NULL) {
        tmp_stack = top_stack;
        top_stack = top_stack->before;
        return tmp_stack;

    }
    else {
        return NULL;

    }

}

char moveh[4] = { 1,-1,0,0 };
char movew[4] = { 0,0,1,-1 };

int main() {

    int t, h, w, i, j, k, l;
    Grid* pop_grid;
    char grid[100][100];
    char visit[100][100];
    int moori;
    scanf("%d", &t);


    for (i = 0; i < t; i++) {
        memset(grid, 0, sizeof(char) * 10000);
        memset(visit, 0, sizeof(char) * 10000);
        moori = 0;
        scanf("%d %d", &h, &w);
        getchar();
        //입력 
        for (j = 0; j < h; j++) {
            for (k = 0; k < w; k++) {
                scanf("%c ", &grid[j][k]);
            }
        }
        //노드 다 돌면서 처음 방문한곳 스택에 넣고 깊이우선 탐색해서 근처에 있는 양들 다 방문처리 
        for (j = 0; j < h; j++) {
            for (k = 0; k < w; k++) {
                if (visit[j][k] == 0 && grid[j][k] == '#') {
                    moori++;
                    visit[j][k] = 1;
                    push(j, k);
                    while (top_stack != NULL) {
                        pop_grid = pop();
                        for (l = 0; l < 4; l++) {
                            if (visit[pop_grid->h + moveh[l]][pop_grid->w + movew[l]] == 0 && grid[pop_grid->h + moveh[l]][pop_grid->w + movew[l]] == '#'
                                && pop_grid->h + moveh[l] >= 0 && pop_grid->h + moveh[l] < h && pop_grid->w + movew[l] >= 0 && pop_grid->w + movew[l] < w) {
                                visit[pop_grid->h + moveh[l]][pop_grid->w + movew[l]] = 1;
                                push(pop_grid->h + moveh[l], pop_grid->w + movew[l]);

                            }

                        }
                        free(pop_grid);
                    }
                }
            }
        }


        printf("%d\n", moori);

    }


    return 0;
}



