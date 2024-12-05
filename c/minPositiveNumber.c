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
/**
 * Finds the smallest positive integer that does not appear in the array.
 * 
 * This function iterates through the given array of integers to find the maximum value.
 * If the maximum value is greater than 0, it starts an infinite loop from 1 to find the smallest
 * positive integer that does not appear in the array. If no such number is found, it returns 1.
 * 
 * @param nums The array of integers.
 * @param n The length of the array.
 * @return The smallest positive integer that does not appear in the array.
 */
int min_positive_number(int nums[], int n)
{
    // Initialize the maximum value variable to 0
    int max = 0;
    // Iterate through the array to find the maximum value
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }
    // If the maximum value is greater than 0, start looking for the smallest positive integer
    if (max > 0)
    {
        // int mp = 1;
        for (int i = 1; 1; i++)
        {
            int j = 0;
            // Check if the current number i exists in the array
            for (; j < n; j++)
            {
                if (i == nums[j])
                {
                    break;
                }
            }
            // If the current number i does not exist in the array, return i
            if (j == n)
            {
                return i;
            }
        }
    }

    // If the maximum value is not greater than 0, return 1 directly
    return 1;
}

/*
时间复杂度为O(n),空间复杂度为O(n)

假设序列的长度为n,那么可以保证该序列缺失的最小正数最小不低于1,最大不高于n+1(当原序列是1,2,...,n的时候,缺失的最小正数为n+1)
考虑使用一个辅助数组,收集给定序列中大等于1,小等于n的元素,其余元素不影响结果
可以定义一个n+1个元素的数组,这样可以更直观统计1~n的数字出现的次数(能够统计数n的个数)
 */

/**
 * 寻找数组中最小的正整数
 * 
 * @param nums 一个整数数组
 * @param n 数组的长度
 * @return 返回数组中最小的正整数，如果1到n都存在，则返回n+1
 *
 * 该函数通过计数的思想，找出缺失的最小正整数。首先初始化一个计数数组s，
 * 长度为n+1，用于统计数组nums中出现的正整数。然后遍历nums数组，对出现在1到n
 * 范围内的正整数进行计数。最后，遍历计数数组s，找到第一个计数为0的索引，即
 * 为缺失的最小正整数。如果1到n范围内的所有正整数都存在，则返回n+1。
 */
int min_positive_number2(int nums[], int n)
{
    // 初始化计数数组s，长度为n+1，初始值都为0
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
    
    // 从1开始遍历计数数组s，寻找第一个计数为0的索引
    int i = 1;
    for (; i <= n; i++)
    {
        if (s[i] == 0)
        {
            // 找到缺失的最小正整数，返回之
            return i;
        }
    }
    
    // 如果1到n都存在，则返回n+1
    return n + 1;
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