// programmers132265.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


#include <string>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;


    int left = 0;
    int right = 0;

    // 맵을 두개 만들고 하나에 맵에는 토핑을 전부 넣은 상태에서 시작 key value는 토핑이름 토핑개수 
    map<int, int> tmp;
    map<int, int> tmp2;
    //   cout<< tmp[1] << endl;

   //cout<< tmp[1] << endl;
 //  tmp.insert({1, 1});

    // 하나의 맵에 토핑을 전부 넣음 
    for (int i = 0; i < topping.size(); i++) {

        if (tmp[topping[i]] == 0) {
            tmp[topping[i]] = 1;
        }
        else {
            tmp[topping[i]]++;
        }
    }

    /*  for(map<int,int>::iterator iter = tmp.begin(); iter != tmp.end(); iter++){
          cout << iter->first << " " << iter->second << endl;


      }
      */

      // cout << tmp.size() << endl;
       //cout << tmp2.size() << endl;

    // 토핑이 전부 추가된 맵에서는 토핑을 하나씩 빼고 개수를 계산하고 하나의 맵에는 토핑을 하나씩 추가하면서 개수 계산 
    for (int i = 0; i < topping.size() - 1; i++) {
        //    cout << tmp[topping[i]] << endl;
        if (tmp[topping[i]] > 1) {
            tmp[topping[i]] -= 1;
        }
        else {

            tmp.erase(topping[i]);
        }

        if (tmp2[topping[i]] == 0) {
            tmp2[topping[i]] = 1;
        }
        else {
            tmp2[topping[i]]++;
        }
        //cout << tmp.size() << " " << tmp2.size() << endl;
        if (tmp.size() == tmp2.size()) {
            answer++;
        }

    }

    /*  int left2[10001] = {0,};
      int right2[10001] = {0,};
      set<int> leftC;
      set<int> rightC;





      // 자르는 범위 설정
      for(int i = 0; i < topping.size() - 1; i++){
          left = 0;
          right = 0;
          // 왼쪽의 토핑 개수구하기
          for(int k = 0; k <= i; k++){
              if(left2[topping[k]] == 0){
                  left++;
                  left2[topping[k]]++;
              }

              //leftC.insert(topping[k]);
          }

          //오른쪽의 토핑 개수 구하기
          for(int j = i + 1; j < topping.size(); j++){
              if(right2[topping[j]] == 0){
                  right++;
                  right2[topping[j]]++;
              }
              //rightC.insert(topping[j]);
          }

          if(left == right){

              answer++;

          }

          for(int l = 0; l <= sizeof right2/sizeof right2[0]; l++){
              left2[l] = 0;
              right2[l] = 0;
          }

          //leftC.clear();
          //rightC.clear();
      }

      */
    return answer;

}



int main()
{
    std::cout << "Hello World!\n";
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
