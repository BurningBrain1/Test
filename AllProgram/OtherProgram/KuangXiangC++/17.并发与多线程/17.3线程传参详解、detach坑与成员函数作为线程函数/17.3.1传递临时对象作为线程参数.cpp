#include<iostream>
#include<thread>
using namespace std;

//常整数引用 字符指针
void myprint1(const int& i, char* pmybuf)
{
	cout << i << endl;
	cout << pmybuf << endl;
	return;
}

//14.13.2节讲过 C++语言只会为const引用产生临时对象 所以第二个参数要加const
//第一个参数不建议使用引用 防止出问题 第二个参数虽然使用了引用&string 
//但实际上还是发生了对象复制 生成了临时对象 这个与系统内部工作机理有关
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
	cout << &pmybuf << endl;//打印地址
	return;
}

class A
{
public:
	A(int a) :m_i(a) {
		cout << "A::A(int a)构造函数执行"<<this<< endl;
	}
	A(const A& a) {
		cout << "A::A(const A)拷贝构造函数执行"<< this << endl;
	}
	~A() {
		cout << "~A::A()析构函数执行" << this << endl;
	}
	mutable int m_i;
};

int main1()
{
    int mvar = 1;
    int& mvary = mvar;
    char mybuf[] = "this is a test";
    thread mytobj(myprint1,mvar,mybuf);
    mytobj.join();//如果换成detach就会出问题 因为子线程可能使用已经失效的主线程内存
	cout << "*********************************" << endl;
	
    thread mytobj1(myprint2,mvar,string(mybuf));//这里直接将mybuf转成string对象 是正确写法
    mytobj1.join();												
    cout << "*********************************" << endl;

    int mvar1 = 1;
    int mysecondpar = 12;
	//希望mysecondpar转成类型A对象传参到myprint3
    thread myobject3(myprint3, mvar1, mysecondpar);
    myobject3.join();//换成detach出问题
    cout << "*********************************" << endl; 

	//正确写法
    thread myobject4(myprint3,mvar1,A(mysecondpar));
    myobject4.join();
    cout << "main主函数执行结束" << endl;
    return 0;
}
