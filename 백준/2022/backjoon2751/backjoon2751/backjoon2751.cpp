

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


void merge(int x[], int tmp[], int left, int mid, int right) {
   // int *y = new int[right] { 0, };
    int i = left;
    int j = mid + 1;
    int k = left;
    
    // 쪼개진 것들을 왼쪽 오른쪽으로 두고 왼쪽이 더 작으면 왼쪽데이터를 새로운 배열에 넣고 오른쪽이 작으면 오른쪽거를 넣고 넣을거는 오른쪽으로 한칸이동 왼쪽 오른쪽 한쪽이라도 mid, right보다 커지면 반복종료
    while (i <= mid && j <= right) {
        tmp[k++] = x[i] <= x[j] ? x[i++] : x[j++];
    }

    int a = 0;
    // i가 mid보다 크면 왼쪽값은 다 넣은거고 아니면 오른쪽 값은 다 넣은게 된다 그래서 남은값들을 배열에 넣어준다 왼쪽 오른쪽것들은 이미 정렬이 된 상태기 때문에 그냥 넣어도 된다
    if (i > mid) {
        for (a = j ; a <= right; a++) {
            tmp[k++] = x[a];
        }
    } 
    else {
        for (a = i; a <= mid; a++) {
            tmp[k++] = x[a];
        }
    }


    for (a = left; a <= right; a++) {
        x[a] = tmp[a];
    }


}

void merge2(int* arr, int* sortedArr, int begin, int middle, int end) {
    int sortedInd = begin;
    int i = begin;
    int j = middle + 1;


    while (i <= middle && j <= end) {
        if (arr[i] < arr[j]) sortedArr[sortedInd] = arr[i++];
        else  sortedArr[sortedInd] = arr[j++];

        sortedInd++;
    }

    //왼쪽이 오른쪽보다 모두 작은 경우
    if (i > middle) {
        while (j <= end) {
            sortedArr[sortedInd++] = arr[j++];
        }
    }
    //오른쪽이 왼쪽보다 모두 작은 경우
    if (j > end) {
        while (i <= middle) {
            sortedArr[sortedInd++] = arr[i++];
        }
    }

    for (int k = begin; k <= end; k++) arr[k] = sortedArr[k];

}



void mergeSort(int x[], int tmp[] , int left, int right) {

    // 병합정렬 반절로 다 쪼갠다음에 그것들을 다시 병합하면서 정렬 
    if (right > left) {
        int mid = (left + right) / 2;
        mergeSort(x, tmp, left, mid);
        mergeSort(x, tmp, mid + 1, right);
        merge2(x, tmp, left, mid, right);
    }





}
int main()
{
    int n = 0;
    
    //숫자를 입력받음
    cin >> n;
   int* x = new int[n] { 0, };
    int* tmp = new int [n] { 0, };
    int i = 0;
    for (i = 0; i != n; i++) {
        std::cin >> x[i];
    }

   // sort(x, x + n);

    mergeSort(x , tmp , 0 , n -1);
    for (i = 0; i != n; i++) {
        cout << x[i] << "\n";
    }
    
    //int y = 0;
    //vector<int> x;
    //for (int i = 0; i != n; i++) {
    //    cin >> y;
    //    x.push_back(y);
    //}

    //sort(x.begin(), x.end());

    //for (int i = 0; i < x.size(); i++) {
    //    cout << x[i] << endl;
    //}


}
