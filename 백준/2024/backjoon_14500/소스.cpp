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
    //기존 코드는 ㅗ ㅏ ㅓ ㅜ 이 형태의 모양이 나오는 경우는 직접 입력해줘서 블럭 크기가 커지면 해결 할 수 없을꺼 같아서 블록 크기와 상관없게 이어져 있는 모든 노드에서 이을 수 있게 수정
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            visiti_tmp[0] = i;
            visitj_tmp[0] = j;

            // 스택에 현재 노드 위치와 값을 넣고 깊이우선탐색
            push(i, j, paper[i][j], 0, visiti_tmp, visitj_tmp);
            while (top > 0) {

                //스택에서 정보 뻄
                tet_tmp = pop();
                // printf("sum : %d\n", tet_tmp.sum);
                 // 이어져 있는 노드와는 연결이 가능하기 때문에 이어져 있는 노드에서 한칸 옆으로 이동하는데 방문한 곳이 아니면 스택에 집어넣고 길이가 총 4가 되면 크기 계산 
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