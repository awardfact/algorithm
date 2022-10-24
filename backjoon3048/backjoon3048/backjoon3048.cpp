

#include <iostream>
using namespace std;

/*
첫 번쨰 줄에 첫 개미 그룹 수와 두 번째 개미 그룹 수를 입력받는다
 다음 두 개 줄에는 그룹별로 개미의 순서가 주어진다
마지막에는 시간(T)가 주어진다



A배열에는 A그룹
B배열에는 B그룹 개미를 넣음
T초가 지난 개미 그룹 배열을 만들고
A배열에 있는 개미들은
T가 i보다 큰 경우(이때만 움직여서)
 현재 위치 + (T - (A배열 길이 - 현재위치)) 위치에 넣고
B배열에 있는 개미들은
T가 i보다 큰 경우(이떄만 움직여서)
A배열 크기 + 현재위치  - (t - 현재위치) 위치에 넣는다

+ 개미가 갈수 있는 최대 위치 조건추가

*/
int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    string ns1, ns2;

    cin >> ns1;
    cin >> ns2;

    string ns = "";
    //개미 그룹 두개를 받고 A그룹은 뒤집어서 ns에 넣음
    for (int i = ns1.length() -1; i >= 0; i--) {
        ns += ns1.at(i);
    }

    ns1 = ns;

    ns += ns2;
    int t;
    cin >> t;
    int tmp;
    //첫 그룹 개미들을 반복 돌면서 제자리를 찾아줌 t가 i보다 클때만 움직여서 작으면 그냥 제자리 
    for (int i = 0; i != ns1.length(); i++) {
        if (t >= ns1.length() - i) {

            tmp = i + (t - (ns1.length() - 1 - i));

            if (tmp > ns2.length() + i) {
                ns[ns2.length() + i] = ns1.at(i);
            }
            else {
              //  ns[i + (t - (ns1.length() - 1 - i))] = ns1.at(i);

                cout << ns1.at(i) << " " << tmp << "\n";
                ns[tmp] = ns1.at(i);

            }

        }
        else {
            ns[i] = ns1.at(i);

        }
    }
    //두번쨰 그룹 개미들을 반복 돌면서 제자리를 찾아줌 t가 i보다 클때만 움직여서 작으면 그냥 제자리 

    for (int i = 0; i != ns2.length(); i++) {

        if (t > i) {

            tmp = ns1.length() + i - (t - i);
            if (tmp < i) {
                ns[i] = ns2.at(i);
            }
            else {
                //ns[ns1.length() + i - (t - i)] = ns2.at(i);
                ns[tmp] = ns2.at(i);

            }


        }
        else {
            ns[ns1.length() + i] = ns2.at(i);
        }
    }


    cout << ns << "\n";
    
    return 0;
}

