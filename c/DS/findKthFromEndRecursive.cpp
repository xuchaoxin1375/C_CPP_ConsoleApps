#include <stdio.h>
#include <stdlib.h>

// typedef struct LNode
// {
//     int data;
//     struct LNode *next;
// } LNode;

typedef int ElemType; // 链表数据的类型定义
typedef struct LNode
{                       // 链表节点的结构定义
    ElemType data;      // 节点数据
    struct LNode *next; // 节点链接指针
} LNode, *LinkList;

LNode *createNode(int value)
{
    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/**
 * @brief Searches for the k-th node from the end of a singly linked list recursively.
 *
 * This function takes a pointer to the head of a singly linked list and an integer k,
 * then finds and prints the data of the k-th node from the end of the list.
 * If the list has fewer than k nodes, it returns 0 indicating failure to find the node.
 * Otherwise, it prints the data and returns 1.
 *
 * @param list Pointer to the head of the singly linked list.
 * @param k The position from the end of the list to find.
 * @return int Returns 1 if the k-th node from the end is found and printed, otherwise returns 0.
 */
int Search_k(LinkList list, int k)
{                                           // 指针p、q指向第一个节点
    LNode *p = list->next, *q = list->next; // 初始化两个辅助指针,都指向首元(此时不保证首元非空)
    // 初始化很重要,不同的初始化方式会影响到后面的判断和条件语句,比如初始化为头指针和初始化为首元指针就不同
    int count = 0; // count用来统计p指针指向链表的第几个(非空)数据结点
    while (p != NULL)
    { // 遍历链表直到最后一个节点
        if (count < k)
            count++; // p指向的非空数据结点位置(当count达到k值时不再增加);显然count==k时,不会立即移动q
        else
            q = q->next; // 如果count < k只移动p(p指向第k+1个元素时,才会第一次移动q)
        p = p->next;     // p始终移动,当count到达k值 之后让p、q同步移动
    }
    // 离开while后p指向尾结点的后继（NULL)
    if (count < k) // 查找失败返回0(非空结点数量小于k)
        return 0;
    else
    {
        printf("%d", q->data); // 否则打印并返回1
    }
    return 1;
}

// 定义一个函数，用于递归地找到链表中倒数第 k 个节点
/**
 * Recursively finds the kth node from the end of a singly linked list.
 *
 * @param head Pointer to the head of the linked list.
 * @param k The position of the node from the end to find.
 * @param count Pointer to an integer that keeps track of the current position from the end.
 * @return Pointer to the kth node from the end if found, otherwise NULL.
 * head,count 会随着递归调用发生变换,而k值始终不变(可以考虑放到外面作为外部变量)
 */
LNode *findKthFromEndRecursive(LNode *head, int k, int *count)
{
    // 如果链表为空，则将计数置为 0，并返回 NULL
    if (!head)
    {
        *count = 0;
        return NULL;
    }
    // 递归地调用函数，处理下一个节点(当此处调用head->next为NULL时,开始回归)
    // 此时head是最后一个数据结点(非空),此返回返回NULL
    // 在count累计到k前,都是返回NULL,直到count累计到k,返回head(倒数第k个结点(非空)),
    // 之后的回归总是返回这个倒数第k个结点
    LNode *node = findKthFromEndRecursive(head->next, k, count);
    // 增加计数
    *count += 1; // 可以统计出链表长度
    // 如果当前计数等于 k，则返回当前节点(算法主要任务完成,继续回退)
    printf("count=%d\t", *count);
    if (node)
    {

        printf("node.data=%d\n", node->data);
    }
    else
    {
        printf("node=NULL\n");
    }
    if (*count == k)
    {
        printf("Get target node\n");
        return head;
    }

    // 否则，返回之前找到的节点
    return node;
}

LNode *findKthFromEnd(LNode *head, int k)
{
    int count = 0;
    return findKthFromEndRecursive(head, k, &count);
}
int Search_k(LinkList list, int k);

int main()
{
    // 创建不带头结点的单链表
    LNode *head = createNode(0);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);

    int k = 2;

    // LNode *kthNode = findKthFromEnd(head, k);

    // if (kthNode)
    // {
    //     printf("The %d-th node from the end is %d\n", k, kthNode->data);
    // }
    // else
    // {
    //     printf("The list is shorter than %d nodes.\n", k);
    // }

    Search_k(head, k);
    // 释放内存
    LNode *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
