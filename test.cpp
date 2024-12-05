#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

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
int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5};             // 初始化数组
    int size = sizeof(arr) / sizeof(arr[0]); // 计算数组大小

    Node *head = createList(arr, size); // 创建链表

    Node *middle = findMiddleNode(head);
    printf("中间节点的数据: %d\n", middle->data);
    return 0;
}
