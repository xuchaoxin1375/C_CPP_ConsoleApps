/*实验七 二叉树及其应用
* 
树是由n（n≥0）个结点构成的一个有限集合以及在该集合上定义的一种结点关系，集合中的元素称为树的结点。
n=0的树称为树|当n子0时，树中的结点应该满足以下两个。
把由子集T、T2……T。构成的树称作根的子树（Subtree）。
条件：
（1）必有一个特定的称为根（root）的结点，这个根结点没有前驱。
94树和二叉树
（2）剩下的结点可以被分成n个（n≥0）互不相交的子集T1、T2、……T。，而且，每一个子集又都是树.

许多实际应用中，对象呈现出一种非线性的次序，其主要表现在结点可能有多个后继结点的集合，树状结构可以对这些应用进行描述。
二叉树是树状结构的一个特列，许多实际问题抽象出来的数据结构往往是二叉树的形式，且普通树可以转换为二叉树进行处理。
本实验实现二叉树和它的一些相关应用。
（1）实验目的
（2）学习掌握二叉树的建立、遍历等基本操作。
（3）提高对树型结构的综合应用能力。
（4）进一步掌握递归算法。
（5）实验内容
（6）二叉树的构建

目标：使用链式方式完成二叉树的构造，实现相关函数。
（7）算法填空：根据功能提示，完善下划线处的代码。
（8）二叉树链式结点类型的定义
定义一个结构体数据类型，用来表示二叉树中的结点。*/
#define _CRT_SECURE_NO_WARNINGS
#define   EMPTY_QUEUE_ERROR   -999999
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLEN 100
typedef struct BTNode {
	char data;    // 结点中的信息，假设为 单个字符
	struct BTNode* lchild, * rchild; // 左右孩子的指针
}BTNode;
/*（9）生成根节点
写一个函数，生成唯一的根节点。根节点的信息用一个字符参数输入。*/
BTNode* CreateRoot(char c)
{
	// 申请根结点空间
	BTNode* tmp = (BTNode*)malloc(sizeof(BTNode));

	// 判断申请空间是否成功，若成功，则输入结点信息，并初始化指针
	if (!tmp)
		printf("申请空间失败，无法创建根结点\n");
	else
	{ // 申请空间成功，为根节点赋初值，并初始化其左右孩子为空
		tmp->data = c;
		tmp->lchild = 0;
		tmp->rchild = 0;
	}

	// 返回根节点
	return tmp;
}
/*10）插入左孩子
在指定结点下插入一个左孩子，
原先的左子树作为新插入左孩子结点的左子树，并
返回新插入左孩子结点的指针。
*/
BTNode* InsertLeftNode(BTNode* curNode, char c)
{
	// 申请 左孩子结点 的空间
	BTNode* tmp = (BTNode*)malloc(sizeof(BTNode));

	// 判断申请空间是否成功，若成功，则输入结点信息，并初始化指针
	if (!tmp)
		printf("申请空间失败，无法创建根结点\n");
	else
	{
		// 存入新结点信息
		tmp->data = c;

		// curNode原先的左子树挂到新结点下面(从原双亲结点断开+接到新结点时同时完成的.)
		/*结点与其孩子的连接时依赖于双亲结点里的子树指针(所谓的结点挂接,就是一个结点地址赋值给目标(新)双亲结点子树指针的操作)*/
		tmp->lchild = curNode->lchild;

		// 新结点右子树置空
		tmp->rchild = 0;

		// 新结点作为左孩子挂在curNode下面
		curNode->lchild = tmp;
	}
	return tmp;/*curNode->lchild*/
}
/*（11）删除左子结点
若指定结点的左子结点 仅有一颗子树，则删除该左子结点，
同时将其子树作为指定结点的左子树。*/
void DelLeftNode(BTNode* curNode)/*指定结点的左子结点 仅有一颗子树*/
{
	// 如果curNode的左子结点有两颗子树，则不删除，直接返回。
	if (curNode->lchild->rchild && curNode->lchild->rchild)/*即curNode->lchild有两个子树*/
		return;

	// 暂存左子结点指针/*便于后期free(),因为左子结点从curNode断开并接上lc后就会断开(无法通过curNode->lchild访问这要被free()的指针*/
	BTNode* tmp = curNode->lchild;

	// 保存该左子结点的非空子树
	BTNode* lc = tmp->lchild ? tmp->lchild :tmp->rchild ;

	// 该非空子树挂到curNode的左路
	curNode->lchild = lc;

	// 删除左子结点
	free(tmp);
}
/*（12）算法实现：根据功能提示，实现算法。
* 
（13）插入右孩子
在指定结点下插入一个右孩子，
原先的右子树  作为 新插入 右孩子结点 的右子树，
并返回新插入右孩子结点的指针。*/
BTNode* InsertRightNode(BTNode* curNode, char c)
{
	/*定义新结点(并为之申请空间,初始化)*/
	BTNode* tmp = (BTNode*)malloc(sizeof(BTNode));
	// 判断申请空间是否成功，若成功，则输入结点信息，并初始化指针
	if (!tmp)
		printf("申请空间失败，无法创建根结点\n");
	else
	{
		tmp->data = c;/*为新结点赋值*/
		tmp->rchild = curNode->rchild;/*为新结点挂上右子树*/
		curNode->rchild = tmp;/*新结点挂到指定节点curNode*/
		tmp->lchild = 0;/*将新结点闲置的左子树(挂一棵空树)指针置为NULL(0)*/
		return tmp;
	}
}
/*（14）删除右子结点
若指定结点的右子结点  仅有一颗子树，
则删除该右子结点，   同时将其  子树  作为指定结点的 右子树。*/
void DelRightNode(BTNode* curNode)/*删除函数主要是有一个寄存结点地址过程*/
{
	//如果curNode的右子树有两颗子树,则不删除:
	if (curNode->rchild->lchild && curNode->rchild->rchild)
	{
		return;/*直接回到主调函数*/
	}
	/*保存要被free的地址*/
	BTNode* tmp = curNode->rchild;
	/*将非空字树(地址)保存到lc*/
	BTNode* lc = tmp->lchild ? tmp->lchild : tmp->rchild;
	/*可以挂接了*/
	curNode->rchild = lc;
	/*可以释放了*/
	free(tmp);

}
/*（15）按先序次序的  构建
按先序遍历的输出次序 输入一个  字符串，其中每个字符代表二叉树中一个结点的值，用’#’字符表示空结点。
试根据此先序遍历的字符次序一次性构造出 链式二叉树。*/
BTNode* CreateTree()/*这种需要回溯的,编写成递归函数是一个好思路(处理最后一次出口调用,其余调用都是
					先只需前面的部分,最后执行之前各次为完整执行的调用(堆栈特性);
					核心性质:每个结点的身份是相对的(既是根结点(孩子结点的),又是孩子结点(双亲结点)
					该递归函数功能要求:能构造根节点;能构造左子树;能构造右子树;能返回执行(构造)结果.
					(返回出口安排在函数的末尾,要在构造号两侧子树后返回)最后,用一棵矮树来测试一下.*/
{
	/*char* str;
	scanf("%s", str);*/
	char ch;/*定义一个结点数据域的变量类型的变量*/
	ch = getchar();

	BTNode* T;/*树的总根结点指针T ;如果直接T = CreateRoot(ch),creatRoot()*/

	{
		/*每次递归调用时先检查该(子)树是否为空树('#')起步*/
		if (ch == '#')/*遇到空树直接返回*/
		{
			T = 0;
		}
	/*递归主体:*/	
		else
		{
			T = (BTNode*)malloc(sizeof(BTNode));
			if (!T)/*内存申请失败.*/
			{
				return NULL;
			}
			T->data = ch;/*填充根节点信息*/
			/*T的左分支左侧递归:*/
			T->lchild = CreateTree();/*构造当前(子)树下一级的树(左子树)
									 CreateTree()返回子树根节点的地址(在递归回程(从最后一次递归出口回来执行之前未完的部分时)*/
				/*直到左侧递归结束后,右侧递归才可得到开始;即每次T->lchild得到返回值(空/非空指针)后,这一级的左子树就有了,
				继而去找右子树(换句话说,就是下一次处理的序列所返回的地址挂接到右子树上:*/
			/*左子树就有了,继而去找右子树*/
			T->rchild = CreateTree();/*构造右子树*/
		}
		/*当左右子树都收到返回值后,说明以这个结点T为根节点(gen'jie'dian)的子树已经构建(找)好了)
		即可返回该结点的指针*/
		return T;
		/*从底层到高层,先左子树后右子树,直到最原始的根结点.*/
	}
	/*这里描述一下返回原始根节点是的场景:T_orignal挂上最大左子树,再挂上最大右子树,返回T_orignal地址*/
}
/*（16）调试
按照提示要求，使用上述构建方法创建如下指定的二叉树。*/
void PreOrderTraverse(BTNode* root);
int main_11()
{
	// 方式1：逐个生成每个结点。

	// 生成二叉树1
	// 定义一个root指针，用来保存根结点， 
	BTNode* root1;

	// 定义一个curNode指针，用来指向root1之外的当前结点
	BTNode* curNode;

	printf("要手动插入二叉树1的序列:\n");
	// 生成根结点A，用root1指针指向该根结点
	root1 = CreateRoot(getchar());

	// 在A下插入左子结点B
	InsertLeftNode(root1, getchar());

	// 在A下插入右子结点C，用curNode指向C
	curNode = InsertRightNode(root1, getchar());

	// 在C下插入左子结点D
	InsertLeftNode(curNode, getchar());
	/*先序遍历打印(手动插入的二叉树1*/
	printf("先序遍历打印(手动插入的二叉树1;\n");
	PreOrderTraverse(root1);/*PreOrderTraverse(&root1);虽然该函数的参数确实为指针,但关键是
							root1变量本身也是指针,所以这里就不要再&root了,否则会出错*/
	
	printf("\n");
	///*由于getchar()会读取输入的空格,这导致连续输入测试多段代码是可能导致读到上一轮的残留输入;
	//可以多一个getchar()读走换行(更好的是清空输入缓冲区:fflush(stdin))*/
	//fflush(stdin);/*参数是文件流指针 FILE *stream ;但似乎没成功 */
	getchar();/*getchar()是可行的*/

	// 试生成二叉树2:

	BTNode* root2;
	printf("要手动插入二叉树2的序列:\n");
	root2 = CreateRoot(getchar());
	curNode = InsertLeftNode(root2, getchar());
	curNode = InsertRightNode(curNode, getchar());
	/*c*/
	curNode = InsertRightNode(root2, getchar());
	BTNode* C = curNode;
	/*E*/
	curNode = InsertLeftNode(curNode, getchar());
	/*G*/
	curNode = InsertRightNode(curNode, getchar());
	/*F*/
	InsertRightNode(C, getchar());

	// your codes

	printf("先序遍历打印(方式1:手动插入的二叉树2;\n");
	PreOrderTraverse(root2);
	printf("\n");
	getchar();
	// 方式2： 用先序次序生成二叉树
	/**/
	// 二叉树1的先序次序为  AB##CD###(空子树也要标识出来,每个叶子节点都要紧跟两个空树##;非满结点也要配有一个空树#)
	printf("要递归插入二叉树1的序列:\n");
	BTNode* root3 = CreateTree();
	printf("先序遍历打印(递归插入的二叉树1(root3);\n");
	PreOrderTraverse(root3);
	printf("\n");
	getchar();

	// 写出二叉树2的先序次序，并生成该树.ABD###CE#G##F##(利用补充虚树的方法来时操作统一起来.)
	printf("要递归插入二叉树2的序列:\n");
	BTNode* root4 = CreateTree();

	printf("先序遍历打印(递归插入的二叉树2(root4);\n");
	PreOrderTraverse(root4);
	printf("\n");

	printf("测试TotalNoLeafNodes(root4):\n");
	printf("非叶子结点数目:%d\n", TotalNoLeafNodes(root4));

	printf("测试TotalLeafNodes(root4):\n");
	printf("叶子结点数目为:%d\n", TotolLeafNodes(root4));

	printf("测试TotalNodes():\n");
	printf("该二叉树的结点数为:%d\n", TotolNodes(root4));

}


/*（17）二叉树的操作
（18）先序遍历
按照先序遍历的方式访问每一个结点，输出结点信息中的字符。*/
void Visit(BTNode* node)  // 访问某结点，这里仅输出结点中的字符
{
	printf("%c", node->data);
}

void PreOrderTraverse(BTNode* root) // 先序遍历
{
	// 若root非空，则先访问root，再按照先序遍历方式访问其左子树
	// 和右子树
	if (root)  //判断非空
	{
		/*双亲(一开始就打印出来.)*/
		Visit(root);   //访问该结点(打印传入的结点)而后对该结点的左子树(左孩子,若孩子为空,则切换到该结点的右子树孩子结点)调用遍历函数
		/*孩子(其次,左孩子优先于右,直到左孩子为空),切换到该孩子的右兄弟*/
		PreOrderTraverse(root->lchild);   //先序遍历的方式访问该结点的左子树(root为叶子结点时
		
		PreOrderTraverse(root->rchild);   //先序遍历的方式访问该结点的右子树
	}
	//printf("\n");递归函数里放这个不合适
}
void collect(/*将root结点里的字符数据保存到字符数组save中,该函数通用.*/
	BTNode* root,
	char* save)/*save要初始化(使之全为0*/
{
	save[strlen(save)] = root->data;
}
/*将先序遍历的结果保存到数组中*/
void SaveResult_PreOrderTraverse(BTNode* root, char* saveP)
{
	if (root)  //判断非空
	{
		collect(root, saveP);
	
/*孩子(其次,左孩子优先于右,直到左孩子为空),切换到该孩子的右兄弟*/
		SaveResult_PreOrderTraverse(root->lchild,saveP);   //先序遍历的方式访问该结点的左子树(root为叶子结点时

		SaveResult_PreOrderTraverse(root->rchild,saveP);   //先序遍历的方式访问该结点的右子树
	}
}
/*（19）  非叶子  结点数
写一个函数统计二叉树中的非叶子结点数目。*/
int TotalNoLeafNodes(BTNode* root)
{
	// 若root为空树，非叶子结点数为0
	if (!root) return 0;
	// 若root没有任何子树，则非叶子结点数也为0
	else if (!root->lchild && !root->rchild) return 0;

		// 否则，root结点 本身就是非叶子结点，还加上  其 子树的 非叶子结点数
	else
		return 1 + TotalNoLeafNodes(root->lchild)+TotalNoLeafNodes(root->rchild);
}
/*（20）二叉树深度
写一个函数求二叉树中的深度。*/
int TreeDeep(BTNode* root)
{
	// 如果root为空树，则深度为0
	if (!root) return 0;
	// 否则，需要先计算出其左右子树的深度，在深度大的值上再加上
	// root本身这一层，即为root指向二叉树的深度
	else
	{
		// 计算左子树深度
		int ld = TreeDeep(root->lchild) ;
		// 计算右子树深度
		int rd = TreeDeep(root->rchild);
		// 返回 root层对深度的贡献值 + 左右子树深度值中的大值
		return 1 + (ld > rd ? ld : rd);
	}
}

/*
递归:(从最简单的情况(往往时出口情况)开始
★★★★★★
递归链式填充构建二叉树(一棵大二叉树树可有左子树+右子树挂到根结点上形成)
递归遍历(输出)二叉树(输出一棵大树可以先输出左子树,再输出根结点(或右子树)
递归统计非叶子结点(一棵大的二叉树的非叶子结点由左子树的非根结点数+右子树的非根结点数+一个根结点数(非叶子结点的子树根结点)
递归统计结点总数(一棵大的二叉树的结点数可由左子树结点数+右子树结点数+一个根节点数)
这些可递归问题都有共同点:如果稍小规模的问题的结论(结果时已知的,且稍大点规模的问题的结果可以通过
对若干小规模问题的结果的简单运算的得到,那么递归理论上就可进行(有时候要安排下顺序),用小规模的例子测试下)
*/

/*
（21）中序遍历
按照中序遍历的方式访问每一个结点，输出结点信息中的字符。函数原型如下：*/
void InOrderTraverse(BTNode* root)
{
	if (root)
	{
		InOrderTraverse(root->lchild);/*第一个得到打印的是尽量底层且最左边的那个结点.*/
		/*其次回头打印根结点(双亲)结点*/
		Visit(root);
		/*最后才是右兄弟结点*/
		InOrderTraverse(root->rchild);
	}
}
/*将中序遍历的结果保存到数组中*/
SaveResult_InOrderTraverse(BTNode* root, char* save)
{
	if (root)
	{
		SaveResult_InOrderTraverse(root->lchild,save);
		collect(root, save);
		SaveResult_InOrderTraverse(root->rchild, save);
	}
}
/*（22）后序遍历
按照后序遍历的方式访问每一个结点，输出结点信息中的字符。函数原型如下：*/
void PostOrderTraverse(BTNode* root)
{
	if (root)/*如果传入的是一个叶子结点,那它的左右孩子root->lchild与root->rchild均为NULL,
			 即此时下面的两个ostOrderTraverse()函数的参数都为NULL,都将直接返回,Visit()得以执行.*/
	{
		PostOrderTraverse(root->lchild);

		PostOrderTraverse(root->rchild);
		Visit(root);
	}
}

/*（23）层次遍历
从根结点层开始，逐层从左至右访问二叉树的每一个结点。函数原型如下：*/
// 使用队列实现该算法，队列中的元素为BTNode的*类型
void LevelTraverse(BTNode* root)
{
	/*在层次遍历函数内部建立类似队列结构,这里定制一个指针数组queue*/
	BTNode* queue[MAXLEN];/*结点的指针数组*/
	int front, rear;/*队列的首元素和队尾元素在数组中的位置(索引)*/
	/*从最简单的情况开始:*/
	if (root == NULL) return;
	/*树非空*/
	front = -1;/*方便进入while*/
	rear = 0;
	/*根结点入队列(从尾部入)*/
	queue[rear] = root;
	while (front != rear)/*队列非空,继续遍历对头继续前进(用只有一个结点的树放进来试一下)*/
	{
		front++;/*进到队头元素的位置*/
		printf("%6c", queue[front]->data);/*访问队首结点的数据域*/
		
		/*将队首结点的左孩子结点入队列(如果有的话);这是下一层的结点了*/
		if (queue[front]->lchild != NULL)
		{
			rear++;
			queue[rear] = queue[front]->lchild;
		}
		/*将队首的有孩子结点入队列(如果右的话*/
		if (queue[front]->rchild != NULL)
		{
			rear++;
			queue[rear] = queue[front]->rchild;
		}
		/*以上两个入队列判断及操作相互独立*/
	}
}
/*（24）结点总数
计算二叉树中的结点总数。*/
int TotolNodes(BTNode* root)
{
	/*如果为空树,返回0*/
	if (!root)
	{
		return 0;
	}
	else/*非空:*/
	{
		return TotolNodes(root->lchild) + TotolNodes(root->rchild)+1;
	}/*当root为叶子结点时,可以运行到这里*/


}
/*（25）叶子结点数
计算二叉树中的叶子结点总数。*/
int TotolLeafNodes(BTNode* root)
{
	//若root为空树:
	if (!root)
	{
		return 0;
	}
	/*该层级(子)树的根结点非空,但其左右孩子均为空.这样的根结点也为叶子节点*/
	if (!root->lchild && !root->rchild)
	{
		return 1;
	}
	else
	{
		return TotolLeafNodes(root->lchild) + TotolLeafNodes(root->rchild);
	}
}
/*（26）二叉树重构(经典应用)(递归处理;主要工作为 :分析并处理结点序列(以便获得 小一级问题规模的递归调用的参数)+创建结点并正确挂接成树)
已知某二叉树的 先序和中序 遍历结果，试重构此二叉树。
 ppos为先序遍历的字符串，ipos为中序遍历的字符串，n为结点总数
 返回重构的二叉树根结点*/
/*思路:先从先序遍历结果序列ppos(序列构成为:根+左子树先根序列+右子树先根序列)中取出第一个结点r(树中的结点是不重复的),
在中序遍历结果序列ipos(序列构成为:左子树中根序列+根结点+右子树中根序列)中找到该结点r,再将中序遍历的结果以
结点r为整棵树的总根节点分为两侧(左侧为左子树,右侧为右子树),至此,
我们就得到小一级规模的两个子问题<左子树先根序列,左子树中根序列>以及<右子树先根序列,右子树中根序列>
循环操作,直到根结点左右子树结点序列不超过1个(tips,同一棵子树的不同序列的长度是一样长的!)
为了方便标识子树序列,引用两个指针来标识子树序列的起止.*/
/*这里子树与根结点挂钩可以是通过传入的二级指针(间接传参使得修改指针的结果离开函数后可以保留,参看<<编程之美>>);
本实验中是通过返回子树节点的地址来来实现挂钩. 
另外注意:每次递归调用,第一个参数来自先序遍历(子)序列,第二个参数来自中序序列的.  
操作结果是得到函数构建的唯一的一棵由先序序列和中序序列共同确定的一棵二叉树.(jin'kao)仅靠其中的一个序列是无法构建唯一的二叉树的.*/
BTNode* RestoreTree(
	char* ppos,/*pre_position,各级规模问题的先序遍历序列*/
	char* ipos, /*in_position 各级规模问题的中序遍历序列*/
	int n)/*各级规模问题的(子)序列的长度.
		  从编程之美学来的将函数原型里的参数换行,以便直接注释参数详细信息*/
{
	/*检查边界条件*/
	if (ppos == NULL || ipos == NULL)/*若传入的某个字符串为空*/
	{
		return;
	}
	/*获取前序遍历序列的第一个节点.*/
/*申请并创建节点*/
	BTNode* temp = (BTNode*)malloc(sizeof(BTNode));
	temp->data = *ppos;/*pPreOrder是字符串的首地址,那*pPreOrder就是字符串(第一个字符)*/
	temp->lchild = 0;
	temp->rchild = 0;
	/*如果当前树(传入的树序列长度)的长度为1,那么已经是最后一个节点(叶子节点)*/
	if (n == 1)/*能够传入重建函数,其值必定为不为0(至少为1)*/
	{
		return temp;/*正常出口(叶子节点的出口)*/
	}

/*准备小一级规模的参数:*/
	/*计算子树长度的准备,引入两个字符指针,初始化各量*/
	char* pOrgInOrder = ipos;/*Ipointer_Orignal_In_Order(数组名即地址)*/
	char* pLeftEnd = ipos;/*中序遍历结果序列字符串首地址*/
	int tempLen = 0;/*子树序列串的长度*/

	/*寻找左子树的结尾,同时统计子树序列长度*/
	while (*ppos != *pLeftEnd)
	{
		/*检查边界
		if (ppos == NULL || pLeftEnd == NULL)
		{
			return;//异常出口
		}

		tempLen++;*/

		/*记录长度,以免溢出
		if (tempLen > n)
		{
			break;
		}*/

		pLeftEnd++;
	}
	/*分别计算左右子树的长度*/
	/*左子树长度:*/
	int LeftLen = (int)(pLeftEnd - ipos);
	/*右子树长度:*/
	int RightLen = n - LeftLen - 1;/*(知二推三,母树长度为参数传入,已知,左子树长度又已求得,则右子树使前两者做差再-1(根结点)即可间接求得)*/

/*递归调用重建函数Restore();各调用的前两个参数注重首字符位置即可*/
	/*重建左子树*/
	if (LeftLen > 0)
	{
		 temp->lchild =  /*将下级调用的结果返回并挂接到当前调用里的 以当前temp结点为根结点的左子树子树位置上*/
			RestoreTree(
			ppos + 1,/*小一级规模问题的 先序序列字符串的首字符*/
			ipos,/*小一级规模问题的 中序序列字符串的首字符(发现构建左子树时总是ipos)*/
			LeftLen);/*该次调用处理的长度.*/
			/*内部不宜放置返回出口,否则只有一侧子树,右子树来不及创建*/
	}/*如果执行到此处,则将重建该级temp的右子树.*/
	/*重建右子树*/	
	if (RightLen > 0)
	{
		 temp->rchild = /*将下级调用的结果返回并挂接到当前调用里的 以当前temp结点为根结点的右子树位置上*/
			RestoreTree(
			ppos + LeftLen + 1,/*小一级规模问题的 先序序列字符串的首字符*/
			ipos + LeftLen + 1,/*小一级规模问题的 中序序列字符串的首字符*/
			RightLen);/*返回?*/
		 //return temp;
	}
	return temp;/*正常出口2(将当前挂接号左子树以及右子树的结点返回到它的上级调用里,以便挂接*/
	
}
/*（27）调试
根据提示调试二叉树的各项操作。*/


void main()
{
	// 生成二叉树1和二叉树2
	printf("输入二叉树1,2的先序序列('#'标识空树/空结点),构建二叉树1,2:\n");
	BTNode* T1 = CreateTree();
		getchar();
	BTNode*T2 = CreateTree();

	// 输出二叉树1和二叉树2的结点总数，叶子结点数，非叶子节点

	printf("测试TotalNoLeafNodes():\n");
	printf("非叶子结点数目:T1:%d T2:%d\n", TotalNoLeafNodes(T1), TotalNoLeafNodes(T2));

	printf("测试TotalLeafNodes():\n");
	printf("叶子结点数目为:T1:%d T2:%d\n", TotolLeafNodes(T1),TotolLeafNodes(T2));

	printf("测试TotalNodes():\n");
	printf("二叉树的结点数为:T1:%d T2:%d\n", TotolNodes(T2), TotolNodes(T2));

	// 树的深度。
	printf("测试TreeDeep():\n二叉树的深度为:T1:%d T2:%d\n", TreeDeep(T1), TreeDeep(T2));
	// 按照先序、中序、后序、层次四种方式输出二叉树1和2
	printf("测试先序遍历PreOrderTraverse():\nT1,T2:\n");
	PreOrderTraverse(T1);
	printf("\n");
	PreOrderTraverse(T2); printf("\n");
	printf("测试中序遍历InOrderTraverse():\nT1,T2:\n");
	InOrderTraverse(T1); printf("\n");
	InOrderTraverse(T2); printf("\n");
	printf("测试后序遍历PostOrderTraverse():\nT1,T2:\n");
	PostOrderTraverse(T1); printf("\n");
	PostOrderTraverse(T2); printf("\n");

	printf("测试层次遍历levelOrderTraverse():\nT1,T2:\n");
	LevelTraverse(T1); printf("\n");
	LevelTraverse(T2); printf("\n");

	// 将二叉树2的先序和中序遍历字符串保存到两个数组
	/*char* saveP = { 0 },
		* saveI = { 0 };*/
		/*这里需要是定义数组,与形参不同,char*save和char save[NUM]是不同的.*/
	char saveP[MAXLEN] = { 0 },
		saveI[MAXLEN] = { 0 };/*保存二叉树2 的中序遍历结果字符串*/
	// 根据这两个数组，重建 二叉树2
	SaveResult_PreOrderTraverse(T2, saveP);/*ABDCEGF*/
	SaveResult_InOrderTraverse(T2, saveI);/*DBAEGCF*/

	printf("将二叉树2的先序和中序遍历字符串保存到两个数组,这两个数组:先序序列%s和中序序列%s，\n重建 二叉树2\n以先序遍历的方式输出重建结果:\n",saveP,saveI);
	PreOrderTraverse(RestoreTree(saveP, saveI, strlen(saveP)));
	printf("\n");
	return 0;
}
//（28）二叉树的应用
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Huffman树的存储结构
#define n 5						//叶子数目
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
	char ch;					//存储字符(A,/B,/...)
	char bits[n + 1];		//存放 编码位串(0,1构成)
}CodeNode;
/*huffman树结点编码 整体树信息数组*/
typedef CodeNode HuffmanCode[n];/*定义新数组类型(规格也包含在新类型名称中)元素数目是Huffman树的叶子节点数目n*/

void InitHuffmanTree(HuffmanTree T);	//初始化Huffman树
void InputWeight(HuffmanTree T);		//输入权值
void SelectMin(HuffmanTree T, int i, int* p1, int* p2);
/*huffman树*/
void main_4()
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

	printf("请输入字符：");
	getchar();/*应该时读走之前输入留下的换行.(这样当然就不需要保存getchar()的返回值了)*/

	/*不妨先直接看for()(前头定义的辅助变量不急着看),在中途看到标识符的话将鼠标悬停在上面即可看到定义(如果有定义时的注释也可显示出来.*/
	for (i = 0; i < n; i++)		//依次求 叶子T[i] 的编码
	{
		H[i].ch = getchar();	//读入叶子T[i]对应的字符

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
		printf("第%d个字符%c的编码为%s\n", i + 1, H[i].ch, H[i].bits);
}


