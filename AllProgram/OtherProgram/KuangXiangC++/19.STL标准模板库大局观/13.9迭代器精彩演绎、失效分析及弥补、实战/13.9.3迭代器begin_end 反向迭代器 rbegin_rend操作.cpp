#include<vector>
#include<iostream>
using namespace std;

int main()
{
    vector<int>iv = { 100,200,300 };//����һ������
    vector<int>::iterator iter;//��������� Ҳ������vector<int>��ͷ

    //(1)begin����һ������������ �������ɷ���һ��������
    iter = iv.begin();//�����������Ԫ�� begin���صĵ�����ָ����������еĵ�һ��Ԫ��
                      //�����൱��iter������Ԫ��iv[0]

    //(2)end����һ������������(�����ɷ���һ��������)
    iter=iv.end();//end���صĵ�����ָ��������һ��Ԫ�صĺ��� ��һ�������ڵ�Ԫ��

    //(3)�������Ϊ�� begin���صĵ�������end���صĵ�������ͬ
    vector<int>iv2;
    vector<int>::iterator iterbegin = iv2.begin();
    vector<int>::iterator iterend = iv2.end();
    if (iterbegin==iterend)
    {
        cout << "����Ϊ��" << endl;
    }

    //(4)��ͳ��ͨ������������������Ԫ�صķ���
    vector<int>::iterator iter1;
    for (iter1 = iv.begin(); iter1 != iv.end(); iter++)
    {
        cout << *iter << endl;//100 200 300
    }

    //2.���������
    //(1)rbegin����һ��������������� ָ�����������һ��Ԫ��
    //(2)rend����һ��������������� ֻ�������ĵ�һ��Ԫ��ǰһ��λ��
    vector<int>iv4 = { 100,200,300 };
    for (vector<int>::reverse_iterator riter=iv4.rbegin();riter!=iv.rend();riter++)
    {
        cout << *riter << endl;//300 200 100
    }

    return 0;
}