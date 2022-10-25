
#include <iostream>
using namespace std;


void top(int bechu[50][50], int jilungi[50][50], int M , int N, int j, int k ) {

	int m = j;
	int n = k;

	while (m > 0) {
		m--;
		if (bechu[m][n] == 1 && jilungi[m][n] == 0) {
			jilungi[m][n] = 1;
			top(bechu, jilungi, M, N, m, n);
		}
		else {
			break;
		}
	}
	
	m = j;
	n = k;

	while (m < M - 1) {
		m++;
		if (bechu[m][n] == 1 && jilungi[m][n] == 0) {
			jilungi[m][n] = 1;
			top(bechu, jilungi,M, N,  m, n);

		}
		else {
			break;
		}
	}
	m = j;
	n = k;

	while (n > 0) {
		n--;
		if (bechu[m][n] == 1 && jilungi[m][n] == 0) {
			jilungi[m][n] = 1;
			top(bechu, jilungi,M, N,  m, n);

		}
		else {
			break;
		}
	}


	m = j;
	n = k;

	while (n < N - 1) {
		n++;
		if (bechu[m][n] == 1 && jilungi[m][n] == 0) {
			jilungi[m][n] = 1;
			top(bechu, jilungi,M , N, m, n);

		}
		else {
			break;
		}
	}






}

/*
M ,k만큼 반복을 돌면서
[i][j]위치의 배추가 1인지 0인지 구함
배추가 있는 지역인 경우
지렁이 체크한 곳인지 체크해서 체크한 곳이면 넘어가고 아니면 지렁이 + 한다음에
상하좌우 방향으로 0이 나올떄까지 지렁이를 체크한 곳으로 만듬
반복 빠져나오면 지렁이 개수 출력

*/
int main()
{
	int T,M,N,K;
	int bechu[50][50] = { 0, };
	int jilungi[50][50] = { 0, };
	int count;
	int x, y;
	int tmpM, tmpN;
	cin >> T;


	for (int i = 0; i != T; i++) {
		cin >> M >> N >> K;

		count = 0;
		for (int j = 0; j != M; j++) {
			for (int k = 0; k != N; k++) {
				bechu[j][k] = 0;
				jilungi[j][k] = 0;
			}
		}

		for (int j = 0; j != K; j++) {
			cin >> x >> y;
			bechu[x][y] = 1;
		}

		for (int j = 0; j != M; j++) {
			for (int k = 0; k != N; k++) {
				if (bechu[j][k] == 1 && jilungi[j][k] == 0) {
					count++;
					jilungi[j][k] = 1;

					top(bechu, jilungi, M, N, j,k);
					//cout << j << " " << k << "\n";



					//while (tmpM < M -1) {
					//	tmpM++;
					//	if (bechu[tmpM][k] == 1 && jilungi[tmpM][k] == 0)  {
					//		jilungi[tmpM][k] = 1;
					//	}
					//	else {
					//		break;
					//	}
					//}

					//tmpN = k;
					//while (tmpN > 0) {
					//	tmpN--;
					//	if (bechu[j][tmpN] == 1 && jilungi[j][tmpN] == 0) {
					//		jilungi[j][tmpN] = 1;
					//	}
					//	else {
					//		break;
					//	}
					//}



					//tmpN = k;
					//while (tmpN <  N -1) {
					//	tmpN++;
					//	if (bechu[j][tmpN] == 1 && jilungi[j][tmpN] == 0)  {
					//		jilungi[j][tmpN] = 1;
					//	}
					//	else {
					//		break;
					//	}
					//}



				}
			}
		}

		cout << count << "\n";
	}

	return 0;
}

