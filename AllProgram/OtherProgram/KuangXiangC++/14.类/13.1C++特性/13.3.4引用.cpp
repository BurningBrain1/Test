#include<iostream>
using namespace std;

void func(int& ta, int& tb)//�β����Ͷ�����������
{
    ta = 4; //��ta tbֵӰ��main()�е�a��b
    tb = 5;
}

int main40()
{
    int value = 10;
    //refval��������(��������������)
    int& refval = value;//value�ı�����refval 
    refval = 13;//�ȼ���value=13��

    //int& refval2;//���� �����������ͱ����ʼ��
    //int& refval3 = 10;//���� ���ñ���󶨵������������
    int bvalue = 89;
    //float& refvalue = bvalue;//���� ����Ҫ��ͬ

    int a = 3;
    int& b = a;//���� ע��&������=�����
    int* p = &a;//ȡ��ַ�� ע��&������=���Ҳ�

    int a1 = 13;
    int b1 = 14;
    func(a1, b1);
    cout << a1 << " " << b1 << endl;//4 5


    return 0;
}