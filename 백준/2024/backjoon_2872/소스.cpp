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

    //순서를 바꾼다는 더 큰 숫자가 앞에 있다는거 + 더 큰 숫자가 앞에 있으면 그 숫자보다 작은 숫자는 모두 순서를 바꿔야함
    // 순서가 바뀐 숫자중에 가장 큰 숫자를 찾고 그 뒤의 숫자중 가장 큰 수를 찾아서 그걸 맨 위로 올림 이거 올리면 더 낮은숫자도 올려야함
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