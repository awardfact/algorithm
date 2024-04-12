#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {

    if (*(int*)a > *(int*)b) {
        return 1;
    }
    else if (*(int*)a == *(int*)b) {
        return 0;
    }
    else {
        return -1;
    }



}

int main() {
    int n, b, k;
    int min, i, j;
    int failure[100000];
    int start;
    int end;
    int cnt;
    int com_flag = 0;

    min = 0x7FFFFFFF;
    scanf("%d %d %d", &n, &k, &b);

    for (i = 0; i < b; i++) {
        scanf("%d", &failure[i]);

    }
    //���峭�� ����
    qsort(failure, b, sizeof(int), compare);

    //���峭�� �ݺ� ������ k�� �����Ű���� ���� i��°���� � ���ľ��ϴ��� ����ؼ� ������ ����
    for (i = 0; i < b; i++) {
        //1�̸� 1���ͽ���
        if (i == 0) {
            start = 1;

            //�̿ܿ��� ���� ���� + 1
        }
        else {
            start = failure[i - 1] + 1;
        }
        com_flag = 0;
        cnt = 0;

        //���粨���� �ݺ� ���Ƽ� ���ľ� �ϴ��� �Ǵ�
        for (j = i; j < b; j++) {

            end = failure[j] - 1;
            if (end - start + 1 >= k) {
                com_flag = 1;
                break;
            }
            else {
                cnt++;
            }

        }

        //�������������� ���Ŀ� ���峭�� ��� end�� n����
        if (com_flag == 0) {
            end = n;
        }

        //  printf("i : %d cnt : %d\n", i, cnt);

          //k���� �̾��� ��ģ ���ڰ� min���� ������ ��ü
        if (end - start + 1 >= k && cnt < min) {
            min = cnt;
        }



    }

    end = n;
    start = failure[b - 1] + 1;
    cnt = 0;
    if (end - start + 1 >= k && cnt < min) {
        min = cnt;
    }


    if (b == 0) {
        min = 0;
    }

    printf("%d\n", min);

    return 0;
}