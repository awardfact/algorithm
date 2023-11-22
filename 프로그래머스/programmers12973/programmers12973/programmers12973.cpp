// programmers12973.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <iostream>
#include<string>
#include <list>
using namespace std;

#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 1;

    string ss = s;

    stack<char> st;
    int i = 0;


    // string 끝까지 탐색하고 stack데이터 없거나 스택에 데이터 없는데 스택 top데이터와 다르면 push하고 같으면 pop해준다 
    while (ss[i] != '\0') {


        if (!st.empty()) {
            if (!st.empty() && st.top() == ss[i]) {
                i++;
                st.pop();
            }
            else {
                st.push(ss[i]);
                i++;
            }

        }
        else {
            st.push(ss[i]);
            i++;


        }

    }


    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.

    if (st.empty()) {
        answer = 1;
    }
    else {
        answer = 0;
    }
    cout << answer << endl;
    return answer;
}

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.

    if (st.empty()) {
        answer = 1;
    }
    else {
        answer = 0;
    }
    cout << answer << endl;
    return answer;
}
int main()
{
    std::cout << "Hello World!\n";
}

