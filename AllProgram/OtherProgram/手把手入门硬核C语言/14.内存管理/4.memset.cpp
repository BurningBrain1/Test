

#include<stdio.h>
#include <string>

//���ڳ�ʼ���ַ�������
int main()
{

	char str[] = "IIIIIIIIIIIIII";
	memset(str,'K',sizeof(str)-1);//�������\0
	memset(str, 0, strlen(str)); //���������\0
	printf("%s \r\n", str);

	return 0;
}