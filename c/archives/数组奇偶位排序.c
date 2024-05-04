/*对一个数组奇数位和偶数位上的元素分别按照升序进行排序（共不超过100个数据）。
输入
一行以0为结束标记的若干数据
[注意：有效数据不包含最后的结束标记0,且要求输入的有效数据中也不包含整数0]
输出
排序之后的数据序列
样例输入
11 3 6 5 4 78 9 12 54 0
样例输出
4 3 6 5 9 12 11 78 54

tips:shell排序的一种特例(间距=2);可以化归为两个连续的数组分别进行排序,再交替打印(基数排序的发牌)
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void sort_char(int* num,int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int  min_index = i;
		for (int j = i + 1; j <= n - 1; j++)
		{
			if (num[min_index] > num[j])
			{
				min_index = j;
			}
		}
		/*swap*/
		int tmp = 0;
		if (min_index != i)
		{
			tmp = num[i];
			num[i] = num[min_index];
			num[min_index] = tmp;
		}
	}
}

int main()
{
	int input[100];	
	int i = 0;
	int num = 0;
	int tmp = 0;
	int odd[50], even[50];
	int k = 0,l = 0;
	for(i = 0,k = 0,l = 0;;i++)
	{
		scanf("%d", &tmp);
		if (!tmp)
		{
			break;
		}
		if (i % 2 == 0)
		{
			even[k++] = tmp;/*偶索引元素数组*/
		}
		else
		{
			odd[l++] = tmp;/*奇索引元素数组*/
		}
	}/*i-1当前数组的元素数目.*/

	sort_char(even, (i + 1) / 2);/*注意优先级*/
	sort_char(odd, i / 2);
	int j = 0;
	for ( j = 0,k = 0,l = 0;j < i; j++)
	{
		if (j % 2 == 0)
		{
			printf("%d ", even[k++]);
		}
		else
		{
			printf("%d ", odd[l++]);
		}
	}
	
}