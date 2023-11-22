
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

/*
첫째 줄에 신호등 개수N과 도로 길이 L이 주어진다
다음 N개 줄에는 신호등의 정보 D R G 가 주어진다
D는 신호등 위치 R과 G는 빨간색 초록색이 지속되는 시간이다
신호등은 D가 증가하는 순서로 주어지며 같은 위치에는 신호등이 없다

신호등을 지나가면 다음 신호등이 있는 위치까지 m를 + 시간도 +
신호등이 있으면 현재 시간때 신호등의 상태를 계산

신호등 상태 계산
신호등 사이클 = 시간 %( R + G)   나머지가 0이면 빨간불이 막 시작했다는 거
나머지 - R했을 떄 0보다 크면 바로 통과 0보다 작으면 차이만큼 시간 플러스하고 지나감
*/

//신호등 구조체
struct road {
    int D;
    int R;
    int G;
};

//구조체 비교 함수 
bool compare(const road a, const road b) {
    return a.D < b.D;
}


int main()
{
    // 신호등 개수 N과 길이 L, 신호등 , 지금까지 거리 시간 등을 선언 
    int N, L = 0;
    vector<road> light;
    road tmp;

    cin >> N >> L;
    int time = 0;
    int current = 0;
    int wait = 0;
    int move = 0;

    // 입력받은걸 신호등 구조체에 넣음 
    for (int i = 0; i != N; i++) {
        cin >> tmp.D >> tmp.R >> tmp.G;
        light.push_back(tmp);
    }


    //거리 순으로 신호등 정렬 
    sort(light.begin(), light.end() ,compare);

    
    for (int i = 0; i != light.size(); i++) {
        // 현재 거리에서 신호등까지의 거리를 구해서 시간 +
        move = light[i].D - current;
        current +=  move;
        time += move;
        // 현제 시간에서 신호등 싸이클 나머지를 구함 
        wait = time % (light[i].R + light[i].G);
        
        // 나머지가 빨간불보다 크면 큰 만큼 더함
        if (wait < light[i].R) {
            time += light[i].R - wait;
        }


    }

    if (current < L) {
        time += L - current;
    }

    cout << time << "\n";

    return 0;
}
