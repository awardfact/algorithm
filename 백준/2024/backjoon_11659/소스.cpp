#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int main() {
    int n, m, i;
    int sum_start, sum_end;
    int sum_arr[100001] = { 0, };
    int sum = 0;
    int input;


    scanf("%d %d", &n, &m);


    // 전부 합쳐도 최대 수- 1억 입력받은 수를 더해서 n까지의 합을 n의 배열에 넣는다 
    for (i = 1; i <= n; i++) {
        scanf("%d", &input);
        sum += input;
        sum_arr[i] = sum;
    }


    // i부터 j번까지 합은  j까지 합에서 i-1번까지의 합을 빼면 된다 
    for (i = 0; i < m; i++) {
        scanf("%d %d", &sum_start, &sum_end);
        printf("%d\n", sum_arr[sum_end] - sum_arr[sum_start - 1]);
    }



    return 0;
}

