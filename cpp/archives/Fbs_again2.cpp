#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        if((n+2)%4==0)/* 观察能够整除的F(n)的位置发现,从的第3个开始,没隔三个(+4)会出现一次整除,即会出现在4n+2处!! */
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}