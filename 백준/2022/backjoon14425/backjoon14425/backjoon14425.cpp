#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int main()
{

	int n = 0;
	int m = 0;
	//집합을 넣을 string벡터 선언
	//vector<string> j;
	map<string, int> j;
	string s;
	// n값과 m값을 받아옴
	cin >> n;
	cin >> m;

	// n개수만큼 문자열을 string벡터에 넣음
	//for (int i = 0; i != n; i++) {
	//	cin >> s;
	//	if (find(j.begin(), j.end(), s) == j.end()) {
	//		j.push_back(s);
	//	}
	//}

	for (int i = 0; i != n; i++) {
		cin >> s;
		if (j.find(s) == j.end()) {
			j.insert({ s, 1 });
		}
	}



	int count = 0;
	//// m개수만큼 문자열을 받아서 string vector에 있는값이면 count++
	//for (int i = 0; i != m; i++) {
	//	cin >> s;
	//	if (find(j.begin(), j.end(), s) != j.end()) {
	//		count++;
	//	}
	//}
	for (int i = 0; i != m; i++) {
		cin >> s;
		if (j.find(s) != j.end()) {
			count++;
		}
	}
	


	cout << count << endl;
	

}

