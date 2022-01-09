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

public:
	void thread_work(int num)  //��һ������
	{
		cout << "���߳�thread_workִ��,this=" << this << ",thread id=" << this_thread::get_id() << endl;
	}
	void operator()(int num)
	{
		cout << "���߳�()ִ��,this=" << this << ",thread id=" << this_thread::get_id() << endl;
	}
};

int main4()
{
	//1 ��ͨ���Ա����
    A myobj(10);
    thread mytobj(&A::thread_work,myobj,15);//��A�Ŀ������캯���������߳���ִ�е� �������������߳���ִ��
    mytobj.join();
    cout << "*****************************************" << endl;
    A myobj1(10);
    thread mytobj1(&A::thread_work,&myobj1,16);//�� ������д��1
    mytobj1.join();
    cout << "*****************************************" << endl;
    A myobj2(10);
    thread mytobj2(&A::thread_work, ref(myobj2), 16);//�� ������д��2
    mytobj2.join();
    cout << "main������ִ�н���" << endl;

	//2 �ɵ��ö���
	A myobj1(10);
	//thread mytobj(myobj,15);�������츴�ƴ��οɵ��ö���д��
	thread mytobj1(ref(myobj1), 17);//�ڶ������������޸�Ϊ&myobj ����ᱨ��
	mytobj1.join();
	cout << "main������ִ�н���" << endl;
    return 0;
}