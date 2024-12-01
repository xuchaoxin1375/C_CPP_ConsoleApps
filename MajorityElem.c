#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define iprint(expr) printf(#expr " = %i\n", expr)  // 整型值调试宏:打印整数表达式


int main()
{
    extern int get_main(int *a, int len);
    extern int Majority(int A[], int n);
    int a[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int len = sizeof(a) / sizeof(int);
    // int res = get_main(a, len);
    int res = Majority(a, len);
    iprint(res);
}
/*
时间复杂度为O(n),空间复杂度为O(n)
 */
int get_main(int *a, int len)
{

    // iprint(len);
    // int s[2][len];
    int s[len];
    int h = len / 2;
    for (int i = 0; i < len; i++)
    {
        s[i] = 0;
    }

    for (int i = 0; i < len; i++)
    {
        s[a[i]]++;
    }
    for (int i = 0; i < len; i++)
    {
        // iprint(s[i]);
        printf("s[%i] = %i\n", i, s[i]);
        if (s[i] > h)
        {
            return i;
        }
    }
    return -1;
}
/* 
时间复杂度为O(n),空间复杂度为O(1)
 */
int Majority(int A[], int n)
{
    int i, c, count = 1; // 用来保存候选众数元素，count 用来计数
    c = A[0];            // 设置 A[0] 为候选众数元素

    // 查找候选众数元素
    for (i = 1; i < n; i++)
    {
        if (A[i] == c)
            count++;
        else if (count > 0)
            count--;
        else
        {
            c = A[i]; // 更换候选众数元素，重新计数
            count = 1;
        }
    }

    // 统计候选众数元素的实际出现次数
    if (count > 0)
        for (i = 0; i < n; i++)
            if (A[i] == c)
                count++;

    // 确认候选众数元素
    if (count > n / 2)
        return c;
    else
        return -1; // 不存在众数元素
}