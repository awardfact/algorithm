#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//비교 함수 
int compare(const void* a, const void* b) {

    if (strlen((char*)a) > strlen((char*)b)) {
        return 1;
    }
    else if (strlen((char*)a) < strlen((char*)b)) {
        return -1;
    }
    else {
        return strcmp((char*)a, (char*)b);

    }


}


int main() {
    char string[20000][51];
    char before[51];
    int n, i;

    scanf("%d", &n);
    //문자열 입력받음
    for (i = 0; i < n; i++) {
        scanf("%s", string[i]);
    }
    //정렬실행
    qsort(string, n, 51, compare);
    //이전꺼와 같지 않으면 출력
    for (i = 0; i < n; i++) {
        if (strcmp(string[i], before) != 0) {
            printf("%s\n", string[i]);
        }
        strcpy(before, string[i]);
    }








    return 0;
}