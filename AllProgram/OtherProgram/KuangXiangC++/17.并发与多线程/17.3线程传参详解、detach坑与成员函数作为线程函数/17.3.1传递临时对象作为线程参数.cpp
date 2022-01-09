#include<iostream>
#include<thread>
using namespace std;

//���������� �ַ�ָ��
void myprint1(const int& i, char* pmybuf)
{
	cout << i << endl;
	cout << pmybuf << endl;
	return;
}

//14.13.2�ڽ��� C++����ֻ��Ϊconst���ò�����ʱ���� ���Եڶ�������Ҫ��const
//��һ������������ʹ������ ��ֹ������ �ڶ���������Ȼʹ��������&string 
//��ʵ���ϻ��Ƿ����˶����� ��������ʱ���� �����ϵͳ�ڲ����������й�
void myprint2(int i, const string& pmybuf)
{
	cout << i << endl;
	//cout<<pmybuf<<endl;
	const char* ptmp = pmybuf.c_str();
	cout << pmybuf.c_str() << endl;
	return;
}

class A;
void myprint3(int i, const A& pmybuf)
{
	//cout<<i<<endl;
	cout << &pmybuf << endl;//��ӡ��ַ
	return;
}

class A
{
public:
	A(int a) :m_i(a) {
		cout << "A::A(int a)���캯��ִ��"<<this<< endl;
	}
	A(const A& a) {
		cout << "A::A(const A)�������캯��ִ��"<< this << endl;
	}
	~A() {
		cout << "~A::A()��������ִ��" << this << endl;
	}
	mutable int m_i;
};

int main1()
{
    int mvar = 1;
    int& mvary = mvar;
    char mybuf[] = "this is a test";
    thread mytobj(myprint1,mvar,mybuf);
    mytobj.join();//�������detach�ͻ������ ��Ϊ���߳̿���ʹ���Ѿ�ʧЧ�����߳��ڴ�
	cout << "*********************************" << endl;
	
    thread mytobj1(myprint2,mvar,string(mybuf));//����ֱ�ӽ�mybufת��string���� ����ȷд��
    mytobj1.join();												
    cout << "*********************************" << endl;

    int mvar1 = 1;
    int mysecondpar = 12;
	//ϣ��mysecondparת������A���󴫲ε�myprint3
    thread myobject3(myprint3, mvar1, mysecondpar);
    myobject3.join();//����detach������
    cout << "*********************************" << endl; 

	//��ȷд��
    thread myobject4(myprint3,mvar1,A(mysecondpar));
    myobject4.join();
    cout << "main������ִ�н���" << endl;
    return 0;
}
