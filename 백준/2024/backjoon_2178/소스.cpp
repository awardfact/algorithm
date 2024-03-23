#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct tetT {
    int i;
    int j;
    int sum;
    int deep;
    int visiti[5];
    int visitj[5];


}tet;

tet stack[1000];
int top = -1;

void push(int i, int j, int sum, int deep, int* visiti, int* visitj) {
    top++;
    stack[top].i = i;
    stack[top].j = j;
    stack[top].sum = sum;
    stack[top].deep = deep;
    if (visiti != NULL) {
        memcpy(stack[top].visiti, visiti, sizeof(int) * 5);
    }
    if (visitj != NULL) {
        memcpy(stack[top].visitj, visitj, sizeof(int) * 5);
    }
    stack[top].visiti[deep] = i;
    stack[top].visitj[deep] = j;

}

tet pop() {
    if (top >= 0) {
        return stack[top--];
    }
}


int main() {

    int n, m, i, j, k, l;
    int paper[501][501];
    int max = 0;
    int sum = 0;
    tet tet_tmp;
    int visit_flag;
    int visiti_tmp[5];
    int visitj_tmp[5];

    scanf("%d %d", &n, &m);
    for (i = n; i >= 1; i--) {
        for (j = 1; j <= m; j++) {
            scanf("%d", &paper[i][j]);
            //   printf("%d\n", paper[i][j]);
        }
    }
    //���� �ڵ�� �� �� �� �� �� ������ ����� ������ ���� ���� �Է����༭ �� ũ�Ⱑ Ŀ���� �ذ� �� �� ������ ���Ƽ� ��� ũ��� ������� �̾��� �ִ� ��� ��忡�� ���� �� �ְ� ����
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            visiti_tmp[0] = i;
            visitj_tmp[0] = j;

            // ���ÿ� ���� ��� ��ġ�� ���� �ְ� ���̿켱Ž��
            push(i, j, paper[i][j], 0, visiti_tmp, visitj_tmp);
            while (top > 0) {

                //���ÿ��� ���� �M
                tet_tmp = pop();
                // printf("sum : %d\n", tet_tmp.sum);
                 // �̾��� �ִ� ���ʹ� ������ �����ϱ� ������ �̾��� �ִ� ��忡�� ��ĭ ������ �̵��ϴµ� �湮�� ���� �ƴϸ� ���ÿ� ����ְ� ���̰� �� 4�� �Ǹ� ũ�� ��� 
                for (k = 0; k <= tet_tmp.deep; k++) {
                    visit_flag = 0;
                    for (l = 0; l <= tet_tmp.deep; l++) {
                        if (tet_tmp.visiti[k] + 1 > n || (tet_tmp.visiti[k] + 1 == tet_tmp.visiti[l] && tet_tmp.visitj[k] == tet_tmp.visitj[l])) {
                            visit_flag = 1;
                        }
                    }


                    if (visit_flag == 0) {
                        if (tet_tmp.deep + 1 == 3) {
                            if (max < tet_tmp.sum + paper[tet_tmp.visiti[k] + 1][tet_tmp.visitj[k]]) {
                                // printf("sum : %d\n", tet_tmp.sum + paper[tet_tmp.visiti[k] + 1][tet_tmp.visitj[k]]);
                                max = tet_tmp.sum + paper[tet_tmp.visiti[k] + 1][tet_tmp.visitj[k]];
                            }
                        }
                        else {
                            push(tet_tmp.visiti[k] + 1, tet_tmp.visitj[k], tet_tmp.sum + paper[tet_tmp.visiti[k] + 1][tet_tmp.visitj[k]], tet_tmp.deep + 1, tet_tmp.visiti, tet_tmp.visitj);
                        }
                    }


                    visit_flag = 0;
                    for (l = 0; l <= tet_tmp.deep; l++) {
                        if (tet_tmp.visitj[k] + 1 > m || (tet_tmp.visiti[k] == tet_tmp.visiti[l] && tet_tmp.visitj[k] + 1 == tet_tmp.visitj[l])) {
                            visit_flag = 1;
                        }
                    }


                    if (visit_flag == 0) {
                        if (tet_tmp.deep + 1 == 3) {
                            if (max < tet_tmp.sum + paper[tet_tmp.visiti[k]][tet_tmp.visitj[k] + 1]) {
                                max = tet_tmp.sum + paper[tet_tmp.visiti[k]][tet_tmp.visitj[k] + 1];
                            }
                        }
                        else {
                            push(tet_tmp.visiti[k], tet_tmp.visitj[k] + 1, tet_tmp.sum + paper[tet_tmp.visiti[k]][tet_tmp.visitj[k] + 1], tet_tmp.deep + 1, tet_tmp.visiti, tet_tmp.visitj);
                        }
                    }

                    visit_flag = 0;
                    for (l = 0; l <= tet_tmp.deep; l++) {
                        if (tet_tmp.visiti[k] - 1 <= 0 || (tet_tmp.visiti[k] - 1 == tet_tmp.visiti[l] && tet_tmp.visitj[k] == tet_tmp.visitj[l])) {
                            visit_flag = 1;
                        }
                    }


                    if (visit_flag == 0) {
                        if (tet_tmp.deep + 1 == 3) {
                            if (max < tet_tmp.sum + paper[tet_tmp.visiti[k] - 1][tet_tmp.visitj[k]]) {
                                max = tet_tmp.sum + paper[tet_tmp.visiti[k] - 1][tet_tmp.visitj[k]];
                            }
                        }
                        else {
                            push(tet_tmp.visiti[k] - 1, tet_tmp.visitj[k], tet_tmp.sum + paper[tet_tmp.visiti[k] - 1][tet_tmp.visitj[k]], tet_tmp.deep + 1, tet_tmp.visiti, tet_tmp.visitj);
                        }
                    }


                    visit_flag = 0;
                    for (l = 0; l <= tet_tmp.deep; l++) {
                        if (tet_tmp.visitj[k] - 1 <= 0 || (tet_tmp.visiti[k] == tet_tmp.visiti[l] && tet_tmp.visitj[k] - 1 == tet_tmp.visitj[l])) {
                            visit_flag = 1;
                        }
                    }


                    if (visit_flag == 0) {
                        if (tet_tmp.deep + 1 == 3) {
                            if (max < tet_tmp.sum + paper[tet_tmp.visiti[k]][tet_tmp.visitj[k] - 1]) {
                                max = tet_tmp.sum + paper[tet_tmp.visiti[k]][tet_tmp.visitj[k] - 1];
                            }
                        }
                        else {
                            push(tet_tmp.visiti[k], tet_tmp.visitj[k] - 1, tet_tmp.sum + paper[tet_tmp.visiti[k]][tet_tmp.visitj[k] - 1], tet_tmp.deep + 1, tet_tmp.visiti, tet_tmp.visitj);
                        }
                    }

                }




            }

        }
    }


    printf("%d\n", max);
    return 0;
}