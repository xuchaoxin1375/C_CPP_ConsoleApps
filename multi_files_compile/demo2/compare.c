// #include "compare.h"

// 实现比较两个整数大小的函数
int compare_integers(int a, int b)
{
    if (a > b)
    {
        return 1; // a大于b
    }
    else if (a < b)
    {
        return -1; // a小于b
    }
    else
    {
        return 0; // a等于b
    }
}