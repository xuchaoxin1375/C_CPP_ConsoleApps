/*实验四 队列
队列也是一种操作受限制的线性列表。队列只能在表的一端进行“存”的插入操作，在另一端进行“取”的删除操作。数据在队列中按照“先进先出”的原则进行存取。本实验实现单链表和它的一些相关应用。
（1）实验目的
（1）理解队列的结构及操作特点；
（2）实现循环队列的入队、出队等基本操作算法
（3）熟练掌握入队、出队时队头、队尾指针的变化情况
（4）掌握队列的应用
（2）实验内容
（1）队列的基本实现
目标：定义一个可存储整型数据的循环队列，并实现其常用算法。
（1）算法填空：根据功能提示，完善下划线处的代码。
（2）队列结构体的定义
定义相应的结构体数据类型，用来表示队列这一数据结构对象。*/

#define _CRT_SECURE_NO_WARNINGS
#define   EMPTY_QUEUE_ERROR   -999999
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLEN 100
typedef int ElemType;
typedef struct {
	int elem[MAXLEN];    // 用来存队列数据元素的数组
	int front;              // 指示队首在数组中位置的标识量
	int rear;               // 指示队尾在数组中位置的标识量adj.后面的,背面的,后方的
}intQueue;
/*
（3）队列的初始化
队列在使用之前，必须对其结构体中的成员变量赋初值，称为初始化，通过函数来实现。
队列的初始化针对队列的某一具体实例进行操作，因此需
将该实例在内存中的地址作为初始化函数的参数。
*/
/*初始化(调整两个位置标识量)*/
void InitQueue(intQueue* pQueue) // 指针类型作为形参，某个队列实例的地址
{
	/**********************************************************
	将该队列实例的队首和队尾标识量置零
	*********************************************************/
	pQueue->front = 0;
	pQueue->rear = 0;
}
/*（4）判断队列是否为空？是否已满？
在 循环队列中:
经常需要判断队列为空或满，队列为空的时候无法出队列，队列已满时无法入队列。

rear+1 与front重合,换句话说rear紧邻于front之后
	(不可超越,互不可超越),且只能够同向的你追我赶.
*/
int  IsEmpty(intQueue* pQueue) // 指针类型作为形参，某个队列实例的地址
{
	/**********************************************************
	队列为空时返回1，否则返回0
	*********************************************************/
	if (pQueue->rear == pQueue->front)
		return  1;
	else
		return 0;
}

int  IsFull(intQueue* pQueue) // 指针类型作为形参，某个队列实例的地址
{
	/**********************************************************
	什么情况下认为该队列已满？
	*********************************************************/
	if ((pQueue->rear + 1) % MAXLEN == pQueue->front)
		return  1;
	else
		return 0;
}
/*（5）入队列
将某数据元素x入队列，成功返回1，失败返回0。*/
int  EnQueue(intQueue* pQueue, ElemType x)
{
	// 1、若该队列已满，则入队列失败
	if (IsFull(pQueue))  return 0;

	// 2、若该队列没满，将x写入队尾，然后队尾位置后移
	else
	{
		pQueue->elem[pQueue->rear] = x;// x入队列
		pQueue->rear = (pQueue->rear + 1) % MAXLEN;// 队尾后移
	}


	return 1;
}
//（6）算法练习：根据功能提示，实现算法。
/*（7）出队列(删除队头)
若队列中有数据，则将队首数据元素返回；
否则，返回一个特殊的标识量，该标识量应该不可能在队列数据中出现，以免无法判断返回的是正常的数据元素还是表示出错。
函数原型如下：
*/
/*对头元素出队列*/
int  DeQueue(intQueue* pQueue)
{
	if (!IsEmpty(pQueue))
	{
		/*移动对头元素前保存该值*/
		ElemType temp = pQueue->elem[pQueue->front];

		/*向前移动front有讲究:
		如果是:pQueue->front++,那么front可能会溢出数组,
		所以必须利用循环队列的周期性质(除以周期取余数),保证不溢出*/
		pQueue->front = (pQueue->front + 1) % MAXLEN;
		return temp;/*删除成功的出口*/
	}
	return EMPTY_QUEUE_ERROR;
}
/*（8）清空队列
将队列清空，所有队列中数据作废。函数原型如下：*/
void  ClearQueue(intQueue* q)
{
	q->front = 0;
	q->rear = 0;
}
/*
（9）求取队列长度(重要)
返回队列中元素的个数
*/
int  QueueLen(intQueue* q)
{
	return (q->rear - q->front + MAXLEN) % MAXLEN;
}
/*（10）遍历队列
将队列元素依次出队并输出。*/
void  TraverseQueue(intQueue* q)
{
	//for(int i = 0;i < QueueLen(q);i++)
	ElemType elem;
	printf("测试TraverseQueue():\n");
	while ((elem = DeQueue(q)) != EMPTY_QUEUE_ERROR)
	{
		printf("%d ", elem);
	}
	printf("\n");
}
/*（11）调试
根据上述队列的定义，完成下面代码，运行并调试程序。
测试样例格式说明：
根据菜单操作：
1、输入1，表示要实现入队操作，紧跟着输入要入队的元素
2、输入2，表示要实现出队操作
3、输入3，返回队列的元素个数
4、输入4，表示从队头到队尾输出队的所有元素
5、输入0，表示程序结束*/
/*
int main()
{
	int a;
	intQueue S;
	int  x,
		e = 0;

	InitQueue(&S);  // 初始化队列S

	while (1)
	{
		printf("  1、输入1，表示要实现入队操作，紧跟着输入要入队的元素\
			\n2、输入2，表示要实现出队操作\
			\n3、输入3，返回队列的元素个数\
			\n4、输入4，表示从队头到队尾输出队的所有元素\
			\n5、输入0，表示程序结束1:Enter\
			\n2:Leave \n3:Return the Length of the Queue\
			\n4:Traverse the Queue\n0:Exit\nPlease choose:\n");换行的标识是"\"

scanf("%d", &a);
switch (a)
{

case 1:
	printf("测试插入EnQueue():\n");
	scanf("%d", &x); // 入队
	if (!EnQueue(&S, x))
		printf("Enter Error!\n");
	else
		printf("The Element %d is Entered!\n", x);
	break;
case 2:
	printf("测试插入DeQueue():\n");
	if ((e = DeQueue(&S)) == EMPTY_QUEUE_ERROR) // 出队
		printf("Delete Error!\n");
	else
		printf("The Element %d is Deleted!\n", e);
	break;
case 3:
	// 输出队列长度
	printf("测试插入QueueLen():\n");
	printf("The Length of Queue is %d!\n", QueueLen(&S));
	break;
case 4:
	printf("测试插入TraverseQueue():\n");
	TraverseQueue(&S); //遍历该队列
	break;
case 0: return 1;
}
	}
}
*/
//（12）思考
//（13）通用的数据队列
//上述实现的队列只能用来保存整型数据，如果想要处理其他类型的数据，该做怎样的修改？
//typedef int ElemType;
//typedef struct {
//	ElemType elem[MAXLEN];    // 用来存队列数据元素的数组
//	int front;              // 指示队首在数组中位置的标识量
//	int rear;               // 指示队尾在数组中位置的标识量
//}Queue;
////将typedef int ElemType中的int修改为其他需要的类型即可;

/*
（14）链队列
虽然使用循环队列可以充分利用数组空间，但队列长度固定仍然不够灵活，当队列所需存储的数据量未知时，循环队列经常难以满足要求。
而采用链式队列，能克服上述缺点。
链式队列是用链式形式来存储数据的队列，可以看做一种特殊形式的链表，两者的联系和区别如下所述：
（15）链式队列是没有专用头结点的特殊链表；
（16）队列中的数据分别存储于链表中的每一个结点中，队首指针指向当前队列头部结点，相应于链表的头指针。
（17）队尾指针指向链表的最后一个结点。
（18）入队列相当于在链表的尾部插入结点；
（19）出队列相当于将当前链表的头结点移除；
（20）当队列为空时，队首和队尾指针均为空；

（21）一般情况下，不需要考虑队列满的状态；
*/
/*
请根据以上描述，实现一个链式队列。
并思考一下，当用链式队列来解决以下部分的应用时，跟前两种方式实现的队列有无区别？
*/
//typedef int QElemType; /* QElemType 类型根据实际情况而定，这里假设为int */
//
//
//
//typedef struct QNode /* 结点结构 */
//{
//	QElemType data;
//	struct QNode* next;
//}QNode, * QueuePtr;
//
//
//
//typedef struct /* 队列的链表结构 */
//{
//	QueuePtr front, rear; /* 队头、队尾指针 */
//}LinkQueue;
//（2）队列的应用
//目标：应用队列解决实际问题。
/*（22）输出杨辉三角
杨辉三角除第一行为两个1以外，从第二行开始，每一行的首尾都为1，中间位置的数为上一行其左右两侧数之和，形状如下：
1 1
1　2　1
1　3　3　1
1　4　6　4　1
试编写函数，利用循环队列实现任意行杨辉三角的输出。

如果要求计算并输出杨辉三角前 n 行的值，则队列的最大空间应为 n + 2。(进进出出的)

假设队列中已存有第 k 行的计算结果，并为了计算方便，在两行之间添加一个“0”作为行界值，
则在计算第 k + 1 行之前，头指针正指向第 k 行的“0”，而尾元素为第 k + 1 行的“0”。

由此从左到右依次输出第 k 行的值，并将计算所得的第 k + 1 行的值插入队列。
*/
/*利用循环队列实现任意行杨辉三角的输出?*/
void  YangHuiTiangle(int n)
{
	int s, e; // s保存 上一行 左侧数据，e保存右侧数据
	intQueue q; // 定义一个队列实例变量q

	InitQueue(&q); // 使用之前需要初始化该队列q

	{ // 预先放入第一行的两个1
		EnQueue(&q, 1);
		EnQueue(&q, 1);
	}
	/*后续的行*/
	// 循环: 逐行处理，
	/*将第i行 出队 并输出，
	 生成第i+1行  入队;
	 在出队输出第i行前要先把下一行(即第i+1行)算好并插入队列后才输出,否则下一行的计算就没有输入了)	(注意是从从头(q->front)出队(保存到e),先进先出);*/
	for (int i = 1; i <= n; i++)//i是要输出的行,i+1是要填充的行 
	{
		/*生成第i+1行*/
		EnQueue(&q, 0);// 两行之间增加一个0作为标记
				// 处理第i行的(要生成的)i+2个数据(第i行有i+1个数,额外有一个0作为分隔行的标记数.
		s = 0;/*计算第i行开始前,将保存上一行左边的值的变量初始化为0*/

		for (int j = 1; j <= i + 2; j++)
		{
			// 读取上一行的第一个数据1，存到e中//q.elem[q.front]
			e = DeQueue(&q);//出队一个

			// 计算i行的第j个数据，并入队
			EnQueue(&q, s + e);//入队一个(第i行的第j个数据)

			s = e;  // 这是为何？(在计算同一行的下一个元素时,当前的元素使用的e就是下一个元素的s;

			// 如果j非第i+2个数据，输出s
			/*(e和s是独立于队列之外的两个变量)
			如果j是的i+2个元素,那么刚好是该行的结束标志数0,(与此同时,可以将生成边缘的"1" 也用e+s计算统一起来(边缘值:0+1 = 1或者1+0 = 1 )
			第一行的元素在队列中不是0,但可以在队列之外单独将s初始化为0*/
			{
				/*输出第i行,第i行有i+1个需要输出的元素,(不包括0)*/
				//your multiple lines code
				if (j < i + 2)
				{
					printf("%d ", s);
				}
			}
		}//for(j)
		printf("\n");  // 结束i行，输出换行符
	}//for(i)   
}

//测试， 使用实际例子测试上述函数是否正常工作

//void main()
//{
//	int n;
//	printf("\n\n\t\tYangHui Triangle:\n\nplease input the lines you want!(1~98, 0 to quit)");
//	scanf("%d", &n);
//	while (n)
//	{
//		//system("cls");/*cls是清屏的,但是它清除的是上一个回车的内容*/
//		printf("测试杨辉三角YangHui():\n");
//		if (n > 0 && n < 99)
//			YangHuiTiangle(n);
//		/*准备接收下一个请求:*/
//		printf("\n\n\t\tYangHui Triangle:\n\nplease input the lines you want!(1~98, 0 to quit)");
//		scanf("%d", &n);
//	}
//}
/*（23）舞伴问题
假设在周末舞会上，男士们和女士们进入舞厅时，各自排成一队，男女人数不一定相等。

跳舞开始时，依次从男队和女队的 队首上各出一人配成舞伴。 舞曲结束后，男女各自入队。
现在用小写字母表示男士，大写字母表示女士，
试输入一个字符串，按照大小写将男女归入两个队列，
试写出当所有人都至少跳舞一次时，舞伴的组合情况。
测试样例格式说明：
[键盘输入]
用字符串表示的当天舞者序列；
[正确输出］
舞伴组合情况

测试样例：
[第一组自测数据]
[键盘输入]
abcDefGiH
[正确输出]
a - D
b - G
c - H
e - D
f - G
i - H

[第二组自测数据]
[键盘输入]
aBcDEF
[正确输出]
a - B
c - D
a - E
c - F
*/

void dance_match()
{
	intQueue qMale ,
		qFemale;/*定义两个队列*/
	char c;
	int LenMale,
		LenFemale;/*记录男女队列是否分别完成遍历一次*/
	char backMale, backFemale;/*记录要重新入队的元素*/
	/*初始化定义的队列*/
	InitQueue(&qMale);
	InitQueue(&qFemale);
	/*读取输入并填充队列*/
	printf("读取输入(字符串)并填充队列:\n其中,女士用大写字母,男士用小写字母表示:\n");
	while (scanf("%c", &c) && c != '\n')
	{
		/*女士用大写:*/
		if (c >= 'A' && c <= 'Z')
		{
			EnQueue(&qFemale, c);

		}
		else if(c >= 'a' && c <= 'z')
		{
			EnQueue(&qMale, c);
		}
	}

	LenMale = QueueLen(&qMale);
	LenFemale = QueueLen(&qFemale);

	printf("输出配对结果:\n");
	while (LenFemale || LenMale)//若双方均为0,就不再进入循环了
	{

		/*LenMale与LenFemale双方均非0*/
		if (LenFemale && LenMale)
		{
			/*配对流程*/
			printf("%c - %c\n", backMale = DeQueue(&qMale), backFemale = DeQueue(&qFemale));
			EnQueue(&qMale, backMale);
			EnQueue(&qFemale, backFemale);
			/*分类减少*/
			LenFemale--;
			LenMale--;
		}//if

		/*LenMale与LenFemale一方为0,另一方非0*/

		else if (!LenMale && LenFemale)/*如果男士先完成遍历*/
		{
			/*配对流程*/
			printf("%c - %c\n", backMale = DeQueue(&qMale), backFemale = DeQueue(&qFemale));
			EnQueue(&qMale, backMale);
			EnQueue(&qFemale, backFemale);

			LenFemale--;
		}
		else
		{
			/*配对流程*/
			printf("%c - %c\n", backMale = DeQueue(&qMale), backFemale = DeQueue(&qFemale));
			EnQueue(&qMale, backMale);
			EnQueue(&qFemale, backFemale);

			LenMale--;
		}
	}//while

}
/*
int main()
{
	dance_match();
}*/

/*
（24）顾客等待时间
某银行有一个客户办理业务站，在一天内随机地有客户到达，
设每位客户的业务办理时间是某个范围内的值。
设只有一个窗口，一位业务人员，
要求程序模拟统计在一天时间内，所有客户的平均等待时间。

模拟数据按客户到达的先后顺序依次由键盘输入，
对应每位客户有 两个数据，即 到达时刻 和 需要办理业务(占用)的时间。
测试样例格式说明：
[键盘输入]
第一行：一天内的客户总人数n

第二行：第一个客户的 到达时刻 和 需要办理业务的时间
第三行：第二个客户的到达时刻和需要办理业务的时间
……
第n行：第n - 1个客户的到达时刻和需要办理业务的时间
第n + 1行：第n 个客户的到达时刻和需要办理业务的时间

[正确输出］
第一行：所有客户的平均等待时间（精确到小数点后2位）

测试样例：
[第一组自测数据]
[键盘输入]
3
1 3
2 1
3 5
[正确输出]
1.33
[第二组自测数据]
[键盘输入]
4
1 1
12 5
15 1
16 5
[正确输出]
1.00*/
/*

比如说:
1 3(等待0时)
2 1(等待
3 5(最后一个人的占用时间不需要出栈,因为它后面没人了,也不需要关系他什么时候结束)
*/
/*
1.计算每个人的等待时长总和
	其中,累计方式为:(记前一个人(第i个)结束离开的时间点为ti+Si同时,记后一个人到达时间为t(i+1);
	如果ti+si>t(i+1),则在等待总时长加上两者之差(或(-1)*它)
	后来的一个人需要等待的时间为前一个人
*/

/*只能处理整点/占用整数小时的情况(可以修改数据结构及相关函数的参数处理类型来提升使用范围*/
float avg_wait_time()
{
	int n = 0,i = 0;
	int come_time = 0,
		occupy_time = 0;
	int pre_time = 0,/*前一个人到的时间*/
		pre_off_time = 0,/*前一个人离开的时刻*/
		aft_time = 0;/*后一个人到达的时间*/

	int sum_wait_time = 0;
	intQueue q_come,
		q_occupy;
	InitQueue(&q_come);
	InitQueue(&q_occupy);

	printf("输入一天内的客户总人数n:\n");
	scanf("%d", &n);

	printf("输入到达时刻 和 需要办理业务(占用)的时间:\n");
	while (i<n)
	{
		scanf("%d%d", &come_time, &occupy_time);
		EnQueue(&q_come, come_time);
		EnQueue(&q_occupy, occupy_time);
		i++;

	}//写入数据完毕
	i = 0;
	/*开始处理:*/
		/*pre_time()提前准备好*/
	pre_time = DeQueue(&q_come);
		//这里以经预先弹出一个元素,在下方的循环中就要少运行一次;(最后一个人的占用时间也不需要出栈,因为它后面没人了,也不需要关系他什么时候结束)
	pre_off_time = pre_time;
	while (i<n-1)
	{	
		pre_off_time = pre_off_time + DeQueue(&q_occupy);
		aft_time = DeQueue(&q_come);
		
		if (pre_off_time > aft_time)
		{
			sum_wait_time += (pre_off_time - aft_time);
		}
		else
		{
			/*不做累加,但下一个人来的晚,以至于要调整pre_off_time(此时已不是本意了)*/
			pre_off_time = aft_time;
		}
		/*为下一次比较做预备*/
	
		i++;
	}

	return sum_wait_time * 1.0 / n;
}
int main()
{
	printf("%.2f\n", avg_wait_time());
}

