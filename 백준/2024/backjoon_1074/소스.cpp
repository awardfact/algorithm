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
    //n r c입력받음 
    scanf("%d %d %d", &n, &r, &c);

    //여기는 0부터 시작하지만 제곱근 구하기 위해서 + 1해서 계산
    rtmp = r + 1;
    ctmp = c + 1;

    // r위치와 c위치가 0 이상이면 반복 
    while (rtmp > 0 && ctmp > 0) {

        // r,y 제곱근을 구함
        x = isqrt(rtmp - 1);
        y = isqrt(ctmp - 1);
        big = 0;
        // 더 큰 제곱근으로 선택 
        if (x > y || x == y) {
            big = x;
        }
        else if (y > x) {
            big = y;
        }

        //제곱근이 1 이상이면 
        if (big > 0) {

            // r또는 c 좌표는 2의 big제곱 이후에 존재하기 때문에 2의 big제곱 계산
            tmp = ipow(2, big);

            //r또는 c좌표가 2의 big제곱 이후에 있다는것은 이전 순서에 최소 big크기의 n배열을 다 탐색했다는 거고 그중에서 r좌표만 이후 좌표면 1 c좌표만 이후 좌표면 2 둘다 이후 좌표면 3개의 big 크기 테이블을 탐색했다는거여서
            // 각각 1 2 3을 곱해줌  
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

            //이쪽으로 오면 가장 작은 크기의 n상자만 남은거여서 1 2 3 4를 더해줘야 하지만 문제는 0부터 시작해서 0 1 2 3을 더해줌 
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