#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int isqrt(int num) {
    int value = 0;
    while (num / 2 > 0) {
        if (num / 2 > 0) {
            value++;
            num /= 2;
        }

    }

    return value;
}

int ipow(int num, int cnt) {
    int i;
    int value = num;
    for (i = 1; i < cnt; i++) {
        value *= num;
    }
    return value;

}

int main() {

    int n, r, c;
    int x, y;
    int rtmp, ctmp;
    int big;
    unsigned int count = 0;
    int tmp;
    //n r c�Է¹��� 
    scanf("%d %d %d", &n, &r, &c);

    //����� 0���� ���������� ������ ���ϱ� ���ؼ� + 1�ؼ� ���
    rtmp = r + 1;
    ctmp = c + 1;

    // r��ġ�� c��ġ�� 0 �̻��̸� �ݺ� 
    while (rtmp > 0 && ctmp > 0) {

        // r,y �������� ����
        x = isqrt(rtmp - 1);
        y = isqrt(ctmp - 1);
        big = 0;
        // �� ū ���������� ���� 
        if (x > y || x == y) {
            big = x;
        }
        else if (y > x) {
            big = y;
        }

        //�������� 1 �̻��̸� 
        if (big > 0) {

            // r�Ǵ� c ��ǥ�� 2�� big���� ���Ŀ� �����ϱ� ������ 2�� big���� ���
            tmp = ipow(2, big);

            //r�Ǵ� c��ǥ�� 2�� big���� ���Ŀ� �ִٴ°��� ���� ������ �ּ� bigũ���� n�迭�� �� Ž���ߴٴ� �Ű� ���߿��� r��ǥ�� ���� ��ǥ�� 1 c��ǥ�� ���� ��ǥ�� 2 �Ѵ� ���� ��ǥ�� 3���� big ũ�� ���̺��� Ž���ߴٴ°ſ���
            // ���� 1 2 3�� ������  
            if (rtmp > tmp && ctmp > tmp) {
                count += ipow(4, big) * 3;
                rtmp -= tmp;
                ctmp -= tmp;
            }
            else if (ctmp > tmp) {
                count += ipow(4, big);
                ctmp -= tmp;
            }
            else if (rtmp > tmp) {
                rtmp -= tmp;
                count += ipow(4, big) * 2;
            }

            //�������� ���� ���� ���� ũ���� n���ڸ� �����ſ��� 1 2 3 4�� ������� ������ ������ 0���� �����ؼ� 0 1 2 3�� ������ 
        }
        else {

            if (rtmp == 1 && ctmp == 1) {
            }
            else if (rtmp == 1 && ctmp == 2) {
                count += 1;
            }
            else if (rtmp == 2 && ctmp == 1) {
                count += 2;
            }
            else if (rtmp == 2 && ctmp == 2) {
                count += 3;
            }
            rtmp = 0;
            ctmp = 0;
        }




    }




    printf("%d\n", count);




    return 0;
}