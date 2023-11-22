// backjoon20113.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
/*
크기가 101인 배열 만들고
n을 입력받고
n개의 정수를 입력받아서 배열에 넣는다
배열을 돌아서 최대 수가 나오면 max를 최대로 하고
동일한 수면 skip 1로 만듬
최대수가 갱신되면 skip은 다시 0
*/
using namespace std;
int main()
{
	int n;
	cin >> n;
	int tmp;

	int impo[101] = { 0, };

	int skip  = 1;
	int max = 0;
	int realImpo = 0;

	for (int i = 0; i != n; i++) {
		cin >> tmp;
		impo[tmp]++;
	}

	for (int i = 1; i <= n; i++) {
		if (max < impo[i]) {
			max = impo[i];
			skip = 0;
			realImpo = i;
		}
		else if (max == impo[i]) {
			skip = 1;
		}


	}
	if (skip == 1) {
		cout << "skipped" << "\n";
	}
	else {
		cout << realImpo << "\n";

	}





}
