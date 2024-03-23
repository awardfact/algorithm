#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct dividePaperT {
    int startn;
    int endn;
    int startm;
    int endm;


}devidePaper;

devidePaper stack[128];
int top = -1;

void push(int sn, int en, int sm, int em) {
    top++;
    stack[top].startn = sn;
    stack[top].endn = en;
    stack[top].startm = sm;
    stack[top].endm = em;
}

devidePaper pop() {
    return stack[top--];
}


int main() {

    int paper[129][129] = { 0, };
    devidePaper tmp_devide;
    int n;
    int i, j;
    int blue_paper = 0;
    int white_paper = 0;
    int blue;
    int white;
    int flag;
    int nmid;
    int mmid;


    scanf("%d", &n);
    //노드를 입력받음
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &paper[i][j]);
        }
    }

    blue = 0;
    white = 0;
    flag = 0;

    //가장 큰 종이 체크 
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            paper[i][j] ? blue++ : white++;
        }
        //다른 색 있으면 4조각으로 자름 
        if (blue && white) {
            push(1, n / 2, 1, n / 2);
            push(n / 2 + 1, n, 1, n / 2);
            push(1, n / 2, n / 2 + 1, n);
            push(n / 2 + 1, n, n / 2 + 1, n);
            flag = 1;
            break;
        }

        if (flag) {
            break;
        }
    }

    if (blue && white == 0) {
        blue_paper++;
    }
    else if (white && blue == 0) {
        white_paper++;
    }

    while (top >= 0) {
        //printf("top : %d\n", top);
        //조각낸 종이를 가져옴 
        tmp_devide = pop();
        flag = 0;
        blue = 0;
        white = 0;
        //다른 색 있으면 다시 4조각 
        for (i = tmp_devide.startn; i <= tmp_devide.endn; i++) {
            for (j = tmp_devide.startm; j <= tmp_devide.endm; j++) {
                paper[i][j] ? blue++ : white++;
            }
            if (blue && white) {
                nmid = tmp_devide.endn - ((tmp_devide.endn - tmp_devide.startn) / 2);
                mmid = tmp_devide.endm - ((tmp_devide.endm - tmp_devide.startm) / 2);

                push(tmp_devide.startn, nmid - 1, tmp_devide.startm, mmid - 1);
                push(nmid, tmp_devide.endn, tmp_devide.startm, mmid - 1);
                push(tmp_devide.startn, nmid - 1, mmid, tmp_devide.endm);
                push(nmid, tmp_devide.endn, mmid, tmp_devide.endm);
                flag = 1;
            }
            if (flag) {
                break;
            }
        }



        if (blue && white == 0) {
            blue_paper++;
        }
        else if (white && blue == 0) {
            white_paper++;
        }

    }

    printf("%d\n%d", white_paper, blue_paper);
    return 0;
}

