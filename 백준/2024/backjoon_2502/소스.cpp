#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
    int dp[60];
    int d, k, i, j, l;
    int end_flag = 0;

    scanf("%d %d", &d, &k);

    //첫째날 둘째날을 1부터 시작해서 d날에 k값이 나오는지 체크
    for (i = 1; i < k - 1; i++) {
        for (j = 1; j < k - 1; j++) {
            dp[0] = i;
            dp[1] = j;
            for (l = 2; l < d; l++) {
                dp[l] = dp[l - 1] + dp[l - 2];

            }


            if (dp[l - 1] > k) {
                break;
            }
            //d일날 k값이 나오면 break
            if (dp[l - 1] == k) {
                end_flag = 1;
                break;
            }

        }
        if (end_flag == 1) {
            break;
        }
    }

    printf("%d\n%d\n", i, j);




    return 0;
}

