/*�����Ե��
��Ŀ����

˵�����˵�����ƴ����ӣ������ż�����ͱ�ʾ���˰��������

Ҳ����˵����Ե�֡��š��� 

����ƴ����ֻҪСд�ַ������м�û�пո�a����0, b����1,�������ƣ�z����25,...Ҳ����˵��26 ����
�š�������СдӢ�ı�ʾ��26���Ƽӷ���
���붼ͷ���أ��Һ��㷢���ˣ�ż��������׼���Ŷ�� 
������С��д�����򣬼�����������Ƿ�ƥ��ɣ�

����
ÿ����������������ȫ��Сд���м�ո������0 0��ʾ����������0֮����һ���ո�
���
��ƥ�䣬���Yes���������No
��������
xiaopang yangjiaaimu 
xidada likeqiang
wuzhen lihao
0 0
�������
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
	/*����26�����ֵ�*/
	for (int i = 0; i < n; i++)
	{
		sys_26[0][i] = 'a' + i;
		sys_26[1][i] = i;
	}
	while (scanf("%s%s",name[0],name[1]) != EOF && name[0][0]-48 != 0)
	{
		/*����ÿ������ֻ��Ҫ�ж����һ����ĸ(���λ)��Ӧ��10���Ƶ���ż�Լ���(��Ϊi*26^n(n>=1ʱ)����Ϊż��*/
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

/*�ʵ�*/
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