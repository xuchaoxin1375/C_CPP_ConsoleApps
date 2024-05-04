/*
 * @Description: 
 * @Version: 2.0
 * @Author: xuchaoxin
 * @Date: 2021-01-02 15:32:58
 * @LastEditors: xuchaoxin
 * @LastEditTime: 2021-01-02 16:36:25
 */


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//在此下方插入自定义函数的声明:
/**
 * @description: 
 * @param {int} a
 * @param {int} b
 * @param {int} c
 * @return {*}
 * @author: xuchaoxin
 */
void Multi(int a[][3], int b[][2], int c[][2]);
//主函数main
int main()
{

    int a[2][3], b[3][2], c[2][2];
    /* 两个二重循环读入数据 */
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
/* 调用执行矩阵计算的函数 */
    Multi(a, b, c);
    /* 将处理结果打印出来 */
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            /* 该行的最后一个元素索引是2,那就是在2之前的元素可以跟一个空格 */
            printf("%d", c[i][j]);
            if (j < 1)
            {
                printf(" ");
            }
        }
        //printf("%d\n");//发生了趣事:打印旧值
        printf("\n");
    }

    return 0;
}
//主函数结束.
//在下方编写自定义函数:
void Multi(int a[][3], int b[][2], int c[][2])
{

    /* mxk , kxn ;结果矩阵因该是mxn*/
    int m = 2; /* 矩阵A的行数 */
    int n = 2; /* 矩阵B的列数 */

    int p = 3; /* 矩阵A的列数必须和矩阵B的行数相同,该数值记为k */
    /* 结果矩阵的每一个元素值是一个k项式的和 */

    /* 记得用c中的元素累计值之前初始化c  */
    /* 由结果矩阵C的规格m*n可知,应该用连个循环来填充矩阵C而且行和列分别是m,n */
    for (int i = 0; i < m; i++) /* 控制行遍历(矩阵A的) */
    {
        for (int j = 0; j < n; j++) /* 控制列遍历(矩阵B的列) */
        {
            c[i][j] = 0;                //初始化累加计数器
            for (int k = 0; k < p; k++) /* k作为遍历元素的驱动器(为两个矩阵所共用(具体是,矩阵A横向遍历,矩阵B纵向遍历)) */
            {
                c[i][j] += a[i][k] * b[k][j]; //后者是b 矩阵
            }
        }
    }
}
