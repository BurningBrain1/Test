#include <iostream>

int main()
{
    int i = 0;
    ++i;//�ȼ�1����
    --i;//�ȼ�1����
    i++;//��ʹ���ټ�1
    i--;//��ʹ�ú��1

    i = 3;
    printf("i=%d\n", ++i);//i=4 �ȼӺ���

    i = 3;
    printf("i=%d\n", i++);//i=3 �ȼӺ���

    -i++;//-(i++)
    int j;
    i++ + j;//(i++)+j

    std::cout << "Hello World!\n";
}