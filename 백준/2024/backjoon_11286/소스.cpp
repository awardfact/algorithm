#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct absHeapT {

    int value;
    char unsigned_flag;


}absHeap;

int heap_cnt;
void swap(absHeap* a, absHeap* b) {
    absHeap tmp = *a;
    *a = *b;
    *b = tmp;

}


//�� ����
void push_up(absHeap* heap, int i) {

    if (i / 2 > 0) {
        //�θ� ��庸�� ũ�ų� ���� ������ ����� �ڽ� ��尡 ������ �ڸ� ����
        if (heap[i].value < heap[i / 2].value || (heap[i].value == heap[i / 2].value && heap[i].unsigned_flag < heap[i / 2].unsigned_flag)) {
            swap(&heap[i], &heap[i / 2]);
            push_up(heap, i / 2);
        }
    }


}

//�ּҰ� ����
void push_down(absHeap* heap, int i) {

    if (i * 2 + 1 <= heap_cnt) {
        absHeap r = heap[i * 2 + 1];
        absHeap l = heap[i * 2];

        absHeap min;
        int node;

        if (l.value < r.value || (l.value == r.value && l.unsigned_flag < r.unsigned_flag)) {
            min = l;
            node = i * 2;
        }
        else {
            min = r;
            node = i * 2 + 1;
        }


        if (heap[i].value > min.value || (min.value == heap[i].value && min.unsigned_flag < heap[i].unsigned_flag)) {
            swap(&heap[i], &heap[node]);
            push_down(heap, node);
        }

    }
    else if (i * 2 <= heap_cnt) {
        absHeap l = heap[i * 2];

        if (heap[i].value > l.value || (l.value == heap[i].value && l.unsigned_flag < heap[i].unsigned_flag)) {
            swap(&heap[i], &heap[i * 2]);
            push_down(heap, i * 2);
        }


    }


}


int main() {

    int i, j, n;
    int input;
    absHeap min_heap[100001];

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
                if (min_heap[1].unsigned_flag == 1) {
                    printf("%d\n", min_heap[1].value);
                }
                else {
                    printf("-%d\n", min_heap[1].value);
                }

            }

            //�ִ밪 ����
            min_heap[1].value = min_heap[heap_cnt].value;
            min_heap[1].unsigned_flag = min_heap[heap_cnt].unsigned_flag;
            heap_cnt--;
            push_down(min_heap, 1);

        }
        else {
            //�� ����
            min_heap[++heap_cnt].value = abs(input);
            if (input > 0) {
                min_heap[heap_cnt].unsigned_flag = 1;
            }
            else {
                min_heap[heap_cnt].unsigned_flag = 0;
            }
            push_up(min_heap, heap_cnt);

        }

    }



    return 0;
}