#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
    int n, k, i;
    int array[100001] = { 0, };
    int input_array[200001] = { 0, };
    int max_cnt = 0;
    int start = 0;
    int end = 0;


    scanf("%d %d", &n, &k);
    //�Է�
    for (i = 0; i < n; i++) {
        scanf("%d ", &input_array[i]);
    }



    for (i = 0; i < n; i++) {
        array[input_array[i]]++;
        // i��° �Է��� �迭�� �ְ� �� �Է°� ���� ���� k�� �Ѵ��� üũ
        if (array[input_array[i]] > k) {
            //k�� �Ѵ´ٸ� ���� �κ� ������ �� �� ���� ������ �κм����� �������������� �������� �����δ�
            while (array[input_array[i]] > k) {
                array[input_array[start]]--;
                start++;
            }

        }
        else {
            //k�� ���� ������ ������ ���̸� ������ �� �ִ� �� ������ i�� �ϰ� �������� üũ
            end = i;
            if (max_cnt < end - start) {
                max_cnt = end - start;
            }
        }


    }

    //���� ���� ���� ���
    printf("%d\n", max_cnt + 1);


    return 0;
}

