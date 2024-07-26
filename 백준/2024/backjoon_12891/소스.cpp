#include <stdio.h>

int main() {
    int s, p;
    char string[1000001];
    int a, c, g, t;
    int acnt = 0;
    int ccnt = 0;
    int gcnt = 0;
    int tcnt = 0;
    int i;
    int pass_cnt = 0;

    scanf("%d %d", &s, &p);
    scanf("%s", string);
    scanf("%d %d %d %d", &a, &c, &g, &t);

    //먼저 p길이만큼 문자열을 구해서 acgt개수를 구한다
    for (i = 0; i < p - 1; i++) {
        if (string[i] == 'A') {
            acnt++;
        }
        else if (string[i] == 'C') {
            ccnt++;
        }
        else if (string[i] == 'G') {
            gcnt++;
        }
        else if (string[i] == 'T') {
            tcnt++;
        }
    }

    //p부터 시작해서 i번쨰 문자열을 넣고 현재 p길이만큼 문자열이 패스워드를 충족하는지 체크하고 문자열 위치를 한칸 뒤로 이동시키기 위해 맨 앞 문자열 문자를 뺸다
    for (i = p - 1; i < s; i++) {
        if (string[i] == 'A') {
            acnt++;
        }
        else if (string[i] == 'C') {
            ccnt++;
        }
        else if (string[i] == 'G') {
            gcnt++;
        }
        else if (string[i] == 'T') {
            tcnt++;
        }

        if (acnt >= a && ccnt >= c && gcnt >= g && tcnt >= t) {
            pass_cnt++;
        }

        //printf("i : %d acnt : %d ccnt : %d gcnt : %d tcnt : %d\n", i, acnt, ccnt, gcnt, tcnt);

        if (string[i - (p - 1)] == 'A') {
            acnt--;
        }
        else if (string[i - (p - 1)] == 'C') {
            ccnt--;
        }
        else if (string[i - (p - 1)] == 'G') {
            gcnt--;
        }
        else if (string[i - (p - 1)] == 'T') {
            tcnt--;
        }

    }

    printf("%d\n", pass_cnt);


    return 0;
}