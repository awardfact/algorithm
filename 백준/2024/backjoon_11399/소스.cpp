#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare(const void* a, const void* b) {

    if (*(int*)a > *(int*)b) {
        return 1;
    }
    else if (*(int*)a == *(int*)b) {

        return 0;
    }
    else {
        return -1;
    }


}

int main() {


    int n, i;
    int p_time[1000];
    int wait_time = 0;
    int time_sum = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &p_time[i]);
    }

    //오름차순으로 정렬
    qsort(p_time, n, sizeof(int), compare);

    //시간 계산
    for (i = 0; i < n; i++) {
        time_sum += wait_time + p_time[i];
        wait_time += p_time[i];
    }

    printf("%d\n", time_sum);

    return 0;
}