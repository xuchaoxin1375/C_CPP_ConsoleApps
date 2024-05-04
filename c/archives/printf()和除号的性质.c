
#include<stdio.h>
int main()
{
	/*整除号:int/int*/
	printf("%d\n", -3 / 2);//打印-1;
	printf("%d\n", -3 / 7);//打印:0;
	/*强制类型转化为(int) 可将实数提取整数部分处理(对负数向上取整,对正数向下取整)*/
	printf("%d\n", (int)1.7);//打印1;
	printf("%d\n", (int)-1.4 / 1);//打印-1
	printf("%d\n", (int)-1.7 / 1);//打印-1
	/*浮点除:float/float或者int/float或float/int..,总之,int/int之外的都隐式转化为浮点除法.
	printf("%d\n", -1.4 / 1);//乱数字
	printf("%d\n", 1.4 / 1);//乱数字
	*/
	//printf("%%d\n");/*使用printf()打印%号要打%%而非\% */
	/*乱数字:*/
	/*
-1.4%d:1717986918       0.000000
1.4%d:1717986918        0.000000
1.4%f   1.400000  
	printf("-1.4%%d:%d\t%f\n", -1.4);
	printf("1.4%%d:%d\t%f\n", 1.4);
	printf("1.4%%f\t%f\n", 1.4);*/


}