#include<iostream>
#include<vector>

using namespace std;

int main2()
{
    //1 ��vector�����ӳ�Ա
    vector<string>mystr;//����һ��string���͵Ŀ�vector����
    mystr.push_back("abcd");
    mystr.push_back("def");

    //2 ����Ԫ��������ͬ ���ж���Ԫ�ظ���
    vector<string>mystr2(mystr);
    vector <string>mystr3= mystr;

    //3 �ó�ʼ���б�������ֵ
    vector<string>def = { "aa","bb","cc"};

    //4 ����ָ��������Ԫ��
    vector<int>ijihe(15,-200);//����15��int����Ԫ�صļ��� ÿ��Ԫ�ض���-200
    vector<string>sjihe(5, "hello");//����5��hello
    vector<int>ijihe2(20);//20��Ԫ�� ÿ����Ϊ0
    vector<string>sjihe2(5);//5��Ԫ�� ÿ����Ϊ""

    //5  ���ֳ�ʼ��
    vector<int>i1(10);//Բ������ס�ĵ�������10��ʾԪ������ ÿ��Ԫ��ֵĬ��Ϊ0
    vector<int>i2{ 10 };//{}��ʾ����Ԫ�� ֵΪ10
    vector<string>snor{ "hello" };//һ��Ԫ������Ϊhello
    vector<string>s22{ 10 };//10��Ԫ�� ��Ϊ10������Ϊstring��������� ����ϵͳ����Ϊ������
    vector<string>s23{10,"hello"};//10��Ԫ�� ÿ��Ԫ�����ݶ���hello
    vector<int>i3(10,1);//������������ 10��Ԫ�� ÿ��Ԫ��ֵΪ1
    vector<int>i4{ 10,1 };//2��Ԫ�� 10��1 ��ͬ�ڳ�ʼ���б�
    vector<string>{"hello"};//ϵͳֱ�ӱ��������

    return 0;
}