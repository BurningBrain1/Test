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

void myprint5(const A& pmybuf)
{
    pmybuf.m_i = 199;//�޸ĸ�ֵ����Ӱ�쵽main��������ʵ�εĳ�Ա����
    cout << "���߳�myprint2�Ĳ���pmybuf�ĵ�ַ��:" << &pmybuf
        << ",thread id=" << this_thread::get_id() << endl;
}

void myprint6(unique_ptr<int> pzn)
{
    return;
}

int main3()
{
    A myobj(10);//����һ�������
    thread mytobj(myprint5,myobj); //�޸�myprint5�ββ���Ӱ�쵽main��������ʵ�εĳ�Ա����
    mytobj.join();
	cout << "----------------------------------------------------" << endl;

	A myobj1(10);
	thread mytobj1(myprint5, ref(myobj1));//���������� �β�const mutable��ȥ��
	mytobj1.join();
	cout << "----------------------------------------------------" << endl;

	unique_ptr<int> myp(new int(100));
	thread mytobj2(myprint6, std::move(myp));
	mytobj2.join();
    cout << "main������ִ�н���" << endl;
    return 0;
}

