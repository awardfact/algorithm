#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int compare(const void* a, const void* b) {


    if(strlen((char*)a ) > strlen((char*)b  ) ){
        return 1;
    }else if( strlen((char*)a ) < strlen((char*)b)   ){
        return -1;
    }else{
        if( strcmp((char*)a , (char*)b) > 0 ){
            return 1;
        }else if( strcmp((char*)a , (char*)b)  ==  0){
            return 0;
        }else{
            return -1;
        }

    }
    

}

int main() {
    
    char number[10000][101] = {0,};
   // int num_tmp;
    char char_tmp[101];
    int n,i,j,k;
    char m[101];
    int num_flag = 0;
    int num_cnt =0;

    
    scanf("%d", &n);
    for(i =0; i < n; i++){
        
        scanf("%s", m);
        k = 0;
        num_flag  = 0;
        //입력한 문자열 탐색
        for(j = 0; j < strlen(m); j++){
            

            // 첫 숫자가 0이면 숫자 나왔다는것만 체크
            if(m[j] == '0' && k == 0){
                num_flag = 1;

            // 첫 숫자가 0이 아닌 숫자가 나오면 atoi시킬 문자열에 넣어줌
            }else if(m[j] >= '0' && m[j] <= '9'){
                char_tmp[k++] = m[j];
                num_flag = 1;
            //숫자가 아니라면 이전에 숫자 있었던거 atoi해서 숫자 배열에 넣어줌
            }else{
                if(num_flag == 1 && k == 0){
                    strcpy(number[num_cnt++] , "0");
                    //number[num_cnt++] = 0;
                }else if(num_flag == 1){

                    char_tmp[k] = '\0';
                    strcpy(number[num_cnt++] , char_tmp);
                   // number[num_cnt++] = atoi(char_tmp);
                }
                num_flag = 0;
                k = 0;
                
            }
        }

        //마지막이 숫자인 경우 
        if(num_flag == 1 && k == 0){
            strcpy(number[num_cnt++] , "0");
            //number[num_cnt++] = 0;
        }else if(num_flag ==  1){
           // printf("%s\n", char_tmp);
            char_tmp[k] = '\0';
            strcpy(number[num_cnt++] , char_tmp);
        
          //  number[num_cnt++] = atoi(char_tmp);
        }


    }


    for(i = 0; i < num_cnt; i++){
        
        
    }

    //정렬
    qsort(number, num_cnt, 101,compare);

    //출력
    for(i = 0; i < num_cnt; i++){
        printf("%s\n", number[i]);
    }
    return 0;
}