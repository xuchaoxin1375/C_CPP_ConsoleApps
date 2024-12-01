#define ElemType int
// 结构体名字为LNode,完整引用为struct LNode,便于内部的指针域定义指针变量
//单链表
typedef struct LNode
{                       // 定义单链表结点类型
    ElemType data;      // 数据域
    struct LNode *next; // 指针域
} LNode, *LinkList;
/*
这里利用typedef 定义了两个别名，LNode为结构体类型，LinkList为结构体指针类型;
根据typedef的用法,LNode,*LinkList 表达式值都是struct LNode类型,因此,LNode是结构体类型,LinkList是结构体指针类型;
这样后续要定义LNode结点可以形如LNode node;
而定义LNode的指针变量形如LinkList node;这相当于LNode *node;这两种定义都表示node是指向LNode类型的指针变量;
也就是说LinkList从语法上和LNode*完全等价,也就是说,LinkList这个指针类型不是必须要的,定义结点指针时可以LNode*类型替代
但是对此做名字区分可以提高可读性,前者用来定义链表(作为头指针),后者作为一般性结点的指针变量定义时使用)

习惯上,LinkList 用来定义单链表的头指针;LinkList L;这表示我们定义了一个名为L的单链表(头指针);
LNode *node用来定义一个指向LNode类型的指针变量node;
这样的可读性比较好
*/

// 双链表
typedef struct DNode
{
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;
