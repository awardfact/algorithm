#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int heap_cnt;
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;

}


//�� ����
void push_up(int* heap, int i) {

    if (i / 2 > 0) {
        //�θ� ��庸�� ũ�� �ڸ� ����
        if (heap[i] > heap[i / 2]) {
            swap(&heap[i], &heap[i / 2]);
            push_up(heap, i / 2);
        }
    }


}

//�ִ밪 ����
void push_down(int* heap, int i) {

    if (i * 2 + 1 <= heap_cnt) {
        int r = heap[i * 2 + 1];
        int l = heap[i * 2];

        int max;
        int node;

        if (l > r) {
            max = l;
            node = i * 2;
        }
        else {
            max = r;
            node = i * 2 + 1;
        }


        if (heap[i] < max) {
            swap(&heap[i], &heap[node]);
            push_down(heap, node);
        }

    }
    else if (i * 2 <= heap_cnt) {
        int l = heap[i * 2];

        if (heap[i] < l) {
            swap(&heap[i], &heap[i * 2]);
            push_down(heap, i * 2);
        }


    }


}


int main() {

    int i, j, n;
    int input;
    int max_heap[100001] = { 0, };

    scanf("%d", &n);
    heap_cnt = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &input);

        if (input == 0) {
            //���� ������ 0 ���
            if (heap_cnt == 0) {
                printf("0\n");
                continue;
                //�� �������ִ밪 ���
            }
            else {
                printf("%d\n", max_heap[1]);
            }

            //�ִ밪 ����
            max_heap[1] = max_heap[heap_cnt];
            heap_cnt--;
            push_down(max_heap, 1);

        }
        else {
            //�� ����
            max_heap[++heap_cnt] = input;
            push_up(max_heap, heap_cnt);

        }

    }



    return 0;
}