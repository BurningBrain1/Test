#include <iostream>
using namespace std;

//����ת�����캯���ص㣺ֻ��һ���β� �ββ��Ǳ����const����
class TestInt1 //һ���� ���汣��0-100֮�������
{
public:
    //�����ϣ��������ʽת�� ǰ��ɼ�explicit
    TestInt1(int x = 0) :m_i(x)//����ת�����캯�� 
                           //�����캯�����Խ�����ת���������Ͷ���
    {
        if (m_i < 0) m_i = 0;//����һ�·�Χ
        if (m_i > 100) m_i = 100;//����һ�·�Χ      
    }
public:
    int m_i;
};

int main1()
{
    
    TestInt1 ti = 12;//��ʽ����ת�� ������ת����TestInt1���� ����������ת�����캯��
    TestInt1 ti2(22);//��������ת�����캯�� �����������ʽ����ת��
    return 0;
}