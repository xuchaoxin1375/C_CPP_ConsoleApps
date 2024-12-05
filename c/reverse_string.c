/* 字符串逆序存放并输出
假设字符串长度不超过999
*/
#include <stdio.h>
#include <string.h>

int main()
{
    const int size = 1000;
    char a[size], t;
    int len;

    printf("请输入一个字符串:\n");
    scanf("%s", a);
    len = strlen(a);
    // 字符序列左半边元素数量为len/2,无论len为奇数还是偶数
    // 交换字符序列左半边和右半边的元素,从收尾对开始交换
    for (int i = 0; i < len / 2; i++)
    {
        t = a[i];
        a[i] = a[len - 1 - i];
        a[len - 1 - i] = t;
    }
    printf("%s", a);
}