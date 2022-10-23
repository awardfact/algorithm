

#include <iostream>

using namespace std;
/*


2일떄
1 2 를  21 로만 가능 1개

4일떄
1234를 21 43 / 41  23  /  13 24  가능 3개

6일떄
123456을  12 34 56 일떄 3개   13 3개   14 3개 15 3개 16 3개 가능
이렇게 해보면 공식이
n -1 * 전에꺼 경우의 수라는 것을 알 수 있다


재귀함수를 이용해서
n이 2면 1을 리턴하고 아니면
n -1 *  (n-2)재귀함수를 리턴한다





*/
long cup(long n) {

    
    if (n == 2) {
        return 1;
    }
    else {
        return ((n - 1) * cup(n - 2) )  % 1000000007;
    }

}

int main()
{

    long m;
    cin >> m;


    long result = cup(m);

    cout << result << "\n";

    return 0;

}

