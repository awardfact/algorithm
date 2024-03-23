#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct listT {
    char name[21];
    struct listT* after;
}list;

int compare(const void* a, const void* b) {

    return strcmp((char*)a, (char*)b);


}


int main() {

    int n, m, i, j;
    int min;
    char char_tmp[21];
    int key;
    list* list_tmp = NULL;
    list* list_current = NULL;
    list dlist[500000];
    char dblist[500000][21];
    int db_cnt = 0;

    for (i = 0; i < 500000; i++) {
        dlist[i].name[0] = '\0';
        dlist[i].after = NULL;

    }


    scanf("%d %d", &n, &m);


    for (i = 0; i < n; i++) {
        scanf("%s", char_tmp);
        key = 0;
        //printf("Char : %s\n",char_tmp);
        for (j = 0; j < strlen(char_tmp); j++) {
            key += (j + 1) * char_tmp[j] * char_tmp[j] * char_tmp[j];
        }

        key = key % 500000;
        //해당 키의 처음 값 
        if (dlist[key].name[0] == '\0') {
            strcpy(dlist[key].name, char_tmp);
            //해당 키에 값이 있는 경우 
        }
        else {

            list_tmp = (list*)malloc(sizeof(list));
            strcpy(list_tmp->name, char_tmp);

            // printf("list_tmp->name  : %s\n", list_tmp->name);
            list_tmp->after = NULL;
            //after가 비어있으면 after에 아니면 after의 after가 비어있는곳에 넣음 
            if (dlist[key].after == NULL) {
                dlist[key].after = list_tmp;
            }
            else {
                list_current = dlist[key].after;
                while (list_current->after != NULL) {
                    list_current = list_current->after;
                }
                list_current->after = list_tmp;
            }

        }
    }

    for (i = 0; i < m; i++) {
        scanf("%s", char_tmp);
        key = 0;
        for (j = 0; j < strlen(char_tmp); j++) {
            key += (j + 1) * char_tmp[j] * char_tmp[j] * char_tmp[j];
        }


        key = key % 500000;
        //동일한 방식으로 키를 만들고 키에 들어있는 이름이 같은지 체크 
        if (dlist[key].name[0] != '\0') {
            if (strcmp(dlist[key].name, char_tmp) == 0) {
                strcpy(dblist[db_cnt++], char_tmp);
                continue;
            }
            else {
                list_current = dlist[key].after;
                // printf("current : %s\n", list_current->name);
                while (list_current != NULL) {
                    //  printf(" name : %s tmp : %s\n", list_current->name, char_tmp);
                    if (strcmp(list_current->name, char_tmp) == 0) {
                        strcpy(dblist[db_cnt++], char_tmp);
                        break;
                    }
                    list_current = list_current->after;
                }
            }
        }
    }


    qsort(dblist, db_cnt, 21, compare);

    printf("%d\n", db_cnt);
    for (i = 0; i < db_cnt; i++) {
        printf("%s\n", dblist[i]);

    }




    return 0;
}