#include <iostream>
using namespace std;

class Time5
{
public:
    int Hour;
    int Minute;
    int Second;
public:
    Time5(int tmphour)
    {
        Hour = tmphour;
        Minute = 59;
        Second = 59;
    }
    Time5(){}
};

void func5(Time5 myt)
{
    return;
}
int main()
{
    func5(16);//�������ɵ�����Time��ĵ������Ĺ��캯��
    Time5 myTime23;
    myTime23 = 16;//���Ҳ������Time��ĵ��������캯��������һ����ʱ����
                  //Ȼ��������ʱ�����ֵ���Ƶ���myTime23�ĳ�Ա������ȥ��
    Time5 myTime100 = { 16 };//����д������ ��һ������16 
                             //������ϵͳ��ȷ���ô�һ�������Ĺ��캯��
    Time5 myTime101 = 16;//��������Ĵ��� ������ʱ���������ʽת������
    func5(16);//��������Ĵ��� ������ʱ���������ʽת������
    return 0;
}