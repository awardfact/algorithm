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
        //�Է��� ���ڿ� Ž��
        for(j = 0; j < strlen(m); j++){
            

            // ù ���ڰ� 0�̸� ���� ���Դٴ°͸� üũ
            if(m[j] == '0' && k == 0){
                num_flag = 1;

            // ù ���ڰ� 0�� �ƴ� ���ڰ� ������ atoi��ų ���ڿ��� �־���
            }else if(m[j] >= '0' && m[j] <= '9'){
                char_tmp[k++] = m[j];
                num_flag = 1;
            //���ڰ� �ƴ϶�� ������ ���� �־����� atoi�ؼ� ���� �迭�� �־���
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

        //�������� ������ ��� 
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

    //����
    qsort(number, num_cnt, 101,compare);

    //���
    for(i = 0; i < num_cnt; i++){
        printf("%s\n", number[i]);
    }
    return 0;
}