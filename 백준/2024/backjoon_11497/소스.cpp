#include <stdio.h>
#include <stdlib.h>

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

    int t, i, j, n;
    int tree[10000];
    int array_tree[10000];
    int rank;
    int left, right, array_left, array_right;
    int right_flag = 0;

    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        scanf("%d", &n);

        rank = 0;
        for (j = 0; j < n; j++) {
            scanf("%d", &tree[j]);
        }


        qsort(tree, n, sizeof(int), compare);


        // for(j = 0; j < n; j++){
        //     printf("%d ", tree[j]);
        // }





        //가운데에 가장 큰걸 놓고 그다음 작은것들을 왼쪽 오른쪽에 놓는다 
        j = 0;
        array_left = n / 2 - 1;
        array_right = n / 2 + 1;
        array_tree[n / 2] = tree[j++];

        right_flag = 0;
        while (j < n) {

            if (right_flag == 1) {
                array_tree[array_right++] = tree[j++];
                right_flag = 0;
            }
            else {
                array_tree[array_left--] = tree[j++];
                right_flag = 1;
            }


        }


        //난이도 계산
        if (rank < abs(array_tree[0] - array_tree[n - 1])) {
            rank = abs(array_tree[0] - array_tree[n - 1]);
        }


        for (j = 1; j < n; j++) {

            if (rank < abs(array_tree[j] - array_tree[j - 1])) {
                rank = abs(array_tree[j] - array_tree[j - 1]);
            }

        }

        // for(j = 0; j < n; j++){
        //     printf("%d ", array_tree[j]);
        // }


        printf("%d\n", rank);

    }

    return 0;
}