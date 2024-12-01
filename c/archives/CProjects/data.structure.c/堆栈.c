/*实验三 堆栈及其应用
堆栈是一种操作受限制的线性列表，堆栈的插入与删除只能在一端进行。栈的修改是按“先进后出”的原则进行的，因此栈又称为“先进后出”的线性表。本实验实现堆栈和它的一些相关应用。
（1）实验目的
（1）熟练掌握栈的结构，以及这种数据结构的特点；
（2）能够在两种存储结构上实现栈的基本运算；
（3）使用栈解决实际问题；
（2）实验内容
（1）栈的基本实现
目标：定义一个可存储整型数据的顺序栈，并实现栈的常用操作。
*/
/*定义相应的结构体类型，用来表示堆栈这一数据结构对象。
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLEN 100

typedef struct {
	/*附设指针top指示 栈顶元素 在顺序栈中的位置,栈顶的位置随着进栈和退栈操作而变化*/
	int elem[MAXLEN];    // 用来存栈数据元素的数组
	int top;               // 指示栈顶位置的标识量
}intStack;/*精髓在于只通过栈顶指针来访问顺序表的元素
		  值得注意的是,栈是否为空(栈中元素数目)与数组里的元素并不直接相关,栈顶标识量之后的数组
		  元素不算是栈中的元素尽管还在数组中,却不在栈中了*/
		  /*
		  (2）栈的初始化
		  栈在使用之前，必须对其结构体中的成员变量赋初值，称为初始化，通过函数来实现。
		  栈的初始化针对栈的某一具体实例进行操作，因此需将该实例在内存中的  地址作为初始化函数的 参数。
		  */
void  InitStack(intStack* pStack) // 指针类型作为形参，某个栈实例的地址
{
	/**********************************************************
	1、该栈实例存储数据元素的空间是否已分配好？若没有分配，需在  此分配空间(即malloc)。本例使用数组elem存储数据，空间预先已分配，
	故无需额外操作。
	*********************************************************/
	// nothing to do in this case

	/**********************************************************
	将该栈实例的栈顶标识量置为0，表达两层含义：（a）栈顶在数组的  0 号位置；(b)栈当前数据元素个数为零。
	*********************************************************/
	pStack->top = 0;
}
/*
（3）判断栈是否为空？是否已满？
在栈的使用过程中，经常需要判断栈为空或满，栈为空的时候无法出栈，栈已满时无法入栈。*/
int  IsEmpty(intStack* pStack) // 指针类型作为形参，某个栈实例的地址
{
	/**********************************************************
	栈为空时返回1，否则返回0
	*********************************************************/
	if (pStack->top == 0)
		return  1;
	else
		return 0;
}
/*判断顺序栈是否栈满,只需与定义时的数组长度比较*/
int  IsFull(intStack* pStack) //指针类型作为形参，某个栈实例的地址
{
	/**********************************************************
	栈中数据元素个数为MAXLEN时返回1，否则返回0
	*********************************************************/
	if (pStack->top == MAXLEN)
		return  1;
	else
		return 0;
}
/*（4）入栈
将某数据元素x入栈，成功返回1，失败返回0*/
int  Push(intStack* pStack, int x)
{
	/**********************************************************
	1、若该栈实例已满，则入栈失败
	*********************************************************/
	if (IsFull(pStack))
		return 0;

	/**********************************************************
	2、若该栈不满，则将x写入该栈的栈顶位置，然后栈顶位置后移
	*********************************************************/
	pStack->elem[pStack->top] = x;    // x入栈
	pStack->top++;    // 栈顶后移
	return 1;
}
/*（5）出栈
若栈中有数据，则将栈顶位置数据元素返回；
否则，返回一个特殊的标识量，该标识量应该不可能在栈数据中出现，
以免无法判断返回的是正常的数据元素还是表示出错。
*/
#define   EMPTY_STACK_ERROR   -999999
int  Pop(intStack* pStack)/*只弹出栈顶(删除栈顶元素)*/
{
	/**********************************************************
	1、若该栈为空，则输出出错信息，并返回出错标识量
	*********************************************************/
	if (IsEmpty(pStack))/*判断栈空也可以直接if(pStack->top == 0)而不调用isEmpty()*/
	{
		printf("\n");
		printf("stack has been empty !can’t pop data from empty stack!\n");
		return EMPTY_STACK_ERROR;
	}

	/**********************************************************
	2、若该栈不为空，则将栈顶标识量后移，并返回栈顶元素
	*********************************************************/
	pStack->top--;     //栈顶标识量后移(倒退)
	return pStack->elem[pStack->top];     //返回栈顶位置数据元素
}
/*（2）算法练习：根据功能提示，实现算法。
*/
/*（6）返回栈顶数据元素，但该数据不出栈
在某些情况下，我们需要知道栈顶数据元素的值，但不需要将该元素出栈，试写出该操作的函数。
注意区分栈中有数据和没数据两种情况。函数原型如下：
*/
/**********************************************************
 获取s指向的堆栈的栈顶元素
*********************************************************/
int GetTop(intStack* s)
{
	if (IsEmpty(s))
	{
		return EMPTY_STACK_ERROR;
	}
	return s->elem[s->top - 1];
}
/*（7）清空栈
将栈清空，所有栈中数据作废。函数原型如下：*/
/**********************************************************
 清空s指向的堆栈
*********************************************************/
void  Clear(intStack* s)
{
	s->top = 0;
}
/*（8）调试
根据上述栈的定义，完成下面代码，运行并调试程序。*/
/*
void main()
{
	intStack s; // 定义一个栈的实例s
	int e;

	// 1. 初始化该栈

	InitStack(&s);

	// 2. 往栈中push三个整数10，20,  30
	printf("测试push():往栈中push三个整数10，20,  30 :\n");
	Push(&s, 10);
	Push(&s,20);
	Push(&s,30);

	// 3. 将s中的数据pop出栈，并输出，直到出栈数据有误为止
	printf("将s中的数据pop出栈，并输出，直到出栈数据有误为止:\n");
	while (  ( e = Pop(&s) ) != EMPTY_STACK_ERROR )
	{

		printf("%d ",e);

	}
}
*/
/*
（3）思考
（1）通用的数据堆栈
上述实现的栈只能用来保存整型数据，如果想要处理其他类型的数据，该做怎样的修改？
（2）动态分配空间的栈
上述实现的是一个用静态数组作为数据存储空间的栈，当入栈数据量超过其最大容量时，该栈不能正常工作。因此，我们希望将存储空间改为动态存储空间，当空间不足时，自动将空间扩大。这时，堆栈数据结构类型可以定义如下：
*/
//
//typedef struct {
//    int* pElem;     // 用来保存动态空间的地址
//    int top;         // 指示栈顶位置的标识量
//    int size;        // 动态空间当前长度的标识量
//}intStack;
//初始化时，为堆栈开辟一个固定大小的数组空间。当入栈时，如果存储空间已满，则重新开辟一个更大的数组空间（通常为原空间的两倍大小），把原数组空间中存储的元素拷贝到新数组空间中，并用新数组空间代替原数组空间作为堆栈的存储空间。尝试实现基于动态数组的堆栈及其常用算法。
//（3）链栈
//无论是使用数组还是动态分配，都需要保留一块连续空间。当栈所需存储的数据量未知时，这两种方式的栈在使用上都不够灵活。而采用链栈，能克服上述缺点。链栈是用链式形式来存储栈数据的栈，可以看做一种特殊形式的链表，两者的联系和区别如下所述：
//1）链栈是没有专用头结点的特殊链表；
//2）栈中的数据分别存储于链表中的每一个结点中，栈顶指针指向当前栈顶结点，相应于链表的头指针。
//3）入栈相当于在链表的头部插入结点；
//4）出栈相当于将当前链表的头结点移除；
//5）当栈顶指针为空时，栈为空；
//6）一般情况下，不需要考虑栈满的状态；
//请根据以上描述，实现一个链栈。并思考一下，当用链栈来解决下面部分的应用时，跟前两种方式实现的堆栈有无区别？


//（1）堆栈的应用
//目标：应用堆栈解决实际问题。在应用堆栈时，需要在相关应用的源代码前包含前述部分中栈的实现代码。
//（1）利用栈将一个整数序列逆序输出
/*
因栈有“先进后出”的特点，可将整数序列先全部压入栈，然后逐一出栈并输出。
整数序列以数组的形式存储，该数组作为函数参数，序列中数据的个数n亦作为参数。*/
void  ReverseData(int* a, int n) // 形参接收一个整数数组
{
	intStack s;  // 定义一个栈变量实例s
	int e;

	// 使用之前需要初始化该栈s
	InitStack(&s);

	// 循环遍历该整数序列(将传入的数组a里的数据压入堆栈)，将所有数据入栈
	for (int i = 0; i < n; i++)
	{
		Push(&s, a[i]);
	}

	// 循环调用Pop函数将数据出栈，保存到e中，并printf输出e，直        // 到Pop出错为止
	while ((e = Pop(&s)) != EMPTY_STACK_ERROR)
	{
		printf("%d ", e);

	}
	printf("\n");

}

// 测试， 使用实际例子测试上述函数是否正常工作
/*
void main()
{
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	printf(" 调用ReverseData(a,10);输入a[10] = { 0,1,2,3,4,5,6,7,8,9 }:\n");
	ReverseData(a,10);  // 调用ReverseData函数
}*/
//（2）利用栈实现八进制转换
/*编写一个函数，将一个十进制整数转换为八进制形式输出。比如输入十进制的“10”，该函数输出“12”。*/
void  ConvertOCT(int n)
{
	intStack s; // 定义一个栈变量实例s
	int e;

	// 使用之前需要初始化该栈s
	InitStack(&s);

	// 循环：若该整数不为零，则将其整除8的余数入栈，同时将该整
	// 数值赋值为整除8之后的倍数
	while (n)
	{
		Push(&s, n % 8);
		n = n / 8;
	}

	// 循环：Pop出栈一个数据到e，若e为正常数据，printf输出e
	while ((e = Pop(&s)) != EMPTY_STACK_ERROR)
	{
		printf("%d", e);
	}

}
// 测试， 使用实际例子测试上述函数是否正常工作
/*
void main()
{

	// 调用ConvertOCT函数，输出10，100等数据的八进制数
	printf("调用ConvertOCT函数，输出10，100等数据的八进制数:\n");
	int n = 0;
	printf("输入要转换的十进制数:\n");
	while (scanf("%d",&n) != EOF)
	{
		ConvertOCT(n);
		printf("输入要转换的十进制数:\n");
	}
}
*/
//思考：将此函数改写，使之可以输出十进制整数的十六进制数据形式。
/*(3）括号匹配
利用栈编写满足下列要求的括号匹配检验程序：
假设表达式中允许包含两种括号：
圆括号和方括号，其嵌套的顺序随意，即
([]()) 或[([][])]等为正确的格式，
[(]或([())或(()]) 均为不正确的格式。
	输入一个包含上述括号的表达式，检验括号是否配对。
*/
void check() // 对于输入的任意一个字符串，检验括号是否配对
{
	intStack s; // 定义一个栈变量实例s(保存左括号的栈)
	char str[80],
		* p,/*p是输入表达式的指针*/
		e;

	// 使用之前需要初始化该栈s
	InitStack(&s);

	printf("请输入表达式\n");/*将输入读入到字符数组中*/
	int i = 0;
	while (scanf("%c", &str[i]) != EOF && i < (80-1))
	{
		i++;//到达下一个新的,未被读入数据的位置
	}
	str[i] = '\0';/*额外补丁,结束字符串,以便能够使下面的while(*p)可以结束 */

	/*根据输入的字符数组作相应的入栈/出栈操作(switch+if);
	虽然这里的栈用的使int 类型的数组,但是,scanf()读入的时字符的Ascii码,作比较时 字符表达'(' 也是比较AScii码,不影响判读匹配结论*/
	p = str;/*从表达式数组的头元素开始,同时辅助指针p可以顺着str数组顺畅访问所有元素*/
	while (*p) // 没到串尾
	{
		switch (*p)
		{
			// 若是左括号，则入栈，且p++
		case '(':
			Push(&s, *p);
			p++;
			break;
		case '[':
			Push(&s, *p);
			p++;
			break;

			// 若是右括号,则弹出栈顶元素，保存到e
		case ')':
			/*弹出左括号栈s的栈顶元素,与当前的右括号作比较,看是否匹配*/
			e = Pop(&s);
			{
				if (e != EMPTY_STACK_ERROR)
				{
					if (e == '(')/*如果匹配成功,继续处理下一个输入的字符*/
					{
						p++;
					}
					else
					{
						printf("匹配失败\n");
						exit(1);
					}
				}
			}
			break;

		case ']':
			e = Pop(&s);
			// 若出栈正常，则判断此时的右括号(即*p) 与 e 是否匹配。若不匹配，则 并结束本函数， 否则p++
			if (e != EMPTY_STACK_ERROR)
			{
				if (e == '[')/*如果匹配成功,继续处理下一个输入的字符*/
				{
					p++;
				}
				else
				{
					printf("isn’t matched pairs\n");
					exit(1);
				}
			}//if
			break;

			// 其它字符不处理，指针向后移
		default:
			p++;
		}// end switch

	} // end while

	if (IsEmpty(&s)) // 字符串结束时 (左括号栈s空)
		printf("matching\n");
	else
		printf("lack of right parenthesis\n");
} // end check

//// 测试样例
/*[第一组自测数据]               [第二组自测数据]
  [键盘输入]                    [键盘输入]
  8*[3*(35-23)]↙                67-[235/ (36+89]↙
  [正确输出]                    [正确输出]
  matching                     isn’t matched pairs
*/
/*
int main()
{
	check();
}*/
/*
（4）利用栈来判断一个字符串是否是“回文”
所谓“回文”，即顺向读和逆向读都相同的文字，如“abcba”，试编写一个函数，读入一个字符串，利用栈判断其是否为“回文”，若是返回1，否则返回0。
*/
int  IsLoop()
{
    /**************************************************
思路：将字符串的字符全部入栈，
然后再逐一出栈，每出栈一个即与原字符串相应位置的字符进行比较，若不相等则返回0；若全相等，则返回1。
   *****************************************************/
   //your multiple lines code.......
	intStack s;
	char c;
	char a[100];
	int i = 0;
	InitStack(&s);
	/*读入字符串*/
	printf("输入字符串:\n");
	while (scanf("%c", &c) != EOF && c != '\n')//scanf("%c")能够读入换行符'\n'
	{
		a[i] = c;
		i++;
		Push(&s,c);
	}
	a[i] = '\0';

	i = 0;
	while (s.top)
	{
		if (Pop(&s) != a[i])
		{
			return 0;
		}
		i++;
	}
	
	return 1;


}

// 测试， 使用实际例子测试上述函数是否正常工作
void main()
{
	//char a[] = "abcba";
    // 定义几个回文和非回文的字符串例子，调用IsLoop函数判断并输出是否回文的信息
	if (IsLoop())
	{
		printf("输入的字符串是回文字符串\n");

	}
	else
	{
		printf("输入的字符串不是回文字符串\n");
	}
}
/*思考：前面对栈的定义可知该栈存储整型数据，本例需保存字符型数据，需对栈定义做修改吗？如果要改，怎么改？
可以不做修改仍可得到正确判断结果;如果要修改在定义栈的结构时将数组改为char型(更好的做法是定义新类型typedef char StackElem,使用StackElem;
这样修改类型只需修改char处即可
*/
//（5）综合练习 － 迷宫问题
//求迷宫中从入口到出口的所有路径是一个经典的程序设计问题。由于计算机解迷宫时，通常用的是“穷举求解”的方法，即从入口出发，顺某一方向向前探索，若能走通，则继续往前走；否则沿原路退回，换一个方向再继续探索，直至所有可能的通路都探索到为止。为了保证在任何位置上都能沿原路退回，显然需要用一个先进后出的结构来保存从入口到当前位置的路径。因此，在求迷宫通路的算法中应用“堆栈”是合适的。
//假设迷宫如下图1所示，图中的每个方块或为通道（以空白方块表示），或为墙（以带阴影的方块表示）。所求路径必须是简单路径，即在求得的路径上不能重复出现同一通道块。
//
//
//
//图1 迷宫问题
//（1）该迷宫可以用二维数组表示，定义如下：
//typedef struct {
//    // ‘#’表示 墙，’=’表示未经过的通道，’*’表示已经过通道，’!’表示绝
//    // 路。初始状态下为‘#’或者’=’
//    char arr[10][10];
//}MazeType;
//根据图1所示，编写一个函数，对迷宫数组进行初始化。
//（2）位置定义如下：
//typedef struct {
//    int r;   // 行坐标
//    int c;   // 列坐标
//}PosType;
//（3）经过路径中的通道块结点信息定义如下：
//typedef struct {
//    int ord;  // 通道块在路径上的序号
//    PosType  seat; // 通道块在迷宫中的坐标位置
//    int dir; // 从此通道块走向下一个通道块的方向            
//}ElemType;
//
//根据以上类型定义，实现一个能容纳ElemType类型数据的栈。
//（4）写一个函数，判断迷宫中的某个位置是否可通过。
//int pass(MazeType* pMyMaze, PosType CurPos)
//{
//    // 如果当前位置为’=’，返回1， 否则返回0
//}
//（5）写一个函数，将迷宫中的某个位置标记为已通过
//void footPrint(MazeType* pMyMaze, PosType CurPos)
//{
//    // 当前位置标记为’*’
//}
//（6）写一个函数，将迷宫中的某个位置标记为绝路
//void blockedPrint(MazeType* pMyMaze, PosType CurPos)
//{
//    // 当前位置标记为’!’
//}
//（7）写一个函数，根据当前位置和探测方向，返回下一个探测位置
//PosType  nextPosition(PosType CurPos, int dir)
//{
//    PosType nextPos;
//    // 怎么根据 dir 得到  nextPos ？？
//    return nextPos;
//}
//（8）给定出发位置和出口位置，根据以上栈实现和相关函数写出在迷宫中求路径的函数。
//int mazePath(PosType CurPos, int dir)
//{
//    // ok, 看你们的了
//}
//（9）用图1所示迷宫验证。
//void main()
//{
//    // 初始化一个迷宫，使用到一个栈，你还需要什么？
//    // 走吧~~~
//    // $*^^)&_)*)*)(^%$^^#%^&^**%
//    // 最终，你的路径存到栈里了吗？但怎么按照出发顺序输出这个路
//    径呢？？？
//        // 也许，你需要更多一个栈．．．
//}
//
//
