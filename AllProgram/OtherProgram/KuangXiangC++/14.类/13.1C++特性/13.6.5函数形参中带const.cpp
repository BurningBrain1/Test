#include<iostream>
using namespace std;

struct student5 { int num; };
void fs5(student5& stu)//��ϣ���޸��βεĻ� дΪconst student &stu
{
    stu.num = 1010;
}

void fs51(const int i)
{
    //i = 100;//�������в��ܸ�������ֵ 
}
int main5()
{
    student5 abc;
    abc.num = 100;
    fs5(abc);
    cout << abc.num <<endl;//1010

    //const student5& def = abc;//���� ��Ϊdef������const& ������fs���ββ���const

    //����β���const class/type& var  ��Ī���Դ���ȥһ������  û��constֻ�ܴ�����
    return 0;
}