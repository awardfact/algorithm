﻿
#include <iostream>

using namespace std;
/*
한 변의 길이가 1인 정사각형을 겹치지 않게 빈틈없이 계속 붙여 나간다면 가장 아랫부분의
정사각형이 n개가 되었을 때 내부 정사각형의 둘레를 구하시오


맨 아랫줄 밑 둘레 = n
오른쪽 왼쪽 둘레 = n *2
계단형식 왼쪽 오른쪽 + 뚜껑 = n

n개일때 둘레는 n*4


*/
int main()
{
    long n;

    cin >> n;

    cout << n* 4<< "\n";


    return 0;
}

