#include <iostream>
using namespace std;

//����ת�����캯���ص㣺ֻ��һ���β� �ββ��Ǳ����const����
class TestInt2 //һ���� ���汣��0-100֮�������
{
public:
    //�����ϣ��������ʽת�� ǰ��ɼ�explicit
    TestInt2(int x = 0) :m_i(x)//����ת�����캯�� 
                           //�����캯�����Խ�����ת���������Ͷ���
    {
        if (m_i < 0) m_i = 0;//����һ�·�Χ
        if (m_i > 100) m_i = 100;//����һ�·�Χ
        cout << "����������ת�����캯��"<<endl;
    }
    TestInt2& operator=(const TestInt2& test)
    {
        cout << "�����˸�ֵ�����" << endl;
        m_i = test.m_i;
        return *this;
    }
    //����ת������� ���Դӱ�������ת������������ �������β�
    operator int() const
    {
        cout << "����������ת�������" << endl;
        return m_i;//����int���� ���԰������ת��int����
    }
public:
    typedef void(*tfpoint)(int);//����ָ�����Ͷ��� 
    using tfpoint = void(*)(int);//����ָ�����Ͷ��� ���using���tfpoint��������
                                 //*������tfpoint ���еȼ�������typedef��
                                 //�Ժ�ὲusing��ʽ ����ֻ��Ҫ��ס�����Ͷ���
    //һ����̬��Ա����
    static void mysfunc(int v1)   //��̬��Ա����
    {
        int test;
        test = 1;
    }
    //����ת������� �ܰѱ������Ͷ���ת����һ������ָ������
    operator tfpoint()//const���Ǳ���ӵ�
    {
        //�Ǿͱ���Ҫ����һ������ָ��
        cout << "�����˺���ָ������ת��" << endl;
        return mysfunc;//������ַ��Ϊ����ָ�����ͷ�����
    }
public:
    int m_i;
};

    int main2()
    {
        TestInt2 ti = 12;//��ʽ����ת�� ������ת����TestInt1���� ����������ת�����캯��
        TestInt2 ti2(22);//��������ת�����캯�� �����������ʽ����ת��
        cout << "---------------------------------------------------" << endl;
        ti2 = 6;//��ʽת����6ת��һ����ʱ��TestInt2���� Ȼ����ø�ֵ���������ʱ�����ti2
        //int k = ti2 + 5;//k=11 �������operator int()��ti2ת��int ���Ϊ6
                          //ע������ж������ת������� ��ʽת���ᱨ�� ��Ϊ��֪��ѡ���ĸ�����ת�������
        int k2 = ti2.operator int() + 5;//Ҳ������ʽ����
        cout << k2 << endl;
        cout << "---------------------------------------------------" << endl;
        //1 ��ʽ������ת������� 
        int k3 = static_cast<int>(ti2) + 5;//11 ����operator int()��ti2ת��int
        cout << "---------------------------------------------------" << endl;
        //2 ��Ȥ���� �����ת��Ϊ����ָ��
        TestInt2 myi(12);
        myi(123);//ִ��operator tfpoint() Ȼ���ִ��mysfunc��Ա����
        myi.operator TestInt2::tfpoint()(123);//tfpoint��TestInt2�ж��������
                                              //����ǰ��Ҫ����TestInt2::�����޶�
        return 0;
    }

