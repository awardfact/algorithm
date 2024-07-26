#include <stdio.h>

int main() {

    int n;
    //왼쪽 사람
    int left_human[10];
    // 위치별 키
    int loop[10] = { 0, };
    //위치여부
    //int loop_batch[10];
    int i, j, left, batch, left_flag;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &left_human[i]);
    }

    // 왼쪽에 있는 사람 수가 사람 서지 않은 배열 수만큼 된 위치에 배치
    for (i = 0; i < n; i++) {
        left = 0;
        batch = 0;
        left_flag = 0;
        //사람이 안서있는 왼쪽 사람 수 만큼 뒤로 이동하고 다 이동했으면 가장 가까운 비어있는 자리를 찾아서 위치
        for (j = 0; j < n; j++) {


            if (left == left_human[i]) {
                left_flag = 1;


            }

            if (loop[j] == 0) {

                if (left_flag) {
                    batch = j;
                    break;
                }
                else {
                    left++;
                }

            }



        }

        // if(batch == 0){
        //     batch = j -1;
        // }

        //printf("batch : %d\n", batch);
        loop[batch] = i + 1;

    }


    for (i = 0; i < n; i++) {
        printf("%d ", loop[i]);
    }


    return 0;
}