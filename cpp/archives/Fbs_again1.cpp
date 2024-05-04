/* There are another kind of Fibonacci numbers: 
F(0) = 7, F(1) = 11, F(n) = F(n-1) + F(n-2)     (n>=2). */
#include<iostream>
using namespace std;
int a[10];
int main()
{
    a[0]=1,a[1]=11;
    int n;
    for(int i=2;i<8;i++)/*i前预留两个位置:i = 0;i = 1;   
                                    i < 8 ?because:a[0]~a[7]已有八个位置来容纳一个周期 观察F(n)/3的余数的规律
                                    (当然你要敢猜测(周期性(周期大小,循环出现))) */
    {
        a[i]=(a[i-1]+a[i-2]);
        //模拟模型:F(n) = F(n-1) + F(n-2)     (n>=2).
    }
    while(cin>>n)//输入
    {
        if((a[n%8])%3==0)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}