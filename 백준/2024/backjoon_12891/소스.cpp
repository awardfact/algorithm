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

    //���� p���̸�ŭ ���ڿ��� ���ؼ� acgt������ ���Ѵ�
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

    //p���� �����ؼ� i���� ���ڿ��� �ְ� ���� p���̸�ŭ ���ڿ��� �н����带 �����ϴ��� üũ�ϰ� ���ڿ� ��ġ�� ��ĭ �ڷ� �̵���Ű�� ���� �� �� ���ڿ� ���ڸ� �A��
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