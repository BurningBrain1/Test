#include <iostream>
using namespace std;


struct student 
{
    int number;
    char name[100];
    void func() {};
};

int main()
{
    student student1;//����ṹ���� �������ʡ��struct ֱ���ýṹ�� ��C���Բ���ʡ��
    student1.number = 1001;
    strcpy_s(student1.name, sizeof(student1.name), "zhangsan");
    student1.func();//���ó�Ա����

    student* pstudent1 = &student1;
    pstudent1->number = 1005;
    cout << student1.number <<endl;//1005
    return 0;
}