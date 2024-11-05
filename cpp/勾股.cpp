/*
 * @Description:
 * @Version: 2.0
 * @Author: xuchaoxin
 * @Date: 2020-10-11 18:37:04
 * @LastEditors: xuchaoxin
 * @LastEditTime: 2021-01-02 20:57:55
 */
/*试通过程序设计求指定区间［a,b］内的所有勾股数组。
输入
输入两个正整数a, b (a<b).
输出
输出［a,b］区间内的所有勾股数组。
样例输入
30, 90
样例输出

*/
// #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
    int a, b;
    int x, y, z, d;

    // printf("请输入区间[a,b]的上下限a,b:");
	printf("please use a comma to as a separator the two integer:\n");
	scanf("%d,%d", &a, &b); // 如果里面有逗号,输入时a,b以逗号隔开而非默认的空格
	
    // 动手画图最重要;//下一轮的遍历的起点相较于与上一轮右移了一位.(当然,同一轮的遍历中,第一个数是固定的)

    /*不妨设x>y;勾股数中a,b不可能相等(根号2)故可以发现,如果x=y=k,则z=double sqrt(2)*k,即此时的z不是整数,故不需考虑*/
    for (x = a; x <= b - 2; x++)
    { // 外层控制x;另外,区间里的后两个数没必要有求平方和!(此时的z必在b后)
        for (y = x + 1; y <= b - 1; y++)
        { // 内层控制y

            d = x * x + y * y;

            z = sqrt(d); // 开方函数sqrt(),发生取整,如果有小数部分,将会丢失,即此时z*z < d
            if (z > b)   // 此时的y对于当前的x已经过大,测试下一个x,并重置y(=x+1)
                break;
            // 跳到上一重循环里.(测试下一个x下的新情况)
            /*若没有过大:下面的if()可以内嵌到if(z>b){里}*/
            if (z * z == d) // 说明之前的d能够刚好开方
            {

                // 把当前的x,y,z三元组打印出来.
                printf("%d^2+%d^2=%d^2\n", x, y, z);
            }
        } // for
    } // for
}

