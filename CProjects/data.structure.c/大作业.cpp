/*
1.设计数据结构
a)	每条航线所涉及的信息有：(填充5条航线,可以有相同的终点站但飞行日期等参数可以不同)
i.	终点站名、
ii.	航班号、
iii.飞机号、
iv.	飞机周日（星期几）、
v.	乘员定额、
vi.	余票量、

b)	订定票的乘客名单(已订票乘客的线性表应按乘客姓名有序)（包括
i.	姓名、
ii.	订票量、(显然取决于乘客的需求)
iii.舱位等级1，2或3）
c)	等候替补的乘客名单（包括
iv.	姓名、
v.	所需数量）。

2.	数据结构的基础上设计算法,使系统能实现的操作和功能如下：
1）	查询航线：根据乘客提出的 终点站名 输出如下信息：(读入用户输入,在各条航线里的对应成员相比较,若匹配则所有输出匹配航线的各项信息.)
i.	航班号、
ii.	飞机号、
iii.星期几飞行，
iv.	最近一天航班的日期和(将的到的所有匹配项,且日期大等于今日的航班做一个排序,并将最小日期输出)
v.	余票额；

2）	承办订票业务：根据乘客提出的要求（航班号、订票数额）查询该航班票额情况，
i.	若有余票，则为乘客办理订票手续，输出座位号；
ii.	若已满员或余票少余订票额，则需重新询问乘客要求。
a)	若需要，可登记排队候补；
3）	承办退票业务：根据乘客提出的情况（日期、航班号），为乘客办理退票手续，
i.	然后查询该航班是否有人排队候补，首先询问排在第一的乘客，若所退票额能满足他的要求，则为他办理订票手续，
ii.	否则依次询问其它排队候补的乘客。
*/

/*外部问题:如何设计界功能菜单,选中并进入功能菜单?
使用printf()+switch()语句实现
scanf("%d", &a);
switch (a)
{
case 1: ;
}*/
/*约定,search()是根据关键字查询与该关键字相关的元素的各项详情(返回详情).

是根据关键字查询有元素具有该关键字(返回是/否)*/
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h> /*getch()所在头文件是conio.h。而不是stdio.h*/
#define MAXLEN 100
#define MAX  60  
#define MAXNAME 10
/*  run   this
#define N 5/*航班号数量*/

/* 订定票的乘客链表结点结构 */
typedef struct LNode_Cer {
    char name[MAXNAME];/*乘客名字(订票的时候输入)名字的排序可以用插入的方式以保持有序*/
    int num_tickets;/*订票量*/
    int rank;/*仓位 等级class是保留字,用rank*/

    LNode_Cer* link;/*指针域*/
}LNode_Cer;/*link node of Certain */
/*航线链表的结点结构*/
typedef struct LFlightNode {
    char name_des[MAX];/*终点站名*/
    char flight_num[MAX];/*航班号:航班号某时某刻从某地飞往另一地的 航班航程的编号*/
    char plane_num[MAX];/*飞机号:飞机号相当于飞机的身份证*/
    int plane_weekday;/*星期几的航班*/

    int plane_crew;/*乘员定额(最大乘客量)*/
    int remaining_tickets;/*剩余票量*/
    /*三种等级仓位的价格int price[3]*/
    /*此外,可考虑还能够查出该航线由哪些乘客以及候补乘客
    LNode_Cer* customerName;
    LNode_Cer* candidateName;*/
    LFlightNode* next;
}LFlightNode;



/*等候替补乘客链队列节点*//*与顺序队列相比,就是队列结构里把数组用链表(头指针)替代(链表外置),虚拟指针用真正的指针替代*/
typedef struct  LQueueNode_Can {
    /*数据域(不同场景下条目可多可少,类型可以多样)*/
    char name[MAXNAME];/*候补乘客名字*/
    int num_tickets;/*该乘客需要的票数*/
/**/
    char flightNo[MAX];/*候补乘客想要的航班*/
    /*附加的指针域*/
    LQueueNode_Can* link;
}LQueueNode_Can;/*candidate*/

/*等待候补乘客链队列整体结构*/
typedef struct LQueue_Can {
    // LQueueNode_Can LQueue[MAXLEN];
    LQueueNode_Can* front;
    LQueueNode_Can* rear;
}LQueue_Can;

/*建立全局变量(在不至于混淆的情况下可以减少参数的传递)*/
/*任何函数都可访问到全局变量(不需要通过传参即可之间从内部访问)*/
LFlightNode* Head = NULL;/*第一个航班结点,初始化为NULL*/
LFlightNode* p2;/*航班辅助指针(指向表尾结点)(如果不设立该全局变量,要使用表尾时也可以同从头遍历找到表尾*/

LNode_Cer* LHead = 0;/*乘客链表表头表头*/
LNode_Cer* pLnow = 0;/*乘客链表表尾指针*/

LQueue_Can LQ = { 0,0 };/*//这里的LQ不设置为指针,而是一个 链队列 类型的 变量,
会分配一个LQueue_Can类型变量大小的内存给LQ.(内部含有两个指针的变量类型),不方便直接初始赋值*/

/*编写自定义基本操作函数时*/
/*假设函数的功能都能够实现,内容的具体实现待逻辑框架设计好后再作填充编写(函数原型的调整)
(如果某个预想函数不易一步实现,则届时可以拆分实现(复合实现)还原到研究问题的本质上*/

/*f初始化链表(可以让它构建一个头结点并返回节点的指针创建链表(可以考虑将他写为复合函数(包含插入函数))*/
/*初始化订定票乘客链表(建一个头结点,返回头结点指针)*/
//LNode_Cer* InitLNode_Cer()/*//无参有返回值带出结果的函数版本(也可以使有参(间接传参保存结果)的版本)*/
//{
//    LNode_Cer* LNode;/*只分配了一个指针的空间*/
//    LNode = (LNode_Cer*)malloc(sizeof(LNode_Cer));/*申请一个节点的空间*/
//    if (!LNode)
//    {
//        printf("malloc failed!\n");
//        exit(1);
//    }
//    LNode->name[0] = 0;
//    LNode->num_tickets = 0;
//    LNode->rank = 0;
//    LNode->link = NULL;
//    return LNode;
//}
/*初始化链队列(申请一个表头结点,并且将处理结果保存再LQ中)
void InitLQueue_Can(LQueue_Can* LQ )
{
    LQ->front = LQ->rear = (LQueueNode_Can*)malloc(sizeof(LQueueNode_Can));
    if (!LQ->front)
    {
        exit(1);
    }
    LQ->front->link = 0;
}
*/
/*插入新结点到队列尾*/
//void EnQueue(/**/LQueue_Can* LQ, char* name, int num_tickets)
//{
//    /*LQ->rear->link = (LQueueNode_Can*)malloc(sizeof(LQueueNode_Can));//直接挂钩新结点
//    scanf("%s", LQ->rear->name);
//    LQ->rear = LQ->rear->link;*/
//    /*如果引入辅助指针s,可以使得表达式更简洁(尽管步骤肯多点.*/
//    LQueueNode_Can* s = (LQueueNode_Can*)malloc(sizeof(LQueueNode_Can));
//    if (!s) exit(1);
//    strcpy(s->name, name);
//    s->num_tickets = num_tickets;
//    s->link = 0;
//
//    LQ->rear->link = s;
//    LQ->rear = s;
//}

/*初始化队列节点
LQueueNode_Can* InitLQueueNode_Can()
{
    LQueueNode_Can* LQNode;
    LQNode = (LQueueNode_Can*)malloc(sizeof(LQueueNode_Can));

    LQNode->name[0] = '\0';
    LQNode->num_tickets = 0;
    LQNode->link = NULL;
    return LQNode;
}*/
/*插入新元素到链表尾*/
//void InsertToLinkTail(LNode_Cer* pHead)
//{
//    LNode_Cer* LNode = (LNode_Cer*)malloc(sizeof(LNode_Cer));
//    if (!LNode)
//    {
//        printf("malloc failed!\n");
//        exit(1);
//    }
//    /*新结点内容写入*/
//    scanf("%s", LNode->name);
//    scanf("%d", &LNode->num_tickets);
//    scanf("%d", &LNode->rank);
//    /*找到链表尾部*/
//    while (pHead->link)
//    {
//        pHead = pHead->link;
//    }/*指向当前表尾元素*/
//    /*插入新节点*/
//    pHead->link = LNode;
//}


/*检查输入的航班号是否早已被占用,返会 是/否*/
int is_aready_have(LFlightNode* Head, char* flight_num)
{
    LFlightNode* p1 = Head;
    while (p1)
    {
        if (!strcmp(p1->flight_num, flight_num))
        {
            return 1;
        }
        p1 = p1->next;
    }
    return 0;
}
/*f录入航班号(在停止之前一直录入)
需要注意的的是,航班号必须唯一,若发现重复录入,应给予提示:*/
void input_flights()/*line_add*/
{
    LFlightNode* p1;
    LFlightNode* ptemp;/*保存新申请的结点内存的指针*/
    //p1 = Head;
    p2 = Head;
    char temp_flight_name[MAX];/*暂存输入的航班号名*/
    char c;/*接收是否继续录入的指令*/
    while (1)
    {
        printf("继续执行录入操作?(按y/Y以外的键退出.)\n");
        c = getch();
        if ((c != 'y' && c != 'Y'))
        {
            break;
        }
        /*创建并写入头结点*/
        if (Head == NULL)
        {
            p2 = (LFlightNode*)malloc(sizeof(LFlightNode));
            p2->next = NULL;
            Head = p2;/*获得表头结点(这一步只需执行一次)*/
        }
        else
        {
            p2 = p2->next = (LFlightNode*)malloc(sizeof(LFlightNode));/*shen'qing申请+插入到表尾+更新表尾结点指针*/
            //p2 = p2->next;/*gengxin更新表尾指针*/
            p2->next = NULL;
            /*这样直接赋值引发问题就是,p2被初始化为与Head一样地指向头结点,而头结点
            的指针域指向NULL,p2->next作为右值时就是NULL;p2->next作为左值时,
            是为了修改表头结点的指针域;
           */
           /*采用辅助指针ptemp的版本*/
           //ptemp = (LFlightNode*)malloc(sizeof(LFlightNode));
           //if (!ptemp) exit(1);
           //ptemp->next = NULL;/*初始化新结点的指针域*/
           //p2->next = ptemp;/*接入新结点*/
           ///*再更新表尾指针的对象*/
           //p2 = ptemp;
        }
        /*向新结点写入数据*/
        printf("\n输入终点站名:");
        scanf("%s", p2->name_des);
        /*测试链表连通性,暂时屏蔽一些内容的填充:*/
        printf("\n请输入唯一的航班号:");
        while (1)
        {
            /*scanf("%s", p2->flight_num);如果直接写入链表,那is_aready_have()就总返回已占用,所有要用临时变量暂存输入.*/
            scanf("%s", temp_flight_name);
            if (is_aready_have(Head, temp_flight_name))
            {
                printf("\n该航班号已被占用,请使用新的编号:");
            }
            else
            {
                strcpy(p2->flight_num, temp_flight_name);
                break;
            }
        }

        printf("\n输入飞机号:");
        scanf("%s", p2->plane_num);
        printf("\n输入出发出发日期(周几):");
        scanf("%d", &p2->plane_weekday);/*取成员->优先于取地址&*/
        printf("\n输入乘员定额:");
        scanf("%d", &p2->plane_crew);

        p2->remaining_tickets = p2->plane_crew;/*初始化余票额*/
        // scanf("%d", &p2->remaining_tickets);/*剩余票量由乘员定额-已被订购数决定*/

    }//while
}//input_flights()//目前读入功能正常
/**/
/*根据用户输入的终点站名,输出:航班号+飞机号+星期几飞行+最近一天的航班日期(额外开个函数,内部调用)+余票额*/
void print_flight_search()//line_search() 根据终点站名查找相关元素的详情.
{
    void print_closest_flight(int departure);
    char des_name[MAX];//临时接收一个名字字符串.
    LFlightNode* p1 = Head;/*p1用于遍历链表结点,一般被初始化为Head,表头开始遍历*/
    if (Head == NULL)
    {
        printf("\n\t        尚未录入任何航班数据,无法提供有效查询!");
        //getch();/*等待用户确认提示后按任意键返回;(也可直接返回)(提示信息已打印)
        return;
    }/*若已经录入一定信息*/
    printf("\n\t 请输入要查询的终点站名:");
    scanf("%s", des_name);
    printf("\n\t 查询结果:\n");
    int is_has = 0;/*标识是否找到符合条件的航班*/

    while (p1)
    {
        if (!strcmp(p1->name_des, des_name))
        {
            is_has++;
            printf("终点站名:%s\n航班号:%s\n飞机型号:%s\n星期:%d\n余票量:%d\n",
                p1->name_des, p1->flight_num, p1->plane_num, p1->plane_weekday, p1->remaining_tickets);
        }
        p1 = p1->next;
    }//while

    if (!is_has) printf("\n\tsorry,没有该航班");
    else
    {
        printf("\n\t输入要出发的日期(星期几),查询最近一天且未过期的航班:");
        int departure;
        scanf("%d", &departure);
        print_closest_flight(departure);
    }
    return;

}
/*配合print_search_ret()根据输入的终点打印最近一天的航班日期(当天即之后)
然而最小值并不一定只有一个!(二次遍历找到全部最小值*/
void print_closest_flight(int departure)
{
    LFlightNode* p1 = Head;
    LFlightNode* nearest_flight = p1;
    int delta = 0;
    int delta_min = 7;
    while (p1)
    {
        if (p1->plane_weekday >= departure)/*筛选本周未过期的航班*/
        {
            /* delta = p1->plane_weekday - departure > 0 ?
                     p1->plane_weekday - departure :departure - p1->plane_weekday ;
                 delta = p1->plane_weekday - departure;
                 if (delta < 0)
                 {
                     delta = -1 * delta;
                 }
             */
             /*找到最近的将来航班p.*/
            delta = p1->plane_weekday - departure;//必>=0
            if (delta < delta_min)
            {
                delta_min = delta;
                nearest_flight = p1;/*保存当前为止的最近航班指针*/
            }

        }//if
       /* else
        {//可忽略.
            printf("\n此航班已过期,应该输入今天及之后的出发日期");
        }*/
        p1 = p1->next;
    }//while

    /*输出所有满足条件的最近hangban(航班)*/
    p1 = Head;/*复位*/
    while (p1)
    {
        if (p1->plane_weekday == nearest_flight->plane_weekday)
        {
            printf("航班:%s\n日期:%d\n", p1->flight_num, p1->plane_weekday);
        }
        p1 = p1->next;
    }

}

/*航班查看(所有航班)函数 */
int Line_See_all()
{
    /*声明函数*/
    int Empty_Flight();
    LFlightNode* p1;
    //system("cls");此处cls函数导致屏幕打印混乱.(vs才可下正常运行.) ;/*清屏*/
    p1 = Head;
    /*打印前检查是否已录入航班信息被录入:*/
    if (Empty_Flight()) return 0;

    printf("\n\n\t           航班信息:\n");

    while (p1 != NULL)
    {
        {
            printf("终点站名:%s\n航班号:%s\n飞机型号:%s\n星期:%d\n余票量:%d\n\n",
                p1->name_des, p1->flight_num, p1->plane_num, p1->plane_weekday, p1->remaining_tickets);/*如果将整型数以%s输出会出错*/
        }
        p1 = p1->next;
    }
    printf("\n\t      按任意键确认返回！\n");
    getch();
}
/*判断航班是否为空函数(菜单调转)  */
int Empty_Flight()
{
    if (Head == NULL)
    {
        //system("cls");此处cls函数导致屏幕打印混乱.(vs才可下正常运行.) ;
        printf("\n\t       sorry,尚不存在航班，按任意键返回！");
        getch();
        return 1;
    }
    else return 0;
}
/*操作异常/非法提示*/
void Error_warning()
{
    printf("\n\t遇到非法或异常操作!\n");
}

/*承办业务系(订票)函数
首先查找是否有对应航班;
若有对应航班,检查是否有余票,若有,询问要订购几张票*/
/*对已定票的乘客名单按名字进行排序*/
void Lsort_names(/*LNode_Cer* LHead*/)//经调试,可正常工作.(调试排序算法,可以在两个循环处+边界收缩处各打一个断点,用一组降序数来试)
{
    LNode_Cer* pp,
        * p,
        * q,
        * last,
        * HHead;/*外加头结点*/
    /*创建头结点:*/
    HHead = (LNode_Cer*)malloc(sizeof(LNode_Cer));
    HHead->link = LHead;
    last = HHead;
    /*通过遍历,使得last被初始化为表尾指针*/
    while (last->link)
    {
        last = last->link;
    }
    /*外层循环*/
    while (last != HHead->link)/*控制排序趟数,last走到表头前,继续比较*/
    {
        pp = HHead;
        p = pp->link;
        /*内层循环(last是右元素的右边界)*/
        while (p != last)/*直到:q == last进入循环并完成比较)(即右边界参与了比较),随后p,q都再向后移动一个元素,这时要离开了,判断条件为p == last*/
        {
            q = p->link;
            if (strcmp(p->name, q->name) > 0)
            {
                pp->link = q;/*1接3*/
                p->link = q->link;/*2接4*/
                q->link = p;/*3接2*/
                /*在必要时修正被悄然前调的last*/
                if (last == q)
                {
                    last = p;
                }//if

            }//if
            pp = (strcmp(p->name, q->name) < 0) ? p : q;
            p = pp->link;

        }//while(内存)

        last = pp;/*last向前回溯*/

    }//while(外层)
    LHead = HHead->link;
    free(HHead);/*释放掉补偿的头结点HHead*/
    return;
}
/*询问是否参加候补+登记候补*/
void inquiry_enroll_candidate(int num_book, char* flight)
{

    {
        /*加入候补队列*/
        /*在本函数之外就将准备好一个初始化完毕的队列,以便随时插入.*/
        printf("输入您的名字:");
        if (LQ.front == 0 && LQ.rear == 0)/*链队列的队头与队尾指针同时为NULL,为空队充分但不必要条件(与具体的实现有关)*/
        {/*处理队头*/
            /*在入队列的过程中,为队头front赋值只执行一次即可.*/
            LQ.front = LQ.rear = (LQueueNode_Can*)malloc(sizeof(LQueueNode_Can));
            /*专门填充队头元素*/
            scanf("%s", LQ.rear->name);
            LQ.rear->num_tickets = num_book;
            LQ.rear->link = 0;

        }
        else/*处理队身*/
        {
            // EnQueue()入队列(尾)
            /*不用辅助指针s*/
            LQ.rear->link = (LQueueNode_Can*)malloc(sizeof(LQueueNode_Can));/*申请新结点的同时+入队列(写入到当前节点的指针域)*/
            LQ.rear = LQ.rear->link;/*加入新结点空间后,更新表尾指针*/
            /*及时初始化节点的指针域*/
            LQ.rear->link = 0;
            /*向新结点写入信息*/
            scanf("%s", LQ.rear->name);
            LQ.rear->num_tickets = num_book;
            strcpy(LQ.rear->flightNo, flight);/*该语句中入股flight是乱七八糟的东西可以导致尾节点指针域混乱(由NULL变成其他的东西)*/

           // printf("\nobserve");
            /*使用辅助指针s可以时表达式更短.*/
//s = (LQueueNode_Can*)malloc(sizeof(LQueueNode_Can));
//if (!s) exit(1);
//                  /*向新结点写入信息*/
//                  scanf("%s", s->name);
                  //s->num_tickets = num_book;
//                  strcpy(s->flightNo, flight);/*原本想订的航班号:*/
//                  /*新结点入队列*/
                  //LQ.rear->link = s;
                  //LQ.rear = s;/*更新队尾指针*/
        }//else/*处理队身*/

    }//if(若参与候补,否则pass该乘客,询问下一位乘客)

    //printf("\nobserve");
    return;
}//inquiry_enroll_candidate

/*判断用户输入的 航班号+订票数量 检查对应航班是否有余票,同时办理订票+询问候补需要*/
void booking()
{
    /*声明函数:*/
    int find_flight_route(char* flight, LFlightNode * *Psave
    /*若找到对应航班,则将结果写在变量Psave中*//*LFlightNode* Head  Head是全局变量 无需传参即可使用*/);
    char c;/*接收用户选择*/
    char flight[MAX];
    int num_book = 0;
    LFlightNode* Psave = 0;/*通过函数find_flight_route(),
                           将找到的航班结点的指针带回(修改Psave)*/

    LQueueNode_Can* s = 0;

    if (Empty_Flight())
    {
        return;
    }
    printf("\n当前可以订票");
    while (1)
    {
        printf("\n输入行班号:");
        scanf("%s", flight);
        if (!find_flight_route(flight, &Psave))
        {
            printf("sorry,没有该航班!");
        }

        else if (Psave->remaining_tickets)/*找到该航班,检查改航班是否满员*/
        {
            printf("尚有余票,输入您想要定的票的数量:\n");
            scanf("%d", &num_book);
            if (num_book < Psave->remaining_tickets)/*余票chongzu充足*/
            {
                /*满足该乘客需求,登记购票*/
                printf("余票数量充足\n输入您的名字:");
                /*创建并向链表头写入数据*/
                if (!LHead)
                {
                    pLnow = (LNode_Cer*)malloc(sizeof(LNode_Cer));
                    LHead = pLnow;/*保存头结点指针;pLnow 是辅助指针(而且是全局变量(可不必全局)*/
                    pLnow->link = 0;/*初始化新结点的指针域*/
                }
                else/*链表身体*/
                {
                    /*直接从当前节点接收新节点内存地址.(直接挂接到表尾.)*/
                    pLnow->link = (LNode_Cer*)malloc(sizeof(LNode_Cer));
                    pLnow = pLnow->link;/*更新pLnow*/
                    pLnow->link = 0;/*初始化新结点的指针域*/
                    /*引入辅助指针+初始化新结点的指针域:*/

                }
                /*向新节点内写入内容*/
                pLnow->num_tickets = num_book;
                scanf("%s", pLnow->name);
                printf("购买几等票:");
                scanf("%d", &pLnow->rank);


                Psave->remaining_tickets -= num_book;
                /*输出座位号:*/
                printf("您的座位号:%d\n\n", Psave->plane_crew - Psave->remaining_tickets);
            }//if
            else/*余票不足*/
            {
                char c;/*接收用户选择*/

                char isCandidate;

                printf("余票不足,是否加入候补?(按y/Y)\n");
                isCandidate = getch();
                if (isCandidate == 'y' || isCandidate == 'Y')
                    inquiry_enroll_candidate(num_book, flight);
            }//else/*余票不足*/


            printf("\n是否继续订票?\n输入y继续"); c = getch();
            if (c != 'y')
            {
                break;
            }//跳出(连续订票循环)
        }//if(若有余票)
    }//while(连续订票循环)

    /*订顶票乘客非空,则为乘客链表排序*/
    if (LHead)
        //Lsort_names(LHead);
        /*需要纠正的观念是,如果全局变量当初本地变量传入参数的话,可能使得修改白费(优先识别为传值传参),
        实在要传参,用间接传参&Head,函数声明可为Lsort_names(LNode_cer**)
        函数原型可为(LNode_cer** ppnode/LHead)*/
    {
        Lsort_names();
    }
}//booking()

/*按航班号查找航班,若找到,返回1,并且将航班结点指针记录到Psave中;
为了带回多个/多种 结果,使用指针间接传参*/
int find_flight_route(
    char* flight,
    LFlightNode** Psave/*若找到对应航班,则将结果写在变量Psave中*/
/*LFlightNode* Head  Head是全局变量 无需传参即可使用*/)
{
    LFlightNode* p1 = Head;
    while (p1)
    {
        if (!strcmp(p1->flight_num, flight))
        {
            (*Psave) = p1;/*保存找到的航班号的指针,以便修访问该结点*/
            return 1;/*表示已找到*/
        }
        p1 = p1->next;
    }
    return 0;
}


/*承办退票业务系函数*/

///*判断是否有对应航班*/
//int is_find_flight(char* refund_flightNo)
//{
//    LFlightNode* p1 = Head;
//    while (p1)
//    {
//        if (strcmp(refund_flightNo, p1->flight_num))
//        {
//            return 1;
//        }
//        p1 = p1->next;
//    }
//    return 0;
//}

/*根据传入的某个节点的指针,删除名单链表节点操作*/
void DeleteLNode_cer(LNode_Cer* p)/**/
{
    LNode_Cer* pre = LHead;
    /*特殊处理头结点的删除*/
    if (p == LHead)
    {
        LHead = LHead->link;
        free(pre);
        return;
    }
    /*寻找pre的正确位置*/
    while (pre)
    {

        if (pre->link == p)/*先找到要被删除的节点的 前驱节点pre*/
        {
            break;
        }
        pre = pre->link;/*没找到的话继续往后找*/
    }

    pre->link = p->link;
    free(p);
}
/*删除队头*/
void DeLQueueNode(LQueueNode_Can** pre)
{
    LQueueNode_Can* p1 = 0;
    /*LQueueNode_Can* pre = LQ.front;*//*用于辅助删除队列元素(由于链队列使用的空间是即使申请/释放的,
                                   不用考虑空间闲置的浪费问题(无需循环结构)*/
                                   /*在候补队列中删除该名字*/
    p1 = *pre;
    *pre = (*pre)->link;/*队头前进.*/
    free(p1);/*释放旧队头节点*/
    return;
}
/*遍历询问候补乘客,直到遇到被退票(的航班)能够满足需求/都不满足需求为止,候补成功接受则要在候补队列中删除改名字*/
void inquiry_can_satisfy(LFlightNode* Psave)
{
    char c;
    printf("\n询问候补乘客,直到遇到被退票(的航班)能够满足需求/都不满足需求为止");
    LQueueNode_Can* p1 = 0;
    LQueueNode_Can* pre = LQ.front;/*用于辅助删除队列元素(由于链队列使用的空间是即使申请/释放的,
                                   不用考虑空间闲置的浪费问题(无需循环结构)*/
    int num_book = 0;
    char flight[MAX];
    while (pre)
    {
        printf("\n航班%s是否能够满足您的目的地?(若是,输入y,并为您办理订票):", Psave->flight_num);
        c = getch();
        if (c == 'y')
        {
            booking();
            /*在候补队列中删除该名字*/
            DeLQueueNode(&LQ.front);/*注意参数写成&pre无法正确更改队头指针,当然可以尝试:DeLQueueNode(&pre);LQ.front=pre;*/
            printf("\n补办完成");
            return;
        }
        else
        {
            /*再次询问是否重新加入候补?*/
            char c;/*接收用户选择*/;

            char isCandidate;

            printf("\n余票不足,是否重新加入候补?(按y/Y)\n");
            isCandidate = getch();
            if (isCandidate == 'y' || isCandidate == 'Y')
            {
                printf("\n输入您想候补的航班号:");
                scanf("%s", flight);
                printf("\n输入您想要订的票数:");
                scanf("%d", &num_book);
                inquiry_enroll_candidate(num_book, flight);
                printf("\n候补完毕!");
            }

            /*否则删除该结点*/
            DeLQueueNode(&pre);
        } //else(仍不满足需求).           
    }//while(pre)遍历询问候补乘客
    printf("\n未满足任何以为候补顾客的需求.");
}

/*根据用户提交的 航班号+日期,将对应票回收+1,删除已订票乘客名单里的名字;*/
void refund()
{
    /*char* refund_flightNo[MAX];糊涂了*/
    char refund_flightNo[MAX];
    char name[MAX];
    int refund_tickets_num = 0;/*保存被退的票的数量*/
    LNode_Cer* p1 = LHead;/*在名单中找到乘客名字*/
    LFlightNode* Psave;
    /*检查是否已录入航班信息,否则无法退票*/
    if (Empty_Flight()) return;

	while (1)/*直到输入正确的可退票行班,离开循环.*/
	{
		printf("\n\t可进行退票手续\n请输入您要退订的航班:");
		scanf("%s", refund_flightNo);
		if (find_flight_route(refund_flightNo, &Psave))/*搜索是否有对应航班号*/
		{
            /*约定:这里的名字是指是个人 名字+身份ID号综合体 的简称(比如 chaoxin_1375,是具有唯一性的主关键词*/
            printf("\n输入您的名字:");
            scanf("%s", name);
            printf("\n正在查找您的名字...\n");
            if (!p1)
            {
                printf("\nsorry,没有该名字,请重新确认.\n");
                return;/*二级菜单*/
            }
            while (p1)
            {
                if (!strcmp(p1->name, name))
                {
                    refund_tickets_num = p1->num_tickets;

                    /*执行删除操作(删除p1)*/
                    printf("执行删除操作...\n");
                    DeleteLNode_cer(p1);
                    break;
                }
                p1 = p1->link;
            }//while(p1)

            printf("名字_ID 删除完毕\n");
            printf("\n回收机票...");
            /*回收机票*/
            Psave->remaining_tickets += refund_tickets_num;
            break;//离开外层循环
        }//if
        else
        {
            printf("\nsorry,没有找到该航班!请重新输入:");
            
        }
    }//while(1)
    printf("\n询问候补乘客的需求:\n");
    inquiry_can_satisfy(Psave);

}//refund()



/*主要复合函数*/
/*航班管理函数*/
void flightNo_manage()
{
    char c;
    //system("cls");此处cls函数导致屏幕打印混乱.(vs才可下正常运行.) ;/*清楚屏幕内容准备当前菜单的打印*/
    while (1)
    {
        printf("\n\t\t          航班管理菜单:\n");

        printf("\n______________________________________________________________\n");
        printf("\t    1.                添加新的航班\n");
        printf("\t    2.                查询航班    \n");
        printf("\t    3.                查看航班    \n");

        printf("\t    4.               返回主菜单  \n");

        printf("\n\n______________________________________________________________\n");
        printf("\t       请选择您想要的服务(回车确定):");
        scanf("%c", &c);
        switch (c)
        {
        case '1': input_flights(); break;/*添加新的航班*/
        case '2': print_flight_search(); break;/*查询航班*/
        case '3': Line_See_all(); break;/*查看航班(全部)*/
        case '4': return;
        default: Error_warning();
        }//switch()
    }//while

}
/*查看当前乘客订单信息*/
void customer_check()
{
    char c;
    LNode_Cer* p1 = LHead;
    LQueueNode_Can* pQ = LQ.front, * pQrear = LQ.rear;
    printf("\n当前乘客订单信息");
    printf("\n\t1.订定票乘客信息");/*xin'xi*/
    printf("\n\t2.候补乘客信息");

    printf("\n\t选择您要的服务:");
    c = getch();
    switch (c)
    {
    case '1':
        printf("\n订定票乘客信息\n按 名字_ID 主关键字升序排列:\n");
        while (p1)
        {
            printf("\n\n乘客姓名:%s\n订票量:%d\n舱位等级:%d", p1->name, p1->num_tickets, p1->rank);
            p1 = p1->link;
        }
        break;/*如果不break,将总是会执行case'2'*/
    case '2':
        printf("\n候补乘客信息:");
        if (!pQ /*|| LQ.rear->link == pQ*/)
        {
            printf("\n当前无候补乘客.");
        }
        while (pQ)
        {
            printf("\n乘客姓名:%s\n订票量:%d\n", pQ->name, pQ->num_tickets);
            pQ = pQ->link;
        }
        break;
    default:
        break;
    }

}

/*主函数*/
int main()
{
    char c;/*接收一个字符,进入选中的菜单项*/
    do {
        //system("cls");//此处cls函数导致屏幕打印混乱.(vs才可下正常运行.) 
        printf("\n\t\t 航空客运订票主系统菜单\n");

        printf("\t1.航班管理子菜单\n");
        printf("\t2.订票办理子菜单\n");
        printf("\t3.退票办理子菜单\n");
        printf("\t4.乘客信息查看子菜单\n");
        printf("\t5.退出\n");
        /*
       printf("\n\t请选择您想要的服务并回车确定:");
       scanf("%c", &c);*/
        printf("\n\t\t请选择您想要的服务:");
        c = getch();
        /*用switch执行调用相应函数执行相应功能*/
        switch (c)
        {
            /*在4个复合函数中选择*/
        case '1': flightNo_manage(); break;/*航  班  管  理 (增) 菜  单*/
        case '2': booking(); break;/* 订  票  办  理 (增) 菜  单*/
        case '3': refund(); break;/*退  票  办  理 (增/删/查) 菜  单*/
        case '4':customer_check(); break;/*/'kʌstəmər/*/

        case '5': exit(0);/*退出系统*/
        default:; break;
        }  //switch

    } while (c != '5');
    return 0;
}

