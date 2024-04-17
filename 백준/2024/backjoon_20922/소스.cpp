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
    //입력
    for (i = 0; i < n; i++) {
        scanf("%d ", &input_array[i]);
    }



    for (i = 0; i < n; i++) {
        array[input_array[i]]++;
        // i번째 입력을 배열에 넣고 그 입력과 같은 수가 k가 넘는지 체크
        if (array[input_array[i]] > k) {
            //k를 넘는다면 최장 부분 수열을 할 수 없기 때문에 부분수열이 가능해질떄까지 시작점을 움직인다
            while (array[input_array[i]] > k) {
                array[input_array[start]]--;
                start++;
            }

        }
        else {
            //k를 넘지 않으면 수열의 길이를 연장할 수 있다 끝 지점을 i로 하고 최장인지 체크
            end = i;
            if (max_cnt < end - start) {
                max_cnt = end - start;
            }
        }


    }

    //최장 수열 길이 출력
    printf("%d\n", max_cnt + 1);


    return 0;
}

