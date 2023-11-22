// backjoon10886.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;
/*
첫줄에 설문조사 할 사람 수가 주어지고
다음 N줄에는 각 줄마다 각 사람이 설문 조사에서 어떤 의견을 표명했는지 나타내는 정수가 주어진다
0은 귀엽지 않고 1은 귀엽다고 설문한거다

귀엽지 않다는 의견이 많으면 Junhee is not cute!을 반대면
Junhee is cute!출력


n변수 선언하고 n을 입력받는다
n개수만큼 입력을 받고
cute 변수와 ncute변수 선언
입력받아서 1이면 cute++ 아니면 ncute++
cute가 많으면 cute출력 아니면 not cute출력
*/
int main()
{

    int n;
    int cute = 0;
    int ncute = 0;
    int tmp;
    cin >> n;

    for (int i = 0; i != n; i++) {
        cin >> tmp;

        if (tmp) {
            cute++;
        }
        else {
            ncute++;
        }
    }

    if (cute > ncute) {

        cout << "Junhee is cute!" << "\n";
    }
    else {
        cout << "Junhee is not cute!" << "\n";

    }


    return 0;
}

