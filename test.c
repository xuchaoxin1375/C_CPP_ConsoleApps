#include <stdio.h>
#define iprint(expr) printf(#expr " = %i\n", expr)  // 整型值调试宏
#define xprint(expr) printf(#expr " = %#x\n", expr) // 整型值调试宏

int main()
{
    int num_d, num_i;
    xprint(-1);
    xprint(0);
    xprint(1);

    return 0;
}