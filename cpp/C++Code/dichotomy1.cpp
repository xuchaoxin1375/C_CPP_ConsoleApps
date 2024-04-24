/* Problem Description
给定序列A={A1,A2,...,An}, 要求  改变(比如对调/就地调整大小(当然,前者是后者的特殊情况),我们只考虑调整大小即可) 
序列A中的某些元素，形成一个严格单调的序列B
（严格单调的定义为：Bi<Bi+1,1≤i<N）。(递增)
我们定义从序列A到序列B变换的代价为cost(A,B)=max(|Ai−Bi|)(1≤i≤N)。
请求出满足条件的最小代价。

进行二分可能的答案: 由二分法找出准确答案是重点，我们函数 judgefail(int curr) 来
判断当最大代价为curr时该序列   是否可以变成严格单调。
1.因为输入的每个数都在10^6内，所以答案也在10 ^6内，从10 ^6开始二分。
    对每个测试数进行测试.必要时削减去curr大小来调整成单调(即便
    是对每一个数进行削减,cost也不会超过curr,当然减掉curr后可能出现负值,这不碍事)
   验证时要尽可能让第1个数变得最小，并且让数紧凑。
2.二分枚举最大改变量
，对于改变量mid，a[0]=a[0]-mid（先尽可能把第一个数变小），然后从第二个数向后扫，
先让a[i]=a[i]-mid，如果b[i]<=b[i-1],说明b【i】此时减的过多了，，b[i]=b[i-1]+1(让序列尽可能的紧凑)，
然后判断abs(a[i]-b[i]),如果>mid， 说明mid过小，返回false，取右区间（较大区间）二分答案；
如果for循环结束返回true，说明mid>=最优解，取左区间（较小区间）二分答案，维护最终答案输出即可。 */
/* 1分摊改变量 
Input
第一行为测试的组数T(1≤T≤10).

对于每一组：
第一行为序列A的长度N(1≤N≤105)，第二行包含N个数，A1,A2,...,An.
序列A中的每个元素的值是正整数且不超过106。
 
/* Sample Input
2

2
1 10

3
2 5 4
 

Sample Output
Case #1:
0

Case #2:
1 */

# include <stdio.h>
# include <stdlib.h> 
int a[100001], n;

bool judge(int num)/* bool型函数(返回bool值True/false),而参数是整形值 */
{
    int x = a[0] - num;//定义x的时候同时给x初始化个值(表达式)为:a[0] - num(削减原序列Ai的值num)
    int y  = 0;
    for(int i=1; i<n; ++i)
    {
        y = a[i] - num;/* 标准(限制条件)分开施加(先后遍历),多个标准同时考虑会使思维混乱 */
        if(y <= x)
        {
            y = x + 1;
            if(abs(y - a[i]) > num)
                return false;
        }
        x = y;/* 刷新x */
    }
    return true;
}




int main()
{
    int t, cas = 1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        
        for(int i=0; i<n; ++i)
            scanf("%d",&a[i]);

        int l=0, r=1000001, mid;
        while(l<r)
        {
            mid = (l+r)>>1;
            if(judge(mid))
                r = mid;
            else
                l = mid + 1;
        }
        printf("Case #%d:\n%d\n",cas++, r);
    }
    return 0;
}
