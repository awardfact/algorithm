
#include <iostream>
#include <vector>

using namespace std;
/*
문자열을 입력받음
반지의 개수 입력받음
반지 개수만큼 문자열을 입력받음

반지의 개수만큼 반복
반지의 첫 번째 문자부터 10 - 찾는 문자 size까지반복
substr i부터 찾는문자 size해서 찾음
같으면 count ++ break하는 식으로 개수를 카운팅

++ 반지여서 뒤부터 앞도 가능

*/
int main()
{
	int n;
	string find;
	cin >> find >> n;
	vector<string> ring;
	string tmp;
	for (int i = 0; i != n; i++) {
		cin >> tmp;
		ring.push_back(tmp);
	}

	int count = 0;
	int tmp2;

	for (int i = 0; i != n; i++) {
		for (int j = 0; j != ring[i].length(); j++) {
			if (ring[i].length() < j + find.length()) {
				tmp2 = j + find.length() - ring[i].length();
				tmp = ring[i].substr(j);
				tmp += ring[i].substr(0, tmp2);
			}
			else {
				tmp = ring[i].substr(j, find.length());
			}

			if (tmp == find) {
				count++;
				break;
			}

		}


	}

	cout << count << "\n";

	return 0;
}