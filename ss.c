#include <stdio.h>

int main()
{
    struct A
    {
        int a;
        char b;
        short c;
    };
    struct B
    {
        char b;
        int a;
        short c;
    };
    printf("sizeof(A)=%d\n", sizeof(struct A));
    printf("sizeof(B)=%d\n", sizeof(struct B));
    return 0;
}
