
#include <iostream>

using namespace std;
int main()
{
    //방학은 L일 수학은 B페이지 국어는 A페이지이다 하루에 국어 C페이지 수학을 D페이지까지 풀 수 있다 숙제를 하지 않고 놀 수 있는 날을 구하라 

    int L, B, A, C, D;
    cin >> L >> A >> B  >> C >> D;

    for (int i = L -1; i > 0; i--) {
        B -= D;
        A -= C;

        if (B <= 0 && A <= 0) {
            cout << i << "\n";
            break;
        }

    }

    return 0;
}
