#include <stdio.h>
#include <string.h>

//팬린드롬 체크 함수 
int panrindropCheck(char* string) {

    int i;
    //앞뒤 다르면 0 리턴
    for (i = 0; i < strlen(string); i++) {
        //printf("string[i] : %c  string[strlen] : %c\n",string[i], string[strlen(string) - i - 1]);
        if (string[i] != string[strlen(string) - i - 1]) {
            return 0;
        }

    }

    // printf("string : %s start : %d\n",string, start);
    return 1;

}


int main() {

    char s[101];
    int i = 0;
    int len = 0;
    scanf("%s", s);


    //문자열에서 i부터 보면 팬린드롬인 경우 문자열 뒤에 i -1부터 0까지 문자열을 추가하면 팬린드롬이 된다
    for (i = 0; i < strlen(s) - 1; i++) {

        if (panrindropCheck(s + i)) {
            i--;
            break;
        }

    }

    //printf("%d %d \n", strlen(s), i);

    //문자열 추가 위치 저장
    len = strlen(s);
    //문자열 안에 팬린드롬이 없으면 끝에서 2번쨰 자리부터 추가 
    if (i == strlen(s) - 1) {
        i = len - 2;
    }

    //팬린드롬이 나올떄까지 i를 줄이면서 i번쨰 문자열을 끝에 추가 
    while (!panrindropCheck(s)) {

        //printf("%s\n", s);
        len = strlen(s);

        s[len++] = s[i--];
        s[len] = 0;


    }


    printf("%ld\n", strlen(s));



    return 0;
}