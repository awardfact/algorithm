#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int t, i, j, k;
    char function[100010];
    int arr[100010];
    int arr_cnt;
    char char_tmp;
    char string_tmp[10];
    int start_array;
    int end_array;
    int rflag = 0;
    int errflag = 0;
    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        //함수와 크기 입력
        scanf("%s %d", function, &arr_cnt);



        //숫자 입력
        getchar();
        getchar();
        j = 0;
        //숫자를 입력받는다 
        while (j < arr_cnt) {
            scanf("%d,,", &arr[j++]);
            // char_tmp = getchar();
            // if(char_tmp == ',' || char_tmp== ']'){
            //     string_tmp[k] = '\0';
            //     arr[j] = atoi(string_tmp);
            //     k = 0;
            //     j++;
            // }else{
            //    string_tmp[k++]= char_tmp;
            // }
        }
        getchar();
        getchar();
        start_array = 0;
        end_array = arr_cnt - 1;
        rflag = 0;
        errflag = 0;
        //함수탐색해서 함수 실행 
        for (j = 0; j < strlen(function); j++) {

            if (function[j] == 'R') {
                //뒤집기 두번 연속 나오면 그대로 뒤집기 나와도 2번 나오면 동일해지고 그 사이에 d가 나와도 뒤집은 상태면 마지막 빼고 아니면 처음 뺴는 식으로 처리
                if (j + 1 < strlen(function) && function[j + 1] == 'R') {
                    j++;
                }
                else {
                    rflag = rflag ^ 0x01;
                }
            }
            else if (function[j] == 'D') {

                //못빼면 에러 
                if (start_array > end_array) {
                    errflag = 1;
                    break;
                }
                // 뒤집힌 상태면 끝에서 뺌
                if (rflag) {
                    end_array--;
                    //뒤집힌 상태 아니면 처음 뻄
                }
                else {
                    start_array++;
                }
            }

        }



        if (errflag == 1) {
            printf("error\n");
        }
        else {

            printf("[");


            if (rflag) {
                for (j = end_array; j >= start_array; j--) {
                    if (j > start_array) {
                        printf("%d,", arr[j]);
                    }
                    else {
                        printf("%d", arr[j]);
                    }
                }
            }
            else {
                for (j = start_array; j <= end_array; j++) {
                    if (j < end_array) {
                        printf("%d,", arr[j]);
                    }
                    else {
                        printf("%d", arr[j]);
                    }
                }

            }

            printf("]\n");

        }




    }



    return 0;
}

