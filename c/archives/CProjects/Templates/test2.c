#include <stdio.h>

int main()
{
    struct key
    {
        char *word;
        int count;
    } keytab[] = {
        "auto", 0,
        "break", 0,
        "case", 1,
        "char", 0,
        "const", 0,
        "continue", 0,
        "default", 0,
        /* ... */
        "unsigned", 0,
        "void", 0,
        "volatile", 0,
        "while", 0};
    struct key *low = &keytab[0];
    struct key *high = &keytab[4];
    struct key *mid;

    // mid = (low + high) / 2;  // 不合法,指针和指针之间不能进行加运算,指针只能和整型进行加运算,指针间只能想减或比较运算
    mid = low + (high - low) / 2; // 合法,通过指针间的减法运算得到元素数量,在基于low指针偏移得到中间指针
    printf("%s,%d\n", mid->word, mid->count);
}