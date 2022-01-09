#include <windows.h>
#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <condition_variable>
#include <future>
using namespace std;

void mythread3(std::promise<int>& tmpp, int calc)//ע���һ������
{

    cout << "mythread3() start" << " thread id= " << std::this_thread::get_id() << endl;
    //��һϵ�и��Ӳ���
    calc++;
    calc *= 10;
    //���������� ��������5s
    std::chrono::milliseconds dura(5000);
    std::this_thread::sleep_for(dura);

    //���ڼ�����˽��
    int result = calc;//������
    tmpp.set_value(result);//������浽��tmpp
    cout << "mythread3() end" << " thread id= " << std::this_thread::get_id() << endl;
}

void mythread3_1(std::future<int>& tmpf)//ע�����
{
    auto result = tmpf.get();//��ȡֵ ֻ��getһ�η���ᱨ�쳣
    cout << "mythread3_1 result=" << result << endl;
    return;
}
int main()
{
    //��promise ���ǿ�����ĳ���̸߳�����ֵ Ȼ���������߳��а�ֵȡ������
    cout << "main" << " thread id= " << std::this_thread::get_id() << endl;
    std::promise<int>myprom;//����std::promise����myprom�������ֵ����Ϊint
    //����һ���߳�t1��������mythread������myprom��Ϊ�����Ž�ȥ
    std::thread t1(mythread3,std::ref(myprom),180);
    t1.join();//���߳�ִ����� ��������� �����쳣 join����.get����Ҳ����
    //��ȡ���ֵ
    std::future<int>ful = myprom.get_future();//promise��future�����ڻ�ȡ�̷߳���ֵ
    auto result = ful.get();//��ȡֵ ������get��ΪһЩ�ڲ�������� ����get��� ֻ��getһ��
    cout << "result= " << result << endl;
    //std::thread t2(mythread3_1,std::ref(ful));//�������� ��������߳������get�Ͳ���������
    //t2.join();
    cout << "main������ִ�н���" << endl;
    //�����
    //main thread id = 10740;
    //lambda my mythread2()start thread id=1436
    //lambda my mythread2()end thread id=1436
    //result=1810
    //main������ִ�н���
    return 0;
}