#include <stdio.h>
#include <string.h>



int main() {

    int n, i;
    int box[1000];

    box[0] = 1;
    box[1] = 3;

    //n-1 + n-2 *2 하면 n의 경우의 수 
    for (i = 2; i <= 1000; i++) {
        box[i] = (box[i - 1] + box[i - 2] * 2) % 10007;

    }


    scanf("%d", &n);


    printf("%d", box[n - 1]);



    return 0;
}

