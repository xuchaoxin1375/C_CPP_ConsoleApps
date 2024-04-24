#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_NONSTDC_NO_DEPRECATE

/* 标题套子*/
//*主函数一般有输入输出(scanf("",& );以及输出:(printf("", ); ))
/* 使用文本替换的功能时一定不要在这里头使用(或者选中想要处理的代码),否则早期的程序里的标识符都会被改动
如果要使用,应该将改程序段拷贝到其他地方,另开一个.c,才可放心操作.
!!!!!!!!!!!!
!!!!!!!!!! 
如果设置的端点过多,可以使用运行到光标处.*/
/*测试基础知识. 

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define PAUSE {printf("\n");system("pause");}//一般放在循环/switch外部!!
int main()
{   
    int a = 0 ;
    printf("%d",a+1);
    return 0;
} 
*/

/*测试/编写大程序. */
/*

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define PAUSE {printf("\n");system("pause");}//一般放在循环/switch外部!!
// // 拷贝到平台的时候把my_fuction_lib.h注释掉.
//#include "my_fuction_lib.h"

//在此下方插入自定义函数对的声明:

//主函数main
int main()
{
    //复制模版式删除这个或者再下面一个
    int n;
    while( scanf("%d",&n) != EOF)
    {
    }
    //复制模版式删除这个或者上面那个
    char str[100];//根据需要分配更大的维数
        //while(scanf("%s",str) != EOF , str == " xxx")判断读到了什么;while(gets(str));
    while( scanf("%s",str) != EOF)
    {
        int len = strlen(str);
        int last_index_of_string = len - 1;

    }
    return 0;
} 
//主函数结束.
//在下方编写自定义函数:


*/

//<<<<<<<<<<<<<---往下输入/插入题目---->>>>>>>>>>>>>>>>>>:/* 记得加 */
//高级语言程序设计实验考试（19级计科类合班）
/* 某校大门外长度为L的马路上有一排树，每两棵相邻的树之间的间隔都是1米。我们可以把马路看成一个数轴，
马路的一端在数轴0的位置，另一端在L的位置；数轴上的每个整数点，即0，1，2，……，L，都种有一棵树。 
由于马路上有一些区域要用来建地铁。这些区域用它们在数轴上的起始点和终止点表示。
已知任一区域的起始点和终止点的坐标都是整数，区域之间可能有重合的部分。
现在要把这些区域中的树（包括区域端点处的两棵树）移走。
你的任务是计算将这些树都移走后，马路上还有多少棵树。

输入
输入的第一行有两个整数L（1 <= L <= 10000）和 M（1 <= M <= 100），L代表马路的长度
，
M代表区域的数目，L和M之间用一个空格隔开。接下来的M行每行包含两个不同的整数，用一个空格隔开，
表示一个区域的起始点和终止点的坐标。

输出
输出包括一行，这一行只包含一个整数，表示马路上剩余的树的数目。

样例输入
10000 10
123 134
890 1231
1321 3123
3333 4444
9999 10000
8888 9988
4555 4666
5000 6000
8007 8887
6777 8000
样例输出
2411

注意,L只是马路的长度,不是想当然的树的棵树.
 */
/* 之前只初始化到10000(L个位置) 当然这也是审题不细致过于紧张,没注意到从0到L都种上树需要L+1个位置. */
// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// #include<ctype.h>
// #include<string.h>

// int main()
// {
// 	int sum = 0;

// 	int l = 0;
// 	int num = 0;

// 	int m = 0,n = 0;

// 	int a[10001] ;
// 	int i = 0;

//     for(i = 0;i<=10000;i++) a[i] = 1;//如果不初始化到索引10000处,平台说输出超限.

// 	scanf("%d %d",&l,&num);

// /* 使用for通过: */
// /*
//     for(i = 0;i < num;i++)
//     {
//         scanf("%d %d",&m,&n);
//         for(int j = m; j <= n;j++)
//         //从while(num--)变过来排查问题的,但注意这时二重循环的循环变量不要使用同一个,将引起混乱.
//         {
//             a[j] = 0;
//         }
//     }
//     */
// /* 使用while通过: */
// 	while(num --)
// 	{
// 		scanf("%d %d",&m,&n);
// 		for(i = m;i <= n;i++)
// 		{

//             a[i] = 0;
// 		}
// 	}

// 	for(i = 0;i<=l;i++)//注意这里的l可以取到10000,而i也可以取到10000,这将导致访问到a[10000]的位置.
// 	{
// 		//if(a[i] == 0)
// 		//sum ++;
//         sum += a[i];
// 	}

// 	printf("%d\n",sum);

// }
/* 测试lcm() */
//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include <stdlib.h>
//#include <ctype.h>
//#define PAUSE {printf("\n");system("pause");}//一般放在循环/switch外部!!
//// // 拷贝到平台的时候把my_fuction_lib.h注释掉.
//#include "my_fuction_lib.h"
//
////在此下方插入自定义函数对的声明:
//
////主函数main
//int main()
//{
//    //复制模版式删除这个或者再下面一个
//    int n;
//    while( scanf("%d",&n) != EOF)
//    {
//        int m;
//        scanf("%d",&m);
//        printf("%d\n",lcm(m,n));
//    }
//
//    return 0;
//}
//主函数结束.
//在下方编写自定义函数:

/* 题目描述
1007

Redraiment小时候走路喜欢蹦蹦跳跳，他最喜欢在楼梯上跳来跳去。
 但年幼的他一次只能走上一阶或者一下子蹦上两阶。
  现在一共有N阶台阶，请你计算一下Redraiment从第0阶到第N阶共有几种走法。

输入

输入包括多组数据。 每组数据包括一行:N(1≤N≤40)。 输入以0结束

输出

对应每个输入包括一个输出。 为redraiment到达第n阶不同走法的数量。

样例输入 Copy

1
3
0
样例输出 Copy

1
3
 */
/* 递归优化之制作字典 */
// #include <stdio.h>
// int main()
// {
//     //采用制作字典的方式:先使用for填充指定规模的字典.
//     int a[41];//为了利用之前计算过的值,需要用数组记录下,以便之后来访问
//     int i,n;
/*制作字典*/
//     a[1]=1;a[2]=2;//字典入口(基础.)
//     /* 从i = 3,开始利用入口 */
//     for (i=3;i<=40;i++)
//     {
//         a[i]=a[i-2]+a[i-1]; //优化递归,将数据保存到数组a中.,减少重复计算
//     }

//     /* 查阅字典调出相应的数据 */
//     while((scanf("%d",&n) !=EOF )&&(n!=0))
//           printf("%d\n",a[n]);
//           return 0;
// }
/* 
2504:
小明很羡慕那些算命的江湖骗子，因为他们可以看你一眼就知道你的前世今生。
当然，我们知道那些骗子都是察言观色的胡诌。但我们可
帮助小明写一个程序，算出一个人的生日是星期几，

输入
输入多组测试数据，每组数据一行，包括三个整数：年（1个空格）月（1个空格）日。
输入0（1个空格）0（1个空格）0表示结束。

输出
请输出星期几的英文。就用1,2,3,4,5,6,7表示星期几.
样例输入
2013 12 18
2010 2 1
1999 7 24
2008 1 13
0 0 0
样例输出
3
1
6
7
提示
你知道今天星期几吗？不知道可以问老师哦！

//  */
//#include <stdio.h>
//int main()
//{
//    int y, m, d,
//        w; /*周几*/
//    while (scanf("%d %d %d", &y, &m, &d) != EOF)
//    {
//        if (y == 0 && m == 0 && d == 0)
//            break;
//        if (m < 3)
//        {
//            m += 12;
//            y = y - 1;
//        }
//        w = (y + (y / 4 - y / 100) /*第一类闰年的年数*/ + y / 400 /*第二类闰年的年数*/
//             + 2 * m + 3 * (m + 1) / 5 + d) %
//                7 +
//            1;
//
//        printf("%d\n", w);
//    }
//    return 0;
//}

/* 有人说你的手机号码蕴含着你的幸运数字，只要你将手机号所有的数字全部加起来。。。呃，
显然结果不可能是个位数。那么请你再加一次（即将上一次的累加和的每一位数字再全部累加起来），
直到只剩一个数字为止，这个数字就是你的幸运数字啦。哇哈哈，你信吗？ 输入 输入多组测试数据
，每组数据为一行你的手机号码。输入0表示结束。 输出 请输出你的幸运数字吧！ 
样例输入
13965847589 
13069851234 
0 
 <注意到13个数码相加的和不超过13*10,当然其实不超过13*9
 也就是说第一次加法后得到的结果不超过三位数.
 然而,如果要采用直接读入大整数的方式处理,需要使用long long 才可以保存11位整数.long类型任然是不够的.
样例输出
 2 
 6
 */
// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// #include <ctype.h>
// #define PAUSE {printf("\n");system("pause");}//一般放在循环/switch外部!!
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// //#include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:
// long long sum_digital_char(long long a)
// {
//     long long temp = 0,
//     sum = 0;
//     for(int i = 0; a > 0;)
//     {
//         sum += a % 10;
//         a /= 10;
//     }
//     return sum ;
// }
// //主函数main
// int main()
// {
//     //复制模版式删除这个或者再下面一个
//     long long num = 0 ;      //尽管后期long long的变量变小了,但是打印的时候变量还是哪么大.乃至要注意相关的函数.
//     /* 如果使用数组来读入电话号码会遇到问题: 由于电话号码的数子之间时没有分隔符的(不好直接读入到整形数组)
//     可以考虑使用字符串%s读入,然后再利用ASCII码值-48来转换
//     当然也可不必用数组*/
//     int i = 0;
//     long long sum = 0;

//     while (scanf("%lld", &num) != EOF && num)
//     {
//         sum = num;
//         // for (i = 1; i < 11; i++)
//         // {
//         //     scanf("%d", &num[i]);

//         //     sum += num[i];
//         // }
//         while(sum > 9)
//         {
//             sum = sum_digital_char(sum);
//         }
//         printf("%lld\n",sum);
//     }
//     printf("\n");
//     return 0;
// }
//主函数结束.
//在下方编写自定义函数:

/*
#include <stdio.h>
long long  add(long long  a){
	long t=0;
	while(a!=0){
	t+=a%10;
	a/=10;
}
return t;}
int main()
{
 long long  n;
 while(scanf("%lld",&n)!=EOF) {
 if(n==0)
 return 0;
 while(n>=10){
 	n=add(n);
 }
 printf("%lld\n",n);
}
 
} */
/*测试基础知识. */

/* 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define PAUSE {printf("\n");system("pause");}//一般放在循环/switch外部!!
int main()
{   
    int a[] = {1,2,3,4,5,6,7,8,9};
    int *p;
    p = a;

   // printf("%d",( p += 2, *(++p) ) );//4
    //printf("%d",( p += 2, *p++ )) ;//3

   // printf("%d",( p += 3, *p--) ) ;//4
    printf("%d",( p += 2, ++*p ) );//4
    return 0;
}  */
/* 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define PAUSE {printf("\n");system("pause");}//一般放在循环/switch外部!!
int main()
{   
    int a = 0 ;
    char str1[] = "good!";
    char str2[5] = {'g','o','o','d'};//如果位置够的话，那么也会不上‘\0'

    char str3[4] = {'g','o','o','d'};//如果没有放入’\0',也不会报错。

    char *str4 = "good!";
    printf("%d\n",'a');
    return 0;
}  */
/* 条件于编译: */
/* #include <stdio.h>
#define MAX 80
#define CHANGE 1
int main()
{
    char str[MAX];
    int i;
    printf("Enter characters:\n");
    scanf("%s", str);
    #if (CHANGE)
    {
        for(i = 0;i<MAX;i++)

      {
          if (str[i] != '\0')
          {
              if (str[i] >= 'a' && str[i] < 'z' || str[i] >= 'A' && str[i] < 'Z')
              {
                  str[i] += 1;
              }
              else if (str[i] == 'z' || str[i] == 'Z')
              {
                  str[i] -= 25;
              }
          }
      }
    }
    #endif

    printf("OUTPUT:\n%s", str);
    return 0;
}
 */
/* 对实数做相等判断要转换为精度范围的比较. */
/* #include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define PAUSE {printf("\n");system("pause");}//一般放在循环/switch外部!!
int main()
{   
    float a = 2.0;
    printf("%d",1.0/3.0*3.0 == 1.0);//可以得到1这一结果.
    return 0;
}  */
// #include <stdio.h>
// #include <string.h>
// void main()
// {
//     char *a[3] = {"morning", "afternoon", "evening"}, *t;
//     int i, j, k = 0;
//     for (j = 0; j < 2; j++)
//     {
//         k = j;
//         for (i = j + 1; /* i < 2 */ i < 3; i++)
//         {
//             if (strcmp(a[k], a[i]) > 0)
//             {
//                 k = i;
//             }
//         }
//         /* swap */
//         t = a[k];
//         a[k] = a[j];
//         a[j] = t;
//     }
//     for (i = 0; i < 3; i++)
//         printf("%c", *a[i]);
// }

/* switch 多次/选择性case跳转 */
// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// #include <ctype.h>

// #define PAUSE {printf("\n");system("pause");}
// int main()
// {
//     int x,y = 0;
//     scanf("%d", &x); //输入2
//     switch(x+1)
//     {
//     case 1:
//         y += 1;
//         printf("%d#", y);
//         break;
//     case 3://第一次进入.
//         y += 3;
//         printf("%d#", y);
//     //没有break,将会直接执行下一个case语句(此时不再判断下一个case的index是否匹配,直接进入!)
//     case 5://第二次免试进入//容易误认为是进入default.
//         y += 5;
//         printf("%d#", y);
//         break;//break离开switch
//     default:
//         y += 7;
//         printf("%d#",y);
//     //system("pause");//这个语句在这里不起作用:因为此前已经break出这个switch,所以不要放在里面啦.
//     }
//     PAUSE;

// }

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// #include <ctype.h>

// int main()
// {
//     char a = '\3' ;
//     char b = '3';
//     char c = '\72';/* 系统解析:'\72'被识别为一个八进制数,
//         转换为十进制数后为58 ,这个ascii将会对应某一个字符:  ':'*/
//     char d = '\072';/* 系统解析:'\072'被识别为一个八进制数,转换为十进制数后为58 */
//     int d2 = '\072';
//     int d3 = '\72';
//     char e = '\48';/* overflow in conversion from 'int' to 'char' changes value from
// '1081' to ''9'' [-Woverflow] */
//     char e2 = 49;//e2 :49 '1'
//     //int e = '99';
// /*一下是运行结果:
// a: 3 ' \003'//字符型变量 a里保存着ascii码值为3. 由于没有哪个字符的ASCII值为3,所以它对应'\003'
// b: 51 '3' //字符变量 b 里保存的ascii码值为51,它有具体的对应的字符3
// C: 58
// d: 58
// d2: 58
// d3: 58
// */
//     printf("%d\n",'\0');//打印0
//     printf("%d\n",a);//3    //char a = '\3' ;

//     printf("0\n");//打印0;
//     printf("%d\n",0);//打印0
//     printf("OK\n");

//    // printf("%c",0);//无用
//     //printf('%d',0);//invalid conversion from 'int' to 'const char*'
//    // printf(0);printf("\n");//无用
//     //printf("%c\n",'\6');//
//     printf("%c\n",'6');//6  相当于putchar();
//     printf("%c\n",54);//6;  %c 将你所填充的54 识别为某个字符的ascii码值.
//     system("pause");
//     return 0;
// }

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// #include <ctype.h>

// int main()
// {
//     int a = 0x10 ;
//     /*无论是八进制还是十六进制,都是数字0开头,只是十六进制多一个小写的x(0x)
//      十六进制数通过0x10来表示.也同样可以用int (任意进制合理大小的整数值) */
//     printf("%d",a+1);
//     return 0;
// }
/* test basic */

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// #include <ctype.h>

// int main()
// {
//     int a = 010;/* int类型可以保存8进制整数.系统将010识别为八进制数; 对应为十进制值:8 */
//     printf("%d",a+1);//9;
//     return 0;
// }
//主函数结束.
//在下方编写自定义函数:

/* 小张是同学会的负责人,但是复杂的联系信息让他很头痛,

请你帮他写一个个人信箱的管理系统(人数小于30人),每个人包含3项信息:

姓名 (小于20个字符)   性别(Female = 女, Male = 男)  生日(年月日)

每个人用一个结构体表示,同时支持以下操作:

add Tim Male 1993 12 22

添加一个名为Tim的男生,出生年月日位1993-12-22

name Tim

返回姓名为Tim的人的所有信息

sex Male

返回所有男生的信息(sex Female返回女生信息)

quit

退出系统

输入
用户指令

输出
输出结果

样例输入
add Tim Male 1993 12 22
add Britney Female 1992 2 23
add Freddy Male 1989 4 22
name Britney
sex Male
quit
样例输出
Britney Female 1992-2-23
Tim Male 1993-12-22
Freddy Male 1989-4-22
提示
用while循环来保证系统始终运行:

while(1) {
     scanf("%s", command);
     if (strcmp(command, "quit") == 0)
              break;
     else
         .....................

}
*/
//
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <stdio.h>
// struct Student{
//     char name[10];
//     char sex[10];
//     int year;
//     int month;
//     int day;
// } stu[40];//一次性申请30个Student结构

// int main()
// {
//     int i=0;
//     int j;/* int i,j;  分开:删除逗号,添加分号; 按下回车 添加int 空格 */

//     char command[10];/* 接收add/name/quit 这几个功能选项参数. */
//     char name[10];//存储/接受 姓名.
//     char gender[10];//性别

//     /* 先解析功能参数 */
//     while(scanf("%s",command) != EOF && strcmp(command,"quit") != 0)
//     {
//         if(strcmp(command,"add") == 0)
//         {
//             scanf("%s%s%d%d%d",stu[i].name,stu[i].sex,
//             &stu[i].year,&stu[i].month,&stu[i].day);
//             i++;
//         }
//         /* 查询名字 */
//         else if (strcmp(command, "name") == 0)//逗号后加一个空格来形成格式风格.
//         {
//             /* 读入要查询的名字 */
//             scanf("%s", name); //
//             /* 开始查找(作匹配.)
//             (一般还要配上一个break,查到内容打印后.但也要注意,即便是名字不一定唯一,
//             可能有同名同姓的,按要求是否break
//             (我姑且称带有break的遍历成为伪遍历.*/
//             for(j=0;j<30;j++)
//             {
//                 if (strcmp(stu[j].name, name) == 0)
//                 {
//                     printf("%s %s %d-%d-%d\n", stu[j].name, stu[j].sex,
//                            stu[j].year, stu[j].month, stu[j].day);
//                     break;
//                 }
//             }
//         }
//         /* 查询性别: */
//         else if (strcmp(command, "sex") == 0)
//         {
//             /* 读入要查询的性别. */
//             scanf("%s", gender);
//             for (j = 0; j < 30; j++)
//             {
//                 if (strcmp(stu[j].sex, gender) == 0)
//                     printf("%s %s %d-%d-%d\n", stu[j].name, stu[j].sex, stu[j].year,
//                            stu[j].month, stu[j].day);
//             }
//         }
//     }
// }
/* 
有一串打乱的成绩,现要求你把他们从低到高排列。
输入
每一行为姓名和成绩
以#作为输入结束标志
输出
输出排序后的结果

样例输入
LI 95
ZHAO 80
SUN 85
JIN 60
QIAN 70
WANG 90
ZHAN 85
#

样例输出
JIN 60
QIAN 70
ZHAO 80
SUN 85
ZHAN 85
WANG 90
LI 95 
*/

// #include <stdio.h>
// #include <stdlib.h>
// typedef struct Student{

// 	char name[20];
// 	float score;
// } Student;

// int  input(Student *st);                    //定义输入函数
// void print(Student *st, int n);                    //定义输出函数
// void sort(Student *st, int n);

// int main()
// {

// 	Student * stu;                                  //定义结构体指针stu
// 	int n;

// 	stu = (Student *)malloc(1000 * sizeof(Student)); //为stu分配内存空间

// 	while ((n = input(stu)) != -1)
// 	{
// 		sort(stu, n);  //调用排序函数
// 		print(stu, n); //调用输出函数

// 	}
// }

// int input(Student *st)
// {
// 	int i;
// 	for (i = 0;; i++)
// 	{

// 		if(scanf("%s", st[i].name) == EOF)
// 		{
// 			return -1;
// 		}

//        /* 判断结束符这点,比较讲究,在读入数据时,
// 应该考虑分别使用(若干个)scanf来读入同一行得不同部分,可以比较灵活得判断 */
// 		else if (st[i].name[0] != '#')
// 		{
// 			scanf("%f", &st[i].score);
// 		}
// 		else
// 		{
// 			break;
// 		}
// 	}
// 	return i;//读入的items
// }
// //输出函数
// void print(Student *st, int n)
// {
// 	Student *p;
// 	for (p=st; p<st+n; printf("%s %.0f\n",p->name, p->score), p++);
// }
// //排序函数
// void sort(Student *st, int n)
// {
// 	int i, j;
// 	Student temp;

// 	for(i = 0;i < n - 1;i++)
// 	{
// 		for(j = 0;j<=n-2-i;j++)
// 		{
// 			if(st[j].score > st[j+1].score)/* 或者j<n-1-i,这个容易错.(是否取等号.) */
// 			{
// 				temp = st[j];
// 				st[j] = st[j+1];
// 				st[j+1] = temp;
// 			}
// 		}
// 	}
// }

/* 数组版本 */
/* 
#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,min,temp1;
	int count=0;
	char a[1000][20];
	int b[1000];
	char temp[100]={};
     for(i=0;;i++)
	{
		scanf("%s",a[i]);
		if(strcmp(a[i],"#")==0)
		{
			break;
		}
		else
		{
		scanf("%d",&b[i]);
		count+=1;
		}
	}
   for(i=0;i<count-1;i++)
	{
        min = i;
        for (j = i; j < count; j++)
            if (b[min] > b[j])
                min = j;

            else if (b[min] == b[j])
            {
                if (strcmp(a[min], a[j]) > 0)
                    min = j;
            }
        strcpy(temp, a[min]);
        strcpy(a[min], a[i]);
        strcpy(a[i], temp);
        temp1 = b[min];
        b[min] = b[i];
        b[i] = temp1;
    }
    for (i = 0; i < count; i++)
        printf("%s %d\n", a[i], b[i]);
} */
/* 

现有一串已按分数高低记录好的成绩,
现在要求你在不打乱原来顺序的基础上

插入一部分数据、删除一部分数据,并输出。(用链表操作)

输入
输入分3部分:

第一部分为已排序好的成绩,#结束;

第二部分为要增加的成绩,#结束:

第三部分为要删除的成绩,#结束;

输出
输出修改后的成绩

样例输入
LI 95
WANG 90
SUN 85
ZHAO 80
QIAN 70
#
ZHAN 85
JIN 60
#
QIAN
#
样例输出
LI 95
WANG 90
SUN 85
ZHAN 85
ZHAO 80
JIN 60
  */
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int main()
// {
// 	struct stu
// 	{
// 		char name[20];
// 		int score;
// 		struct stu *next;
//     } *head = NULL,
//       *pnow, /* 新增节点的指针. /欲删除的节点指针*/
//       *p,  /* 母链表的当前位置的指针 */
//         /* 它是独立于链表之外的工作人员般的存在,通过它来访问(操作/修改)他所指的结构体元素的内容, */
//       *pre; /* 保存前一个节点的地址(外地址) */

//     char buf[20]; /* 数据缓冲区 ,当需要读入的数据比较多样,考虑先放入缓冲区再解析会比较灵活.
//                     buf里面可能存放的内容有两类:1.名字/2.'#' (而分数不会进去的(scanf(%s遇到空格结束读入.))) */

// 	int size_stu = sizeof(struct stu);
// 	/* 原来的母链表 头部. */

// 	/* 新增节点的指针. */
// 	pnow = (struct stu *)malloc(size_stu);
// 	/* 初始化头部和尾部得指针. */
// 	p = head = pnow;
// 	/* 读入第一行数据 并写入到母链表的表头元素中去*/
// 	scanf("%s %d", &pnow->name, &pnow->score);

// 	/* 第二行起需要分析读入到缓冲区里的内容 */
// 	while (scanf("%s", &buf) != EOF)
// 	{
// 		if (buf[0] == '#') /*到头了, 结束该母链表的读入 */
// 		{
// 			break;
// 		}
// 		else
// 		{
// 			/* 处理(建立下一个元素 )包括申请节点,连接节点内地址,更新(工作者指针的指向关系)(节点外地址操作)*/
// 			pnow = (struct stu *)malloc(size_stu);
// 			/* 连接并更新节点里的指针 */
// 			p->next = pnow; /* 连接到下一个元素 (采用上一个连接到当前,而非当前连接到下一个)(修改p所指节点的内地址.)*/
// 			p = pnow;		/* 更新节点里的指针 (将当前节点的外地址赋给p*/
// 			/* 数据写入到当前. */
// 			strcpy(pnow->name, buf);
// 			scanf("%d", &pnow->score);
// 		}
// 	}
// 	p->next = NULL;

// 	/* 处理增加的items,仍然采取一个一个节点的申请,连接 */
// 	while (scanf("%s", &buf) != EOF)
// 	{
// 		if (buf[0] == '#')
// 		{
// 			break;
// 		}
// 		else
// 		{
// 			pnow = (struct stu *)malloc(size_stu);
// 			strcpy(pnow->name, buf);
// 			scanf("%d", &pnow->score);

// 			p = head->next; /* 保存母链表的首节点的内地址.(第二个节点的地址(如果有的话)) */

// 			pnow->next = NULL; /* 当前接节点默认独立 */
// 			/* 比较大小(都从母表头比起.),再合适的位置插入节点. */
// 			if (pnow->score > head->score) /* 接到头部去 */
// 			{
// 				pnow->next = head;
// 				head = pnow; /* 更新指向头部指针head */
// 			}
// 			else
// 			{
// 				/* p = head->next; */
// 				pre = head;
// 				/*    p->score 原链表第二个节点里的分数.
// 				pre,和 p 是母链表中一前一后的关系.
// 				<= 表示新节点尽量靠后.*/
// 				while (p != NULL && pnow->score <= p->score) /* 如果仍然小于等于,继续后移. */
// 				{
// 					/* pre = p; 都可以.*/
//                  pre = pre->next;
// 					p = p->next; /* 统称指向下一个节点. */
// 				}
// 				pnow->next = p;	  /* 为了防止链表断了,应该从后往前作连接工作. */
// 				pre->next = pnow; //被赋新值的同时就断开了旧有的链接
// 			}
// 		}
// 	}
// 	/* 匹配姓名,删除节点. */
// 	while (scanf("%s", &buf) != EOF)
// 	{
// 		if (buf[0] == '#')
// 			break;
// 		else
// 		{
// 			if (!strcmp(head->name, buf)) /* 匹配成功. */
// 			{
// 				p = head;
// 				head = head->next; /*丢弃旧头部 */
// 			}
// 			else
// 			{
// 				p = head->next; /* p母链表的当前位置的指针 */
// 				pre = head;
// 				/* 当前节点不是最后一个同时 里面的名字不匹配 */
// 				while (p != NULL && strcmp(p->name, buf) != 0)
// 				{
// 					/* p,pre各自指向自己的下一个节点. */
// 					p = p->next;
// 					pre = pre->next;
// 				}
// 				pre->next = p->next;
// 				p->next = NULL;
// 			}
// 			free(p);
// 		}
// 	}
// 	/* 打印内容. */
// 	p = head;
// 	for (; p != NULL;)
// 	{
// 		printf("%s %d\n", p->name, p->score);
// 		p = p->next;
// 	}
// 	/* while (p != NULL)
// 	{
// 		printf("%s %d\n", p->name, p->score);
// 		p = p->next;
// 	} */
// 	return 0;
// }

/* 
已知f[]与g[]两个整数数组,元素都已经  从小到大排好序,
请写一个程序,算出f[]中比g[]中元素大的对数。

换句话说,f[0]比g[]中多少个元素大,f[1]比g[]中多少个元素大等, 
这些值的总和就是要求的答案。 

举个例子,如果f[]这哦国内游1,3,5,7,9,而g[]中有2,3,4,7,8。 
那么: 
f[0]比g[]中的所有元素都小; f[1]比g[0]大; f[2]比g[0]、g[1]、g[2]大;
 f[3]比g[0]、g[1]、g[2]大; f[4]比g[0]、g[1]、g[2]、g[3]、g[4]大; 
 
 所以答案是0+1+3+3+5=12
输入
第一行为两个整数m, n(1≤m, n≤1000),
分别代表数组f[], g[]的长度。 

第二行有m个元素,为数组f[]。 
第三行有n个元素,为数组g[]。

输出
输出支配值。
样例输入
5 5
1 3 5 7 9
2 3 4 7 8
样例输出
12
提示
你能想出O(n+m)的算法吗?^_^
加油! 
*/

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// #include <ctype.h>
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// //#include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:

// //主函数main
// int main()
// {

//     int m,n;
//     while( scanf("%d %d",&m,&n) != EOF)
//     {
// 		int size_int = sizeof(int);
// 		int *p = (int*)malloc(m * size_int);//f[]
// 		//free(p);
// 		int *q = (int *)malloc(n*size_int);//g[]
// 		//free(q);
// 		int sum = 0;
// 		for(int i = 0;i<m;i++)
// 		{
// 			scanf("%d",p+i);
// 		}
// 		for(int i = 0;i<n;i++)
// 		{
// 			scanf("%d",q+i);
// 		}
// 		for(int i = m-1;i >= 0 ;i--)
// 		{
// 			for(int j = n-1; j >= 0; j--)//>= 而非<=
// 			{
// 				if(*(p+i) > *(q + j))
// 				{
// 					sum += (j + 1);
// 					break;
// 				}
// 			}
//  		}
// 		free(q);
// 		free(q);
//  	printf("%d\n",sum);
//      }

//     return 0;
// }
/* 现有有N个学生的数据记录,每个记录包括学号、姓名、三科成绩。

 编写一个函数input,用来输入一个学生的数据记录。 
 编写一个函数print,打印一个学生的数据记录。
  在主函数调用这两个函数,读取N条记录输入,再按要求输出。 N<100

输入
学生数量N占一行 每个学生的   学号、姓名、三科成绩  占一行,空格分开。
输出
每个学生的学号、姓名、三科成绩占一行,   逗号分开。
样例输入
2
a100 zhblue 70 80 90
b200 newsclan 90 85 75
样例输出
a100,zhblue,70,80,90
b200,newsclan,90,85,75
 */

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// #include <ctype.h>

// //在此下方插入自定义函数对的声明:
// struct student
// {
//     char id[20]; /* student ID */
//     char name[20];
//     float score1;
//     float score2;
//     float score3;
//     struct student *next;
// }; //分号莫忘.
// //用  结构体类型的 指针变量 作为参数要比直接用结构体作为参数来的高效
// void read_in_link( struct student * link,int n)
// {//链表//contemporary(当代.)
//     /* 读入数据到链表需要:
//     一个中间结构体
//     一个循环变量(计数器) */
//     struct student *p; /* p->next = &link[i + 1] */
//     int i = 0;

//     p = link;/* 左值和右值都是指针变量(赋值后,具有几乎等价的属性.)
//                 (用p作为循环变量,同一风格,缩短名字,link作为右值会自然些.) */
//     for (; p < link + n; )
//     {

//         scanf("%s %s %f %f %f", p->id, p->name, &p->score1, &p->score2, &p->score3);

//         i == n - 1 ? (p->next = NULL) : (p->next = &link[i + 1]);
//         i++;
//         p++;
//     }
// }
// /* 以链表末端的NULL,不需要知道链表的元素个数. */
// void print(struct student *p)
// {
//     struct student *i;
//     for(i = p;i != NULL;i = i->next)
//     {
//         printf("%s,%s,%.0f,%.0f,%.0f\n",i->id,i->name,i->score1,i->score2,i->score3);
//     }
// }
// //主函数main
// int main()
// {

//     int n;
//     while (scanf("%d", &n) != EOF)
//     {
//         struct student *link;
//         /* (一次性,申请内存(这件事还是放在主函数里去做比较好.),并处理失败的情况. */
//         if ((link = (struct student *)malloc(n * sizeof(struct student))) == NULL)
//         {
//             puts("Error");
//             exit(1);
//         }

//         read_in_link(link,n);
//         print(link);

//     }

//     return 0;
// }

/* 已有a、b两个链表,
每个链表中的结点包括学号、成绩。

要求把两个链表合并,按学号升序排列。

输入
第一行,a、b两个链表元素的数量N、M,用空格隔开。
 接下来N行是a的数据 
 然后M行是b的数据 
 
 每行数据由 学号和成绩两部分组成
输出
按照  学号升序  排列的数据
样例输入
2 3

5 100
6 89

3 82
4 95
2 10
样例输出
2 10
3 82
4 95
5 100
6 89
提示*/
//
// #include <stdio.h>
// #include <stdlib.h>

// struct Student
// {
// 	int id;
// 	float score;
// 	struct Student *next;
// };

// void input(struct Student *stu, int n);

// struct Student *merge(struct Student *stu1, struct Student *stu2, int m);

// void print(struct Student *stu);

// int main()
// {
// 	int m, n;
// 	while (scanf("%d%d", &m, &n) != EOF)
// 	{
// 		/* 申请两块链表a,b */
// 		struct Student *a = (struct Student *)malloc(m * sizeof(struct Student));
// 		struct Student *b = (struct Student *)malloc(n * sizeof(struct Student));
// 		input(a, m);
// 		input(b, n);

// 		print(merge(a, b, m));
// 		return 0;
// 	}
// }

// void input(struct Student *stu, int n)
// {
// 	int i = 0;
// 	struct Student *p;
// 	for (p = stu; p < stu + n; p++, i++)
// 	{

// 		scanf("%d %f", &p->id, &p->score);
// /*          读入数据的同时把结构元素连接起来(连接下一个元素.) */
// 		i == n - 1 ? (p->next = NULL) : (p->next = &stu[i + 1]);
// 	}
// }

//  /* 传入两个链表的首地址,以及第一个链表的元素数目. */
// struct Student *merge(struct Student *stu1, struct Student *stu2, int m)
// {
// 	/* stu1[m - 1]链表元素stu1[m-1]的地址(可能不是)? stu1[m-1]->next为什么非法?
// 	调试过程中发现:stu1[m - 1] 是{...},也无法用*运算,因该不是地址,而是结构体本身.
// 	(stu1 + k)是第k个元素的地址,而stu1[k]则是stu1[k]是第k个元素本身(即 *(stu1 + k)这和数组直接取元素的形式一样..
// 	stu1是指向链表头的指针;*/
// 	stu1[m - 1].next = stu2; //链表a末尾元素连接到链表b的首元素.

// 	struct Student *p, *q, temp; //p,q作为位置记录器的结构体指针变量.
// 								 /* 	temp:contemporary(当代)*/
// 	for (p = stu1; p != NULL; p = p->next)
// 	{

// 		q = p->next;
// 		/* 选择法排序是跳跃式的(每一趟由一个固定的基点),每次修改都是这对着基准位置(将其迭代为正确的值)
// 		而冒泡法是两两比较,(虽然每一趟都没有固定的点,但所有趟次都有一个共同的起点) */
// 		for (/* q = p->next */; q != NULL; /* q = q->next */)
// 		{
// 			/*[min,max] */
// 			if (p->id > q->id)
// 			{
// 				/* 对id排序 */
// 				temp.id = p->id;
// 				p->id = q->id;
// 				q->id = temp.id;
// 				/* 同时对成绩做调整,不过是否调整还是基于对id的比较*/
// 				temp.score = p->score;
// 				p->score = q->score;
// 				q->score = temp.score;
// 			}
// 			q = q->next;
// 		}
// 	}
// 	/* 返回链表表头. */
// 	return stu1;
// }

// void print(struct Student *stu)
// {
// 	struct Student *p;
// 	/* 使出链表的内容:从表头的指针开始,到NULL结束;同过迭代p (p=p->next)实现 */
// 	for (p = stu; p != NULL; p = p->next)
// 	{
// 		printf("%d %.0f\n", p->id, p->score);
// 	}
// }

/* 输入两个正整数m和n(m<n),
求m到n之间(包括m和n)所有素数的和,

要求定义并调用函数isprime(x)来判断x是否为素数(素数是除1以外只能被自身整除的自然数)。

输入
m n

输出
素数和

样例输入
2 3
样例输出
5 */

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// #include <ctype.h>

// int isprime_ii(int n) //分析普通阶段的因子是否为质数
// {
//     if (n == 0 || n == 1)
//     {
//         return 0;
//     }
//     for (int i = 2; i * i < n + 1; i++)
//     {
//         if (n % i == 0)
//             return 0;
//     }
//     return 1; /* 当个摆设,不然会waring说没有返回值. */
// }
// //主函数main
// int main()
// {
//     //复制模版式删除这个或者再下面一个
//     int m,n;
//     while( scanf("%d %d",&m,&n) != EOF)
//     {
//         int sum_prime = 0;
//         for(int i = m;i<=n;i++)
//         {
//             if(isprime_ii(i))
//             {
//                 sum_prime += i;

//             }
//         }
//         printf("%d\n",sum_prime);
//     }

// }
//主函数结束.
//在下方编写自定义函数:

/* 编一个程序,输入一个字符串,将组成字符串的所有非英文字母的字符删除后输出。

输入
一个字符串,长度不超过80个字符。

输出
删掉非英文字母后的字符串。

样例输入
abc123+xyz.5
样例输出
abcxyz
 */
/* 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
// // 拷贝到平台的时候把my_fuction_lib.h注释掉.
//#include "my_fuction_lib.h"

//在此下方插入自定义函数对的声明:

//主函数main
int main()
{
    char str[100];//根据需要分配更大的维数
        //while(scanf("%s",str) != EOF , str == " xxx")判断读到了什么;while(gets(str));
    while( scanf("%s",str) != EOF)
    {
        int len = strlen(str);
        int last_index_of_string = len - 1;
        for(int i = 0;i < len;i++)
        {
            if(isalpha(str[i]))
            {
                printf("%c",str[i]);
            }
        }
        printf("\n");
    }
    return 0;
}  */
//主函数结束.
//在下方编写自定义函数:

/* 输入n(n<=100)个整数,按照绝对值从大到小排序后输出。题目保证对于每一个测试实例,所有的数的绝对值都不相等。
输入
输入数据有多组,每组占一行,
每行的第一个数字为n,
接着是n个整数,n=0表示输入数据的结束,不做处理。
输出
对于每个测试实例,输出排序后的结果,两个数之间用一个空格隔开。每个测试实例占一行。
样例输入
3 3 -4 2
4 0 1 2 -3
0
样例输出
-4 3 2
-3 2 1 0
 */

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// #include <ctype.h>
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// //#include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:
// void bubble_int_sort(int *p, int n)
// {
//     void swap_int_pointer(int *a, int *b);
//     /* 冒泡 枚举图
//     /*冒泡法不需要设立最值flag. */
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = 0; j <= n - 2 - i; j++)
//         {
//             /*通过改变'<'为'>',可以从降序转为升序; 通过监视*(p+j)和*(p+j+1)可以知道当前(第j组)相邻量的值的情况 */
//             if ( abs(*(p + j)) <abs( *(p + j + 1)) )
//             {
//                 swap_int_pointer(p + j, p + j + 1);
//             }
//         }
//     }
// }
// /* 数字版swap() */
// void swap_int_pointer(int *a, int *b)
// {
//     int temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }
// //主函数main
// int main()
// {
//     //复制模版式删除这个或者再下面一个
//     int n;
//     while (scanf("%d", &n) != EOF && n != 0)
//     {
//         int *p = (int *)malloc(n*sizeof(int));
//         for(int i = 0;i<n;i++)
//         {
//             scanf("%d",p+i);
//         }
//         bubble_int_sort(p,n);
//         for(int i = 0;i<n;i++)
//         {
//             printf("%d",*(p+i));
//             if(i<n-1)
//             {
//                 printf(" ");
//             }
//         }
//         printf("\n");

//     }

//     return 0;
// }
//主函数结束.
//在下方编写自定义函数:

/* 解一元二次方程ax2+bx+c=0的解。

输入
多组测试,每行输入三个实数a,b,c的值,a 不为0.

输出
输出两个根X1和X2,用空格隔开,具体格式为:

X1 X2

其中大的根先输出,即X1>=X2。
结果保留两位小数。

如果没有实根,输出“NO”

样例输入(所给的几个样例虽然都是整数,但没有其他所有说输入一定都是整数)
1 5 -2
1 1 2
1 -2 1
样例输出
0.37 -5.37
NO
1.00 1.00
提示
该题有多组测试数据

 */
/* 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
// // 拷贝到平台的时候把my_fuction_lib.h注释掉.
//#include "my_fuction_lib.h"

//在此下方插入自定义函数对的声明:

//主函数main
int main()
{

    float a, b, c;
    while (scanf("%f %f %f", &a, &b, &c) != EOF)
    {
        float delta = b * b - 4 * a * c;
        float x1, x2;
        if (delta >= 0)
        {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            printf("%.2f %.2f\n", x1, x2);
        }
        else
        {
            printf("NO\n");//NO不是No
        }
    }

    return 0;
} */
//主函数结束.
//在下方编写自定义函数:

/* 双参 递归案例题: */
/* 一场球赛开始之前,售票工作正在紧张的进行中。

每张球票为50元。
现有m+n个人排队等待购票,

其中有m个人手持50元的钞票,
另外n个人手持100元的钞票。

求出这m+n个人排队购票,使得售票处    不至于   出现找不开钱的局面的     不同排队  种数。(注意,允许出现0种哦.)
约定,拿  同样面值钞票的人  对换位置后为    同一种排队。

输入
输入m,n (m<100, n<100)

输出
输出排队种数

样例输入
15,12
样例输出
4345965
提示

算法思路
定义函 数f(m,n)  表示m个人手持50元,n个人手持100元共有的排队种数

这里有两个参量m,n ,情况会麻烦些.

先从 简单/极端  的情况入手讨论.(对这类情况的讨论往往为递归出口的处理和设计提供了便利):
当n=0,没有手持100元的人排队,这个情况是找得开钱 f(m,0) =1(且只有一种可能)

当m<n,(手持50元的人数小于手持100元的人数) f(m,n)=0

其他情况(m>n>0)
    又分为两种情况,但这次采用逆向(逆推)的思维考虑递推
    (是否感觉到,当大一些规模的问题要受较小规模时的解决方案的影响时,多多考虑递归的方案)
    而分类(无论时一个参量还是两个参量)思维会将递归的威力进一步发挥出来..以及边逆推边还原场景,边分类讨论.
当 第  m+n 个人  手持100元,他 之前  的m+n-1个人  有m个人手持50元,n-1个人手持100元,共有的排队种数为f(m,n-1)

当第m+n个人手持50元,他之前的m+n-1个人有m-1个人手持50元,n个人手持100元,共有的排队种数为f(m-1,n)

根据上述情况可得到

递归公式f(m,n)=f(m-1,n)+f(m,n-1)//在探究递推公式时,可以自己据一些小规模的例子类帮忙,以及验证公式的正确性.


递归出口:
n=0 f(m,0)=1
m<n f(m,n)=0

 */

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// #include <ctype.h>

// //在此下方插入自定义函数对的声明:
// int f(int m,int n)
// {
//     if (n == 0)/* 如果在判断句中把==写作了=,那么往往出不了结果,甚至segementation fault */
//     {
//         return 1;
//     }
//     else if (m < n)
//     {
//         return 0;
//     }
//     else
// //  {
//             //printf("f(m:%d,n:%d)\n", m, n);
//            /* return (一个或多个较小规模的f()的函数表达式. */
//         return f(m, n - 1) + f(m - 1, n);
//     }
// }
// //主函数main
// int main()
// {
//
//     int m, n;
//     while (scanf("%d , %d", &m, &n) != EOF)
//     {

//         printf("%d\n", f(m, n));
//         break;
//     }

//     return 0;
// }
//主函数结束.
//在下方编写自定义函数:

/*
将一个字符串中(没有空格)用科学计数法表示的数串转
换成对应的实数,结果保留 6 位小数。

输入仅一个字符串,该字符串中仅有一个用科学计数法表示的数据串。
输入
一个字符串中(字符中不含空格)包含  一个  用   科学计数法  表示的  数串(它的意思是从一段文字中要解析处数字的部分并进行转化,(默认是十进制的.))

输出
科学计数法表示的数串对应的实数

样例输入
abc1.32e+2defg
abc   1.32e+2  defg

样例输出
132.000000

 */

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// #include <ctype.h>

// //在此下方插入自定义函数对的声明:
// int is_legal_num_string(char *str, int digital_index_1st, int digital_index_last)
// {
//     int num_E_e = 0, index_E_e = -1; //index为了判断先后性.
//     int num_pointer = 0, index_pointer = -1;
//     /*下面的i任然是匹配于最原始的str中的索引 */
//     for (int i = digital_index_1st; i <= digital_index_last; i++)
//     {
//         /* 检查内部是否出现非法字符 */
//         if (str[i] != 'e' && str[i] != 'E' && str[i] != '.' && !isdigit(str[i]) && str[i] != '+' && str[i] != '-')
//         {
//             return 0;
//         }
//         else if (str[i] == 'e' || str[i] == 'E')
//         {
//             num_E_e++;
//             if (index_E_e == -1)
//             {
//                 index_E_e = i;
//             }
//         }
//         else if (str[i] == '.')
//         {
//             num_pointer++;
//             if(index_pointer == -1)
//             {
//                 index_pointer = i;
//             } /* code */
//         }

//         if (num_pointer > 1 || num_E_e > 1 || (index_pointer > index_E_e && index_E_e != -1))
//         {
//             return 0;
//         }
//     }
//     return 1;
//     /* 对'e','E','.'的重复性格检查. */
// }
// //主函数main
// int main()
// {

//     //复制模版式删除这个或者上面那个
//     char str[100]; //根据需要分配更大的维数
//         //while(scanf("%s",str) != EOF , str == " xxx")判断读到了什么;while(gets(str));
//     while (scanf("%s", str) != EOF)
//     {
//         int len = strlen(str);

//         int digit_1st_index = -1;
//         int digit_last_index = -1;
//         int e_index = -1;
//         // int part1 = 0;用来存储float将导致信息损失.
//         // int part2 = 0;
//         float part1 = 0;
//         float part2 = 0;
//         float result = 0;

//         float signal_1 = +1.0; /* 处理正负数的. 但在定义的时候要定义为float,否则int 下 1.0没用,还是1*/
//         float signal_2 = +1.0; /* 处理指数部分的正负. */
//         int i = 0;//小心放置.
//         int j = 0;
//         while (1)
//         {
//             digit_1st_index = -1;
//             digit_last_index = -1;
//             e_index = -1;
//             // int part1 = 0;用来存储float将导致信息损失.
//             // int part2 = 0;
//             part1 = 0;
//             part2 = 0;
//             result = 0;

//             i = j;//记录着经过了多少次for:
//             for (; i < len; i++)
//             {

//                 /* isdigit是计算机C(C++)语言中的一个函数,主要用于检查其参数 (某个ascii码 是否为十进制数字字符。 */
//                 /* 记录第一个数字字符出现的位置. */

//                 if (isdigit(str[i]) && digit_1st_index == -1)
//                 {
//                    digit_1st_index = i;
//                 }

//                 /* 找出科学计数法中出现e/E的位置 */

//                 if ((str[i] == 'e' || str[i] == 'E') && digit_1st_index != -1)
//                 {
//                     e_index = i;
//                 }
//                 /* 找出最该可能是科学计数法表示的数串 的 最后一个数码 */
//                 if (e_index != -1 && isdigit(str[i]) && !isdigit(str[i + 1]))
//                 {
//                     digit_last_index = i;
//                     break; /*abc1.32e+2defg */
//                 }
//             }

//             /* before deal,judge the number_string is legal? */
//             /* 如果的到了否定的结果,那就从下一个起始字符再判断. */
//             if (is_legal_num_string(str, digit_1st_index, digit_last_index))
//             {

//                 int change_char_to_int = 0;
//                 /* deal part1: */
//                 for (int i = digit_1st_index; i < e_index; i++)
//                 {
//                     if (str[i] != '.')
//                     {
//                         change_char_to_int = str[i] - 48;
//                         part1 = change_char_to_int + part1 * 10;
//                     }
//                 }
//                 if (str[digit_1st_index] == '-')
//                 {
//                     signal_1 = -1;
//                 }

//                 int setoff_point = e_index - digit_1st_index - 2;

//                 part1 = signal_1 * part1 / (float)(pow(10, setoff_point));

//                 /* deal part2: */
//                 int state = 0; /* 默认没有符号位. */
//                 if (!isdigit(str[e_index + 1]))
//                 {
//                     if (str[e_index + 1] == '-')
//                     {
//                         signal_2 = -1;
//                     }
//                     /* 符号位需要占一位. */
//                     state = 1;
//                 }

//                 for (int j = e_index + state + 1; j <= digit_last_index; j++)
//                 {
//                     change_char_to_int = str[j] - 48;
//                     part2 = change_char_to_int + part2 * 10;
//                     part2 *= signal_2;
//                 }

//                 result += part1 * pow(10, part2);
//                 printf("%.6f\n", result);

//                 break;
//             }//if

//             j++;

//         } //while(1)

//     } //while(scanf)
//     return 0;
// }
//主函数结束.
//在下方编写自定义函数:

/* 真子串是指从原字符串中   通过删除某些字符   但不破坏余下字符的顺序  而形成的新字符串。
输入n个  字符串,统计出现   某个字符串是另一个字符串的  真子串的  组数。

输入
输入n及n个字符串

输出
真子串数目

样例输入
3
abc
cxajfkabjfkdc
xjfabkdc
样例输出
3 

两两握手的规模.

*/

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// //#include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:
// /* 判断真子串:真子串是指从原字符串中   通过删除某些字符   但不破坏余下字符的顺序  而形成的新字符串 */
// int is_sub_string(char*a,char*b)
// {
//     int len_a = strlen(a);
//     int len_b = strlen(b);

//     char *longer = b;
//     char *shorter = a;
//     int len_longer = len_b , len_shorter = len_a;

//     if(len_a>len_b)
//     {
//        longer = a;
//        shorter = b;
//        len_longer = len_a;
//        len_shorter = len_b;
//     }

//     int is_match = 0;
//     int j = 0;
//     /* 不回头的遍历 */
//     for(int i = 0; i<len_shorter;i++)
//     {
//         for(;j < len_longer;j++)
//         {

//             if(shorter[i] == longer[j])
//             {
//                 is_match ++;

//                 break;
//             }
//         }
//         if (shorter[i] == longer[j])
//         {
//             j++;
//         }
//         if (is_match == len_shorter)
//         {
//             return 1;
//         }
//     }
//     return 0;
// }
// //主函数main
// int main()
// {
//     //复制模版式删除这个或者再下面一个
//     int n;

//     while( scanf("%d",&n) != EOF)
//     {
//         int sum = 0;
/* 用指针读入一系列的字符串 */
//         int k = 50;
//         char* p = (char*)malloc(sizeof(char)*k*k);
//         char* q = p;//拷贝初始地址以备用.

//         for(int i = 0;i<n;i++)
//         {
//             scanf("%s",p);
//             p += k;
//         }
//         p = q;//将指针回拨到初始位置(之前由于读入数据导致偏移.

//         for(int i = 0;i<n;i++)
//         {
//             for(int j = i + 1;j < n;j++)
//             {
//                 sum += is_sub_string((p+k*i),(p+k*j));
//             }
//         }
//         printf("%d\n",sum);

//     }

//     return 0;
// }
//主函数结束.
//在下方编写自定义函数:


/* 输入10个整数,
将其中最小的数与第一个数对换,
把最大的数与最后一个数对换。

写三个函数; ①输入10个数;②进行处理;③输出10个数。

输入
10个整数

输出
整理后的十个数,每个数后跟一个空格(注意最后一个数后也有空格)

样例输入
2 1 3 4 5 6 7 8 10 9
样例输出
1 2 3 4 5 6 7 8 9 10 
 */

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// void swap_int_pointer(int *a, int *b)
// {
//     int temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }
// //在此下方插入自定义函数对的声明:
// /* 用指针读入并保存数字,如果读取结束/出错,返回0,如果读取成功,返回1 */
// int read(int *p, int n)
// {
//     for (int i = 0; i < n; i++)
//     {

//         if(scanf("%d", p + i) == EOF)
//         {
//             return 0;
//         }
//     }
//     return 1;
// }
// void deal(int *p,int n)
// {
//     int min_index = 0; /* 最小元素的 索引/偏移量 */
//     int max_index = 0;

//     for (int i = 1; i < n; i++)
//     {
//         if (*(p + min_index) > *(p + i))
//         {
//             min_index = i;
//         }
// /*
//         由于本题要求交换的操作有两处,故不宜同时确定min_index 和max_index,因为第一次swap后元素的排列很可能发生了改变.
//         宜再第一次swap后再重新扫描.
//         if (*(p + max_index) < *(p + i))
//         {
//             max_index = i;
//         } */
//     }

//     // int temp;
//     // temp = *(p+min_index);
//     // *(p+min_index) = *(p);
//     // *p = temp;
//     swap_int_pointer(p + min_index, p);
//     //这里发生了自定义的函数嵌套调用,因为内部的函数在外部函数之前定义了所以不必再在调用函数里声明,类似于main()
//     for (int i = 1; i < n; i++)
//     {

//         if (*(p + max_index) < *(p + i))
//         {
//             max_index = i;
//         }
//     }
//     swap_int_pointer(p + max_index, p + n - 1);
// }

// void print(int *p,int n)
// {
//     for(int i = 0;i<n;i++)
//     {
//         printf("%d ",*(p+i));
//     }
//     printf("\n");
// }
// //主函数main
// int main()
// {
//     //复制模版式删除这个或者再下面一个
//     int n;

//     int size_int = sizeof(int);
//     int *p;
// //printf ("test\n");
//     p = (int *)malloc(10 * size_int);
//     //free(p);

//     while (read(p, 10))
//     {
//         deal(p, 10);
//         print(p, 10);
//     }

//     free(p);

//     return 0;
// }
//主函数结束.
//在下方编写自定义函数:

/* 问题D:时钟夹角
题目描述
fire现在没有事情做,只能看着时钟发呆,出于对数据的渴望,

突然他想知道这个表的时针和分针的夹角是多少？

现在fire知道的只有时间,请你帮他算出这个夹角。

注:夹角的范围[0,180],时针和分针的转动是连续而不是离散的。
输入
输入数据的第一-行是一-个数据T,表示有T组数据。每组数据有三个整数 h(0<= h<24),m(0<= m< 60),
s(0<=s< 60)分别表示时、分、秒。
输出
对于每组输入数据,输出夹角的大小的    整数部分。
样例输入
2
8 3 17 
5 13 30

样例输出
138
75

!分析:
事实上,其实如果肉眼足够强大的化,分针和秒针是不必要看的
(时针是能够反赢分钟和秒针的位置的,时针外的两个指针是为了弥补肉眼的不足)
同样的对于分针来讲,秒针也只是帮助人眼观察,(分钟本身是可以反映秒针的位置呢)

我们不妨先考虑秒针为零的基准状况:
另外,
写个函数,
秒针相对于12点/0点刻度的偏转量;
再写个函数计算分针对12/0点的偏转角度
最后求时针对12点的偏转量.
再将后两者做差.

秒针转动一格:即秒针偏转6°(时间推进了一秒钟,== 1/60分钟 == 1/3600小时)
那么这时候,分针将偏转:6°*(1/60);
时针将偏转6°*(1/3600);

分钟转动一格,时钟偏转6°*(1/60)
(总之,上一级的偏转量要基于(且仅基于)下一级别指针的偏转量)
 
基于上,可以算出
 */

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// #define ANGLE_PER_MINUTE 6
// #define ANGLE_PER_HOUR 30
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// //#include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:
// float minute_hand_angle(int minute,int second)
// {
//     float minute_offset = 0;
//     minute_offset += ANGLE_PER_MINUTE * ( minute + second  / 60.0);//be careful.
//     return minute_offset;/* 返回分针偏转角度. */
// }
// /*莫把分钟数和分针偏转角搞混了. */
// float hour_hand_angle(int hour,int minute,int second)
// {
//     float hour_offset = 0;
//     /* 先将秒钟数整合到分钟数,将分钟数整合到小时(单位转换),最后乘以每小时的偏转角. */
//     hour_offset += ANGLE_PER_HOUR * ( hour + (minute + second / 60.0 )  / 60.0 );
//     return hour_offset;
// }
// //主函数main
// int main()
// {
//     //复制模版式删除这个或者再下面一个
//     int n;
//     struct time{
//         int hour;
//         int minute;
//         int second;
//     }time_in_day;
//     struct time *p;
//     p = &time_in_day;
//     while (scanf("%d", &n) != EOF)
//     {
//         for(int i = 0;i<n;i++)
//         {
//             scanf("%d %d %d", &(p->hour), &(p->minute), &(p->second));
//             if(p->hour >= 12) p->hour -= 12;
//             float angle_minute = 0, angle_hour = 0;
//             angle_minute = minute_hand_angle((p->minute), (p->second));
//             angle_hour = hour_hand_angle( p->hour, p->minute,p->second);

//             /* -0.5是为了向下取整(否则系统将四舍五入.) */

//             //取出一个浮点数的小数部分
//             float result = fabs(angle_minute - angle_hour);

//             if (result <= 180 && result > 0.4)
//             {
//                 printf("%.0f\n", result - 0.5);
//             }
//             else if (result <= 0.4)
//             {
//                 printf("%.0f\n", result );
//             }

//             else
//             {
//                 printf("%.0f\n", 360 - result - 0.5);
//             }
//         }
//     }

//     return 0;
// }
//主函数结束.
//在下方编写自定义函数:

/* 问题C:日子计算(结构+函数)[易]
题目描述

定义一个  结构体变量(包括年、月、日),计算该日  在本年中为第几天？

(注意考虑闰年问题)要求写-一个函数days,实现上面的计算。
由主函数将年月日传递给days函数,计算后将日子传递回主函数输出。

输入
输入年月日。
输出
输入该日在本年中为第几天。
样例输入
2001.3.13样例输出

72 
*/

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// /* 判断润年 */
// int is_leap_year(int year)
// {
//     if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//     {
//         return 1;
//     }
//     return 0;
// }

// //在此下方插入自定义函数对的声明:
// int sum_month_to_day(int month_num,int *month)
// {

//     int i = 0,sum = 0;
//     for(;i<month_num;i++)
//     {
//         sum += month[i];
//     }
//     return sum;
// }
// //主函数main
// int main()
// {
//     //复制模版式删除这个或者再下面一个
//     struct date{
//         int year;
//         int month;
//         int day;
//     } date;
//     int day = 0;
//     int leap_year[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
//     int nonleap_year[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};//也可以通过if来省掉该行.
//     while( scanf("%d . %d . %d",&date.year,&date.month,&date.day) != EOF)
//     {
//         if(is_leap_year(date.year))
//         {
//             day = sum_month_to_day(date.month,leap_year) + date.day;
//         }
//         else
//         {
//             day = sum_month_to_day(date.month,nonleap_year) + date.day;
//         }
//         printf("%d\n",day);
//     }

//     return 0;
// }
//主函数结束.
//在下方编写自定义函数:

/* 间题B:买水果(结构体)
题目描述
Lulu想要买水果,市场有很多水果,价格都不一样,ulu想从最便宜的开始买。请你帮她算一下吧。

输入
第一行是一个整数T(I<=T<=100,表示有T组数据,

每组数据第一行为n,有n种水果,

接下来有n行,每行有一个水果名字和相应的单位重量价格

输出
对每组数据,按价格从小到大的顺序输出水果。格式为水果名字和价格。
样例输入
1
3
apple 12
banana 15
pear 8

样例输出
pear 8
apple 12
banana 15 */

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// //#include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:

// //主函数main
// struct fruit
// {
//     char name[10];
//     int price;
// };
// int main()
// {
//     int n;
//     scanf("%d", &n);

//     while (n--)
//     {
//         //int index_up[100];
//         struct fruit fruits[100]; /* 使用结构体定义变量的时候务必不要将struct丢下而单抽出结构名fruit,否则系统
//            识别不出来你是要定义某个结构体相关的变量/数据类型.,他会认为这只是一未定义的标识符.struct告诉系统一下.*/
//         int m;
//         scanf("%d", &m);
//         /* Write data to structure array */
//         for (int i = 0; i < m; i++)
//         {
//             /* 而在取用成员的时候,由于成员运算符的使用,使得系统能够辨认出这个标识符是个结构体. */
//             scanf("%s",fruits[i].name);
//             scanf("%d",&fruits[i].price);

//         }
//         //这是相当低效的(这里用结构体相互赋值,只是为了加深理解而已.)
//         for(int i = 0;i<m - 1;i++)
//         {
//             for (int j = 0; j <= m - 2 - i; j++)
//             {
//                 if (fruits[j].price > fruits[j + 1].price)
//                 {
//                     struct fruit temp;
//                     temp = fruits[j];
//                     fruits[j] = fruits[j+1];
//                     fruits[j+1] = temp;
//                 }
//             }
//         }
//         for(int i = 0;i<m;i++) printf("%s %d\n" ,fruits[i].name,fruits[i].price);

//     }

//     return 0;
// }
//主函数结束.
//在下方编写自定义函数:

/* 问题A:判断逆序是否相等(字符串+指针)
题目描述
现在有一系列的字符串,要求你编写一个程序判断这个字符串的逆序是否和他本身一样,若-样则输出
"Yes"否则输出"No"
输入
有多组输入,每行表示一一个字符串(不超过100位)
输出
对于每组输入输出"Yes"或"No" */

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// #include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:
// void reverse_string(char *str)
// {
//     int len = strlen(str); //the lenth of string,it is not the same with the index.
//     /* len 为奇数时:len 为偶数也可用次for   关键在于对调的次数上的控制. */
//     for (int i = 0; i < len / 2; i++) /* 画个图,算出len的值,标上两端及中间的关于(len的表达式),将会一目了然 */
//     {
//         char temp;
//         temp = str[len - 1 - i];
//         str[len - 1 - i] = str[i];
//         str[i] = temp;
//     }

// }
// //主函数main
// int main()
// {

//     char str[100];//根据需要分配更大的维数
//     char cp[100];
//         //while(scanf("%s",str) != EOF , str == " xxx")判断读到了什么;while(gets(str));
//     while( gets(str))
//     {

//         strcpy(cp,str);
//         reverse_string(cp);
//         if( ! strcmp(str,cp))
//         {
//             puts("Yes");//puts()自带换行效果.
//         }
//         else
//         {
//             printf("No\n");
//         }

//     }
//     return 0;
// }
/* 
葱葱跟巴豆玩游戏。游戏规则很简单,就是比大小。

他们各自从牌堆里随机抽出   十一张牌,
牌上面标有数字N,0<N<=1000,
同一数字的牌只有一张,不会重复。
然后他们各自从手里拿出一张牌比大小,
牌数大的得一点分数,最后谁得到的分多谁就胜利。
葱葱耍了点小手段,知道巴豆的手牌,以及巴豆的出牌顺序

那么葱葱最多可以拿几分呢？
    现在给出两行数据,第一行有十一个数字为葱葱的手牌,
    第二行也有十一个数字是巴豆的手牌。
输出为葱葱最多可以拿几分。

输入
测试数据有多组,每组测试数据包括2行:
每行有十一个数字N,0<N<=1000。
输出
输出整数M,M为葱葱   最多可以  拿到的分数。

样例输入
12 13 14 15 16 17 18 19 20 21 22
1 2 3 4 5 6 7 8 9 10 n
样例输出
n 

贪心算法 类似:田忌赛马问题
这个题目贪心的本质在于:(浪费别人好马,节约自己的好马)
*田忌只在有把握赢的情况下(能赢就赢)  拿出 快马(比王的马要稍微较快点的马(不要浪费更好的马))和王比,
否则用  最慢(尽可能慢)的马(最大程度 浪费)掉王的快马   

贪心策略:
明确一个方向入手;迭代减小规模.
1,
如果田忌的最快马快于齐王的最快马,则两者比。
(因为若是田忌的别的马很可能就赢不了了,所以两者比)
2,
如果田忌的最快马慢于齐王的最快马,则用田忌的   最慢马和齐王的最快马比。
(由于所有的马都赢不了齐王的最快马,所以用损失最小的,拿最慢的和他比)
3,!!!!
若相等,则比较田忌的最慢马和齐王的最慢马
a.若田忌最慢马  快于  齐王最慢马,两者比。(在这两场比赛中,田忌能赢1场,最慢的马能用来赢,何乐而不为.)
(田忌的最慢马既然能赢一个就赢,而且齐王的最慢马肯定也得有个和他比,)
b.其他,则拿田忌的最慢马和齐王的最快马比(注意两马战力相等的情况,不能算田忌输)。
(反正所有的马都比田忌的最慢马快了,所以这匹马必输,选贡献最大的,干掉齐王的最快马)

*/

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// //#include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:
// void swap_int_pointer(int *a, int *b)
// {
//     int temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }
// /* 指针版冒泡排序(整数版) (两重for,一个if_swap()*/
// void bubble_int_sort(int *p, int n)
// {
//     void swap_int_pointer(int *a, int *b);
//     /* 冒泡 枚举图解:https://img02.sogoucdn.com/app/a/100520146/2ebb85e6d696706cd231a745c593b1dd*/
//     /*冒泡法不需要设立最值flag. */
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = 0; j <= n - 2 - i; j++)
//         {
//             /*通过改变'<'为'>',可以从降序转为升序; 通过监视*(p+j)和*(p+j+1)可以知道当前(第j组)相邻量的值的情况 */
//             if (*(p + j) < *(p + j + 1))
//             {
//                 swap_int_pointer(p + j, p + j + 1);
//             }
//         }
//     }
// }
// //主函数main
// int main()
// {
//     //复制模版式删除这个或者再下面一个
//     int n = 11;
//     int *p;//田忌马(葱葱)
//     int *q;//王马(巴豆)

//     int size_int = sizeof(int);
//     p = (int *)malloc(n * size_int);
//     q = (int *)malloc(n * size_int);
//     while (scanf("%d", p) != EOF)//注意了,malloc必须安排再scanf之前,否则无法读入(指针找不到内存)
//     {

//         for (int i = 1; i < n; i++)
//         {
//             scanf("%d", p + i);
//         }
//         for (int i = 0; i < n; i++)
//         {
//             scanf("%d",q+i);
//         }

//         bubble_int_sort(p, n);
//         bubble_int_sort(q, n);

//         int win = 0;
//         /* 将参加比赛的马的位置 置为0,以便重新排序,实现迭代 */
//         for (int i = 0,j = 0; j < n; j++)
//         {
//             if (*(p + i) > *(q+i))
//             {
//                 win++;
//                 *(p+i) = *(q+i) = 0;
//             }
//             else if (*(p+i) < *(q+i))
//             {
//                 /* 田忌的最差马和王的最优马比 */
//                 *(p+n-1) = *(q) =  0;
//             }
//             else /* 双方快马一样快. */
//             {
//                 /*比较最慢的马的状况 */
//                 if(*(p+n-1) > *(q+n-1))/* 田忌最慢马能赢过王的最慢马. */
//                 {
//                     win++;
//                     *(p+n-1) = *(q+n-1) = 0;
//                 }
//                 else/* 其他情况,则让田忌最慢的马和王的最优马比 */
//                 {
//                     *(p+n-1) = *q = 0 ;
//                     /* 这一场田忌输. */
//                 }
//             }
//             /* 待优化 */
//             i = 0;
//             /* 重新排序 */
//             bubble_int_sort(p, n);
//             bubble_int_sort(q, n);

//         }
//         printf("%d\n",win);
//     }
//         return 0;
// }
//主函数结束.
//在下方编写自定义函数:

/*
 计算字符串中子串出现的次数

输入
输入以空格相隔的两个字符串(字符数不大于20个),敲回车

输出
统计第一个字符串中   第二个字符串  出现的次数

样例输入
Goodoo o
样例输出
4 */

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// //#include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:

// //主函数main
// int main()
// {
//     char s1[100];
//     char s2[100];//根据需要分配更大的维数
//     char buf[100];

//         //while(scanf("%s",str) != EOF , str == " xxx")判断读到了什么;while(gets(str));
//     while( scanf("%s %s", s1,s2) != EOF)
//     {
//         int cnt = 0;
//         int len = strlen(s1);
//         int len_2 = strlen(s2);
//         int j = 0;
// /* 挨个字符扫描.(若匹配s2则跳跃len_2 个字符(避开重叠地情况)) */
//         for(int i = 0;i < len;i++)
//         {
// /* 单个字符地去匹配. */
//             for( j = 0;j < len_2;j++)
//             {
//                 if(s1[i+j] != s2[j])
//                 {
//                     break;
//                 }

//             }
//      /* 匹配成功,则跳过len_2个字符, */
//             if(j >= len_2)
//             {
//                 cnt++;
//                 i += len_2 -1;/* 由for的i++补上. */
//             }
//         }
//         printf("%d\n",cnt);

//     }
//     return 0;
// }
//主函数结束.
//在下方编写自定义函数:

/* 
* 圈报数问题.(和列报数问题的共同点在于:(有效)报数记录器的使用及重置
有n个人(n<=1000),用1,2,...,n编号,顺序排列,
 并首尾相连围成一圈。从第一个人开始报数(从1到4),凡报到4的人退出圈子,
 且后面的人继续报数(同样从1到4报数),问最后留下的是原来第几号的那一位(用指针实现)。

输入
输入正整数n。

输出
输出最终留下的那个人的编号。

样例输入
53
样例输出
7
提示 */

 #include <stdio.h>
 #define N 1000
 int main()
 {
     void dismiss(int m);/*声明函数*/

     int n;
     scanf("%d", &n);/*读入学生规模*/

     dismiss(n);/*调用处理函数*/
     return 0;
 }
 /*处理函数(包括打印)*/
 void dismiss(int m) //m位同学
 {
     int i, /*循环变量*/
         j = 0, /*报数数码记录器j */
         t = 0;/*记录已经离场的学生的数目*/
     int identifier[N]; //保存编号identifier
     int *p = identifier;
     /*初始化数组*/
     for (i = 0; i < m; i++)/*[0,m-1]*/
     {
         *(p + i) = i + 1; //通过指针创建/修改了数组里的内容(生成编号.)
     }

     //如果不对数组进行剪裁的话,则需要一个东西(这里定义了数码记录器j)来记录当前所报的数码(在1,2,3,4中循环)
     //在编号位没有被摸为零的,可使所报数码+1每报到数码4的时候,作剔除(摸零);从头开始报(1,2,3,4)
     /* 不得不说,这个for是巧妙的:
 1.他的循环结束判断条件不是直接由循环变量i来控制的,
 而是借助与另一个关键指标(变量t):被剔除的学生数目是否达到了(学生总数-1),即是否只剩一个同学在场了
 那么i加到什么时候是个尽头?这无所谓了.*/
     /* 这个for要实现当访问到尾的时候能够回到头部(通过 判断(是否末尾--若是,重置i  再扫描来实现) */
     for (i = 0; t < m - 1; i++) 
     {
         /* 该编号的同学是否已被抹去/有效,若有,使所报数码j++;如果使用的是0/1状态数组,可以省去判断,直接用一句:j += state[i];即可. */
         if (identifier[i] != 0)
             j++;

         if (j == 4) //所报数值累计到4的同学://而且每达到4,重置j= 0;
         {
             *(p + i) = 0; //赋值位0表示离开/抹去

             j = 0; //重置数码记录器
             t++;   //记录被抹去了多少位同学.当该数值达到n-1时,则只剩下一个同学了,结束循环
         }
         /* 判断是否到了结尾identifier[m-1] 了(最后一个元素的索引 m-1),处理回头问题. :
         通过重置i=-1为啥不是0?,因为回到for的时候会i++的identifier[0]..,*/
         if (i >= m - 1)
             i = -1;
     }
     /*打印结果:*/
     for (i = 0; i < m; i++)
     {
         if (identifier[i] != 0)/*如果使用0/1 state[]数组,也是如此判断打印.*/
             printf("%d", i + 1);
     }
 }

 /*
列报数问题:
编号为1,2,…,n的n位小朋友依次排成一列,从1号开始1,2,…,m报数,
凡报到m者出列, 直至报数到队列尾部。
此后, 又从 队列尾部 开始  反向  1,2,…,m报数, (这里是指尾部的同学原有的recorder被1,2,,m覆盖.)
凡报到m者同样出列。这样反复顺逆报数,

直至队列剩下m-1个小朋友为止。

问:最后未出列的m-1位小朋友编号为多少？
    第p个出列的是哪位小朋友？

输入
输入n(初始小朋友总数),m,p ((小盆友数目)  m <= n <=500,(报数m的取值范围.)1 <= m <= 20,  (第p位出列的小朋友的编号范围.1 <= p <= n-m+1(保留m-1位不出列)

输出
输出  未 出列 的m-1位小朋友的编号

输出第p位出列的小朋友编号

样例输入
100,3,50
样例输出
4 77 (未出列的m-1位小朋友的编号序列)
25(第p位出列的小朋友编号)
 */

 //#include <stdio.h>
 //int main()
 //{
 //	int ln,/*累计离开的同学的数目*/
 //        x,/*保存第p个出列的同学的编号;只允许被修改一次*/
 //        s, /*报数记录器s,累计该轮同学的有效报数(离场的同学当然就报不了数啦/或者要说跳过).*/
 //        i,/*循环变量.*/
 //        n, /*小朋友总数目*/
 //        m, /*报到m的同学要出列*/
 //        p;/*指定的第p位同学的编号*/
 //
 //	int t;
 //
 //	int a[501];/*数组的索引表示最初的同学的所编号.*/
 //	scanf("%d,%d,%d", &n, &m, &p);
 //	/* 每位同学初始化为1*/
 //	for (i = 1; i <= n; i++)
 //		a[i] = 1;/* a[i] = 1 表示该位(编号位i)的同学在场,否则(若被修改为0表示离场出列) ,
 //		这个是挺巧妙,为配合报数记录器的使用提供了方便,如果第i号同学出列了,
 //		那么s += a[i] 能够统一起来完成计数的工作(只有在场的同学才会使s增加.*/
 //
 //	ln = 0;
 //	x = 0;
 //	t = 0;//t类似于flag,如果if中的式子长,可以考虑引用,但不是必须的)
 //
 //	while (1)
 //	{
 //        /*顺序筛查队列*/
 //		for (s = 0, i = 1; i <= n; i++)
 //		{
 //			/* 循环变量i表示学生编号.(第i位学生.) */
 //			s += a[i];//s记录该轮有效报数情况有效报数次数,s达到m(次时,对应的编号位i的同学离场);这里刚好可以省去对a[i]是否有效(i号同学是否离场)的判读,直接s +=a[i];
 //            
 //			if (s == m)//s达到m(次时,对应的编号位i的同学离场)
 //			{
 //				a[i] = 0;//抹去该同学.
 //				s = 0;//重置报数记录器s.
 //				ln++;//累计离开的同学的数目.
 //			}
 //
 //            /*记住第p个出列的同学的编号i,存入x;注意x的值只可被修改一次(才是有效且正确的)*/
 //			if (ln == p && x == 0)//x==0来判断x是否已修改过.
 //				x = i;//x用来保存第p位离开的同学的编号.(被指定要打印出来的.)
 //			/* 值得注意的是,同一个p下可能对应多个i,(或者说知道下一个同学报m之前的若干个i都不会让p变化(增加),所以要记住第一个i才是正确的编号,否则
 //			不同的i下可能对应同一个ln,导致出错,可通过判断保存该编号的变量是否为初始值来避免重复写入.) */
 //
 //			/* 离开的人数达到上限(报数活动达到结束要求.):跳出循环 */
 //			if (ln == n - m + 1)
 //			{
 //				// t = 1;
 //				break;
 //			}//结束内层for:1.当i遍历到最后一位同学时:当满足break的条件时.
 //		}//for
 //        /*再跳出外层循环while*/
 //		if (ln == n - m + 1/* t == 1 */)
 //			break;
 //
 //		/* 开始逆序筛查: 从 n~1(为了不与顺序筛查的过程产生干扰,将逆序筛查的工作于顺序筛查相互独立(当然这两个模块几乎一样,循环遍历的编号趋势相反而已,可以考虑编一个函数.考虑预编译处理.);想要一口气解决两个方向的筛查往往会导致杂乱. */ 
 //        /* 之前我想的复杂了,这里不需要记住之前的报数记录承接情况,反正到了一端,都是要从1再报起,粗暴.
 //		为了推动这两个循环运作知道得出答案为止,又在最外层设置了一个while循环.
 //        (得到答案时,从最内层循环连续break出来)
 //		只要分为一来一往的 两类循环即可.而这两个循环有共同的累计量.(ln) */
 ///************************************************************************/
 //		for (s = 0/* 报数记录器重置 */, i = n; i >= 1; i--)
 //		{
 //			s += a[i];
 //			if (s == m)
 //			{
 //				a[i] = 0;
 //				s = 0;
 //				ln++;
 //			}
 //            /*与第一个模块一样,都要检测i是否是第p位离场的同学,是否到游戏结束的时候了*/
 //			if (ln == p && x == 0)
 //				x = i;
 //
 //			if (ln == n - m + 1)
 //			{
 //				//t = 1;
 //				break;
 //			}
 //		}//for
 //		if (ln == n - m + 1)
 //			break;
 //	}//while
 //
 //    /*打印*/
 //    for (i = 1; i <= n; i++)
 //    {
 //        if (a[i] != 0)
 //            printf("%d ", i);
 //    }
 //	printf("\n");
 //
 //	printf("%d\n", x);
 //
 //	return 0;
 //}

 /* 如果条件改为每回 扫描承接上一次报的数 */
 // #include <stdio.h>
 // #include <string.h>
 // #include <math.h>
 // #include <stdlib.h>

 // //主函数main
 // int main()
 // {
 //     //输入n,m,p
 //     int n,m,p;

 //     while( scanf("%d , %d , %d",&n,&m,&p) != EOF)
 //     {
 //         int size_int = sizeof(int);
 //         int *ptr = (int *)malloc(n*size_int);
 //         //free(ptr);
 //         /* 初始化小朋友的编号.记录处理结果. */
 //         for(int i = 0;i < n;i++)  *(ptr + i ) = (i+1);

 //         int change = 0;/* 这个东西可不要放在循环里 */

 //         int counting_recorder = 1;
 //         int children_off = 0;/*累计离开的小朋友数目.  off + still = n;still = m-1 ;off = n-m+1 */
 //         int i = 0;
 //         int p_th_off ;/* 记录第ptr位离开的同学的编号. */

 //         /* off = n-m+1 时离开for(停止报数.) */
 //         for(i = 0; children_off < n-m + 1;)
 //         {
 //             /* to judge whether the child is still ptrresent and he/she doesn't reptrort m*/
 //             if (*(ptr + i) != 0 && counting_recorder != m)
 //             {

 //                 counting_recorder++; /* 这里的++是下一个同学所要报的数 */
 //             }
 //             else if (*(ptr + i) != 0 && counting_recorder == m) /* the child reptrort m: */
 //             {
 //                 ++children_off;        /*这里对child_off的累加必须是基于在场的同学,否则对空位多次相加显然达不到目的*/
 //                  /* 另外,它必须在该位同学离开前记录下编号.否则被抹成0,就坏了.  */
 //                 if (children_off == p) //
 //                 {
 //                     //p_th_off = children_off;/* 我们要的是编号. */
 //                     p_th_off = *(ptr + i);
 //                 }
 //                 *(ptr + i) = 0; /* this optreration means the child leaving.*/

 //                 counting_recorder = 1;/* reset the recorder.for the next child who is ptrresent 准备下一位同学要报的数*/
 //                 //children_off ++;
 //             }

 //             if( i < n -1   && change ==  0)/* i 从0 开始.增加 */
 //             {
 //                 i++;
 //                 /* 跳出循环前,改变下change */
 //                 if(i == n - 1 )
 //                 {
 //                     change = 1;
 //                     /* 监视内部过程. */
 //                     // /* 如果这里的不定义for 专属的i,那会造成上面的含i式紊乱. */

 //                 }
 //             }

 //             else/* i 从n-1开始递减 */
 //             {

 //                 i--;
 //                 /* 跳出循环前,改变下change */
 //                 if (i == 0)
 //                 {
 //                     change = 0;
 //                     //  /* 监视内部过程. ,但注意,是从遵从s型来回看,而并不总是从前往后看*/
 //                     // for (int i = 0; i < n; i++)
 //                     // {
 //                     //     if (*(ptr + i) != 0)
 //                     //     {
 //                     //         printf("%d ", *(ptr + i));
 //                     //     }
 //                     // }
 //                     // printf("\n");
 //                 }
 //             }
 //         }

 //         for(int i = 0;i < n;i++)
 //         {
 //             if(*(ptr+i) != 0)
 //             {
 //                 printf("%d ",*(ptr+i));
 //             }
 //         }
 //         printf("\n");

 //         printf("%d\n", p_th_off);

 //         free(ptr);
 //     }

 //     return 0;
 // }
 //主函数结束.
 //在下方编写自定义函数:

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// //#include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:
// int strcmp_mine(char*p, char*q)
// {
// 	int len_p = strlen(p);
// 	int len_q = strlen(q);
// 	for (int i = 0; i < len_p && i < len_q; i++)
// 	{
// 		if (*(p + i) == *(q + i))
// 			;
// 		else if (*(p + i) != *(q + i))
// 		{
// 			return *(p + i) - *(q + i);
// 		}
// 	}
// 	return 0;
// }
// //主函数main
// int main()
// {
// 	//复制模版式删除这个或者再下面一个
// 	int n;
// 	while (scanf("%d", &n) != EOF)
// 	{

// 		//printf("test:\n");
// 		/* char s1[100],s2[100]; */
// 		char *p, *q;
// 		int size_char = sizeof(char);
// 		p = (char *)malloc(100 * size_char);
// 		q = (char *)malloc(100 * size_char);

// 		scanf("%s %s", p, q);
// 		printf("%d\n", strcmp_mine(p, q));
// 	}

// 	return 0;
// }
/* 不吉利的数字为所有含有4或38的号码。例如:
38315 73418 88914
都属于不吉利号码。但是,3n582虽然含有3和8,但不是38连号,所以不属于不吉利数字之列。
你的任务是,对于每次给出的一个牌照区间号,推断出交管局今次又要实际上给多少辆新的士车上牌照了。
输入
输入的都是整数对n、m(0<n≤m<1000000),如果遇到都是0的整数对,则输入结束。
输出
对于每个整数对,输出一个不含有不吉利数字的统计个数,该数值占一行位置。
样例输入
1 100
0 0
样例输出
80
 */

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// //#include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:
// /* 取出读入的数据的数码,并且返回这个数的位数: */
// int fetch_num_char(int n,int *num_char)
// {
//     int i = 0;
//     int cnt=0;
//     for(;n>0;)
//     {
//         num_char[i++] = n%10;
//         n /= 10;
//         cnt++;
//     }
//     for(i = 0;i<cnt/2;i++)
//     {
//         int temp;
//         temp = num_char[i];
//         num_char[i] = num_char[cnt-1-i];
//         num_char[cnt-1-i] = temp;
//     }
//     return cnt;
// }
// /* 监测号码中的不吉利数 */
// int is_bad_num(int *num,int n)
// {
//     /* 由于一下两个标准边界不一 */
//     /* 监测4 */
//     for(int j= 0;j<n;j++)
//     {
//         if(num[j] == 4)
//             return 1;
//     }

//     /* 监测38 */
//     for(int i= 0;i < n -1;i++)
//     {
//         if( (num[i] == 3) && (num[i+1] == 8)  )
//         {
//                 return 1;
//         }
//     }

//     return 0;
// }
// //主函数main
// int main()
// {
//     //复制模版式删除这个或者再下面一个
//     int n,m;
//     int len_number;
//     int num_char[100];

//     while( scanf("%d%d",&n,&m) ,n != 0 || n != 0)
//     {
//         int good_number = 0;
//         for(int i = n;i<m+1;i++)
//         {
//             len_number = fetch_num_char(i,num_char);
//             if(! is_bad_num(num_char,len_number) )
//             {
//                 good_number++;

//             }
//         }
//      printf("%d\n",good_number);
//     }

//     return 0;
// }
//主函数结束.
//在下方编写自定义函数:

/* 编写一函数,实现两个字符串的比较。即自己写一个strcmp函数,
 函数原型为strcmp(char *p1,char *p2),设p1指向字符串s1,p2指向字符串s2。要求当s1=s2时,返回值为0;
 (s1,s2长度相等并且不超过100) 若s1！=s2,返回它们两者第一个不同字符的ASCII码差值
 (如“BOY”与“BAD”,第2个字母不同,“O”与“A”之差为79-65=14);如果s1>s2,则输出正值,反之输出负值。(本题要求用指针来做)
输入
第一行为N,表示接下来有N组测试数据。接下来的N行表示N组测试数据,
每组测试数据包含两个字符串,中间用空格隔开,并且保证每个字符串中的字符都是小写字母。
输出
输出两个字符串比较的结果。
样例输入
2
abcdef aaaaaa
a z
样例输出
1
-25 
*/

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// //#include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:
// int strcmp_mine(char*p, char*q)
// {
// 	int len_p = strlen(p);
// 	int len_q = strlen(q);
// 	for (int i = 0; i < len_p && i < len_q; i++)
// 	{
// 		if (*(p + i) == *(q + i))
// 			;
// 		else if (*(p + i) != *(q + i))
// 		{
// 			return *(p + i) - *(q + i);
// 		}
// 	}
// 	return 0;
// }
// //主函数main
// int main()
// {
// 	//复制模版式删除这个或者再下面一个
// 	int n;
// 	while (scanf("%d", &n) != EOF)
// 	{

// 		//printf("test:\n");
// 		/* char s1[100],s2[100]; */
// 		char *p, *q;
// 		int size_char = sizeof(char);
// 		p = (char *)malloc(100 * size_char);
// 		q = (char *)malloc(100 * size_char);

// 		scanf("%s %s", p, q);
// 		printf("%d\n", strcmp_mine(p, q));
// 	}

// 	return 0;
// }
//主函数结束.
//在下方编写自定义函数:

/* 按时间顺序给出奥运会的获奖情况,根据获奖情况输出当前奥运金牌榜。

输入
第一行一个整数N,代表奖牌的数量。
接下来N行,每行代表  (奖牌机器所属的国家的名字)和奖牌的类型。
为了简化问题,国家名中不存在空格。
N<=500
输出
按金牌数量降序输出每个国家的名称,及金银铜牌的数量,用空格隔开。
若金牌数相同,则比较银牌的数量。
若金牌银牌的数量都相同,则比较铜牌的数量。

样例输入
10
zhongguo jin
zhongguo tong
meiguo jin
yidali jin
faguo jin
faguo tong
meiguo yin
meiguo yin
eluosi tong
zhongguo jin
样例输出
zhongguo 2 0 1
meiguo 1 2 0
faguo 1 0 1
yidali 1 0 0
eluosi 0 0 1 
*/
// #include <stdio.h>
// #include <string.h>
// #define GOLD 10000
// #define SILVER 100
// #define COPPER 1
/* 按照降序提取出某组数据的索引(数据又cnt个,原始数据存在weights数组中,提取出的索引序列保存在sort数组中) */
// void sort_link(int *weights,int* sort,int cnt)
// {

//     for (int i = 0; i < cnt; i++) //控制扫描次数
//     {
//         int max_index = 0;

//         for (int j = 0; j < cnt; j++) //每次都从头到尾扫描
//         {
//             if (weights[max_index] < weights[j])
//             {
//                 max_index = j;
//             }
//         }

//         sort[i] = max_index;//保存该次扫描中的max_index;
//         weights[max_index]= -1;//以此实现迭代
//     }
// }
// int main()/* 如果int main 写作intmain,会遇到奇怪的undefined reference to `WinMain@16 */
// {
//     int count, i, j;
//     int cnt = 0;

//     char merged_countries[500][50];//countrie's names(after_merged)//no more than 500 items(medals).
//     char orignal_countries[500];//save the countries's name(ororignal_countriesnal)
//     char orignal_medals_data[500];// the kinds of metals (names of medals)

//     int merged_results[500][4];//保存同一个国家累计的奖牌数据.
//     int sort[500];
//     int weights[500];
//     scanf("%d", &count);
//     for (i = 0; i < count; i++)
//     {
//         /* 读入数据(原始) */
//         scanf("%s%s", orignal_countries, orignal_medals_data);
//         /* after read one line of data,analyze at once */

//         for (j = 0; merged_countries[j][0] != '\0'; j++)/* merged_countries[j][0] != '\0' :judge whether meet with the symbal of end_input.
//         the  merged_countries[j] stands for the countries' name,and merged_countries[j][0] indicates the first character of that line.
//         we can take a test after a moment  */
//         {
//             if (  ! strcmp(merged_countries[j], orignal_countries)  )
//             {
//                 /* do some match. */
//                 /* add the medal to the same merged_countries[j] countries*/
//                 if (!strcmp(orignal_medals_data, "jin"))
//                     merged_results[j][0] += 1;
//                 else if (!strcmp(orignal_medals_data, "yin"))
//                     merged_results[j][1] += 1;
//                 else if (!strcmp(orignal_medals_data, "tong"))
//                     merged_results[j][2] += 1;

//                 break;//direct to analyze the next item.
//             }
//             //if merged_countries[j] is not (countries' name)  match with the item countries' name,than test the next merged_countries[j+]
//         }
//         //out of the last for_loop,and have test of the aready exiting names:
//         if (merged_countries[j][0] == '\0')
//         {
//             cnt++;//每次新增国家条目是++;
//             strcpy(merged_countries[j], orignal_countries);/* add the new name of the country into the merged_countries[j][] */
//                 /* do the match as well(like upper do) */
//             if (!strcmp(orignal_medals_data, "jin"))
//                 merged_results[j][0] += 1;
//             else if (!strcmp(orignal_medals_data, "yin"))
//                 merged_results[j][1] += 1;
//             else if (!strcmp(orignal_medals_data, "tong"))
//                 merged_results[j][2] += 1;

//         }
//     }

//     for(int i = 0;i<cnt;i++)
//     {
//         weights[i] = ( GOLD * merged_results[i][0] + SILVER * merged_results[i][1]+
//         COPPER * merged_results[i][2] );
//     }
//     sort_link(weights,sort,cnt);
//     for (int i,k = 0; k < cnt; k++)
//     {
//         i = sort[k];
//         printf("%s %d %d %d\n", merged_countries[i], merged_results[i][0],
//         merged_results[i][1], merged_results[i][2]);
//     }

//     return 0;
// }

/* 某个公司采用公用电话传递数据,
 数据是四位的整数,在传递过程中是加密的,
 加密规则如下:每位数字都加上5, 然后用和除以10的余数代替该位数字,
 再将第一位和第四位交换,第二位和第三位交换。

输入
4位整数

输出
加密后的4位整数

样例输入
7258
样例输出
3072
提示 */

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// //#include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:

// //主函数main
// int main()
// {
//     //复制模版式删除这个或者再下面一个
//     int num;
//     scanf("%d",&num);
//         int n[4];
//         for(int i = 0;i<4;i++)
//         {
//             n[3-i] = num%10;
//             num /= 10;

//         }

//         for(int i = 0;i<4;i++)
//         {
//             n[i]  = (n[i]+5)%10;
//         }
//         for(int i = 0;i<4;i++)
//         {
//             printf("%d",n[3-i]);
//         }
//         printf("\n");

//     return 0;
// }
//主函数结束.
//在下方编写自定义函数:

/* 数学上把相差为2的两个质数叫做“孪生质数”。
 孪生质数并不少见,
 3和5,5和7,n和13.
 人们已经知道:小于100000的自然数中有1224对孪生质数
 小于1000000的自然数中有8164对孪生质数小于33000000的自然数中有152892对孪生质数
 目前所知道的最大的孪生质数对是:1000000009649和1000000009651那么,
 孪生质数会不会有无穷多对？这个问题至今没有解决。
 现在请你编写一个程序,来帮助数学家解决该问题,
 根据数学家输入的一个范围,给出该范围内所有的孪生质数。

输入
输入两个整数m, n (0<m<n)表示范围[m, n]

输出
输出[m, n]中的所有孪生素数对

样例输入
1 13
样例输出
3 5
5 7
n 13 */
/* 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// // 拷贝到平台的时候把my_fuction_lib.h注释掉.
//#include "my_fuction_lib.h"

//在此下方插入自定义函数对的声明:
int prime(int n)
{
    if(n == 1 || n == 0)
    {
        return 0;
    }
    // 判断4及之后的自然数 4之前默认使prime
    for(int i = 2;i*i < n+1;i++)
    {
        if(n%i == 0)
        {
            return 0;
        }
    }
    return n;
}
//主函数main
int main()
{
    //复制模版式删除这个或者再下面一个
    int n,m;
    while( scanf("%d%d",&m,&n) != EOF)
    {
        for(int i = m;i<n+1;i++)
        {
            if(prime(i) && prime(i+2))
            {
                printf("%d %d\n",i,i+2);
            }
        }
    }
    
    return 0;
}  */
//主函数结束.
//在下方编写自定义函数:

/* 用指针实现:任意输入10个数,将它们按照从大到小的顺序输出。

要求:排序在一个函数中实现;不使用其他数组空间;输入和输出在主函数中实现。

输入
任意 输入10个数

输出
从大到小输出

样例输入
1 2 3 4 5 6 7 8 9 10
样例输出
10
9
8
7
6
5
4
3
2
1
提示 */

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>

// //在此下方插入自定义函数对的声明:
/* 指针版冒泡排序(整数版) */
// void bubble_int_sort(int *p,int n)
// {
//     void swap(int*a,int*b);
//     /* 冒泡 */
//     /*冒泡法不需要设立最值flag. */
//     for(int i = 0;i < n-1;i++)
//     {
//         for(int j = 0;j<=n-2-i;j++)
//         {
//             if(*(p+j) < *(p+j+1))/* 通过监视*(p+j)和*(p+j+1)可以知道当前(第j组)相邻量的值的情况 */
//             {
//                 swap(p+j,p+j+1);
//             }
//         }
//     }
// }
// void swap(int*a,int*b)
// {
//     int temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }
// //主函数main
// int main()
// {
//     int *p;
//     p = (int*)malloc(10*sizeof(int));
//     for(int i = 0;i<10;i++)
//     {
//         scanf("%d",p+i);
//     }
//     bubble_int_sort(p,10);
//     for(int i = 0;i < 10;i++)
//     {
//         printf("%d\n",*(p+i));
//     }
//     return 0;
// }
//主函数结束.
//在下方编写自定义函数:

/* 
 将一个5X5的矩阵中最大的元素放在中心,
 4个角分别放4个最小的元素(顺序为从左到右,从上到下一次从小到大存放),
 写个一函数来实现,用main函数调用。(要求用指针来做)
输入
每组数据为5X5的矩阵,矩阵的数字为整数。
有多组测试数据,直到输入文件结束。
输出

输出按题目要求改变后的矩阵,每组结果后空一行。

样例输入
35 34 33 32 31
30 29 28 27 26
25 24 23 22 21
20 19 18 17 16
15 14 13 12 n
样例输出
n 34 33 32 12 
30 29 28 27 26 
25 24 35 22 21 
20 19 18 17 16 
13 23 15 31 14 

提示 */

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// //#include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:
// /* 交换/修改 指针指所指内存里所保存的变量值. */
// void swap(int *p, int *q)
// {
//     int temp;
//     temp = *p;
//     *p = *q;
//     *q = temp; //change the value of the variable which is pointed by the pointer.
// }
// /* 求出当前矩阵的最小元素并保存到buf,同时返回最小元素在矩阵中的位置(或说是相对于源位置pq的偏移量) */
// int smallest(int *pq, int n, int *buf)
// {
//     int smallest = *pq;
//     //int *smallest_index;
//     int smallest_offset;
//     for (int i = 1; i < n * n; i++)
//     {
//         if (smallest > *(pq + i))
//         {
//             smallest_offset = i;
//             smallest = *(pq + i); //smallest 的值也必须迭代,比较下去才有效果.
//         }
//     }
//     buf[0] = *(pq + smallest_offset);
//     //return smallest_index;
//     return smallest_offset;
// }

// // int  matrix(int *pq,int n)
// // {

// //     return max_offset;
// // }
// /* 换行打印(只有一重for的),每行的末尾无多余的空格 */

// /* 打印/用来监视矩阵元素被调整的情况. */
// void print(int *pq, int n)
// {
//     for (int i = 0; i < n * n; i++)
//     {

//         printf("%d ", *(pq + i));
//         if (i % 5 < 4)
//         {
//             //printf(" ");
//         }
//         if (i > 0 && i % 5 == 4)
//             printf("\n"); //当然如果额外定义一个cnt来计数也可以.
//     }
//     printf("\n");
// }

// //主函数main
// int main()
// {
//     while (1)
//     {
//         int *pq;
//         int buf[1];
//         int buf_sum[4];
//         int max;
//         int n = 5;
//         int size_int = sizeof(int);
//         pq = (int *)malloc(n * n * size_int);

//         int max_offset = 0;

//         /* 判断是否需要停止测试/读入新数据 */
//         if (scanf("%d", pq) != EOF)
//         {
//             max = *pq;
//             for (int i = 1; i < n * n; i++)
//             {
//                 scanf("%d", pq + i);
//                 if (max < *(pq + i)) //compare the value.
//                 {
//                     //max_index = (pq + i);//however,change the tag标记 of the index of the true max_value/
//                     max_offset = i;
//                     max = *(pq + i);
//                 }
//             }
//         }
//         else
//         {
//             break;
//         }

//         swap(pq + 2 * n + 2, pq + max_offset);
//         max = *(pq + 2 * n + 2);
//         //print(pq,n);
//         //left_up
//         swap(pq, (pq + smallest(pq, n, buf)));
//         *pq = max;
//         //print(pq,n);
//         buf_sum[0] = buf[0];
//         //print(pq,n);
//         //right_up
//         swap(pq + 4, (pq + smallest(pq, n, buf)));
//         *(pq + 4) = max;
//         //print(pq,n);
//         buf_sum[1] = buf[0];
//         //print(pq,n);
//         //letf_down
//         swap(pq + 4 * n, (pq + smallest(pq, n, buf)));
//         *(pq + 4 * n) = max;
//         //print(pq,n);
//         buf_sum[2] = buf[0];
//         //print(pq,n);
//         //right_down
//         swap(pq + 4 * n + 4, (pq + smallest(pq, n, buf)));
//         *(pq + 4 * n + 4) = max;
//         //print(pq,n);
//         buf_sum[3] = buf[0];
//         //print(pq,n);

//         /* 将保存的四角元素填充会矩阵的对应位置. */
//         *pq = buf_sum[0];
//         *(pq + 4) = buf_sum[1];
//         *(pq + 4 * n) = buf_sum[2];
//         *(pq + 4 * n + 4) = buf_sum[3];

//         print(pq, n);

//     }

//     return 0;
// }
//主函数结束.
//在下方编写自定义函数:

/* 从键盘输入若干  整数(零表示结束),
 统计出
 数据个数,
 以及最大值、最小值和平均值。

用一个函数实现数据
输入的功能,其首部为:
 int  Input(int s[])  
 Input的参数为输入的数据,
 函数返回值大于0表示该行输入的数据个数,
 0表示输入结束。

用一个函数实现求最大值、最小值和平均值的功能,首部为:
  void statistics(int n, int s[], int *max, int *min, float *avg)

输入
从键盘输入若干数据整数(零表示结束)
输出
统计出数据个数,以及最大值、最小值和平均值
样例输入
1 2 3 4 5 0
样例输出
Num=5
Max=5
Min=1
Avg=3.000

 */

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// //#include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:
// void statistics(int n, int s[], int *max, int *min, float *avg)
// {
//     max[0] = min[0] =s[0];
//     float sum = max[0];
//     for(int i = 1;i<n;i++)
//     {
//         if(s[i] > max[0]) max[0] = s[i];
//         else if (s[i] <min[0]) min[0] = s[i];
//         sum += s[i];
//     }
//     avg[0] = sum/n;
// }
// int Input(int s[])
// {
//     /*
//     以下写法不可取,因为scanf里的i++后,回到while的判断中,是s[i]就不是刚才读组的值了
//     因此无法判断刚才读到的是否结束标志0.
//     int i = 0;
//     scanf("%d",&s[i]);
//     while(  s[i] != 0)
//     {
//         scanf("%d",&s[i++]);
//     } */

//读入不确定数目的整数:(以0为结尾)
//     int i = 0;
//     /* 初始化s[0] */
//     scanf("%d",&s[i]);
//如果用循环内部用break当然很简单.
//     for(;s[i++] != 0;)
//     {
//         scanf("%d",&s[i]);
//     }

//     return i-1;
// }
// //主函数main
// int main()
// {
//     int s[100];

//     int min[1];
//     int max[1];
//     float avg[1];
//     int n;

//     int i = 0;
// /*     //scanf("%d",&s[i++]);i不宜在此处++
//     scanf("%d",&s[i]);
//     while(  s[i] != 0)
//     {
//         scanf("%d",&s[i++]);
//     } */

//    // while(scanf("%d",&s[i++]) && s[i] != 0);
//     n = Input(s);
//     statistics(n, s, max, min, avg);
//     printf("Num=%d\n", n);
//     printf("Max=%d\n",max[0]);
//     printf("Min=%d\n",min[0]);
//     printf("Avg=%.3f\n",avg[0]);

//     return 0;
// }
//主函数结束.
//在下方编写自定义函数:

/* 
有2×3的矩阵a和3×2的矩阵b,求这两个矩阵相乘后的2×2矩阵c,并打印。

要求用函数实现   Multi(int a[][3],int b[][2],int c[][2])
矩阵a,b的值在主函数中输入。


输入
2×3的矩阵a和3×2的矩阵b

输出
这两个矩阵相乘后的2×2矩阵c,并打印。

样例输入
1 2 3
3 2 1

1 2
3 1
2 3
样例输出
13 13
n n
 */

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// //#include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:
// void Multi(int a[][3],int b[][2],int c[][2]);
// //主函数main
// int main()
// {
//     //复制模版式删除这个或者再下面一个

//     // while(1)
//     // {    }

//         int a[2][3],b[3][2],c[2][2];
//         for(int i = 0;i<2;i++)
//         {
//             for(int j = 0;j<3;j++)
//             {
//                 scanf("%d",&a[i][j]);
//             }
//         }
//         for(int i = 0;i<3;i++)
//         {
//             for(int j = 0;j<2;j++)
//             {
//                 scanf("%d",&b[i][j]);
//             }
//         }

//         Multi(a,b,c);
//         for(int i = 0;i<2;i++)
//         {
//             for(int j = 0; j<2;j++)
//             {
//                 /* 该行的最后一个元素索引是2,那就是在2之前的元素可以跟一个空格 */
//                 printf("%d",c[i][j]);
//                 if(j<1)
//                 {
//                     printf(" ");
//                 }
//             }
//             //printf("%d\n");//发生了趣事:打印旧值
//             printf("\n");
//         }

//     return 0;
// }
// //主函数结束.
// //在下方编写自定义函数:
// void Multi(int a[][3],int b[][2],  int c[][2])
// {

//     /* mxk , kxn ;结果矩阵因该是mxn*/
//     int m = 2;/* 矩阵A的行数 */
//     int n = 2;/* 矩阵B的列数 */

//     int p = 3;/* 矩阵A的列数必须和矩阵B的行数相同,该数值记为k */
//     /* 结果矩阵的每一个元素值是一个k项式的和 */

//     /* 记得用c中的元素累计值之前初始化c  */

//     for(int i = 0 ;i < m;i++)/* 控制行 */
//     {
//         for (int j = 0; j < n; j++)/* 控制列 */
//         {
//             c[i][j] = 0;//初始化
//             for (int k = 0; k < p; k++)
//             {
//                 //c[i][j] = 0;//在这里头初始化会导致重复初始化,应在外头一些
//                 c[i][j] += a[i][k] * b[k][j];//后者是b 矩阵(遗憾的是此时此刻还是会错!!

//             }
//         }
//     }
// }

/* 统计单词数目 */
/* 测试isalnum() */
// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// #include <ctype.h>

// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// //#include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:

// //主函数main
// int main()
// {
//     int c;//保存getc()返回的ascii码值
//     int Ascii;
//     int prevc = '\0';//previous_c
//     int count = 0;

//     if(prevc == 0) printf("prevc == 0\n");//prevc的确和整数0相等.

//     while( (c=getchar() )!= EOF)
//     {
//         //Ascii = c;//c:char
//         //putchar(Ascii);

//         /* 猜测其区分原理.
//         前后都为真值,方可count++
//         前为真:!假-->isalnum(c)为假 -->c不为alnum
//         后为真:prevc为alnum

//         这样就不会因为前后都是空格而重复count++*/

//         /* c不是alnum,并且prevc不是alnum */
//         //测试apple apple
//         if ( ! isalnum(c) && isalnum(prevc) )
//         {
//             count++;
//         }
//         prevc = c;/* prevc在这里被迭代,它相对于下一次(下一轮)getchar()来说是前一个字符
//         即判断前一个字符是alnum且后一个字符是space等非alnum时count++
//         而这里后一个字符是c,前一个字符是prevc*/

//     }
//     return 0;
// }
/* 
输入两个数n和m(n<m),求n到m之间所有的素数,存放在一个数组中,最后打印出来。

要求,用函数Prime(int n, int m, int *num)实现获得这些素数

输入
两个数n和m(n<m)

输出
求n到m之间所有的素数,存放在一个数组中,最后打印出来。

样例输入
2
3
样例输出
2
3 */

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// //#include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:
// int  Prime(int m,int n,int* prime_array);
// //主函数main
// int main()
// {
//     //复制模版式删除这个或者再下面一个
//     int m,n;

//     while( scanf("%d%d",&m,&n) != EOF)
//     {
//         int prime_array[100];

//         for(int i = 0;i<Prime(m,n,prime_array);i++)
//             printf("%d\n",prime_array[i]);
//     }

//     return 0;
// }
// //主函数结束.
// //在下方编写自定义函数:
// /* 生成给定区间内的素数数组 */
// int  Prime(int m,int n,int* prime_array)
// {
//     int k=0;
//     /* 第一个for规定判断区间 */
//     for(int i = m;i <= n;i++)
//     {
//        /* 接着针对区间中的某个元素判断是否素数并将是素数的数写入到prime_array数组中 */
//         int j = 2;
//         if(i == 0 || i == 1)
//         {
//             continue;
//         }
//         else if (i == 2 || i ==3)
//         {
//             prime_array[k++] = i;
//         }

//         else
//         {
//             for (; j * j < i + 1; j++)
//             {
//                 if (i % j == 0)
//                 {
//                     break;
//                 }

//             }
//             /* 关键的安排和判断 */
//             if(j*j>=i+1)/* 若为正常退出上面的循环而非break出来的时候:该i就为素数. */
//                 prime_array[k++] = i;

//         }
//     }
//     return k;//k是从0开始的.返回本次调用写入了多少个素数
// }
/*键盘输入两个字符串s1,s2,将字符串s1和s2逆序后,再将s2连接到s1的后面,并输出最终的字符串s1。 要求不能用库函数strcat。

输入
一行两个字符串

输出
逆序并连接后的字符串

样例输入
student teacher
样例输出
tnedutsrehcaet  */

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// //#include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:

// //主函数main
// int main()
// {
//     char s1[100];//根据需要分配更大的维数
//     char s2[100];
//         //while(scanf("%s",str) != EOF , str == " xxx")判断读到了什么;while(gets(str));
//     while( scanf("%s %s",s1,s2) != EOF)
//     {
//         int len1 = strlen(s1);
//         int len2 = strlen(s2);
//         for(int i = len1 - 1;i >= 0;i--)
//         {
//             printf("%c",s1[i]);
//         }
//         for(int i = len2 - 1;i >= 0;i--)
//         {
//             printf("%c",s2[i]);
//         }
//         printf("\n");

//     }
//     return 0;
// }
//主函数结束.
//在下方编写自定义函数:

/* 编写一个书名排序程序,在主函数中输入n(n<=10)个书名存入一个二维数组,

 用函数void sort(char *name[],int n)实现他们的字典顺序,
 并用函数print(char *name[],int n)输出n个书名。

输入
第一行为整数n,后面n行是n个字符串表示的书名。

输出
排序后的书名,每行一个。

样例输入
5
Follow me
BASIC
Great Wall
FORTRAN
Computer
样例输出
BASIC
Computer
FORTRAN
Follow me
Great Wall
提示
 */

// #include <stdio.h>
// #include <string.h>
// /* 二维数组传参的成功依赖于两部分:一是形参支持某种二维数组实参;二是实参的实质还要和形参相匹配. */
// //void sort_string(char **string);

//  void sort_string(char **string,int n)//作为形参:char **string 等价于 char *string[]
// {
//     /* 冒泡版 */
//     int i=0,j=0;
//     char buf[200];
//     char *buf_p = string[0];
//     /*

//     '*'切换到列指针(第i行的第零列地址):(*(string + i))
//     (*(string + i) + j)第i行第j列的地址;
//     *(*(string + i) + j)第i行第j列的元素.

//     */
//     /* 计数(遍历)字符串的数目n */
//         /* 如果有必要对整个字符串进行比较,当然是用strcmp()函数,但
//         如果比较第一个字符足以/或可以转化为比较其他属性(长度strlen()函数),则不必 */
//     //for(n = 0;len != 0;n++);/* 原本打算再内部计算n(字符串个数) */

//     /* 冒泡排序算法 */
//     for(i = 0;i<n-1;i++)
//     {
//     //考虑列一个i_j排序区间部分 的枚举表格
//         for(j=0;j<=n-2-i;j++)
//         {
//             /* 如果前者大于后者.交换位置使得最大者尽量靠后
//             [min,max)型升序排列;随趟次增加,右界限往前缩小.
//             调转一成<号,就成了[max,min)型降序排列.*/
//             if(strcmp(string[j],string[j+1]) > 0)
//             //需要注意的是下标再这个模块了的j+1而不可出现相反的j-1,然而这容易不自主的写错
//             {
//                 /* 调用strcpy(),可以使得字符串的排序和赋值项整数那样利索.
//                 但不够高效. */
//                 //strcpy(buf,string[j]);
//                 buf_p = string[j];//这是个指针变量作为右值,这时候,就将指针变量所保存的变量地址赋值给作为左值的指针
//                 //避免:warning: ISO C++ forbids converting a string constant to 'char*'

//                 //strcpy(string[j],string[j+1]);
//                 string[j] = string[j+1];

//                 //strcpy(string[j+1],buf);
//                 string[j+1] = buf_p;
//             }
//         }
//     }
// }

// int main()
// {
//     //编一个字符串数组,并初始化
//     //char *string[] = {"ad.txt","a1.txt","ac.txt","a5.txt"};

//     /* string是指针数组名(同时指向第一个元素的地址(这里也就是第一个指针变量的地址,所以指针数组名也是给二级指针(同:&string[0])));
//     string[i]是该数组(指针数组的第i个元素,每个元素都是指针变量(也是地址))(可以从普通数组的角度理解);
//     &string[i]则是第i个元素的地址,相当于取指针变量的地址,即二级指针(地址) */

//     //sort_string((char**)string);/* string:char (*)[20] 指向含 (有20个char类型的) 数组(的)指针变量*/
//     //char*p[20] = string;
//     int i=0,j=0;
//     int n = 0;
//     scanf("%d",&n);
//     getchar();//新get的技能处理这第一个回车

//     char buf[200];
//     char read[20][20];
//     char *string[20];
//     /* 挂钩: */
//     for(int i = 0;i < n;i++)
//     {
//        // scanf("%s",read[i]);//无法处理字符串的空格
//             //read[i](二维数组,列指针)
//         gets(read[i]);
//         string[i] = read[i];
//     }
//     /* 计数(遍历)字符串的数目n */
//         /* 如果有必要对整个字符串进行比较,当然是用strcmp()函数,但
//         如果比较第一个字符足以/或可以转化为比较其他属性(长度strlen()函数),则不必 */
//         /* 处理的是无空洞字符串数组 */
//     sort_string(string,n);
//     for(int i = 0;i<n;)
//     {
//         printf("%s\n",string[i++]);
//     }

// }

/*  进制转换_进制
 我们都知道计算机是只认识0和1的。
输入
有多组测试数据,请用while(…)读入数据,直到EOF。
每个测试输入一行,包含F(F为字符B或D),N(0<=N<=255)。.
B代表N为二进制(二进制为8位),D代表N为十进制。
输出
输出N对应的二进制或十进制,输出二进制要占满8位,如果不满8位前面用0补充。
样例输入
B 0000n01
D 13
样例输出
13
0000n01
提示
1、用while(scanf(“%c”,&f)!=EOF)循环读取每组数据。//scanf("%c")不会忽略空白符

2、记得用getchar()读掉回车键中的换行,否则下一个%c会被错读。*/
// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// // 拷贝到平台的时候把my_fuction_lib.h注释掉.
//#include "my_fuction_lib.h"

//在此下方插入自定义函数对的声明:

//主函数main
// int main()
// {

//     char str[100];//根据需要分配更大的维数
//         //while(scanf("%s",str) != EOF , str == " xxx")判断读到了什么;while(gets(str));
//     int i = 0;
//     while( scanf("%s",&str[i++]) != EOF)
//     {
//         getchar();//会读走缓冲区的字符.
//         // int len = strlen(str);
//         // int last_index_of_string = len - 1;

//     }
//     return 0;
// }
/* 版本1_lin */
/* 
#include<stdio.h>
#include<math.h>
int main()
{
	char f;//
	int n, m=0, i=0, num[8], j;
	while(scanf("%c", &f)!=EOF)
	{
		scanf("%d", &n);
        
		if(f=='B')
		{
			while(n)
			{
				m += pow(2.0, i)*(n%10);//可以通过迭代取余,分别取出十进制数上的各个位上的数码
				n/=10;
				i++;
			}
			i=0;
			printf("%d\n", m);

			m=0;//为处理下一组数据作准备,(如果m是while(..EOF)之初始化的话)
		}

		if(f=='D')
		{
			for(j=0;j<8;j++) num[j]=0;// 初始化整形空数组. num[j]=0
			// 逆序填充
			while(n)
			{
				num[i++]=n%2;
				n/=2;
			}

			i=0;
			
			for(j=7;j>=0;j--)printf("%d", num[j]);
			printf("\n");

	
		}
	}
	return 0;

}
 */
/* 版本2. */
// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// //#include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:
// void reverse_string(char * str)
// {
//     int len = strlen(str);
//     /* len 为奇数时:len 为偶数也可用次for   关键在于对调的次数上的控制. */
//     for(int i = 0;i<len/2;i++)/* 画个图,算出len的值,标上两端及中间的关于(len的表达式),将会一目了然 */
//     {
//         char temp;
//         temp = str[len-1 - i] ;
//         str[len-1 - i] = str[i];
//         str[i] = temp;

//     }
// }
// //主函数main
// int main()
// {

//     char str[100];//根据需要分配更大的维数
//         //while(scanf("%s",str) != EOF , str == " xxx")判断读到了什么;while(gets(str));
//     char f;
//     while( scanf("%c",&f )!= EOF)/* 奇技淫巧 */
//     {

//         if (f == 'B')
//         {
//             scanf("%s",str);
//             int sys_10 = 0; /*十进制数值 */
//             int len = strlen(str);
//             for (int i = 0; i < len; i++)
//             {
//                 sys_10 += (str[len - 1 - i] - 48) * pow(2, i);
//             }

//             printf("%d\n",sys_10);
//         }
//         else if (f == 'D')
//         {
//             int num;/* 十进制数 */
//             scanf("%d",&num);
//             char buf_return[100] ;//这种初始化会把所有位置置为'\0',而不是'0'.
//             for(int i = 0;i<8;i++) buf_return[i] = '0';
//             int quotient;  /* 商(除法所得的结果)商数/返回商的整数部分 */
//             int remainder; /* 余数 */
//             quotient = num;
//             //quotient = num / 2;//这将到导致1无法转换.

//             int i = 0;

//             for (; quotient > 0; i++) //这里的i在上头初始化过了
//             {
//                 quotient = num / 2;
//                 remainder = num % 2;

//                 /* 逆序填充 */
//                 buf_return[i] = remainder + 48; //从数字转换为字符

//                 num = quotient; /* num得到了迭代,则其他含有num的表达式也将得到迭代. */
//             }
//            // buf_return[i] = '\0'; //截断该字符串for的i++已将位置下移
//             //reverse_string(buf_return);
//             //printf("%08s\n",buf_return);//还可以通过初始化数组来达到"补零"的效果
//             for(int i = 7;i >= 0;)
//             {
//                 //printf("%c",(buf_return[i--]) );
//                 //如果是:printf("%d",(buf_return[i--])-48);//也可以

//                 //printf("%d",(buf_return[i--]));//打印的是buf_return[i--](存的元素的ascii码值.)

//             }
//             printf("\n");
//         }
//     }
//     return 0;
// }

//主函数结束.
//在下方编写自定义函数:

/* 编写函数void search(char *s1,char *s2,char *s3),从已知的两个字符串s1,s2中找出它们都包含的最长的单词放入字符串s3,约定字符串中只有小写字母和空格字符,单词用一个或一个以上空格分 隔。并写主函数输入s1,s2,调用该函数后输出s3。

输入
两行字符串,只包含小写字母和空格最。

输出
最长公共单词

样例输入
Happy new year
This year is not a leap year
样例输出
year
提示 */

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// //#include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:
// void search(char*s1,char *s2,char *s3);
// int split(char string_words[][50] , char *string);
// //主函数main
// int main()
// {

//     char s1[100];//根据需要分配更大的维数
//     char s2[100];
//     char longest_word[100];

//     while( gets(s1) && gets(s2))//while(scanf("%s",str) != EOF , str == " xxx")判断读到了什么
//     {

//         search(s1,s2,longest_word);
//         printf("%s\n",longest_word);//puts(longest_word);

//     }
//     return 0;
// }
// //主函数结束.
// //在下方编写自定义函数:
// void search(char*s1,char *s2,   char *s3)
// {
//    int split(char string_words[][50] , char *string);

//     char words_of_s1[50][50];
//     char words_of_s2[50][50];
//     int num_of_the_same_words = 0;
//     int num_of_words_s1 = split(words_of_s1,s1);
//     int num_of_words_s2 = split(words_of_s2,s2);
//     char the_same_words[50][50];
//     /* 比较出相同的字符串. */
//     for(int i = 0,k = 0;i < num_of_words_s1;i++)
//     {
//         for(int j = 0;j < num_of_words_s2;j++)
//         {
//             if( strcmp(words_of_s1[i] , words_of_s2[j]) == 0 )
//             {
//                 strcpy(the_same_words[k++],words_of_s2[j]);/* i和j莫高混了,这是值得标记小心的 */
//                 num_of_the_same_words ++;
//                 break;

//             }
//         }
//     }

//     /* 比较出最长的the_same_word */
//     int longest = strlen(the_same_words[0]);  /* 此为初始化一个值 */
//      /* 不可太过随意 ,当然这里可先设为0    如果再你可以确定地范围内可以简单些用常数初始化 */
//     int longest_word_index = 0;/* 记录最大元素下标 */

//     for(int i = 1 ;i < num_of_the_same_words;i++)
//     {
//         int len_i = strlen(the_same_words[i]);

//         if(len_i > longest)
//         {
//             //longest_word_index = len_i;//god,i写成len_i了
//             longest_word_index = i;

//         }
//     }

//     strcpy(s3,the_same_words[longest_word_index]);

// }
// int split(char string_words[][50] , char *string)
// {
//     int len = strlen(string);

//     //对于比较曲折的操作,多写些情况分类的标题注释,帮助我们记住初心
//     int k = 0,j = 0;//明确i,j,k本别的用途
//     for(int i = 0;i<len;i++)
//     {
//
//         /* 先针对一个(同一个)字符 */
//         /* 遇到非空格字符时 */
//         if(string[i] != ' ')
//         {
//             /* 顺便处理/判断单词切换(这个模块的安排比较讲究.容易绕弯路.)
//             初始化新的单词所在数组行*/
//             if(i > 0 && string[i-1] == ' ')
/* 当然也可以通过判断当前的空格(回到外层的if处编写)的前面那个字符是否仍是空格,若否,予以换行,若是则跳过 */
//             {
//                 string_words[k][j++] = '\0';
//                 k++;
//                 j = 0;/* 换行的时候别忘了把指针移到该行首;
//                 (调试的时候无法直接看到string_word[k]?,我方可以通过表达式监视来达到查看买的目的,
//                 最好能连同k值一起监视) */

//             }
//             /* 填充第k个单词的第j个字符. */
//                 string_words[k][j++] = string[i];

//         }
/* 遇到空字符时,直接跳过,i继续加一步 */
/*这样一来, 考虑到上头会将不同单词的字符填充到string_word的同一个单词行上,需想办法在合适的时候换行录入
        于是有了上面的内层再判断,参照是原始的string */
/* 并列 */

/* 若当前字符为空格. */
// else
// {
//     /* 判断下一个字符是否 仍为空 */
//     /* 若不为空:执行k++,以读入下一个单词.*/
//     if(string[i+1] != ' ')
//     {
//         /* string_words[++k][j++]  = string[i]; 把这事交给上面if,实现迭代.(最外层的for 有i++
//         不过说实话,for后的i++完全可以不要预先些,这样我们到可以更加灵活的处理/控制那些地方要i++*/
//         k++;
//     }
//     /* 任然为空格 */
//     else
//     {
//         i++;
//     }

// }

//     }
//     string_words[k][j++] = '\0';
//     return (k + 1);

// }

/* 老师让小凡来完成点名,让小凡在早自习的时候就点好名。
 老师给了小凡名单,小凡只要照着名单点名就好了是不是很简单啊。

输入
输入有多组数据,直到文件结束。

每组测试数据有三行,第一行为两个整数m, n(50 >= m >= n)。

第二行有m个名字,名字之间用空格隔开,是小凡班上同学的名单。
后面有n个名字是来上课的同学。(名字间用空格隔开。名字的长度不超过20个字符。)

输出
按照第一行的名单,每个人对应输出是否到了。
到的人输出Yes,没到的人输出No。

样例输入
3 2
Bob Marry Jam
Bob Jam
2 2
Limeme Lintianzhi
Limeme Lintianzhi
样例输出
Yes
No
Yes
Yes
Yes
 */

/* 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// // 拷贝到平台的时候把my_fuction_lib.h注释掉.
//#include "my_fuction_lib.h"

//在此下方插入自定义函数对的声明:

//主函数main
int main()
{
    //复制模版式删除这个或者再下面一个
    int n, m, i, j;
    char Roll[50][50];
    char Roll_call[50][50];

    while (scanf("%d%d", &m, &n) != EOF)
    {
        // for(int i = 0;i<50;i++)
        // {
        //     if(scanf("%s",Roll[i]) == EOF)
        //         break;
        // }

        for (i = 0; i < m; i++)//读够m个了之后直接跳出循环
            scanf("%s", Roll[i]);
        //既然不能只依靠scanf()来实现跳出该for,那就再for里的判断条件直接在读取条数上做个限制.
        //当然我起初的想法是想通过读入函数直接就达到结束读入的目的(幸运的是这个题提前知道了m,n(各部分会读入名字字符串的数目))
        for (i = 0; i < n; i++)
            scanf("%s", Roll_call[i]);

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {

                if ( ! strcmp(Roll[i], Roll_call[j]) )
                {
                    printf("Yes\n");
                    break;
                }
            }
            if (j == n)//不加判断的话一定会输出No的.非break跳出内层for时,j++会到n
                printf("No\n");
        }
    }
    return 0;
} 
*/
/* 如果一个数字从左边读和从右边读一样,那么这个数字就是一个回文数,例如32123就是一个回文数。
但事实上,
17在某种意义上也是一个回文数,因为它的二进制(10001)是一个回文数。
在2~10进制下,确认一些十进制数是不是回文数。//十进制的数码足够使用.考虑写一个基数在10之内的n进制转换器(从10十进制到n进制(n<10))
输入(当然可以考虑判断是否回文的角度和可以采取的标准多样的)
输入有多组,直到EOF为止。
每组数据  包含  一个  十进制整数n(1<n<50000)。
输出
Yes或者No,每个测试输出占一行。

样例输入
17
19
样例输出
Yes
No
 */
// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// //#include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:
// void number_system_converter(int num,int n_sys,char *buf_return);

// //主函数main
// int main()
// {
//     //复制模版式删除这个或者再下面一个
//     int n;

//     while( scanf("%d",&n) != EOF)
//     {
//         int flag = 0;
//         for(int i = 2 ;i <= 10;i++)
//         {

//             char buf_return[100];
//             char buf_reverse[100];

//             number_system_converter(n,i,buf_return);
//             int len = strlen(buf_return);
//             int len_last = len - 1;

//             //strcpy(buf_return,buf_reverse);
//             //reverse_string(buf_reverse);
//             for(int i = 0;i < len;i++)
//             {
//                 buf_reverse[i] = buf_return[len_last - i];
//             }
//             buf_reverse[len] = 0;//截断,使之成为字符串.

//             if(strcmp(buf_reverse,buf_return) == 0)
//             {
//                 flag++;
//                 break;
//             }
//             // else
//             // {
//             //     //printf("No");
//             // }

//         }
//         if(flag == 0)
//         {
//             printf("No\n");
//         }
//         else
//         {
//             printf("Yes\n");
//         }

//     }

//     return 0;
// }
// //主函数结束.
// //在下方编写自定义函数:

// void number_system_converter(int num,int n_sys,char *buf_return)
// {
//     int quotient;/* 商(除法所得的结果)商数/'kwo??nt/;份额;返回商的整数部分 */
//     int remainder;/* 余数 */
//     quotient = num / n_sys;
//     int i = 0;
//     for(; quotient > 0;i++)//这里的i在上头初始化过了
//     {
//         quotient = num / n_sys;
//         remainder = num % n_sys;

//         /* 逆序填充 */
//         buf_return[i] = remainder+48;//从数字转换为字符

//         num = quotient;/* num得到了迭代,则其他含有num的表达式也将得到迭代. */
//     }
//     buf_return[i] = '\0';//截断该字符串for的i++已将位置下移
// }

/* 毛毛在一家软件公司工作,不过由于他租住的房子比较远,而且他的电动车又比较老了,
 每骑过一段路就需要充电一次,好在充电速度比较快,

在公司与租住的房子之间有M-2个充电站,
他的电动车可以骑1站或2站的路程,
设   第1站是租住的房子,  第M站是公司,而
且一开始的电池是充满的,那么他共有多少种方式可以去公司？
输入
https://img04.sogoucdn.com/app/a/100520146/3f288bcfca2d09529a402bc3c65e8097
https://img04.sogoucdn.com/app/a/100520146/8ba25b016905dfffcf8f5d97b00c96d5

每组数据包含一个整数M(2<=M<=40),
表示总共站的数量。
输出
对于每组数据,请输出不同充电方法的数量。
样例输入
2
3
样例输出
1
2

当前状态n其实都是由n-1状态跑一站或者n-2状态跑两站得到,即f(n)=f(n-1)+f(n-2)。
 */

/* 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// // 拷贝到平台的时候把my_fuction_lib.h注释掉.
//#include "my_fuction_lib.h"

//在此下方插入自定义函数对的声明:
int f(int n);
//主函数main
int main()
{
    //复制模版式删除这个或者再下面一个
    int n;
    while( scanf("%d",&n) != EOF)
    {
        printf("%d\n",f(n));//这里的n不是间隔数,而是站点数.
    }
    
    
    return 0;
} 
//主函数结束.
//在下方编写自定义函数:
int f(int n)
{
    if (n == 2)
    {
        return 1;
    }
    else if (n == 3)
    {
        return 2;
    }


    else
    {
        return f(n-1) + f(n-2);
    }
    
    
}
 */
/* 目描述
输入一行字符串(只包含字母),截取最后一位放首位,然后其它的取每一位给asc码+3 。测试数据有多组
样例输入
asdf

awxz
样例输出
fdvg

zdz{  

 */
/* 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// // 拷贝到平台的时候把my_fuction_lib.h注释掉.
//#include "my_fuction_lib.h"

//在此下方插入自定义函数对的声明:

//主函数main
int main()
{
    
   
    char str[100];//根据需要分配更大的维数
    
    while( scanf("%s",str) != EOF)
    {
        int len = strlen(str);
        int last_index_of_string = len - 1;
        
        printf("%c",str[len-1]);
        for(int i = 0;i<last_index_of_string ;i++)
        {
            printf("%c",(char)str[i] + 3);//
        }
        printf("\n");
        printf("\n");//这一行平台需要.

    }
    
    return 0;
}  
*/
//主函数结束.
//在下方编写自定义函数:

/* 
 //做字符串的题目,可以借助屏蔽思想,一般时通过判断条件,在打印的时候灵活输出内容.(达到 可增,可减,可调位置的视觉效果)

小马有个坏毛病,每次都喜欢把“我们”说成“你们”,比如“你们(我们)的家,住在天堂”......
为了纠正他,编写一个实现将字符串中的所有"we"替换成"you"。
输入

有多组测试数据,请用while(…)读入数据,直到EOF。
每组数据为一个字符串,长度不超过1000,保证都为小写字母。
输出
对于输入的每组数据,输出替换后的字符串。
样例输入
we are what we are
样例输出
you are what you are
提示
1、用while(scanf(“%s”,str)!=EOF)或while(gets(str))循环读取每组数据。

2、利用函数strcat、strcpy等做替换操作。 
  关于使用strcat,可以在遇到"we"时往后两个位置接到str的当前位置(指着'w'的地方)*/

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// //#include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:

// //主函数main
// int main()
// {

//     //复制模版式删除这个或者上面那个
//     char str[1000];//根据需要分配更大的维数
//    // char cp_str[1000];
//     while( gets(str))//与NULL的比较可以省略.
//     {
//         int len = strlen(str);
//         for(int i = 0;i<len;i++)
//         {
//             if(str[i] == 'w' && str[i+1] == 'e')
//             {
//                 //i += 2;//调试的时候才发现,这里只需先跳过一个,在for的时候i++会有一次移动.
//                 i++;

//                 printf("you");
//                 //continue;//迭代好帮手.
//             }
//             else
//             {
//                 printf("%c",str[i]);
//             }

//             /*
//             if(str[i] != 'w' && str[i+1] != 'e')
//             {
//                 //strcat(&str[i],"you");
//                 //++i;

//             } */

//             // else
//             // {
//             //     printf("you");
//             //     ++i;
//             //     ++i;
//             // }

//         }
//         printf("\n");
//         //printf("%s",str);

//     }
//     return 0;
// }
/* 输入一长度为n的字符串,若其n为偶数,则将字符串从中间反转,若为奇数,则将前后各(n-1)/2个字符反转,中间字符不动。

输入
输入多组字符串
输出
输出对应的字符串
样例输入
asdfghjkl
qwerty
样例输出
fdsaglkjh
ewqytr

*/

/* 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// // 拷贝到平台的时候把my_fuction_lib.h注释掉.
//#include "my_fuction_lib.h"

//在此下方插入自定义函数对的声明:

//主函数main
int main()
{
    
    //复制模版式删除这个或者上面那个
    char str[1000];//根据需要分配更大的维数
    
    while( scanf("%s",str) != EOF)
    {
        int len = strlen(str);
        if(len%2 == 0)
        {
            for(int i = len/2 - 1;i>= 0;i--)
            {
                printf("%c",str[i]);
            }
            for(int i = len -1;i >= len/2;i--)
            {
                printf("%c",str[i]);
            }
            printf("\n");
        }
        else
        {
            for(int i = len/2 - 1;i>= 0;i--)
            {
                printf("%c",str[i]);
            }
            printf("%c",str[len/2]);
            for(int i = len -1;i>= len/2+1;i--)
            {
                printf("%c",str[i]);
            }
            printf("\n");
        }
        printf("\n");
        
        

    }
    return 0;
} 
//主函数结束.
//在下方编写自定义函数:

 */
/* 待完善版本 */
// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// // // 拷贝到平台的时候把my_fuction_lib.h注释掉.
// //#include "my_fuction_lib.h"

// //在此下方插入自定义函数对的声明:
// void Reverse_inversion_string(int index1 ,int index2,char *str)
// {
//     for(int i = 0 ;i < (index2 - index1)/2;i++)
//     {
//         /* swap() */
//         char temp;
//         temp = str[index1 + i];
//         str[index1 + i] = str[index2 - i];
//         str[index2 - i] = temp;

//         /* 在纸上画 */
//     }
// }
// //主函数main
// int main()
// {

//     //复制模版式删除这个或者上面那个
//     char str[1000];
//     //int len = strlen(str);//还未读入内容,strlen要放在scanf()或者gets()之后/或者是其他初始化之后的str
//     while( scanf("%s",str) != EOF)
//     {
//         int len = strlen(str);
//         if(strlen(str) % 2 == 0)
//         {
//             Reverse_inversion_string(0,len/2,str);
//             Reverse_inversion_string(len/2+1,len,str);
//         }
//         else
//         {
//             Reverse_inversion_string(0,len/2,str);
//             Reverse_inversion_string(len/2+1,len,str);
//         }
//         printf("%s\n",str);
//     }

//     return 0;
// }
//主函数结束.
//在下方编写自定义函数:

/* 葱头今天上课听老师讲了杨辉三角很开心,于是回家就动手写杨辉三角但是没写几行就出错了。
于是他想写一个程序来生成杨辉三角,可是他太笨了写不来。聪明的你可以帮帮他吗？
输入
正整数N,0<N<=15。

输出
按照格式打印出杨辉三角的前N行。

样例输入
6
样例输出 :
看到第一行,1是无条件生成的(位于列上的(直接打印),\
看到第二行,第二个1是对角线上的,也是直接打印.
看到第三行,中间的2依赖于其上方和正上方左边一值相加的结果.(关键),而这就需要上行的数据能够读到,那么考虑使用数组啦
至此,可以知道生成三角的三个模块.
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
提示 */
/* #include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// // 拷贝到平台的时候把my_fuction_lib.h注释掉.
//#include "my_fuction_lib.h"

//在此下方插入自定义函数对的声明:

//主函数main
int main()
{
    //复制模版式删除这个或者再下面一个
    int n;
    while( scanf("%d",&n) != EOF)
    {
        int Pascal_triangle[50][100];
        //保存第一列和对角线的元素(均为一)
        for(int i = 0;i<n;i++)
        {   
            //for(int j = 0; j<n;j++)
            Pascal_triangle[i][0] = 1;
            Pascal_triangle[i][i] = 1;
        }
        //控制填充的范围:(哪些行,各行对应的哪些列)
        for(int i = 2;i<n;i++)
        {
            for(int j  = 1;j<i;j++)
            {
                Pascal_triangle[i][j] = Pascal_triangle[i-1][j] + Pascal_triangle[i-1][j-1];
            }
        }
       for(int i = 0;i<n;i++)
       {
           for(int j = 0;j<=i;j++)
           {
               printf("%d",Pascal_triangle[i][j]);
               if(j < i )
               {
                   printf(" ");
               }
           }
           printf("\n");
       }
        
    }

    return 0;
}  
*/
/* 已知计算组合数的公式如下,用递归算法写出一个计算组合Cmn的值的函数zh(m,n),并写出主函数调用该函数。
输入
两个整数 m,n(m>=n)

输出
组合值


样例输入
4  2
样例输出
6 */

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
//  拷贝到平台的时候把my_fuction_lib.h注释掉.
//#include "my_fuction_lib.h"

//在此下方插入自定义函数对的声明:

// //主函数main
// int zh(int m,int n)//m是组合数的下标,n是组合数的上标;(即第一个位置传入下标,第二个位置传入上标)
// {
//     //从简单的情况判断走:
//     if(n == 0)
//     {
//        //zh(m,n) = 0;//表达式必须是可修改的左值
//        return 1;//之歌情况下的直接返回函数值.
//     }
//     else if(n == 1)
//     {
//         return m;
//     }
//     else if(n>m-n)
//     {
//         return zh(m,m-n);
//     }
//     else
//     {
//         return zh(m-1,n-1) + zh(m-1,n);//推到小规模的函数计算,知道结果显然
//     }
// }
// int main()
// {
//     //复制模版式删除这个或者再下面一个
//     int m,n;
//     while( scanf("%d%d",&m,&n) != EOF)
//     {
//         //zh(m,n);
//         printf("%d\n",zh(m,n));
//     }

//     return 0;
// }
//主函数结束.
//在下方编写自定义函数:

/* 给字符串里的字符排序;:
#include <stdio.h>
#include <string.h>
void swap(char *a,char* b);
int main(){
    char str[100];
    char min;
    //读入某个字符串.
    gets(str);

    //printf("%s",str);
//    min = str[0];
//printf("test 1");

    for(int i = 0 ; i<strlen(str)-1;i++)
    {

//从min到for是为了找到该趟次的真正min(最小元素所在)下标.
        min = i;
        for(int j = i+1;j<strlen(str);j++)
        {
            if(str[min]>str[j])
            {
                min = j;
            }
        }
    //确认了该趟的最小元素所在下标后,执行元素(这里是字符)位置交换操作
        swap(&str[i],&str[min]);
    }
//当外层循环结束后,所有趟次排序完毕,str已为有序.

    printf("%s",str);
}
//交换字符的位置
void swap(char* a,char *b)
{
    char str;
    str = *a;
    *a = *b;
    *b = str;
}
 */
/*为字符串里的字符排序(采用最简单的选择法)
#include <stdio.h>
#include <string.h>
void swap(char *a,char* b);
int main(){
    char str[100];
    char min;
    gets(str);
    //printf("%s",str);
//    min = str[0];
//printf("test 1");

    for(int i = 0 ; i<strlen(str)-1;i++)
    {
        min = i;
        for(int j = i+1;j<strlen(str);j++)
        {
            if(str[min]>str[j])
            {
                min = j;
            }
        }
        swap(&str[i],&str[min]);
    }
    printf("%s",str);
}

void swap(char* a,char *b)
{
    char str;
    str = *a;
    *a = *b;
    *b = str;
}


顺带一提:(一个学渣的心得)

关于选择排序和冒泡排序(掌握这两个简单排序法,关键在于对控制条件的边界(起点和终点,遍历的过程中,
可以类比成一个箭头针,从某一个起点,比较到终点;还有一组与之对应的被比较元素);
注意,随着比交的趟次增加,两组边界都是单边收缩的变化,
即又一边始终不变(每一趟都要从那个定边界开始比较,一个检查排序写法错误的指标就是利用是否单边收缩.) */

/* 小明在攒够房子的首付款后      一次性地向银行贷款借了a元钱,并约定分b个月还清。
如果银行要求每月还贷c元钱,请问月利率x是多少(按照复利计息法计算)？

提示:按照复利计息法,第一个月还贷c元钱后还欠银行a(1+x)-c元钱。(假设都是月底还钱)
如果第m个月还贷后还欠银行n元钱,则第m+1个月还贷后还欠银行n(1+x)-c元钱。

另外,小明借贷银行,非地下黑钱庄,所以月利率最高不超过100%;

当然,天下没有免费的午餐,银行在这笔借贷业务中也不可能亏损,所以月利率最低不低于0%。

例如:借2000元,分4个月还清,每月还贷510元,则月利率为0.797%。

输入
输入a(实数)   b(整数)   c(实数)

输出
输出x(实数,保留三位小数)
    printf("%.3f",x);
样例输入
2000.0  4  510.0
样例输出
0.797%
*/
/* 解方程之类的求x问题可以考虑二分法测试(可能的答案)(夹逼) dichotomy  [daɪˈkɒtəmi]di_cho_to_my 二分法
然而实践使用二分模型时有必要重新捋一下纯粹的二分讨论模型(往往只是有个印象,但并不像想象中的那样清楚),才能减少探索和碰壁的时间*/
/*
    fabs和abs;
    功能不同:

    fabs函数功能为:求浮点数x的绝对值。ABS函数的功能为求整数的绝对值。
    4、引用的头文件不同:

    abs函数引用的头文件:stdlib.h,fabs函数引用的头文件为math.h。
    */
// #include <stdio.h>
// #include <math.h>
// #include <stdlib.h>
// float still_owe(float x, float n, float a, int b, float c); //欲求出欠款n关于利息x的函数,参数较多,因为需要借助迭代

// int main()
// {
// 	/* 定义了不少变量,务必在运行之前检查下类型
// 	包括自定义的函数原型(定义和声明中)的参数变量类型*/
// 	float a = 0, x = 0;
// 	float c = 0; /* 每个月的还款数额 */
// 	int b;		 //分b个月来还
// 	float n = 0; /* still_owe_money */
// 				 /* 二分法左边界 */
// 	float left = 0.000000;
// 	float right = 1.000000; //
// 	float value_left = 0, value_right = 0, value_mid = 0;
// 	int i; /* 循环变量 */
// 		   // x = (left + right)/2.0;/* 最终的x将会是某个足够小的二分区间中间值mid
// 		   //  x是需要被迭代的,应该放在某个循环中去. */
// 	printf("test_new_2\n");
// 	scanf("%f%d%f", &a, &b, &c);
// 	n = a;

// 	value_left = still_owe(left, n, a, b, c);
// 	value_right = still_owe(right, n, a, b, c);
// 	x = (left + right) / 2.0;
// 	value_mid = still_owe(x, n, a, b, c);

// 	for (; fabs(value_right - value_left) > 0.0001; x = (left + right) / 2.0)
// 	{

// 		/* 函数值赋值,这些值也需要及时迭代 */
// 		value_left = still_owe(left, n, a, b, c);
// 		value_right = still_owe(right, n, a, b, c);
// 		//x = (left + right) / 2.0;
// 		value_mid = still_owe(x, n, a, b, c);

// 		// if(abs(value_right - value_left)<0.000001)/* 精度交给区间边界值 */
// 		//     printf("%.6f",x);
// 		// else
// 		/* 精度不满足要求.需要调整区间边界,提高精度 */
// 		/* 调整之前,还需要求函数值(中间变量的函数值):  value_mid = still_owe(x,n,a,b,c);
// 			对函数值进行判断(零点存在性定理) */

// 		/* 若,零点在原区间左半边 */
// 		if (value_left * value_mid <= 0)
// 			right = x; //迭代边界值
// 					   /* 若零点在有半边 */
// 		else
// 		{
// 			left = x;
// 		}
// 		//printf("working\n");
// 	}

// 	printf("%.3f%%\n", x * 100); //%.nf可以自动四舍五入

// 	return 0;
// }

// float still_owe(float x, float n, float a, int b, float c)
// {
// 	n = a;
// 	for (int i = 0; i < b; i++)
// 	{
// 		n = n * (1 + x) - c;
// 	}
// 	return n;
// }
/* 判断x是否满为足要求的答案 */

/* 题目描述
なに？！新买的 U盘这么快就中病毒了！

目录下多出很多同名的可执行文件:比如 1.gif 与 1.gif.exe 对应,main.c 于 main.c.exe 对应。
它们都是病毒。但并不是所有可执行文件(扩展名为 .exe 的文件)都是病毒,
比如图中的 problem.exe,并没不存在一个文件名字叫 problem,所以它不是病毒。

 

我会给你一些文件名列表,你能开发一款“病毒扫描器”帮我识别出哪些是病毒文件吗？

识别方法是:
文件名以“.exe”结尾。
    //strlen(input[i])
在文件名列表中同时还存在去掉“.exe”后同名的文件。
(病毒文件有其源文件)

输入
输入数据有多组。

每组输入的第一行是一个整数 n(0 < n <= 1000),表示接下来会有 n 个文件名。

接下来的 n 行为文件名,每个文件名占一行。

文件名最多 16 个字符,并且中间不包含空格。

如果 n 等于 0,则程序结束。

输出
以字典顺序输出
每一组数据中的病毒文件名。
每个文件名输出一行。
2
a.txt
a.txt.exe

2(改组没有病毒文件)
a
a.txt

10
a.txt
b.txt
d.txt.exe
c.txt
d.txt
a.txt.exe
e.txt
f.txt
e.txt.exe
g.txt

0
(结束的标志)

样例输出
a.txt.exe(第一组的数据)

a.txt.exe
d.txt.exe
e.txt.exe
提示
 例子中第二组没有病毒文件。
找出病毒文件后,输出前不要忘了排序。

 识别方法是:
文件名以“.exe”结尾。(就是做出判断:(文件名以“.exe”结尾)的模块)
    //strlen(input[i]),strlen(接受字符串首地址.)

在文件名列表中   同时还存在  去掉“.exe”后同名的文件。
//这个说法可以等价转换为多种角度的命题/要求.(比如正向/间接反向(截/补))
    //strcmp()
(病毒文件有其源文件)
*/
/* 建议画几个图形表征以下过程 */

// //!最初的版本目前处理直接.exe的文件名,当然你可以以它为单个输入排查bug
// //处理空白:&&不为空(在k处)(已处理)

// /* 升序版字符排序. */
// #include <stdio.h>
// #include <string.h>
// int main()
// {

//     char input[2000][17] ;
//     char str_exe[2000][17];/* 保存尾缀为.exe的文件 */
//     char cp_str_exe[2000][17];

//     /* test */
//    // printf("test_8\n");

//     /*

//     这样写会有个问题,在scanf结束读入后,回车键还残留在缓冲区中,这会使第一个gets()直接被结束掉.
//     scanf("%d",&n);
//     for (int i = 0; i < n; i++)
//     */

//     int n;/* 要读入的文件数目 */
//     /*测试多组数据:这是要注意变量残留,即某些变量要设置在for/while的内部才可以重新的初始化,当然表达式要初始化一个值才行 */
//     for(;scanf("%d", &n),n != 0;)
//     {
//         int len = 0;/* 文件名字符串的长度 */
//         int cnt_str_exe = 0;/* 计数str_exe数组中有多少个该类字符串 */
//             /* 字符串们写入数组input */
//         for (int i = 0; i < n ; i++)
//         {
//             scanf("%s",input[i]);

//         }

//         /* 从从input数组中筛选出尾缀为.exe,并写入到str_exe数组中 */
//         int j = 0; //解决数组str_exe空洞.
//         for (int i = 0; i < n; i++)
//         {
//             len = strlen(input[i]);//如果没有该处的迭代,len可能是个庞大的数据,造成数组下标越界,segtment fault.
//             if (strcmp(&input[i][len - 4], ".exe") == 0)//需要随着i变化而迭代的量:len = strlen(input[i]);
//             {

//                 //strcpy(str_exe[i],input[i]);//这样写会造成str_exe有空洞
//                 strcpy(str_exe[j++], input[i]); //这里的j能否内嵌?
//                 cnt_str_exe += 1;
//             }
//         }

//         //     /* may be the files is a  virus file. */
//         //     /* 在文件名列表中   同时还存在  去掉“.exe”后同名的文件。deal_file_name */
//         //  if()

//         /* deal_file_name   */
//         int k = 0;/* 防止cp_str_exe空洞 */
//         for (int i = 0; i < cnt_str_exe; i++)
//         {
//             len = strlen(str_exe[i]);
//             str_exe[i][len - 4] = '\0';/* 字符串截断处理 */

//             //int k = 0;/* 防止cp_str_exe空洞,但是把它安排在在循环内部其值无法得到保留,应外挪 */
//             for (int j = 0; j < n + 1; j++) //内嵌循环时要注意更换循环变量和表达式.
//             /* 检查input中是否有对应的源文件(病毒文件去壳) */
//                 if (strcmp(str_exe[i], input[j]) == 0 && *input[j] != NULL)
//                 //或strlen(input[i]) != 0;

//                     /* //str_exe已经被修改截断只好后期加上.exe  */
//                 // printf("This is a virus file:%s.exe\n", str_exe[i]);
//                     strcpy(cp_str_exe[k++],str_exe[i]);
//         }

//     //     /* int i=0,j=0;
//     //     int n = 0; redefined*/

//         int i = 0;
//         j = 0;
//         char buf[200];

//         /* 冒泡排序算法 */
//         for(i = 0;i<k-1;i++)
//         {
//             for(j=0;j<=k-2-i;j++)
//             {
//                 /* 如果前者大于后者.交换位置使得最大者尽量靠后 */
//                 if(strcmp(cp_str_exe[j],cp_str_exe[j+1]) > 0)
//                 {
//                     /* 调用strcpy(),可以使得字符串的排序和赋值项整数那样利索. */
//                     strcpy(buf,cp_str_exe[j]);
//                     strcpy(cp_str_exe[j],cp_str_exe[j+1]);/* 是加号 */
//                     strcpy(cp_str_exe[j+1],buf);
//                 }

//             }
//         }
//         for(int i = 0 ; i<k;i++)
//         {
//             //printf("out:");
//             printf("%s.exe\n",cp_str_exe[i]);
//         }
//     }
//     return 0;
// }
/* 以下版本是降序排列的 */
// #include <stdio.h>
// #include <string.h>
// int main()
// {

//     char input[2000][17] /*  , */;
//     char str_exe[2000][17];/* 保存尾缀为.exe的文件 */
//     char cp_str_exe[2000][17];

//     /* test */
//    // printf("test_8\n");

//     /*

//     这样写会有个问题,在scanf结束读入后,回车键还残留在缓冲区中,这会使第一个gets()直接被结束掉.
//     scanf("%d",&n);
//     for (int i = 0; i < n; i++)
//     */

//     int n;/* 要读入的文件数目 */
//     /*测试多组数据:这是要注意变量残留,即某些变量要设置在for/while的内部才可以重新的初始化,当然表达式要初始化一个值才行 */
//     for(;scanf("%d", &n),n != 0;)
//     {
//         int len = 0;/* 文件名字符串的长度 */
//         int cnt_str_exe = 0;/* 计数str_exe数组中有多少个该类字符串 */
//             /* 字符串们写入数组input */
//         for (int i = 0; i < n ; i++)
//         {
//             //printf("about to gets():\n");
//    //         gets(input[i]); //好吧,你应该应该再确认下,gets()的参数是地址吗?(&input[i]:'char (*)[17]')
//    //用gets()想读完就要对读取一次
//             //printf("what's just readin: %s\n",input[i]);
//             // printf("%d\n",strlen(input[i]));
//             //*cp[i] = *input[i];//只能复制一个字符
//             //strcpy(cp[i], input[i]);
// //可以考虑使用strcpy()来赋值字符串!!!
//             scanf("%s",input[i]);
//             //printf("what's just copyin: %s\n",cp[i]);//%s,针对地址.
//             //len = strlen(input[i]);

//             //printf("last for letters: %s\n",&input[i][len-4]);
//             /*如果只是 input[i][len-4] 的话,可以有两个角度理解它
//             1.input[i]看作数组名,后面紧紧跟着[len-4]就是访问该数组的某个单字符
//             2.把input[i][len-4]当成一个正常的二维数组来看,这种写法就是访问二维数组中的某一个元素值
//             而此处我们要取倒5个元素所在的地址,从此处读取到'\0'为止*/

//         }

//         /* 从从input数组中筛选出尾缀为.exe,并写入到str_exe数组中 */
//         int j = 0; //解决数组str_exe空洞.
//         for (int i = 0; i < n ; i++)
//         {
//             len = strlen(input[i]);//如果没有该处的迭代,len可能是个庞大的数据,造成数组下标越界,segtment fault.
//             if (strcmp(&input[i][len - 4], ".exe") == 0)//需要随着i变化而迭代的量:len = strlen(input[i]);
//             {

//                 //strcpy(str_exe[i],input[i]);//这样写会造成str_exe有空洞
//                 strcpy(str_exe[j++], input[i]); //这里的j能否内嵌?
//                 cnt_str_exe += 1;
//             }
//         }

//         //     /* may be the files is a  virus file. */
//         //     /* 在文件名列表中   同时还存在  去掉“.exe”后同名的文件。deal_file_name */
//         //  if()
//         /*          deal_file_name   */
//         int k = 0;/* 防止cp_str_exe空洞 */
//         for (int i = 0; i < cnt_str_exe; i++)
//         {
//             len = strlen(str_exe[i]);
//             str_exe[i][len - 4] = '\0';/* 字符串截断处理 */

//             //int k = 0;/* 防止cp_str_exe空洞,但是把它安排在在循环内部其值无法得到保留,应外挪 */
//             for (int j = 0; j < n + 1; j++) //内嵌循环时要注意更换循环变量和表达式.
//             /* 检查input中是否有对应的源文件(病毒文件去壳) */
//                 if (strcmp(str_exe[i], input[j]) == 0)
//                     /* //str_exe已经被修改截断只好后期加上.exe  */
//                 // printf("This is a virus file:%s.exe\n", str_exe[i]);
//                     strcpy(cp_str_exe[k++],str_exe[i]);
//         }

//     //     /* int i=0,j=0;
//     //     int n = 0; redefined*/

//         int i = 0;
//         j = 0;
//         char buf[200];
//         /* 计数(遍历)字符串的数目n */
//             /* 如果有必要对整个字符串进行比较,当然是用strcmp()函数,但
//             如果比较第一个字符足以/或可以转化为比较其他属性(长度strlen()函数,然而这种做法并不保险,
//             因为未被填入内容的位置是随机值,不可控)*/
//             /* 处理的是无空洞字符串数组 */
//             /* 看来这个参量不是和在函数内部求,建议作为参数传递给排序函数 */
//         //for(int n = 0;strlen(cp_str_exe[n])!= 0;n++);

//         /* 冒泡排序算法 */
//         for(i = 0;i<k-1;i++)
//         {
//             for(j=0;j<=k-2-i;j++)
//             {
//                 /* 如果前者大于后者.交换位置使得最大者尽量靠后 */
//                 if(strcmp(cp_str_exe[j],cp_str_exe[j+1]) > 0)
//                 {
//                     /* 调用strcpy(),可以使得字符串的排序和赋值项整数那样利索. */
//                     strcpy(buf,cp_str_exe[j]);
//                     strcpy(cp_str_exe[j],cp_str_exe[j+1]);/* 是加号 */
//                     strcpy(cp_str_exe[j+1],buf);
//                 }

//             }
//             /* 每一趟的结束之后可以打印被排好的那个(最大的)数据了,但是此时会漏一个免排序元素(这里是那个最小元素) */
//             if(k > 0)
//                // printf("test\n");
//                 printf("%s.exe\n",cp_str_exe[k-1-i]);
//         }
//     // printf("%d items\n",k);
//         /* 补丁 */
//         printf("%s.exe\n",cp_str_exe[0]);
//     }

//     return 0;
// }

/* 
方案一:
#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000][30], a[1000][30], num[1000];
    int i, j, k = 0, n;

    while (scanf("%d", &n) != EOF && n != 0)//每轮测试读入一个n(该组的数据规模)
    {   //读入n个字符串(文件名),放在str数组里.
        for (i = 0; i < n; i++)
        {
            scanf("%s", &str[i]);
        }

        for (i = 0; i < n; i++)
        {
            if (strstr(str[i], ".exe") == NULL)//第i个文件名.
            {
                strcat(str[i], ".exe");
            }

        }
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (strcmp(str[i], str[j]) == 0)
                {
                    strcpy(a[k], str[i]);
                    k++; break;
                }
            }
        }
        for (i = 0; i < k; i++)
        {
            for (j = i + 1; j < k; j++)
            {
                if (strcmp(a[i], a[j])>0)
                {
                    strcpy(num, a[i]);
                    strcpy(a[i], a[j]);
                    strcpy(a[j], num);
                }
            }
        }
        for (i = 0; i < k; i++)
        {
            printf("%s", a[i]);
            if (a[i] != NULL)
                printf("\n");
            strcpy(a[i],"NULL");

        }
        k = 0;
    }
    return 0;
} 

*/
/*方案二: */

/* 题目描述
输入一个长度不超过100的字符串,删除串中的重复字符。

输入要检查的字符串,长度不超过100个字符:abacaeedabcded.
输出删除重复字符后的字符串:abced.
样例输入saas
样例输出sa
 */
//握手模型;最理想地输入的比较次数规模(1+2+..+n)地规模(类似勾股数枚举)
/*
#include <stdio.h>    
#include <string.h>    
#define N 200    
int main()    
{    
    char a[N];  //存储字符串.  
    int i,j,n;    
    char k;    
    gets(a);//读入字符串. 

    //遍历输入的字符串(一定规模内的) 

    //控制外层循环的趟次,并提供趟次号变量i
    int f=strlen(a);  
    for(i=0;i<strlen(a);i++)  
    {
        for(n=0;n<i;n++)//内层遍历从i=1开始进入,控制各趟次内需要执行循环的次数
        {
            if(a[i]==a[n])  //n比i更加常变:每趟比较中,i只有相同的一个值,而n要遍历i个值.;每一趟中,i就作为一个标杆
            {  //a[i] == a[n]意味着出现了重复字符;
                //下面这个循环将下一个值替代上一个值,即相当于把位置i之后的那部分子字符串向前集体地挪了一格,从而减小重复字符串的规模
                for(j=i;j<f;j++)
                {
                    a[j]=a[j+1]; //迭代a[j] ,并对字符数组(字符串)做出了该改变
                }  
                i=i-1;//将这轮发生处理地循环重新执行??/(迭代),最外层i++会加回到这个i,至于为啥放在这里,
                //当然可以再此 break;//直达外层for
            }//刚从此处离开后,n++(n将+1),之后,在这一轮发生地if将是上一轮规模地比较,不会再更改字符串了,直到外层地i++后重新开始
        }
        //刚从此处离开后,会执行在外面一层地循环变量迭代(i++)

    }  
     
    puts(a);    
    return 0;    
}  
/* 问题c:方阵中的鞍点判断(数组)[中]
题目描述
输入一个正整数m(1<m<6)和m阶方阵A中的元素,
如果找到A中的鞍点(鞍点的元素值在该行上最大,在该列上最小)
,就输出它的下标;
否则,输出"NO"(没有鞍点)。设A中最多有一个鞍点 */

// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
// 	int n, m=0, i, j, k;
// /* 定义三个指针用来标记和接收malloc()来的空内存地址 */
// 	int *p;

// 	int *pp,*qq;

// 	scanf("%d", &n);//n用来告诉计算机你要申请的内存块数
//     /* 这些内存强制转换为int类型,用来存储int类型的数据,从而达到直接将数据放到内存中去(存储) */
//     p = (int *)malloc(n*n*sizeof(int));//二维规模的内存

// 	pp = (int *)malloc(n*sizeof(int));//行里面最大的下标//1.用来指示二维中行的位置情况.2.用来存储每一行中的最大值所在下标索引.

// 	qq = (int *)malloc(n*sizeof(int));//列里面最大的下标//用来存储每一列中的最大值所在下标索引

// 	for(i = 0;i<n*n;i++)scanf("%d", p+i);/* //填充输入的数据到二维内存中,直接将数据保存到指定的d地址,
//                                             (这里有个小套路,在scanf(读数据的时候,用p+i来驱动指针/地址前进))
//                                             还有其他形式:for(q=p ; q<p+n;q++)  scanf("%d", q); 这种写法是把指针本身当作循环控制变量,
//                                             上一种写法中循环变量只是普通的整形*/
//     /* 将地址所指的内存里保存的值都初始化为1 */
//     //明确:qq+i 是指某个地址 ;*(qq+i)是指某个地址所指内存里保存的数据值
// 	for(i = 0;i<n;i++)
// 	{
// 		*(qq+i) = 1;
// 		*(pp+i) = 1;
// 	}

// //对于行和列最大值采集,采集源头指针p是共用的.
// //循环变量是共用i,而他们是互不干扰的,和行/列的意义固定关系,(他们用pp和qq指针来区分行/列 (当然可以换成别的字母)
// // *(pp+i) 刚开始为一.

// /* 将每一行的最大值元素的下标,每一列的最小元素的下标分别都记录到*(pp+i)和*(qq+i)中,但尚未处理唯一性问题
// 其中*(pp+i)记录的是列号,而*(qq+i)记录的是行号? */
// 	for(i = 0;i<n;i++)
// 	{
// 		for(j = 0;j<n;j++)//这里j既是可以是行内左右移动,也可以是里内上下移动的驱动标兵
// 		{
//             //针对行(第一行i开始)
// 			if( *( p+i*n+  ( *(pp+i) ) )   <   *( p+i*n+j ) )//去看下*和+的优先级. //系同一行的比较(第i行(i从零开始))
//                 *(pp+i)=j;
//                 //发现小了,马上换成较大值
//                 /* p+i*n+( *(pp+i) ):p是二维内存的首地址,+i*n效果上,是指针向下走i行(每行有n个int内存块)(可以画个矩阵图) ,
//                 用指针pp来指明所在行的位置(列位置)    总之,p+i*n+( *(pp+i) )是由外层循环来控制的,内层j对它不影响
//                 而*( p+i*n+j )中的j来驱动在该行的位置 ;(要和*( p+i*n+j ) 比较,迭代*/

// /* 分清楚模块之间是并列关系(互补干扰)(甚至为了避免干扰,可以将上面并列代码暂时注释掉/?/承接(先后)关系?/ 比较明显的父子关系.
// 如果事先不知道是归属于哪一种,可以意义尝试,看那个将代码解释的通顺*/
//             //针对列:(第一列(也用i刻画)开始)
// 			if(  *( p+i+n* ( *(qq+i) ) ) > *(p+i+j*n)  )/*
//             经过上述分析,我们可以知道:在这个if里(共同的i是表示共同的列,而不同行则有n的系数(*qq+i)和j来标识.)
//            发现这段比较长, 1.分析比较对象(本质)
//             不妨先判断下它是元素还是下标,(通过观察,
//             式子中有p,视为主体,在外围括号又有*运算符,为元素之间的比较.
//             2.从后者(较为简短入手)),可画辅助图形 ,并比较表达式中相同的部分和不同的部分:n*( *(qq+i) )和后者的j*n差了n的系数
//             注意左式里的是qq而非qq  */
//                  *(qq+i)=j;//将*(qq+i)更改成该列最小元素的下标值//系角标的值的更改.
// 		}
// 	}

// /* 处理唯一性 */

// 	for(i = 0;i<n;i++)
// 	{
// 		for(j = 0;j<n;j++)
// 		{
//             //按变更的频率来划分/看待/理解较长的表达式
//             //p+i*n用来指向第i行的首位值,其中j不影响   *( p+i*n  +( *(pp+i) ) )的值(他是个元素值), *(pp+i)是个列号该行最大
// 			if( ( *(p+i*n  +j) == *( p+i*n  +( *(pp+i) ) ) ) && ( j != *(pp+i) ) )
//             //if(  ( j != *(pp+i) ) && ( *(p+i*n  +j) == *( p+i*n  +( *(pp+i) ) ) )  )(换个顺序)这么些可能会更好理解,
//             /* 类似于f(x1)==f(x2)且x1!=x2 ,如果这样,就不满足唯一性了*/
//                 *(pp+i)=-1;//不满足唯一性,以此报废该行??

//             /* p+i*n用来指向第i列的位值 */
// 			if(  (*(p+i+  n*j) == *( p+i+  n*(*(qq+i)) ) )  &&(j!=*(qq+i)))
//                 *(qq+i)=-1;
// 		}
// 	}

// 	for(i = 0;i<n;i++)
// 	{
// 		if( *( qq+ (*(pp+i)) )==i )//是关于下标的表达式
//         //指针 内存 下标(嵌套)用出了函数的感觉!
//         /* //( qq+ (*(pp+i)) )
//         (在以下表达式都不为-1的话):
//         我们分成两部分来理解
//         令x = *(pp+i)是第i行最大元素所在列的列号
//         令y = *(qq+x) 是第x列最小元素所在行的行号
//         可知,y = *(qq+x) = *( qq+ (*(pp+i)) )如果还是== i的话,即找到鞍点.
//          */
// 		{
// 			printf("%d %d\n", *(qq+i), *(pp+i));
// 			m++;//flag+1
// 		}
// 	}

// 	if(m==0)printf("NO\n");

//     free(p);
// 	free(pp);
// 	free(qq);
// 	return 0;
// }

// #include <stdio.h>
// #include <string.h>
// int linemax_column_number(int a[][6],int m,int i);
// int columnmin(int a[][6],int m,int j);

// int main()
// {
//     int a[6][6];
//     int m = 0;
//     int x = 0 ,y = 0;

//     while ( scanf("%d",&m) != EOF)
//     {

//         for(int i = 0;i<m;i++)
//         {
//             for(int j = 0;j < m;j++)
//             {
//                 scanf("%d",&a[i][j]);
//             }
//         }//结束读入/

//         int flag = 0;
//         for(int i = 0;i<m;i++)
//         {
//             if((x = linemax_column_number(a,m,i)) >= 0 && (y = columnmin(a,m,x)) >= 0);//j(max)

//             {
//                 if(a[i][x] ==  y )
//                 {
//                     printf("%d %d\n",i,x);
//                     flag = 1;
//                     break;

//                 }
//             }
//         }

//         if(flag == 0)
//         {
//             printf("NO\n");
//         }

//     }

// }

// /* 找出各行最大元素所在列,如果唯一,则返回列号
// (i行号由实参传入) */
// int linemax_column_number(int a[][6],int m,int i)
// {   int j=0;
//     //int linemax = 0;//初始化最大元素为linemax=0,考虑负数的情况,=0,并不保险.宜设为某个输入的元素.
//     int linemax = a[i][0];
//     int linemax_column_number = 0;
//     for( j = 1 ;j<m;j++)
//     {
//         if(linemax<a[i][j])//
//         {

//             linemax = a[i][j];
//             linemax_column_number = j;//共享if语句

//         }

//     }//
//     /* 判定行最大元素是否具有唯一性,不唯一则返回-1 */
//     int maxs = 0;
//     for(int j = 0 ;j<m;j++)
//     {
//         if(linemax == a[i][j]) maxs += 1;
//     }
//     if(maxs>1) return -1;

//     return linemax_column_number;
// }

// /* 求基于linemax_column_number这一列号所对应列的最小值 */
// int columnmin(int a[][6],int m,int j)//列
// {
//     int i = 0;
//     int  columnmin = a[i][j];
//     //这里的初始化不可过于随意.
//     for(i = 1;i<m;i++)
//     {

//         if (columnmin>a[i][j])//是否偏大
//         {
//             columnmin = a[i][j];
//         }
//     }
// /* 判定最小值是否具有唯一性,若没有,返回-1 */
//     int mins = 0;
//     for(int i = 0 ;i<m;i++)
//     {
//         if(columnmin == a[i][j]) mins += 1;
//     }
//     if(mins>1) return -1;
//     return columnmin;/* 返回该列唯一的最小值元素(如果有) */
// }
/* 问题B:最大乘积
题目描述
输入一组整数 从该组整数中任意取出若干个,求所能得到的最大乘积。
输入
样例包含多组数据,每组数据中先输入一个整数NO-n<100),后面N行每行一个整数。读取到文件尾结束。
输出
每组数据输出占一行,输出该组整数所能得到的最大乘积。 */
/* 

/* #include <stdio.h>
#include <string.h>
int main(){
    int a[100];
    int n;
   while (scanf("%d",&n)!= EOF)
   {
       int sum = 1;
    int numberofminus = 0;
    int minus[100];
    //计数负数有几个;
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&a[i]) ;
        if (a[i]<0) numberofminus += 1;
        
    }
    //将所有非0数相乘
    for(int i = 0;i < n;i++)
    {
        if(a[i]!=0)  sum *= a[i];   
    }   

    //如果负数的个数为奇数数.
    if (numberofminus%2 != 0)
    {
           //负数拷贝到minus[]里: 
        for(int i = 0;i < n;i++)
            {
                if(a[i]<0) 
                {
                    minus[i] = a[i];
                }
            } 
        //找到最大负数(绝对值最小的负数)
        int maxnegtive = minus[0];
        for(int i = 1;i < numberofminus ;i++)
        {
            if(maxnegtive < minus[i] )
            {
                maxnegtive = minus[i];
            }
        } 
        //原来的积除于这个最小负数.
        sum /= maxnegtive;
  
    }
    
    printf("%d\n",sum);
   }
    
    
    
}  */

/* 排序:对指针的指向关系进行重构 
字符串排序:
请编写C程序,输入5个不同的且为字符格式的学生编号,将其先由大到小排序,再将最大的学生编号和最小的学生编号互换位置,然后输出此时5位学生的编号。

输入
输入5位学生的编号(只含数字字符、英文字母或空格)。

输出
输出按题意要求排序后的5位学生的编号。

样例输入
good1
tiger100
horse20n
mouse 022
21century
样例输出
21century
mouse 022
horse20n
good1
tiger100
提示
用gets()函数输入字符串。

*/
/*#include <stdio.h>
#include <string.h>
void swap(char **,char **);
int main(){

    char *p[5];//开一个指针数组.(同时也要开一个二维数组来与指针数组绑定;(否则光有指针数组只是空壳(只是一些没有空地的地址),存不了东西(字符串)
    char str[5][50];//开一个字符数组(5行50列规格),与指针数组p对应绑定
    int i,j;
//    printf("test_1\n");
    for (i = 0;i<5;i++)
    {
        gets(str[i]);//向字符数组里填东西:(二维数组中的第i行的字符串),然后与p[i]绑定.
        p[i] = str[i];//让指针数组里的指针p[i]指向字符串的首地址str[i];
       //printf("___________%s",p[i]);
    }
 
            //使得*p[]指针数组中最后的那个指针所指的那个元素被迭代为最小
            //类似于冒泡
            //if(*p[j] > *p[j-1] )//p[j-1]可以触及p[i];(虽然j无法于i相等)
            //如果后指针所指的元素大于前指针所指的元素,那么交换这对相邻指针的指向关系
            //最终,最大的那个元素将由最前面的那个指针所指向.那么隐去这一对指向关系后(p[0]----str_var(max))
            //由j>=i+1来实现.(可以感受到冒泡思维,再各趟的"排序中" 遇到最大值之前,所作的所有swap操作都是没什么意义的)
    for(i=0;i<5;i ++ )//外层循环变量除了可以用来控制循环的次数,还可以参与内部循环的条件控制.(双控变量)
    {//冒泡
        for(j=4;j>=i+1;j--)
        {//!!比较字符串位置索引的前后j>i;j只需要到前推到i+1处即可,i处的元素由此时的j-1,来访问到,使之参与比较.
            if(*p[j]>*p[j-1])
           // if(p[j] > p[j-1] )//比较的是地址(int(十六进制)).而非地址所指的字符串本身(char).
                                //实际上就是*pointer.(这里的值是各个字符串)
                                //字符串的比较是计算机内部逐字符的比较,
                                //用户把他们简化的当作两个字符的比较的用法一样;
 //这里再做一个额外的小区分:*p[j+1](对于str的行指针,指上(前)一个字符串首地址)和*p[j]+1(指这一字符串中的后面(下)一个字符);
            {
                //直接交换,而不设置最值角标中间变量,冒泡
                swap(&p[j],&p[j-1]);//pointer.
                //swap(*p[j],*p[j-1]);//*p[j]是字符串本身:即char 类型的变量.
            }
        }
    }
    printf("%s\n",p[4]);
    for(i = 1;i < 4;i++)
    {
        printf("%s\n",p[i]);
    }
    printf("%s\n",p[0]);
    
}  

void swap(char **a,char **b)//交换指向关系而已
{
   
    char *t;

    t = *a;//
    *a = *b;
    *b = t;
} 
 */

/* 

*/
/*  分解质因数(本解答利用迭代减小规模的思路) */
/**/
#include <stdio.h>
#include <string.h>
int isprime(int n);
int main(){
    int n;
    scanf("%d",&n);
    printf("%d=",n);

    //迭代减小n的规模.
    for(int i = 2;i<n+1;)
    {
        if(n != 1 && n%i == 0 && isprime(i))
        /*n!=1:还未分解完毕;n%i=0:n被i整除;isprime(i):i是质数.*/
        {

            printf("%d",i);/*打印该因子*/
            
            n = n/i;//不是%;n=1的时候分解完毕.

            if(n != 1) printf("*");/*如果当前因子i不是最后一个因子,打印乘号*/
            
            i=2;//k&R的手法,内部重新初始化i;//可以修改为递归函数
        }
        else
        {
            i++;
        }
        
    }//for

    return 0;
} 
int isprime(int n)
{
    if(n==2) return 1;
    for(int i = 2;i<n ;i++)
    {
        if(n%i == 0)
        {
            return 0;
        }
    }
    return 1;
}
 
/* #include <stdio.h>
int main(){
 int a,b,i,n,j;
 scanf("%d%d",&a,&b);
 for(i=a;i<=b;i++){
  printf("%d=",i);
         n=i;
         j=2;
         while(n!=j){
         for(j=2;j<n;j++){
          if(n%j==0&&n!=j){
           printf("%d*",j);
     n=n/j;
     break; 
    }
   }
          
   }
     printf("%d\n",n);
  }
 return 0; 
 }
  */

/* 输入一个正整数,将它分解为质因数(质数即素数)。例如,输入90,输出... 
一下为不完整分析:*/
/* #include <stdio.h>
#include <string.h>
int main(){
    int n;
    int isprime(int a);
    scanf("%d",&n);
    //属于对称性问题
    for(int i = 2;i*i < n + 1;i++)
    {
        if(n%i == 0)
        {

        }

    }

}
int isprime(int a)//分析普通阶段的因子是否为质数
{
    for(int i = 2;i*i < n + 1;i++)
    {
            if(a%i == 0)
                return 0;
            else 
                return 1;
    }
}
 */
/* 字符串逆序存放并输出 */
/* #include <stdio.h>
#include <string.h>
int main(){
    char a[1000],t ;
    int len;
    
    scanf("%s",a);
    len = strlen(a);
    
    for(int i = 0;i<len/2;i++)
    {
        t = a[i];
        a[i]=a[len-1-i];
        a[len-1-i] = t;
    }
    printf("%s",a);

}  */
/* #include <stdio.h>
#include <string.h>
int main(){
    char string[10000];
    gets(string);
    while (int i = 0,string[i]=='i' && string[i+1]=='s')
    {
        strcat();
    }
    
}
 */
/* 从键盘输入的字符串中查找是否含有单词"is/Is/IS/iS"(大小写不区分),
有则将其删除,输出结果字符串。
输入:egidisisiiifssiidis
输出:idiiifssiid */
/* 
#include <stdio.h>
int main()
{
    char s[1000];
    int i,j;
    scanf("%s",s);//读入字符串(不需要&)
    for(i = j = 0; s[i]; i ++)//条件时s[i],即会遍历完整个字符串s
    {
        //对if嵌套有时会比(&&逻辑与)更加灵活(特别是条件表达式太长时)
        // if(s[i] == 'i' || s[i] == 'I')
        // {
        //     if(s[i+1] == 's' || s[i+1] == 'S')
        //         i++;
            
        // }这么写的话单个字符i将会进入if(而不会进入else,i就不会被写入s[j]当中)
        if(s[i] == 'i' || s[i] == 'I')
        {
            if(s[i+1] == 's' || s[i+1] == 'S')
            {
                i++;
            }   
            else
            {
                s[j++] = s[i];
                //仍然要把单独地i存入s[j]数组(单独的s字母字符呢?放心,它再第一if的判断中就过不了,会写进s[j])
            }
            
        }
        else s[j++] = s[i];//把需要保留地字符都装到s里面.
    }
    s[j] = 0;//本行是遍历完s且将最后一个需要保留地字符(我们成为合法字符)更新到s里头后,
                //立刻屏蔽掉之后地内容(is),如果没有该行,结果:合法字符串之后原样输出旧字符地后部分
     //但是为什么不时'\0' ?
    printf("%s\n",s);
    return 0;
} */
/* 问题B:上三角矩阵判断(数组)[易]
题目描述
输入一个正整数m(1Kms6)和m阶方阵A中的元素,如果A是上三角矩阵,则输出"YES",否则输出
"NO"(上三角矩阵即主对角线以下的元素都为0的矩阵,主对角线为从矩阵的左上角至右下角的连线)。
输入
3123012001输出
YES */
/* 

 */

/*  问题A:对角元素除法运算(数组)[易]
题目描述
输入一个正整数m(1sms6)和m阶方阵A中的元素(其中对角线上的元素不能为0),以A的每一行元素除以其中的对角元素,求解并输出新的方阵,要求每个元素保留两位小数。
输入
3 2 4 
6 3 9
10 15 5
输出
1.00 2.00 3.00
2.00 1.00 3.00
2.00 3.00 1.00


#include <stdio.h>
#include <string.h>
int main(){
    float a[6][6];
    int m;
    //printf("debuging\n");
    scanf("%d",&m);
    //printf("debuging\n");
    for(int i = 0;i<m;i++){
        for(int j = 0;j < m;j++){
           // printf("debuging_for\n");
            scanf("%f",&a[i][j]);
            
            //printf("%f",a[i][j]);
        }

    }

    for(int i = 0, t ;i<m;i++){//
       t = a[i][i];
        for(int j=0;j<m;j++){
        //  a[i][j] = a[i][j]/a[i][i]; //注意,这是后的a[i][i]已经被默默修改了,
        //                                // 我们因该单独保存各行的对角量值保证它再该行不变 
            a[i][j] = a[i][j]/t;
            printf("%.2f",a[i][j]);
            if(j<m-1) printf(" ");
        }
        printf("\n");
    }


}  
 */
/* 标题套子
#include <stdio.h>
#define D "%d" //输出控制符
#define F "%f" //输出控制符
#define NL "\n"
#define CIN_D(x) scanf(D NL,(&x))
#define CIN_F(x) scanf(F NL,(&x))
#define COUT_D(x) printf(D,(x))
int main(){
    
    return 0;
} 
*/

/* 
#include <stdio.h>
#define D "%d" //输出控制符
#define F "%f" //输出控制符
#define CIN_D(x) scanf("%d",&(x))
#define CIN_F(x) scanf("%f",&(x))
#define COUT_D(x) printf("%d",(x))
int main(){
    int a ;
    float b;
    CIN_D(a);
    COUT_D(a - 1);
    return 0;
}
 */

/* 问题E:大奖赛现场统分-数组[中]
题目描述
某大奖赛有n(1<n<40)个选手参赛,m(2<m<20)个评委为依次参赛的选手评判打分:最高10分,最低0分。统分规则为:每个选手所得的m个得分中,去掉一个最高分,去掉一个最低分,最后平均为该选手的最后得分。根据n个选手的最后得分从高到低排出名次表,以便确定获奖名单。
输入
输入选手的数目n(1<n<40),评委的数目m(2<m<20),以及评委对每位选手的打分。
输出
选手的排名及最终的得分值(小数点后保留两位)。
样例输入
3,5
5.6 7.8 9.4 5.8 8.8
7.8 6.7 8.3 6.9 5.5
6.7 9.2 8.8 8.3 9.0
样例输出
第1名:3号选手,得分8.70
第2名:1号选手,得分7.47
第3名:2号选手,得分7.13提示
1.在输入样例中,第一行的"3,5”表示3个选手,5个评委。
2.在输入样例中,第二行为5个评委对第1位选手的分别打分;第三行为5个评委对第2位选手的分别打分;第四行为5个评委对第3位选手的分别打分.
3.在输出样例中出现的标点符号均在英文状态下输入的。 */
/*
 */
/* 
#include <stdio.h>
void swap(float *, float *);
float average(int m, float judge[]);
void bubble_sort(int n, float competitor[]);

int main() {
	int n, m;
	int max ;
	float judge[20];
	float competitor[40];
	float copycompetior[40];
	int numberOfcompetitor[40];//储存选手编号
	scanf("%d,%d", &n, &m);//届时注意输入分隔符,
	for (int i = 0; i < n; i++) {
		competitor[i] = average(m, judge);
		// printf("%d\n",competitor[// printf(“％d \ n”,competitor [i]);i]);
	}
	for (int i = 0; i < n; i++) {
		copycompetior[i] = competitor[i];
	}
	for (int i = 0; i < n ; i++) {
		//找到该趟次中最大元素所在位置索引.
		max = 0;
		for (int j = 1; j < n ; j++) {
			if (copycompetior[max] < copycompetior[j])
				max = j ;//再打各补丁?

		}
		numberOfcompetitor[i] = max;//记录位置
		copycompetior[max] = 0;//使之不会影响下一个排名的选手的查找.
		
	}
	bubble_sort(n, competitor);

	for (int i = 0; i < n; i++)
	{
		printf("第%d名:%d号选手,得分%.2f\n", i+1, numberOfcompetitor[i]+1, competitor[i]);//printf("%f(修改时若忽视将导致输出异常")
	}

	return 0;//主函数.
}
//
void swap(float *a, float *b) {
	float temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;//修改旧变量(这一操作),二不带回其他值.

}
float average(int m, float judge[]) {
	float min, max, temp, sum = 0;
	scanf("%f", &judge[0]);//(也可以整合到for里面去),则min = max =judge[0]//初始化为0
	min = max = judge[0];
	//这是就要及时地为sum赋上第一个值(judge[0]),否则第一个值将丢失.
	sum = judge[0];
	for (int i = 1; i < m; i++) {
		//不对数组进行任何排序性修改,只是记录最值,并保存(迭代更换)到指定的变量里
		scanf("%f", &judge[i]);//函数内部的变量类型也要在修改函数是注意
		sum += judge[i];

		if (min > judge[i]) {        //写个swap()
			temp = judge[i];
			judge[i] = min;
			min = temp;
		}
		else if (max < judge[i]) {
			temp = judge[i];
			judge[i] = max;
			max = temp;
		}
	}
	sum = sum - min - max;
	return sum / (m - 2.0);
}
//循环:loop
void bubble_sort(int n, float competitor[]) {
	int max;
	//事实上,选择排序法更适合于本题

	for (int i = 0; i < n - 1; i++) {//i = 0的版本.
		 
		//j作箭头指着.(从最后一个索引(n-1))
		for (int j = n - 1; j > i; j--) {// j:  0,1,...,    i,...n-2,   n-1.(也可写作j<= n-2),该轮进行了n-2 - i + 1 = n-1-i次比较.
			max = n;//?
					//每一趟地最后一个元素由判断语句中的competitor[j+1]引入比较.
			if (competitor[j] > competitor[j - 1]) {

				swap(&competitor[j], &competitor[j - 1]);

			}
			

		}//该趟(对应行的排序结束)

		
	}

	return;
} */
/* 问题D:回文数猜测-分支循环小综合[难]
题目描述
所谓回文数,即顺序与逆序均为相同的整数。如292、10301均为回文数。
“顺逆求和”操作就是把一个数与其逆序数相加。
有人猜测:任意一个十进制整数n(n不为回文数),经有限次“顺逆求和’操作可得到一个回文数。

例如,对于n=69,有(1)69+96=165(2)165+561=726(3)726+627=1353
(4)1353+3531=4884(回文数)。
试设计程序,验证某一区间[x1,×2]中的每一个数n是否为回文数,
若不是,请展示n通过以上“顺逆求和”操作转化为回文数的步骤数。
例如n=69时经4次操作得到回文数,输出69(4)及得到的回文数4884。
如果超过100步还未能转化为回文数,则终止操作,输出n(？),表明该数可能不满足猜测。
输入
输入两个整数(第一个小于第二个)。
输出
输出回文数的步骤数及相应的回文数。
输入
86 90
输出
86(3):nn
87(4):4884
88(0):88
89(?):
90(1):99
 */

/*
#include <stdio.h>
int palindrome(int n);
int main(){
    int x1,x2;
    int flag ;
    scanf("%d%d",&x1,&x2);
    for(int i = x1;i <= x2;i ++ ){
        if(i == palindrome(i)){   //如果写成赋值表达式,编译器检查不出逻辑错误的.
                                    //(死循环的时后就要考虑是否疏忽写成=(==才是对的)),可能还有多处!1
            printf("%d(0):%d\n",i,i);
        }
        //else if 不可直接用于替代else   else if(1)
        //区别于else 即else后不需加条件(xx)
        //else if(是需要的填写条件的!!)
        //else if(1)(死循环了)
        else
        {
            //for(int t = i,j = 1;j <= 100;j ++){
                //j为进行逆序求和的次数.
            flag = 0;
            int t = i;
            for(int j = 1;j <= 100;j ++){
                //int t = i;位置犯错
                t += palindrome(t);
                if(t == palindrome(t)){
                    printf("%d(%d):%d\n",i,j,t);
                    flag = 1;
                    break;
                }  
            }
            if(flag == 0)
                {
                    printf("%d(?):\n",i);
                } 
        
        }
    }
        
    return 0;
} 
//调试的时后注意函数是否错误;
int palindrome(int n){
    int ret = 0;//这里不要重复定义n
    while (n > 0)
    {
        //ret += n % 10 + ret * 10;//前面已经使用了自增运算符,出现重复逻辑(混论)
        //对n迭代:
        ret = n % 10 + ret * 10;
        n /= 10;
    }
    
    return ret;
}//端点调试不要断在自定义函数内部!!

 */

/* 问题C:计算三角形的面积和周长(分支)[易]
题目描述
输入三角形的3条边a、b、c,如果能构成一个三角形,输出面积area和周长perimeter(保留两位小数);否则,
输出“There sides do not correspond to a valid triangle”。
在一个有效的三角形中,任意两边之和大于第三边。
三角形面积计算公式area=sqrt(s(s-a)(s-b)(s-c)),其中s=(a+b+c)/2。
输入
345235输出
6.0012.00(6.00为面积,12.00为周长)There sides do not correspond to a valid triangle */
/* #include <stdio.h>
#include <math.h>
int main(){
    float a,b,c;
    float s;
    float perimeter = 0;
    float area = 0;
    scanf("%f%f%f",&a,&b,&c);
    if (a + b > c && a + c > b && b + c > a){
        perimeter = a+b+c;
        s = 1/2.0*perimeter;
        area = sqrt(s*(s - a)*(s - b)*(s - c)); 
        printf("%.2f %.2f\n",s,perimeter);
    }
    else
         printf("There sides do not correspond to a valid triangle");
    return 0;
} 
 */
/* #include <stdio.h>
#include <math.h>
int main(){
    float a,b,c;
    float s;
    float perimeter = 0;
    float area = 0;

while(scanf("%f%f%f",&a,&b,&c) != EOF)
{
    
    if ((a + b > c )&&( a + c > b) && (b + c > a)){
        perimeter = a+b+c;
        s = 1/2.0*perimeter;
        area = sqrt(s*(s - a)*(s - b)*(s - c)); 
        printf("%.2lf %.2lf\n",area,perimeter);
    }
    else
         printf("There sides do not correspond to a valid triangle\n");

}
      
    return 0;
}   */
//题目描述
//接收一个四位数。编写一个程序,将该数的每一位数字相加并显示结果。
/* #include <stdio.h>
int main(){
    int n;
    int m = 0;//有必要对m做初始化,否则m += n % 10;会把m随机值计入
    scanf("%d",&n);
    while(n > 0){
        m += n % 10; 
        n = n/10;    
    }
    printf("%d",m);
    return 0;
}
 */
/* 从键盘输入一个整数n(1≤n≤9),打印出指定的菱形。
输入
正整数n(1≤n≤9)。
输出
指定的菱形。 第一行前面有n-1个空格,第二行有n-2个空格,以此类推。
样例输入
5
样例输出
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
    
     */
//打印菱形
/* #include <stdio.h>
int main(){
    int n;
    int m;
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++){
        //先打印该行的n-1各空格(连续打印完)
        for(int j = 0;j < n - i;j ++){
            printf(" ");       
        }
        //接着打印该行的*号
        for(int k = 0;k < 2 * i - 1;k++){
            printf("*");
                }
        printf("\n");//位下一行准备
    }
    for(int i = 1;i < n;i ++){
        //先打印该行的n-1各空格(连续打印完)
        for(int j = 0;j < i;j ++){
            printf(" ");       
        }
        //接着打印该行的*号
        m = 2 * n - 1;
        for(int k = 0;k < m - 2 * i;k++){
            printf("*");
         }
        printf("\n");
    }
}  */

/* //三重回文数(回文:palindrome)
*/
/* 
#include <stdio.h>
int istri_palindrome(int n);
int main(){
    int n;
    int power_n = n*n;
    int cube_n = n*n*n;
    scanf("%d",&n);
    if (istri_palindrome(n) && istri_palindrome(power_n) && istri_palindrome(cube_n))
        printf("%d是三重回文数\n",n);
    else
        printf("%d不是三重回文数\n");
    
    return 0;
        
}
int istri_palindrome(int n){
    int b,r=0;
    b = n;
    while(b)
    {
        r = r*10+b%10;
        b = b/10;
    }
    if (n == r)
        return 1;
    else
    {
        return 0;
    }
    
}  */
/* //回文函数:(思路有两类,一类是局部(内部的)角度,也就是从定义出发,高位与低位比较,
次高与次低比较,...一对一对地比较
另一类是比较好地整体比较法,把旧数整体逆序,
在比较先后两数是否相等(定义迁移),转化问题(可见成功地转化是多么重要)))
 */
/* #include<stdio.h>
int huiwen(int n)
{
    int b,r=0;
    b=n;
    while(b)
    {
        r = r*10+b%10;
        b = b/10;
    }
    return r;
}
 
int main(int argc,char **argv)
{
    int start,end,cnt,n;
    cnt = 0;
    printf("请输入范围:");
    scanf("%d %d",&start,&end);
    while(start <=end)
    {
        n=start;
        cnt = 0;
        while(huiwen(n) != n)
        {
          n = n+huiwen(n);
          cnt++;
          if(cnt > 100)
          {
              break;
          }
        }
        if(cnt > 100)
        {
            printf("%d(?):?\n",start);
        }else
        {
            printf("%d(%d):%d\n",start,cnt,n);
        }
        start++;
    }
} */

//插入数组
/* 
有一个已经排好序的数组:    int a[n]={1,4,6,9,13,16,19,28,40,100};

今输入一个数,要求按原来排序的规律将其插入数组中,并输出新的数组。此题要求不再定义使用新的数组。

输入
输入一个整数。

输出
输出符合要求的新数组。

样例输入
10
样例输出
1
4
6
9
10
13
16
19
28
40
100 
*/

/* #include <stdio.h>
int main(){
    int a[n] = {1,4,6,9,13,16,19,28,40,100};
    int temp = 0;
    
    scanf("%d",&a[10]);
    for(int i = 0; i < 10; i++){
        if (a[10 - i] < a[10-i-1]) {
            temp = a[10-i-1];
            a[10-i - 1] = a[10 - i];
            a[10 - i] = temp;
            }   
    }
    for(int j = 0;j < n;j++)
        printf("%d\n",a[j]);
} */
/* //球落地反弹
一球从100m高度自由落下,每次落地后反跳回原高度的一半,再落下。求它在第n次落地时,共经过多少米？第n次反弹多高？(小数点后保留5位)

输入
输入一个正整数n。

输出
输出小球经过的路程和第n次反弹的高度。

样例输入
10
样例输出
共经过299.60938米
第n次反弹0.09766米

*/
/* 
#include <stdio.h>
#define H0 100
#define K 2*H0//第n次往返经过的路程位2*(1/2)^(n-1)*H0 = (2*H0) * (1/2)^(n-1),
               //则可令常系数k = 2*H0 
int main(){
    int n;
    int m;
    float distance = H0;
    float distance_th = H0;
    float delta = K;
    scanf("%d",&n);
    m = n;
    while(--n){
    distance += 1/2.0*delta;
    delta /= 2;
    }
    while (m--)
    {
        distance_th /= 2;
    }
    

    printf("共经过%.5f米\n",distance);
    printf("第n次反弹%.5f米",distance_th);
}  */
/* #include<stdio.h>
#define H0 100
int main()
{
	int n;
    //第n次往返经过的路程位2*(1/2)^(n-1)*H0 = (2*H0) * (1/2)^(n-1),
    //则可令常系数k = 2*H0 
	float  k = 2*H0,sum = H0,height = 100,;
    float  b, i,
	scanf("%d", &n);
    //只需针对于n>1的情况(2,3,...),让i从1开始,(i<n),可以使得n>=2,是才(有需要/适合进入该循环)
	for (i = 1; i < n; i++) {
        
		sum += k / 2;
		k /= 2;         //对first迭代,可以避开对乘方函数的调用(这也是递归函数编写的关键.)

	}

	for (i = 0; i < n; i++)
		height = height / 2;
	printf("共经过%.5f米\n", sum);
	printf("第n次反弹%.5f米\n", height);

}
 */

/* //10米跳水计分系统/* 
#include <stdio.h>
int main()
{
    float score[10];//存储输入的分数
    float max, min, sum;//存储最高分,最低分和总分
    int i;

    scanf("%f", &score[0]);
    max = min = score[0];//首先假设输入的第一个分数是最高分和最低分
    sum = score[0];//

    for(i=1; i<10; i++)//然后输入剩下的9个分数
    {
        scanf("%f", &score[i]);
        sum += score[i];//在已有值的基础上累加的经典写法
        if(score[i]>max) 
            max = score[i];
        else if(score[i]<min) 
            min = score[i];
    }
    sum = sum - max -min;//减去最高分和最低分
    printf("%.3f\n", sum/8.0);
}
 */

/*试通过程序设计求指定区间［a,b］内的所有勾股数组。
输入
输入两个正整数a, b (a<b).
输出
输出［a,b］区间内的所有勾股数组。
样例输入
30, 90
样例输出

*/
/* 
#include<stdio.h>
#include<math.h>
int main()
{
   int a,b;
   int x,y,z,d;

  // printf("请输入区间[a,b]的上下限a,b:");
   scanf("%d,%d",&a,&b);//如果里面有逗号,输入时a,b以逗号隔开而非默认的空格
  // printf("区间[%d,%d]中的勾股数组有:\n",a,b);
//动手画图最重要;
//下一轮的遍历的起点相较于与上一轮右移了一位.(当然,同一轮的遍历中,第一个数是固定的)
   for(x=a;x<=b-2;x++){//外层控制x
       //区间里的后两个数没有求平方和!(此时的z必在b后)
      for(y=x+1;y<=b-1;y++){//内层控制y
      //可以发现,如果x=y=k,则z=double sqrt(2)*k,即此时的z不是整数,故不需考虑
         d=x*x+y*y;

         z=sqrt(d);//开方函数sqrt(),发生取整,如果有小数部分,将会丢失,即此时z*z < d
         if(z>b)//此时的y对于当前的x已经过大,测试下一个x,并重置y(=x+1)
            break;
            //跳到上一重循环里.(测试下一个x下的新情况)
         if(z*z==d)//说明之前的d能够刚好开方
         {
           
            //把当前的x,y,z三元组打印出来.
            printf("%d^2+%d^2=%d^2\n",x,y,z);
         }
      }
    }
 
} */
/* 编一个程序,输入一个字符串,将组成字符串的所有非英文字母的字符删除后输出。
 
输入
输入一个字符串

输出
输出删除非英文字母后的字符串

样例输入
jka.39+jka;fkkKKaakda;?
样例输出
jkajkafkkKKaakda */
/* 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 拷贝到平台的时候把my_fuction_lib.h注释掉.
   // #include "my_fuction_lib.h"

//在此下方插入自定义函数对的声明:
int is_English_character(char a)
{
    if(a >= 'A' && a <= 'Z' || a >= 'a' && a <= 'z')//'Z'和'a'之间还有许多符号[]等;
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
//主函数main
int main()
{
    char str[10000];
    while( scanf("%s",str) != EOF)
    {
        for(int i = 0;i<strlen(str);i++)
        {
            if(is_English_character(str[i]))
            {
                printf("%c",str[i]);//][中括号人能够输出!!why?]
            }
            
        }
        //printf("\n");//多余的\n使得ACM上通不过.
    }

    return 0;
}  
*/
//主函数结束.
//在下方编写自定义函数:

//往下输入/插入题目:
/*小凡的老师给了小凡一个任务就是做一个中文的计算器。比如说输入“十加十”,那么小凡就要得到 20 这个值
,但是小凡太笨怎么都搞不定,所以老师给他降低了要求,让他只要把阿拉伯数字转换成中文就行了,
还说如果他连这个都不会就不给他及格了。小凡都快哭了,好心的你帮帮他吧。
输入
有多组测试数据,请用while(…)读入数据,直到EOF。
每组数据为一串数字,如:2358、2989、51(不超过9999)。
输出
每个输入对应一个输出。对应上面的输出分别为二千三百五十八、两千九百八十九、五十一。
样例输入
36
2n
2126
10
20
101
样例输出
三十六
二百一十一
二千一百二十六
十
二十
一百零一
提示
1、用while(scanf(“%s”,str)!=EOF)或while(gets(str)//返回值与NULL比较)循环读取每组数据。

2、情况比较繁琐,请多思考 


//策略:
1.梳理一下如果是人类来识别阿拉伯数字并转化为中文的过程:
a.先数出这个数是几位数,以便确定最高位;

b.如果数码不是0,则连同他的权一起读出来;如果遇到数码为零的则该为的权就不读出来; 

    (一个零我们直接读个零;如果有多个相邻的零,我们也只读一个零)  (这一条规则是本题的处理的关键,
    看看能否在这点转化,优化算法)
    //为了监测是否有相邻的零存在,我们可考虑设一个监控变量flag(相邻零的个数):
    当flag = 1 且不超过1:不读出它的权(屏蔽掉该位的权);当flag = 2时,屏蔽掉前一个零(考虑写成函数)
    迭代上述过程.(最终没有采用该法.)

    思想方法,变换角度审视问题(经常是在构成问题的这些素材之间切换视角)
比如100101
十万位上有非0数,我们就连同它的权读出,下一个非零数为百位,也连同它的权一起读出,
再有个位上的非零数(这时只读出数码)  一十万 一百 一
再往里头插入一个零,如果有空位的话。(想法挺好,不太好实现.最后还是边调用函数(处理非零) 便插入'零'一个比较长的if)
好在这个题目要求的范围只在9999内,不会引起十万和一十万的分歧(然而n读十一还是一十一)
即便有如此分歧,我们可以单独再开一一个if 输入的如果是两位数且以一开头。判断即可(单独一个:0)
*/

/* 
// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>

// //在此下方插入自定义函数对的声明:
// /* 阿拉伯数字转换为汉字. */
// char * change_to_Chinese_character(char str_i, char*);
// /* 权重函数 */
// char* insert_weights(char *buf, int len);
// //void insert_zero(char(*b)[6];
// int internal_zero(char *str,int i,int len);/* 处理内部和外部(尾端的一些零) */
// //主函数main
// int main()
// {
// 	//printf("test:\n");
// 	char str[5];/* 读入的阿拉伯数子不超过9999 ,但可以自行增加字典*/
// 	char buf[10];/* 用来带回函数处理后字符串.在函数调用时,它会被清空之前的残留,进行该次重写 */
// 				 //int len = strlen(str);还未读入内容!应在scanf之后

// 	while (scanf("%s", str) != EOF)
// 	{
// 		//char str[5];/* 读入的阿拉伯数子不超过9999 */

// 		/* 将读入的数字字符串转化为数码,并存储到整形数组中去,方便提供运算。 */
// 		int len = strlen(str);

// 	/*	int number[5];
// 		for (int i = 0; i<len; i++)
// 		{
// 			number[i] = str[i] - '0';
// 		}*/

// 		char result[10][6] = { 0 };/*  */
//         int cnt_result = 0;
//         if (str[0] != '0')//len != 1 &&
//         {

//             int k = 0;                    /*用于指示移位填充*/
//             int j = len;                  /*是否打印出来是另一回事,权始终是要向后移动的*/
//             for (int i = 0; i < len; i++) /* 需要测试len次. */
//             {

//                 /* k比较灵活,用于指引strcpy()填充内容到result中位置 */
//                 if (i >= 1 && str[i] == '0' && str[i - 1] != '0' && internal_zero(str, i, len))
//                 {
//                     strcpy(result[k++], change_to_Chinese_character(str[i], buf)); //至少要等到k = 2之后
//                     cnt_result++;
//                 }
//                 else if (str[i] != '0')
//                 {
//                     /* 这个手法很好,在把当前位置填充后,还把位置指向下一个,放置冲突 */
//                     strcpy(result[k++], change_to_Chinese_character(str[i], buf)); /* 一个汉字就是一个字符串 */
//                     cnt_result++;
//                     if (j >= 2)
//                     {
//                         strcpy(result[k++], insert_weights(buf, j));
//                         cnt_result++;
//                     }
//                 }

//                 j--;
//             }
//         }
//          else
//         {
//            strcpy(result[0],"零") ;
//            cnt_result++;
//         }

//         //int delta[5];
// 		//int j = 0;
// 		//for (int i = 0; i < len; i++)
// 		//{
// 		//	if (str[i] == '0')
// 		//	{
// 		//		delta[j++] = i;
// 		//	}
// 		//}

// 		// int cnt = 0;/* 记录len中有多少字符串.(单独计数不太方便(就在写入result的时候顺便给它计数))
// 		//             如果是要单独计数,可以考虑在使用result之前(定义的同时,将其初始化掉),
// 		//             利用strlen,更好是strcmp() */
// 		// for( int i = 0 ;i < len;i++ )
// 		// {
// 		//     strcpy(result[i],change_to_Chinese_character(str[i],buf));
// 		//     cnt++;

// 		// }

//         for (int i = 0; i < cnt_result; i++)
//         {
//             if (len == 2 && str[0] == '1')
//                 printf("%s", result[i + 1]);
//             else
//                 printf("%s", result[i]);
//         }
//         printf("\n");
//     }

// 	return 0;
// }
// //主函数结束
// //在下方编写自定义函数:
// int internal_zero(char *str,int i,int len)
// {
//     int cnt = 0;
//     for(;i<len;i++)
//     {
//         if(str[i] != '0')
//         {
//             cnt++;
//         }
//     }
// /*     if(cnt>0)
//     {
//         return 1;
//     }else
//     {
//         return 0;
//     }
//      */
//     return cnt;
// }

// /* 考虑在主函数中联合判断控制流交叉调用. */

// /* 一旦调用,就打印最高位,调用条件位len >= 2 并且当前位的数码非零,(利用迭代j=len来实现重复利用.) */
// char* insert_weights(char *buf, int len)
// {
// 	char weight[5][6] = { "十","百","千",   "万" };//这个东西不太灵活,就放在函数里定义即可.
// 	strcpy(buf, weight[len - 2]);//weight[strlen(a) - 2 - i] 列地址.
// 	return buf;

// }
// char * change_to_Chinese_character(char str_i, char* buf)
// {
// 	/* 用gcc编译一个程序的时候出现这样的警告:
// 	warning: control reaches end of non-void function

// 	它的意思是:控制到达非void函数的结尾。
// 	就是说你的一些本应带有返回值的函数到达结尾后可能并没有返回任何值。
// 	这时候,最好检查一下是否每个控制流都会有返回值 */
	// switch (str_i)
	// {

	// case '1':
	// 	strcpy(buf, "一");
	// 	break;
	// case '2':
	// 	strcpy(buf, "二");
	// 	break;
	// case '3':
	// 	strcpy(buf, "三");
	// 	break;
	// case '4':
	// 	strcpy(buf, "四");
	// 	break;
	// case '5':
	// 	strcpy(buf, "五");
	// 	break;
// 	case '6':
// 		strcpy(buf, "六");
// 		break;
// 	case '7':
// 		strcpy(buf, "七");
// 		break;
// 	case '8':
// 		strcpy(buf, "八");
// 		break;
// 	case '9':
// 		strcpy(buf, "九");
// 		break;

// 	case '0':
// 		strcpy(buf, "零");
// 		break;

// 	default:
// 		break;

// 	}
// 	return buf;

// }

//*主函数一般有输入输出(scanf("",& );以及输出:(printf("", ); ))
/*
以下函数(版本只能处理不带零的数字.)
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

    //在此下方插入自定义函数对的声明:
void change_to_Chinese_character(char *a,char (*b)[6]);
void insert_weights(char* a, char (*b)[6]);
void deal_with_0(char (*b)[6]); 
*/

//第二维的维数需要被给出.//当传入的是二维数组的数组名

//作为形参的时候,被必要区分 char**和char*[],它们都被机器处理为char**,即前者.

//主函数main
// int main()
// {
//     char str[5];/* 读入的阿拉伯数子不超过9999 */
//     while( scanf("%s",str) != EOF)
//     {

//         //char weight[5][6]={    "十","百","千",   "万"};/* 存放权:各十百千万(每个汉字占4个字节左右(待定)) */
//         char numerical_character[10][6] = {"一","二","三",,,,,};
//         char result[10][6] = {0};/*  */

//         change_to_Chinese_character(str,result);
//         insert_weights(str, result);
//         void deal_with_0(result);
//         /* change_to_Chinese_character(str,result);
//         void change_to_Chinese_character(char *a,char **b);
//         // note: expected 'char **' but argument is of type 'char (*)[6]' */
//         /* 所谓的二维数组名就是char (*)[6] (指向一维char型数组的 指针)*/

//         /*测试权重数组是否保存正常.
//         for(int i = 0 ;i<5;i++)
//         {
//             printf("%s\n",weight[i]);
//         }
//         */
// //printf("test:\n");

//        for(int i = 0 ;i<strlen(str) * 2 - 1;i++)//strlen(有待商榷)//也可以打个补丁把result阶段'\0'
//         {

//             printf("%s",result[i]);
//         }
//         printf("\n");
//     }

//     return 0;
// }
//     //在下方编写自定义函数:

//     /* C语言利用函数"返回"字符串
//     1.将参数字符串修改掉(void)
//     2.传入一个保存结果的字符串,将处理结果写在该字符数组里(void) */
// void deal_with_0(char (*b)[6])
// {

// }
// void insert_weights(char* a, char (*b)[6])
// {
//     char weight[5][6]={    "十","百","千",   "万"};//这个东西不太灵活,就放在函数里定义即可.
//     for(int i = 0;i<strlen(a) -1;i++)
//     {
//         strcpy(b[2*i+1] , weight[strlen(a) - 2 - i]);//weight[strlen(a) - 2 - i] 列地址.

//     }
// }
// void change_to_Chinese_character(char *a,char (*b)[6])
// {
//     for (int i = 0; i < strlen(a);i++)
//     {
//         switch (a[i])
//         {
//             /* switch 内部的break只是跳出switch的*/
// /*
//         case '1':
//             strcpy(*b, "一");//b行指针,*b就是列指针了:这一点与b[0]相同.
//             break;
//             这里是否又说明了行指针和列指针的区别
//             */

//         case '1':
//             strcpy(b[2 * i], "一");/* 变址运算符[],第b行指针,*b就是列指针了:这一点与b[0](列指针)相同.,但这里的switch要被重复利用,不可用常数来定位置 */
//             break;
//         case '2':
//             strcpy(b[2 * i], "二");
//             break;
//         case '3':
//             strcpy(b[2 * i], "三");
//             break;
//         case '4':
//             strcpy(b[2 * i], "四");
//             break;
//         case '5':
//             strcpy(b[2 * i], "五");
//             break;
//         case '6':
//             strcpy(b[2 * i], "六");
//             break;
//         case '7':
//             strcpy(b[2 * i], "七");
//             break;
//         case '8':
//             strcpy(b[2 * i], "八");
//             break;
//         case '9':
//             strcpy(b[2 * i], "九");
//             break;
//         case '0':
//             strcpy(b[2 * i], "零");
//             break;
//         default:
//             break;
//         }
//     }
// }

/*       */
/* 
现在有三根相邻的柱子,标号为A,B,C,A柱子上从下到上按金字塔状叠放着n个不同大小的圆盘,现在把所有盘子一个一个移动到柱子C上,并且每次移动同一根柱子上都不能出现大盘子在小盘子上方,请输出实现最小移动次数的方案。
盘子不超过20

输入
多组数据,每组一个整数n
输入0 结束

输出
输出最少步骤数

样例输入
1
2
3
0
样例输出
1
3
7 */
/* 做这道题还是花了不少心思:
1.模型抽象:将盘子的大小抽象为数字的大小,这样表示和画草图比较方便和直观.
2.考虑了贪心的策略:直接抽出放置需要的最理想步骤(最后没用上,但和递归还是有所联系)
3.考虑了递推(递归):解决更大规模的f(n)时尝试和f(n-1)或者时更小规模的已解决的f(x)建立方程(递推关系);为了之后的推理清晰,再重申一下f(x)含义:
f(x)是指:在含有x(或则更多的盘子的柱子上),将x个盘子都搬到另一个柱子(这个柱子为空(视为无穷大)或者它已有的盘子级别>x),所需要的步骤数
    事实上,递推的方法中含有基本的的迭代(参数迭代) 
4.情景逆推:(假设前头的准备工作已经执行就绪),放入C柱子的第一个盘必须时最大的,我们就考虑在放置这个最大盘到C柱时三柱的盘子分布形式
位 各柱子上的盘个数:{n-1,1,0}对应的排放状况(记为状态p1): ( 1~n-1,n,C(0(空))),其中A/B等地位!(三角);从这个状态开始操作到全部完成(在C柱上(1~n的排列)),需要+1+f(n-1)次操作;
  那么在状态p1中的(1~n-1)这个柱子如何得到?任然借助小规模已解决的f(x)来处理:它可以由A柱(1~n)通过f(x= n-1)次操作,来达到p1状态
5.综合p1状态之前的需要f(n-1)次,p1之后需要  1+f(n-1) 次,则f(n) = 1 + 2f(n-1);
6.优化位通向公式:借助数列知识:通过配凑,1/2(2f(n) + m) = (2f(n-1) + m);联立5中的原始方程,解得m = 2;...f(n) = 2^n-1; 
}
*/
/* 公式优化版:
 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

    //在此下方插入自定义函数对的声明:

//主函数main
int main()
{
        int n;
        int f;

       // while (scanf("%d", &n) != 0)//错误.
       
        //f(n);
        while (scanf("%d", &n) , n != 0)//&& n != 0
        {
            f = pow(2, n) - 1;
            printf("%d\n", f);
            
        }

        return 0;
        return 0;
} 
/*
#include <stdio.h>
#include <string.h>
    //在此下方插入自定义函数对的声明:
int f(int );
//主函数main
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    //f(n);
     printf("%d\n",f(n));
    return 0;
} 
    //在下方编写自定义函数:
int f(int n)
{
    if(n == 1)
    {
        return 1;
    }
    return f(n-1) * 2 + 1;
} */

/* 某数列为K(n)的定义为:用递归的方法求该数列的第x项k(x)。

           1              n=1
 k(n)=    k(n-1)×2       n为偶数
          k(n-1)×3       n为奇数
输入
x(若x小于1输出input data error!)

输出
k(x)=

样例输入
1
2
0
样例输出
k(1)=1
k(2)=2
input data error!

 */

// #include <stdio.h>
// #include <string.h>
// //在此下方插入自定义函数:
// int k(int x);
// int x_is_odd(int x);
// int x_is_even(int x);
// int main()
// {
//         int x;
//     while (scanf("%d",&x) != EOF)
//     {
//         if(x < 1)
//         {
//             printf("input data error!\n");
//         }
//         else
//         {
//         printf("k(%d)=%d\n",x,k(x))  ;
//         }
//     }
// //printf("test_2:\n");
//    // scanf("%d",&x);//&x
//     return 0;
// }
/*主递归函数.*/
// int k(int x)
// {
//     if(x%2 == 0)
//     {
//        return x_is_even(x);

//     }
//     else
//     {
//        return x_is_odd(x);

//     }
// }
/*处理奇数情况.*/
// int x_is_odd(int x)//odd 奇数的:
// {
//     int x_is_even(int x);/*可能需要调用处理偶数参数的函数*/
//     if(x == 1) return 1;

//     //int k;
//     //x_is_odd(x);
//    /*  k = x_is_odd(x-1) * 3;
//     return k; */
//     return x_is_even(x-1) * 3;
// }
/*处理偶数情况*/
// int x_is_even(int x)//even 偶数的:
// {
//     int x_is_odd(int x);/*可能需要调用处理奇数参数的函数*/
//     if(x == 1) return 1;

//     //int k;
//     //x_is_odd(x);
//    /*  k = x_is_even(x-1) * 2;
//     return k; */
//     return x_is_odd(x-1) * 2;
// }

/* 输入两个正整数m和n(m≥1,n≤10000),
从小到大输出
m~n(包括m,n)之间的所有完数。

完数就是因子和与它本身相等的数。
要求定义并调用函数factorsum(number),它的功能是返回number的因子和。
例如:factorsum(12)的返回值是16,即1+2+3+4+6。

输入
10 500

输出
28 496

样例输入
1 20
样例输出
6 
*/

// #include <stdio.h>
// #include <string.h>
// int ispernum(int);
// int factorsum(int );
// int main(){
//     int m,n;
//     scanf("%d%d",&m,&n);
//     for(int i = m;i<=n;i++)
//     {
//         if(ispernum(i))
//         {
//             printf("%d ",i);
//         }
//     }

//     return 0;
// }
// /* 返回num的因子之和:(不要求式质因子) ,不会有重复加的问题*/
// int factorsum(int num)
// {
//     int sum = 0;//计数器一定要初始化.
//     for(int i = 1;i<num ;i++)/* 不包括num本身的因子 */
//     {
//         if(num % i == 0)
//         {
//             sum += i;
//         }
//     }
//     return sum;
// }
// int ispernum(int p)
// {
//     int factorsum(int num);
//     if(p == factorsum(p))
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }

// }
/* 编写函数num(int m,int k,int xx[])将大于正整数m且紧靠m的k个素数存入数组xx中,并在main函数中将这个数组中的元素输出。

输入
输入正整数m和k。

输出
输出数组中的所有元素。

样例输入
30 6
样例输出
31
37
41
43
47
53
// 提示 */
// #include <stdio.h>
// #include <string.h>
// void num(int m,int k,int xx[]);
// int prime(int n);
// int main(){
//     int m,k;
//     int xx[1000];/* 如果不给[]填充长度值,会说:不允许使用不完整的类型. */
//     scanf("%d%d",&m,&k);/* 如果缺少scanf会怎么样,经常会进入类似于死循环的输出.因为刚定义的整数而未初始化的是非常大整数 */

//     num(m,k,xx);
//     for(int i = 0;i<k;i++)
//     {
//         printf("%d\n",xx[i]);
//     }
//     return 0;
// }
// void num(int m,int k,int xx[])
// {
//     int prime(int n);
//     int end = 0;
//     int j = 0;
//     for(int  i = 1;end < k;i++)/* 结束条件是end数值达到k 即end == k跳出 */
//     {
//         if(prime(m+i))
//         {
//             xx[j++] = prime(m+i);
//             /* (遍历)筛选合格元素填充到数组里的操作往往要在循环变量之外在定义个数组下标变量,以免出现空洞. */
//             end ++;
//         }
//     }
// }
// int prime(int n)
// {
//     if(n == 1 || n == 0)
//     {
//         return 0;
//     }
//     // 判断4及之后的自然数 4之前默认使prime
//     for(int i = 2;i*i < n+1;i++)
//     {
//         if(n%i == 0)
//         {
//             return 0;
//         }
//     }
//     return n;
// }
/* gcd函数(低级的短除法) */
/* 
#include <stdio.h>
#include <string.h>
int gcd(int,int);
int main(){
    int a,b;
    //printf("test_1:\n");
    scanf("%d%d",&a,&b);
    printf("%d",gcd(a,b)) ;

    return 0;
} 
//(短除法gcd函数:
int gcd(int a,int b)
{
    int s = 1;
    for(int i = 2;i <= a && i <= b;i++)//这里的a,b会不会受到内部值更改的影响呢?
    {
        //int gcd = 1;//名称变量名和函数名取一样,可否?
        //int s = 1;定义在这里看不见了
        if(a%i == 0 && b%i == 0)
        {
            //gcd *= i;
            s *= i;
            a /= i;
            b /= i;

            i = 2;//K&R的手法,这句话使得上头的for可以重复利用(迭代 递归.)
        }
        
    }
    return s;
} */


/*函数的嵌套与定义小探究: */
/*
#include <stdio.h>
#include <string.h>
void print1();
void pirnt2();
int main(){
    print1();
    return 0;
}
void print1()
{   
    //void print2();//函数嵌套调用需要在内部声明一下如果把这句话注释掉,会出错
    void print2();
    printf("test1:\n");
    print2();

}
void print2()
{
    printf("test2:\n");
} */


/*  输入
超大数相加.
第一个数字M代表接下来有几组数据;

接下来每一组数据包含两个数据,数字很大哦;
确保没有前缀0,数据很大;

输出
输出计算后的结果,每个结果占一行;

样例输入
3
123 456
1234567890987654321 9876543210123456789
nnnnnnnnnnnnnn1 nnnnnnnnnnnnnnn
样例输出
579
nnnn10nnnn10
122222222222222222222222222222
*/

/* 解决这个问题需要处理的小问题:
1.如何存储很长的数字(类型的变量存不了几十位长的整数!)
2.如何将存储的数据以合适的方法取出来,进行计算 
*/
/* 下面用的方法是啰嗦的,但是明确了:往字符数组里填充某个整数,该整数会被视为某个字符的ascii码值.
而往整形数组里填充整数,那存进去的就是整数本省(吗?)
探究了如何从整数存到字符数组,如何从字符数组提取出一位(叫数码吗?)整数(0~9范围的)(相差48/'0')
对与0有关的数组的初始化往往会漏带掉导致随机值的莫名其妙
同一数组使用strcpy是十分不建议的. */
// #include <stdio.h>
// #include <string.h>

// // 返回字符串?/指向字符串的指针? char strlonger();
// int main(){

// //printf("test_4\n");
//     int n;
//     while(scanf("%d",&n) != EOF)
//     {
//         for(int i = 0;i<n;i++)
//         {
//             char recieve_big_number_1[10000];//数组不够大可能无法输出结果/
//             char recieve_big_number_2[10000];
//             char sum_up[10000];
//             scanf("%s%s",recieve_big_number_1,recieve_big_number_2);/* 暂且 将输入大数视为字符串 存入字符数组. */

//             int dif;/*差值difference */

//             char *big;
//             char *small;//char (*small)[100];small = recievi_big_number_1,到底哪种形式可行呢?

//             int len_small;
//             int len_big;
//             int up = 0;
//             /* 判断那个数大 ,使用abs的话会简洁些*/
//             if(  ( dif =  strlen(recieve_big_number_1) - strlen(recieve_big_number_2) )  >= 0)
//             {
//                 big = recieve_big_number_1;
//                 len_big = strlen(big);
//                 small = recieve_big_number_2;
//                 len_small = strlen(small);
//             }
//             else
//             {
//                 big = recieve_big_number_2;
//                 len_big = strlen(big);
//                 small = recieve_big_number_1;
//                 len_small = strlen(small);
//                 dif = -dif;
//             }

//             strcpy(&sum_up[1],big);/* 试图空出sum_up[0]这个可能的最高位. (该操作确实可行) */
//             /* 当然,这样sum_up[0]的值是随机的,你以选择初始化,当然这题不必须,因为输出的为可能1.从[1]开始输出;2.[0]会被进位值覆盖(为1) */

//             /* 位置对齐(其实这件事并不必要
//             ,当然,它对于连锁进位还是提供了方便):
//             但还可以调整填入sum_up的顺序来(高位往后填充,再逆序从高到低输出.)这就无需对齐
//             事实上,逆(反)序填充,正序输出的手段可以减少很多的不必要的工作量(输出方式是很灵活的),
//             考试的话前者的定位更合适,平时我们正序排列还正序输出只是为了试验某些知识点,检验思维漏洞(这还未必能办到,就不要死磕)*/
//            /* 版本一有巨大缺陷 */

//             // if(dif > 0)
//             // {
//             //     int j = 0;
//             //     for(int i = 0;i<len_small;i++)
//             //     {
//             //         // 调试时,若看指针的话,只能看到首地址对应元素的变化,更应该观察的是指针所指的源数组的被间接改变的结果
//             //         /*考虑dif== 0, */
//             //         small[i+dif] = small[i];
//             //         //small[i] = '0';这么些的话,前面一串都被赋值为0.考虑另用一个互不干扰的变量
//             //         if(j<dif)
//             //             small[j++] ='0';//'0'就是48啦.(int)

//             //     }
//             //     small[len_small] = '0';  //这句话有待商榷:
//             // }
//             /* 版本2 */
//             //

//            // strcpy(small[len_big - len_small],small);////这里是为什么?处理较长的的输入是就会报错segmentation fault
//             /* 在同一个字符串中使用strcpy有哪些风险? */
//             for(int i = 0;i<len_small;i++)
//             {
//                 /* 如同交换两个变量的值,为了避免重叠的问题,还应开一个buf // 或者考虑从后面的字符开始挪,可以避免重叠造成覆盖,数据丢失*/
//                 /* 值得一提的是,类似的操作再不同的顺序安排下可能产生巨大的不同 */
//                  small[len_small - 1 - i+dif] = small[len_small -1 -i] ;
//             }
//             for(int i = 0;i<len_big -len_small;i++)//可以考虑使用字符串函数.
//             {
//                 small[i] = '0';
//             }
//             /* 打个补丁否则某些例子会使下面len_small 重新计算时出现偏差. */
//             small[len_big] = '\0';
//             /* 对齐后刷新len_small */
//             len_small = strlen(small);/* 虽然也可以直接用len_big赋值给len_small ,可以不要补丁了*/

//         /* 将字符转化为数字 */
//         /* int big_last;
//             big_last = (int)big[len_big-1] - 48; */
//             //test将会是存入的数字字符的ASCII值,然而,
//             //由于ASCII值具有良好的递增规律,-48就可以转换为输入的数字大小了
//             //printf("%d",test);

//             /* 小学的按位加法(及进位) */

//             for(int i = 0;i<len_big /* && i<len_small */;i++)/*   i 类似(前移)改变量 */
//             {   /* 以下可以得到迭代 */

//                 int signal_add_i = 0;
//                 /* signal_add_i本身不依赖于对齐 */

//                 signal_add_i = (int)big[len_big-1 - i ] - 48  +  (int)small[len_small-1 -i] - 48 + up ;
//                 up = 0;/* 加完进位,使得进位记录器up归零,否则up回不去了 */
//                 /* 如果发生进位 */
//                 if( signal_add_i >= 10)
//                     {
//                         up = 1;
//                         /* int fill_sum_up;
//                         fill_sum_up = (char)(signal_add_i / 10) + 48;
//                         sum_up[len_big - i ] = fill_sum_up; */
//                         int fill_sum_up;
//                         fill_sum_up = (signal_add_i % 10) + '0';
//                         sum_up[len_big - i ] = fill_sum_up;

//                     }
//                     /* 若不发生进位 */
//                 else
//                     sum_up[len_big - i ] = signal_add_i + '0';

//             }
//             //
//             if(up == 1) /* 我竟然写成了赋值号 =  */
//             {
//                 sum_up[0] = '1';
//                 printf("%s\n",sum_up);
//                 //printf("\n out1 :    %s\n",sum_up);//更清楚输出

//             }

//                 //if(up = 1) sum_up[len_big - len_small - 1] +=  1;
//                 /* 打印的时候分个类(首位是否被进位) */
//             else
//                 printf("%s\n",&sum_up[1]);   /* 非首地址,需& */
//                 //printf("\n out2:       %s\n",&sum_up[1]);
//         }

//     }
//     return 0;
// }

/* 另一个版本 */
// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     int n;
//     /*      这块代码不可放在外部(测试多组数据时,有残留)
//             char s1[100], s2[100];

//             再开一对整形数组,存储接受的字符串所转化成的整形数据,即提取各位上的数码,便于运算.而且不会破坏输入数据
//             int num1[31], num2[31], len1, len2, i, j;
//             */
//     //printf("test\n");
//     while (scanf("%d",&n) != EOF)
//     {

//         for (int i = 0; i < n; i++)
//         {

//          //这块代码不可放在外部(测试多组数据时,有残留)
//             char s1[10000], s2[10000];

//             //再开一对整形数组,存储接受的字符串所转化成的整形数据,即提取各位上的数码,便于运算.而且不会破坏输入数据
//             int num1[10000], num2[10000], len1, len2, i, j;

//             /* 快速初始化数组memset(从内存的角度)
//         第一:memset函数按字节对内存块进行初始化,
//         所以不能用它将int数组初始化为0和-1之外的其他值(除非该值高字节和低字节相同)。*/
//             scanf("%s%s", s1, s2);
//             memset(num1, 0, sizeof(num1));
//             memset(num2, 0, sizeof(num2));
//             //printf("please int fist number\n");

//             //printf("please int secound number\n");
//             //scanf("%s", s2);
//             len1 = strlen(s1);
//             len2 = strlen(s2);

//             /* 两个控制变量,实现交叉填充 */
//             for (i = len1 - 1, j = 0; i >= 0; i--)
//             {
//                 num1[j] = s1[i] - 48; //从字符到整数的转换(0~9),并且填充到整形数组
//                 j++;
//             }

//             for (i = len2 - 1, j = 0; i >= 0; i--)
//             {

//                 num2[i] = s2[j] - 48;
//                 j++;
//             }
//             /* (len2 > len1 ? len2 : len1)的运算结果是len2和len1的较大值,十分紧凑 */
//             for (i = 0; i < (len2 > len1 ? len2 : len1); i++)
//             {
//                 /* 将相加的结果保存到num1里 */
//                 num1[i] += num2[i];
//                 /* 如果需进位 */
//                 if (num1[i] > 9)
//                 {
//                     num1[i + 1] += 1; /* 迭代高一位的数码,让其+1 */
//                     num1[i] -= 10;    /* 留下个位,放在当其位置 */
//                 }

//             } /* 最高位的情况(是否进位,以及填充到适当的位置 还需单独判断下: */
//             /* 上头的i++在跳出for是已经移位都最高位(如果进位的话) */
//             /* 最低位放在num1数组的最前面,这样方便处理未知的最高位,届时逆序输出即可(从后往前打印(高位-->低位)) */
//             if (num1[i]) /* 最高位是否1(此时的num1[i]只为1/0 (1是低位进上去的;0则是之前memset()初始化的值,且没有进位)) */
//             {
//                 for (j = i; j > -1; j--) /* 或说:j >= 0 */
//                     printf("%d", num1[j]);
//                 printf("\n");
//             }
//             /*不进位:  */
//             else
//             {

//                 for (j = i - 1; j > -1; j--)
//                     printf("%d", num1[j]);
//                 printf("\n");
//             }

//         }
//     }

//     return 0;
// }

/* sum_of_factors因子之和/月老? */

//输入数据的第一行是一个数字T(1<=T<=500000),它表明测试数据的组数.
//然后是T组测试数据,每组测试数据只有一个数字N(1<=N<=500000).
// #include<stdio.h>
// #include<math.h>
// #include<string.h>
// #include<math.h>

// //#include<algorithm>
// //using namespace std;
// //#define M 30007
// //#define inf 9999
// int a[500000];
// int main()
// {
//     for(int i=1;i<=50;i++) a[i]=1;//初始化各个计数器

//     for(int i=2;i<=25;i++){//创建字典的过程没用使用if语句!
//                     printf("(i ex) = %d\n",i);

//         for(int j=i*2 /*每次进入循环的时候做(作用一次)一次初始化*/
//          ;j<=50; j+=i/*通常改变循环变量的语句放置在for(括号里,
//          而非执行语句{里})*/)

//          {
//             //子循环变量j的更迭依赖于父循环变量i
//             //j从2x2开始,
//             /*

// */
//                     printf("(i in) = %d ",i);
//                     printf("j = %d ",j);
//             a[j]+=i;//在该结果上加上因子
//                     printf("a[j] = %d\n",a[j]);

//         }
//     }//为循环添加调试语句是,要注意添加大括号!
//  //测试组数的套路:int t ,scanf(&t),while{int n,scanf(&n)}
//     int t;
//     scanf("%d",&t);
//     while(t--)
//     {
//         int n;
//         scanf("%d",&n);
//         printf("%d\n",a[n]);/*!!利用数组储存住计算过的数据,减少重复计算(比如
//         输入的几个数据中有重复的(相同的))*///字典.
//     }
//     return 0;
//     getchar();

// }

// ————————————————
// 版权声明:本文为CSDN博主「hy1405430407」的原创文章,遵循 CC 4.0 BY-SA 版权协议,转载请附上原文出处链接及本声明。
// 原文链接:https://blog.csdn.net/hy1405430407/article/details/46343609
/* test_getline and copy */
// #include <stdio.h>
// #define MAXLINE 1000
// int getline(char line[],int maxline);
// void copy(char to[],char from []);
// main ()
// {
//     int len;/*当前行的长度*/
//     int max;    /*目前发现的最长行的长度*/
//     char line [MAXLINE];/*当前的输入行*/
//     char longest [MAXLINE];/*用于保存最长行*/

//     max = 0;

//     while ((len = getline(line,MAXLINE)) > 0)/*遍历读入的行*/
//     {
//         if (len > max )
//         {
//             max = len;
//             copy(longest,line);
//             //printf("%d",len);
//         }
//     }

//     if ( max > 0){
//         printf("%s",longest);
//     }

// }

// int getline(char s[],int lim){
//     int i ,c;

//     for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
//         s [i] = c;
//     }
//     if (c =='\n'){
//         s [i] = '\n';
//         ++i;
//     }
//     s [i] = '\0';
//     //printf("%s",s);
//     return i ;
// }

// void copy(char to[] , char from[]){
// 	int i;

// 	i = 0;

//     while ((to [i] = from[i] )!= '\0'){ //千万要小心的是,含有赋值表达式的复合判断句,
// 										//要考虑到运算优先级,发返回的值是0/1,又或是字符串//
//         ++i;/*定义再while内部的步长。*/
//     }
// }

/* k&R:test _of_EOF */
//#include <stdio.h>
//main()
//{
//    int c;
//    while (c = getchar() != EOF)//getchar()还可以读入enter(\r)
//
//        printf("%d\n",c);
//
//
//    //printf("%d - at EOF\n",c);
//
//
//}
/*
#include <stdio.h>
main()
{
    printf("EOF is %d\n ",EOF);
}
*/
//#include <stdio.h>
// main()
//{
//    long nc;
//
//    nc = 0;
//    //while(getchar() != EOF)
//       // ++nc;
//    c = getchar();
//    printf("%s",c);
//    //printf("%ld\n",nc);

//  double nc;
//  for(nc = 0; getchar() != EOF;++nc)  //换行再ctrl+z+Enter 结束
//  	;
//  printf("%.f",nc);

//#include <stdio.h>
//#define NONBLANK 'a'//声明字符变量也需要再main之前。
// main()
//{
//
//
//
//	int c,lastc;
//	lastc = NONBLANK;
//	while ((c = getchar()) != EOF){
//		if(c != ' ')
//			putchar(c);
//		else if(lastc !=' ')
//			putchar(c);
//		lastc = c;//刷新lastc 核心。
//	}
//
//
//
//
//}

//#include <stdio.h>
//main()
//{
//	int c;
//	while ((c = getchar()) != EOF){
//		if (c =='\t')
//			printf("\\t") ;//既可以\t,也可以按Tab键
//		else if (c == '\\')
//			printf("\\\\") ;
//		else if (c == '\b')
//			printf("\\b") ;//需要手动输入\b
//		else
//			putchar
//			(c);
//			//注意,这里的c不是字符,而是ASCLL值,在输出的时候会转换为字符本身。;
//
//	}
//
// }

//#include <stdio.h>
//#define IN 1
//#define OUT 0
//main(){
//	int nc,nl,nw,state,c;//注意这里的c是为接受getchar()而准备的
//	state = OUT;
//	nc = nw = nl =0;
//	while((c = getchar()) != EOF){  	//getchar()  后面的括号()别再忘记了！
//										//虽然“c = getchar()”整个表达式外有无括号对while的测试条件的真假不影响。
//										//但是如果要利用c的具体值来代表字符(ASCALL),就得加(),否则c返回的都是1或一个0
//
//
//		++nc;
//
//		if (c == '\n')
//
//			++nl;
//
//		else if (c == '\n' || c == '\t' || c == ' ')//(if 或者else if都无伤大雅
//			state = OUT;
//		else if (state == OUT){		//执行语句超过两行,一定要{},否则废了(宁可多家,也不可少加
//								//这里看似明知故问,但是却十分必要,
//							//以等带输入的字符流遍历到下一个单词分隔符
//			state = IN;
//			++nw;
//		}
//
//	}
//	printf("%d %d %d",nl,nw,nc);
//
//}

/* test_of_histgram */
/* 
#include <stdio.h>
#define MAXHIST 15
#define MAXWORD n
#define IN 1
#define OUT 0
main()
{
	int c,i,nc,state;
	int len;
	int maxvalue;
	int ovflow;
	int wl[MAXWORD];
	
	state = OUT;
	nc = 0 ;
	ovflow = 0 ;
	for (i = 0; i < MAXWORD; ++i)
		wl[i] = 0;
	while ((c = getchar()) != EOF){
		if (c == ' '||c == '\n' || c == '\t'){
			state = OUT;
			if(nc > 0){
				if (nc < MAXWORD){
					++wl[nc];
				}else 
					++ovflow;
			nc = 0;
			}
		}else if(state == OUT){	
			state = IN;
			nc = 1;
		}
		 else 
		 	++nc;
		 	
	}
	maxvalue = 0;
	for (i = 1;i <MAXWORD; ++i)
		if (wl[i] > maxvalue)//maxvalue(最高频数,而非最长单词)是没有限制的 
			maxvalue = wl[i];
	//printf("%d",maxvalue);/*
	for (i = 1;i < MAXWORD; ++i){
	
		printf("%5d - %5d",i,wl[i]);
		if(wl[i] > 0){
			
			//printf("\tlen = %d",wl[i] * MAXHIST);
			if ((len = wl[i] * MAXHIST/maxvalue) <= 0){
				len = 1; //		15		10/这里已经完成了对len的表达式定义 	wl[i] / maxvalue(是<=1的) 
							//当然了,如果maxvalue比较小,(max value<	MAXHIST) 那么len会以较大的*号数作为基础输出 
			//这里只是看比例,而不是看数目。 
			 wl[i] * MAXHIST/maxvalue;
			
			
			  ;		//len = wl[i] * MAXHIST/maxvalue(再if语句内部定义也是合理的) 
				 
			}else  
			//	printf("\t len = %d",len) ;
			
			while (len >0){
				putchar('*');
				
				//printf("len = %d",len) ;
				
				--len;
			}
			
			putchar('\n');
					
		}
	}
	if (ovflow > 0){
		printf("there are %d words >= %d\n",ovflow,MAXWORD);	
	}
	
} */
/* test_of_histgram_2 */
/* 
#include <stdio.h>
#define MAXHIST 15
#define MAXWORD n
#define IN 1
#define OUT 0
main()
{
	int c,i,j,nc,state;
	int len;
	int maxvalue;
	int ovflow;
	int wl[MAXWORD];
	
	state = OUT;
	nc = 0 ;
	ovflow = 0 ;
	for (i = 0; i < MAXWORD; ++i)
		wl[i] = 0;
	while ((c = getchar()) != EOF){
		if (c == ' '||c == '\n' || c == '\t'){
			state = OUT;
			if(nc > 0){
				if (nc < MAXWORD){
					++wl[nc];
				}else 
					++ovflow;
			nc = 0;
			}
		}else if(state == OUT){	
			state = IN;
			nc = 1;
		}
		 else 
		 	++nc;
		 	
	}
	maxvalue = 0;
	for (i = 1;i <MAXWORD; ++i)
		if (wl[i] > maxvalue)//maxvalue(最高频数,而非最长单词)是没有限制的 
			maxvalue = wl[i];
			
	for (i = 1; i < MAXWORD; ++i)
		printf("%5d",wl[i]);		
	putchar('\n');	
		
	for (i = MAXHIST;i > 0 ; --i){
		for ( j = 1;j < MAXWORD; ++j )
			if (wl[j] *  MAXHIST/maxvalue >= i)
				printf("%5s","*");//这是打印即兴字符的方法。 
			else
				printf("%5s"," ");
		putchar('\n');
	}

	for (i = 1; i < MAXWORD;++i)
		printf("%5d",i);
	putchar('\n');
	
	for (i = 1; i < MAXWORD; ++i)
		printf("%5d",wl[i]);		
	putchar('\n');
	if (ovflow > 0){
		printf("there are %d words >= %d\n",ovflow,MAXWORD);
		
	}
	
}
 */
/* 

#include <stdio.h>
main()
{
	int c,i,nwhite,nother;
	int ndigit[10];
	int test;
	
	//初始化各个统计量,而数组的各个量通过for,做变量。 
	//写错单词,伤！ 
	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0; 
	while ((c = getchar()) != EOF)
		if (c >= '0' && c <= '9'){//于while不同的是,if 执行语句超过两行,一定要{},否则废了(宁可多家,也不可少加
			 //小心c >='0',而非<='0' ,否则进不了循环。 
		
			++ndigit[c - '0'];//对数组进行迭代更新。
			//printf("ndigit[c - '0'] is: %d",test)  ;
		}
			
		else if (c == ' '||c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;
			
	//打印ndigit,也是遍历打印出来 
	printf("digits = ");
	for (i = 0; i < 10; ++i)   //这里的++符号已经指定步长为1,不要再添加1了,除非你写作i += 1 
		printf(" %d",ndigit[i]);
		
	printf(",white space = %d,other = %d\n",
	nwhite,nother);
		
 } 
  */

/* K&R:EOF */
// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int c;
//     while (c = getchar() != EOF)
//     {
//         printf("%d\n",c);

//         /* code */
//     }
//     printf("%d - at EOF\n",c);

// }

/* #include <stdio.h>
main()
{
    printf("EOF is %d\n ",EOF);
    
}
 */

//3
/* 
#include <stdio.h>
main()
{
    long nc;
    while(getchar != EOF)
        ++nc;
    printf("%d\n",nc);
    
}




#include <stdio.h>
main()
{
	int c,i,nwhite,nother;
	int ndigit[10];
	int test;
	
	//初始化各个统计量,而数组的各个量通过for,做变量。 
	//写错单词,伤！ 
	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0; 
	while ((c = getchar()) != EOF)
		if (c <= '0' && c <= '9')
			test = ++ndigit[c - '0'];//对数组进行迭代更新。
			
			
		else if (c == ' '||c == '\n' || c == '\t')
			   ++nwhite;
		else
			++nother;
			
	//打印ndigit,也是遍历打印出来 
	printf("digits = ");
	for (i = 0; i < 10; ++i)   //这里的++符号已经指定步长为1,不要再添加1了,除非你写作i += 1 
		printf(" %d",ndigit[i]);
		
	printf(",white space = %d,other = %d\n",
	nwhite,nother);
		
 } 
  */

/* Problem Description
// 给定序列A={A1,A2,...,An}, 要求  改变序列A中的某些元素,形成一个严格单调的序列B
// (严格单调的定义为:Bi<Bi+1,1≤i<N)。(递增)
// 我们定义从序列A到序列B变换的代价为cost(A,B)=max(|Ai?Bi|)(1≤i≤N)。
// 请求出满足条件的最小代价。


// Input
// 第一行为测试的组数T(1≤T≤10).

// 对于每一组:
// 第一行为序列A的长度N(1≤N≤105),第二行包含N个数,A1,A2,...,An.
// 序列A中的每个元素的值是正整数且不超过10^6。
 
// /* Sample Input
// 2

// 2
// 1 10

// 3
// 2 5 4
 

// Sample Output
// Case #1:
// 0

// Case #2:
// 1 */

// # include <stdio.h>
// # include <stdlib.h>
// int a[10000], n;

// int judge(int num)/* 判断二分取得中间值num(调节Ai的允许变化量范围最大限度)是否能满足题意,假定这个num传入的就是所求的最小代价,,若返回1,则对num减半再检验 */
// {
//     int x = a[0] - num;/*
//     //定义x的时候同时给x初始化个值(表达式)为:a[0] - num(将原序列Ai的值削减掉num,既然假定这个num传入的就是所求的最小代价,那么第一个x<=序列B的最小值
//     并且,对A序列每一个Ai都减去num并不会使得代价cost比 只对某单个Ai元素减去num时的cost变大),另外这时的x允许出现负数 */
//     int y  = 0;
//     for(int i=1; i<n; ++i)/* 以a[0]为基准(作为B序列中的最小值.) */
//     {
//         y = a[i] - num;/* (限制条件)分开写(先后遍历),多个标准同时考虑会使思维混乱 */
//         if(y <= x)
//         {
//             y = x + 1;/* (根据递增要求)来更新y的值(放大y使得它与x相比有最小限度的增大量1(紧),使得满足递增条件同时|Ai?Bi|也最小,要与当前num比较 */
//             if(abs(y - a[i]) > num)//(根据是否满足不超过num) 来检验当前这个num是否够大;y的变化未必连续
//                 return 0;//改变量超过这个num,不符合题意.
//         }
//         x = y;/* 迭代,刷新x,来比较下一个相邻y */
//     }
//     return 1;
// }

// int main()
// {
//     int t, cas = 1;
//     scanf("%d",&t);
//     while(t--)
//     {
//         scanf("%d",&n);

//         for(int i=0; i<n; ++i)
//             scanf("%d",&a[i]);
// //二分取出一系列的mid,传入judge(),直到找到最小的那个cost(即num)
//         int l=0, r=1000000, mid;//left和right边界
//         while(l<r)
//         {
//             mid = (l+r)/2;
//             if(judge(mid))
//                 r = mid;//刷新有边界
//             else
//                 l = mid + 1;//刷新左边界
//         }
//         printf("Case #%d:\n%d\n",cas++, r);
//     }
//     return 0;
// }
// /*
// 改变:比如对调/就地调整大小(当然,前者是后者的特殊情况),此处只考虑调整大小即可
// 进行二分处理,逐个判断可能的答案:
//  编写函数 judge(int num) 来判断当最大代价为num(意思是current)时该序列   是否可以变成严格单调。
// 1.因为输入的每个数都在10^6内,所以答案也在10 ^6内,从10 ^6开始二分。

//     对每个测试数进行测试.必要时削减去num大小来调整成单调(即便
//     是对每一个数进行削减,cost也不会超过num,当然减掉num后可能出现负值,这不碍事)
//    验证时要尽可能让第1个数变得最小,并且让数紧凑。
// 2.二分枚举最大改变量/分摊改变量
// 对于改变量mid,a[0]=a[0]-mid(先尽可能把第一个数变小),然后从第二个数向后判断,
// 先让a[i]=a[i]-mid,如果b[i]<=b[i-1],说明b【i】此时减的过多了,,b[i]=b[i-1]+1(让序列尽可能的紧凑),
// 然后判断abs(a[i]-b[i]),如果>mid, 说明mid过小,返回0,取右区间(较大区间)二分答案;
// 如果for循环结束返回1,说明mid>=最优解,取左区间(较小区间)二分答案。
//    */

/* 编写一个函数,用于接收三角形的底和高,并计算该三角形的面积,将面积作为返回值返回。在main函数中调用求面积的函数,并接收函数的返回值,将求得的面积输出。

输入
输入三角形的底和高。

输出
输出三角形的面积(小数点后保留两位)。

样例输入
10.5,22.34
样例输出
三角形的面积为n7.29 

本题比较简单,值得注意的是scanf(里头的%f,%f要跟上逗号!!
直接将函数的返回值打印出来可以节省一个(少定义一个变量存储变量的结果,当然,如果程序较长,
则还是建议再定义一个变量来接受函数返回值))*/
/* 
#include <stdio.h>
#include <string.h>
float area_of_triangle(float,float);
int main(){
    float bottom_side, height;
    scanf("%f,%f",&bottom_side,&height);

    printf("三角形的面积为%.2f",area_of_triangle(bottom_side,height));

    return 0;
} 
float area_of_triangle(float bottom_side , float height)
{
    float area;
    area = bottom_side * height/2.00;
    return area;

} */
/* 绝对素数是指本身是素数,其逆序数也是素数的数。例如:10321与12301是绝对素数。编写一个程序,求出所有m~n(m≥n,n≤1000)之间的绝对素数。程序要求实现两个自定义函数,prime(n)用于判断一个整数n是否是素数,是则返回1,否则返回0;inv(n)用于对整数n进行逆序,函数返回逆序后的整数。主函数通过调用上述两个自定义函数实现绝对素数的判断和输出。

输入
m n

输出
m~n之间的绝对素数,每个输出整数占5位,每行输出10个

样例输入
n 1000
样例输出
   n   13   17   31   37   71   73   79   97  101
  107  n3  131  149  151  157  167  179  181  191
  199  3n  313  337  347  353  359  373  383  389
  701  709  727  733  739  743  751  757  761  769
  787  797  907  919  929  937  941  953  967  971
  983  991 */

// #include <stdio.h>
// #include <string.h>
// int prime(int);
// int inv(int);
// int main(){
//     int m,n;
//    // printf("test\n");
//     while((scanf("%d%d",&m,&n) != EOF))
//     {
//         int cnt = 0;
//         for(int i = m ; i <= n; i++)
//         {
//             if(prime(i) &&  prime(inv(i)))/* 及时检查下传入的参数是否正当(尤其使多个函数有共同的参数(这错误会有连锁效应) */
//             {
//                 //cnt++;

//                // 每个输出整数占5位,每行输出10个
//                 printf("%5d",i);
//                 if(++cnt%10 == 0) printf("\n");

//             }

//         }

//         //printf()
//     }
//     return 0;
// }
/* 素数prime函数 */
// int prime(int n)
// {
//     if(n == 1 || n == 0)
//     {
//         return 0;
//     }
//     /* 判断4及之后的自然数 4之前默认使prime*/
//     for(int i = 2;i*i < n+1;i++)
//     {
//         if(n%i == 0)
//         {
//             return 0;
//         }

//     }
//              /* 回过头去看1,2,3的情况 */
//     return n;
// }
//整数逆序函数
// int inv(int n)
// {
//     int inv = 0;
//     for(;n > 0;)
//     {
//         inv = (inv) * 10 + n % 10;
//         n /= 10;
//     }

//     return inv;
// }
// #include <stdio.h>
// #include <string.h>
// int main(){

//      int a[100]={1,3,6};/* increment /'??kr?m?nt/ n.增加(增加物, 增量, 余差) */
//      //const int a[100]={1,3,6}//这将导致数组元素不可更改.
//     //a[0] = a[1]++;
//     printf("a[0]=%d",++a[0]);/* 这里的自增对象是a[0],我们说,数组就是批量的定义了一批类型相同的变量并且相邻的排列 */
//     return 0;
// }
/*

#include <stdio.h>
#include <string.h>
int main(){
//printf("test_1\n");
} 
*/
/* 辗转相除法:虽然这个方法着眼于除法和余数,但还是宜从乘除的角度
可否认为:辗转相除就是一个在分解出因数的过程. */
/* 题目如下,输入两个数,如a,b,且a,b是都大于0的整数,a<=b,输出a除以b的结果,
结果用真分数表示,即最简分数。nput:
输入两个数a,b,以EOF结束。

Output:
输出a除以b的结果,结果就分数表示,如,1除以2得1/2,2/4=1/2,如果a等于b,那么输出1。
//简版:


#include <stdio.h>
#include <string.h>

int gcd(int a, int b) {
      
    //如果a,b本身就可以整除或被整除:那么其中一个就是它两的gcd,并且这时候退出递归函数是刚好合适的. 
    同时运气好的话,(a>b),直接输出结果gcd = b;
    if (a % b == 0)
        return b;
        //当一其中的任何一方作为gcd多不可得,那说明两者的较小者还是太大了.需要减小gcd的测试值
        什么样的测试值合适呢,就落在了余数上(取两者某个顺序的模作为新的除数,)

//如果调个顺序就能整除或根本无法直接整除,(现尝试将它们统一起来处理):
//调换位置(a = b;b = a % b(前者好理解,后者:a < b,那么a%b就是a 本身.
其中的两层用意:调换a,b的在函数处理时的相对位置(能够如此简洁地同一器两种情况是a%b的特性好)
; ))
    else 
        return gcd(b, a % b);//传入的参数(b,a%b)是递归得以正确推进的关键(它们必须是会变化的表达式).
}
int main()
{
    int a;
    int b;
    int x;
  
   while (scanf("%d%d",&a,&b) != EOF)
   {
        x = gcd(a,b);
        //if(a<=b);
        if(a == b) printf("1");
        else
        {
        printf("%d/%d\n", a/x ,b/x);
        }
   }
  
} 
 */
/*
#include <stdio.h>
#include <string.h>

//  void swap(int *a, int *b){
//     //int *t;//导致segmentfault,因为指针没有初始化!.    
//     // *t = *a;
//     // *a = *b;
//     // *b = *t;
//     int t;
//     t = *a;
//     *a = *b;
//     *b = t;
// } 
int gcd(int a, int b) {    //欧几里得算法求最大公约数
    if (a % b == 0)
        return b;//最终出口?
    else 
        return gcd(b, a % b);
}
int main()
{
    int a;
    int b;
    int x;
    // int m,n;
    // int  numerator ;
    // int denominator;//分母

    //scanf("%d%d",&a,&b);//又把&号忘了,这将导致调试无法进行(而且由于编译器不知到你的目的还不给(无法)为你你报错,导致疑惑)
   while (scanf("%d%d",&a,&b) != EOF)
   {
        x = gcd(a,b);
        //if(a<=b);
        if(a == b) printf("1");
        else
        {
        printf("%d/%d\n", a/x ,b/x);
        }
   }
  
}  */

/* 随着城市的发展公交车变成了人们日常生活中不可缺少的交通工具,而在高峰期,经常出现公车坐慢的情况。现在假定初始在第一站的时候公车上有k个人,以后每经过一站车上的人先下去一半ki/2(ki除2的整数部分),然后再上ki人,现在已知公车的限乘人数L,假定公车如果不能再上人就(即ki-ki/2+ki >L)的时候公车就开始不再站台停靠了直接开往终点站,求公车最后到达终点站时车上的人数。

Input:
输入数据包括多个测试样例,每个测试样例包含1行,分别为站台的总数N(包含起点终点,起点终点不上下人),初始车上的人数k,和限乘的人数L(10=> n>0,100=>k,l=>1)。 输入数据以三个0 0 0为结尾。

Output:
输出公车最后到达终点站时车上的人数。

Sample Input:
10 2 10
10 0 10
3 8 70
0 0 0 
Sample Output:
8
0
12
Hint:
无比简单的递归  */
/* 
#include <stdio.h>
#include <string.h>

int next(int k);
int main(){
    
   int n,k,l;
   int t;
   int ans;
   //printf("test_1\n");
   //printf("test_2\n");
   while ( scanf("%d%d%d",&n,&k,&l) && n != 0)
   {

      ans = k;
      while (ans<l && n-- - 2 > 0  )
      {
         if(next(k)<l)
         {
            ans = next(k);
            k = ans;
         }
        
      }
    
      printf("%d\n",ans);  
   }
   //printf("%d\n",ans);
   
    return 0;
} 
int next(int k)
   {
      k = 2*k - k/2;
      return k;
   } */
/* #include <stdio.h>
#include <string.h>
int main()
{
	char	*arglist[3];

	arglist[0] = "ls";
	arglist[1] = "-l";
	arglist[2] = 0 ;
	// printf("* * * About to exec ls -l\n");
	// //execvp( "ls" , arglist );
	// printf("* * * ls is done. bye\n");
} */

/* //测试strcpy:覆盖性
# include <string.h>
# include <stdio.h>
void main()
{ 
	 char destination[25] = "te_____________st ";
     //printf("%s\n",destination);//

	 //char blank[]= "",c[]= "C++";
     char turbo[] = "Turbo";
	 strcpy(destination, turbo);//"Turbo"放到destination
     
	//  strcat(destination, blank); 
	//  strcat(destination, c); 
	 printf("%6s\n", destination);
/* 运行结果:
     test
 Turbo
 表明strcpy()会将目标字符串(就内容)给覆盖掉
  */

/* #include <stdio.h>
#include <string.h>
void main(int argc, char *argv[])
{
    printf("test argv in the envirment of vscode:\n");
    while(argc>1)
    { 
        ++argv; 
        printf("%s\n",*argv);
        --argc;
    }
    
} */
/* #include <stdio.h>
#include <string.h>
void swap(char *a,char* b);
int main(){
    char str[100];
    char min;
    gets(str);
    //printf("%s",str);
//    min = str[0];
//printf("test 1");
    for(int i = 0 ; i<strlen(str)-1;i++)
    {
        min = i;
        for(int j = i+1;j<strlen(str);j++)
        {
            if(str[min]>str[j])
            {
                min = j;
            }
        }
        swap(&str[i],&str[min]);
    }
    printf("%s",str);
}

void swap(char* a,char *b)
{
    char str;
    str = *a;
    *a = *b;
    *b = str;
} */
/*指针数组的例子:
#include <stdio.h>
#include <string.h>
int main(){
    int b[2][3],*pb[2];
    int i,j;
    for(i = 0 ;i < 2; i++)
        for(j=0;j<3;j++)
            b[i][j] = (i + 1)*(j+1);
    pb[0]=b[0];
    pb[1]=b[1];
    for(i = 0;i<2;i++)
        for(j=0;j<3;j++,pb[i]++)//列指针,具体到二维数组的各个元素.
            printf("b[%d][%d]:%2d\n",i,j,*pb[i]);
    return 0;
    // b[0][0]: 1
    // b[0][1]: 2
    // b[0][2]: 3
    // b[1][0]: 2
    // b[1][1]: 4
    // b[1][2]: 6

}  */

/* 编制程序,输入n个整数(n从键盘输入,n>0),输出它们的偶数和。

输入
n

n个整数

输出
其中偶数的和

样例输入
10
1 2 3 4 5 6 7 8 9 10
样例输出
30

#include <stdio.h>
int main(){
    int n ;
    int x ;
    int sum = 0;
    scanf("%d",&n);
    for (;n--;){
        scanf("%d",&x);
        if(x%2 == 0)
            sum += x;
    }
    printf("%d",sum);
    

    return 0;
} */
// 题目描述
// 输入10个数,求它们的平均值,并输出大于平均值的数据的个数。

// 输入
// 10个数

// 输出
// 大于平均数的个数

// 样例输入
// 1 2 3 4 5 6 7 8 9 10
// 样例输出
// 5
// #include <stdio.h>
// #define N 10
// int main(){
//     int n = N;
//     float ave;
//     int sum = 0;
//     int a[10] ;
//     int i = 0 ;
//     int u =0 ;
//     while(n--){
//         scanf("%d",&a[i++]);
//         sum += a[i -1];

//     }
//      ave = sum/N;

//      for (i=0; i < 10;i++){
//             if (a[i] > ave)
//      {
//         u++;
//         //printf("%d\n",a[i]);//%d
//      }

//      }

//      printf("%d\n",u);
// }
/* 
计算题
#include <stdio.h>
#include <math.h>
int main(){
    float x;//变量(浮点)
    float y;//函数值(浮点数)

    int n;
    scanf("%d",&n);//读入测试次数&

    for(int i = 0;i < n;i++){
        scanf("%f",&x);
        if (x<-2) y = x*x-sin(x);
        else if (x >= -2 && x <= 2) y = pow(2,x)+ x;
        //else y =pow( x*x + x + 1,0.5);
        else y = sqrt(x*x + x + 1);
        printf("%.2f\n",y);
    }


} */
/* 输入1个四位数,将其加密后输出。方法是将该数每一位上的数字加9,然后除以10取余,做为该位上的新数字,最后将第1位和第3位上的数字互换,第2位和第4位上的数字互换,组成加密后的新数。

输入
1257

输出
4601

样例输入
1257
样例输出
4601 */
/* #include <stdio.h>
int main(){
    int n ;
    int a,b,c,d = 0;
    int p,q;
    scanf("%d",&n);
  
    a = n / 1000;
    b = (n % 1000 )/100;
    c = (n % 100) /10;
    d = n % 10;
    
    a =(a + 9) %10;
    b = (b + 9) % 10;
    c = (c + 9) % 10;
    d = (d + 9)%10;

    p = a;
    a = c;
    c = p;

    q = b;
    b = d;
    d = q;
    printf("%d",a * 1000 + b * 100 + c * 10 + d);
    return 0;


} */
/* 猴子第一天摘下若干个桃子,当即吃了一半,
还不瘾,又多吃了一个。第二天早上又将剩下的桃子吃掉一半,
又多吃了一个。以后每天早上都吃了前一天剩下的一半零一个。
到第10天早上想再吃时,见只剩下一个桃子了。求第一天共摘了多少。

输入
无

输出
第一天摘的桃子数？

样例输入
样例输出
1534

#include <stdio.h>
#define DAY 10
int main(){
    int N = 1;
    int i = 1;
   
    while (i++ < DAY)
    {
        N = 2 * (1+N);
    }
    printf("%d",N);
    //return 0;
} */
/* 以空格为分界,依次输入年月日。

输出
输出其在当年是第几天

样例输入
2004 1 1
样例输出
1
提示
注意闰年和非闰年的差别,注意数据范围！
//leap_year.

#include <stdio.h>
int main(){
    int year ,month,day;
    int theday = 0;
    int legality = 1;
    scanf("%d%d%d",&year,&month,&day);
    if ((year%4==0&&year%100!=0)||year%400==0)
       switch (month)
       {
       case 1:
        if(day >= 0 && day <=31) theday += 0 ;
        else legality = 0;
           break;
        case 2:
            if(day >= 0 && day <=29) theday += 31 ;
        else legality = 0;
           break;

        case 3:
           if(day >= 0 && day <=31) theday += 60 ;
        else legality = 0;
           break;
        case 4:
            if(day >= 0 && day <=30) theday += 91 ;
        else legality = 0;
           break;
        case 5:
           if(day >= 0 && day <=31) theday +=121 ;
        else legality = 0;
           break;
        case 6:
           if(day >= 0 && day <=30) theday +=152 ;
        else legality = 0;
           break;
        case 7:
           if(day >= 0 && day <=31) theday += 182;
        else legality = 0;
           break;
        case 8:
            if(day >= 0 && day <=31) theday += 213 ;
        else legality = 0;
           break;
        case 9:
           if(day >= 0 && day <=30) theday += 244 ;
        else legality = 0;
           break;
        case 10:
           if(day >= 0 && day <=31) theday += 274 ;
        else legality = 0;
           break;
        case n:
           if(day >= 0 && day <=30) theday += 305;
        else legality = 0;
           break;
        case 12:
           if(day >= 0 && day <=31) theday +=335 ;
        else legality = 0;
           break;
       default:
       legality = 0;
           break;
       }
       
   else if(!((year%4==0&&year%100!=0)||year%400==0))
         switch (month)
       {
       case 1:
           if(day >= 0 && day <=31) theday += 0 ;
        else legality = 0;
           break;
        case 2:
           if(day >= 0 && day <=28) theday +=31;
        else legality = 0;
           break;

        case 3:
           if(day >= 0 && day <=31) theday += 59;
        else legality = 0;
           break;
        case 4:
            if(day >= 0 && day <=30) theday +=90 ;
        else legality = 0;
           break;
        case 5:
           if(day >= 0 && day <=31) theday +=120 ;
        else legality = 0;
           break;
        case 6:
            if(day >= 0 && day <=30) theday += 151 ;
        else legality = 0;
           break;
        case 7:
           if(day >= 0 && day <=31) theday +=181 ;
        else legality = 0;
           break;
        case 8:
           if(day >= 0 && day <=31) theday += 212 ;
        else legality = 0;
           break;
        case 9:
            if(day >= 0 && day <=30) theday +=243 ;
        else legality = 0;
           break;
        case 10:
           if(day >= 0 && day <=31) theday +=273 ;
        else legality = 0;
           break;
        case n:
           if(day >= 0 && day <=30) theday +=304 ;
        else legality = 0;
           break;
        case 12:
           if(day >= 0 && day <=31) theday +=334 ;
        else legality = 0;
           break;
       default:
       legality = 0;
           break;
       }
    
   if (legality == 0) printf("date error!");
   else
   {
     theday += day;
   printf("%d",theday);
   }
   

  
    return 0;
} */
/* 判断闰年
#include <stdio.h>
int main(){
    int year = 0;
    scanf("%d",&year);
   if ((year%4==0&&year%100!=0)||year%400==0){
       printf("%d年是闰年",year);
   }
   else
       printf("%d年不是闰年",year);

   
    return 0;
} */
/*
注意这一题Windows端和ACM平台不一样(对于换行的处理) 
输入20个字符,统计其中英文字母、数字字符、空格或回车、其他字符的个数。

输入
1234 abcd

  1234asdf

输出
8个英文字母
8个数字字符
4个空格或回车
0个其他字符

#include <stdio.h>
int main(){
    int a = 0,b=0,c=0,d=0;
    int ch;
    while((ch = getchar()) != EOF){
        if (ch >= 65 && ch <=122) a++;
        else if (ch >= 48 && ch <= 57) b++;
        else if (ch == 10 || ch == 32) c++;
        else d++;
    }
    

    printf("%d个英文字母\n%d个数字字符\n%d个空格或回车\n%d个其他字符\n",a,b,c,d);
} */
/* 
编制程序,输入n个整数(n从键盘输入,n>0),输出它们的偶数和。

输入
n

n个整数

输出
其中偶数的和

样例输入
10
1 2 3 4 5 6 7 8 9 10
样例输出
30

 */
/* 
输入存款金额money、存期year和年利率rate,根据公式计算存款到期时的本息合计sum(税前),输出时保留2位小数。

输入
1000   1   0.1

输出
n00.00

样例输入
1000   1   0.1
样例输出
n00.00

#include <stdio.h>
#include <math.h>
int main(){
    float year,money,rate;
    float sum;
    scanf("%f%f%f",&money,&year,&rate);
    sum = money;
    //for (;year>0;year--)
    for (;year--;)
    {
    
    sum *=(1 + rate);
    }
    printf("%.2f",sum);
    return 0;

} */

/* 
编写一个程序,验证用户输入的一个字符是否是大写字母,如果是打印出“输入的是一个大写字母”,否则打印出“输入的不是一个大写字母”。

输入
输入一个字符。

输出
若是大写字母,输出“输入的是一个大写字母”;

若不是大写字母,输出“输入的不是一个大写字母”。

样例输入
a
样例输出
输入的不是一个大写字母
#include <stdio.h>
int main(){
    int ch ;
    if ((ch = getchar())<97 && ch > 64 ) printf("这是一个大写字母");
    else printf("输入的不是一个大写字母");
    getchar();
    return 0;
} */
/* 
题目描述(详情看我博客)
一个工厂制造的产品形状都是长方体,它们的高度都是h,长和宽都相等,一共有6个型号
,它们的长宽分别为1×1,2×2,3×3,4×4,5×5,6×6。这些产品通常使用一个6×6×h的长方体包裹包装,
然后邮寄给客户。因为邮费很贵,所以工厂要想方设法地减少每个订单运送时的包裹数量。
他们很需要有一个好的程序以解决这个问题从而节省费用。现在这个程序由你来设计。

输入
每个订单信息用包括6个整数的一行数据表示,中间用空格隔开,分别为1×1至6×6这6种产品的数量。

输出
输出一个整数代表对应的订单所需的最小包裹数。

样例输入
0 0 4 0 0 1
样例输出
2
#include <stdio.h>
int main(){
  int n = 0;
  int a1,a2,a3,a4,a5,a6;
        //2x2,1x1,规格的产品适合用来插空.
  int x;//2x2的空位数,将用于和a2的数量比较,看是否还要开新箱子
  int y;//1x1的空位数,将用于和a1的数目比较,看是否还要开新箱子
  int c[4] = {0,5,3,1};//枚举放完3x3规格产品后,该个箱子的剩余可放2X2的空位数

  scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5,&a6);  
  n = a6+a5+a4+(a3+3)/4;
  x = 5 * a4 + c[a3%4];//不是/号
  if (x < a2) n += (a2 - x   + 8) / 9;
  //技巧:
  y = 36 * n - (36 * a6 + 25 * a5 + 16 * a4 + 9 * a3 + 4 * a2 ) ;
  if(y < a1) n += (a1 - y + 35) /36;
  printf("%d",n); 
  
    return 0;
} */
/* #include <stdio.h>
#define HOUR 3600
#define MINUTE 60
int main(){
    int a,b,c;
    int t = 2;
    int t1 = 0;
    int t2 = 0;
    int t3 = 0;
    int h,m,s = 0;

    scanf("%d:%d:%d",&a,&b,&c);
    t1 = a*60*60 + b*60 + c;

    scanf("%d:%d:%d",&a,&b,&c);
    t2 = a*60*60 + b*60 + c;
 
    if((t3 = t1-t2) <= 0){  
        t3 = -t3;
    } 

    else if(t1-t2 > 0){
        t3 = t1-t2;
    }
   // printf("%d\n",t3);
    h = t3/HOUR;
    m = t3%HOUR/MINUTE;
    // s = t3 - h*HOUR - m*MINUTE;

    // if(m<10)
    // {
    //     printf("%d:0%d:%d",h ,m ,s = t3 - h*HOUR - m*MINUTE);
    // }
    // else printf("%d:%d:%d",h ,m ,s = t3 - h*HOUR - m*MINUTE);
    printf("%d:%02d:%02d",h ,m ,s = t3 - h*HOUR - m*MINUTE);
    
   
} */
/* 
#include <stdio.h>
#include <string.h>
void prt(int *x,int *y,int *z){

printf("%d,%d,%d",++*x,++*y,*(z++));

}

int main(){

int a=10,c=20,b=40;

prt(&a,&b,&c);

prt(&a,&b,&c);

}
 */
//n,41,2012,42,20
/* 
给出三个整数,请你设计一个程序,求出这三个数的和、乘积和平均数。
输入
输入只有三个正整数a、b、c。
输出
输出一行,包括三个的和、乘积、平均数。 数据之间用一个空格隔开,其中平均数保留小数后面两位。
样例输入
1 2 3
样例输出
6 6 2.00
提示
#include <stdio.h>
int main(){
   
   int a,b,c;

   int x,y;
   float z;
    scanf("%d%d%d",&a,&b,&c);
    x = a + b + c;
    y = a * b * c;
    //z = x / 3*1.0 ;
    //z = (float)(x)/3;
    z=x*1.0/3;
    printf("%d %d %.2f\n",x,y,z);
    return 0;
} */
/*
//  #include <stdio.h>
// int main(void){
//     int  a,c;
//     char b;
//     int  m;
//    /*  scanf("%d%c%d",&a,&b,&c);
//     printf()
//     if ('b' == '+') printf("%d",a+b);
//         else if ('b' == '-') printf("%d",a-b);
//         else if ('b' == '*') printf("%d",a*b);
//         else printf("d",a/b); */
//     while (scanf("%d%c%d",&a,&b,&c) != EOF)
//     {
//         // printf("%c\n",b);
//         // printf("%d,%d\n",a,c);
//         if (b== '+') printf("%d\n",a+c);
//         /*if ('b' == '+')  这里的b一旦加上'',就和变量b无关,而是单纯的字符字面量b的Ascll*/
//         else if (b == '-') printf("%d\n",a-c);
//         else if (b == '*') printf("%d\n",a*c);
//         else printf("%d\n",a/c);

//     }

// }

/* 
题目描述
根据居民月用水量x(吨)计算并输出应该缴纳的水费y(元),输出时保留2位小数。两者的函数关系如下:y=0, x<0; y=4x/3, 0<=x<=15; y=2.5x-10.5, x>15.

输入
20

输出
39.50

样例输入
-1
样例输出
0.00
提示
#include <stdio.h>
int main(){
    float x;
    scanf("%f",&x);
    if (x<0) 
        printf("%.2f\n",0);//???
    else if (x >= 0 && x <= 15 )
        printf("%.2f\n",4 * x / 3.0);
        
            
    else  printf("%.2f\n",2.5 * x - 10.5);
    
    return 0;
    
} */
/* 输入华氏温度f,计算并输出相应的摄氏温度c (保留2位小数)。c = 5/9(f-32).

输入
华氏温度
17.2

输出
摄氏温度
The temperature is -8.22
样例输入
17.2
样例输出
The temperature is -8.22
提示
#include <stdio.h>
int main()
{
    float farh;
    scanf("%f",&farh);
    printf("The temperature is %.2f",5.0/9.0*(farh - 32));
} */
/* 
题目描述
输入2个复数,实现其乘法运算

输入
分别输入2个复数的实部和虚部(限定为整型),不含实部/虚部的部分以0表示

输出
输出两复数乘法运算结果中的实部

样例输入
2 3 4 5
样例输出
-7
#include <stdio.h>
int main()
{
    int n1,i1;
    int n2,i2;
    scanf("%d%d",&n1,&i1);
    scanf("%d%d",&n2,&i2);
    printf("%d",n1 * n2 - i1 * i2);

    
} */
/* 题目描述
求任何一个两位整数3次方的最后三位数字构成的数

输入
输入一个大于等于10,小于等于99的整数

输出
输出由整数3次方的最后三个数字构成的数

样例输入
n
样例输出
331
#include <stdio.h>
int main()
{
    int n,t;
    scanf("%d",&n);
    t =  (n*n*n)%1000;
    printf("%d",t);

    return 0;
}
 */
// #include <stdio.h>
// int main(void){
//     int n = 0;
//     //int m = 0;
//     scanf("%d",&n);
//     //while((n/8) >= 0)
//     //while(n > 0)
//    /*  while(n){
//         m = (n%8) + m*10;

//         if(n==0) break;
//         n = n/8;
//     } */
//     printf("0%o,%#0x\n",n,n);

// }
//a+b
/* 
#include <stdio.h>

int main(){
  int a;
  int b;
  scanf("%d%d",&a,&b);//Ctrl+D结束输入,退出终端
                      //scanf("%d%d",&a,&b);
  printf("%d\n",a+b);
  
  return 0;
} 
*/
// #include <stdio.h>
// #include <string.h>
// int main(){
//     int a=-1, b=-3;
//     //printf("%d\n",b/a); //3
//     //printf("%d\n",b/(unsigned int)a);//0\
// /*     printf("(unsigned int)a= %x\n",(unsigned int)a);//ffffffff
// /*     printf("int a = %x\n",a);//ffffffff(以补码的形式表示)
//     printf("(unsigned int)b= %x\n",(unsigned int)b);//ffffffff
//     printf("int b = %x\n",b);  */
// //    printf("%d\n",(signed int)(-3)/(unsigned int)(-1));//0
//     /* 应为fffffffd/ffffffff=0(前者是-3的补码,后者是-1的补码
//     (即,在这里(无符号数运算)负号不可以抵消(没有负负得正了))) */
//     //printf("signed int (-3) = %#x\n",(signed int)(-3));
//     printf("unsigned int (-3) = %#x\n",(unsigned int)(-3));//
//     /* unsigned int (-3) = 0xfffffffd */
//     printf("unsigned int (3) = %#x\n",(unsigned int)(3));
//     /* unsigned int (3) = 0x3 */
//     return 0;
// }

//编译预处理)有以下程序:
/* #include <stdio.h> 

#define M(x,y,z) x*y+z

int main()

{

int a = 1, b = 2, c = 3;

printf("%d\n", M(a+b, b+c, c+a));

return 0;

} */
/* #include <stdio.h> 

#define SQR(X) X*X

int main()

{

int a = 16, k = 2, m = 1;

a /= SQR(k + m) / SQR(k + m);

printf("%d\n", a);

return 0;

} */
/* #include <stdio.h> 

#define N       2

#define M       N+1

#define NUM 2*M+1

int main()

{

int i;

for(i = 1; i <= NUM; i++)

     printf("%d\n", i);

return 0;

} */
//6次
/*  #include <stdio.h> 

#define PT          5.5

#define S(x)        PT* x * x

main( )

{

int a=1,b=2;

printf("%4.1f\n",S(a+b));

} */
//9.5
/* #include <stdio.h> 

#define MIN(x,y)  (x)<(y) ? (x) : (y)

int main()

{

int i,j,k;

i = 10; j = 15;

k = 10 * MIN(i, j);

printf("%d\n", k);

return 0;

} */
//15
/* #include <stdio.h>

#define HELLO 100

int main()

{

     printf("%d\n",HELLO);

     return 0;

} */
//100

/* #include <stdio.h>

#define A 2

#define B A+1

int main()

{

     printf("%d\n",B);

     return 0;

} */
//3

/* 
#include <stdio.h>

#define A 2

#define B A+1

int main()

{

     printf("%d\n",--B);//编译错误: B必须是可修改的左值

     return 0;

} */

/* #include <stdio.h>

#define MIN(x,y) (x)<(y)?(x):(y)

int main()

{

     int k=MIN(1,2);

     printf("%d\n",k);

     return 0;

} */
//1

/* #include <stdio.h>

#define MIN(x,y) (x)<(y)?(x):(y)

int main()

{

     int i=10,j=15,k;

     k=10*MIN(i,j);

     printf("%d\n",k);

     return 0;

} */
//15
/* #include <stdio.h>

#define MOD(x,y) x%y

int main()

{

     int a=15,b=100;

     int z=MOD(b,a);

     printf("%d\n",z++);

     return 0;

}
 */
//10
/* #include <stdio.h>

#define X 5

#define Y X+1

#define Z Y*X/2

int main()

{

     printf("%d\n",Z);

     return 0;

} */
//7
/* 
#include <stdio.h>

#define F(x) x*x

int main()

{

     printf("%d\n",F(1+2)+3);

     return 0;

} */
//8
/* #include <stdio.h>

#define F(x) (x)*x

int main()

{

     printf("%d\n",F(1+2)+3);

     return 0;

} */
//8

/* #include <stdio.h>

#define F(x) x*(x)

int main()

{

     printf("%d\n",F(1+2)+3);

     return 0;

} */
//10
/* #include <stdio.h>

#define F(x) (x)*(x)

int main()

{

     printf("%d\n",F(1+2)+3);

     return 0;

} */
//12
/* #include <stdio.h>

#define F(x) (x*x)

int main()

{

     printf("%d\n",F(1+2)+3);

     return 0;

} */
//8

//设有以下宏定义:
/* 
#define N             3
#define Y(n)          ( (N+1)*n)
#include <stdio.h>
int main()
{   
    int z;
    z = 2 * (N + Y(5+1));//这里的参数仍然不可以私自计算.宏参数永远只是做最单纯的原字符照搬,不加任何干扰.
    printf("%d",z);
} */
//48

/* #include <stdio.h>

#define K 5.5

#define F(x) K*x*x

int main()

{

     int a=1,b=2;

     printf("%.1f\n",F(a+b));//9.5

     return 0;

} */
/* #include <stdio.h> 

#define F(X,Y) (X)*(Y)

int main()

{

int a=3, b=4;

printf("%d\n", F(a++, b++));

return 0;

} */
/* // //程序中头文件typel.h 的内容是:
// #define N       5
// #define M1      N*3
//主程序如下:
#include <stdio.h> 
#include "type1.h" 
#define M2  N*2
int main()
{
    int i;
    i=M1+M2;
    printf("%d\n",i);
    return 0;
} */
//和一下程序效果一致
/* #define N       5
#define M1      N*3
#define M2      N*2
#include <stdio.h> 
int main()
{
    int i;
    i=M1+M2;
    printf("%d\n",i);
    return 0;
}
 */
/* #include <stdio.h>

#define f(x)  (x*x)

int main()

{

int i1, i2;

i1=f(8) / f(4);

i2=f(4 + 4) / f(2 + 2);

printf("%d, %d\n", i1, i2);

return 0;

} */
/* #include <stdio.h>

#define K 5.5

#define F(x) K*(x*x)

int main()

{

     int a=1,b=2;

     printf("%.1f\n",F(a+b));//27.5

     return 0;

} */
/* 
#include <stdio.h>

#define F(x) x*(x+1)

int main()

{

     int a=2,b=3;

     printf("%d",F(1+(a+b)));

     return 0;

} */
//(编译预处理)有以下程序:
/* #include <stdio.h>

#define F(x) x*(x+1)

int main()

{

     int a=2,b=3;

     printf("%d",F(1+a+b));

     return 0;

} */
//(编译预处理)有以下程序:
/* #include <stdio.h>

#define F(a,b) for(int i=a;i<b;i++)

int main()

{

     F(3,5)

            printf("%d",i);//34

     return 0;

} */
/* 关于宏的内容 */
// #include <stdio.h>
// /* 这个宏用来交换值很不错.它是直接在主调函数内操作,能够修该实参变量的值 */
// #define F(a,b)/* 别名 */ {int t;t=a;a=b;b=t;}/* 一个复合语句而已 */

// int main()
// {
//     int x=1,y=2;
//     F(x,y);
//     printf("%d %d\n",x,y);
//     return 0;
// }

/* 字符表达式 */
// #include <stdio.h>
// int main(){
//     int a = 'a';
//     int A = 'A';

//     // printf("%c\n",97);/* a*/
//     // printf("%d\n",23);/* 23 */
//     // printf("%d",d);//不允许直接这样
// printf("Ascall(a) = %d\n",a);//输出97
// printf("Ascall(A) = %d\n",A);/* //这里的表示符A表示的是上面初始化的 字符表达式'A'
//             大写字母排在小写字母之前 */
// /*  */
// printf("Ascall(G) = %d\n",'G');

// if (4){
//     printf("OK\n");
// }
// if (!4) {
//     printf("OKK\n");

// }
// //putchar('a');//输出字符a

// /* printf("%\n",);
// printf("%3c\n",ch); */

// }

// /* 对指针跳动的理解 */
// //老师讲的很好,但还是不如自己动手测试实例,
// //并微调源代码挖掘和和验证自己的设想(借助调试功能窥探细节是如此重要!)
// int main()
// {
//     static int a[3][4]={1,2,3,4,5,6,7,8,9,10,n,12};
//     int i,j,(*p)[4];
//     for(p=a,i=0;i<3;i++,p++){

//         for(j=0;j<4;j++){
// /* 所谓行指针操纵(操纵列之间的变换)是先将行指针转化位列指针(比如由行指针p-->p[i]+n或者:p-->*p+n) */
//     /*//行指针在行之间跳动,列指针在列之间跳动.
//             printf("%d\t",*(*p+j));//0,1,2,3列
//                 1       2       3       4
//                 5       6       7       8
//                 9       10      n      12 */
//     /*
//             printf("%d\t",(*p+j)); //驱动列指针向右移动.//*p是列指针

//             4210720 4210724 4210728 4210732
//             4210736 4210740 4210744 4210748
//             4210752 4210756 4210760 4210764  */

//  //           printf("%d\t",p);//查看之前p++语句的效果.发现正是从上一行移动到下一行.
//             /*  4210720 4210720 4210720 4210720 //与上面的首(各行的)地址相同.
//                 4210736 4210736 4210736 4210736
//                 4210752 4210752 4210752 4210752 */

//                  printf("%d\t",p+j);//每次跨越一行(p是行指针)
//                  /* 4210720 4210736 4210752 4210768
//                     4210736 4210752 4210768 4210784
//                     4210752 4210768 4210784 4210800 */

//         }
//         printf("\n");
//     }

// }
/*短路:
#include <stdio.h>
int main()
{
int a=5, b=6, c=7, d=8, m=2, n=2; 
m= a>b ? c=5 :(n=c > d);
printf("%d\n",c); // 7
return 0; 
} */
/* #include <stdio.h>
int main(void){
	int a=3,b = 4 ,c = 5;
	printf("%d",!(a>b)&&!c||1);//1
} */

// /* //深入理解:K&R:如果某个算术运算符有一个浮点型操作数和一个整型操作数,则在开始运算之前整型操作数将会被转换为浮点型。 */
// #include <stdio.h>
// int main(){
// 	int x = 1;
// 	int y = 2;
// 	int s ;
// 	float ss;//为了不丢失精度,结果以float型保存
// 	float sf;
// 	float sf1;
// 	float sf2;
// 	s = 1.0+x/y;
// 	ss = 1.0+x/y;
// 	sf = float(x/y);
// 	sf1 = (float)x/(float)y;
// 	sf2 = x/(y*1.0);
// 	printf("sf2 = %f\n",sf2);//0.500000
// 	printf("sf1 = %f\n",sf1);//0.5
// 	printf("sf = %f\n",sf);//0.000000
// 	printf("ss = %f\n",ss );//1.000000
// 	printf("s = %d\n",s );//1
// 	printf("x/y*1.0 = %f\n",x/y*1.0);
// 	printf("(1.0 + x/y) = %f\n",(1.0 + x/y) );//1.000000
// /*由于x/y的优先级更高,所以该式为1.0 + 0 = (float)1.0=1.000000 */
// 	printf("(1.0 + x/y) = %d\n",(1.0 + x/y) );//0
// 	printf("1.0 + x/y = %d\n",1.0 + x/y);//结果为0,because 这里%d优先正对单个变量

// 	return 0;
// }
/* #include <stdio.h>
int main(){
	int x = 2;
	int m = 3;
	int g ;
	int t ; 
	// 由于逗号运算符的优先级低于 赋值运算符=
	g = x,m;//g = 2
	t = (x,m);// t = 3

	printf("g = %d\nt = %d\n",g,t);
	//printf("%d",(++x,x++));
	return 0;
} */
/* /* #include <stdio.h>
int main()
{
	char c, s[100];
	scanf("%s", s);
	c = getchar();
	return 0;
} */

/* #include <stdio.h>
int main()
{
	char c, s[100];
	gets(s);
	//c = getchar();
	return 0;
}
  */

/* 运算符++(i++) */
// #include <stdio.h>
// int main() {
// 	int i = 2;
// 	int y = 0;
// 	/* 运算先考虑优先级,操作数两边优先级相同再考虑结合性。 */

// 	 /* 尽管表达式中运算符有左右结合顺序之分,但是这是局部而言,应首先从整体上从左往有读表达式 */
// 	//*printf("%d", y = ++i + i++ + i);*//* 9 */   printf("%d", ++i + i++ + i);/*9*/    /*这两个同地位(不分先后,实现方式是运行前一个print的时后,注释掉后一个
// 	//																	   同样的,运行第二个printf是把第一个printf注释掉,这样就可以屏蔽掉相互之间
// 	//																	   由于自增带来的副作用而造成y值和右值的混乱*/

// 	//*从上面的运行结果可知,printf表达式的值与是不是赋值语句无关*/

// 	//printf("  i1 = %d\n   %d\n  i2 = %d\n", i, y = ++i + i++ + i, i);/*4,9,4*/
// 	//printf("  i1 = %d\n   %d\n  i2 = %d\n", i, y , i);/*4,9,4*/
// 	////说明用于计算y的i值是3.

// 	printf("  i1 = %d\n   %d\n  i2 = %d\n", i, y = i++ + i, i);/*3,4,3*/

// 	  return 0;
// }
//运算符优先级:
// #include <stdio.h>
// main(){
//     int i = 3 ;
//     int d = 0 ;/* //一般都给它初始化一下,
//                 (为了在调试的侯不会出现莫名奇妙的值(理论上可以任意取,只要该变量在被使用的时候会被赋新值即可) */
// /* printf(可以打印表达式的值) */
//     printf("i= %d\n",i++);//打印出原来i的值,顺便给i做个i +=1 的迭代!
//     printf("-i++ = %d\n",-i++);/* ++优先高于取负- ,
//                             这里先是i++把i原值递给取负运算,再打印整个表达式的值,最后才顺便给i加一
//                             可见,i++做的两件事不一定是一口气做完的,i值加一将会体现再下一个语句中,而++i则是一口气做完!*/
//     d = i;              //
//     printf("d = %d\n",d);
// /* i++ = 3
//    -i++ = -4
//    d = 5 */
//     getchar();

//     //printf("");
// }

/* 
jlh很喜欢吃水果,苹果是他最喜欢的,其次是梨。他天天想着吃水果,竟然感动了女娲大神,女娲大神给了他n个篮子,让他选择其中的m个(m<=n)个篮子。每个篮子里有a个苹果和b个梨。请你们帮jlh选择篮子吧。

Input:
输入一个t(t<=10),表示有t组测试数据,再输入n和m(0=<m<=n<=100000),接下来的n行,输入a和b表示苹果和梨的数量。

Output:
按jlh选择的顺序(先选苹果多的,苹果数量相同选梨多的,两者相同选序号小的)篮子的序号(1-n),m个数用空格隔开。

Sample Input:
2
2 1
2 0
1 4

3 2
3 4
2 6
3 5
Sample Output:
1
3 1
*/
/*
#include <stdio.h>
int whichismax(int v[],int n){
    int i,max;
    max = 0;
    for(i = 0;i < n ;i ++){
        if(v[i] > v[max])
            max = i;
    }
    return max;
}

int main()
{
    int t;
    int n,m;
    int i;
    int a[100000][2],v[100000];
    scanf("%d ",&t);

    while (t --)
    {
        scanf("%d %d",&n,&m);
    //     填充数组(二维),只需for下的scanf() 
        for (i= 0;i < n;i ++){
            scanf("%d %d",&a[i][0],&a[i][1]);

            
        }
        for(i = 0;i < n;i ++)
            v[i] = a[i][0]*100000 + a[i][1];
        for(i = 0; i < m ;i ++){

            if(i == m-1)
                 printf("%d",whichismax(v,n) + 1);
            else
            
                printf("%d",whichismax(v,n) + 1);
                
             v[whichismax(v,n)] = -1;
            
           

        }
        printf("\n");
    }
} 
*/
/* 
将你的编号数
所有因子加起来得到一个编号,
这个编号的主人就是你的另一半。
数字N的因子就是所有比N小又能被N整除的所有正整数,如12的因子有1,2,3,4,6.
你想知道你的另一半吗?
?

Input
输入数据的第一行是一个数字T(1<=T<=500000),它表明测试数据的组数.然后是T组测试数据,每组测试数据只有一个数字N(1<=N<=500000).
?

Output
对于每组测试数据,请输出一个代表输入数据N的另一半的编号.?
Sample Input
3 2 10 20
Sample Output
1 8 22 */
/* #include<stdio.h>
#include<math.h>
int main()
{
    int t, n, ans;
    float r;
    scanf("%d", &t);

    //如果要测试t组(次)输入数据,套路为(while(t--){scanf("%...")})
    while(t--)
    {
        scanf("%d", &n);
        ans = 0;
        r = sqrt(n * 1.0);
        //浮点化运算
        //需要测试的除数上限.

//循环内部定义整形变量i(如果需要一个只在循环的时候用到的循环变量i)
        for(int i = 2; i <= r; i++)
        //遍历(从2开始,遍历需要测试的除数(i(i<=r))
        {
            if(n % i == 0)//表达式还是一样的,与除数范围无直接相关.
                        //判断是否n可以整除i
            {//若进入,i已为n的因子
                if(i * i != n)
                //极端情况线性:即判断了是否该对因子对的两个数字相等(n是否为某个合适的i的平方数),是的换只取其一
                    ans += (i + n / i);
                    //各对因子对(之和)
                else ans += i;
            }
        }
        printf("%d\n", ++ans);
    }
    return 0;
} */
// 原文链接:https://blog.csdn.net/hy1405430407/article/details/46343609
/* //沙漠带油问题:
#include<stdio.h>
int main()
{
    int k;            
    float d,d1;      
    float oil[10],dis[10];
    int i;
    printf("NO. distance(k.m.)toil(l.)\n");
    k=1;
    d=500;       
    dis[1]=500;
    oil[1]=500;
    do{
        k=k+1;
        d=d+500/(2*k-1);
        dis[k]=d;
        oil[k]=oil[k-1]+500;
    }while(!(d>=1000));
    dis[k]=1000;       
    d1=1000-dis[k-1];   
    oil[k]=d1*(2*k+1)+oil[k-1];   
    for(i=0;i<k;i++)      
        printf("%d\t%f\t%f\t\n",i,1000-dis[k-i],oil[k-i]);
    getchar();
} */

/*手机中有这样的一种九宫格键盘: 
数字1上有ABC 
数字2上有DEF 
数字3上有GHI 
数字4上有JKL 
数字5上有MNO 
数字6上有PQRS 
数字7上有TUV 
数字8上有WXYZ 
数字9上有 * 
给出一个只有由大写字母和*组成的的字符串,求出所有字符对应的手机键盘上的数字的和。
Input
输入一个字符串,长度不超过100
Output
输出对应的和, 每组输出独占一行
Sample Input
ABC*
Sample Output
12
*/
/* 
#include <stdio.h>
int main()
{
	printf("Enter:");
	char a[101];
	int i = 0; //数组下标i
	int num = 0; //用于累积各个char输入带来的结果改变量
	for (;;) //这里跳出循环使用的是break的方式.!!!!
	{
		scanf("%c", &a[i]); //读取一个char,放在字符数组的对应位置,一次一个
		//读入:char,由于单向传值,scanf必须配合&

		//针对单个变量取值的if判断:
		if (a[i] == '\n') //先考虑极端之最少/小(无)输入.
			break;

		if (a[i] == 'A' || a[i] == 'B' || a[i] == 'C')
			//类似分段函数,(枚举相同函数值变量区间里的:散点,可以使用或逻辑)
			//'A'为字符常量.
			//
			num++;
		//如果读到的char输入该类,则为上一个结果的基础上增加2....
		if (a[i] == 'D' || a[i] == 'E' || a[i] == 'F')
			num += 2;
		if (a[i] == 'G' || a[i] == 'H' || a[i] == 'I')
			num += 3;
		if (a[i] == 'J' || a[i] == 'K' || a[i] == 'L')
			num += 4;
		if (a[i] == 'M' || a[i] == 'N' || a[i] == 'O')
			num += 5;
		if (a[i] == 'P' || a[i] == 'Q' || a[i] == 'R' || a[i] == 'S')
			num += 6;
		if (a[i] == 'T' || a[i] == 'U' || a[i] == 'V')
			num += 7;
		if (a[i] == 'W' || a[i] == 'X' || a[i] == 'Y' || a[i] == 'Z')
			num += 8;
		if (a[i] == '*')

			num += 9;
	}
	printf("%d", num);
	getchar(); 
} */
/*用远择法对10个蓝数排序。
// 重复算法排序 */

// #include <stdio.h>
// #define N 7
//  main(){
//     int i,j,min,temp,a[N];
//     printf("Enter a series (N) of numbers:\n");

//     for(i=0;i<N;i++) {       /* for(里面的模块是以;分格而非,   !!) */
//         printf("a[%d] = ",i);/* 这里没有换行,是为了
//         下一个语句scanf()在控制台输入数据的时后是填在对应索引的后面
//         为输入(交互填数字)时提供视觉的方便,而非为打印内容而设计的,
//         交互填数的时侯,在结束一个填写后会以Enter键作为一个输入的结束
//         ,与此同时,还会换行! */
//         scanf("%d",&a[i]);
//     }
//     printf("\n");//告一段落
// /* 再次横排呈现刚才输入保存到数组的数据 */
//     for(i = 0;i < N ;i++)
//         printf("%5d",a[i]);
//     printf("\n");//告一段落

// /* 开始排列算法的描述 */
//     for(i = 0;i < N - 1;i++){

//             min = i;//先处理(记录)数组下标
//        // for(j = 0;j <N - i - 1;j++))//或
//        //for(j = 1,j < N - i,j++)//或
//        for(j = i;j<N;j++)
//             if(a[min] > a[j])
//                 min = j;
//         temp = a[i];
//         a[i] = a[min];//最小值放到待排序子序列的首位值
//         a[min] = temp;
//     }
//         /* 准备输出 */
//     printf("\n The sorted sequence is as follows:");
//     for(i = 0;i < N; i++){
//         printf("%5d",a[i]);
//     }

// }
/*循环读入:a+b:
#include <stdio.h>
int main(){
  int a;
  int b;
  while(scanf("%d%d",&a,&b)!=EOF){//Ctrl+D结束输入,退出终端
  //scanf("%d%d",&a,&b);
  printf("%d\n",a+b);
  }
} */
/*换乘车问题zjgsu/博客 
#include <stdio.h>
#include <string.h>
int next(int k);
int main(){
    
   int n,k,l;
   int t;
   int ans;
   scanf("%d%d%d",n,k,l);
   while ( n != 0)
   {

      ans = k;
      while (ans<l && n-- - 2 > 0  )
      {
         if(next(k)<l)
         {
            ans = next(k);
         }
        
      }
    

   }
   
   printf("%d",ans);
    return 0;
} 
int next(int k)
   {
      k = 2*k - k/2;
      return k;
   } */
/* #include <stdio.h>
#include <string.h>
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",a+b);
    return 0;
} */
//-------------------------------------------------
/* #include<stdio.h>

int fun(int a) {

   if (a == 1||a == 0)

     return 1;

   return a*fun(a - 1);

}

int main() {

   int a ,ans;

   ans = fun(100);
printf("%d",ans);
   return 0;

}
 */

//完整段代码test:
/* 做zjooc的测试代码段,向上添加 */
/* #include <stdio.h>
#include <string.h>
//测试的函数请放在下方一行:

//主函数:
int main(){
  //请在下方(一行插入即可)
 
} 
*/