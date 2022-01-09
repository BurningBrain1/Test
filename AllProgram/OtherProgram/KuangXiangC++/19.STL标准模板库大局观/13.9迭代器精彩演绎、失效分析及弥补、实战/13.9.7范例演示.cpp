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
    //(1)用迭代器遍历string类型数据
    string str("I love China");
    for (auto iter=str.begin();iter!=str.end();++iter)
    {
        *iter = toupper(*iter);//所有元素转成大写
    }
    cout << str << endl;//I LOVE CHINA

    //(2)vector容器常用操作与内存释放
    //ServerName=1区  表示服务器名是什么
    //ServerID=100000 表示服务器id是什么
    conf* p_conf1 = new conf;
    strcpy_s(p_conf1->itemname,sizeof(p_conf1->itemname),"ServerName");
    strcpy_s(p_conf1->itemcontent, sizeof(p_conf1->itemcontent), "1区");

    conf* p_conf2 = new conf;
    strcpy_s(p_conf2->itemname, sizeof(p_conf2->itemname), "ServerID");
    strcpy_s(p_conf2->itemcontent, sizeof(p_conf2->itemcontent), "100000");

    vector<conf*>conflist;//这个容器中放入两个结构体指针
    conflist.push_back(p_conf1);
    conflist.push_back(p_conf2);

    //现在conflist里就有数据了 以后要查询ServerName ServerID的时候就可以查询了
    char* p_tmp = getinfo(conflist, "SeverName");
    if (p_tmp!=nullptr)
    {
        cout << p_tmp << endl;//1区
    }

    //要释放内存 自己new就要自己delete
    std::vector<conf*>::iterator pos;
    for (pos=conflist.begin();pos!=conflist.end();++pos)
    {
        //注意 这里没有破坏迭代器 因为没有往conflist容器中增加删除数据 
        //只是删除迭代器里元素所指向的由我们自己分配的内存
        delete(*pos);//*pos才是那个指针 所以这里要delete(*pos)
    }
    conflist.clear();//要不要都行 因为容器本身的内容 在容器失效后系统会自动释放
    return 0;
}