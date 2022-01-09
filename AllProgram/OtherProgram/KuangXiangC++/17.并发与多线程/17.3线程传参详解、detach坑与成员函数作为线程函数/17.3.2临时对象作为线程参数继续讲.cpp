#include<iostream>
#include<thread>

using namespace std;

class A
{
public:
	A(int a) :m_i(a) {
		cout << "A::A(int a)���캯��ִ��,this=" << this
			<< ",thread id=" << this_thread::get_id() << endl;
	}
	A(const A& a) {
		cout << "A::A(const A)�������캯��ִ��,this=" << this
			<< ",thread id=" << this_thread::get_id() << endl;
	}
	~A() {
		cout << "~A::A()��������ִ��,this=" << this
			<< ",thread id=" << this_thread::get_id() << endl;
	}
	mutable int m_i;
};

//����һ��Ҫд������ ����������߳��е���һ�ο������캯��
void myprint4(const A& pmybuf)
{
	cout << "���߳�myprint2�Ĳ���pmybuf�ĵ�ַ��:" << &pmybuf
		<< ",thread id=" << this_thread::get_id() << endl;
}

int main2()
{
    //1 ��ʱ������ʱ��ץ��
    cout << "���߳�id=" << this_thread::get_id() << endl;
    int mvar = 1;
	//detach�������д�� �����ʱ�����������߳��й����
    thread mytobj(myprint4,mvar);
    mytobj.join();//��join()����۲�
    cout << "*********************************" << endl;
    thread mytobj1(myprint4,A(mvar));
    mytobj1.join();
    cout << "main������ִ�н���" << endl;
    return 0;
}