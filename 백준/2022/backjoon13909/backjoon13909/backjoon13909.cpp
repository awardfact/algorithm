
#include <iostream>
#include <cmath>

/*
약수의 개수가 홀수면 열린 상태가 된다
약수의 개수가 홀수가 되려면 제곱수여야 한다
N의 제곱근을 구한다
*/
using namespace std;
int main()
{
    int n;
    cin >> n;


    int m = sqrt(n);
    cout << m << "\n";


    return 0;
}

