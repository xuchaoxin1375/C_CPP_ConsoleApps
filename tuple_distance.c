#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main()
{
    int A[] = {-1, 0, 9};
    int B[] = {-25, -10, 10, 11};
    int C[] = {2, 9, 17, 30, 41};
    int size_A = sizeof(A) / sizeof(A[0]);
    int size_B = sizeof(B) / sizeof(B[0]);
    int size_C = sizeof(C) / sizeof(C[0]);
    extern int td(int A[], int B[], int C[], int size_A, int size_B, int size_C);
    // extern int findMinofTrip(int A[], int n, int B[], int m, int C[], int p);
    extern int findMinofTrip(int A[], int B[], int C[], int n, int m, int p);
    int (*func)(int *, int *, int *, int, int, int);
    func = findMinofTrip;
    int distance = func(A, B, C, size_A, size_B, size_C);
    printf("distance=%d\n", distance);
    return 0;
}
/*
  算法复杂度：O(n^3)
  计算三个元组的最小距离，输出三个元组的最小距离的三个元素
 */
int td(int A[], int B[], int C[], int size_A, int size_B, int size_C)
{
    int distance = -1;
    int t1, t2, t3;

    for (int i = 0; i < size_A; i++)
    {
        for (int j = 0; j < size_B; j++)
        {
            for (int k = 0; k < size_C; k++)
            {
                int dist = abs(A[i] - B[j]) + abs(A[i] - C[k]) + abs(B[j] - C[k]);
                if (distance == -1)
                {
                    distance = dist;
                }
                if (dist < distance)
                {
                    distance = dist;
                    t1 = i;
                    t2 = j;
                    t3 = k;
                }
            }
        }
        /* code */
    }
    printf("(%d,%d,%d)\n", A[t1], B[t2], C[t3]);
    // printf("distance=%d\n", distance);
    return distance;
}

/* 
高效算法
 */

// #define INT_MAX 0x7fffffff // 该值在stdlib.h中定义一样
#define bool int
#define true 1
#define false 0

int abs_(int a)
{ // 计算绝对值
    if (a < 0)
        return -a;
    else
        return a;
}

bool xls_min(int a, int b, int c)
{ // a 是否是三个数中的最小值
    if (a <= b && a <= c)
        return true;
    return false;
}

/*
时间复杂度为O(n)
 */
int findMinofTrip(int A[], int B[], int C[], int n, int m, int p)
{
    // D_min 用于记录三元组的最小距离，初值赋为 INT_MAX
    int i = 0, j = 0, k = 0, D_min = INT_MAX, distance;

    while (i < n && j < m && k < p && D_min > 0)
    {
        distance = abs_(A[i] - B[j]) + abs_(B[j] - C[k]) + abs_(C[k] - A[i]); // 计算 D
        if (distance < D_min)
            D_min = distance; // 更新 D_min
        if (xls_min(A[i], B[j], C[k]))
            i++; // 更新 a
        else if (xls_min(B[j], C[k], A[i]))
            j++; // 更新 b
        else
            k++; // 更新 c
    }

    return D_min;
}