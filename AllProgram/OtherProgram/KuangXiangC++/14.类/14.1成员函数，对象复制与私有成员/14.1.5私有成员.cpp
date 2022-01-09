#include <iostream>
using namespace std;

class Time5
{
public:
    int Hour;
    int Minute;
    int Second;
private:
    int Millisecond;
private:
    void initMillTime(int mls);
};

void Time5::initMillTime(int mls)
{
    Millisecond = mls;
}


int main()
{
    return 0;
}