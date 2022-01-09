#include<iostream>
#include<thread>
using namespace std;

void myprint1()
{
    cout << "我的线程开始执行了" << endl;

    cout << "我的线程执行了完毕了" << endl;
}

void myprint11()
{
    cout << "我的线程执行了完毕了1" << endl;
    cout << "我的线程执行了完毕了2" << endl;
    cout << "我的线程执行了完毕了3" << endl;
    cout << "我的线程执行了完毕了4" << endl;
    cout << "我的线程执行了完毕了5" << endl;
    cout << "我的线程执行了完毕了6" << endl;
    cout << "我的线程执行了完毕了7" << endl;
}

int main1()
{
    //线程对象 给定参数是函数名 它是可调用对象  代表该线程从这个函数开始运行
    thread mytobj(myprint1);
    mytobj.join();//join会卡在这里 等待myprint线程执行完 程序流程才会继续向下走
    //结果:
    //我的线程开始执行了
    //我的线程执行了完毕了

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

    mytobj3.join();//调用join()或detach() 后续用joinable()都为false
    if (mytobj3.joinable())
    {
        mytobj3.join();  //经典写法
    } 
    else
    {
        cout << "false" << endl;
    }
    cout << "main主函数执行结束" << endl;//主线程在执行 主线程从main返回 代表整个进程运行结束
    return 0;
}
