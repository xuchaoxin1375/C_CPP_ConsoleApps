/*（8）调试
构建测试数据，在主函数中调用上述所有操作，运行并调试程序。

（3）思考
（1）动态数组(静态链表)
在当前的顺序表数据类型定义中，我们使用静态数组来存放元素，因而一个顺序表最多只能存放MAXLEN个元素。
为了存放更多元素，就需要能够对存放空间进行扩展。为了实现这一目标，我们可以使用动态数组来存放元素。
这时，顺序表数据结构类型可以定义如下： */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct
{
    int* elem; // 指向用来存放表元素的动态数组空间
    int size;  // 表明动态数组空间的大小
    int n;          // 定义一个变量，记录数组中实际存放的元素的个数
} intVec;
// /* 初始化时，为顺序表开辟一个固定大小的数组空间。当插入新元素时，
// 如果表存储空间已满，则重新开辟一个更大的数组空间（通常为原空间的两倍大小），
// 把原数组空间中存储的元素拷贝到新数组空间中，并用新数组空间代替原数组空间作为顺序表的存储空间，
// 进而可以把新元素放入到顺序表中。

// 尝试实现基于动态数组的顺序表及其常用算法。
// （2）顺序表的应用
// 目标：能够利用顺序表来解决一些实际应用问题。

// （1）集合求并
// 定义两个顺序表对象LA和LB，用户输入两组整数集合数据，并分别依次插入到顺序表LA和LB中。

// 实现算法，合并LA和LB中的数据，并把合并后的数据存放到LA中。
//最后，依次读取并输出LA中的数据元素。
void againMalloc(intVec* L);
void initList(intVec* L, int ms);
void insert_last_list(intVec* L, int x);
int search(intVec* LA, int e);
void UnionSet(intVec* LA, intVec* LB);
void batchInsertList(intVec* L);
void print(intVec* L);
void intersectionSet(intVec* LA, intVec* LB, intVec* LC);

int main()
{
    intVec LA, LB;
    intVec LC;
    printf("LA表的输入为:1 2 3 4 5 6 -1\n");
    batchInsertList(&LA);
    printf("LB表的输入为:3 4 5 6 7 8 9 -1 \n");
    batchInsertList(&LB);

    printf("测试并集函数UnionSet()\n");
    UnionSet(&LA, &LB);
    printf("并集结果LA:\n");
    print(&LA);

    //printf("测试交集函数intersection()\n");
    //initList(&LC,5);/*单独初始化LC表*/
    //intersectionSet(&LA, &LB, &LC);
    //printf("交集结果LC:\n");
    //print(&LC);
    
}
//顺序表的输出比链表的输出要简单些.
void print(intVec* L)
{
    int i = 0;
    for (i = 0; i < L->n; i++)
    {
        printf("%d ", L->elem[i]);
    }
}
/*批量插入(初始化并等待键盘输入)元素到顺序表中*/
void batchInsertList(intVec* L)
{
    int ms = 20;
    int i=0;
    initList(L, ms);
    printf("向顺序表里插入元素:\n");
    scanf("%d", &i);
    while (i != -1)/* -1作为结束输入的标志 */
    {
        insert_last_list(L, i);
        scanf("%d", &i);
    }
}
/* 向线性表L中第pos个元素插入x,若插入成功返回1,否则返回0 */
int insertPosList(intVec* L, int pos, int x)/* 比insert_last_list()使用范围更广更强大 */
{
    int i;
    /* 是否越界 */
    if (pos < 1 || pos > L->n + 1)
    {
        /* "pos越界,插入失败,返回0; */
        return 0;
    }
    /* 是否要拓宽空间 */
    if (L->n == L->size)
    {
        againMalloc(L);
    }/* 确保空间足够/仍然不够则会立即结束函数.againmalloc */

    for (i = L->n - 1; i >= pos - 1; i--)
    {
        L->elem[i + 1] = L->elem[i];
    }/* 已经腾出位置了 */
    L->elem[pos - 1] = x;/* 执行插入 */
    L->n++;/* 修正表长 */
    return 1;/* 插入成功返回1 */
}
// 合并两个顺序表的算法可通过如下函数实现： */
void UnionSet(intVec* LA, intVec* LB)
{
    /**********************************************************
    合并LA和LB所指向的两个顺序表对象中的数据，并把合并后的数据存放于LA中
    *********************************************************/
    int nA, nB, i, e;

    nA = LA->n; // 顺序表LA中的元素个数
    nB = LB->n; // 顺序表LB中的元素个数

    // 逐个读取LB中的元素：若该元素不在LA中，则把该元素插入到LA中
    for (i = 1; i <= nB; i++)/* 外层循环控制条件为待插入元素所在集合(链表)的元素个数 */
    {
        e = LB->elem[i - 1]; // 读取LB中的第i个元素
        if (search(LA, e) == -1)/*时间复杂度为O(n)*/
        {
            // 若该元素不在LA中
            insert_last_list(LA, e);     // 把该元素插入到LA的表尾
            nA++; // 记录LA中当前的元素个数
        }
    }
}
/*集合求交集:*/
void intersectionSet(intVec* LA, intVec* LB, intVec* LC)
{
    int i = 0;
    for (i = 0; i < LA->n; i++)
    {
        if (search(LB, LA->elem[i]) != -1)
        {
            insert_last_list(LC, LA->elem[i]);
        }
    }
}
void insert_last_list(intVec* L, int x)
{
    /* 插入表尾的话不用判断越界.但仍然要判断空间是否足够. */
    if (L->n == L->size)
    {
        againMalloc(L);/* 需要重新分配更大空间 */
    }
    L->elem[L->n] = x;/* 把x插入到表尾 */
    L->n++;/* 线性表长度+1 */
}
void againMalloc(intVec* L)
{
    int* p = (int*)realloc(L->elem, 2 * L->size * sizeof(int));
    if (!p)
    {
        printf("reallo failured !");
        exit(1);
    }
    L->elem = p;/* 使表头指针指向新分配的链表空间 */
    L->size = 2 * L->size;
}
void initList(intVec* L, int ms)/* 参数L届时在main()里头定义一个intVec类型的变量L,然后将该变量的地址&L传入initlist函数即可 */
{
    if (ms < 0)
    {
        printf("maxsize is illegal");
    }
    L->elem = (int*)malloc(ms * sizeof(int));
    if (!L->elem)
    {
        printf("malloc failured");
        exit(1);
    }
    L->size = ms;/* 设置线性表的空间大小为ms */
    L->n = 0; /*表中现有元素数为0 */
}
int search(intVec* LA, int e)
{
    int i = 0;
    for (i = 0; i < LA->n; i++)
    {
        if (LA->elem[i] == e)
        {
            return i;
        }
    }
    return -1;
}

// /* 
// （2）集合求交
// 类似地，可以编写两个集合求交程序。定义两个顺序表对象LA和LB，
// 用户输入两组整数集合数据，并分别依次插入到顺序表LA和LB中。实现算法，对LA和LB中的数据进行求交，
// 并将结果存放到一个新的顺序表对象LC中。最后，依次读取并输出LC中的数据元素。两个顺序表的求交算法可通过如下函数实现： */
// /**********************************************************
// 	对LA和LB所指向的两个顺序表中的数据进行求交，结果存放于LC中
// *********************************************************/
// void IntersectSet(intVec *LA, intVec *LB, intVec *LC);
// /* （3）综合练习
// 在具体应用程序中，可以使用顺序表来存储和管理数据。这里，要求实现一个简单的整数数据管理系统。基本要求如下：
// （4）构建一个简单的可交互系统，用户可以在系统中插入、删除和查找整数，并可统计系统中的整数个数；
// （5）使用顺序表来存储整数数据； */
