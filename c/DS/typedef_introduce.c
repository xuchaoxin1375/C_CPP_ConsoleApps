typedef struct Node
{
    int data;
    struct Node *next;
} Node;
typedef Node *LinkList;
//为了提高可读性,利用typedef和Node类型定义一个LinkList类型,效果:ListList L;等价于Node *L;

// typedef *Node LinkList;//这种定义是错误的

#define bool int
#define true 1
#define false 0
