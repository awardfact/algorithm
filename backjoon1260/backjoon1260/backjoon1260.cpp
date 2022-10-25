
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
n m v값들을 받아옴
m개의 노드를 받아서 node배열에 넣음 넣을 때 양쪽을 다 넣어줘야함
문제에는 안써져있는데 작은 순부터 돌아야 되는거라 n개의 노드를 반복 돌면서 정렬
DFS는 함수에 들어오면 해당 노드를 방문체크에 추가해주고 해당 노드 반복 돌면서 방문 안한 노드가 있으면 그 노드를 재귀함수
하는 식으로 함수 생성
너비우선 탐색은 큐를 만들고 처음 노드를 큐에 넣고 큐가 빌때까지 큐에 있는 노드 pop 후 그 노드 방문 노드에 추가
해당 노드 반복돌아서 방문안한 노드가 있으면 그 노드를 큐에 넣는 함수를 생성

*/

void DFS(vector<vector<int>> node, int v , int count , int* visit , int* order) {
	


	if (*(visit + v) == 0) {
		cout << v << " ";
		count++;
		*(visit + v) = count;
		*(order + count) = v;
	}

	//if (*(visit + v) == 0) {
	//	count++;
	//	*(visit + v) = count;
	//	*(sort + count) = v;
	//}
	for (int i = 0; i != node[v].size(); i++) {
		if (*(visit + node[v][i]) == 0) {
			DFS(node, node[v][i], count, visit, order);
		}

	}



}

void BFS(vector<vector<int>> node, int v, int count, int* visit, int* order) {

	queue<int> que;


	que.push(v);
	int tmp = 0;
	while (!que.empty()) {


		tmp = que.front();
		que.pop();
		if (*(visit + tmp) == 0) {
			cout << tmp << " ";
			count++;
			*(visit + tmp) = count;
			*(order + count) = tmp;
		}
		for (int i = 0; i != node[tmp].size(); i++) {

			if (*(visit + node[tmp][i]) == 0) {
				que.push(node[tmp][i]);
			}
		}



	}
	//if (*(visit + v) == 0) {
	////	cout << v << " ";
	//	count++;
	//	*(visit + v) = count;
	//	*(order + count) = v;
	//}



	//while (!que.empty()) {
	//	BFS(node, que.front(), count, visit, order);
	//	que.pop();
	//}
	//
}

int main()
{
	int n, m, v;

	cin >> n >> m >> v;
	vector<vector<int>> node(n + 1);

	int* visit = new int[n + 1]{0,};
	int* order = new int[n + 1] {0, };
	int* visit2 = new int[n + 1] {0, };
	int* order2 = new int[n + 1] {0, };
	int num1, num2;

	for (int i = 0; i != m; i++) {
		cin >> num1 >> num2;
		node[num1].push_back(num2);
		node[num2].push_back(num1);
	}

	for (int i = 1; i <= n; i++) {
		sort(node[i].begin(), node[i].end());
	}

	int count = 0;
	DFS(node, v, count, visit , order);
	cout << "\n";
	BFS(node, v, count, visit2, order2);




	return 0;
}

