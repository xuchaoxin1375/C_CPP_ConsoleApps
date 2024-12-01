#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define iprint(expr) printf(#expr " = %i\n", expr)  // 整型值调试宏:打印整数表达式
#define xprint(expr) printf(#expr " = %#x\n", expr) // 整型值调试宏:打印整数十六进制
#define sprint(expr) printf(#expr " = %s\n", expr)  // 字符串调试宏:打印字符串

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int a = 123;
    int b = a;
    iprint(a);
    b = 321;
    iprint(b);
    iprint(a);
    int *p = &a;
    *p = 111;
    iprint(a);
    xprint(40000);
    printf("%f\n", 4e+4);
    iprint(arr[-11]);
    return 0;
}