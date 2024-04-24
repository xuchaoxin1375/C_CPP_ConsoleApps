#define _CRT_SECURE_NO_WARNINGS
/*7进制小数的有效位
题目描述
假设有多个7进制表示的4位小数，请将之按照“3舍4入”的方式保留3位有效数字
［这里7进制的"3舍4入”类比于10进制的"4舍5入”，明白了吗？］
输入
多行7进制的四位小数。
输出
对应的3位有效位小数。
样例输入
0.6665
0.1234
0.1265
0.6531
样例输出
1.000
0.124
0.130
0.653
*/
#include <stdio.h>
#include <string.h>
int main()
{
	char str_7[10];
	int num_7[10] = { 0 };
	int n;
	//int j;
	while (scanf("%s", str_7) != EOF)
	{
		n = strlen(str_7);
		/*字符数组->整型数组*/
		for (int i = 0,j = 1; i < n; i++)
		{
			if (str_7[i] == '.')/*小数点后期额外打印.*/
			{
				continue;
			}
			num_7[j] = str_7[i] - 48;
			j++;
		}
		/*单独处理因四舍五入而进位的情况*/
		if (num_7[5] >= 4)
			{
				num_7[4]++;
				num_7[5] = 0;
			}
		/*处理满进制而进位的情况.*/
		for (int i = n-2; i > 0; i--)
		{
			if (num_7[i] > 6)
			{
				num_7[i - 1] ++;
				num_7[i] = 0;
			}
			else
			{
				break;
			}
		}
		
		if (!num_7[0])/*专门处理输入是6.666x (x>3)的情况.*/
		{}
		else
		{
			printf("%d", *num_7);
		}
		/*共同的部分:小数点额外打印,紧跟在num_7[1]之后打印*/
		printf("%d\.", num_7[1]);
		for (int i = 2; i < 5; i++)
		{
			printf("%d", num_7[i]);

		}
		printf("\n");
		
	}
}