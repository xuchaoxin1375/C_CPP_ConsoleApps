#define _CRT_SECURE_NO_WARNINGS
/* ��Ŀ����
����һ�����Ȳ�����100���ַ���,ɾ�����е��ظ��ַ���

����Ҫ�����ַ���,���Ȳ�����100���ַ�:abacaeedabcded.
���ɾ���ظ��ַ�����ַ���:abced.
��������saas
�������sa
 */
 //����ģ��;�����������ıȽϴ�����ģ(1+2+..+n)�ع�ģ(���ƹ�����ö��)

void print(char*);
#include <stdio.h>
#include <string.h>
int main()
{
	/**���岢��ʼ������Ϊ0*/
	char a[100] = { 0 };
	int i, j;
	printf("input string to remove the duplicate characters:\n");
	gets(a);
	int len = strlen(a);
	/*��������a*/
	for (i = 0; i < len; i++)
	{
		/*ѡ��Ԫ��a[i],����ɸѡ���
		ÿһ���ڲ����ѭ���Ϳ��Ա�֤ԭ������ֻ��һ��a[i]Ԫ��*/
		const char tmp = a[i];
		/*���ñ��-ɨ�跨,��ԭ�������ݴ���/ӳ����µ���̬*/
		if (tmp != -1)
		{
			/*������һ��ѭ���������ν���a[i]����֮���Ԫ��*/
			for (j = i + 1; j < len; j++)
			{
				if (tmp == a[j])
				{
					a[j] = -1;
				}
			}

		}
	}

	///*�ٴ�ɨ��ѭ�����Ϳ��Դ�ӡ/������*/
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

