#include <stdio.h>


int main() {

	int n, m;
	int i, j;
	char a[10][10] = { 0, };
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++) {
		getchar();
		for (j = 0; j < m; j++) {

			a[i][j] = getchar();
			
			if(a[i][j] == '1'){
				a[i][j] = 1;
			}
			else {
				a[i][j] = 0;
			}

		}

	}


	for (i = 0; i < n; i++) {
		for (j = m -1; j >= 0; j--) {
			printf("%d", a[i][j]);
		}
		printf("\n");
	}

	


	return 0;
}