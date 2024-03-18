#include <stdio.h>

int main(){
    int n;
    int count;
    int tmp;

    
    scanf("%d", &n);
    //바로 나뉘어지면 /5
    if(n % 5 == 0){
        count = n / 5;
    }else{
        //바로 나뉘어지지 않는 경우 나눠지는만큼 5로 나누고 나머지를 2 나머지 계산해서 0이 나올때까지 계산
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