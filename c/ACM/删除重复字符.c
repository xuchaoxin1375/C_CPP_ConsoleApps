#define _CRT_SECURE_NO_WARNINGS
/* 题目描述
输入一个长度不超过100的字符串,删除串中的重复字符。

输入要检查的字符串,长度不超过100个字符:abacaeedabcded.
输出删除重复字符后的字符串:abced.
样例输入saas
样例输出sa
 */
 //握手模型;最理想地输入的比较次数规模(1+2+..+n)地规模(类似勾股数枚举)
#include <stdio.h>
#include <string.h>
int main()
{
	//int a[100] = { 0 };
	char a[100] = { 0 };
	int i, j;
	
	gets(a);
	int len = strlen(a);



	for (i = 0; i < len; i++)
	{
		
		const char tmp = a[i];
		if (tmp != -1)
		{
			for (j = i + 1; j < len; j++)
			{
				if (tmp == a[j])
				{
					a[j] = -1;
				}
			}

		}
	}
	for (int i = 0; i < len; i++)
	{
		if (a[i] != -1)
		{
			printf("%c", a[i]);
		}
	}
	printf("\n");
}

/*失败的彩蛋*/

//for (i = 0; i < len; i++)
//{/*用最简单的输入测试:dd */
//	const char tmp = a[i];
//	for (j = i + 1; j < len; j++)
//	{
//		if (tmp == a[j])
//		{
//			for (int k = j; k < len - 1; k++)
//			{
//				a[k] = a[k + 1];/*要注意:k+1<len(或说k<=len-1)*/
//			}
//			len--;
//			j = i + 1;
//		}

//	}//for

//}//for
