#include <stdio.h>
#include <stdlib.h>

void һ��malloc��free()
{
	char name[128];
	strcpy(name, "Tom");
	//malloc����void*ָ�� GNU��Ϊchar*��void*��һ����
	char* pName = malloc(128*sizeof(char));
	if (pName=NULL)//�жϷ����Ƿ�ɹ�  ���ɹ�˵���ڴ���ܲ�����
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
	//FTest *pName = (FTest*) calloc(10,sizeof(FTest));//�����ڴ�й©
	//
	//pName = (FTest*) realloc(pName, 10 + 2 * sizeof(FTest));
	//pName[14].x = 10;
	//printf("%d \n\r",pName[14].x);//
	//free(pName);



	typedef unsigned char uint8;

	//F 
	//char src[20] = "���~~~~";
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