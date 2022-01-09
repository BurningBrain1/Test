// STL.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include <array>
#include <string>
#include <vector>
using namespace std;

class A
{
public:
    int m_i;
    A(int tmpv) :m_i(tmpv)
    {
        cout << "A::A()���캯��ִ��" << endl;
    }
    A(const A& tmpA)
    {
        m_i = tmpA.m_i;
        cout << "A::A()�������캯��ִ��" << endl;
    }
    ~A()
    {
        cout << "A::~A()��������ִ��" << endl;
    }
};
int main()
{
    //19.2.2 ������˵���ͼ�Ӧ��
    array<string, 5>mystring = {"I","Love1","China"};//�������5��stringԪ��
    cout << "mystring.size()=" << mystring.size() << endl;//5
    mystring[0] = "It is long~~~~~~~~~~~~~~~long~~~~~~~long";
    mystring[4] = "It is long~~~~~~~~~~~~~~~long~~~~~~~long";
    cout << "sizeof(string)=" << sizeof(string) << endl;
    for (size_t i = 0; i < mystring.size(); ++i)
    {
        const char* p = mystring[i].c_str();
        cout << "----------------begin------------------------" << endl;
        cout << "����Ԫ��ֵ=" << p << endl;//���±���� ��0��ʼ
        printf("�����ַ=%p\n", &mystring[i]);
        printf("ָ����ַ�����ַ=%p\n", p);
        cout << "------------------end--------------------------" << endl;
    }

    const char* p1 = "Love1Love2Love3";
    const char* p2 = "Love1Love2Love3";
    printf("ָ���ַ�����p1��ַ=%p1\n", p1);
    printf("ָ���ַ�����p2��ַ=%p2\n", p2);
    cout << "�ҵ���ѽ" << endl;

    //mystring.size();
    //sizeof(string) = 28; string����Ĭ��Ϊ28�ֽ�
    //-----------begin-------------------
    //����Ԫ��ֵ=It is long~~~~~~~~~~~~~~~long~~~~~~~long;
    //�����ַ=0057FBF8
    //ָ����ַ�����ַ=0078CE58
    //-----------end---------------------
    //-----------begin-------------------
    //����Ԫ��ֵ = Love1Love2;
    //�����ַ=0057FC14
    //ָ����ַ�����ַ=00785958
    //-----------end---------------------
    //-----------begin-------------------
    //����Ԫ��ֵ=China
    //�����ַ=0057FC30
    //ָ��Ķ����ַ=0057FC34
    //-----------end---------------------
    //-----------begin-------------------
    //����Ԫ��ֵ=
    //�����ַ=0057FC4C
    //ָ��Ķ����ַ=0057FC50
    //-----------end---------------------
    //-----------begin-------------------
    //����Ԫ��ֵ=It is long~~~~~~~~~~~~~~~long~~~~~~~long
    //�����ַ=0057FC68
    //ָ��Ķ����ַ=0078D0D0
    //-----------end---------------------
    //ָ���ַ�����p1��ַ=00EAED542
    //ָ���ַ�����p2��ַ=00EAED542

    vector<A>myveca;
    cout << "myveca.capacity()=" << myveca.capacity() << endl;//0   
    cout << "myveca.size()=" << myveca.size() << endl;//0

    myveca.reserve(10);//Ԥ��10���ռ�

    cout << "myveca.capacity()=" << myveca.capacity() << endl;//10
    cout << "myveca.size()=" << myveca.size() << endl;//0

    for (int i=0;i<5;++i)
    {
        cout << "---------begin--------" << endl;
        myveca.push_back(A(i));//������ĩβ����Ԫ��
        cout << "----------end----------" << endl;
    }


}


