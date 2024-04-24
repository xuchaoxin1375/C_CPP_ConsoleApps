#include <stdio.h>
#include "compare.h"

int main()
{
    int num1 = 3;
    int num2 = 5;

    int result = compare_integers(num1, num2);

    switch (result)
    {
    case 1:
        printf("%d is greater than %d\n", num1, num2);
        break;
    case -1:
        printf("%d is less than %d\n", num1, num2);
        break;
    case 0:
        printf("%d is equal to %d\n", num1, num2);
        break;
    }

    return 0;
}