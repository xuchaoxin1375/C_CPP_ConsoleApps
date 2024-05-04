#include <stdio.h>

void print_hello()
{
    printf("Hello, World!\n");
}

int main()
{
    int a = 5;
    int b = 10;
    int sum = a + b;

    print_hello();
    printf("Sum: %d\n", sum);

    return 0;
}