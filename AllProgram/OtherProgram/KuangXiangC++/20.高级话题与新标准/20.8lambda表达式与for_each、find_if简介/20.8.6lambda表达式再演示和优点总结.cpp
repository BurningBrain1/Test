#include<iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	//1 for_each�е�lambda���ʽ
	vector<int> myvector = {10,20,30,40,50};
	int isum = 0;
	for_each(myvector.begin(), myvector.end(), [&isum](int val) {
		isum += val;
		cout << val << endl;
		});
	cout << "sum=" << isum << endl;//sum=150

	//2 find_if�е�lambda���ʽ
	vector<int>myvector1 = { 10,20,30,40,50 };
	auto result = find_if(myvector1.begin(), myvector1.end(), [](int val) {
		cout << val << endl;
		if (val>15)
		{
			return true;//����true��ֹͣ����
		}
		return false;//ֻҪ����false,find_if�Ͳ�ͣ�ı���myvector һֱ������trueֹͣ
		});

		if (result==myvector1.end())
		{
			cout << "û�ҵ�" << endl;
		} 
		else
		{
			cout << *result << endl;//�ҵ��� ���Ϊ20
		}
}