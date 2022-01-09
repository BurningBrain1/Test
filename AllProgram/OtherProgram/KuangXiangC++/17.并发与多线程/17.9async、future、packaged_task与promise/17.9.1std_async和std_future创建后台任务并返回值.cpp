#pragma once
#include<iostream>
#include<thread>
#include <list>
#include <mutex>
#include <future>
using namespace std;

class A1
{
public:
    int mythread(int mypar)
    {
        cout << mypar << endl;
        cout << "mythread()start" << "thread id=" << std::this_thread::get_id() << endl;
        std::chrono::milliseconds dura(2000);
        std::this_thread::sleep_for(dura);
        cout << "mythread()end" << "thread id=" << std::this_thread::get_id() << endl;
        return 5;
    }
};

int mythread()
{
    cout << "mythread()start" << "thread id="<< this_thread::get_id() << endl;
    std::chrono::milliseconds dura(2000);//1s=1000s
    std::this_thread::sleep_for(dura);//��Ϣһ����ʱ��
    cout << "mythread()end" << "thread id=" << std::this_thread::get_id() << endl;
    return 5;
}

int mythread1()
{
    return 1;
}

int main()
{
    //1 std::async��std::future
    cout << "main " << "thread id=" << std::this_thread::get_id() << endl;
    std::future<int>result = std::async(mythread);//���̲����Ῠ������
                                                  //����߳���ں�����Ҫ����
                                                  //�Ѳ�������async�ڶ���������λ��
    cout << "continue" << endl;
    cout << result.get()<< endl;//��������ȴ��߳�ִ���� 
                                //������get��ΪһЩ�ڲ�������� ֻ��getһ�� �����쳣
    cout << "main������ִ�н���" << endl;
    //���:
    //main threadid=15064
    //continue..!
    //mythread() start threadid=6896
    //mythread() end threadid=6896
    //5
    //main������ִ�н���

    result.wait();//���̿�������ȴ��̷߳��� ���������ؽ��
    
    A1 a;
    int tmppar = 12;
    std::future<int> result1 = std::async(&A1::mythread, &a, tmppar);
                                    //����ڶ��������Ƕ����ַ�����ܱ�֤�߳������õ���
                                    //ͬһ������ �������������߳���ں����Ĳ��� 
    cout << "continue" << endl;
    cout << result1.get() << endl;
    cout << "main������ִ�н���" << endl;
    //���:
    //main threadid=11552
    //continue..!
    //12
    //mythread() start threadid=13868
    //mythread() end threadid=13868
    //5
    //main������ִ�н���

    //2 std::async����������
    // 
    //(1)std::launch::deferred
    //�ò�����ʾ�߳���ں�����ִ�б��ӳٵ�std::future��wait����get��������ʱ�����wait
    //����getû�б����� ��ô�߳̾͸ɴ಻ִ����
    //ע�� ����д������û�������߳� ���������߳��е��õ���ں��� 
    auto result2 = std::async(std::launch::deferred, &A1::mythread, &a, tmppar);//����ע��͵��д��auto
    //���:
    //main threadid=15072
    //continue..!
    //12
    //mythread() start threadid=15072
    //mythread() end threadid=15072
    //5
    //main������ִ�н���

    //(2)std::launch::async ϵͳ����Ҫ���������߳���ִ��
    auto result3 = std::async(std::launch::async, &A1::mythread, &a, tmppar);
    //���:
    //main threadid=9892
    //continue..!
    //12
    //mythread() start threadid=7916
    //mythread() end threadid=7916
    //5
    //main������ִ�н���

    //(3)std::launch::deferred��std::launch::asyncͬʱʹ��
    auto result4 = std::async(launch::async | launch::deferred, &A1::mythread, &a, tmppar);
    //|��ʾ����ö��ֵһ����

    //(4)�����κζ���Ĳ���  
    //async()���� Ĭ���õľ���std::launch::async���
    std::future<int>result5 = std::async(&A1::mythread, &a, tmppar);

    //3 std::async��std::thread������
    //��ζ�ſ����Ǵ������̲߳�������ʼִ���߳�
    cout << "main������ִ�н���" << endl;
    return 0;
}