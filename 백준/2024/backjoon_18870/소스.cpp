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

        //��ȣ�� �����ص�
        x[i].order = i;
    }


    // ���� ������������ ����
    qsort(x, n, sizeof(zip), compare);

    //���������� �°� ���� ����
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

    //�ٽ� ��ȣ�� ����
    qsort(x, n, sizeof(zip), compare_order);
    //�Է��ߴ� ������ ���� ���
    for (i = 0; i < n; i++) {
        printf("%d ", x[i].rate);

    }


    //printf("%d\n", cnt);

    return 0;
}
