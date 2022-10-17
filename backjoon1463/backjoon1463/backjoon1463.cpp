#include <iostream>
#include <algorithm>
#include <malloc.h>

void oneCount(int array[], int x) {
    

    // 2부터 원하는 값까지 최소 횟수를 구함
    for (int i = 2; i <= x; i++) {
        array[i] = array[i - 1] + 1;
        if (i % 2 == 0) {
            array[i] = std::min(array[i], array[i / 2] + 1);
        }


        if (i % 3 == 0) {
            array[i] = std::min(array[i], array[i / 3] + 1);
        }

    }
}


int main()
{
    int x = 0;
    //숫자를 입력받음
    std::cin >> x;
    int *array = new int[x + 1] { 0, };

  
    //1로 만드는 횟수 구하는 함수 실행
    oneCount(array , x);
    // 횟수 출력 
    std::cout << array[x] << std::endl;




}


