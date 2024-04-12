#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
    int n, m, b;
    int i, j;
    int ground[257] = { 0, };
    int input_num;
    int block;
    int time;
    int min_time = 0x7FFFFFFF;
    int min_time_block;

    scanf("%d %d %d", &n, &m, &b);
    //높이를 블록 인덱스 개수를 값으로 설정
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &input_num);
            ground[input_num]++;
        }
    }

    //최대 높이부터 그 높이로 맞출 수 있는지 맞춘다면 시간은 얼마나 걸리는지 계산 
    for (i = 256; i >= 0; i--) {
        block = b;
        time = 0;
        for (j = 256; j >= 0; j--) {
            if (j == i || ground[j] == 0) {
                continue;
            }
            //높은걸로 맞출떄
            if (i > j) {
                //걸리는 시간 
                time = time + ((i - j) * ground[j]);
                //블록 감소 
                block = block - ((i - j) * ground[j]);
                if (block < 0) {
                    time = -1;
                    break;
                }

                //낮은걸로 맞출때
            }
            else {



                //걸리는 시간 
                time = time + (((j - i) * 2) * ground[j]);
                //블록은 증가
                block = block + ((j - i) * ground[j]);



            }
            //  printf("i : %d j : %d time ; %d block : %d\n",i,j, time, block);
        }

        //최소 시간보다 시간이 더 줄었으면 그 시간으로 변경 
        if (time != -1 && min_time > time) {
            min_time = time;
            min_time_block = i;
        }


    }


    printf("%d %d\n", min_time, min_time_block);
    return 0;
}



