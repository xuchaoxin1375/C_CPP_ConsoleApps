#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 初始化链表并从数组创建链表
Node *createList(int arr[], int size)
{
    // 使用尾插法创建链表,创建链表的时间复杂度为O(n),一个尾指针来辅助(否则时间复杂度会上升值O(n^2))
    Node *head = (Node *)malloc(sizeof(Node)); // 创建头结点
    head->next = NULL;                         // 初始化头结点的next指针为空

    Node *current = head; // 定义辅助的当前指针(或称为尾指针),初始化为指向头结点

    for (int i = 0; i < size; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node)); // 创建新节点
        newNode->data = arr[i];                       // 设置数据
        newNode->next = NULL;
        current->next = newNode; // 链接新节点到链表尾部
        current = newNode;       // 移动当前指针到新节点
    }

    return head; // 返回带头结点的链表
}

// 逆序链表函数
void reverseList(Node *head)
{
    Node *prev = NULL;          // 指示被逆序部分的新序列(链表)的表头(从NULL开始,头插法);刚开始时没有元素完成逆序,因此已被逆序的部分为空
    Node *current = head->next; // 指示逆序进度(当前要被逆序的结点),跳过头结点(从首元开始)
    Node *next = NULL;          // 作为current的后继(能够直接初始化为next=current->next),因为首元结点还没判断是否非空;

    // prev,next在第一次循环中进行第一次更新值
    while (current != NULL)
    {
        next = current->next; // 保存下一个节点
        current->next = prev; // 反转指针(将current的后继指针指向prev,current结点的逆序就完成了);注意第一个被反转的结点将作为新序列的尾结点,其后继为NULL,循环的主要工作是从NULL(尾结点开始)找到前驱,然后修改前驱结点的后继指针;
        // 推进进度并维护指针间的逻辑关系
        prev = current; // 更新prev指针(pre新序列的表头)

        current = next; // 向后移动current指针

        // next=next->next;//这个语句需要确保next不是NULL,否则会报错;此外,前面next赋值给了current,next=next->next;等价于next=current->next;然而这需要确保current不是NULL,否则会报错,而对于循环而言,while(current!=NULL)正好能做这个检查,所以这个工作就留给下一次循环处理
    } // 循环的核心是指针反转current->next=prev和current=next推进逆序进度,其余语句维护指针的语言(逻辑关系)以便进行下一个循环

    head->next = prev; // 头结点指向新的头部（原尾节点）
}

// 打印链表函数
void printList(Node *head)
{
    Node *current = head->next; // 跳过头结点
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void printList_NoHeader(Node *head)
{
    Node *current = head; // 跳过头结点
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
// 释放链表内存
void freeList(Node *head)
{
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp); // 释放节点内存
    }
}
// 寻找单链表的中间节点
Node *findMiddleNode(Node *head)
{
    Node *slow = head->next; // 慢指针从头结点后面开始
    Node *fast = head->next; // 快指针从头结点后面开始

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void change_list(Node *h)
{
    Node *p, *q, *r, *s; // 定义4个辅助指针;(前2个确定中间结点和尾结点);r辅助逆序后半段链表,s用于后边段链表的遍历指针
    p = q = h;           // 将p,q都初始化为h
    printList(h);
    // q前进到速度是p的两倍(p是慢指针,q是快指针)
    while (q->next != NULL)
    { // 寻找中间节点(这里p在结点数量为奇数时n/2+1)
        p = p->next;
        q = q->next;
        // print p,q
        // printf("p,q: %d,%d\n", p->data, q->data);
        // 为了避免q->next为NULL,q执行第二步前进需要再判断q->next!=NULL,才能再前进一步
        if (q->next != NULL)
            q = q->next; // 条件允许时q再走一步
        // printf("p,q: %d,%d\n", p->data, q->data);
        // printf("\tq:%d\n", q->data);
    } // 至此,p->next是后半部序列的首元,而q是尾元
    // printList_NoHeader(p->next);
    // printList(h);
    q = p->next;    // p所指节点为中间节点，其后继赋值给q为后半段链表的首节点
    p->next = NULL; // 中间结点的后继置为NULL,即L前半段的尾指针的后继为NULL;此后p作为已逆序的部分链表的首元指针,作为头插法着陆点

    while (q != NULL)
    { // 将链表后半段逆置

        r = q->next; // q的后继赋值给辅助指针r
        q->next = p; // 未逆序的部分链表首元后继改为已逆序部分的首元
        // 维护指针间的逻辑关系,以便下一轮操作
        p = q; // 迭代已逆序部分的首元指针
        q = r; // 迭代未逆序部分的首元指针
    } // p此时指向后半段链表的首元(尾元是前半段的尾元(重叠))
    printf("reverse result of first half list:");
    printList(h);
    printf("reverse result of later half list:");
    printList_NoHeader(p);
    /* 准备重排 */
    // 准备两段链表的首元指针
    s = h->next; // s指向前半段的第一个数据节点，即插入点
    q = p;       // 指向后半段的第一个数据节点

    while (s->next != NULL) // 第一个链表长度可能短一个元素(总链表长度为偶数的时候);为了防止循环内赋值空指针造成segment fault(运行时难以察觉的错误),这里用s->next!=NULL判断是否进入循环;
    {                       // 将链表后半段的节点插入到指定位置
        r = q->next;        // 将q插入到前半段链表前,标记q的后继,即指定指向后半段的下一个节点备用
        q->next = s->next;  // s后继交接给q:将q所指节点插入到s所指节点之后
        s->next = q;        // s的新后继为q;
        printf("s,q: %d,%d\n", s->data, q->data);
        // 更新下一个带插入结点的前驱
        s = q->next; // s指向前半段的下一个插入点
        q = r;       // 更新第二段链表中下一个要插入的节点(第二段链表的首元)
        // print s,q
        // printf("s,q: %d,%d\n", s->data, q->data);
    }
    // 退出时第二段链表可能尾结点多出来了, 实际上两段链表尾结点重合(相同),检查第一段尾结点取值和第二段相同位序结点q数据是否相同,如果不同,那么就接上,并且尾结点置空,否则就不用接了(第一段的尾结点作为做终链表的尾结点,其后继为NULL)
    if (s->data != q->data)
    {

        q->next = NULL;
        s->next = q;
    }
    // if()
    printf("resort res:\n");
    printList(h);
}
// 测试函数
int test_reverse()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};       // 初始化数组
    int size = sizeof(arr) / sizeof(arr[0]); // 计算数组大小
    Node *head = createList(arr, size);      // 创建链表

    printf("原链表: ");
    printList(head);

    reverseList(head); // 逆序链表

    printf("逆序后的链表: ");
    printList(head);

    freeList(head); // 释放链表内存

    return 0;
}
int test_middle()
{
    int arr[] = {1, 2, 3, 4, 5};             // 初始化数组
    int size = sizeof(arr) / sizeof(arr[0]); // 计算数组大小
    Node *head = createList(arr, size);      // 创建链表

    Node *middle = findMiddleNode(head);
    printf("中间节点的数据: %d\n", middle->data);
    freeList(head); // 释放链表内存

    return 0;
}
int main(int argc, char const *argv[])
{
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8}; // 初始化数组(偶数个结点)
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // 奇数个结点

    int size = sizeof(arr) / sizeof(arr[0]); // 计算数组大小
    Node *head = createList(arr, size);      // 创建链表

    change_list(head);
    // printList(head);
    
    freeList(head); // 释放链表内存
    return 0;
}
