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
        //������ ����
        if (input_num == 0) {
            //���� ��尡 �ִ°�츸 
            if (node_num > 1) {
                //����ϰ� ���� ���� ��带 ���� ���� ���� �ű�
                printf("%d\n", heap[1]);
                heap[1] = heap[node_num - 1];
                node_num--;
                current_node = 1;
                // printf("node_num : %d\n", node_num);
                 // �ڽ� ��尡 �ִ� ��� �ݺ� ����
                while (current_node * 2 < node_num) {
                    //�ڽĳ�尡 �� ũ�� �ڸ��� �ٲ�
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
                //��������� 0 ���
                printf("0\n");
            }

            //���� �߰� 
        }
        else {
            heap[node_num] = input_num;
            current_node = node_num;
            //������尡 ���������� �ݺ� 
            while (current_node / 2 > 0) {
                // printf("hear[node] %d  heap[node/2] %d\n",heap[current_node] ,heap[current_node / 2]);
                 //������庸�� �� ������ �������� ��ġ �ٲ�
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