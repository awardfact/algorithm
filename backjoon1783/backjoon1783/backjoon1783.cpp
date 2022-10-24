// backjoon1783.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

/*
* 
* 

위아래가 충분할 때 가능한 수는 1 + (N -2)
세로는 3개 이상이면 모두 가능 3개 이하면 최대 3개 

5개 미만인 경우에는 같은 경우의 수만 이용이 가능 

세로가 1이거나 가로 1이면 1

세로가 2인 경우 
가로가 7 이상이면 4 5이상이면 3 3이상이면 2 나머지 1

세로가 3 이상인 경우
가로가 1이면 1
가로가 2면 2
가로가 3이면 3 
가로가 4면 4
가로가 7 이상이면  N-2 
*/
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    int count = 0;
    if (n >= 3) {

        if (m >= 7)
        {
            count = m - 2;
        }
        else if (m >= 4) {
            count = 4;
        }
        else if (m >= 3) {
            count = 3;
        }
        else if (m >= 2) {
            count = 2;
        }
        else {
            count = 1;
        }
        
    }
    else if(n == 2) {
        
        if (m >= 7) {

            count = 4;
        }else if (m >= 5) {
            count = 3;
        }
        else if(m >= 3) {
            count = 2;
        }
        else {
            count = 1;
        }


    }
    else {
        count = 1;
    }
        

    cout << count << "\n";

    return 0;
}


