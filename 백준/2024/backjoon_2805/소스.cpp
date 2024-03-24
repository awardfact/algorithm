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

    //길이를 내림차순으로 정렬
    qsort(tree, tree_cnt, sizeof(int), compare);

    //이진탐색을 하기 위한 min,max값 설정
    mid = tree[0] / 2;
    max = tree[0];
    min = 0;

    for (i = 0; i < tree_cnt; i++) {
        //   printf("%d\n", tree[i]);
    }

    i = 0;
    //더 나눌 수 없을떄까지 반복
    while (min + 1 != max) {
        //printf("min : %d mid : %d max : %d\n", min,mid,max);
        cut_length = 0;
        big_flag = 0;
        //mid높이로 잘라서 찾는 길이보다 길게 아니면 짧게 나오는지 체크 길게 나오면 flag를 설정 
        for (i = 0; i < tree_cnt; i++) {
            if (mid < tree[i]) {
                cut_length += tree[i] - mid;
            }

            if (cut_length >= find_length) {
                big_flag = 1;
                break;
            }

        }

        //크면 최대 높이를 mid로 설정해야함
        if (big_flag == 1) {
            min = mid;
            mid = (min + max) / 2;

            //짧으면 최소치를 mid로 설정해야함
        }
        else {
            max = mid;
            mid = (min + max) / 2;
        }


    }

    printf("%d", mid);

    return 0;
}

