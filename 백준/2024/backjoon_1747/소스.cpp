#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//�Ҹ���� ���ϴ� �Լ� 
int penlindron(int n) {

    char num_string[10];
    int tmp = n;
    int i = 0;
    while (tmp > 0) {
        num_string[i++] = tmp % 10;
        tmp /= 10;
    }


    i--;
    while (i >= 0) {
        if (n % 10 != num_string[i--]) {
            return -1;
        }
        n /= 10;
    }

    return 1;
}


int main() {
    int i, j, n, k, l;
    int num[1300000] = { 0, };
    int sosu[500000];


    num[1] = 1;
    scanf("%d", &n);
    //�����佺ä�� �Ҽ��� ����
    for (i = 2; i < 1300000; i++) {
        for (j = i + i; j < 1300000; j = j + i) {
            num[j] = 1;
        }
    }


    j = 0;
    //n���� �Ҽ��� ���� sosu�迭�� ����
    for (i = n; i < 1300000; i++) {


        if (num[i] == 0) {
            sosu[j++] = i;
        }
    }



    //n���� ū �Ҽ����� �Ҹ���� ù��°�� ��ã���� ���
    for (i = 0; i < j; i++) {

        //printf("sosu : %d %d\n", sosu[i], penlindron(sosu[i]));
        if (penlindron(sosu[i]) == 1) {
            printf("%d\n", sosu[i]);
            break;
        }


    }


    return 0;
}

