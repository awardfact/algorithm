#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
    int i, j, n, p;
    int gt[6][300000] = { 0, };
    int len[6] = { 0, };
    int um, flet;
    int um_num, flet_num;
    int cnt = 0;

    scanf("%d %d", &um_num, &flet_num);
    //음과 플랫을 입력받고 입력받은 플렛이 기존 플랫들보다 크면 뒤에 추가하고 작으면 큰것들을 배열에서 삭제한다
    for (i = 0; i < um_num; i++) {
        scanf("%d %d", &um, &flet);

        for (j = len[um - 1] - 1; j >= 0; j--) {
            // 누른 더 큰 플랫이 있으면 삭제하고 카운트해줌
            if (flet < gt[um - 1][j]) {
                len[um - 1]--;
                cnt++;
            }
            else {
                break;
            }
        }

        // 큰거는 삭제했고 같은게 아니면 누르고 카운트
        if (gt[um - 1][len[um - 1] - 1] != flet) {
            gt[um - 1][len[um - 1]++] = flet;
            cnt++;
        }



    }


    printf("%d\n", cnt);


    return 0;
}

