#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {

    int t, i, n;

    long long first_set[50];
    long long second_set[50];
    long long triangle[100];
    int triangle_len = 0;
    char first_flag = 1;


    //바로 이전 다른색 + 그 전전 다른색으로 계산해서 값을 미리 구함
    first_set[0] = 1;
    triangle[triangle_len++] = 1;
    second_set[0] = 1;
    triangle[triangle_len++] = 1;
    first_set[1] = 1;
    triangle[triangle_len++] = 1;
    second_set[1] = 2;
    triangle[triangle_len++] = 2;
    first_set[2] = 2;
    triangle[triangle_len++] = 2;
    second_set[2] = 3;
    triangle[triangle_len++] = 3;
    i = 3;
    while (i < 50) {
        if (first_flag) {
            triangle[triangle_len] = second_set[i - 1] + second_set[i - 3];
            first_set[i] = triangle[triangle_len++];
            first_flag = 0;
        }
        else {
            triangle[triangle_len] = first_set[i] + first_set[i - 2];
            second_set[i] = triangle[triangle_len++];
            first_flag = 1;
            i++;
        }
    }




    // for(i = 0;i<100; i++){
    //     printf("%lld\n", triangle[i]);

    // }

    scanf("%d", &t);
    //구한 값 출력
    for (i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%lld\n", triangle[n - 1]);


    }




    return 0;
}