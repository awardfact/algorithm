

#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
using namespace std;

/*
첫쨰 줄에 종이의 줄 개수입력을 받는다
다음 N줄에는 각 줄의 내용이 주어진다
숫자를 임시 저장할 변수 tmp선언
N개만큼 반복을 돌리고 그 안에
각 줄의 글자들을 반복을 돌린다
글자 처음부터 돌면서 숫자가 있으면 tmp에 숫자를 추가한다
만약 tmp가 빈 내용일 때 0이 나오면 그냥 패스한다 알파벳이 나와도 패스
tmp에 내용이 있는데 알파벳이 나오거나 글이 끝난 경우에는
int vector에 값을 추가한다
다 한다음에 vector정렬 후 출력

out of range뜨는데 최대 100자인데 다 숫자이면 범위 넘어가는거라 뜨는거같음

*/

//ss가 크면 1
bool compare(const string s,const  string ss) {
	if (s.size() != ss.size()) {
		return s.size() < ss.size();
	}
	else {
		return s.compare(ss)< 0;
	}
	


}

int main()
{
	int n;
	vector<string> num;
	vector<string> line;

	int i, j;
	string tmp = "";

	cin >> n;
	string s;
	for (int i = 0; i != n; i++) {
		cin >> s;
		line.push_back(s);
	}

	//N줄의 글을 읽음
	for (i = 0; i != line.size(); i++) {
		tmp = "";
		// i번쨰 줄의 글자를 읽어서 숫자가 있으면 숫자를 읽고 숫자의 앞에 0이 있으면 생략한다 
		for ( j = 0; j != line[i].length(); j++) {
			// j번째 글자가 숫자인 경우 
			if (isdigit(line[i].at(j))) {
				// 첫 숫자가 0인경우
				if (line[i].at(j) == '0' && tmp == "") {
					 // 첫 숫자는 0이지만 마지막 글자인경우 tmp에 0을 추가한다 
					if (j == line[i].length()-1) {
						tmp += line[i].at(j);
					}
				}
				// 첫 숫자가 0이 아닌 숫자인 경우 tmp에 숫자를 추가한다 
				else {
					tmp += line[i].at(j);
				}


			}

			// 숫자가 아닌경우 
			else {
				// tmp에 숫자들이 있으면 숫자 배열에 tmp를 추가 
				if (tmp != "") {

					num.push_back(tmp);
					tmp = "";
				}

			}

		}

		//i번쨰 줄의 마지막 글자가 숫자면 tmp에 있는 숫자를 숫자 배열에 추가해준다    
		if (tmp != "") {
			num.push_back(tmp);
		}
	}



	//비내림차순 정렬 
	sort(num.begin(), num.end(), compare);


	// 정렬한 숫자들 출력 
	for (i = 0; i != num.size(); i++) {
		cout << num[i] << "\n";
	}


}
