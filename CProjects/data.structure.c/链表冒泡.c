#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_NONSTDC_NO_DEPRECATE

#define   EMPTY_rearUEUE_ERROR   -999999
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h> /*getch()所在头文件是conio.h。而不是stdio.h*/
#define MAXLEN 100
#define MAX  60  

typedef struct node
{
    int data;
    struct node *link;
}node;

/*带头结点的链表的冒泡(
    如果不带头结点,任然使用该函数,那么第一个元素(表头)将没有参加排序,可以考虑后期打个补丁,用直接插入的方法解决表头)
    或者,从外部创建一个头结点接上去拍好后在释放掉它*/
void bubblesort_link(const node*head)/*head是链表头结点(而非表头)*/
{
    node
    *pre,/* 前结点指针 */
    *p,/* 中结点指针p = pre->link; 排序关系表达式的LHS*/
    *rear,/*后节点指针*/

    *last;/*表尾结点指针*/
    last = head;
    /*找到表尾指针*/
    while(last->link)
    {
        last = last->link;
    }
    /*外层循环,控制循环次数/终止*/
    while(last!=head->link)/*last要回溯;head->link是const类型的*/
    {
        
        pre = head;/*每一轮开始,都将pre初始化尾head*/
        p = pre->link;/* p (jin'gen)紧跟pre其后(同时,每一轮开始前,都将其置为表头结点*/ 
        
        /*内层循环:LHS∈[head,last)(注意区间是左闭右开的,LHS为p的时候+)*/
        while(p!=last)/*p是主要的被比较对象;last是每轮比较范围的右边界范围也是针对p指针的;比较到p是last的前一个元素即可,last通过是rear来访问*/
        {
            rear = p->link;/*后指针rear紧跟p*/
            /*若前者大于后者*/
            if(p->data>rear->data)/* p是主要的被比较对象 */
            {
                /*执行链表节点的交换;修改三个指针.*/
                pre->link=rear;
                p->link = rear->link;/*顺序讲究,趁早访问第四个节点.*/
                rear->link = p;
                /*检查last是否该向前回溯一个元素:
                本轮的最后一次判断与操作可能使得右边界和边界的前驱发生交换,这就使得last所指的节点前移了一个元素.因此在这里要做一下修正(当然如果最后一次比较不发生交换,那也就不会进入到外层的if,不会执行多余的修正的.*/
                if(last==rear)/*本轮的最后一组比较且需要发生交换操作,则修正之.*/
                {
                    last = p;
                }//if(内)

            }//if(外)
            /*接下来为辅助指针找到/修正 所指的节点*/
            /*根据p与rear的比较是否发生交换,pre的更新可能仅两种,而无论是否发生位置交换,pre取的是rear和p中的较小者;*/
            pre = (p->data<rear->data)?p:rear;
            p = pre->link;/*链表的位置已经是调整好了的找到一个对应关系,其余顺藤摸瓜*/
            /*rear 的调整安排在while的开头*/
        }//while(内层);离开此处后,p == last;
        /*收缩右边界,将p的前驱pre 赋给last*/
        last = pre;

    }//while(外层)
}

