#include <stdio.h>

int node[31][31] = {0,};



int main() {


    int i,j,k;
    int n,m,test_num;

    //  ������ 1�� �������� m���� ����� ���� m��
    for(i = 1; i <= 30; i++){
        node[1][i] = i;
    }
    
    for(i = 2; i <= 30; i++){
        for(j= i; j <=30; j++){
            //2 4��   6��   1-3 3��  2-3 3��
            // 2 3�̸� 3�� �� 1-2 -2��  2-2 -1�� = 3
            // 2 2 ��   1��   1- 1 -1�� 2-1 -0��
            // 3 3 �̸� 1��  2 2  3 2 
            // 3 4 ��    2  3 -3��  3 3  1��
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