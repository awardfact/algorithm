#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {

    if (*(int*)a > *(int*)b) {
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
    int n, b, k;
    int min, i, j;
    int failure[100000];
    int start;
    int end;
    int cnt;
    int com_flag = 0;

    min = 0x7FFFFFFF;
    scanf("%d %d %d", &n, &k, &b);

    for (i = 0; i < b; i++) {
        scanf("%d", &failure[i]);

    }
    //고장난거 정렬
    qsort(failure, b, sizeof(int), compare);

    //고장난거 반복 돌려서 k개 연결시키려면 고장 i번째부터 몇개 고쳐야하는지 계산해서 낮은거 추출
    for (i = 0; i < b; i++) {
        //1이면 1부터시작
        if (i == 0) {
            start = 1;

            //이외에는 이전 고장 + 1
        }
        else {
            start = failure[i - 1] + 1;
        }
        com_flag = 0;
        cnt = 0;

        //현재꺼부터 반복 돌아서 고쳐야 하는지 판단
        for (j = i; j < b; j++) {

            end = failure[j] - 1;
            if (end - start + 1 >= k) {
                com_flag = 1;
                break;
            }
            else {
                cnt++;
            }

        }

        //못빠져나왔으면 이후에 고장난게 없어서 end는 n으로
        if (com_flag == 0) {
            end = n;
        }

        //  printf("i : %d cnt : %d\n", i, cnt);

          //k개를 이었고 고친 숫자가 min보다 작으면 교체
        if (end - start + 1 >= k && cnt < min) {
            min = cnt;
        }



    }

    end = n;
    start = failure[b - 1] + 1;
    cnt = 0;
    if (end - start + 1 >= k && cnt < min) {
        min = cnt;
    }


    if (b == 0) {
        min = 0;
    }

    printf("%d\n", min);

    return 0;
}