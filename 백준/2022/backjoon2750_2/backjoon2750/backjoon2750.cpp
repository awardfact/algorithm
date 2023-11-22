

#include <iostream>

void sortt(int array[], int b ,int c) {
    std::cout << b  << " b " << c << std::endl;
    // 오른쪽이 왼쪽보다 큰 경우만 함수 실행 
    if (b < c) {
        // 임시 변수 
        int tmp = 0;

        // 비교하는 값
        int p = array[b];

        //비교하는 왼쪽 숫자 시작점 
        int low = b;

        // 비교하는 오른쪽 끝 시작점
        int high = c + 1;

        std::cout << p  << "  " << high << " a" << low << std::endl;
        do {





            //비교값보다 큰게 나올떄까지 오른쪽으로 가면서 값 구함
            do {
                low++;
            } while (array[low] < p && low <= c);

            //비교값보다 작은게 나올떄까지 왼쪽으로 가면서 값 구함
            do {
                high--;
            } while (array[high] > p && high >= b);

            std::cout << high << " " << low << std::endl;
            // 값들이 없어서 교차하지 왼쪽의 비교값보다 큰 값이랑 오른쪽의 비교값보다 작은 값을 바꿔줌 
            if (high > low) {
                tmp = array[low];
                array[low] = array[high];
                array[high] = tmp;
            }

            //왼쪽에는 비교값보다 큰 값이 없을때까지 반복 
        }while (low < high);

        //반복 끝난거는 high값이 low값보다 작아진거라 high왼쪽에는 비교값보다 큰게 없어서 위치를 바꿈 
        tmp = array[b];
        array[b] = array[high];
        array[high] = tmp;



        // 해당 함수를 왼쪽 오른쪽 나눠서 진행 
        sortt(array, b, high - 1);
        sortt(array, high + 1, c);


    }

}


int main()
{


    int n = 0;
    int i = 0;



    std::cin >> n;
    int *x = new int [n] { 0, };
    for (i = 0; i != n; i++) {
        std::cin >> x[i];
    }
    



 

    sortt(x, 0, n);


    for (int j = 0; j != n; j++) {
        std::cout << x[j] << std::endl;
    }

 

}

