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
        cout << "�����˹��캯��" << endl;
        cout << "val1=" << val1 << endl;
        cout << "val2=" << val2 << endl;
    }
    CTempValue(const CTempValue& t) :val1(t.val1), val2(t.val2)
    {
        cout << "�����˿������캯��" << endl;
    }
    virtual ~CTempValue()
    {
        cout << "��������������" << endl;
    }
    CTempValue& operator=(const CTempValue& tmpv)
    {
        //�����ó�ʼ���б� ���캯�����г�ʼ���б�
        val1 = tmpv.val1;
        val2 = tmpv.val2;
        cout << "�����˿�����ֵ�����" << endl;
        return *this;
    }

public:
    int Add(CTempValue tobj)
    {
        int tmp = tobj.val1 + tobj.val2;
        tobj.val1 = 1000;//�޸���������ûӰ��
        return tmp;
    };//��ͨ��Ա����
};

CTempValue Double(CTempValue& ts)
{
    CTempValue tmpm;//���������һ�ι����һ�����������ĵ���
    tmpm.val1 = ts.val1 * 2;
    tmpm.val2 = ts.val2 * 2;
    return tmpm;//�ϵ㵽���� �ᷢ�ֵ����˿������캯������������ ���ʾ��������ʱ����
}

CTempValue Double�Ż�д��(CTempValue& ts)
{
    return CTempValue(ts.val1*2,ts.val2*2);
}

class mynum
{
public:
    mynum()//���캯��
    {
        cout << "�����˹��캯��" << endl;
    }
    mynum(int x, int y) :num1(x), num2(y)//���캯��
    {
        cout << "�����˹��캯��" << endl;
    }
    mynum(const mynum& t) //�������캯��
    {
        cout<<"�����˿������캯��" << endl;
    }
    virtual ~mynum()//��������
    {
        cout <<"��������������"<< endl;
    }
public:
    int num1;
    int num2;
};

//�������������� �������mynum�����ļӷ������
mynum operator0(mynum& tmpnum1, mynum& tmpnum2)
{
    mynum result;
    result.num1 = tmpnum1.num1 + tmpnum2.num1;
    result.num2 = tmpnum1.num2 + tmpnum2.num2;
    return result;
}

mynum operator+(mynum& tmpnum1, mynum& tmpnum2)//�Ż�д��
{
    //�ٵ���һ�ι��캯������������
    return mynum(tmpnum1.num1 + tmpnum2.num1, tmpnum1.num2 + tmpnum2.num2);
}

int main()
{
    //1 �Դ�ֵ�ķ�ʽ���������ݲ���
    CTempValue tm(10, 20);//���ù��캯��
    int Sum = tm.Add(tm);//���¿������캯��ִ��
    cout << "Sum=" << Sum << endl;//Sum=30
    cout << "tm.val1=" << tm.val1 << endl;//tm.val1=10;   
    cout << "---------------------------------------------" << endl;

	//2 ����ת�����ɵ���ʱ����/��ʽ����ת���Ա�֤�������óɹ�
	CTempValue sum;
	sum = 1000;
    cout << "---------------------------------------------" << endl;
	//�Ż���
	CTempValue sum1 = 1000;
    cout << "---------------------------------------------" << endl;
	//C++ֻ��Ϊconst���ò�����ʱ����
	char mystr1[100] = "I love";
	int result1 = calc(mystr1, 'o');//���ô�const�ĺ���
	string mystr2 = "I love";
	int result2 = calc(mystr2, 'o');//���ò���const�ĺ���
	const string mystr3 = "I love";
	int result3 = calc(mystr3, 'o');//���ô�const�ĺ���
    cout << "---------------------------------------------" << endl;

    //3 �������ض����ʱ��
    CTempValue tsl(10, 20);
    Double(tsl);//Ϊ�˼� �Ȳ����պ���Double���صĽ�� �������һ���ͷ���ʱ�������������

	CTempValue ts2(10, 20);
    CTempValue ts3=Double(ts2);

    CTempValue ts4(10, 20);
    CTempValue&& ts5 = Double(ts4);

    CTempValue ts6(10, 20);
    CTempValue&& ts7 = Double�Ż�д��(ts6);
	cout << "---------------------------------------------" << endl;

    //4 ��������������֮�е��Ż�
    mynum tm1;
    tm1.num1 = 10;
    tm1.num2 = 100;
    mynum tm2;
    tm2.num1 = 20;
    tm2.num2 = 200;
    mynum tm3 = tm1 + tm2;//��ִ��operator+(...)
    cout << "---------------------------------------------" << endl;
	return 0;
}

