
#include <iostream>
#include <algorithm>
#include <map>
#include <random>
#include <string>
using namespace std;
string poketmon[100001];
int isalpha2(string s) {

	int alpha = 1;
	for (int i = 0; i < s.size(); i++) {
		if (!isalpha(s[i])) {
			alpha = 0;
		}
	}
	return alpha;

}

int main()
{
	// 포켓몬 도감 수 , 맞출 문제 수 입력받는 정수 
	int n, m = 0;

	// 맞춰야 하는 포켓몬도감맵
	map<string, int> poket;

	// 도감 수 , 맞출 문제 수를 입력받음
	cin >> n;
	cin >> m;
	string s;
	
	cin.tie(0); 
	ios::sync_with_stdio(0);



	for (int i = 1; i <= n; i++) {
		cin >> s;
		//포켓몬 이름이 영어로 이루어져있고 2~20자일 떄만 도감에 넣는다
		if (isalpha2(s) && (s.length() >= 2 && s.length() <= 20)) {
			poketmon[i] = s;
			poket.insert({ s, i });

		}
	}


	// 랜덤 설정
	//random_device rd;   
	//mt19937 gen(rd());
	//uniform_int_distribution<> dist(1, poket.size());
	//uniform_int_distribution<> dist2(0, 1);
	
	//랜덤 숫자를 받을 변수 선언 
	int rand1 = 0;
	int rand2 = 0;

	//int answer;
	string answer;


	// 맵에 들어있는 값을 담을 iter선언
	map<string, int>::iterator iter;

	int success = 0;
	for (int i = 0; i < m; i++) {
		cin >> answer;


		if (isalpha2(answer)) {
			iter = poket.find(answer);
			cout << iter->second << "\n";
		}
		else {
			cout << poketmon[stoi(answer)] << "\n";

		}


		// 포켓몬 번호, 번호 또는 이름 랜덤돌림 
		//rand1 = dist(gen);
		//rand2 = dist2(gen);

		// 번호에 맞는 포켓몬을 맵에석 가져옴 
		//iter = poket.find(rand1);

		/*
		
		
		// 두번쨰 랜덤이 0이면 번호를 보여주고 이름을 맞추기 
		if (rand2 == 0) {
			cout << iter->first  << endl;
			cin >> sanswer;

			if (sanswer == iter->second) {

				success++;
			}

		}
		// 두번쨰 랜덤이 1이면 이름을 보여주고 번호를 맞추기 
		else {
			cout <<  iter->second << endl;
			cin >> answer;

			if (answer == iter->first) {
				success++;

			}
		}
		
		*/

		


	}


	
	return 0;


}

