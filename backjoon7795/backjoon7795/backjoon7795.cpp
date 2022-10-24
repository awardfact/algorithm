

#include <iostream>
#include <algorithm>
using namespace std;



int A[20000] = { 0, };
int B[20000] = { 0, };

/*

T를 입력받은
T개수만큼 반복문을 돌림
N,M을 입력받음
N개 반복, M개 반복문을 돌려서 입력받음
숫자를 A,B배열에 넣음
B 내림차순으로 정렬하고
비교값보다 작은 위치 + 1 을 리턴하는 이진탐색함수 생성
A반복 돌리고 함수 호출해서 M - 리턴값 을 카운팅한다
*/

bool cmp(int a, int b) {
    return a > b;
}

int ijin(int left, int right, int cmp, int c[]) {
    int mid = (left + right) / 2;

    if (c[mid] < cmp) {
        if (mid == 0) {
            return 0;
        }
        else {

            return ijin(left, mid -1, cmp, c);

        }
    }
    else {

        if (mid == right) {
            return mid + 1;
        }
        else {
            return ijin(mid + 1, right, cmp, c);
        }
    }

}

int main()
{
    int T, N, M;

   // list<int> A;
    //list<int> B;

    int tmp;
    cin >> T;


    int mid, left, right;
    int count = 0;
    for (int i = 0; i != T; i++) {
        cin >> N >> M;
        count = 0;
        for (int j = 0; j < N; j++) {

            cin >> tmp;
            //A.push_back(tmp);
            A[j] = tmp;
        }
        for (int j = 0; j < M; j++) {
            cin >> tmp;
            //B.push_back(tmp);
            B[j] = tmp;

        }

        sort(B, B + M , cmp);
        mid = M / 2;
        left = 0;
        right = M -1;

        for (int j = 0; j != N; j++) {
            tmp = ijin(left, right, A[j], B);

            count += M - tmp;


        }

        cout << count << "\n";


    }
    return 0;
}
