#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct heapT {

    int value;
    int index;

}heap;


int main() {
    int t, i, j, k, input_cnt;
    char operation;
    heap max_que[1000010];
    heap min_que[1000010];
    int que_num;
    int current;
    int current2;
    int input;
    heap tmp;
    int deep;
    int sib;
    int min, key;
    int max_index, min_index;

    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        scanf("%d", &input_cnt);

        que_num = 0;
        min = 0x7FFFFFFF;
        k = 0;
        for (j = 0; j < input_cnt; j++) {
            // scanf("%c %d", &operation, &input);
            scanf(" %c", &operation);
            scanf(" %d", &input);
            if (que_num == 0 && operation == 'D') {
                continue;
            }

            //입력
            if (operation == 'I') {



                max_que[++que_num].value = input;



                current = que_num;
                //부모보다 크면 자리바꿈
                while (current / 2 > 0) {
                    if (max_que[current / 2].value < max_que[current].value) {
                        tmp = max_que[current];
                        max_que[current] = max_que[current / 2];
                        max_que[current / 2] = tmp;

                        min_que[max_que[current / 2].index].index = current;

                        // if(key == current / 2){
                        //      key = current;
                        //  }
                        current = current / 2;
                    }
                    else {
                        break;
                    }
                }


                min_que[que_num].value = input;
                min_que[que_num].index = current;

                while (current2 / 2 > 0) {
                    if (min_que[current2 / 2].value > min_que[current2].value) {
                        tmp = min_que[current2];
                        min_que[current2] = min_que[current2 / 2];
                        min_que[current2 / 2] = tmp;
                        max_que[min_que[current2 / 2].index].index = current2;
                        // if(key == current2 / 2){
                        //      key = current2;
                        //  }
                        current2 = current2 / 2;
                    }
                    else {
                        break;
                    }
                }

                max_que[que_num].index = current2;

                //if(min >= que[current]){

                //    printf("in\n");
                //     min = que[current];
                //     key = current;
                // }
                // deep = sqrt(current);
                // sib = pow(deep);
                // //형제보다 크면 자리바꿈 
                // for(k = current - 1; k > sib; k--){
                //     if(que[k]  < que[current]){
                //         tmp = que[current];
                //         que[current] = que[current /2];
                //         que[k = que[current];
                //         current = k;
                //     }
                // }

            }
            else if (operation == 'D') {

                if (input == 1) {

                    min_index = max_que[1].index;
                    //tmp = que[que_num];
                    max_que[1] = max_que[que_num];
                    que_num--;
                    current = 1;
                    min_que[max_que[1].index].index = current;

                    while (que_num >= current * 2) {
                        if (current * 2 + 1 <= que_num && max_que[current].value < max_que[current * 2 + 1].value && max_que[current * 2].value < max_que[current * 2 + 1].value) {
                            tmp = max_que[current];
                            max_que[current] = max_que[current * 2 + 1];
                            max_que[current * 2 + 1] = tmp;
                            // if(key == current * 2 + 1){
                            //      key = current;
                            //  }
                            min_que[max_que[current * 2 + 1].index].index = current;
                            min_que[max_que[current].index].index = current * 2 + 1;
                            current = current * 2 + 1;

                        }
                        else if (max_que[current].value < max_que[current * 2].value) {
                            tmp = max_que[current];
                            max_que[current] = max_que[current * 2];
                            max_que[current * 2] = tmp;
                            min_que[max_que[current * 2].index].index = current;
                            min_que[max_que[current].index].index = current * 2;
                            // if(key == current * 2 ){
                            //      key = current;
                            //  }
                            current = current * 2;

                        }
                        else {
                            break;
                        }

                    }


                    min_que[min_index] = min_que[que_num + 1];
                    current = min_index;
                    max_que[min_que[min_index].index].index = current;
                    while (que_num >= current * 2) {
                        if (current * 2 + 1 <= que_num && min_que[current].value > min_que[current * 2 + 1].value && min_que[current * 2].value > min_que[current * 2 + 1].value) {
                            tmp = min_que[current];
                            min_que[current] = min_que[current * 2 + 1];
                            min_que[current * 2 + 1] = tmp;

                            max_que[min_que[current * 2 + 1].index].index = current;
                            max_que[min_que[current].index].index = current * 2 + 1;

                            current = current * 2 + 1;

                        }
                        else if (min_que[current].value > min_que[current * 2].value) {
                            tmp = min_que[current];
                            min_que[current] = min_que[current * 2];
                            min_que[current * 2] = tmp;

                            max_que[min_que[current * 2].index].index = current;
                            max_que[min_que[current].index].index = current * 2;

                            current = current * 2;

                        }
                        else {
                            break;
                        }

                    }


                    // p = 1;
                    // c = 2;
                    // while(c <= que_num){
                    //     if(c <= que_num && que[c] < que[c+1]){
                    //         c++;
                    //     }
                    //     if(que[tmp] >= que[c]){
                    //         break;
                    //     }
                    //     que[p] = que[c];
                    //     p = c;
                    //     c *=2;
                    // }
                    // que[p] = tmp;


                    // if(min >= que[current]){
                    //     min = que[current];
                    //     key = current;
                    // }

                }
                else if (input == -1) {



                    max_index = min_que[1].index;
                    //tmp = que[que_num];
                    min_que[1] = min_que[que_num];
                    que_num--;
                    current = 1;
                    max_que[min_que[1].index].index = current;
                    while (que_num >= current * 2) {
                        if (current * 2 + 1 <= que_num && min_que[current].value > min_que[current * 2 + 1].value && min_que[current * 2].value > min_que[current * 2 + 1].value) {
                            tmp = min_que[current];
                            min_que[current] = min_que[current * 2 + 1];
                            min_que[current * 2 + 1] = tmp;
                            // if(key == current * 2 + 1){
                            //      key = current;
                            //  }
                            max_que[min_que[current * 2 + 1].index].index = current;
                            max_que[min_que[current].index].index = current * 2 + 1;
                            current = current * 2 + 1;

                        }
                        else if (min_que[current].value > min_que[current * 2].value) {
                            tmp = max_que[current];
                            min_que[current] = min_que[current * 2];
                            min_que[current * 2] = tmp;
                            max_que[min_que[current * 2].index].index = current;
                            max_que[min_que[current].index].index = current * 2;
                            // if(key == current * 2 ){
                            //      key = current;
                            //  }
                            current = current * 2;

                        }
                        else {
                            break;
                        }

                    }


                    max_que[max_index] = max_que[que_num + 1];
                    current = max_index;
                    min_que[max_que[max_index].index].index = current;
                    while (que_num >= current * 2) {
                        if (current * 2 + 1 <= que_num && max_que[current].value < max_que[current * 2 + 1].value && max_que[current * 2].value < max_que[current * 2 + 1].value) {
                            tmp = max_que[current];
                            max_que[current] = max_que[current * 2 + 1];
                            max_que[current * 2 + 1] = tmp;
                            // if(key == current * 2 + 1){
                            //      key = current;
                            //  }
                            min_que[max_que[current * 2 + 1].index].index = current;
                            min_que[max_que[current].index].index = current * 2 + 1;
                            current = current * 2 + 1;

                        }
                        else if (max_que[current].value < max_que[current * 2].value) {
                            tmp = max_que[current];
                            max_que[current] = max_que[current * 2];
                            max_que[current * 2] = tmp;

                            min_que[max_que[current * 2].index].index = current;
                            min_que[max_que[current].index].index = current * 2;
                            // if(key == current * 2 ){
                            //      key = current;
                            //  }
                            current = current * 2;

                        }
                        else {
                            break;
                        }

                    }




                    // if(key != que_num){
                    //     tmp = que[que_num];
                    //     que[que_num] = que[key];
                    //     que[key] = tmp; 
                    // }
                    // que_num--;


                    // if(que_num > 0){
                    //     min = 0x7FFFFFFF;
                    //     deep = sqrt(que_num);
                    //     sib = pow(2,deep);

                    //     min = que[que_num];
                    //     key = que_num;

                    //     for(k = sib; k <= que_num; k++){
                    //         if(que[k] <= min){
                    //             min = que[k];
                    //             key = k;
                    //         }
                    //     }
                    // }else {
                    //     min = 0x7FFFFFFF;
                    // }



                }



            }
            // for(i = 1; i <=que_num; i++){
            //     printf("%d ",que[i]);
            // }
           // printf("\n");

                //printf("num : %d max : %d min : %d\n", que_num, que[1], que[key]);

            printf("ed que_num : %d\n\n\n", que_num);

        }


        if (que_num == 0) {
            printf("EMPTY\n");

        }
        else {
            printf("%d %d\n", max_que[1].value, min_que[1].value);
        }

    }

    return 0;
}


