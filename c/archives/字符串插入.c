/*字符串插入操作
题目描述
输入两个字符串，第一个己经按从小到大（ASCII码值）的顺序排列好了。编写程序，将第二个字符串插 入到第一个字符串中，使得插入后的字符串仍然是按照ASCII码值从小到大顺序排列起来。
输入
多组输入数据，每行的两个字符串以空格相间隔。 

［要求第一个字符串己从小到大排序，但是第二个字符串不一定有序。］
输出
每行为一个合并在一起的有序（按ASCII码值升序）的字符串。
样例输入
123 654 acd bde
样例输出
123456 abcdde
提示
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char str1[100]/*有序*/, str2[100]/*有序性未知*/;
	while (scanf("%s%s", str1, str2) != EOF)/*scanf_s(读入两个%s就会出错)*/
	{
		/*可以用strcat合并字符串,再统一排序,最为简便.*/
		/*也可以用插入法插入到正确的位置,但注意要调整位置.*/
		int len_1 = 0,len_2 = 0;
		len_1 = strlen(str1);
		len_2 = strlen(str2);

		strcat(str1, str2);
		/*确定待插入排序范围*/
		for (int i = len_1; i < len_1+len_2;i++)
		{
			int const tmp = str1[i];/*本轮的待插入元素.*/
			/*将str2中的元素插入到str1中*/
			int j = i;
			for (; j >= 1 && tmp < str1[j - 1]; j--)
			{
				str1[j] = str1[j - 1];/*前一个元素盖到当前位置上str1[j-1] -> str1[j]*/
			}
			str1[j] = tmp;
		}
		/*打印结果:*/
		printf("%s\n", str1);
	}
}