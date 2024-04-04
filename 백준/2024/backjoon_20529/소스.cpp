#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int dif_alpha(char* a, char* b) {

    int i;
    int dif = 0;
    for (i = 0; i < strlen(a); i++) {
        if (a[i] != b[i]) {
            dif++;
        }

    }

    return dif;
}


int get_distance(char* mbti1, char* mbti2, char* mbti3) {
    int dif = 0;

    dif = dif_alpha(mbti1, mbti2);
    dif += dif_alpha(mbti1, mbti3);
    dif += dif_alpha(mbti2, mbti3);

    return dif;

}


int main() {

    int t, i, j, k, l;
    int n;
    int zero_flag;
    //int mbti[17] = {0,};
    char mbti[256][5];
    int max = 0;
    int min = 0;
    int distance = 0;
    char mbti_input[10];
    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        scanf("%d", &n);

        memset(mbti, 0, sizeof(int) * 17);
        zero_flag = 0;
        for (j = 0; j < n; j++) {
            scanf("%s", mbti_input);

            //256넘으면 무조건 3명은 같은 mbti
            if (n < 256) {
                strcpy(mbti[j], mbti_input);

            }
        }

        if (n >= 256) {
            printf("0\n");
        }
        else {

            min = 1000;
            //256명 이하인 경우에 최소 거리를 구한다 
            for (j = 0; j < n; j++) {
                for (k = j + 1; k < n; k++) {
                    for (l = k + 1; l < n; l++) {
                        distance = get_distance(mbti[j], mbti[k], mbti[l]);
                        //printf("distance : %d\n", distance);
                        if (distance < min) {
                            min = distance;
                        }
                    }
                }
            }
            printf("%d\n", min);


        }

    }




    return 0;
}


