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
    //���� �÷��� �Է¹ް� �Է¹��� �÷��� ���� �÷��麸�� ũ�� �ڿ� �߰��ϰ� ������ ū�͵��� �迭���� �����Ѵ�
    for (i = 0; i < um_num; i++) {
        scanf("%d %d", &um, &flet);

        for (j = len[um - 1] - 1; j >= 0; j--) {
            // ���� �� ū �÷��� ������ �����ϰ� ī��Ʈ����
            if (flet < gt[um - 1][j]) {
                len[um - 1]--;
                cnt++;
            }
            else {
                break;
            }
        }

        // ū�Ŵ� �����߰� ������ �ƴϸ� ������ ī��Ʈ
        if (gt[um - 1][len[um - 1] - 1] != flet) {
            gt[um - 1][len[um - 1]++] = flet;
            cnt++;
        }



    }


    printf("%d\n", cnt);


    return 0;
}

