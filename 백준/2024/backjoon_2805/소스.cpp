#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {

    if (*(int*)a < *(int*)b) {
        return 1;
    }
    else if (*(int*)a == *(int*)b) {
        return 0;
    }
    else {
        return -1;
    }

}



int main() {
    int tree[1000001];
    unsigned int find_length;
    int tree_cnt, i;
    int mid, max, min;
    unsigned int cut_length;
    int big_flag;

    scanf("%d %d", &tree_cnt, &find_length);

    for (i = 0; i < tree_cnt; i++) {
        scanf("%d", &tree[i]);
    }

    //���̸� ������������ ����
    qsort(tree, tree_cnt, sizeof(int), compare);

    //����Ž���� �ϱ� ���� min,max�� ����
    mid = tree[0] / 2;
    max = tree[0];
    min = 0;

    for (i = 0; i < tree_cnt; i++) {
        //   printf("%d\n", tree[i]);
    }

    i = 0;
    //�� ���� �� ���������� �ݺ�
    while (min + 1 != max) {
        //printf("min : %d mid : %d max : %d\n", min,mid,max);
        cut_length = 0;
        big_flag = 0;
        //mid���̷� �߶� ã�� ���̺��� ��� �ƴϸ� ª�� �������� üũ ��� ������ flag�� ���� 
        for (i = 0; i < tree_cnt; i++) {
            if (mid < tree[i]) {
                cut_length += tree[i] - mid;
            }

            if (cut_length >= find_length) {
                big_flag = 1;
                break;
            }

        }

        //ũ�� �ִ� ���̸� mid�� �����ؾ���
        if (big_flag == 1) {
            min = mid;
            mid = (min + max) / 2;

            //ª���� �ּ�ġ�� mid�� �����ؾ���
        }
        else {
            max = mid;
            mid = (min + max) / 2;
        }


    }

    printf("%d", mid);

    return 0;
}

