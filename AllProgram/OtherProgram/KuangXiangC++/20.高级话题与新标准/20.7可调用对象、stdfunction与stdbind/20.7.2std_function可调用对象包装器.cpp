#include<iostream>
#include <functional>
using namespace std;

class TC2
{
public:
    TC2()
    {
        m_a = 1;
    }
    void operator()(int tv)
    {
        cout << "TC2::operator()ִ���ˣ�tv=" << tv << endl;
    }
    void ptfunc(int tv)
    {
        cout << "TC2::ptfunc()ִ����,tv=" << tv << endl;
    }
    static int stcfunc(int tv)
    {
        cout << "TC2::stcfunc()��̬����ִ���ˣ�tv=" << tv << endl;
        return tv;
    }
    int m_a;
};
class TC21
{
public:
    using tfpoint = void(*)(int);
    static void myfunc(int tv)
    {
        cout << "TC21::myfunc()��̬��Ա����ִ���ˣ�tv=" << tv << endl;
    }
    operator tfpoint() { return myfunc; }//����ת�������/����ת������
};
class CB2
{
    function<void()> fcallback;
public:
    CB2(const function<void()> f) :fcallback(f)
    {
        
        cout << "ִ��CB2���캯��"<<endl;
        //function<void()> fcallback = f;
        int i;  
        i = 1;
    }
    void runcallback(void)
    {
        fcallback();
    }
};

class CT2
{
public:
    CT2()
    {
        cout << "CT2::CT2()ִ��" << endl;
    }
    CT2(const CT2&)//�������캯��
    {
        cout << "CT2::CT2(const CT&)ִ��" << endl;
    }
    ~CT2()
    {
        cout<<"CT2::~CT2()ִ��" << endl;
    }
    void operator()(void)
    {
        cout << "CT2::operator()ִ��" << endl;
    }
};
void myfunc2(int i)
{
    cout << "myfunc2()����ִ����." << i << endl;
}
void runfunc2(int x)
{
    cout << x << endl;
}
void mycallback2(int cs, const function<void(int)>& f)
{
    f(cs);
}

int main2()
{
    //1.����ͨ����
    function<void(int)> f1 = myfunc2;
    f1(100);
    cout << "-----------------------------------------" << endl;
    //2.����ľ�̬��Ա����
    function<int(int)>fs2 = TC2::stcfunc;//��һ����ľ�̬��Ա����
    fs2(110);//���þ�̬��Ա����
    cout << "-----------------------------------------" << endl;
    //3.�󶨷º���
    TC2 tc3;
    function<void(int)>f3 = tc3;//ʹ����δ��ʼ���ľֲ�������tc3��
    //��Ϊ��TC���г�Ա����û����ʼ������Ҫ����һ�����캯������ʼ����Ա����
    f3(120);//TC2::operatorִ���ˣ�tv=120

    TC21 tc4;  //ע������TC21��
    function<void(int)>f4 = tc4;
    f4(150);//TC21::myfunc()��̬��Ա����ִ���� tv=150
    cout << "-----------------------------------------" << endl;
    //4������ʾ1
    CT2 ct;  
    //(function<void()>)(ct);
    CB2 cb(ct);//CB2��Ҫ�ɵ��ö�����Ϊ����������
    //��Ϊ��operator()����ct����תΪfunction<void(void)>&����
    //���е���CT2�������캯��ִ�ж��

    //cb.runcallback();//CT2::operator()ִ��
    cout << "-----------------------------------------" << endl;
    //5������ʾ2
    for (int i = 0; i < 10; i++)
    {
        mycallback2(i, runfunc2);//0-9
    }
    return 0;
}

