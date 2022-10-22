// backjoon5543.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main()
{
	int sangduck;
	int jungduck;
	int haduck;
	int cola;
	int cidar;

	int min = 2500;
	//상덕 중덕 하덕 사이다 콜라 가격을 받고 가장 싼 세트 메뉴의 가격을 출력한다  세트는 햄버거 + 콜라 - 50이다 
	cin >> sangduck >> jungduck >> haduck >> cola >> cidar;
	
	min = sangduck;
	if (min > jungduck) {
		min = jungduck;
	}

	if (min > haduck) {
		min = haduck;
	}

	if (cola > cidar) {
		cout << min + cidar - 50 << "\n";
	}
	else {
		cout << min + cola - 50 << "\n";

	}


	return 0;
}

