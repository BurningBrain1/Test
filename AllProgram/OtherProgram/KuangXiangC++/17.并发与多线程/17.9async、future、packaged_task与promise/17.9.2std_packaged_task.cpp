#pragma once
#include<iostream>
#include<thread>
#include <list>
#include <mutex>
#include <future>
#include <vector>
using namespace std;

vector<std::packaged_task<int(int)>>mytasks;

int mythread2(int mypar)
{
	cout << mypar << endl;
	cout << "mythread2()start" << " thread id=" << std::this_thread::get_id() << endl;
	std::chrono::milliseconds dura(5000); //5s
	std::this_thread::sleep_for(dura);//��Ϣһ����ʱ��
	cout << "mythread()end" << " thread id=" << std::this_thread::get_id() << endl;
	return 5;
}

int main()
{
	cout << "main" << " thread id=" << std::this_thread::get_id() <<endl;
	std::packaged_task<int(int)>mypt(mythread2);//�Ѻ���(��������lambdaҲ����)mythreadͨ��package_task��װ����
	std::thread t1(std::ref(mypt),1);//�߳�ֱ�ӿ�ʼִ�� �ڶ���������Ϊ�߳���ں����Ĳ���
	t1.join();//���Ե�������ȴ��߳�ִ����� ������������� ��������
	std::future<int>result = mypt.get_future();//std::future�����ﺬ���߳���ں����ķ��ؽ��
											   //������result����mythread���صĽ��
	cout << result.get() << endl;
	cout << "main������ִ�н���" << endl;
	//���:
	//main thread id=3040
	//1
	//mythread2()start thread id=11308
	//mythread2()end thread id=11308
	//5
	//main������ִ�н���

	//��װlambdaд��
	cout << "main" << " thread id=" << std::this_thread::get_id() << endl;
	std::packaged_task<int(int)>mypt([](int mypar)
		{
			cout << mypar << endl;
			cout << "lambda mythread2()start" << " thread id=" << std::this_thread::get_id() << endl;
			std::chrono::milliseconds dura(5000);
			std::this_thread::sleep_for(dura);
			cout << "lambda mythread2()end" << " thread id=" << std::this_thread::get_id() << endl;
			return 15;
		});
	std::thread t1(std::ref(mypt),1);
	t1.join();
	std::future<int>result1 = mypt.get_future();
	cout << result1.get() << endl;
	cout << "main������ִ�н���" << endl;
	//���:
	//main thread id = 10332;
	//1
	//lambda my mythread2()start thread id=1380
	//lambda my mythread2()end thread id=1380
	//15
	//main������ִ�н���

	//package_task��װ�����Ķ���Ҳ����ֱ�ӵ���  Ҳ��һ���ɵ��ö���
	cout << "main" << " thread id=" << std::this_thread::get_id() << endl;
	std::packaged_task<int(int)>mypt1([](int mypar)
		{
			//ͬ��
		});
	mypt1(105);//�ɵ��ö��� �൱��ֱ�ӽ��к������� ���漰�����߳�
	std::future<int>result = mypt1.get_future();
	cout << result.get() << endl;
	cout << "main������ִ�н���" << endl;
	//���:
	//main thread id = 3356;
	//105
	//lambda my mythread2()start thread id=3356
	//lambda my mythread2()end thread id=3356
	//15
	//main������ִ�н���

    cout << "main" << " thread id=" << std::this_thread::get_id() << endl;
    std::packaged_task<int(int)>mypt2([](int mypar)
        {
            //ͬ��
        });
	//vector<std::packaged_task<int(int)>>mytasks; ȫ�ֱ���
	//������
	mytasks.push_back(std::move(mypt2));//�ƶ����� ���ȥ��mypt��empty��
	//������
	std::packaged_task<int(int)>mypt3;
	auto iter = mytasks.begin();
	mypt3 = std::move(*iter);//���ƶ�����
	mytasks.erase(iter);//ɾ����һ��Ԫ�� �������Ѿ�ʧЧ��������
	mypt3(123);//ֱ�ӵ���
	//Ҫȡ�ý�� ����Ҫ�������future
	std::future<int>result = mypt3.get_future();
	cout << result.get() << endl;
	cout << "main������ִ�н���" << endl;
    //���:
    //main thread id = 11712;
    //123
    //lambda my mythread2()start thread id=11712
    //lambda my mythread2()end thread id=11712
    //15
    //main������ִ�н���
	return 0;
}