#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct RGBT {
    int r;
    int g;
    int b;

}RGB;



//���� �� ����
int min_value(int a, int b) {


    if (a >= b) {
        return b;

    }
    else {
        return a;
    }


}


int main() {

    int n, i, j;
    RGB rgb[1000];
    int dp[1000][3];
    int min;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &rgb[i].r, &rgb[i].g, &rgb[i].b);

    }


    //���� �������� �� ���� ���� 
    dp[0][0] = rgb[0].r;
    dp[0][1] = rgb[0].g;
    dp[0][2] = rgb[0].b;

    //���������� r g b�� �����߰� �� ���� ���� ������ dp[i][��]�� ��
    for (i = 1; i < n; i++) {

        dp[i][0] = rgb[i].r + min_value(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = rgb[i].g + min_value(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = rgb[i].b + min_value(dp[i - 1][0], dp[i - 1][1]);

    }

    //���� ���� ���� ���
    if (dp[n - 1][0] <= dp[n - 1][1] && dp[n - 1][0] <= dp[n - 1][2]) {
        printf("%d\n", dp[n - 1][0]);
    }
    else if (dp[n - 1][1] <= dp[n - 1][2]) {
        printf("%d\n", dp[n - 1][1]);
    }
    else {
        printf("%d\n", dp[n - 1][2]);
    }

    return 0;
}



