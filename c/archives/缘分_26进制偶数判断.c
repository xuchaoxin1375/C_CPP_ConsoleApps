/*美妙的缘分
题目描述

说将两人的姓名拼音相加，如果是偶数，就表示两人八字相符，

也就是说，“缘分”呐—— 

姓名拼音都只要小写字符，且中间没有空格，a代表0, b代表1,依次类推，z代表25,...也就是说，26 进制
呐——，用小写英文表示的26进制加法，
想想都头疼呢！幸好你发现了，偶数嘛，很容易检测的哦。 
你来帮小胖写个程序，检测两个姓名是否匹配吧？

输入
每行两个姓名，姓名全部小写，中间空格隔开，0 0表示结束（两个0之间有一个空格）
输出
若匹配，输出Yes，否则输出No
样例输入
xiaopang yangjiaaimu 
xidada likeqiang
wuzhen lihao
0 0
样例输出
Yes
Yes
No
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main()
{
	const int n = 26;
	char sys_26[2][26];
	char name[2][30];
	/*制作26进制字典*/
	for (int i = 0; i < n; i++)
	{
		sys_26[0][i] = 'a' + i;
		sys_26[1][i] = i;
	}
	while (scanf("%s%s",name[0],name[1]) != EOF && name[0][0]-48 != 0)
	{
		/*发现每个名字只需要判断最后一个字母(最低位)对应的10进制的奇偶性即可(因为i*26^n(n>=1时)均必为偶数*/
		int sum = 0;
		const char chr_last_1 = name[0][strlen(name[0]) - 1];
		const char chr_last_2 = name[1][strlen(name[1]) - 1];
		for (int i = 0; i < n; i++)
		{
			if (chr_last_1 == sys_26[0][i])
			{
				sum += sys_26[1][i];
				
			}
			if (chr_last_2 == sys_26[0][i])
			{
				sum += sys_26[1][i];
			}
		}
	
		if (sum % 2 == 0)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}

/*彩蛋*/
/*void reverse(char* name,int n)
{
	char tmp;
	for (int i = 0; i < n/2; i++)
	{
		tmp = name[i];
		name[i] = name[n - 1 - i];
		name[n - 1 - i] = tmp;
	}

}*/