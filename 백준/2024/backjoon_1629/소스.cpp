#include <stdio.h>

int main() {

    int n;
    //���� ���
    int left_human[10];
    // ��ġ�� Ű
    int loop[10] = { 0, };
    //��ġ����
    //int loop_batch[10];
    int i, j, left, batch, left_flag;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &left_human[i]);
    }

    // ���ʿ� �ִ� ��� ���� ��� ���� ���� �迭 ����ŭ �� ��ġ�� ��ġ
    for (i = 0; i < n; i++) {
        left = 0;
        batch = 0;
        left_flag = 0;
        //����� �ȼ��ִ� ���� ��� �� ��ŭ �ڷ� �̵��ϰ� �� �̵������� ���� ����� ����ִ� �ڸ��� ã�Ƽ� ��ġ
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