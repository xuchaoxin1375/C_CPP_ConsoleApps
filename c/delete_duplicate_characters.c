#define _CRT_SECURE_NO_WARNINGS
/* 题目描述
输入一个长度不超过100的字符串,删除串中的重复字符。

输入要检查的字符串,长度不超过100个字符:abacaeedabcded.
输出删除重复字符后的字符串:abced.
样例输入saas
样例输出sa
 */
 //握手模型;最理想地输入的比较次数规模(1+2+..+n)地规模(类似勾股数枚举)

void print(char*);
#include <stdio.h>
#include <string.h>
int main()
{
	/**定义并初始化数组为0*/
	char a[100] = { 0 };
	int i, j;
	printf("input string to remove the duplicate characters:\n");
	gets(a);
	int len = strlen(a);
	/*遍历数组a*/
	for (i = 0; i < len; i++)
	{
		/*选定元素a[i],进行筛选标记
		每一次内部标记循环就可以保证原序列中只有一个a[i]元素*/
		const char tmp = a[i];
		/*利用标记-扫描法,将原来的数据处理/映射出新的形态*/
		if (tmp != -1)
		{
			/*利用另一个循环变量，衔接着a[i]索引之后的元素*/
			for (j = i + 1; j < len; j++)
			{
				if (tmp == a[j])
				{
					a[j] = -1;
				}
			}

		}
	}

	///*再次扫描循环，就可以打印/输出结果*/
	print(a);


}
/*to scan and print the result char array of handled*/
void print(char* a) {
	/*cyclic var*/
	int i = 0;
	int len = strlen(a);
	for (i = 0; i < len; i++) {
		if (a[i] != -1) {
			printf("%c", a[i]);
		}
	}
	/*if there are may times to test,give it a line break*/
	printf("\n");
}

