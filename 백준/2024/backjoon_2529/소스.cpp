#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queT {
    char use_num[10];
    char string[11];
    int step;
    struct queT* after;

}que;


que* front_que = NULL;
que* rear_que = NULL;
que* tmp_que = NULL;

//BFS�ϱ� ���� ť
void push(char* use_num, char* string, int step) {

    tmp_que = (que*)malloc(sizeof(que));
    memcpy(tmp_que->use_num, use_num, 10);
    memcpy(tmp_que->string, string, 11);
    tmp_que->step = step;
    tmp_que->after = NULL;

    if (front_que == NULL) {
        front_que = tmp_que;

    }
    else {
        rear_que->after = tmp_que;

    }

    rear_que = tmp_que;
}


que* pop() {

    if (front_que != NULL) {
        tmp_que = front_que;
        front_que = front_que->after;
        return tmp_que;

    }
    else {
        return NULL;
    }


}



int main() {


    char simbol[10];
    int i, j;
    int k;
    char small[12];
    char big[12];
    char tmp_string[11];
    char tmp_use_num[10];
    que* tmp_que = NULL;
    int step;

    scanf("%d", &k);

    strcpy(big, "0");
    strcpy(small, "99999999999");
    //�Է�
    j = 10;
    for (i = 0; i < k; i++) {
        getchar();
        scanf("%c", &simbol[i]);
    }


    //0���� �����ؼ� BFS���� 
    for (i = 0; i <= 9; i++) {

        //���ڴ� �ϳ��� ����� �� �־ 0���� ó���ϰ� ����Ѱ��� 1�� 
        for (j = 0; j <= 9; j++) {
            tmp_use_num[j] = 0;
        }
        tmp_use_num[i] = 1;
        //���ڸ� ���ڷ�
        tmp_string[0] = i + 48;

        //ť�� ����
        push(tmp_use_num, tmp_string, 0);

        while (front_que != NULL) {
            //ť���� �ϳ��� ��
            tmp_que = pop();
            step = tmp_que->step;
            //printf("string ; %s step : %d\n", tmp_que->string, tmp_que->step);
            //���� ��� �� ��� ũ�� ���ؼ� �۰ų� ũ�� ����
            if (tmp_que->step >= k) {


                tmp_que->string[step + 1] = 0;
                // printf("end : %s  atoi : %d\n", tmp_que->string, atoi(tmp_que->string));

                if (atoll(small) > atoll(tmp_que->string)) {
                    strcpy(small, tmp_que->string);
                }

                if (atoll(big) < atoll(tmp_que->string)) {
                    strcpy(big, tmp_que->string);
                }

                //printf("small : %s\n", small);
                free(tmp_que);
                continue;

            }



            // printf("simbol : %c\n", simbol[step]);

             //�ɺ��� ���� ������ ���� ���ڰ����� �۰ų� ũ�� �ݺ� ���鼭 ������ ���ڸ� �ٽ� ť�� ���� 
            if (simbol[step] == '<') {

                for (j = (tmp_que->string[step] - 48) + 1; j <= 9; j++) {

                    if (step == 8) {
                        // printf("j : %d use : %d\n", j, tmp_que->use_num[j]);    
                    }


                    if (tmp_que->use_num[j] == 0) {
                        tmp_que->use_num[j] = 1;
                        tmp_que->string[step + 1] = j + 48;
                        push(tmp_que->use_num, tmp_que->string, step + 1);
                        tmp_que->use_num[j] = 0;
                    }

                }

            }
            else {
                for (j = 0; j < (tmp_que->string[step] - 48); j++) {

                    if (tmp_que->use_num[j] == 0) {
                        tmp_que->use_num[j] = 1;
                        tmp_que->string[step + 1] = j + 48;
                        push(tmp_que->use_num, tmp_que->string, step + 1);
                        tmp_que->use_num[j] = 0;
                    }

                }


            }

            free(tmp_que);

        }



    }



    printf("%s\n", big);
    printf("%s\n", small);
    return 0;
}
