#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
int main()
{
	int a = 0;
	float b = 0;
	a = 10 / 3.2;
	b = 10 / 3.2;
	printf("���ͱ������渡������:\n");
	printf("a = %d\n", a);
	printf("b = %f\n",b);
	
	printf("%%d��ӡ��������b:%d\n", b);

	printf("%%f��ӡ������a:%f\n",a);

}
/*���
���ͱ������渡������:
a = 3
b = 3.125000
%d��ӡ��������b:0
%f��ӡ������a:0.000000
*/