#include<iostream>
using namespace std;

class TC1
{
public:
    TC1()
    {
        m_a = 1;
    }
    void operator()(int tv)
    {
        cout << "TC1::operator()ִ���ˣ�tv=" << tv << endl;
    }
    void ptfunc(int tv)
    {
        cout << "TC1::ptfunc()ִ����,tv=" << tv << endl;
    }
    static int stcfunc(int tv)
    {
        cout << "TC1::stcfunc()��̬����ִ���ˣ�tv=" << tv << endl;
        return tv;
    }
    int m_a;
};

class TC11
{
public:
    using tfpoint = void(*)(int);
    static void myfunc(int tv)
    {
        cout << "TC11::myfunc()��̬��Ա����ִ���ˣ�tv=" << tv << endl;
    }
    operator tfpoint() { return myfunc; }//����ת�������/����ת������
};

void myfunc1(int i)
{
    cout << "myfunc1()����ִ����." << i << endl;
}

int main1()
{
    //1����ָ��
    void(*pmf)(int) = myfunc1;//���庯��ָ�벢����ֵ��myfunc��&myfuncһ��Ч��
    pmf(15);//һ���ɵ��ö���

    //2���к������ò������������
    TC1 tc;
    tc(20);//�ȼ���tc.operator()(20)

   //3��ת��Ϊ����ָ��������
    TC11 tc2;
    tc2(50);//�ȵ���tfpoint���ٵ���myfunc ���Ǹ��ɵ��ö���
            //�ȼ���tc2.operator TC11::tfpoint()(50)

    //4���Ա����ָ��
    TC1 tc3;
    //���Ա����ָ�����myfpointpt���岢������ֵ
    void(TC1:: * myfpointpt)(int) = &TC1::ptfunc;
    //Ҫ���ó�Ա���� �ͱ����õ�����tc3
    (tc3.*myfpointpt)(68);
    return 0;
}