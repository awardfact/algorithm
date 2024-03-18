#include <stdio.h>

int main(){
    int n;
    int k; 
    int country;
    int i;
    int gold[1000];
    int silver[1000];
    int bronze[1000];
    int goldk,silverk,bronzek;
    int rank =1;
    //나라와 찾을 국가 
    scanf("%d %d", &n, &k);

    for(i = 1; i<= n; i++){
        //메달 입력
        scanf("%d ", &country);
        scanf("%d %d %d",&gold[country], &silver[country], &bronze[country]);
        //찾는 국가 메달 저장
        if(country == k){
            goldk = gold[country];
            silverk = silver[country];
            bronzek = bronze[country];

        }
    }
    

    //등수 계산
    for(i = 1; i <= n; i++){
        
        if(i != k){
            if(gold[i] > goldk ){
                rank++;
                continue;
            }else if(gold[i] == goldk && silver[i] > silverk ){
                rank++;
                continue;
            }else if(gold[i] == goldk && silver[i] == silverk && bronze[i] > bronzek ){
                rank++;
                continue;
            }
        }
    }
    

    printf("%d", rank);


    


    return 0;
}