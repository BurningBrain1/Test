#include<iostream>
using namespace std;

int main4()
{

    //1 const char * p
    //pָ������ݲ���ͨ��p���޸� pΪ����ָ��
    char str[] = "ILove";
    char* p1;
    p1 = str;
    *p1 = 'Y';//��ʱpΪ��YLove��
    p1++; //p����ָ��ͬ��λ�� ֻҪ��Щλ�õ��ڴ�����ǹ�
    cout << p1 << endl;//��ʱpΪ��Love����Ϊָ����ǰ����һ��

    const char* p;
    //*p = 'Y';//����
    str[0] = 'Y';//��ȷ

    //2 char const *p�ȼ���const char *p

    //3 char * const p
    //p��������ָ��ͬĿ�� pΪָ�볣��
    char str1[] = "I Love";
    char* const p2 = str1;//�����ʱ������ʼ��
    //p2++;//������ p������ָ��ͬĿ��
    *p2 = 'Y';//�������޸�ָ��Ŀ���е�����

    //4 const char * const p=str��char const * const p=str �����ɱ�

    //5 �����÷�
    int i = 100;
    const int& a = i;//��ʾa��������ݲ���ͨ��a�Լ����޸� ����a=200�Ƿ�
    const int& b = 156;//���� ����ֵ��ʼ���������� ��int& b=156����
                       //b�������Ƿ������ڴ� ����ֵ��ֵ�����ᵽ
    //b = 157;//���� b���ɳ��� ֵ�����޸�
    return 0;
}