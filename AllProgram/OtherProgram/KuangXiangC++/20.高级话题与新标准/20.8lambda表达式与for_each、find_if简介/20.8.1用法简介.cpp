#include<iostream>
#include <functional>
using namespace std;



int main1()
{
    //(1) �������ͺ��õ������﷨ lambda���ʽ�ķ������ͱ������
    auto e = [](int a)->int
    {
        return a + 1;
    };
    cout << e(1) << endl;
    //Ҳ����д��auto f=[](int a){...}��Ϊ���������Ը���return�ƶ�����
    //Ҳ����auto f=[](int a=8)->int{...}����������Ĭ��ֵ
    
    //(2)û�в�����ʱ�� �����б����ʡ�� ����Ҳ����ʡ��
    auto f1 = []() {return 1; };
    auto f2 = [] {return 2; };
    cout << f1() << endl;//1
    cout << f2() << endl;//2

    //(3)�����б�[]�ͺ����岻��ʡ�� ����ʱ�̰���
    //(4)lambda���ʽ�ĵ��÷�������ͨ������ͬ ������()���ֺ������������
    //(5)lambda���ʽ���Բ������κ����� �������κ����;��Ƿ���void
    //(6)������ĩβ�ķֺŲ���ʡ��

    return 0;
}