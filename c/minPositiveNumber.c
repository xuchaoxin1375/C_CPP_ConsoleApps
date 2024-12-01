#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    extern int min_positive_number(int nums[], int n);
    extern int min_positive_number2(int nums[], int n);
    extern int min_positive_number3(int nums[], int n);
    // int nums[] = {1, 2, 3, 4, -1, 5, 6, 7, 8, 9, 10};
    // int nums[] = {1, 2, 3};
    int nums[] = {-5, 3, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);
    int (*func)(int *, int);
    func = min_positive_number3;
    int res = func(nums, n);
    printf("%i\n", res);
}
/*
时间复杂度为O(n^2),空间复杂度为O(1)
 */
int min_positive_number(int nums[], int n)
{

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }
    if (max > 0)
    {
        // int mp = 1;
        for (int i = 1; 1; i++)
        {
            int j = 0;
            for (; j < n; j++)
            {
                if (i == nums[j])
                {
                    break;
                }
            }
            if (j == n)
            {
                return i;
            }
        }
    }

    return 1;
}

/*
时间复杂度为O(n),空间复杂度为O(n)

假设序列的长度为n,那么可以保证该序列缺失的最小正数最小不低于1,最大不高于n+1(当原序列是1,2,...,n的时候,缺失的最小正数为n+1)
考虑使用一个辅助数组,收集给定序列中大等于1,小等于n的元素,其余元素不影响结果
可以定义一个n+1个元素的数组,这样可以更直观统计1~n的数字出现的次数(能够统计数n的个数)
 */

int min_positive_number2(int nums[], int n)
{
    int s[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        s[i] = 0;
    }
    // 统计出现的数字(负数不用管,大于n的数也不用管)
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0 && nums[i] <= n)
        {
            s[nums[i]]++;
        }
    }
    // int m = 0;
    int i = 1;
    for (; i <= n; i++)
    {
        // printf("s[%d]=%d\n", i, s[i]);
        if (s[i] == 0)
        {
            // printf("return %d\n", i);
            return i;
        }
    }
    return n + 1;
    // 返回n+1(1~n都出现了)
    // if (i = n + 1)
    // {
    //     return n + 1;
    // }
}
/*
和上一个算法的区别是,使用malloc函数动态分配空间,使用free函数释放空间
使用memset将分配的空间全部字节置为0,快速初始化计数数组
并且申请的数组空间少1个,注意对应关系
 */
int min_positive_number3(int nums[], int n)
{
    int i;//循环变量
    int *s;
    s = (int *)malloc(sizeof(int) * n); // 分配空间(计数数组)
    memset(s, 0, sizeof(int) * n);      // 赋初值为 0

    for (i = 0; i < n; i++)
    {
        if (nums[i] > 0 && nums[i] <= n) // 若 A[i] 的值介于 1~n，则标记数组 B
            s[nums[i] - 1] = 1;
    }

    for (i = 0; i < n; i++)
    {
        // 扫描数组 s，找到目标值
        if (s[i] == 0)
            break;
    }
    //如果不是通过break退出循环,说明1~n都出现了,此时i=n;
    free(s); // 释放空间(注意: 释放空间的操作不能省略)

    return i + 1; // 返回结果(注意s[i]统计的是i+1出现的次数,返回的时候返回i+1而不是i;对于i=n的情况,i+1为n+1)
}