#include <stdio.h>

#define iprint(expr) printf(#expr " = %i\n", expr) // 整型值调试宏:打印整数表达式

#define xprint(expr) printf(#expr " = %#x\n", expr) // 整型值调试宏:打印整数
int g = 1;
void changePointer(int *pp, int *q)
{
    // 我们知道通过指针传参,可以修改实参所指地址对应的变量取值(不是实参本身的取值)
    // 这里修改函数形参指针pp,看看会不会影响pp对应的实参的取值
    // 结论是不会影响到实参本身(尽管可以通过指针修改主调函数中定义的变量取值)
    xprint(pp);
    *pp = *q;
    pp = q;
    xprint(pp);
}
void changePP(int **pp, int *q)
{
    // 通过指针传参,可以修改实参所指地址对应的变量取值(不是实参本身的取值)
    // 这里修改函数形参指针pp,看看会不会影响pp对应的实参的取值
    // 结论是会影响到实参本身(尽管可以通过指针修改主调函数中定义的变量取值)
    xprint(pp);
    xprint(*pp);
    *pp = q; // 修改pp所指的指针的取值(修改指针变量需要二级指针参数)
    xprint(*pp);
}
void changeG(int v)
{
    // 全局变量g不通过显式传参,而是函数内部直接能够访问到外部变量g,并且可以直接修改
    // 因此滥用全局变量,会带来意外的混乱发生
    g = v;
}
void changeArr(int arr[], int v)
{
    arr[0] = v;
}
int main()
{
    int a = 10;
    int b = 20;
    int c[] = {1, 2, 3};

    int *p = &a;
    // 检查主调函数中定义的变量地址和取值
    iprint(a);
    iprint(b);
    xprint(&a);
    xprint(&b);
    xprint(p);
    // 试验1
    //  试验指针传参会不会修改p本身,以及p所指的变量会不会被修改
    changePointer(p, &b);
    // 可以验证,p本身不会被修改,而p所指的变量*p会被修改,本例中主调函数的变量a被修改为20
    xprint(p);
    iprint(a);

    // 试验2
    // changePP(&p, &b);
    // xprint(p);
    // iprint(*p);

    // 试验3
    // changeG(b);
    // iprint(g);
    // 试验4
    changeArr(c, b);
    for (size_t i = 0; i < sizeof(c) / sizeof(int); i++)
    {
        printf("c[%d]=%d\n", i, c[i]);
    }

    return 0;
}