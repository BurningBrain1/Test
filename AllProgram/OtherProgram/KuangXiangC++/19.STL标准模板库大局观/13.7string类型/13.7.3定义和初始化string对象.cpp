#include<iostream>
#include<string>

using namespace std;

int main1()
{
    string s1; //Ĭ�ϳ�ʼ�� ������ַ���
    string s2 = "I Love China";//���ַ������Ƶ�s2�����һ���ڴ���
    string s3("I Love China");
    string s4 = s2; //��s2�����ݸ��Ƶ���s4��������ڴ���

    int num = 6;
    string s5(num, 'a');//��s5��ʼ��Ϊ����num���ַ�'a'��ɵ��ַ���
    return 0;
}