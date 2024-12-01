#include <stdio.h>

// 反转数组a中从索引p到q的部分
// 参数:
//   a: 指向数组的指针
//   p: 起始索引
//   q: 结束索引
void reverse(int *a, int p, int q)
{
    // 遍历数组的前半部分，交换对称位置的元素
    for (int i = 0; i < (q - p + 1) / 2; i++)
    {
        // 方案1:普通方案(写法简单,推荐)
        // 交换当前索引和对称索引处的元素
        int tmp = a[p + i];
        a[p + i] = a[q - i];
        a[q - i] = tmp;

        // 方案2:使用数组和异或运算(采用亦或方案需要的辅助空间位0,但是空间复杂度仍然记为O(1)(常数级))
        // 通过异或运算交换元素，无需额外变量
        // a[p + i] = a[p + i] ^ a[q - i];
        // a[q - i] = a[p + i] ^ a[q - i];
        // a[p + i] = a[p + i] ^ a[q - i];

        // 方案3:使用指针和异或运算
        // 通过指针和异或运算交换元素，无需额外变量
        // *(a + p + i) = *(a + p + i) ^ *(a + q - i);
        // *(a + q - i) = *(a + p + i) ^ *(a + q - i);
        // *(a + p + i) = *(a + p + i) ^ *(a + q - i);
    }
}

int main()
{
    const int size = 10;
    int a[size];
    for (int i = 0; i < size; i++)
    {
        a[i] = i + 1;
    }

    int shift = 4;
    reverse(a, 0, shift - 1);
    reverse(a, shift, size - 1);
    reverse(a, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}