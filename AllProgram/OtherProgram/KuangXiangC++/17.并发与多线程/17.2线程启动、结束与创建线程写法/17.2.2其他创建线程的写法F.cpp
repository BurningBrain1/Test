#include<iostream>
#include<thread>
using namespace std;

class TA2
{
public:
    void operator()()
    {
        cout << "TA2::operator()��ʼִ����" << endl;
        cout << "TA2::operator()ִ�н�����" << endl;
    }
};

class TA21
{
public:
    TA21(int i) :m_i(i)
    {
        printf("TA21()���캯��ִ�У�m_i=%d,this=%p\n", m_i, this);
    }
    ~TA21()
    {
        printf("TA21()��������ִ�У�m_i=%d,this=%p\n", m_i, this);
    }
    TA21(const TA21& ta) :m_i(ta.m_i)
    {
        printf("TA21()�������캯��ִ�У�m_i=%d,this=%p\n", m_i, this);
    }
    void operator()()
    {
        cout << "mi1��ֵΪ" << m_i << endl;
        cout << "mi2��ֵΪ" << m_i << endl;
        cout << "mi3��ֵΪ" << m_i << endl;
        cout << "mi4��ֵΪ" << m_i << endl;
        cout << "mi5��ֵΪ" << m_i << endl;
        cout << "mi6��ֵΪ" << m_i << endl;
    }

    int m_i;  //���ﲻ����ָ������� 
};

int main2()
{
    //1 ���ഴ���߳�
    TA2 ta;
    thread mytobj3(ta);//ta����ɵ��ö��󣬲���дthread mytobj3(TA()) ������벻��
    mytobj3.join();//ȷ���ȴ��߳�ִ�н��� ������join
    cout << "**************************************" << endl;

    int myi = 6;
    TA21 ta1(myi);//���캯��ִ��
    thread mytobj4(ta1);//�������캯��ִ��
    //mytobj4.detach();
    mytobj4.join();//��join()������������      
    cout << "main������ִ�н���" << endl;

	//2 ��lambda���ʽ�������߳�
	auto mylamthread = []
	{
		cout << "�ҵ��߳̿�ʼִ����" << endl;
		cout << "�ҵ��߳�ִ���������" << endl;
	};

	thread mytobj4(mylamthread);
	mytobj4.join();
	cout << "main������ִ�н���" << endl;
    //���:
   //�ҵ��߳̿�ʼִ����
   //�ҵ��߳�ִ���������
   //main������ִ�н���
    return 0;
}
