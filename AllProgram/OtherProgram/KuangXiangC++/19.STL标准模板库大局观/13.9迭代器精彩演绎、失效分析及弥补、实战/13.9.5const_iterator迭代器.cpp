#include<vector>
#include<iostream>
using namespace std;

int main()
{
   
    vector<int>iv = { 100,200,300 };//����һ������
    vector<int>::const_iterator iter;
    for (iter = iv.begin(); iter != iv.end(); ++iter)
    {
        //*iter = 4;//������
        cout << *iter << endl;//���� ����������Ҳ���������������ж�Ԫ��ֵ
    }

    //������constʱ �����ó���������
    const vector<int>iv1 = { 100,200,300 };//����һ������ ��const
    vector<int>::const_iterator iter1;
    for (iter = iv.begin(); iter != iv.end(); ++iter)//���������ĵ������᷵��const������
    {
        cout << *iter << endl;//���� ����������Ҳ���������������ж�Ԫ��ֵ
    }

    //cbegin��cend���������ǲ��ǳ������� ���صĶ��ǳ���������
    vector<int> iv4={100,200,300};
    for (auto iter2=iv4.cbegin();iter2!=iv4.cend();++iter)
    {
        //*iter = 58; ���� ���ܸ�������ֵ ˵��cbegin���ص��ǳ���������
    }
    return 0;
}