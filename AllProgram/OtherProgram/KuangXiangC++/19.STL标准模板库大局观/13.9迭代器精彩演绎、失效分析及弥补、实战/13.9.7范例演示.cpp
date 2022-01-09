#include<vector>
#include<iostream>
using namespace std;

struct conf
{
    char itemname[40];
    char itemcontent[100];
};
char* getinfo(vector<conf*>& conflist, const char* pitem)
{
    for (auto pos = conflist.begin(); pos != conflist.end(); ++pos)
    {
        if (_stricmp((*pos)->itemname,pitem)==0)
        {
            return (*pos)->itemcontent;
        }
    }
    return nullptr;
}

int main()
{
    //(1)�õ���������string��������
    string str("I love China");
    for (auto iter=str.begin();iter!=str.end();++iter)
    {
        *iter = toupper(*iter);//����Ԫ��ת�ɴ�д
    }
    cout << str << endl;//I LOVE CHINA

    //(2)vector�������ò������ڴ��ͷ�
    //ServerName=1��  ��ʾ����������ʲô
    //ServerID=100000 ��ʾ������id��ʲô
    conf* p_conf1 = new conf;
    strcpy_s(p_conf1->itemname,sizeof(p_conf1->itemname),"ServerName");
    strcpy_s(p_conf1->itemcontent, sizeof(p_conf1->itemcontent), "1��");

    conf* p_conf2 = new conf;
    strcpy_s(p_conf2->itemname, sizeof(p_conf2->itemname), "ServerID");
    strcpy_s(p_conf2->itemcontent, sizeof(p_conf2->itemcontent), "100000");

    vector<conf*>conflist;//��������з��������ṹ��ָ��
    conflist.push_back(p_conf1);
    conflist.push_back(p_conf2);

    //����conflist����������� �Ժ�Ҫ��ѯServerName ServerID��ʱ��Ϳ��Բ�ѯ��
    char* p_tmp = getinfo(conflist, "SeverName");
    if (p_tmp!=nullptr)
    {
        cout << p_tmp << endl;//1��
    }

    //Ҫ�ͷ��ڴ� �Լ�new��Ҫ�Լ�delete
    std::vector<conf*>::iterator pos;
    for (pos=conflist.begin();pos!=conflist.end();++pos)
    {
        //ע�� ����û���ƻ������� ��Ϊû����conflist����������ɾ������ 
        //ֻ��ɾ����������Ԫ����ָ����������Լ�������ڴ�
        delete(*pos);//*pos�����Ǹ�ָ�� ��������Ҫdelete(*pos)
    }
    conflist.clear();//Ҫ��Ҫ���� ��Ϊ������������� ������ʧЧ��ϵͳ���Զ��ͷ�
    return 0;
}