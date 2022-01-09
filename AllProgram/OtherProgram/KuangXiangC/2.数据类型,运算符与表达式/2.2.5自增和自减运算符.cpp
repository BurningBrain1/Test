#include <iostream>

int main()
{
    int i = 0;
    ++i;//先加1再用
    --i;//先减1再用
    i++;//先使用再加1
    i--;//先使用后减1

    i = 3;
    printf("i=%d\n", ++i);//i=4 先加后用

    i = 3;
    printf("i=%d\n", i++);//i=3 先加后用

    -i++;//-(i++)
    int j;
    i++ + j;//(i++)+j

    std::cout << "Hello World!\n";
}