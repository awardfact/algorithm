#include <stdio.h>

int main() {

    int n;
    int heap[200001] = { 0, };
    int input_num;
    int tmp;
    int node_num = 1;
    int current_node = 0;
    int i;


    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &input_num);
        //힙에서 삭제
        if (input_num == 0) {
            //힙에 노드가 있는경우만 
            if (node_num > 1) {
                //출력하고 가장 하위 노드를 가장 상위 노드로 옮김
                printf("%d\n", heap[1]);
                heap[1] = heap[node_num - 1];
                node_num--;
                current_node = 1;
                // printf("node_num : %d\n", node_num);
                 // 자식 노드가 있는 경우 반복 진행
                while (current_node * 2 < node_num) {
                    //자식노드가 더 크면 자리를 바꿈
                    //printf("%d %d %d\n",heap[current_node] , heap[current_node *2 ] , heap[current_node * 2 + 1] );
                    if (heap[current_node] > heap[current_node * 2] || (current_node * 2 + 1 < node_num && heap[current_node] > heap[current_node * 2 + 1])) {
                        if (current_node * 2 + 1 < node_num && heap[current_node * 2 + 1] < heap[current_node * 2]) {
                            tmp = heap[current_node * 2 + 1];
                            heap[current_node * 2 + 1] = heap[current_node];
                            heap[current_node] = tmp;
                            current_node = current_node * 2 + 1;
                        }
                        else {
                            tmp = heap[current_node * 2];
                            heap[current_node * 2] = heap[current_node];
                            heap[current_node] = tmp;
                            current_node *= 2;
                        }

                        continue;
                    }
                    break;

                }
            }
            else {
                //비어있으면 0 출력
                printf("0\n");
            }

            //힙에 추가 
        }
        else {
            heap[node_num] = input_num;
            current_node = node_num;
            //상위노드가 있을때까지 반복 
            while (current_node / 2 > 0) {
                // printf("hear[node] %d  heap[node/2] %d\n",heap[current_node] ,heap[current_node / 2]);
                 //상위노드보다 더 작으면 상위노드와 위치 바꿈
                if (heap[current_node] < heap[current_node / 2]) {
                    tmp = heap[current_node / 2];
                    heap[current_node / 2] = heap[current_node];
                    heap[current_node] = tmp;
                    current_node /= 2;
                }
                else {
                    break;
                }
            }
            // printf("node : %d\n", heap[1]);
            node_num++;
        }




    }



    return 0;
}