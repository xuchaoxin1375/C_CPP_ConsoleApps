/*��һ����������λ��ż��λ�ϵ�Ԫ�طֱ�������������򣨹�������100�����ݣ���
����
һ����0Ϊ������ǵ���������
[ע�⣺��Ч���ݲ��������Ľ������0,��Ҫ���������Ч������Ҳ����������0]
���
����֮�����������
��������
11 3 6 5 4 78 9 12 54 0
�������
4 3 6 5 9 12 11 78 54

tips:shell�����һ������(���=2);���Ի���Ϊ��������������ֱ��������,�ٽ����ӡ(��������ķ���)
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
			even[k++] = tmp;/*ż����Ԫ������*/
		}
		else
		{
			odd[l++] = tmp;/*������Ԫ������*/
		}
	}/*i-1��ǰ�����Ԫ����Ŀ.*/

	sort_char(even, (i + 1) / 2);/*ע�����ȼ�*/
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