#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {

    int t, i, j, k;
    char wear_name[30][21];
    char input_name[21];
    char wear_type_name[21];
    int wear_type[30] = { 0, };
    int wear_type_cnt = 0;
    int type_flag = 0;
    int wear_cnt;
    int sum;
    scanf("%d", &t);
    for (i = 0; i < t; i++) {

        wear_type_cnt = 0;
        sum = 0;
        scanf("%d", &wear_cnt);
        for (j = 0; j < wear_cnt; j++) {
            scanf("%s %s", input_name, wear_type_name);

            type_flag = 0;
            //같은 타입 의상 있으면 그 의상으 종류 +해줌
            for (k = 0; k < wear_type_cnt; k++) {
                if (strcmp(wear_type_name, wear_name[k]) == 0) {
                    wear_type[k]++;
                    type_flag = 1;
                }

            }

            //같은 타임 의상 없으면 새로운 타입 추가 
            if (type_flag == 0) {
                wear_type[wear_type_cnt] = 1;
                strcpy(wear_name[wear_type_cnt], wear_type_name);
                wear_type_cnt++;
            }
        }


        if (wear_type_cnt > 0) {
            sum = wear_type[0] + 1;
            for (j = 1; j < wear_type_cnt; j++) {
                sum *= wear_type[j] + 1;
            }

            sum -= 1;

        }



        printf("%d\n", sum);


    }




    return 0;
}