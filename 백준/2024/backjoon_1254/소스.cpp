#include <stdio.h>
#include <string.h>

//�Ҹ���� üũ �Լ� 
int panrindropCheck(char* string) {

    int i;
    //�յ� �ٸ��� 0 ����
    for (i = 0; i < strlen(string); i++) {
        //printf("string[i] : %c  string[strlen] : %c\n",string[i], string[strlen(string) - i - 1]);
        if (string[i] != string[strlen(string) - i - 1]) {
            return 0;
        }

    }

    // printf("string : %s start : %d\n",string, start);
    return 1;

}


int main() {

    char s[101];
    int i = 0;
    int len = 0;
    scanf("%s", s);


    //���ڿ����� i���� ���� �Ҹ������ ��� ���ڿ� �ڿ� i -1���� 0���� ���ڿ��� �߰��ϸ� �Ҹ������ �ȴ�
    for (i = 0; i < strlen(s) - 1; i++) {

        if (panrindropCheck(s + i)) {
            i--;
            break;
        }

    }

    //printf("%d %d \n", strlen(s), i);

    //���ڿ� �߰� ��ġ ����
    len = strlen(s);
    //���ڿ� �ȿ� �Ҹ������ ������ ������ 2���� �ڸ����� �߰� 
    if (i == strlen(s) - 1) {
        i = len - 2;
    }

    //�Ҹ������ ���Ë����� i�� ���̸鼭 i���� ���ڿ��� ���� �߰� 
    while (!panrindropCheck(s)) {

        //printf("%s\n", s);
        len = strlen(s);

        s[len++] = s[i--];
        s[len] = 0;


    }


    printf("%ld\n", strlen(s));



    return 0;
}