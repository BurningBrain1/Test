#include<iostream>
using namespace std;

int main3()
{
    int a = 1;
    int& b{ a };//b��a ��Ȼ����
    //int& c;//������ ���ñ���Ҫ��ʼ��(��һ������) 
    //int& c = 1;//������ cҪ������ֵ�� ���ܰ󶨵���ֵ1��
    const int& c = 1;//���� const���ÿ��԰󶨵���ֵ�� ����const���ñȽ�����

    int tempvalue = 1; //���԰�tempvalue����һ����ʱ����
    const int& d = tempvalue;
    cout << d << endl;//1
    tempvalue = 10;
    cout << d << endl;//10
    //d = 20; ���� ���ܸ�ֵ
    return 0;
}