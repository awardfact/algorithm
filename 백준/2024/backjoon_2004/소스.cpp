#include <stdio.h>

int soinsu(int num, int insu) {

    int cnt = 0;
    long long int insu_tmp = insu;


    //num!에서 구하는 insu가 나오는 개수를 구한다 
    while (num >= insu_tmp) {

        cnt += num / insu_tmp;
        insu_tmp *= insu;
    }

    return cnt;
}


int main() {

    int n, m;
    int n2insu, m2insu, nm2insu;
    int n5insu, m5insu, nm5insu;

    scanf("%d %d", &n, &m);

    //공식 n! / m! n-m!  0의 개수는 소인수분해 2의 개수 5의 개수중 작은 수 
    n5insu = soinsu(n, 5);
    n2insu = soinsu(n, 2);

    m5insu = soinsu(m, 5);
    m2insu = soinsu(m, 2);

    nm5insu = soinsu(n - m, 5);
    nm2insu = soinsu(n - m, 2);

    if (n2insu - m2insu - nm2insu > n5insu - m5insu - nm5insu) {
        printf("%d\n", n5insu - m5insu - nm5insu);
    }
    else {
        printf("%d\n", n2insu - m2insu - nm2insu);
    }



    return 0;
}