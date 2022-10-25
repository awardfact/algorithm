

#include <iostream>
#include <algorithm>
using namespace std;
/*
* 
* 값이 1개여도 1이 나와서 기본 수는 1이댐 
전꺼보다 크면 전꺼 개수 + 1
10 20 10 30 20 50
1  2   1   3   2   4    나오는 개수 
전꺼 값보다 클때 전꺼 값 나오는 개수 + 1 이댐 

*/
int main()
{
	int N, tmp;
	cin >> N;
	int* su = new int[N] {0, };

	for (int i = 0; i != N; i++) {
		cin >> tmp;
		*(su + i) = tmp;
	}

	int dp[1000] = { 0, };

	int count = 1;
	int max = 0;
	for (int i = 0; i != N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {

			if(*(su + i) > *(su + j) && dp[i] <dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}



	sort(dp, dp + N);



	cout << dp[N - 1] << "\n";

	//cout << count << "\n";
	return 0;

}

