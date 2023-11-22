
#include <iostream>

/*
점수가 최소려면 어디에 있든 같은 숫자는 붙어 있어야함
그러면 i두개는 한몸으로 치고 이 개수들의 위치가 있을 수 있는 경우의 수를
계산하면 됨
N이 주어졌을 때 N개의 숫자가 정렬될 수 있는 경우의 수 계산
*/
using namespace std;
int main()
{

	int n;

	cin >> n;
	int su = 1;
	for (int i = n; i > 1; i--) {

		su *= i;
	}

	cout << su << "\n";
	return 0;
}

