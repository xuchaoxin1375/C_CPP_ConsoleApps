#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main()
{
    int test = '\0';
    if (test)
    {
        printf("true\n");
    }
    printf("test = %d\n", test);
    return 0;
}