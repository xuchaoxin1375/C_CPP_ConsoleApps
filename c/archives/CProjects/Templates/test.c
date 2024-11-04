#include <stdio.h>
#include <math.h>
static char daytab[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                             {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

/* day_of_year:  set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day:  set month, day from day of year */

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

static char mat[2][10] = {{0, 11, 12, 13, 14, 15, 16, 17, 18, 19},
                          {0, 21, 22, 23, 24, 25, 26, 27, 28, 29}};

struct
{
    int len;
    char *str;
} *p;

int main()
{

    struct demo
    {
        int len;
        char *str;
    } x = {3, "hello"};
    struct demo *ps = &x;
    int *p_int;
    char *p_char;
    double *p_double;

    printf("Size of int*\t\t: %zu bytes\n", sizeof(p_int));
    printf("Size of char*\t\t: %zu bytes\n", sizeof(p_char));
    printf("Size of double*\t\t: %zu bytes\n", sizeof(p_double));
    printf("Size of struct demo*\t: %zu bytes\n", sizeof(ps));

    printf("%d\n", sizeof "abcdef");
    printf("%d\n", sizeof(size_t));
    // printf("%d\n", sizeof int);//报错
    printf ("%d\n", sizeof x);

    // 比较地址
    // printf("%p,%p\n", mat, *mat);         // 行指针和列指针地址一样
    // printf("%p,%p\n", mat + 1, *mat + 1); // 行指针和列指针地址分别+1,结果不一样,前者偏移量是行向量的元素个数的地址,后者是列向量的单个元素地址

    // char *s = "hello";
    // printf("%s\n", s);
    // printf("%c\n", s[0]);
}