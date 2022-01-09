#include<iostream>
#include <functional>
using namespace std;


void myfunc3(int x, int y, int z)
{
    cout << "x=" << x << ",y=" << y << ",z=" << z << endl;
}

void myfunc31(int& x, int& y)
{
    y++;
    x++;
}

class CQ
{
public:
    CQ()
    {
        printf("CQ::CQ()���캯��ִ��,this=%p\n",this);
    }
	CQ(const CQ&)
	{
		printf("CQ::CQ(const CQ&)�������캯��ִ��,this=%p\n", this);
	}
	~CQ()
	{
		printf("CQ::~CQ()��������ִ��,this=%p\n", this);
	}
    void myfunpt(int x, int y)
    {
        cout << "x=" << x << ",y=" << y << endl;
        m_a = x;
    }
    int m_a = 0;//��Ա����
};
class CT3
{
public:
	CT3()
	{
		cout << "CT3::CT3()ִ��" << endl;
	}
	CT3(const CT3&)//�������캯��
	{
		cout << "CT3::CT3(const CT3&)ִ��" << endl;
	}
	~CT3()
	{
		cout << "CT2::~CT2()ִ��" << endl;
	}
	void operator()(void)
	{
		cout << "CT3::operator()ִ��" << endl;
	}
};
void myfunc(int i)
{
	cout << "myfunc3()����ִ����." << i << endl;
}
void runfunc3(int x)
{
	cout << x << endl;
}
void mycallback3(int cs, const function<void(int)>& f)
{
	f(cs);
}

int main()
{
    //��ʾ�󶨺���myfunc3����������ֵΪ10 20 30������ֵanto��ʾ���ǲ���ϵ��
    //���ص����ͣ�ʵ�������ص�Ҳ��һ���º������Ͷ��󣬿���ֱ�ӵ��ã�Ҳ����
    //����std::function
    auto bf1 = std::bind(myfunc3, 10, 20, 30);
    bf1();//ִ��myfunc3���� ���x:10 y=20 z=30

    //��ʾ�󶨺���myfunc3�ĵ���������Ϊ30 ��myfunc3�ĵ�һ �ڶ��������ֱ�
    //�ɵ���bf2ʱ�ĵ�һ�� �ڶ�������ָ�� _1 _2,...,20�����Ǳ�׼���ﶨ���
    //ռλ���ĺ��� ���������Ĳ�����20�� placeholders::_1��ʾ���λ�ý��ں�������
    //ʱ������ĵ�һ������������
    auto bf2 = std::bind(myfunc3, placeholders::_1, placeholders::_2, 30);
    bf2(5, 15);//ʵ�ʵ���ָ��myfunc3�ĵ�һ���͵ڶ������� ���x:10 y=20 z=30
    std::bind(myfunc3, placeholders::_1, placeholders::_2, 30)(10, 20);//ֱ�ӵ���

    //myfunc3�ĵ�һ �ڶ��������ֱ��ɵ���bf3�ĵڶ� ��һ������ָ��
    auto bf3 = std::bind(myfunc3, placeholders::_2, placeholders::_1, 30);
    bf3(5,15);

    int a = 2;
    int b = 3;
    auto bf4 = std::bind(myfunc31,a,placeholders::_1);
    bf4(b);//ִ�к�a=2 b=4 ��˵��bind����Ԥ�Ȱ󶨵ĺ���������ͨ��ֵ���ݵ�
    //�������aʵ������ֵ���ݵ� bind���ڲ����Ȱ󶨵Ĳ��� ͨ��std::placeholders
    //���ݵĲ�����ͨ�����ô��ݵģ��������bʵ���������ô��ݵ�
    cout << "-------------------------------------------" << endl;
    CQ cq;//һ�������
    auto bf5 = std::bind(&CQ::myfunpt, cq, placeholders::_1, placeholders::_2);
    //�ຯ���о��Ե�ַ �Ͷ����޹� ��Ҫ�����ñ�������������
    bf5(10, 20);//�Գ�Ա�����ĵ��� ���x=10 y=20
    cout << "-------------------------------------------" << endl;
    //bind��function���ʹ�ã�bind����ֱֵ�Ӹ���std::function���ͣ�
    CQ cq1;
    std::function<void(int, int)> bfc6 = std::bind(&CQ::myfunpt, cq1,
                        std::placeholders::_1, std::placeholders::_2);
    bfc6(10, 20);
    cout << "-------------------------------------------" << endl;
    std::function<int& (void)>bf7 = std::bind(&CQ::m_a, &cq);
    bf7() = 60;//ִ�к�cq�����m_a��Ա����ֵΪ60��
    cout << "-------------------------------------------" << endl;
    auto rt = std::bind(CT3());
    rt();//����operator()�����ʾCT::operator()ִ��
    cout << "-------------------------------------------" << endl;
    auto bf = std::bind(runfunc3, placeholders::_1);//��һ�������ɵ���ʱ
                                                    //�ĵ�һ������ָ��
    for (int i=0;i<10;i++)
    {
        mycallback3(i, bf);//bf��bind���صĽ�� 
                           //ֱ�Ӵ��ݸ���const std::function<void(int)>&f
    }
    return 0;
}