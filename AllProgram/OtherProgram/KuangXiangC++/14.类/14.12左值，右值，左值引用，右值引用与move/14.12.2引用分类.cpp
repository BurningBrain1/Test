#include<iostream>
using namespace std;

int main2()
{
    //1 ��ֵ����
    int value = 10;
    int& refval = value;//value�ı�����refval &�����ʶ���� ��ʶ��һ������
    refval = 13;//�ȼ���value=13;

    //2 const����(��������) Ҳ����ֵ���� ������Щ��ϣ���ı�ֵ�Ķ���
    const int& refval2 = value;
    //refval2 = 18;   //���� ��������ʾ�����ʽ�����ǿ��޸ĵ���ֵ

    //3 ��ֵ����
    int&& refrightvalue = 3;//�󶨵�һ������
    refrightvalue = 5;//�������޸�ֵ
    return 0;
}