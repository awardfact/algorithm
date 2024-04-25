#include <stdio.h>
#include <stdlib.h>

typedef struct stackT {
    int startx;
    int endx;
    int starty;
    int endy;
    int bracket;
    struct stackT* before;
    struct stackT* after;


}stack;

stack* top_stack = NULL;
stack* tmp_stack = NULL;




void push(int startx, int endx, int starty, int endy, int bracket) {

    tmp_stack = (stack*)malloc(sizeof(stack));

    tmp_stack->startx = startx;
    tmp_stack->endx = endx;
    tmp_stack->starty = starty;
    tmp_stack->endy = endy;
    tmp_stack->bracket = bracket;

    tmp_stack->before = NULL;
    tmp_stack->after = NULL;
    if (top_stack == NULL) {
        top_stack = tmp_stack;

    }
    else {
        top_stack->after = tmp_stack;
        tmp_stack->before = top_stack;
    }

    top_stack = tmp_stack;
}



stack* pop() {

    if (top_stack != NULL) {
        tmp_stack = top_stack;
        top_stack = top_stack->before;
        return tmp_stack;
    }
    else {
        return NULL;
    }

}







int main() {
    int n, i, j;
    stack* pop_stack;
    char qtree[65][65] = { 0, };
    char print_tree[10000] = { 0, };
    int print_index = 0;
    char start_dot = 0;
    char dif_flag = 0;
    int left_bracket[100] = { 0, };
    char midx, midy;



    scanf("%d", &n);


    for (i = 1; i <= n; i++) {
        scanf("%s", qtree[i] + 1);
    }


    // for(i = 1; i <= n; i++){
    //     for(j = 1; j <=n; j++){
    //         printf("%c", qtree[i][j]);
    //     }
    //     printf("\n");
    // }


    start_dot = qtree[1][1];
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (start_dot != qtree[i][j]) {
                //������ �Ʒ�
                push(n / 2 + 1, n, n / 2 + 1, n, 1);
                //���� �Ʒ�
                push(1, n / 2, n / 2 + 1, n, 1);

                //������ ��
                push(n / 2 + 1, n, 1, n / 2, 1);

                //���� �� 
                push(1, n / 2, 1, n / 2, 1);

                //�� ��ȣ �������� 1�� 4���� ���־���
                left_bracket[1] = 4;

                print_tree[print_index++] = '(';
                dif_flag = 1;
                break;
            }

        }

        if (dif_flag == 1) {
            break;
        }
    }

    if (dif_flag == 0) {

        printf("%c\n", start_dot);
    }
    else {

        //���̿켱 Ž�� ���� 
        while (top_stack != NULL) {
            pop_stack = pop();
            start_dot = qtree[pop_stack->starty][pop_stack->startx];
            dif_flag = 0;
            //  printf("%d %d %d %d  %c\n", pop_stack->startx, pop_stack->endx, pop_stack->starty, pop_stack->endy, start_dot);
            for (i = pop_stack->starty; i <= pop_stack->endy; i++) {
                for (j = pop_stack->startx; j <= pop_stack->endx; j++) {
                    if (start_dot != qtree[i][j]) {
                        midx = (pop_stack->startx + pop_stack->endx) / 2;
                        midy = (pop_stack->starty + pop_stack->endy) / 2;
                        //������ �Ʒ�
                        push(midx + 1, pop_stack->endx, midy + 1, pop_stack->endy, pop_stack->bracket + 1);
                        //���� �Ʒ�
                        push(pop_stack->startx, midx, midy + 1, pop_stack->endy, pop_stack->bracket + 1);

                        //������ ��
                        push(midx + 1, pop_stack->endx, pop_stack->starty, midy, pop_stack->bracket + 1);

                        //���� �� 
                        push(pop_stack->startx, midx, pop_stack->starty, midy, pop_stack->bracket + 1);

                        //��ȣ�߰�
                        left_bracket[pop_stack->bracket + 1] += 4;
                        print_tree[print_index++] = '(';
                        dif_flag = 1;
                        break;

                    }
                }

                if (dif_flag == 1) {
                    break;
                }
            }

            //  printf("%d %d %d %d  %c\n", pop_stack->startx, pop_stack->endx, pop_stack->starty, pop_stack->endy, start_dot);

            if (dif_flag == 0) {
                print_tree[print_index++] = start_dot;
                //�ش� ��ȣ�� ������ ������ ����
                left_bracket[pop_stack->bracket]--;

                //�ش� ��ȣ ���� ������ 4�� ���������°�� 
                while (left_bracket[pop_stack->bracket] % 4 == 0) {
                    //�ݴ� ��ȣ �߰��ϰ� ���� ��ȣ���� ������ ������ �Ѱ� ����
                    print_tree[print_index++] = ')';
                    if (pop_stack->bracket > 1) {
                        pop_stack->bracket--;
                        left_bracket[pop_stack->bracket]--;

                    }
                    else {
                        break;
                    }

                }

            }


            free(pop_stack);
        }
        print_tree[print_index] = '\0';
        printf("%s\n", print_tree);

    }




    return 0;
}