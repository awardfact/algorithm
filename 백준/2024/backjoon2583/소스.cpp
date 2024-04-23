#include <stdio.h>
#include <stdlib.h>

typedef struct stackT {
    int x;
    int y;
    struct stackT* before;
    struct stackT* after;


}stack;

char visit[101][101] = { 0, };
stack* top_stack = NULL;
stack* tmp_stack = NULL;


int compare(const void* a, const void* b) {
    if (*(int*)a > *(int*)b) {
        return 1;

    }
    else if (*(int*)a > *(int*)b) {
        return 0;
    }
    else {
        return -1;
    }


}

void push(int x, int y) {

    tmp_stack = (stack*)malloc(sizeof(stack));

    tmp_stack->x = x;
    tmp_stack->y = y;
    tmp_stack->before = NULL;
    tmp_stack->after = NULL;
    if (top_stack == NULL) {
        top_stack = tmp_stack;

    }
    else {
        top_stack->after = tmp_stack;
        tmp_stack->before = top_stack;
    }

    top_stack = tmp_stack;
}



stack* pop() {

    if (top_stack != NULL) {
        tmp_stack = top_stack;
        top_stack = top_stack->before;
        return tmp_stack;
    }
    else {
        return NULL;
    }

}



char movex[4] = { -1,1, 0,0 };
char movey[4] = { 0,0, 1, -1 };




int main() {
    int n, m, kan, i, j, k;
    stack* pop_stack;
    int cnt = 0;
    int wide[5001] = { 0, };
    int leftx, rightx, topy, bottomy;

    scanf("%d %d %d", &m, &n, &kan);

    //�Է�
    for (i = 0; i < kan; i++) {
        scanf("%d %d %d %d", &leftx, &bottomy, &rightx, &topy);
        // �׸� �簢���� ���Ե� �κ� �湮ó��
        for (j = leftx; j < rightx; j++) {
            for (k = bottomy; k < topy; k++) {
                if (visit[k][j] == 0) {
                    visit[k][j] = 1;
                }
            }
        }

    }



    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {

            //�湮�� ���� ���� ���̸� �и��� ���� ������ �ø��� ������ ũ�⸦ �ʺ�켱 Ž���� ���� ���Ѵ�
            if (visit[i][j] == 0) {

                push(i, j);
                visit[i][j] = 1;
                wide[cnt]++;
                while (top_stack != NULL) {
                    pop_stack = pop();

                    for (k = 0; k < 4; k++) {
                        //����� �湮���� ���� ���̸� �湮ó�� �� ���� ����



                        if (pop_stack->x + movex[k] >= 0 && pop_stack->x + movex[k] < m && pop_stack->y + movey[k] >= 0 && pop_stack->y + movey[k] < n && visit[pop_stack->x + movex[k]][pop_stack->y + movey[k]] == 0) {

                            visit[pop_stack->x + movex[k]][pop_stack->y + movey[k]] = 1;
                            push(pop_stack->x + movex[k], pop_stack->y + movey[k]);

                            wide[cnt]++;
                        }
                    }

                    free(pop_stack);

                }
                //�и��� ���� ���� ����
                cnt++;
            }

        }



    }

    qsort(wide, cnt, sizeof(int), compare);

    printf("%d\n", cnt);
    for (i = 0; i < cnt; i++) {
        printf("%d ", wide[i]);
    }



    return 0;
}