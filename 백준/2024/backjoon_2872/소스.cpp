#include <stdio.h>

int main() {

    int n, i;
    int book[300000];
    int cnt = 0;
    int max = 0;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &book[i]);
    }

    //������ �ٲ۴ٴ� �� ū ���ڰ� �տ� �ִٴ°� + �� ū ���ڰ� �տ� ������ �� ���ں��� ���� ���ڴ� ��� ������ �ٲ����
    // ������ �ٲ� �����߿� ���� ū ���ڸ� ã�� �� ���� ������ ���� ū ���� ã�Ƽ� �װ� �� ���� �ø� �̰� �ø��� �� �������ڵ� �÷�����
    for (i = 0; i < n - 1; i++) {
        if (book[i] > book[i + 1] && book[i] > max) {
            max = book[i];
        }
        else if (max != 0 && book[i] > cnt && book[i] < max) {
            cnt = book[i];
        }

    }

    if (max != 0 && book[n - 1] > cnt && book[i] < max) {
        cnt = book[n - 1];
    }

    printf("%d\n", cnt);
    return 0;
}