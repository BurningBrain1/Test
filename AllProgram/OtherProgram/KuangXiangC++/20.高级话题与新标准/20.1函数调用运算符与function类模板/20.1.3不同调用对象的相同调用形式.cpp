#pragma once

#include <map>
#include <string>
#include <iostream>
using namespace std;

int echovalue3(int value)
{
    cout << value << endl;
    return value;
}
class biggerthanzero3
{
public:
    //���غ������������
    int operator()(int value)const
    {
        if (value < 0)return 0;
        return value;
    }
};
int main3()
{
    map<string, int(*)(int)> myoper;//�����ַ��� ֵ�Ǻ���ָ��
    myoper.insert({"ev",echovalue3});//��insert���������������Ӽ�ֵ��
    
    biggerthanzero3 obj;
    //myoper.insert({"bt",biggerthanzero});//���� ������ʹ��������
    //myoper.insert({"bt",obj1});//���� ����objû�б�ϵͳ���ɺ���ָ��

    return 0;
}



