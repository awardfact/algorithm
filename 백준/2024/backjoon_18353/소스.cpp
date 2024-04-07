#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int binary_search(int* array, int len, int n) {

    int min = 0;
    int max = len - 1;
    int mid;

    if (array[max] > n) {
        return len;
    }

    if (array[min] < n) {
        return 0;
    }

    while (min <= max) {
        mid = (min + max) / 2;


        if (array[mid] == n) {
            return -1;
        }if (array[mid] < n) {
            max = mid - 1;

        }
        else {
            min = mid + 1;
        }


    }
    //    printf("n : %d mid %d \n", n,mid);

    return mid;



}


int main() {
    int soldier[2000];
    int sort_soldier[2000] = { 0, };
    int n, i;
    int len = 0;
    int index;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &soldier[i]);
    }


    sort_soldier[0] = soldier[0];
    len = 1;
    //최장 감소 부분 수열 방식으로 반복문 + 이진탐색으로 제일 크면 맨 앞 제일 작으면 맨 뒤로 이동하고 사이 값들은 더 큰경우에만 변경
    for (i = 1; i < n; i++) {
        index = binary_search(sort_soldier, len, soldier[i]);
        // printf("len : %d\n", len);

       //  printf("index : %d n : %d\n", index, soldier[i]);
        if (index != -1) {

            if (sort_soldier[index] < soldier[i]) {
                sort_soldier[index] = soldier[i];
            }
            else {
                sort_soldier[index + 1] = soldier[i];
            }

            if (len == index) {
                len++;
            }
        }

    }

    for (i = 0; i < n; i++) {
        //   printf("%d ", sort_soldier[i]);

    }
    //n에서 최장 수열 뺴서 출력
    printf("%d\n", n - len);

    return 0;
}



