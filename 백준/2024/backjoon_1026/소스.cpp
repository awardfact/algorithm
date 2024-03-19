#include <stdio.h>
#include <stdlib.h>

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

int compare2(const void* a, const void* b) {
    if (*(int*)a > *(int*)b) {
        return -1;
    }
    else if (*(int*)a == *(int*)b) {
        return 0;
    }
    else {
        return 1;
    }

}



int main() {
    int n;
    int a[100];
    int b[100];
    int i = 0;
    int s = 0;
    scanf("%d", &n);
    //a�Է�
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    //b�Է�
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    //������ �ϳ��� ���� �ϳ��� �������� �ؼ� ���� �迭�� ����
    qsort(a, n, sizeof(int), compare);
    qsort(b, n, sizeof(int), compare2);

    for (i = 0; i < n; i++) {
        s += a[i] * b[i];
    }

    printf("%d\n", s);






    return 0;
}