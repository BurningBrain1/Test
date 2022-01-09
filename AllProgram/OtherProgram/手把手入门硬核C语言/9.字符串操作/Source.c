#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define INDEX_NONE -1

void remove_char_end(char *str, char sub_str)
{
	int len = strlen(str);

	for (int i = len; i >= 0; i--)
	{
		if (str[i] == sub_str)
		{
			strcpy(&str[i], &str[i + 1]);
		}
	}
}

void remove_char_start(char *str, char sub_str)
{
	int len = strlen(str) + 1;

	//从头开始检查 然后删除对象
	for (int i = 0; i < len; i++)
	{
		if (str[i] == sub_str)
		{
			do
			{
				str[i] = str[i + 1];
				i++;
			} while (str[i + 1] != '\0');
			str[i] = '\0';

			break;
		}
	}
}

// "wearwetryy wrwq asdgddawtdgh"
// "as"
int find_string(char *str, char const* sub_str)
{
	int len = strlen(sub_str);
	int index = INDEX_NONE;
	for (int i = 0; str[i] != '\0';i++)
	{
		if (sub_str[0] == str[i])
		{
			int tmp_index = i;
			int l = 1;//第一个是成功
			while (sub_str[l] == str[i + l])
			{
				l++;
			}

			if (len == l)
			{
				index = tmp_index;
				break;
			}
		}
	}

	return index;
}

void remove_string_start(char *str,char const* sub_str)
{
	int index = find_string(str, sub_str);
	if (index != INDEX_NONE)
	{
		strcpy(&str[index], &str[index + strlen(sub_str)]);
	}
}

void replace_char_inline(char *str,const char sub_char_a, const char sub_char_b)
{
	int index = find_string(str,&sub_char_a);
	if (index != INDEX_NONE)
	{
		str[index] = sub_char_b;
		replace_char_inline(str, sub_char_a, sub_char_b);
	}
}

#include <stdarg.h>
//"asdadasd %s asd asd %d 飞洒发的 %s"
int get_printf(char *buf ,char *format,...)
{
	va_list param_list;
	va_start(param_list, format);
	char param_char = *format++;

	for (int i = 0; param_char != '\0';i++)
	{
		if (param_char != '\%' && *(format-1) != '\%')
		{
			buf[i] = param_char;
		}
		else
		{
			param_char = *format++;
			switch (param_char)
			{
				case 'c':
				case 'C':
				{
					buf[i] = va_arg(param_list,char);
					break;
				}
				case 's':
				case 'S':
				{
					char *p = va_arg(param_list,char*);
					int len = strlen(p);
					for (int j = 0; j < len;)
					{
						buf[i++] = p[j++];
					}
					i--;

					break;
				}
				case 'd':
				case 'D':
				case 'i':
				case 'I':
				{
					int new_int = va_arg(param_list,int);
					char buf_int[8] = { 0 };
					char *p = itoa(new_int, buf_int, 10);
					int len = strlen(p);
					for (int j = 0 ; j < len;)
					{
						buf[i++] = p[j++];
					}
					i--;
					break;
				}
			}
		}

		param_char = *format++;
	}

	return strlen(buf) + 1;
}

void main()
{
	//char o[] = "Hello World~~~";
	//char O1 = 'l';
	//char O2[] = "1";//'1' + '\0'
	//char O3[] = { '1','\0' };

	////index 0   1   2   3   4   5 
	////v     H   e   l   l   d   \0
	////addr 0x1 0x2 0x3 0x4 0x5 0x6

	//printf("%s \r\n", o);
	//for (int i = 0 ;i < 12; i++)
	//{
	//	printf("%c \r\n", o[i]);
	//}

	//char Data[] = "Hello World~~~";
	//char Data1[15] = {0};
	////Data1 = Data;

	//printf("%s \r\n", Data);
	////for (int i = 0; i < 14; i++)
	////{
	////	Data1[i] = Data[i];
	////}
	////Data1[14] = '\0';

	//strcpy(Data1,Data);

	//printf("%s \r\n", Data1);
	
	//char Data[128] = "Hello";
	//char Data1[] = "World";
	//for (int i = 0; i < 5; i++)
	//{
	//	DataTmp[i] = Data[i];
	//}
	//DataTmp[5] = ' ';
	//for (int i = 0; i < 5; i++)
	//{
	//	DataTmp[i + 6] = Data1[i];
	//}
//	DataTmp[12] = '\0';

	//strcat(Data, Data1);
	//printf("%s \r\n", Data);

	//char Data[] = "Hello";//  '\0'

	//int len = 0;
	//while (Data[len] != '\0')
	//{
	//	len++;
	//}
	//printf("%d \r\n", len);

	//printf("%d \r\n", strlen(Data));/*size_t*/
	//printf("%d \r\n", sizeof(Data));

	//char Data[] = "Hello";//  '\0'
	//char Data1[] = "Hello";

	//int bEqual = strcmp(Data, Data1);
	// 如果相等 0
	// 如果Data > Data1 >0
	// 如果Data < Data1 <0
	// 如果Data  Data1 长度相等 比较的是当前字符的ASCII
	//if (strlen(Data) > strlen(Data1))
	//{
	//	bEqual = 1;
	//}
	//else if (strlen(Data) < strlen(Data1))
	//{
	//	bEqual = -1;
	//}
	//else
	//{
	//	for (int i = 0; i < strlen(Data); i++)
	//	{
	//		if (Data[i] != Data1[i])
	//		{
	//			bEqual = 1;
	//			break;
	//		}
	//	}
	//}
	//printf("%d \r\n", bEqual);

//	char Data[] = "Hello";// 
	//"ll"
	//int Index = -1;
	//for (int i = 0; i < strlen(Data); i++)
	//{
	//	if (Data[i] == 'e')
	//	{
	//		Index = i;
	//		break;
	//	}
	//}

//	printf("%c \r\n", Data[Index]);
	//char * Index = strchr(Data, 'e');
	//printf("%c \r\n", *Index);
	//char Data[] = "Hello";
	//const char *V = strstr(Data, "e");
	//printf("%c \r\n", *V);

	//char aa[] = "123";
	//long a = atol(aa);
	//printf("%ld \r\n", a);
	//int number = 0;

	//char tmep_char;
	//char array_char[128] = { 0 };
	//while ((tmep_char = getchar()) != '\n' )
	//{
	//	array_char[number++] = tmep_char;
	//	array_char[number] = '\0';
	//}

	//number = 0;
	//char array_char1[128] = {0};
	//while ((tmep_char = getchar()) != '\n')
	//{
	//	array_char1[number++] = tmep_char;
	//	array_char1[number] = '\0';
	//}

	//char *p = NULL;
	//if (p = strstr(array_char1, array_char))
	//{
	//	printf("%s", p);
	//}

	//int char_len = strlen(array_char);//jo
	//int char_len1 = strlen(array_char1);//wijofjasd
	//char *p = array_char1;
	//char *q = array_char;

	//int flag = 0;
	//for (;*(p + strlen(array_char) + 1);p++)
	//{	
	//	for (q = array_char; *p == *q && *q; p++,q++);

	//	if(!*q)
	//	{
	//		flag = 1;
	//		break;
	//	}
	//}

	//if (flag)
	//{
	//	printf("找到了");
	//}
	//else
	//{
	//	printf("不存在");
	//}

	//for (int i = 0;(char_len1 - i) >= char_len;i++)
	//{
	//	if (array_char1[i] == array_char[0])//j
	//	{
	//		int j = 0;
	//		for (;j < char_len;j++)
	//		{
	//			if (array_char1[i + j] != array_char[j])
	//			{
	//				break;
	//			}
	//		}

	//		if (j == char_len)
	//		{
	//			printf("%d \n", i + 1);
	//			break;
	//		}
	//	}
	//}

	//sizeof()//只能获取数组  指针的 只能获取指针大小
	//strlen() + 1; // '\0'
	
	//char p[] = "asdasdwqae asd asd asd qaw";
	//printf("sizeof(p) = %d \r\n", sizeof(p));//'\0'
	//printf("strlen(p) = %d \r\n", strlen(p));
	
	//char str[] = "	小明 ： 你好 我叫什么什么... \n  \
	//				小红 ： 很高兴认识你 \n  \
	//				小黑 ： 你好 \n";
	//printf("%s \r\n", str);
	//
	//	char *p = strtok(str, "\n");
	//	while (p)
	//	{
	//		printf("%s \r\n", p);
	//		p = strtok(NULL, "\n");
	//	}
	//	/*
	//	小明 ： 你好 我叫什么什么... \n
	//	小红 ：很高兴认识你 \n
	//	小黑 ： 你好 \n
	//	*/

	//char array_c[] = "asdasdasd asd asd a % asd asd a";

	//int len = strlen(array_c) + 1;
	//printf("%s \r\n", array_c);
	////从头开始检查 然后删除对象
	//for (int i = 0; i < len; i++)
	//{
	//	if (array_c[i] == '\%')
	//	{
	//		do
	//		{
	//			array_c[i] = array_c[i + 1];
	//			i++;
	//		} while (array_c[i + 1] != '\0');
	//		array_c[i] = '\0';

	//		break;
	//	}
	//}

	//从尾部开始删除
	/*char array_c[] = "asdasdasd asd asd a % asd asd a";

	int len = strlen(array_c);
	printf("%s \r\n", array_c);
	for (int i = len;i >=0 ;i--)
	{
		if (array_c[i] == '\%')
		{
			strcpy(&array_c[i],&array_c[ i + 1]);
		}
	}


	printf("%s \r\n", array_c);*/

	//char str[] = "asdwj;ld,sdfaw[d2-1532-5e yyyyyyyya  swe s asd ert";
	//char sub_str[] = "5e";
	//printf("%s \r\n", str);
	//remove_string_start(str, sub_str);

	//printf("%s \r\n", str);
	//char str[] = "ABCD as dasd asd";
	//char str_sub[] = "ABD";

	//int len = strspn(str, str_sub);

	/*char str[] = "asdawrasfa asd asd wqqwrg";
	printf("%s \r\n", str);
	replace_char_inline(str, 'a', 'T');
	printf("%s \r\n", str);*/

	char buf[256] = { 0 };
	int size = get_printf(buf,"Hello %s Hei %c ooo %d osad %i ppppp","XXXX",'T',454,231);
	int comp_size = strlen(buf) + 1;

	printf("%s \n size = %i;\n comp_size = %i \n", buf, size, comp_size);
	system("pause");
}
