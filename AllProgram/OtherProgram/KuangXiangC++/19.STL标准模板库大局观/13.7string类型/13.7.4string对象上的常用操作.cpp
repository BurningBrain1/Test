#include<iostream>
#include<string>

using namespace std;

int main()
{
    //(1)�ж��Ƿ�Ϊ��empty()
    string s1; 
    if (s1.empty())
    {
        cout << "s1Ϊ��" << endl;
    }
    
    //(2)size()����length() �����ֽ�/�ַ�����
    string s11;
    cout << s11.size() << endl;//0
    cout << s11.length() << endl;//0
    string s2 = "�Ұ��й�";
    cout << s2.size() << endl;//8  1������ռ2���ֽ�
    cout << s2.length() << endl;//8 
    string s3 = "I Love China";
    cout << s3.size() << endl;//13
    cout << s3.length() << endl;//13

    //(3)����s�еĵ�n���ַ�
    s3[4] = 10;

    //(4)s1+s2 �ַ������� �������Ӻ�Ľ�� 
    string s4 = "abcd";
    string s5 = "dfsdf";
    string s6 = s4 + s5;

    //(5)s1=s2 �ַ�������ֵ s2����ȡ��ԭ��s1���������
    s4 = s5;

    //(6)s1==s2 �ж������ַ����Ƿ���� ��Сд����
    if (s4==s5)
    {
        cout << true << endl;
    }

    //(7)s1!=s2 �ж������ַ��������
    if (s4!=s5)
    {
        cout << true <<endl;
    }

    //(8)s.c_str()����һ���ַ���s�е�����ָ�루�������ʵ���Ͼ���
    //string�ַ���������ݣ� ���ص���һ��ָ������C�ַ����ĳ���ָ��
    string s9 = "abc";
    string s10 = "abC";
    const char* p = s10.c_str();//����pָ��s10��ߵ��ַ�����
    char str[100];
    strcpy_s(str,sizeof(str),p);//�ַ������ݸ��Ƶ�str��
    cout << str << endl;//abC

    //(9)��дstring����
    cin >> s1;//����abc�س�
    cout << s1 << endl;//���abc

    //(10)����ֵ��string��� �����ַ������ܰ������
    string s33 = s1 + "and" + s2;

    //(11����Χfor���string��ʹ��
    string ss = "I Love China";
    for (auto& c:ss)
    {
        c = toupper(c);//��Ϊc��һ������ �����൱�ڸı�s�е�ֵ
    }
    cout << ss << endl;//I LOVE CHINA
}