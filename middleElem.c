#include <stdio.h>
#include <assert.h>

/*
 * 函数名：M_Search
 * 功能：在两个已排序的数组A和B中查找中间元素
 * 输入：两个整型数组A和B，以及它们的大小n
 * 输出：两个数组中间值的较小值
 */
int M_Search(int A[], int B[], int n)
{
    int s1, d1, m1, s2, d2, m2;
    s1 = 0;
    d1 = n - 1;
    s2 = 1;
    d2 = n - 1;

    while (s1 <= d1 || s2 <= d2)
    {
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;

        if (A[m1] == B[m2]) // 满足条件①
            return A[m1];

        if (A[m1] < B[m2]) // 满足条件②
        {
            if ((s1 + d1) % 2 == 0)
                s1 = m1;
            else
                d1 = m1 - 1;
            if ((s2 + d2) % 2 == 0)
                d2 = m2;
            else
                s2 = m2 + 1;
        }
        else // 满足条件③
        {
            if ((s1 + d1) % 2 == 0)
                d1 = m1;
            else
                s1 = m1 + 1;
            if ((s2 + d2) % 2 == 0)
                s2 = m2;
            else
                d2 = m2 - 1;
        }
    }

    return A[s1] < B[s2] ? A[s1] : B[s2];
}

void run_tests()
{
    // Happy path test cases
    int A1[] = {1, 3, 5};
    int B1[] = {2, 4, 6};
    assert(M_Search(A1, B1, 3) == 3); // Middle element is 3

    int A2[] = {1, 2, 3};
    int B2[] = {4, 5, 6};
    assert(M_Search(A2, B2, 3) == 3); // Middle element is 3

    // Edge cases
    int A3[] = {1};
    int B3[] = {2};
    assert(M_Search(A3, B3, 1) == 1); // Only one element, return 1

    int A4[] = {1, 2, 3, 4, 5};
    int B4[] = {6, 7, 8, 9, 10};
    assert(M_Search(A4, B4, 5) == 5); // Middle element is 5

    int A5[] = {1, 3, 5, 7};
    int B5[] = {2, 4, 6, 8};
    assert(M_Search(A5, B5, 4) == 4); // Middle element is 4

    // Edge case: Identical elements
    int A6[] = {1, 1, 1};
    int B6[] = {1, 1, 1};
    assert(M_Search(A6, B6, 3) == 1); // All elements are the same

    // Edge case: Arrays with negative numbers
    int A7[] = {-5, -3, -1};
    int B7[] = {-4, -2, 0};
    assert(M_Search(A7, B7, 3) == -3); // Middle element is -3

    // Edge case: Large numbers
    int A8[] = {1000000, 2000000, 3000000};
    int B8[] = {1500000, 2500000, 3500000};
    assert(M_Search(A8, B8, 3) == 2000000); // Middle element is 2000000
}

int main()
{
    run_tests();
    printf("All tests passed!\n");
    return 0;
}