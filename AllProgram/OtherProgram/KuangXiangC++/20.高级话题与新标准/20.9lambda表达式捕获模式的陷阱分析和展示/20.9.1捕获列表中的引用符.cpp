
#include <iostream>
#include <ctime>
#include <vector>
#include <functional>
using namespace std;

std::vector<std::function<bool(int)>>gv;//ȫ���� ÿ��Ԫ�ض���һ��function
								//ÿ��function����ȥһ��int ����һ��bool

void myfunc1()
{
	//Ҫ����<ctime>ͷ
	srand((unsigned)time(NULL));//���ݵ�ǰʱ������һ����������� ���������rand
								//��������� ����ÿ�γ��������������һ��
	int tmpvalue = rand() % 6;//0-5֮�����ֵ
	gv.push_back(//��һ���ɵ��ö���(lambda���ʽ)��gv������
		[&](int tv) {
			//���lambda������������tmpvalue�������� ���Ǻ��鷳����
			if (tv % tmpvalue == 0)//���tv��tmpvalue�ı���
			{
				return true;
			}
			return false;
		});
}

int main()
{
	myfunc1();
	cout << gv[0](10) << endl;//���ٵ��� ������õ������� ��Ϊ��ʱlambda��tmpvalue
							  //�ѱ����� ���Ի����δ������Ϊ



	return 0;
}
