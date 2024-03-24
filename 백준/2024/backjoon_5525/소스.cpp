#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int i, j, n, m;
    //char pn[1000002];
    int pn;
    char string[1000001];
    int index;
    int ncnt = 0;
    int before = 0;
    int fail;
    scanf("%d", &n);

    index = 0;

    pn = n * 2 + 1;
    // for(i = 0; i < n; i++){
    //     pn[index++] = 'I';
    //     pn[index++] = 'O';
    // }
    // pn[index++] = 'I';
    // pn[index++] = '\0';

    scanf("%d", &m);
    scanf("%s", string);
    i = 0;
    if (m > n * 2) {
        while (i <= strlen(string) - pn + 1) {

            //printf("i : %d\n", i);

            //이전꺼가 맞다면 뒤에 2개만 더 비교하면된다 비교 도중 틀리면  그 틀린 위치까지는 절대 정답이 될 수 없다 
            if (before == 0) {
                // if(strncmp(pn, &string[i], strlen(pn)) == 0){
                //     ncnt++;
                //     before = 1;
                // }else{
                //     before = 0;

                // }
                fail = 0;

                // printf("i : %d\n", i);

                 //I O 패턴 체크 
                for (j = 0; j < pn - 1; j = j + 2) {
                    if (string[i + j] != 'I') {
                        if (j != 0) {
                            i = i + j;
                        }
                        else {
                            i++;
                        }
                        fail = 1;
                        break;
                    }

                    if (string[i + j + 1] != 'O') {
                        i = i + j + 1;
                        fail = 1;
                        break;
                    }

                }

                //마지막에  I로 끝나는지 체크 
                if (fail == 0) {
                    if (string[i + j] != 'I') {
                        if (j != 0) {
                            i = i + j;
                        }
                        else {
                            i++;
                        }
                        fail = 1;

                    }
                }

                // printf("i : %d fail : %d\n",i,fail);
                if (fail == 0) {
                    //  printf("suc i : %d\n", i);
                    ncnt++;
                    i += 2;
                    before = 1;

                }

            }
            else {
                // printf("i : %d\n", i);
               //  printf("string[i + pn - 2] : %c  string[i + pn - 1] : %c\n", string[i + pn - 2] , string[i + pn - 1] );
                if (string[i + pn - 2] == 'O' && string[i + pn - 1] == 'I') {

                    // printf("2\n");
                    ncnt++;
                    i += 2;
                }
                else {
                    i += 1;
                    before = 0;
                }


            }


        }



    }


    printf("%d\n", ncnt);

    return 0;
}

