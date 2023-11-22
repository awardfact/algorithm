// backjoon2750.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    int x[1000] = { 0 , };
    int y = 0;
    int i = 0;

    int j = 0;

    cin >> n;
    // 숫자를 받아옴 
    for (j = 0; j != n; j++) {
        cin >> x[j];
    }

    int k = 0;
    int tmp = 0;

    // 버블 정렬 실행 
    for (j = 0; j < n -1; j++) {
        for (k = j + 1; k < n; k++) {
            if (x[j] > x[k]) {
                tmp = x[j];
                x[j] = x[k];
                x[k] = tmp;
            }
        }
    }
    int before = 0;
    for (j = 0; j != n; j++) {
        if (j != 0 && before == x[j]) {
            continue;
        }
        else {
            before = x[j];
        }

        cout << x[j] << endl;
    }


}

