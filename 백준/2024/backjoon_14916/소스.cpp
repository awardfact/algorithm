#include <stdio.h>

int main(){
    int n;
    int count;
    int tmp;

    
    scanf("%d", &n);
    //�ٷ� ���������� /5
    if(n % 5 == 0){
        count = n / 5;
    }else{
        //�ٷ� ���������� �ʴ� ��� �������¸�ŭ 5�� ������ �������� 2 ������ ����ؼ� 0�� ���ö����� ���
        count = n / 5;
        tmp = n % 5;
        while(tmp != 0){

            if(tmp % 2 == 0){
                break;
            }else{
                count--;
                tmp += 5;
            }
        }
        count += tmp / 2;
        

    }
    


    printf("%d", count);


    


    return 0;
}