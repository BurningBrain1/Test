#include<vector>
#include<iostream>
using namespace std;

int main()
{
    //(1)(2)(3)*iter���ص�����iter��ָ���Ԫ�ص����� ָ��end�ĵ����� ������++
    vector<int>iv = {100,200,300};//����һ������
    vector<int>::iterator iter;
    for (iter=iv.begin();iter!=iv.end();++iter)
    {
        cout << *iter << endl;
    }

    //(4)iter1==iter2��iter1��=iter2 �ж������������Ƿ����
    //(5)�ṹ��Ա������
    struct student
    {
        int num;
    };

    vector<student> sv;
    student mystu;
    mystu.num = 100;
    sv.push_back(mystu);//�Ѷ���mystu���Ƶ���sv������
               //(�Ǹ��� ��ʱmystu�������е�studentû��ֱ�ӹ�ϵ)
    mystu.num = 200;//���ﲻ��������е�Ԫ�ز���Ӱ�� ��Ϊ�Ǹ��ƹ�ϵ
    vector<student>::iterator iter1;
    iter1= sv.begin();//ָ���һ��Ԫ��
    cout <<(*iter1).num << endl;
    cout <<iter1->num << endl;//����ȡֵ��ʽ 100
    return 0;
}