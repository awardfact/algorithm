#include <iostream>


using namespace std;

int main() {

	int n;
	cin >> n;

	int tmp = 0;
	int min  = 999999999;
	int max = 0;
	// 약수 공식이 약수중에 가장 작은 수와 가장 큰 수를 곱하면 나와서 입력된값중에서 최소값이랑 최대값을 구하고 곱한걸 출력해준다 
	for (int i = 0; i != n; i++) {
		cin >> tmp;
		if ( min > tmp) {
			min = tmp;

		}

		if (max < tmp) {
			max = tmp;
		}

	}

	cout << min * max << "\n";

	return 0;

}