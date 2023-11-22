#include <iostream>
#include <map>
using namespace std;



int main()
{
    int n, m;

    //맵 변수 선언
    map<int, int> sangcard;



    int tmp = 0;
    cin >> n;
    // 카드 개수만큼 정수를 입력받아서 맵에 넣는다 
    for (int i = 0; i != n; i++) {
        cin >> tmp;
        sangcard.insert({ tmp , 1 });
    }

    cin >> m;
    int* mcard = new int[m]{0, };
    //m개를 입력받아서 m개의 정수를 입력받은 다음에 그 정수가 맵에 있으면 mcard i번째 값을 1로 만듬 
    for (int i = 0; i != m; i++) {
        cin >> tmp;
        if (sangcard.find(tmp) != sangcard.end()) {
            mcard[i] = 1;
        }
    }

    //값 출력 
    for (int i = 0; i != m; i++) {
        cout << mcard[i] << " ";
    }



}
