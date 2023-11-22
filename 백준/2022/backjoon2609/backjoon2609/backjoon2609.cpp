

#include <iostream>
#include <cmath>
using namespace std;

int uclid(int a, int b) {
	int c = a % b;
	if (c == 0) {
		return b;
	}
	return uclid(b, c);
}

int main()
{
	int n, m;

	int j = 0;

	cin >> j;

	int result[1000];

	for (int i = 0; i != j; i++) {



		cin >> n >> m;


		// 유클리드 호제법을 이용하면 최대공약수를 구할 수 있고 최ㅅ공배수는 m * n /최대공약수이다 
		int max = 0;
		if (n > m) {
			max = uclid(n, m);


		}
		else if (n < m) {
			max = uclid(m, n);

		}
		else if (n == m) {
			max = n;

		}

		result[i] = (m * n) / max;




	}

	for (int i = 0; i != j; i++) {
		cout << result[i] << "\n";
	}


		
}


