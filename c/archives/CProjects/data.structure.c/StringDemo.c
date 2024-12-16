#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct String
{
    char *ch;   // 指向字符数组
    int length; // 字符串长度
} String;

// 初始化函数
void initString(String *str, const char *initValue)
{
    if (str == NULL)
    {
        return; // 避免对空指针操作
    }
    if (initValue == NULL)
    {
        str->ch = NULL; // 如果初始值为空字符串
        str->length = 0;
    }
    else
    {
        str->length = strlen(initValue);                            // 获取字符串长度
        str->ch = (char *)malloc((str->length + 1) * sizeof(char)); // 分配内存
        if (str->ch != NULL)
        {
            strcpy(str->ch, initValue); // 复制字符串
        }
    }
}

// 销毁函数
void freeString(String *str)
{
    if (str != NULL && str->ch != NULL)
    {
        free(str->ch); // 释放动态分配的内存
        str->ch = NULL;
        str->length = 0;
    }
}

int main()
{
    String myString;

    // 初始化
    initString(&myString, "Hello, World!");
    printf("String: %s, Length: %d\n", myString.ch, myString.length);

    // 销毁
    freeString(&myString);

    return 0;
}