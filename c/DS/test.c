#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define ElemType int
#define MaxSize 100
int main(int argc, char const *argv[])
{
    struct Snode
    {
        ElemType data;
        int next;
    } SLinkList[MaxSize];
    // typedef struct SNode
    // {
    //     ElemType data;
    //     int next; // 使用数组下标表示指针域,而不是SNode类型的指针
    // } SLinkList[MaxSize];
    // struct
    return 0;
}