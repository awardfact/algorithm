#include <stdio.h>
#include <string.h>



int main() {
    int m, i;
    char set[21] = { 0, };
    char order[7];
    int input_num;

    scanf("%d", &m);

    //�ִ� ���ڰ� 20�̿��� 20ũ���� �迭�� ����� �迭index�� ������ �ؼ� ó�� 
    for (i = 0; i < m; i++) {
        scanf("%s %d", order, &input_num);


        if (order[0] == 'a') {
            if (order[1] == 'd') {
                set[input_num] = 1;
            }
            else if (order[1] == 'l') {
                memset(set + 1, 1, sizeof(char) * 20);
            }


        }
        else if (order[0] == 'r') {
            set[input_num] = 0;
        }
        else if (order[0] == 'c') {
            printf("%d\n", set[input_num]);
        }
        else if (order[0] == 't') {
            set[input_num] = set[input_num] ^ 1;
        }
        else if (order[0] == 'e') {
            memset(set + 1, 0, sizeof(char) * 20);
        }



    }


    return 0;
}

