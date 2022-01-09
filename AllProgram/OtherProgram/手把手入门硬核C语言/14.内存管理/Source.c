#include <stdio.h>
#include <stdlib.h>

void 一节malloc和free()
{
	char name[128];
	strcpy(name, "Tom");
	//malloc返回void*指针 GNU认为char*与void*是一样的
	char* pName = malloc(128*sizeof(char));
	if (pName=NULL)//判断分配是否成功  不成功说明内存可能不足了
	{
		fprintf(stderr, "Error");
		exit(-1);
	}
	else
	{
		strcpy(pName, "666");
	}
}

typedef struct 
{
	int x;
	int y;
}FTest;

void main()
{
	char name[128];
	strcpy(name, "Tom");

	///*void* **/	
	//FTest *pName = (FTest*) calloc(10,sizeof(FTest));//容易内存泄漏
	//
	//pName = (FTest*) realloc(pName, 10 + 2 * sizeof(FTest));
	//pName[14].x = 10;
	//printf("%d \n\r",pName[14].x);//
	//free(pName);



	typedef unsigned char uint8;

	//F 
	//char src[20] = "你好~~~~";
	//char dest[20] = {0};
	/*int i = 0;
	while (i>=20)
	{
		dest[i] = src[i];
		i++;
	}*/
//	memcpy(dest, src, sizeof(src));
	//memcpy(dest, src, 2);
	//printf("%s \r\n", dest);

	system("pause");
}