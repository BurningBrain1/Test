#include<iostream>
#include<thread>
using namespace std;

void myprint1()
{
    cout << "�ҵ��߳̿�ʼִ����" << endl;

    cout << "�ҵ��߳�ִ���������" << endl;
}

void myprint11()
{
    cout << "�ҵ��߳�ִ���������1" << endl;
    cout << "�ҵ��߳�ִ���������2" << endl;
    cout << "�ҵ��߳�ִ���������3" << endl;
    cout << "�ҵ��߳�ִ���������4" << endl;
    cout << "�ҵ��߳�ִ���������5" << endl;
    cout << "�ҵ��߳�ִ���������6" << endl;
    cout << "�ҵ��߳�ִ���������7" << endl;
}

int main1()
{
    //�̶߳��� ���������Ǻ����� ���ǿɵ��ö���  ������̴߳����������ʼ����
    thread mytobj(myprint1);
    mytobj.join();//join�Ῠ������ �ȴ�myprint�߳�ִ���� �������̲Ż����������
    //���:
    //�ҵ��߳̿�ʼִ����
    //�ҵ��߳�ִ���������

    thread mytobj2(myprint11);
    mytobj2.detach();

    thread mytobj3(myprint11);
    if (mytobj3.joinable())
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false";
    }

    mytobj3.join();//����join()��detach() ������joinable()��Ϊfalse
    if (mytobj3.joinable())
    {
        mytobj3.join();  //����д��
    } 
    else
    {
        cout << "false" << endl;
    }
    cout << "main������ִ�н���" << endl;//���߳���ִ�� ���̴߳�main���� ���������������н���
    return 0;
}
