#include <stdio.h>


int main() {

    int t;
    int n;
    int i;
    int dp[11] = { 0 };

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (i = 4; i <= 11; i++) {
        // 전 숫자의 방법에서 전부 +_1을 더하는 방법과 -2 숫자에서 전부 +2를 더하는 방법과 -3숫자에서 전부 +3을 더하는 방법을 더해서 i번째 방법 수를 구함
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%d\n", dp[n]);

    }

    return 0;
}