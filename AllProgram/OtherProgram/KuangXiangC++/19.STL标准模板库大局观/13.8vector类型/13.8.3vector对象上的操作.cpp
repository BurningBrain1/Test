#include<iostream>
#include<vector>

using namespace std;

int main()
{
    //1 �ж��Ƿ�Ϊ��
    vector<int> ivec;
    if (ivec.empty())
    {
        cout << "ivecΪ��"<< endl;
    }

    //2 push_back��vectorĩβ���Ԫ��
    vector<int> ivec2;
    ivec2.push_back(1);
    ivec2.push_back(2);
    for (int i = 3; i < 100; i++)
    {
        ivec2.push_back(i);
    }

    //3 size����Ԫ�صĸ���
    cout << ivec2.size()<< endl;

    //4 clear:�Ƴ�����Ԫ�� �������
    ivec2.clear();
    cout << ivec2.size() << endl;//0

    //5 v[n]����v�еĵ�n���ַ�
    ivec2.clear();
    ivec2.push_back(1);
    ivec2.push_back(2);
    cout << ivec2[1] << endl;//2

    //6 ��ֵ�����=
    vector<int> ivec3;
    for (int i = 0; i < 100; i++)
    {
        ivec3.push_back(i);
    }
    vector<int>ivec4;
    ivec4.push_back(111);
    ivec4 = ivec3;//Ҳ�õ���100��Ԫ�� ԭ�����ݱ����б�ȡ��
    //7if(ivec3==ivec4)��if(ivec3!=ivec4)������ʾ

    //8 ��Χfor��Ӧ��
    vector<int>vecvalue{1,2,3,4,5};
    for (auto& vecitem:vecvalue)//���������� �����޸�Ԫ��ֵ
    {
        vecitem = 2 * vecitem;
    }
    for (auto& vecitem:vecvalue)
    {
        cout << vecitem << endl;
    }
    return 0;
}