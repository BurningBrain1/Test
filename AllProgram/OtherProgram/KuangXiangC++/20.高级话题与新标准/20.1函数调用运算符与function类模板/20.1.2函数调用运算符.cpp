#pragma once
#include <iostream>
using namespace std;

class biggerthanzero2
{
public:
    //���غ������������
    int operator()(int value)const
    {
        if (value < 0)return 0;
        return value;
    }
    biggerthanzero2(int i)
    {
        cout << "biggerthanzero1�Ĺ��캯��ִ����" << endl;
    }
};

void func2(int i)
{
    cout << "���Ǻ���func2()" << i << endl;
    return;
}

int main2()
{
    func2(5);
    int i = 200;
    biggerthanzero2 obj(1);//�������岢��ʼ�� ���õ��ǹ��캯��
    int result = obj(i);//�ȼ���obj.operator()(i)
    cout << result << endl;//200
    return 0;
}

