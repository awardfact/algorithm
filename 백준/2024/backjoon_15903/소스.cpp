#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int card_num = 0;

// ���� �ٲٴ� �Լ�
void swap(long long int* a, long long int* b) {
    long long int tmp = *a;
    *a = *b;
    *b = tmp;


}

//�켱���� ť ���� �� �ø��� �Լ� 
void push_up(long long int* card, int n) {

    int p;
    while (n / 2 > 0) {
        p = n / 2;
        //�θ� �� ũ�� �ڸ�����
        if (card[p] > card[n]) {
            swap(&card[p], &card[n]);
            n /= 2;
        }
        else {
            break;
        }
    }

}



//�켱���� ť ���� �� ������ �Լ� 
void push_down(long long int* card, int n) {

    int l, r;

    //�ڽ��� �ִ� �� �ڽ��� �� ���� ��� �� ���� �ڽİ� ��ġ ����
    while (card_num >= n * 2) {
        l = n * 2;
        r = n * 2 + 1;

        if (card_num >= l && card[l] < card[n]) {
            if (card_num >= r && card[r] < card[l]) {
                swap(&card[r], &card[n]);
                n = r;

            }
            else {
                swap(&card[l], &card[n]);
                n = l;


            }


        }
        else if (card_num >= r && card[r] < card[n]) {
            swap(&card[r], &card[n]);
            n = r;


        }
        else {
            break;
        }


    }


}




int main() {
    int n, m, i, j;
    long long int card[1001];
    int input_card = 0;
    long long int a, b, sum;

    scanf("%d %d", &n, &m);

    //�Է¹����� �켱���� ť�� ����
    for (i = 0; i < n; i++) {
        scanf("%d ", &input_card);


        card[++card_num] = input_card;
        push_up(card, card_num);

    }

    //�켱���� ť���� 2�� ���� ���ϰ� 2�� �ٽ� ����
    for (i = 0; i < m; i++) {
        a = card[1];
        card[1] = card[card_num--];
        push_down(card, 1);
        b = card[1];
        card[1] = card[card_num--];
        push_down(card, 1);

        sum = a + b;

        card[++card_num] = sum;
        push_up(card, card_num);

        card[++card_num] = sum;
        push_up(card, card_num);


    }

    sum = 0;
    //�켱����ť�� ��� ���� ����
    while (card_num > 0) {
        a = card[1];
        card[1] = card[card_num--];
        push_down(card, 1);


        sum += a;


    }


    printf("%lld\n", sum);
    return 0;
}

