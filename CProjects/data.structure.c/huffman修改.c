
#define _CRT_SECURE_NO_WARNINGS
#define   EMPTY_QUEUE_ERROR   -999999
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLEN 100
/*（29）哈夫曼编码
已知如下代码是  对5个带权结点  生成Huffman树，并输出结点的Huffman编码。
请理解并调试该代码。

之后对代码进行修改，使之完成如下任务。
1. 已知所用词汇的词频如下表所示，请计算出各词汇权重。
单词	    全部	 love	is	this	commandment 	always	said	by
出现次数	314	 40	    10	6	      50	          32	12   	5

单词	   Marbury	which	means	that	one	 person	any	 other
出现次数	20	      18	12	      30	10	 25	     8	 36

2. 根据各词汇的权重，构建词汇的Huffman树，并求得各词汇的Huffman编码。
3. 根据词汇的Huffman编码对如下句子进行编码压缩和解压缩。
“love is love, this commandment is always said by Marbury, which means that one person always love any other person.”

提示：如何保存“0”“1”串的编码更省空间？
比如两个编码 0100和1011，如果用字符数组保存需要8个字节，
但如果用二进制表示为“0100 1011”，则用一个字符”K”(其ASCII码为75，75的二进制为” 01001011”)即可表示这两个编码。
上面这段话可以压缩为几个字符？
*/

/*如何阅读含有数量众多的自定义的函数?
首先应该看main()函数,main()中调用的函数一般已经是建立在基础自定义(或库函数)的复合函数(如果足够复杂),
 根据调用的复合函数去查看基础函数的用法及定义(需要什么看什么,自动帮你导航到有必要看的函数定义,看完就回到main()中继续看下一个调用所涉及的函数(及子函数)需求因果清晰,不易混淆)
 然而,不但使写出来的代码要每行都知道含义,有些没写出来的行应知道使怎么回事(或者是在别处得到处理了/没必要处理)*/

 /*哈夫曼树的总结点数是2n-1（n是叶子节点数）
 证明如下：

 因为二叉树中n0=n2+1;
 所以节点总数T=n0+n1+n2=n2+1+n1+n2;
 又n1=0，
 所以T=2n2+1=2(n0-1)+1=2n0-1,得证*/



 //Huffman树的存储结构
#define n 15					//叶子数目
#define m 2*n-1					//树中结点总数

/*基于数组实现的静态链表孩子双亲结点二叉树数据结构*/
/*Huffman树的基本结点类型(结点本身的权以及和其他结点的链接情况/关系*/
typedef struct					//结点类型(叶子节点)
{
	float weight;				//权值，不妨设权值均大于零(任意数值)
	int lchild, rchild, parent;	//左右孩子及双亲指针
}HTNode;
/*Huffman整体的结构体(节点变量类型的数组),只存放(带权的)叶子节点*/
typedef HTNode HuffmanTree[m];	//HuffmanTree是向量类型/*定义新数组类型(规格也包含在新类型名称中)元素数目是Huffman树的结点总数m*/

/*Huffuman树的各基本结点的附加编码信息*/
typedef struct
{
	char str[MAXLEN];					//存储字符串单词
	char bits[n + 1];		//存放 编码位串(0,1构成)
}CodeNode;
/*huffman树结点编码 整体树信息数组*/
typedef CodeNode HuffmanCode[n];/*定义新数组类型(规格也包含在新类型名称中)元素数目是Huffman树的叶子节点数目n*/

void InitHuffmanTree(HuffmanTree T);	//初始化Huffman树
void InputWeight(HuffmanTree T);		//输入权值
void SelectMin(HuffmanTree T, int i, int* p1, int* p2);
/*huffman树*/
void maiiin()/*如果树足够高的话,字符(单词)的编码最短长度可以超过1*/
{
	/*内部声明两个函数:*/
	/*不是调用!!!1*/
	void CreateHuffmanTree(HuffmanTree T);	//声明:构造Huffman树的函数
	void CharSetHuffmanEncoding(HuffmanTree T, HuffmanCode H); //声明:计算各节点的哈夫曼编码,并将结果存于参数H中的函数.
	/*定义两个Huffman树类型的变量(起始是结点类型的数组)*/
	HuffmanTree T;
	HuffmanCode H;

	CreateHuffmanTree(T);/*main()中函数的先后调用是有逻辑关系的,前面的函数调用可能对后面调用的函数的
						 参数缠产生影响比如初始数据结构/填充数据结构..以便后面的调用可以正确访问*/
	CharSetHuffmanEncoding(T, H);
}
/*代码阅读记录(示例):
* 700->713->715
*/

void CreateHuffmanTree(HuffmanTree T)//main()_1调用(构造Huffman树,复合函数)
{ 	//构造Huffman树，T[m-1]为其根结点
	int i, p1, p2;
	InitHuffmanTree(T);		//将T初始化
	InputWeight(T);			//输入叶子权值至T[0..n-1]的weight域

	for (i = n; i < m; i++)		/*共进行n-1次合并，新结点依次存于T[i]中;从n->m这些节点是非叶子节点(后期构建而非传入的n个叶子)它们的权值
								起初由叶子节点合并得到,之后也可称为被合并的对象,接入T数组(每合并一次,T中的结点就会少一个:(插入一个新结点,丢弃两个旧结点)
								当然负责保存编码信息的 数组H 中的结点不会被删掉*/
	{
		SelectMin(T, i - 1, &p1, &p2);
		//在T[0..i-1]中选择 两个 权最小的 根结点，其序号分别为p1和p2
		T[p1].parent = T[p2].parent = i;/*i是当前数组T中最后一个结点的下一个空位置索引,相当于把p1和p2挂接到该处*/
		/*处理最小权结点和次小权的左右关系*/
		T[i].lchild = p1;		//最小权的根结点是 新结点的左孩子
		T[i].rchild = p2;		//次小权的根结点是 新结点的右孩子
		/*新结点的T[i].parent 此时仍然处于被InitHuffman初始化的NULL(如果某个新结点的T[i].parent最终没有被修改(保持为NULL)那这个T[i]就是Huffman树的总根结点*/
		T[i].weight = T[p1].weight + T[p2].weight;/*新结点的权值*/
	}
}

void InitHuffmanTree(HuffmanTree T)/*初始化Huffman树*/
{
	int i;
	for (i = 0; i < m; i++)/*将Huffman树的所有结点位置都进行初始化( m = 2n-1)*/
	{
		T[i].weight = 0;
		T[i].lchild = T[i].rchild = T[i].parent = NULL;/*三个关系(虚拟)指针都初始化为NULL即: (void*)0  */
	}
}

void InputWeight(HuffmanTree T)//输入权值(到给定的n个叶子节点里)
{
	int i;
	for (i = 0; i < n; i++)/*这里的n是前面的宏定义,值为5,(当然建议用大写N比较合适)*/
	{
		printf("请输入第%d个权值：", i + 1);
		scanf("%f", &T[i].weight);/*权 写在树数组T的前n个结点里*/
	}
}
/*在T[0..i]中选择 两个还未合并的 权最小的 根结点(这些叶子节点都当成一棵树,即叶子本身就是根)，其序号分别为p1和p2(采用间接传参,以便保存修改结果)*/
void SelectMin(HuffmanTree T,
	int i,/*扫描/判断的范围:到索引i个为至(从0~i)(为了提高搜索效率的附加参数(这里同时也是必要的)*/
	int* p1, /*最小*/
	int* p2)/*次小*/ //在T[0..i-1]中选择 两个 权最小的 根结点，其序号分别为p1和p2(采用间接传参,以便保存修改结果)
{
	//在T中选择两个权最小的根结点
	int j;
	float min1,/*最小*/
		min2;/*次小*/
	min1 = min2 = -1;

	for (j = 0; j <= i; j++)/*从0到i均取得即遍历所有叶子节点*/
		/*如果T[j]尚未被合并,T[j].parent就是保持初始的NULL*/
		if (T[j].parent == NULL)/*如果T[j].parent != NULL,说明它之前已经被用于合并了(而被屏蔽,那么在T数组中就不可再参与合并,也就不可干扰新序列的最小权搜索*/
		{
			/*更新min1*/
			if (T[j].weight < min1 /*比当前为止最小的权都小,那这个T[j]就是新的最小权节点.*/
				|| min1 == -1)/*为了可以启动第一次判断,否则所有节点的权都为正数无法进入比较*/
			{
				if (min1 != -1)/*如果min1之前已被修改.就必要更新min2和p2,当然也可以不判断,一律geng'xin更新.不会错*/
				{
					/*修改min1和*p1前,将数据复制到min2和*p2*/
					min2 = min1;
					*p2 = *p1;
				}
				/*修改min1和*p1*/
				min1 = T[j].weight;
				*p1 = j;
			}
			else
				if (T[j].weight < min2 || min2 == -1)
				{
					min2 = T[j].weight;
					*p2 = j;
				}
		}
}
/*逆序收集编码字符,顺序读取.*/
void CharSetHuffmanEncoding(HuffmanTree T, HuffmanCode H)/*main()_2调用(基础函数)*/
{	//根据Huffman树T 求Huffman编码表H
	int c,/*child位置*/
		p,/*parent位置.*/
		i;				//c和p分别指示 T中(数组中)  孩子和双亲的位置
	char cd[n + 1];			//临时存放编码/*最后多申请的一个位置:cd[n]用来保存字符串结束符'\0'.可以确定单个字符的Huffman编码的长度不会超过n

	int start;				//指示编码在cd中的起始位置
	cd[n] = '\0';				//编码结束符

	printf("请输入单词字符：");
	//getchar();/*应该时读走之前输入留下的换行.(这样当然就不需要保存getchar()的返回值了)*/

	/*不妨先直接看for()(前头定义的辅助变量不急着看),在中途看到标识符的话将鼠标悬停在上面即可看到定义(如果有定义时的注释也可显示出来.*/
	for (i = 0; i < n; i++)		//依次求 叶子T[i] 的编码
	{
		scanf("%s",H[i].str);	//读入叶子T[i]对应的单词

		start = n;			//编码起始位置  的初值
		c = i;/*初始化为i*/				//从 叶子T[i] 开始 上溯/*(yin'wei)因为输入的是叶子节点,当然要上溯 '构建'树
		while ((p = T[c].parent) != NULL)/*//直至 上溯到T[c]是树根 为止;收集0,1字符编码串.树根节点的父节点指针为NULL
			(当然,树根肯定不是初始输入的n个叶子节点了,而是中途合并的新节点(这些非叶子节点只有位置,没有节点的编?).*/
		{	//若T[c]是T[p]的左孩子，则生成代码0；否则生成代码1
			cd[--start] = (T[p].lchild == c) ? '0' : '1';/*收集的字符是从后往前写,顺着度就可以获得从根节点到叶子节点的编码序列.
														 (start=n;该位置被写入'\0',要前移一个位置再写入(--start)
														 (然而短编码牵头又空(乱)区域,幸好start可以指示编码后从哪里开始读取字符,
														 且前头已经在cd[n]处初始化为结束符'\0'*/
			c = p;			//继续上溯/*因为链表上溯跳跃,所以c不直接用i替代.*/
		}
		/*叶子节点编码信息数组H.*/
		strcpy(H[i].bits, &cd[start]);		//复制编码位串(写入到对应叶子结点正式编码区域)
	}
	/*打印结果:*/
	for (i = 0; i < n; i++)
		printf("第%d个字符%s的编码为%s\n", i + 1, H[i].str, H[i].bits);
}


