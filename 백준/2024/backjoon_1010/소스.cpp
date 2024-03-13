#include <stdio.h>

int node[31][31] = {0,};



int main() {


    int i,j,k;
    int n,m,test_num;

    //  왼쪽이 1개 오른쪽이 m개면 경우의 수는 m개
    for(i = 1; i <= 30; i++){
        node[1][i] = i;
    }
    
    for(i = 2; i <= 30; i++){
        for(j= i; j <=30; j++){
            //2 4면   6개   1-3 3개  2-3 3개
            // 2 3이면 3개 능 1-2 -2개  2-2 -1개 = 3
            // 2 2 면   1개   1- 1 -1개 2-1 -0개
            // 3 3 이면 1개  2 2  3 2 
            // 3 4 면    2  3 -3개  3 3  1개
            node[i][j] =  node[i - 1][j -1] + node[i][j-1];
        }
    }


    scanf("%d", &test_num);
    for(i = 0; i < test_num; i++){
        scanf("%d %d", &n, &m);



        printf("%d\n",node[n][m]);

    }


	return 0;
}