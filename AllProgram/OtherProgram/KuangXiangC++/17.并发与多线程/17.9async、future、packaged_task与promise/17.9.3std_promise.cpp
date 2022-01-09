#include <windows.h>
#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <condition_variable>
#include <future>
using namespace std;

void mythread3(std::promise<int>& tmpp, int calc)//注意第一个参数
{

    cout << "mythread3() start" << " thread id= " << std::this_thread::get_id() << endl;
    //做一系列复杂操作
    calc++;
    calc *= 10;
    //做其他运算 整个花费5s
    std::chrono::milliseconds dura(5000);
    std::this_thread::sleep_for(dura);

    //终于计算出了结果
    int result = calc;//保存结果
    tmpp.set_value(result);//结果保存到了tmpp
    cout << "mythread3() end" << " thread id= " << std::this_thread::get_id() << endl;
}

void mythread3_1(std::future<int>& tmpf)//注意参数
{
    auto result = tmpf.get();//获取值 只能get一次否则会报异常
    cout << "mythread3_1 result=" << result << endl;
    return;
}
int main()
{
    //用promise 我们可以在某个线程给它赋值 然后在其他线程中把值取出来用
    cout << "main" << " thread id= " << std::this_thread::get_id() << endl;
    std::promise<int>myprom;//声明std::promise对象myprom，保存的值类型为int
    //创建一个线程t1，将函数mythread及对象myprom作为参数放进去
    std::thread t1(mythread3,std::ref(myprom),180);
    t1.join();//等线程执行完毕 这个必须有 否则报异常 join放在.get后面也可以
    //获取结果值
    std::future<int>ful = myprom.get_future();//promise和future绑定用于获取线程返回值
    auto result = ful.get();//获取值 但这种get因为一些内部特殊操作 不能get多次 只能get一次
    cout << "result= " << result << endl;
    //std::thread t2(mythread3_1,std::ref(ful));//传递数据 加了这个线程上面的get就不能再用了
    //t2.join();
    cout << "main主函数执行结束" << endl;
    //结果：
    //main thread id = 10740;
    //lambda my mythread2()start thread id=1436
    //lambda my mythread2()end thread id=1436
    //result=1810
    //main主函数执行结束
    return 0;
}