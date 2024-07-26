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

            //행성이 시작점 안에 포함되고 도착점 안에 포함되지 않으면 무조건 나가야해서 +
            if ((x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy) < r * r) {
                if ((x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy) >= r * r) {
                    cnt++;
                }
                //시작점 안에 포함되지 않지만 도착점이 포함되면 무조건 방문해야해서 +
            }
            else if ((x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy) < r * r) {
                cnt++;
            }

        }

        printf("%d\n", cnt);
    }


    return 0;
}


