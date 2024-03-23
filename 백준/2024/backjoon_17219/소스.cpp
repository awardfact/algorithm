#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sitePassT {
    char site[21];
    char pass[21];
    int num;
    struct sitePassT* after;
}sitePass;

int main() {
    int n, m, i, j;
    sitePass sp[100000];
    sitePass* sp_tmp;
    sitePass* sp_tmp2;
    int tmp;
    char char_tmp[21];
    char char_tmp2[21];
    int key_tmp;

    for (i = 0; i < 100000; i++) {
        sp[i].num = 0;
        sp[i].after = NULL;
    }
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%s %s", char_tmp, char_tmp2);

        key_tmp = 0;
        // printf("strlen(char_tmp) : %d\n", (int)strlen(char_tmp));
        for (j = 0; j < strlen(char_tmp); j++) {
            tmp = (j + 1) * char_tmp[j] * char_tmp[j];
            key_tmp += tmp;
        }
        //  printf("key : %d\n", key_tmp);
        key_tmp = key_tmp % 100000;
        if (sp[key_tmp].num == 0) {
            strcpy(sp[key_tmp].site, char_tmp);
            strcpy(sp[key_tmp].pass, char_tmp2);
            sp[key_tmp].num++;

        }
        else {
            sp_tmp = (sitePass*)malloc(sizeof(sitePass));
            sp_tmp->after = NULL;
            strcpy(sp_tmp->site, char_tmp);
            strcpy(sp_tmp->pass, char_tmp2);

            if (sp[key_tmp].after == NULL) {
                sp[key_tmp].after = sp_tmp;
            }
            else {
                sp_tmp2 = sp[key_tmp].after;
                while (sp_tmp2->after != NULL) {
                    sp_tmp2 = sp_tmp2->after;
                }
                sp_tmp2->after = sp_tmp;

            }

        }
        // printf("key : %d\n", key_tmp);
    }



    for (i = 0; i < m; i++) {
        scanf("%s", char_tmp);

        key_tmp = 0;
        for (j = 0; j < strlen(char_tmp); j++) {
            tmp = (j + 1) * char_tmp[j] * char_tmp[j];
            key_tmp += tmp;
        }
        key_tmp = key_tmp % 100000;


        if (strcmp(sp[key_tmp].site, char_tmp) == 0) {
            printf("%s\n", sp[key_tmp].pass);
        }
        else {
            sp_tmp = sp[key_tmp].after;

            while (strcmp(sp_tmp->site, char_tmp) != 0) {
                sp_tmp = sp_tmp->after;
            }
            printf("%s\n", sp_tmp->pass);

        }

    }


    return 0;
}