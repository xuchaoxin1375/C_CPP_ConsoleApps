#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define iprint(expr) printf(#expr " = %i\n", expr)  // 整型值调试宏
#define xprint(expr) printf(#expr " = %#x\n", expr) // 整型值调试宏

int gcd1(int a, int b)
{
    a = abs(a);
    b = abs(b);
    if (a % b == 0)
    {
        // a>=b的情况下才有可能
        return b;
    }
    else
    {
        /*
          (1)a<b时
          gcd(b, a);
          (2)a>b但a%b!=0 (2)
          gcd(b, a % b);

          如果考虑本节的性质,a<b时a%b=a,那么情况(1)可以的gcd(b,a)=g(b,a%b),和情况(2)的式子相同了
          所以上述两种情况(1)(2)合并
      */
        return gcd1(b, a % b);
    }
}
int gcd(int a, int b)
{
    /* 为了能够处理负数,这里引入了abs函数,可用通过stdlib.h导入 */
    a = abs(a);
    b = abs(b);
    int r = a % b;
    if (!r)
    {
        return b;
    }
    else
    {
        return gcd(b, r); // 这里的return可以省略掉
    }
}

void test_gcd()
{
    // 1
    assert(gcd(132, 15) == 3);

    // 2
    assert(gcd(15, 132) == 3);
    assert(gcd(132, -15) == 3);

    // 3
    assert(gcd(24, 30) == 6);

    // 4
    assert(gcd(48, 18) == 6);

    // 5
    assert(gcd(18, 48) == 6);

    // 6
    assert(gcd(11, 11) == 11);

    // 7
    assert(gcd(4, 4) == 4);

    // 8
    assert(gcd(3, 3) == 3);

    // 9
    assert(gcd(2, 2) == 2);

    // 10
    assert(gcd(1, 1) == 1);

    assert(gcd(6409, 42823) == 17);

    printf("All tests passed\n");
}
int main()
{

    test_gcd();
    // iprint(gcd(132, 15));//3
    iprint(gcd(6409, 42823)); // 17
    return 0;
}