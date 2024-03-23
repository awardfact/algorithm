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



    // 2칸까지 세팅해줌
    step_max[0] = step[0];
    step_max[1] = step[0] + step[1];
    if (step[2] + step[2 - 1] > step[2] + step[2 - 2]) {
        step_max[2] = step[2] + step[2 - 1];
    }
    else {
        step_max[2] = step[2] + step[2 - 2];
    }
    //printf("max : %d\n",step_max[2]);

    //3칸부터는 2칸 점프면 그냥 점프하면 되는데 1칸 이동하면 2칸이 연속이기 떄문에 1칸 전은 무조건 2칸 전이어야댐
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
