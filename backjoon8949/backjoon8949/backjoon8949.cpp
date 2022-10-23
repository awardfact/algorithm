

#include <iostream>
#include <string>

using namespace std;
/*

숫자를 더할 때 오른쪽부터 왼쪽으로 가면서 하나씩 더하는데 10이상일 때 받아올림을 하지 않고
그냥 두 숫자의 합을 적어버려서

123 + 2495를 했을 때 25118 이런식으로 나오는 프로그램


반복문을 돌면서

% 10  / (10 /10)  i가 1일때
% 100 / (100 / 10) i 가 2일떄
이렇게 한 값을 더해야 하는데
%하는 숫자, /할 숫자, 나온 값을 곱할 숫자를 선언하고
반복 돌떄마다 이 숫자들을 10씩 곱함 그리고
더한값을 곱할 숫자만큼 곱해서 sum에 더하고
10보다 큰 경우에는 곱할 숫자를 다시 10 곱합


*/
int main()
{
    int A, B;
    cin >> A >> B;

    int per = 10;
    int slash = 1;
    int sumx = 1;
    long tmp,tmpA, tmpB , tmpSum;
    long sum = 0;
    string sum2;
    for (int i= 0; i <= 6; i++) {
        tmpA = (A % per) / slash;
        tmpB = (B % per) / slash;
        tmp = tmpA + tmpB;
        if (A / slash == 0 && B / slash == 0) {
            break;
        }
        if (tmp >= 10) {
            sum2 = to_string(tmp) + sum2;
            tmp *= sumx;
            sumx *= 10;

            //sum *= 100;
            sum += tmp;
        }
        else {
            sum2 = to_string(tmp) + sum2;
            tmp *= sumx;
            //sum *= 10;


            sum += tmp;

        }

        per *= 10;
        slash *= 10;
        sumx *= 10;


    }
    cout << sum2 << "\n";
    //cout << sum << "\n";
    return 0;
}
