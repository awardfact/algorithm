#include <stdio.h>
#include <stdlib.h>



void lis(int* array, int* len, int n) {
    int max = *len;
    int min = 0;
    int mid = (min + max) / 2;

    if (*len == 0) {

        array[0] = n;
        *len += 1;
        return;
    }


    if (array[0] > n) {
        array[0] = n;
        return;
    }

    if (array[*len - 1] < n) {
        array[*len] = n;
        *len += 1;
        return;
    }


    while (min <= max) {

        mid = (min + max) / 2;
        if (array[mid] == n) {
            mid = -1;
            break;
        }if (array[mid] > n) {
            max = mid - 1;
        }
        else if (array[mid] < n) {
            min = mid + 1;
        }


    }

    //   printf("mid : %d array[mid] : %d n : %d\n", mid, array[mid], n);
    if (mid != -1) {

        if (array[mid] > n) {
            array[mid] = n;
        }
        else {
            array[mid + 1] = n;
        }


    }


}



int main() {
    int n, i, j;
    int cnt = 0;
    int max = 0;
    int len = 0;
    int box[1000];
    int box_cnt[1000] = { 0, };
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &box[i]);
    }

    //최장증가 부분 수열로 가장 긴 증가 수열을 구함
    for (i = 0; i < n; i++) {
        //printf("i : %d n : %d\n", i, box[i]);

        lis(box_cnt, &len, box[i]);



    }
    printf("%d\n", len);
    return 0;
}