/*实验六 串及其应用
串是零个或多个字符组成的有限序列，例如“”，“abcd”。其常见操作包括：串的查找、串的比较等。本实验实现串和它的一些相关应用。
（1）实验目的
（2）掌握串的常用操作，如：串的查找、串的比较等；
（3）掌握串的应用。
（4）实验内容
（5）串的实现
目标：定义一种串的数据结构类型，并实现其常用算法。
（6）算法填空：根据功能提示，完善下划线处的代码。
（7）串数据类型的定义
定义相应的结构体数据类型，用来表示串这一数据结构对象。*/

#define _CRT_SECURE_NO_WARNINGS
#define   EMPTY_QUEUE_ERROR   -999999
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLEN 100
/*整体串结构,与直接使用字符数组不同的是,串结构体可以直接读取它的长度,而且串结构中保存字符的数组中国'\0'不对串的长度产生印象,写入的length值是唯一串长值*/
typedef struct {
	char* ch;   // 用来存放串中字符的  动态数组
	int length;  // 记录串的长度
}MString;
/*（8）初始化串
在使用串之前，初始化其为一个空串。可以通过一个函数实现该操作，函数接收一个待初始化的串的地址作为参数。*/
void InitString(MString* s)
{
	/**********************************************************
	初始化s指向的串为空串
	*********************************************************/

	s->ch = 0;  // 设置串存储空间为空
	s-> length= 0;  // 设置串的长度为0：空串

	return;
}
/*（9）串赋值(或者叫清空旧串并赋予新串,
串赋值：给串 赋予一个新的  字符序列。*/
void AssignString(MString* s, char* cs)
{
	/**********************************************************
	把  cs指向的字符串  赋给s指向的串对象
	*********************************************************/
	int len = strlen(cs);

	if (s->length != len) { // 如果串空间与字符串大小不同，申请新空间
		if (s->length) { // 如果串的原有  空间非空，先要释放老空间
			free(s->ch);
		}
		s->ch = (char*)malloc(sizeof(char) * len); // 分配新的串存储空间
	}
	/*memcpy():内存拷贝函数，函数原型为void *memcpy(void *destin, void *source, unsigned n)；
	函数的功能是从源内存地址的起始位置开始  拷贝若干个字节  到目标内存地址中，即从源source中拷贝n个字节到目标destin中。*/
	memcpy(s->ch, cs, sizeof(char) * len); // 把字符串赋给串
		/*和realloc()比较下:
		realloc原型是extern 
		void *realloc(void *mem_address, unsigned int newsize);
		void *realloc(void *ptr, size_t size) 尝试重新调整之前调用 malloc 或 calloc 所分配的 ptr(即 mem_address) 所指向的内存块的大小
		语法: 指针名=（数据类型*）realloc（要改变内存大小的指针名，新的大小）。
新的大小可大可小（如果新的大小大于原内存大小，则新分配部分不会被初始化,原有的内容会得到保留(会被剪切粘贴到新内存空间)；如果新的大小小于原内存大小，可能会导致数据丢失*/
	
	s->length = len; // 设置串的长度
}
/*（10）比较串(相当于stringcmp()
给定两个串S和T。对于S > T、S = T、S < T，分别返回 正值、0、负值。
只需对齐,从头怼一趟即可*/
int CompareString(MString* S, MString* T)
{
	/**********************************************************
	比较S和T所指向的两个串
	*********************************************************/
	int i,
		//cmpSize_gt = ((S->length >= T->length ? S->length : T->length)),
		cmpSize = (S->length <= T->length ? S->length : T->length);/*cmpSize保存的时字符串S,T中  较小者的长度.*/

	// 1. 在两个串的范围内，由前往后，逐个比较S和T中的每个字符。
	// 若碰到某个字符不等：如果S中的该字符<T中的该字符，返回 S<T；否则返回S>T(对于S > T、S = T、S < T，分别返回 正值、0、负值。)
	{
		/*for (int i = 0; i < cmpSize_gt; i++)
		{}*/
			for (int i = 0; i < cmpSize; i++)
			{
				if (S->ch[i] < T->ch[i])
				{
					return S->ch[i] - T->ch[i];
				}
				else if(S->ch[i] > T->ch[i])
				{
					return S->ch[i] - T->ch[i];
				}
				else
				{
					/*pass*/
				}
			}
			return S->length - T->length;
		
	}

	// 2. 若在  两个串的范围内，对应字符均相等。则依据串的长度判定
	// 两个串的大小
	if (S->length == T->length)
		return 0;
	else if (S->length < T->length)
		return -1;
	else
		return 1;
}
/*（11）调试
使用上述操作，完成下面代码，运行并调试程序。*/
void main_1()
{
	MString s, t;  // 定义两个串对象

	// 1. 初始化定义的两个串对象
	{
		InitString(&s);
		InitString(&t);

	}

	// 2. 分别将“hello, string”和“ni hao, string”赋给s和t
	{
		AssignString(&s, "hello,string");
		AssignString(&t, "ni hao, string");
		
	}

	// 3. 比较两个串的大小，并输出比较结果：相等或谁大谁小
	{
		printf("分别将“hello, string”和“ni hao, string”赋给s和t:\n");
		int a = CompareString(&s, &t);
		if (a > 0)
		{
			printf("串S > T.\n");
		}
		else if (a == 0)
		{
			printf("串S = T.\n");
		}
		else
		{
			printf("串S < T.\n");
		}
	}


}
//（12）算法练习：根据功能提示，实现算法。
/*（13）获取串中字符
读取串中的某个字符。读取位置必须在串的长度范围之内，即[1, length]，length为串中字符序列的长度。函数原型如下：
*/
/**********************************************************
读取s指向的串中第i个位置处的字符
*********************************************************/
char StrAt(MString* s, int i)
{
	if (i<0 || i >s->length)
	{
		printf("非法读取:\n");
		exit(1);
	}
	return s->ch[i];
}


/*（14）获取子串
给定一个串，从其字符序列的某个位置开始，读取若干个字符，形成该串的一个子串。若读取成功，返回1；否则，返回0。函数原型如下：
*/
/**********************************************************
从第i个字符开始，从s指向的串中读取len个字符，形成一个子串，并
存储在sub指向的串中
*********************************************************/
void Print_string(MString* s)
{
	//printf("\n");
	for (int i = 0; i < s->length; i++)
	{
		putchar(s->ch[i]);
	}
	printf("\n");
}

int SubString(MString* sub, MString* s, int i, int len)/*i从1计数*/
{
	/*设i是从1计数*/
	if (i<1 || i + len -1 > s->length)
	{
		printf("获取起始位置非法:\n");
		return 0;
	}

	sub->length = len;
	sub->ch = (char*)malloc(len * sizeof(char));/*需要分配内存给串才能使用*/
	int j = 0;/*j是s串的第j个字符位置*/
	/*写函数最好在脑中有一个示意图:*/
	for ( j = i; j < i+len; j++)/* j<i+len 是由  j <= i+len-1 化简的*/
	{
		sub->ch[j - i] = s->ch[j-1];/*访问数组,位置参量-1*/
	}
	//Print_string(sub);该语句可用来监视朴素算法的查找过程.
	return i;
}
/*（15）合并字符串
给定两个串S1和S2。通过把S2中的字符序列追加在S1中的字符序列之后，合并两个串，并把合并后的字符序列放在新串T中。
算法实现提示：1）
检查串T的空间是否与合并后的字符序列个数相等。如不等，为T分配新的串空间；
2）依次把S1和S2中的字符序列拷贝到T的串空间中。函数原型如下：
*/
/**********************************************************
合并S1和S2所指向的两个串，并把   合并结果存储在T指向的串中
*********************************************************/
void ConcatString(MString* T, MString* S1, MString* S2)
{
	/*检查串T的空间是否与合并后的字符序列个数相等。如不等，为T分配新的串空间；
	因为传入的T可能是新的也可能是旧的.*/
	int ret = 0;
	//int sum_len_S12 = 0;
	ret = T->length == S1->length + S2->length;/*K&R*/
	T->length = S1->length + S2->length;
	if (!ret)
	{
		T->ch = (char*)malloc(sizeof(char) * T->length);
	}
	
	for (int i = 0; i < T->length; i++)
	{
		if (i < S1->length)
		{
			T->ch[i] = S1->ch[i];
		}
		else
		{
			T->ch[i] = S2->ch[i - S1->length];
		}
	}
}
/*（16）清空串
当串不再使用时，需要释放其中的动态数组内存，可通过如下函数实现：
*/
/**********************************************************
释放s指向的串的数组内存空间
*********************************************************/
void ClearString_temp(MString* s)/*请在此处改为ClearString()*/
{
	free(s->ch);
}

/*（17）调试
构建测试数据，在主函数中调用上述所有操作，运行并调试程序。*/
//(18)应用


/*（19）查找子串//朴素算法
定义两个串对象S和T，用户输入两个字符串，并分别赋给串S和T。
实现算法，从串S中的字符序列的某个指定位置开始，查找  与T相等的子串。
若查找成功，打印出第一个这样的子串在S中的位置，否则打印查找失败
。查找子串的算法可通过如下函数实现：
*/
/**********************************************************
从S指向的串的第i个字符开始，查找与T相等的子串。
若查找成功，返回第一个这样的子串在S中的位置；否则返回0
*********************************************************/

int SubIndex(MString* S, MString* T, int i)/*i从1计数*/
{
	
	int j;
	MString sub;/*这个串时Subindex()内部定义的,使用它的时候要&sub*/

	// 从串S中的第i个字符开始(j = i)，提取与串T长度相等的 子串；
	// 比较该子串是否与T相等。若相等，查找成功；
	// 否则，从第i+1个字符开始，继续提取子串并与T比较
// 反复上述操作，直到查找成功或子串提取失败为止
	InitString(&sub);

	for (j = i; j <= S->length; j++) {
		// 在串S中从第j个字符开始提取长度为T->length的子串
		// 并存储在串sub中
		if (!SubString(&sub,S,j,T->length)) { // 提取子串，若失败
			return 0;
		}
		if (CompareString(&sub,T) == 0) { // 比较提取的子串和串T，若相等
			return j;
		}
	}
	ClearString(&sub);

	return 0;
}
/*void Print_string(MString* s)
{
	//printf("\n");
	for (int i = 0; i < s->length; i++)
	{
		putchar(s->ch[i]);
	}
	printf("\n");
}*/
void Print_string(MString* s);
int SubIndex(MString* S, MString* T, int i);
int main_2()
{
	MString s, t,
		sub,
		str_cat;  // 定义串对象

	// 1. 初始化定义的两个串对象

	InitString(&s);
	InitString(&t);
	InitString(&sub);//定数据结构的同时(使用前)要伴随初始化,否则会出错;

	// 2. 分别将“hello, string”和“ni hao, string”赋给s和t

	/*
	printf("分别将“hello, string”和“ni hao, string”赋给s和t:\n");
	AssignString(&s, "hello,string");	AssignString(&t, "ni hao, string");*/
	printf("分别将\"nia1123o\"和\"12\"赋给s和t:\n");
	AssignString(&s, "nia1123o");	AssignString(&t, "12");

/*
	printf("测试AssignString():\n");
	Print_string(&s);
	Print_string(&t);

	
	printf("测试StrAt(&s, 4);\n");
	putchar(StrAt(&s, 4)); printf("\n");

	printf("测试SubString(&sub, &s, 3, 4);\n");
	SubString(&sub, &s, 3, 4);
	Print_string(&sub);

	printf("测试ConcatString(&str_cat, &s, &t):\n");
	ConcatString(&str_cat, &s, &t);
	Print_string(&str_cat);
*/	
	/**/
	printf("测试SubIndex(&s, &t, 1):\
		\n第%d个位置出现第一个子串.(0表示没有子串)\n", SubIndex(&s, &t, 1));
		/*从S指向的串的第i个字符开始，查找与T相等的子串。若查找成功，返回第一个这样的子串在S中的位置；否则返回0*/
	

}
/*上述的子串查找算法时间复杂度并不是最优的，会存在较多的字符重复比较。
KMP（Knuth - Morris - Pratt）算法是一种高效的字符串匹配算法，查询相关资料，理解并尝试实现该算法。
（20）综合练习
实现一个简单的打字练习程序。基本要求如下：
（21）从文本文件中读取参考文本内容，并存储在一个串对象中；
（22）构建一个简单的可交互系统，要求：
（23）参考文本内容隔行显示；
（24）从上到下，用户根据显示的每行参考文本，输入正确的字符（若输入错误，系统可提示）；
（25）用户输入的每行字符显示在对应的参考文本行的下面；
每次练习完成后，统计并打印出练习的正确率。
*/

#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;	/* ElemType类型根据实际情况而定，这里假设为int */

typedef char String[MAXSIZE + 1]; /*  0号单元存放串的长度 */

/* 生成一个其值等于chars的串T */
Status StrAssign(String T, char* chars)
{
	int i;
	if (strlen(chars) > MAXSIZE)
		return ERROR;
	else
	{
		T[0] = strlen(chars);
		for (i = 1; i <= T[0]; i++)
			T[i] = *(chars + i - 1);
		return OK;
	}
}

Status ClearString(String S)
{
	S[0] = 0;/*  令串长为零 */
	return OK;
}

/*  输出字符串T。 */
void StrPrint(String T)
{
	int i;
	for (i = 1; i <= T[0]; i++)
		printf("%c", T[i]);
	printf("\n");
}

/*  输出Next数组值。 */
void NextPrint(int next[], int length)
{
	int i;
	for (i = 1; i <= length; i++)
		printf("%d", next[i]);
	printf("\n");
}

/* 返回串的元素个数 */
int StrLength(String S)
{
	return S[0];
}

/* 朴素的模式匹配法 */
int Index(String S, String T, int pos)
{
	int i = pos;	/* i用于主串S中当前位置下标值，若pos不为1，则从pos位置开始匹配 */
	int j = 1;				/* j用于子串T中当前位置下标值 */
	while (i <= S[0] && j <= T[0]) /* 若i小于S的长度并且j小于T的长度时，循环继续 */
	{
		if (S[i] == T[j]) 	/* 两字母相等则继续 */
		{
			++i;
			++j;
		}
		else 				/* 指针后退重新开始匹配 */
		{
			i = i - j + 2;		/* i退回到上次匹配首位的下一位 */
			j = 1; 			/* j退回到子串T的首位 */
		}
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}

/* 通过计算返回子串T的next数组。 */
void get_next(String T, int* next)
{
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i < T[0])  /* 此处T[0]表示串T的长度 */
	{
		if (j == 0 || T[i] == T[j]) 	/* T[i]表示后缀的单个字符，T[j]表示前缀的单个字符 */
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];	/* 若字符不相同，则j值回溯 */
	}
}

/* 返回子串T在主串S中第pos个字符之后的位置。若不存在，则函数返回值为0。 */
/*  T非空，1≤pos≤StrLength(S)。 */
int Index_KMP(String S, String T, int pos)
{
	int i = pos;		/* i用于主串S中当前位置下标值，若pos不为1，则从pos位置开始匹配 */
	int j = 1;			/* j用于子串T中当前位置下标值 */
	int next[255];		/* 定义一next数组 */
	get_next(T, next);	/* 对串T作分析，得到next数组 */
	while (i <= S[0] && j <= T[0]) /* 若i小于S的长度并且j小于T的长度时，循环继续 */
	{
		if (j == 0 || S[i] == T[j]) 	/* 两字母相等则继续，与朴素算法增加了j=0判断 */
		{
			++i;
			++j;
		}
		else 			/* 指针后退重新开始匹配 */
			j = next[j];/* j退回合适的位置，i值不变 */
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}

/* 求模式串T的next函数修正值并存入数组nextval */
void get_nextval(String T, int* nextval)
{
	int i, j;
	i = 1;
	j = 0;
	nextval[1] = 0;
	while (i < T[0])  /* 此处T[0]表示串T的长度 */
	{
		if (j == 0 || T[i] == T[j]) 	/* T[i]表示后缀的单个字符，T[j]表示前缀的单个字符 */
		{
			++i;
			++j;
			if (T[i] != T[j])      /* 若当前字符与前缀字符不同 */
				nextval[i] = j;	/* 则当前的j为nextval在i位置的值 */
			else
				nextval[i] = nextval[j];	/* 如果与前缀字符相同，则将前缀字符的 */
											/* nextval值赋值给nextval在i位置的值 */
		}
		else
			j = nextval[j];			/* 若字符不相同，则j值回溯 */
	}
}

int Index_KMP1(String S, String T, int pos)
{
	int i = pos;		/* i用于主串S中当前位置下标值，若pos不为1，则从pos位置开始匹配 */
	int j = 1;			/* j用于子串T中当前位置下标值 */
	int next[255];		/* 定义一next数组 */
	get_nextval(T, next);	/* 对串T作分析，得到next数组 */
	while (i <= S[0] && j <= T[0]) /* 若i小于S的长度并且j小于T的长度时，循环继续 */
	{
		if (j == 0 || S[i] == T[j]) 	/* 两字母相等则继续，与朴素算法增加了j=0判断 */
		{
			++i;
			++j;
		}
		else 			/* 指针后退重新开始匹配 */
			j = next[j];/* j退回合适的位置，i值不变 */
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}

int main_3_kmp()
{
	int i, * p;
	String s1, s2;

	StrAssign(s1, "abcdex");
	printf("子串为: ");
	StrPrint(s1);
	i = StrLength(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	get_next(s1, p);
	printf("Next为: ");
	NextPrint(p, StrLength(s1));
	printf("\n");

	StrAssign(s1, "abcabx");
	printf("子串为: ");
	StrPrint(s1);
	i = StrLength(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	get_next(s1, p);
	printf("Next为: ");
	NextPrint(p, StrLength(s1));
	printf("\n");

	StrAssign(s1, "ababaaaba");
	printf("子串为: ");
	StrPrint(s1);
	i = StrLength(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	get_next(s1, p);
	printf("Next为: ");
	NextPrint(p, StrLength(s1));
	printf("\n");

	StrAssign(s1, "aaaaaaaab");
	printf("子串为: ");
	StrPrint(s1);
	i = StrLength(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	get_next(s1, p);
	printf("Next为: ");
	NextPrint(p, StrLength(s1));
	printf("\n");

	StrAssign(s1, "ababaaaba");
	printf("   子串为: ");
	StrPrint(s1);
	i = StrLength(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	get_next(s1, p);
	printf("   Next为: ");
	NextPrint(p, StrLength(s1));
	get_nextval(s1, p);
	printf("NextVal为: ");
	NextPrint(p, StrLength(s1));
	printf("\n");

	StrAssign(s1, "aaaaaaaab");
	printf("   子串为: ");
	StrPrint(s1);
	i = StrLength(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	get_next(s1, p);
	printf("   Next为: ");
	NextPrint(p, StrLength(s1));
	get_nextval(s1, p);
	printf("NextVal为: ");
	NextPrint(p, StrLength(s1));

	printf("\n");

	StrAssign(s1, "00000000000000000000000000000000000000000000000001");
	printf("主串为: ");
	StrPrint(s1);
	StrAssign(s2, "0000000001");
	printf("子串为: ");
	StrPrint(s2);
	printf("\n");
	printf("主串和子串在第%d个字符处首次匹配（朴素模式匹配算法）\n", Index(s1, s2, 1));
	printf("主串和子串在第%d个字符处首次匹配（KMP算法） \n", Index_KMP(s1, s2, 1));
	printf("主串和子串在第%d个字符处首次匹配（KMP改良算法） \n", Index_KMP1(s1, s2, 1));

	return 0;
}

