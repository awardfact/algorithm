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


    // ���� ���ĵ� �ִ� ��- 1�� �Է¹��� ���� ���ؼ� n������ ���� n�� �迭�� �ִ´� 
    for (i = 1; i <= n; i++) {
        scanf("%d", &input);
        sum += input;
        sum_arr[i] = sum;
    }


    // i���� j������ ����  j���� �տ��� i-1�������� ���� ���� �ȴ� 
    for (i = 0; i < m; i++) {
        scanf("%d %d", &sum_start, &sum_end);
        printf("%d\n", sum_arr[sum_end] - sum_arr[sum_start - 1]);
    }



    return 0;
}

