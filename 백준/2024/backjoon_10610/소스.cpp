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

    //N�� �Է¹޴´� 
    scanf("%s", n);

    // N�� ������������ �����Ѵ� 
    qsort(n, strlen(n), sizeof(char), compare);

    //30�� ����� ������ ���ڸ��� 0�̸鼭 3�� ������� ���ڸ� 0�ƴϸ� -1
    if (n[strlen(n) - 1] != '0') {
        printf("-1");
    }
    else {

        //3�� ��� ���ϴ� ������ �ڸ����� ���� 3�� ����̱� ������ �ڸ����� �� ����
        for (i = 0; i < strlen(n); i++) {
            sum += n[i] - 48;
        }

        //�ڸ����� ���� 3�� ����� �� ���
        if (sum % 3 == 0) {
            printf("%s", n);
        }
        else {
            printf("-1");
        }

    }







    return 0;
}