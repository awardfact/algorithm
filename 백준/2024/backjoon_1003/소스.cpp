#include <stdio.h>
#include <stdlib.h>



int main() {

    int t, n;
    int i, j;
    int fiboz[41];
    int fiboo[41];
    scanf("%d", &t);


    for (i = 0; i < t; i++) {
        scanf("%d", &n);
        for (j = 0; j <= n; j++) {
            fiboz[j] = 0;
            fiboo[j] = 0;
        }

        for (j = 0; j <= n; j++) {
            if (j == 0) {
                fiboz[j]++;
            }
            else if (j == 1) {
                fiboo[j]++;
            }
            else {
                fiboz[j] = fiboz[j - 1] + fiboz[j - 2];
                fiboo[j] = fiboo[j - 1] + fiboo[j - 2];
            }

        }

        printf("%d %d\n", fiboz[n], fiboo[n]);



    }





    return 0;
}