#pragma once
#include <iostream>
#include <functional>
#include <map>
using namespace std;

int echovalue4(int value)
{
    cout << value << endl;
    return value;
}
class biggerthanzero4
{
public:
    //���غ������������
    int operator()(int value)const
    {
        if (value < 0)return 0;
        return value;
    }
};
int main4()
{
    biggerthanzero4 obj;   //���к�������������Ķ���
    function<int(int)> f1 = echovalue4;//����ָ��
    function<int(int)> f2 = obj;//����������غ������������
    function<int(int)> f3 = biggerthanzero4();//��������������ʱ����

    f1(5);//5
    cout << f2(3) << endl;//3
    cout << f3(-5) << endl;//0

    map<string, function<int(int)>> myoper;

    biggerthanzero4 obj1;
    map<string, function<int(int)>> myoper1 =
    {
        {"ev",echovalue4},
        {"bt",obj1},
        {"bt2",biggerthanzero4()}
    };

    myoper1["ev"](12);//"ev"�Ǽ�,��ômyoper["ev"]����ֵ 12
    cout << myoper1["bt"](3) <<endl;//3
    cout << myoper1["bt2"](-5) << endl;//0

    //�������echovalue�ĺ������� ��������
    int(*fp)(int) = echovalue4;//����һ������ָ�� ������������� ��Ϊ����ָ�����ж�Ӧ�Ĳ������ͺͷ�������
    function<int(int)>f4 = fp;//ֱ������ȥ����ָ������Ǻ�����


    return 0;
}
