#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int card_num = 0;

// 순서 바꾸는 함수
void swap(long long int* a, long long int* b) {
    long long int tmp = *a;
    *a = *b;
    *b = tmp;


}

//우선순위 큐 삽입 후 올리는 함수 
void push_up(long long int* card, int n) {

    int p;
    while (n / 2 > 0) {
        p = n / 2;
        //부모가 더 크면 자리변경
        if (card[p] > card[n]) {
            swap(&card[p], &card[n]);
            n /= 2;
        }
        else {
            break;
        }
    }

}



//우선순위 큐 삭제 후 내리는 함수 
void push_down(long long int* card, int n) {

    int l, r;

    //자식이 있는 고 자식이 더 작은 경우 더 작은 자식과 위치 변경
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

    //입력받으면 우선순위 큐에 넣음
    for (i = 0; i < n; i++) {
        scanf("%d ", &input_card);


        card[++card_num] = input_card;
        push_up(card, card_num);

    }

    //우선순위 큐에서 2개 빼서 더하고 2개 다시 삽입
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
    //우선순위큐를 모두 빼서 더함
    while (card_num > 0) {
        a = card[1];
        card[1] = card[card_num--];
        push_down(card, 1);


        sum += a;


    }


    printf("%lld\n", sum);
    return 0;
}

