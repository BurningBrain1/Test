

#include<stdio.h>
#include <string>

//用于初始化字符串数组
int main()
{

	char str[] = "IIIIIIIIIIIIII";
	memset(str,'K',sizeof(str)-1);//这个包含\0
	memset(str, 0, strlen(str)); //这个不包含\0
	printf("%s \r\n", str);

	return 0;
}