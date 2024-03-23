#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
    int n;
    int i, j;
    int index;
    char right[10];
    char reverse[10];
    while (1) {
        scanf("%s", right);

        if (strcmp(right, "0") == 0) {
            break;
        }


        index = 0;
        for (j = strlen(right) - 1; j >= 0; j--) {
            reverse[index++] = right[j];

        }
        reverse[index] = '\0';
        if (strcmp(right, reverse) == 0) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }


    }

    return 0;
}

