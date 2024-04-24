#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
int main()
{
	int a = 0;
	float b = 0;
	a = 10 / 3.2;
	b = 10 / 3.2;
	printf("整型变量保存浮点型数:\n");
	printf("a = %d\n", a);
	printf("b = %f\n",b);
	
	printf("%%d打印浮点型数b:%d\n", b);

	printf("%%f打印整型数a:%f\n",a);

}
/*结果
整型变量保存浮点型数:
a = 3
b = 3.125000
%d打印浮点型数b:0
%f打印整型数a:0.000000
*/