#include <stdio.h>
#include <string.h>
#include <stdlib.h>





int main() {

    int t, n;
    int i, j;
    int x1, y1, x2, y2;
    int cx, cy, r;
    int cnt;

    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        scanf("%d", &n);
        cnt = 0;
        for (j = 0; j < n; j++) {
            scanf("%d %d %d", &cx, &cy, &r);

            //�༺�� ������ �ȿ� ���Եǰ� ������ �ȿ� ���Ե��� ������ ������ �������ؼ� +
            if ((x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy) < r * r) {
                if ((x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy) >= r * r) {
                    cnt++;
                }
                //������ �ȿ� ���Ե��� ������ �������� ���ԵǸ� ������ �湮�ؾ��ؼ� +
            }
            else if ((x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy) < r * r) {
                cnt++;
            }

        }

        printf("%d\n", cnt);
    }


    return 0;
}


