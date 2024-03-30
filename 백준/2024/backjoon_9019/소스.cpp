#include <stdio.h>
#include <stdlib.h>
#include <string.h>




short before[10000];
char visit[10000];

// �ʺ�켱 Ž���� ���� ����ü ����
typedef struct DSLRT {

    int value;
    //  char* dslr;

    struct DSLRT* after;
}DSLR;

//�ʺ� �켱 Ž���� ���� ť ����
DSLR* front_que = NULL;
DSLR* rear_que = NULL;
DSLR* tmp_que = NULL;

//ť�� ������ ����
void push(int value) {

    tmp_que = (DSLR*)malloc(sizeof(DSLR));
    tmp_que->value = value;
    tmp_que->after = NULL;


    if (front_que == NULL) {
        front_que = tmp_que;

    }
    else {
        rear_que->after = tmp_que;
    }

    rear_que = tmp_que;

}

//ť���� ���� �Լ� 
int pop() {
    int que_value;
    if (front_que != NULL) {
        tmp_que = front_que;
        que_value = tmp_que->value;
        front_que = front_que->after;
        free(tmp_que);
        return que_value;
    }
    else {
        return -1;
    }


}


int convert_D(int n) {

    return (n * 2) % 10000;

}


int convert_S(int n) {

    if (n == 0) {
        return 9999;
    }
    else {
        return n - 1;
    }


}


int convert_L(int n) {
    int tmp = n;
    int one = tmp % 10;
    tmp /= 10;
    int ten = tmp % 10;
    tmp /= 10;
    int hundred = tmp % 10;
    tmp /= 10;
    int thousand = tmp % 10;


    return (hundred * 1000) + (ten * 100) + (one * 10) + (thousand);


}



int convert_R(int n) {
    int tmp = n;
    int one = tmp % 10;
    tmp /= 10;
    int ten = tmp % 10;
    tmp /= 10;
    int hundred = tmp % 10;
    tmp /= 10;
    int thousand = tmp % 10;


    return (one * 1000) + (thousand * 100) + (hundred * 10) + (ten);


}


void visit_printf(int start, int end) {

    if (start == end) {
        return;
    }

    visit_printf(start, before[end]);
    printf("%c", visit[end]);


}



int main() {

    int t;
    int i;
    int a, b;
    int data;

    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        scanf("%d %d", &a, &b);


        memset(before, 0, sizeof(short) * 10000);
        memset(visit, 0, sizeof(char) * 10000);

        //dslr �� ������ ���� ť�� ����




        push(convert_D(a));
        push(convert_S(a));
        push(convert_L(a));
        push(convert_R(a));

        //�������ϱ����� ���� ���̶� �ش� ������ � ��� �����ߴ��� ����
        visit[convert_D(a)] = 'D';
        before[convert_D(a)] = a;
        visit[convert_S(a)] = 'S';
        before[convert_S(a)] = a;
        visit[convert_L(a)] = 'L';
        before[convert_L(a)] = a;
        visit[convert_R(a)] = 'R';
        before[convert_R(a)] = a;

        //   printf("a : %d b : %d\n", a,b);
           //ť�� ���� ������ �ݺ� 
        while (front_que != NULL) {
            //tmp_dslr = pop();
            data = pop();
            if (data == -1) {
                break;
            }
            //   printf("data : %d\n",data);

              //printf("tmp_dslr : %d   %s\n", tmp_dslr->value, tmp_dslr->dslr);
               //���� ������ ����ϰ� ť�� �ִ°� ���� pop_int�ؼ� free��Ŵ
            if (data == b) {
                while (front_que != NULL) {
                    pop();
                }
                visit_printf(a, b);
                printf("\n");
                break;

            }
            else {
                //���� �ٸ��� �� ���� dslr�����ؼ� ť�� ����
                if (visit[convert_D(data)] == 0) {
                    push(convert_D(data));
                    before[convert_D(data)] = data;
                    visit[convert_D(data)] = 'D';
                }


                if (visit[convert_S(data)] == 0) {
                    push(convert_S(data));
                    before[convert_S(data)] = data;
                    visit[convert_S(data)] = 'S';
                }


                if (visit[convert_L(data)] == 0) {
                    push(convert_L(data));
                    before[convert_L(data)] = data;
                    visit[convert_L(data)] = 'L';
                }

                if (visit[convert_R(data)] == 0) {
                    push(convert_R(data));
                    before[convert_R(data)] = data;
                    visit[convert_R(data)] = 'R';
                }



            }



        }

    }

    return 0;
}