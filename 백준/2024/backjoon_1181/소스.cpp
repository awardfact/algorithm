#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�� �Լ� 
int compare(const void* a, const void* b) {

    if (strlen((char*)a) > strlen((char*)b)) {
        return 1;
    }
    else if (strlen((char*)a) < strlen((char*)b)) {
        return -1;
    }
    else {
        return strcmp((char*)a, (char*)b);

    }


}


int main() {
    char string[20000][51];
    char before[51];
    int n, i;

    scanf("%d", &n);
    //���ڿ� �Է¹���
    for (i = 0; i < n; i++) {
        scanf("%s", string[i]);
    }
    //���Ľ���
    qsort(string, n, 51, compare);
    //�������� ���� ������ ���
    for (i = 0; i < n; i++) {
        if (strcmp(string[i], before) != 0) {
            printf("%s\n", string[i]);
        }
        strcpy(before, string[i]);
    }








    return 0;
}