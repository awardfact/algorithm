#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
    int n, i;
    int input_num;
    int min = 4001;
    int max = -4001;
    int sum = 0;
    int num[8001] = { 0, };
    double avg = 0;
    int mid = 0;
    int poor = 4001;
    int range = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &input_num);
        num[input_num + 4000]++;
        sum += input_num;
        //ÃÖ¼Ò°ª
        if (min > input_num) {
            min = input_num;
        }
        //ÃÖ´ë°ª¤º
        if (max < input_num) {
            max = input_num;
        }
    }

    //Æò±Õ
    avg = (double)sum / (double)n;

    range = max - min;
    max = -4004;
    //ÃÖºóµµ ¼ö °¡Á®¿È
    for (i = 0; i <= 8000; i++) {


        if (max < num[i]) {

            max = num[i];
        }
    }


    //ÃÖºó°ª
    for (i = 0; i <= 8000; i++) {
        if (num[i] == max && poor != 4001) {
            poor = i - 4000;
            break;
        }
        else if (num[i] == max) {
            poor = i - 4000;
        }


    }


    sum = 0;
    //Áß¾Ó°ª
    for (i = 0; i <= 8000; i++) {
        sum += num[i];
        if (sum >= n / 2 + 1) {
            mid = i - 4000;
            break;
        }
    }





    printf("%d\n", (int)round(avg));
    printf("%d\n", mid);
    printf("%d\n", poor);
    printf("%d\n", range);



    return 0;
}