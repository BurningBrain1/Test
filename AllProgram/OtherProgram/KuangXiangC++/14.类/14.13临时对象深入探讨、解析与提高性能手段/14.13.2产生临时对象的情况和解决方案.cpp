#include<iostream>
#include<vector>
#include<thread>
#include "common.h"
using namespace std;

class CTempValue
{
public:
    int val1;
    int val2;
public:
    CTempValue(int v1 = 0, int v2 = 0) :val1(v1), val2(v2)
    {
        cout << "调用了构造函数" << endl;
        cout << "val1=" << val1 << endl;
        cout << "val2=" << val2 << endl;
    }
    CTempValue(const CTempValue& t) :val1(t.val1), val2(t.val2)
    {
        cout << "调用了拷贝构造函数" << endl;
    }
    virtual ~CTempValue()
    {
        cout << "调用了析构函数" << endl;
    }
    CTempValue& operator=(const CTempValue& tmpv)
    {
        //不能用初始化列表 构造函数才有初始化列表
        val1 = tmpv.val1;
        val2 = tmpv.val2;
        cout << "调用了拷贝赋值运算符" << endl;
        return *this;
    }

public:
    int Add(CTempValue tobj)
    {
        int tmp = tobj.val1 + tobj.val2;
        tobj.val1 = 1000;//修改这里对外界没影响
        return tmp;
    };//普通成员函数
};

CTempValue Double(CTempValue& ts)
{
    CTempValue tmpm;//这里会消耗一次构造和一次析构函数的调用
    tmpm.val1 = ts.val1 * 2;
    tmpm.val2 = ts.val2 * 2;
    return tmpm;//断点到这里 会发现调用了拷贝构造函数和析构函数 这表示生成了临时对象
}

CTempValue Double优化写法(CTempValue& ts)
{
    return CTempValue(ts.val1*2,ts.val2*2);
}

class mynum
{
public:
    mynum()//构造函数
    {
        cout << "调用了构造函数" << endl;
    }
    mynum(int x, int y) :num1(x), num2(y)//构造函数
    {
        cout << "调用了构造函数" << endl;
    }
    mynum(const mynum& t) //拷贝构造函数
    {
        cout<<"调用了拷贝构造函数" << endl;
    }
    virtual ~mynum()//析构函数
    {
        cout <<"调用了析构函数"<< endl;
    }
public:
    int num1;
    int num2;
};

//类外的运算符重载 针对两个mynum类对象的加法运算符
mynum operator0(mynum& tmpnum1, mynum& tmpnum2)
{
    mynum result;
    result.num1 = tmpnum1.num1 + tmpnum2.num1;
    result.num2 = tmpnum1.num2 + tmpnum2.num2;
    return result;
}

mynum operator+(mynum& tmpnum1, mynum& tmpnum2)//优化写法
{
    //少调用一次构造函数与析构函数
    return mynum(tmpnum1.num1 + tmpnum2.num1, tmpnum1.num2 + tmpnum2.num2);
}

int main()
{
    //1 以传值的方式给函数传递参数
    CTempValue tm(10, 20);//调用构造函数
    int Sum = tm.Add(tm);//导致拷贝构造函数执行
    cout << "Sum=" << Sum << endl;//Sum=30
    cout << "tm.val1=" << tm.val1 << endl;//tm.val1=10;   
    cout << "---------------------------------------------" << endl;

	//2 类型转换生成的临时对象/隐式类型转换以保证函数调用成功
	CTempValue sum;
	sum = 1000;
    cout << "---------------------------------------------" << endl;
	//优化：
	CTempValue sum1 = 1000;
    cout << "---------------------------------------------" << endl;
	//C++只会为const引用产生临时对象
	char mystr1[100] = "I love";
	int result1 = calc(mystr1, 'o');//调用带const的函数
	string mystr2 = "I love";
	int result2 = calc(mystr2, 'o');//调用不带const的函数
	const string mystr3 = "I love";
	int result3 = calc(mystr3, 'o');//调用带const的函数
    cout << "---------------------------------------------" << endl;

    //3 函数返回对象的时候
    CTempValue tsl(10, 20);
    Double(tsl);//为了简单 先不接收函数Double返回的结果 多调用了一次释放临时对象的析构函数

	CTempValue ts2(10, 20);
    CTempValue ts3=Double(ts2);

    CTempValue ts4(10, 20);
    CTempValue&& ts5 = Double(ts4);

    CTempValue ts6(10, 20);
    CTempValue&& ts7 = Double优化写法(ts6);
	cout << "---------------------------------------------" << endl;

    //4 类外的运算符重载之中的优化
    mynum tm1;
    tm1.num1 = 10;
    tm1.num2 = 100;
    mynum tm2;
    tm2.num1 = 20;
    tm2.num2 = 200;
    mynum tm3 = tm1 + tm2;//会执行operator+(...)
    cout << "---------------------------------------------" << endl;
	return 0;
}

