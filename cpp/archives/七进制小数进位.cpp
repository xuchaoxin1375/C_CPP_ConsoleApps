#define _CRT_SECURE_NO_WARNINGS
/*7����С������Чλ
��Ŀ����
�����ж��7���Ʊ�ʾ��4λС�����뽫֮���ա�3��4�롱�ķ�ʽ����3λ��Ч����
������7���Ƶ�"3��4�롱�����10���Ƶ�"4��5�롱���������𣿣�
����
����7���Ƶ���λС����
���
��Ӧ��3λ��ЧλС����
��������
0.6665
0.1234
0.1265
0.6531
�������
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
		/*�ַ�����->��������*/
		for (int i = 0,j = 1; i < n; i++)
		{
			if (str_7[i] == '.')/*С������ڶ����ӡ.*/
			{
				continue;
			}
			num_7[j] = str_7[i] - 48;
			j++;
		}
		/*���������������������λ�����*/
		if (num_7[5] >= 4)
			{
				num_7[4]++;
				num_7[5] = 0;
			}
		/*���������ƶ���λ�����.*/
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
		
		if (!num_7[0])/*ר�Ŵ���������6.666x (x>3)�����.*/
		{}
		else
		{
			printf("%d", *num_7);
		}
		/*��ͬ�Ĳ���:С��������ӡ,������num_7[1]֮���ӡ*/
		printf("%d\.", num_7[1]);
		for (int i = 2; i < 5; i++)
		{
			printf("%d", num_7[i]);

		}
		printf("\n");
		
	}
}