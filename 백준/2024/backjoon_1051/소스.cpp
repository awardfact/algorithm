#include <stdio.h>
#include <string.h>
#include <stdlib.h>





int main() {

    int n, m, i, j;
    char square[50][50];
    char big = 0;
    char big_tmp = 0;

    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%s", square[i]);
    }

    i = 0;
    j = 0;
    big_tmp = 1;
    //���� ��ܺ��� �����ؼ� ���ݱ��� ���� �ִ� ���簢������ ū �������� ���� ���簢���� �ִ��� �˻� 
    while (i < n && j < m) {
        if (i + big_tmp < n && j + big_tmp < m) {

            // printf("i : %d j : %d big_tmp : %d\n", i,j, big_tmp);
            if (square[i][j] == square[i + big_tmp][j] && square[i][j] == square[i][j + big_tmp] && square[i][j] == square[i + big_tmp][j + big_tmp]) {

                big = big_tmp;
            }
            big_tmp++;

        }
        else {
            big_tmp = big;
            j++;
            if (j >= m) {
                j = 0;
                i++;
            }


        }








    }

    if (big == 0) {
        printf("1\n");
    }
    else {
        big++;
        printf("%d\n", big * big);
    }



    return 0;
}


