#include <stdio.h>
#include <string.h>
#include <stdlib.h>



char string[5000000];

int main() {

	int len;
	//char* string;
	//char string[100] = { 0, };
	char tmp_string[7];

	//char string2[1000];

	int i = 0;
	int j = 0;
	int flag = 0;
	int char_flag = 1;
	long long sum = 0;





	scanf(" %d", &len);


	scanf("%s", string);




	for (i = 0; i < len; i++) {
		//����
		//printf("string[i] : %c\n", string[i]);
		if (string[i] >= 48 && string[i] <= 57) {
			//���� 6�ڸ� �̻��� ��� ����ѹ� ������ �Ǵ� 
			//printf("num\n");
			if (flag > 5) {
				tmp_string[j] = '\0';
				sum += atoi(tmp_string);
				j = 0;
				flag = 0;
				char_flag = 0;
			}
			else if (char_flag) {
				tmp_string[j++] = string[i];
				flag++;
				//printf("flag : %d j : %d\n", flag, j);

			}


		}
		//����
		else {
			//printf("char\n");
			//������ ���ڿ����� sum�� �߰� 
			if (flag >= 1) {
				tmp_string[j] = '\0';
				sum += atoi(tmp_string);
				j = 0;
				flag = 0;

			}
			char_flag = 1;


		}

	}
	if (flag >= 1 && flag <= 6) {
		tmp_string[j] = '\0';
		sum += atoi(tmp_string);

	}
	printf("%lld\n", sum);
	//free(string);

	return 0;
}