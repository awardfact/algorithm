#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main() {

    int step[300];
    int step_max[300];
    int step_cnt;
    char one_cnt;
    int i;

    scanf("%d", &step_cnt);
    for (i = 0; i < step_cnt; i++) {
        scanf("%d", &step[i]);
    }



    // 2ĭ���� ��������
    step_max[0] = step[0];
    step_max[1] = step[0] + step[1];
    if (step[2] + step[2 - 1] > step[2] + step[2 - 2]) {
        step_max[2] = step[2] + step[2 - 1];
    }
    else {
        step_max[2] = step[2] + step[2 - 2];
    }
    //printf("max : %d\n",step_max[2]);

    //3ĭ���ʹ� 2ĭ ������ �׳� �����ϸ� �Ǵµ� 1ĭ �̵��ϸ� 2ĭ�� �����̱� ������ 1ĭ ���� ������ 2ĭ ���̾�ߴ�
    for (i = 3; i < step_cnt; i++) {

        if (step[i] + step_max[i - 3] + step[i - 1] > step[i] + step_max[i - 2]) {
            step_max[i] = step[i] + step_max[i - 3] + step[i - 1];
        }
        else {
            step_max[i] = step[i] + step_max[i - 2];
            one_cnt = 0;
        }



    }

    printf("%d\n", step_max[step_cnt - 1]);
    return 0;
}
