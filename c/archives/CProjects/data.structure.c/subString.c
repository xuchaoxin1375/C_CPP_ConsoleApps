#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define iprint(expr) printf(#expr " = %i\n", expr)  // 整型值调试宏:打印整数表达式
#define fprint(expr) printf(#expr " = %f\n", expr)  // 整型值调试宏:打印整数表达式
#define xprint(expr) printf(#expr " = %#x\n", expr) // 整型值调试宏:打印整数十六进制
#define sprint(expr) printf(#expr " = %s\n", expr)  // 字符串调试宏:打印字符串

#define pprint(expr) printf(#expr " = %p\n", expr) // 指针调试宏:打印指针(取决于具体的机器实现)

/**
 * @brief Determine if the main string M starts with the target string T
 *
 * @param M The main string
 * @param T The target string
 * @return 1 if M starts with T, 0 otherwise
 */
bool startMatch(char *M, char *T)
{
    // Check if the length of M is less than the length of T
    if (strlen(M) < strlen(T))
        return 0;

    // Iterate through T and compare the characters with M
    for (int i = 0; T[i] != '\0'; i++)
    {
        // If the characters do not match, return 0
        if (M[i] != T[i])
        {
            return false;
        }
    }

    // If all characters match, return 1
    return true;
}
/**
 * @brief Determine if the main string M starts with the target string T
 *
 * @details This is a more concise version of startMatch, it uses a while loop to compare the characters of M and T.
 *          If the characters do not match, return false. Otherwise, return true.
 *
 * @param M The main string
 * @param T The target string
 * @return 1 if M starts with T, 0 otherwise
 */
bool startMatch2(char *M, char *T)
{
    /*
    主串M和模式串T匹配成功的标志是T被遍历匹配到最后一个字符'\0'(此前中途如果遇到不匹配的情况,则表明匹配失败)
    主串M的长度可能短于模式串T,对于两个字符串的遍历,任意一个遇到'\0'结束或者失配时结束遍历,最后再检查一下是否T被遍历完(检查离遍历循环时模式串的检查位置是否停留在\0处即可,如果是说明匹配成功,否则失败)
     */
    // while(*M++==*T++);//比较到出现'\0'时应该立即结束循环,即便是两串相等,防止'\0'=='\0'后继续比较下去

    // while (*M && *T && (*M++ == *T++))//比较到出现'\0'结束循环;把++放到循环里代码更加紧凑,但是可读性降低,不方便调试(新手不友好);这里不能省略*M,*T
    //*M保证了主串还未结束,字符'0'是真值(和`\0`不同,`\0`是0,是假值)

    // 如果将++放到循环体中,仔细观察可以发现,*M,*T可以省略掉其中的一个,*M==*T会判断剩下的一个
    while (*M && (*M == *T))
    {
        // printf("M:%c,T:%c\n", *M, *T);//打印放在循环末尾会丢失第一个字符打印结果
        M++;
        T++;
    }
    return *T == '\0';
}
void testStartMatchFunc(bool (*func)(char *, char *))
{
    assert(func("hello", "hello") == true);        // Full match
    assert(func("hello", "hell") == true);         // Prefix match
    assert(func("hello", "hello there") == false); // M longer than T, no match
    assert(func("hello", "helloa") == false);      // Different characters, no match
    assert(func("", "") == true);                  // Both empty strings
    assert(func("a", "a") == true);                // Single character match
    assert(func("abc", "ab") == true);             // T ends before M
    assert(func("abc", "abcd") == false);          // T longer than M, no match
    // assert(func("abc", "abc\0") == true);          // T ends with null character
    // assert(func("abc\0", "abc") == false);         // M ends with null character, T doesn't
}
int subString(char *M, char *T)
{

    int lenM = strlen(M);
    int lenT = strlen(T);
    int stop = lenM - lenT + 1; // 需要遍历主串的大最大字符数(主串的最大位序字符)
    for (int i = 0; i < stop; i++)
    {
        if (startMatch(M + i, T))
        {
            return i;
        }
    }
    return -1;
}
// 单元测试函数
void test_subString()
{
    assert(subString("hello", "ll") == 2);
    assert(subString("aaaaa", "aa") == 0);
    assert(subString("abcdef", "def") == 3);
    assert(subString("abcdef", "xyz") == -1);
    assert(subString("a", "a") == 0);
    assert(subString("", "a") == -1);
    assert(subString("abc", "") == 0);
    assert(subString("aaa", "a") == 0);
    assert(subString("abcabc", "abc") == 0);
    assert(subString("abcabc", "bca") == 1);
    printf("All tests passed successfully.\n");
}

/* 定义C语言的String(基于堆分配内存) */
typedef struct String
{
    char *ch;
    int length;
} String;

// 初始化函数
void StrAssign(String *str, const char *initValue)
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

int Index_deprecated(String S, String T)
{
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length)
    {
        if (S.ch[i] == T.ch[j])
        {
            ++i;
            ++j; // 继续比较后继字符
        }
        else
        {
            // 指针后退重新开始匹配
            j = 1; // 模式串的指针重置为1
            i = i - j + 2;
        }
    }
    if (j > T.length)
        return i - T.length;
    else
        return -1;
}

int Index(String S, String T)
{
    int i = 0, j = 0;
    while (i < S.length && j < T.length) // 从0开始计数
    {
        if (S.ch[i] == T.ch[j])
        {
            // printf("%d %d\n", i, j);
            // printf("%c %c\n", S.ch[i], T.ch[j]);
            ++i;
            ++j; // 继续比较后继字符(如果两个串都还未结束)
        }
        else
        {
            // 指针后退重新开始匹配
            j = 0; // 模式串的指针重置为0
            i = i - j + 1;
        }
    } // 离开循环时至少有一个字符串结束
    // printf("%d %d\n", i, j);
    if (j == T.length)
    {

        printf("%d \n", i - T.length);
        return i - T.length;
    }
    else
    {

        printf("%d \n", -1);
        return -1;
    }
}

// 测试函数
void testIndex()
{
    // 测试用例1：两个空字符串
    String S1, T1;
    StrAssign(&S1, "");
    StrAssign(&T1, "");
    assert(Index(S1, T1) == 0);
    freeString(&S1);
    freeString(&T1);

    // 测试用例2：S不包含T
    String S2, T2;
    StrAssign(&S2, "abcdef");
    StrAssign(&T2, "xyz");
    assert(Index(S2, T2) == -1);
    freeString(&S2);
    freeString(&T2);

    // 测试用例3：S包含T
    String S3, T3;
    StrAssign(&S3, "abcdef");
    StrAssign(&T3, "def");
    assert(Index(S3, T3) == 3);
    freeString(&S3);
    freeString(&T3);

    // 测试用例4：T为空字符串
    String S4, T4;
    StrAssign(&S4, "abcdef");
    StrAssign(&T4, "");
    assert(Index(S4, T4) == 0);
    freeString(&S4);
    freeString(&T4);

    // 测试用例5：S为单个字符，S等于T
    String S5, T5;
    StrAssign(&S5, "a");
    StrAssign(&T5, "a");
    assert(Index(S5, T5) == 0);
    freeString(&S5);
    freeString(&T5);

    // 测试用例6：S为单个字符，S不等于T
    String S6, T6;
    StrAssign(&S6, "a");
    StrAssign(&T6, "b");
    assert(Index(S6, T6) == -1);
    freeString(&S6);
    freeString(&T6);
    // 测试用例7：给定的测试用例
    String S, T;
    StrAssign(&S, "hello");
    StrAssign(&T, "ll");
    assert(Index(S, T) == 2);
    freeString(&S);
    freeString(&T);

    // 更多测试用例...
}

int main()
{

    testIndex();
    // test_subString();
    return 0;
}
