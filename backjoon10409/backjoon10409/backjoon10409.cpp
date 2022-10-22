

#include <iostream>
#include <vector>
using namespace std;
/*
T분 시간이 주어지고 요청된 일의 수행시간이 주어진다 FCFS(first-come first-served)규칙에 따라
요청된 일을 처리하는데 T시간동안 몇개의 일을 완수할 수 있는지 출력하는 프로그램

vector<int>로 변수를 설정하고 걸리는 시간을 여기에 넣는데
개수만큼 반복문을 돌고 T시간 - 벡터에 있는 시간해서
마이너스를 시켰을 떄 T가 0보다 크거나 갖으면 count++하고
아니면 count을 출력
*/
int main()
{
	int n, t;
	cin >> n >> t;

	vector<int> time;

	int tmp; 
	for (int i = 0; i != n; i++) {
		cin >> tmp;

		time.push_back(tmp);
	}
	int count = 0;
	for (int i = 0; i != n; i++) {
		t -= time[i];

		if (t >= 0) {
			count++;
		}
		else {
			break;
		}

	}

	cout << count << "\n";




}

