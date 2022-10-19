
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int isalpha2(string s) {



}

int main()
{
	// 포켓몬 도감 수 , 맞출 문제 수 입력받는 정수 
	int n, m = 0;

	// 맞춰야 하는 포켓몬도감맵
	map<int, string> poket;

	// 도감 수 , 맞출 문제 수를 입력받음
	cin >> n;
	cin >> m;
	string s;
	for (int i = 0; i != n; i++) {
		cin >> s;
		//포켓몬 이름이 영어로 이루어져있고 2~20자일 떄만 도감에 넣는다
		if (isalpha2(s) && (s.length() >= 2 && s.length() <= 20)) {


		}
	}



}

