#include <iostream>


using namespace std;

int main() {

	int n;
	cin >> n;

	int tmp = 0;
	int min  = 999999999;
	int max = 0;
	// ��� ������ ����߿� ���� ���� ���� ���� ū ���� ���ϸ� ���ͼ� �ԷµȰ��߿��� �ּҰ��̶� �ִ밪�� ���ϰ� ���Ѱ� ������ش� 
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