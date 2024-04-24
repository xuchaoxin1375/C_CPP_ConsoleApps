#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct PloyNode
{
    int exp;
    int coef;/*coefficient/ˌkoʊɪ'fɪʃnt/ n.系数*/
    struct PloyNode* next; /* struct 关键字再定义链表时千万别漏 */
} Poly;
/*多项式的一项包括两个信息点:指数和系数(系数合并后可变化,指数合并后没有变(或者说就是公用啦)*/
// 实现带头结点的多项式的相加(传入的参数是带头结点的多项式单链表)
void add_poly(Poly* polya, Poly* polyb)
{
    Poly* p, /*多项式a的辅助指针*/
        * q,/*多项式b的辅助指针*/
        * pre, /*结果多项式链表的头指针,通过该该指针链接标识结果链表的表尾结点,以便加入新结点*/
        * temp;/*用于free()结点时暂存
               (pre指针是p指针的前驱,是为了在p前面插入新结点提供方便)*/
    int sum;
    /*使p,q分别指向多项式a与多项式b的表头结点*/
    p = polya->next;
    q = polyb->next;

    pre = polya;/*结果链表的表头与多项式a共用*/

    while (p != NULL && q != NULL)
    {
        /*p指针后移,q不动,回到循环继续比较下一场*/
        if (p->exp > q->exp)
        {
            /*一般的,在移动当前指针前先把当前值赋值给它的前驱节点指针(pre),然后才后移动当前指针p(形象的说,先等pre赶上来,p再后移*/
            pre->next = p;/*pre链接p作为后继结点*/
            pre = pre->next;/*pre指针前进一步(后移),这与直接些写作pre = p不同,(少了pre->next = p 结果链表就并不连续)
                            */
            p = p->next;/*p结点后移*/
        }//if_1
        /*(核心部分)处理指数相同的情况(合并p,q所指结点)
        (内部又分为:
        合系数为0(释放p,q 结点);
        合系数不为0(只要也记得要释放q结点).
        */
        else if (p->exp == q->exp)
        {
            sum = p->coef + q->coef;
            /*合系数不为0(更新结果链表的表尾结点pre,后移p,q 要记得要释放q结点)*/
            if (sum != 0)
            {
                p->coef = sum;
                /*后移指针pre(结果链表)*/
                pre->next = p;
                pre = pre->next;

                p = p->next;
                /*要释放到q所指结点(当然不能直接释放,可以应用辅助指针,标记要释放的那个节点,然后再安心后移q)*/
                temp = q;
                /*要在释放之前完成q的后移操作,否则移不了*/
                q = q->next;
                free(temp);
            }//if_2
            /*合系数为0(从结果链表(LA)中删除q结点,然后分别释放p,q 结点)*/
            else
            {
                /*借助辅助指针将p结点释放且实现后移p*/
                temp = p->next;//保存下一个结点的指针
                free(p);
                p = temp;
                /*同上*/
                temp = q->next;
                free(q);
                q = temp;
            }//else_2
        }//else if _1

        /*q所指结点在p结点之前尾插入到结果链表里*/
        else/*p->exp < q->exp */
        {
            pre->next = q;
            pre = pre->next;

            q = q->next;
        }//else_1
    }//while
    /*离开while后无非两种情况:p != NULL或者 p != NULL*/
    if (p != NULL)/*也可作!p*/
        pre->next = q;
    else
        pre->next = p;
}

//创建一个带头结点的多项式单链表
Poly* create_poly()/*创建并填充链表*/
{
    Poly* head,
        * tail,/*表尾节点可以用来指示新结点的前驱*/
        * p;

    int exp, coef;
    /*初始化辅助指针*/
    head = (Poly*)malloc(sizeof(Poly));/*申请头结点*/
    head->next = NULL;/*使头结点指向NULL*/
    tail = head;/*尾指针初始化为指向头结点*/

    scanf("%d%d", &coef, &exp);/*预读入两个数(循环之外),以便判断是否继续读入*/
    while (exp != -1 && coef != -1)
    {
        p = (Poly*)malloc(sizeof(Poly));
        if (p == NULL)
        {
            printf("Malloc failure\n");
            return NULL;
        }
        /*若成功申请到内存,向结点内写入数据*/
        p->exp = exp;
        p->coef = coef;
        p->next = NULL;

        tail->next = p;/*新结点接入到链表尾部*/
        tail = p;/*接入新结点后要更新修正尾指针*/
        scanf("%d%d", &coef, &exp);/*继续读取下一组数(循环之内)*/
    }
    return head;
}
/*遍历带头结点的单链表*/
void print_poly(Poly* head)
{
    for (head = head->next; head; head = head->next)
        printf("%d*x^%d ", head->coef, head->exp);
}
int main()
{
    Poly* p, * q;
    printf("Polynomial add:\n");
    printf("请按降序输入系数和指数,以-1 -1作为结的标记\n");
    printf("例如,多项式3x^9+6x^5-7x^2+9可以如下方式输入:\n");
    printf("3 9\n");
    printf("6 5\n");
    printf("-7 2\n");
    printf("9 0\n");
    printf("-1 -1\n");

    printf("请按以上方式输入第一个多项式:\n");
    /*调用create_poly()函数等待用户输入并创建链表.*/
    p = create_poly();
    printf("请按以上方式输入第二个多项式:\n");
    /*调用create_poly()函数等待用户输入并创建链表.*/
    q = create_poly();

    /*调用add_poly()函数合并多项式*/
    add_poly(p, q);

    printf("运行结果如下:\n");
    print_poly(p);
}

