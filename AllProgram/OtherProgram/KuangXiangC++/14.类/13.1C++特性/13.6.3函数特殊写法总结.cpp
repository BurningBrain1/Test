#include<iostream>
using namespace std;

//1 ������������Ϊvoid��ʾ�����������κ����� 
    //�����Ե���һ����������Ϊvoid�ĺ�����Ϊ��һ������void�����ķ���ֵ
void funca()
{
    //...
}
void funcb()
{
    return funca();
}

//2 ��������ָ��ͷ������õ����
int* myfunc()
{
    int tmpvalue = 9;//Ҫ���ȫ�ֱ���
    return &tmpvalue;//�﷨��û�� �����¾޴����� tmpvalueӦ��Ϊȫ�ֱ���
}
int& myfunc2() //��������
{
    int tmpvalue = 9;
    cout << &tmpvalue << endl;
    return tmpvalue;//������Ī˵��������
}

//3 �����βεĺ����������д������ �����β��б�ֱ�ӿ��Ÿ���
int myfunc3(void) { return 1; }

//4 ���һ������������ ��ô�����������ֻ������ û�ж���

//5 ����ֻ�ܶ���һ�� �������������

//6 ͨ���������β������к������ò����Ĵ���
struct student3 { int num; };
void fs(student3& stu)
{
    stu.num = 1000;
}

//7 ��������
//void fs1(const int i){}//���� const�ؼ����ڱȽ�ͬ������ʱ�ᱻ����
//void fs1(int i){}

void fs2(const int i){}//���� ��Ϊ�β����Ͳ�ͬ
void fs2(float i){}

void fs3(const int i){}//���� ��Ϊ�β�������ͬ
void fs3(const int i,const int j){}

int main3()
{
    //2 ��������ָ��ͷ������õ����
    int* p = myfunc();
    *p = 6;//���������Լ��ĵ�ַ�ϸ�ֵ
    
    int& k = myfunc2();
    //k��ַ�е����ݲ������� ǧ�򲻿��Զ�д
    cout << &k << endl;//tmpvalue�Ѿ����� �������ڴ�

    //��ȷд��
    int k1 = myfunc2();
    cout << &k1 << endl;//��ַ��ͬ

    //6 ͨ���������β������к������ò����Ĵ���
    student3 abc;
    abc.num = 100;
    fs(abc);
    cout << abc.num << endl;//1000
    return 0;
}