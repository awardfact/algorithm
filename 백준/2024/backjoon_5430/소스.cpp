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
        //�Լ��� ũ�� �Է�
        scanf("%s %d", function, &arr_cnt);



        //���� �Է�
        getchar();
        getchar();
        j = 0;
        //���ڸ� �Է¹޴´� 
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
        //�Լ�Ž���ؼ� �Լ� ���� 
        for (j = 0; j < strlen(function); j++) {

            if (function[j] == 'R') {
                //������ �ι� ���� ������ �״�� ������ ���͵� 2�� ������ ���������� �� ���̿� d�� ���͵� ������ ���¸� ������ ���� �ƴϸ� ó�� ���� ������ ó��
                if (j + 1 < strlen(function) && function[j + 1] == 'R') {
                    j++;
                }
                else {
                    rflag = rflag ^ 0x01;
                }
            }
            else if (function[j] == 'D') {

                //������ ���� 
                if (start_array > end_array) {
                    errflag = 1;
                    break;
                }
                // ������ ���¸� ������ ��
                if (rflag) {
                    end_array--;
                    //������ ���� �ƴϸ� ó�� �M
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

