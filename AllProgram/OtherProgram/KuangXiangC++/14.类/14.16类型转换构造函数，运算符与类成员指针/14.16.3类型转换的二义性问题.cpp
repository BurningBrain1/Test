#include <iostream>
using namespace std;

//����ת�����캯���ص㣺ֻ��һ���β� �ββ��Ǳ����const����
class TestInt3 //һ���� ���汣��0-100֮�������
{
public:
    //�����ϣ��������ʽת�� ǰ��ɼ�explicit
    TestInt3(int x = 0) :m_i(x)//����ת�����캯�� 
                           //�����캯�����Խ�����ת���������Ͷ���
    {
        if (m_i < 0) m_i = 0;//����һ�·�Χ
        if (m_i > 100) m_i = 100;//����һ�·�Χ
        cout << "����������ת�����캯��" << endl;
    }
    TestInt3& operator=(const TestInt3& test)
    {
        cout << "�����˸�ֵ�����" << endl;
        m_i = test.m_i;
        return *this;
    }
    
    operator int() //����һ��ת�����������ֵ�����ת�������
    {
        return 6;
    }
    //operator double() { return 10.6; };//�ֶ���һ��ת����ʵ�����ֵ�����ת�������
public:
    int m_i;
};

class CT1
{
public:
    CT1(int ct) {};//����ת�����캯��
};
class CT2
{
public:
    CT2(int ct){}//����ת�����캯��
};

void testfunc(const CT1& C){};
void testfunc(const CT2& C){};
int main3()
{
    TestInt3 aa;
    int abc = aa + 12;//�ᱨ�����Դ���

    //testfunc(101);//�ᱨ������ int��ת����CT1���� Ҳ����ת����CT2����
    testfunc(CT1(101));//����ȷ����void testfunc(const CT1 &C){}
                       //�������ֶα���������ƵĲ���
	return 0;
}