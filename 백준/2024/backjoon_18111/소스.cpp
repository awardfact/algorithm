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
    //���̸� ��� �ε��� ������ ������ ����
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &input_num);
            ground[input_num]++;
        }
    }

    //�ִ� ���̺��� �� ���̷� ���� �� �ִ��� ����ٸ� �ð��� �󸶳� �ɸ����� ��� 
    for (i = 256; i >= 0; i--) {
        block = b;
        time = 0;
        for (j = 256; j >= 0; j--) {
            if (j == i || ground[j] == 0) {
                continue;
            }
            //�����ɷ� ���⋚
            if (i > j) {
                //�ɸ��� �ð� 
                time = time + ((i - j) * ground[j]);
                //��� ���� 
                block = block - ((i - j) * ground[j]);
                if (block < 0) {
                    time = -1;
                    break;
                }

                //�����ɷ� ���⶧
            }
            else {



                //�ɸ��� �ð� 
                time = time + (((j - i) * 2) * ground[j]);
                //����� ����
                block = block + ((j - i) * ground[j]);



            }
            //  printf("i : %d j : %d time ; %d block : %d\n",i,j, time, block);
        }

        //�ּ� �ð����� �ð��� �� �پ����� �� �ð����� ���� 
        if (time != -1 && min_time > time) {
            min_time = time;
            min_time_block = i;
        }


    }


    printf("%d %d\n", min_time, min_time_block);
    return 0;
}



