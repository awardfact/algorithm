#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    if (*(char*)a > *(char*)b) {
        return -1;
    }
    else if (*(char*)a == *(char*)b) {
        return 0;
    }
    else {
        return 1;
    }

}


int main() {
    char n[1000000];
    int i = 0;
    int sum = 0;

    //N을 입력받는다 
    scanf("%s", n);

    // N을 내림차순으로 정렬한다 
    qsort(n, strlen(n), sizeof(char), compare);

    //30의 배수의 공식은 끝자리가 0이면서 3의 배수여서 끝자리 0아니면 -1
    if (n[strlen(n) - 1] != '0') {
        printf("-1");
    }
    else {

        //3의 배수 구하는 공식은 자릿수의 합이 3의 배수이기 떄문에 자릿수를 다 더함
        for (i = 0; i < strlen(n); i++) {
            sum += n[i] - 48;
        }

        //자릿수의 합이 3의 배수면 값 출력
        if (sum % 3 == 0) {
            printf("%s", n);
        }
        else {
            printf("-1");
        }

    }







    return 0;
}