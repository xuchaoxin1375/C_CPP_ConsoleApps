#define _CRT_SECURE_NO_WARNINGS
/* ��Ŀ����
����һ�����Ȳ�����100���ַ���,ɾ�����е��ظ��ַ���

����Ҫ�����ַ���,���Ȳ�����100���ַ�:abacaeedabcded.
���ɾ���ظ��ַ�����ַ���:abced.
��������saas
�������sa
 */
 //����ģ��;�����������ıȽϴ�����ģ(1+2+..+n)�ع�ģ(���ƹ�����ö��)
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

/*ʧ�ܵĲʵ�*/

//for (i = 0; i < len; i++)
//{/*����򵥵��������:dd */
//	const char tmp = a[i];
//	for (j = i + 1; j < len; j++)
//	{
//		if (tmp == a[j])
//		{
//			for (int k = j; k < len - 1; k++)
//			{
//				a[k] = a[k + 1];/*Ҫע��:k+1<len(��˵k<=len-1)*/
//			}
//			len--;
//			j = i + 1;
//		}

//	}//for

//}//for
