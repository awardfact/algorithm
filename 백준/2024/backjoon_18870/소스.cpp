#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


typedef struct zipT {

    int num;
    int rate;
    int order;
}zip;



int compare(const void* a, const void* b) {
    zip* coma = (zip*)a;
    zip* comb = (zip*)b;
    if (coma->num > comb->num) {
        return 1;
    }
    else if (coma->num == comb->num) {
        return 0;
    }
    else {
        return -1;
    }


}


int compare_order(const void* a, const void* b) {
    zip* coma = (zip*)a;
    zip* comb = (zip*)b;
    if (coma->order > comb->order) {
        return 1;
    }
    else if (coma->order == comb->order) {
        return 0;
    }
    else {
        return -1;
    }


}



int main() {

    int n, i;
    zip x[1000000];
    int before = 0x7FFFFFFF;
    int rate = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x[i].num);

        //번호를 저장해둠
        x[i].order = i;
    }


    // 숫자 오름차순으로 정렬
    qsort(x, n, sizeof(zip), compare);

    //오름차순에 맞게 순위 배정
    for (i = 0; i < n; i++) {
        if (i == 0) {
            before = x[i].num;
            x[i].rate = rate;
            continue;
        }

        if (before == x[i].num) {
            x[i].rate = rate;

        }
        else {
            x[i].rate = ++rate;
            before = x[i].num;
        }

    }

    //다시 번호로 정렬
    qsort(x, n, sizeof(zip), compare_order);
    //입력했던 순으로 순위 출력
    for (i = 0; i < n; i++) {
        printf("%d ", x[i].rate);

    }


    //printf("%d\n", cnt);

    return 0;
}
