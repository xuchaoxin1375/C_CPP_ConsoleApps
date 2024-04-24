#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
/*使用函数的三部曲:1.定义:2.声明;3.函数被调用
另外注意,头文件里不允许右重名的两个函数. */

//往下:
/* 递归函数
编写心得:
一般来说,在传参和返回结果这里是一个递归函数的技术点
有时是对递归函数的参数进行迭代;
有时是直接对return的表达式进行处理.
(当然也可以两者兼有之.)
递归函数的直接出口(真正出口是返回递归函数本身以外的常量/变量/停止运行)
 */

/* 最小公倍数:lcm() */
int lcm(int a,int b)
{ 
    int gcd_Euclid(int,int);   
    return a*b/gcd_Euclid(a,b);
}
/* 截取出特定位数小数的部分. */
float save_pre_bit(float n,int save_bit)
{
    /* 3.1415926 4 */
    return (int)(n * pow(10,save_bit))/pow(10,save_bit);
    //可以通过监视该表达式来查看.pow()返回double类型的浮点数.
}
/* 判断真子串:真子串是指从原字符串中   通过删除某些字符   但不破坏余下字符的顺序  而形成的新字符串 */
int is_sub_string(char*a,char*b)
{
    int len_a = strlen(a);
    int len_b = strlen(b);
    
    char *longer = b;
    char *shorter = a;

    int len_longer = len_b , len_shorter = len_a;
    /* 确定下较长地字符串和较短的字符串 */
    if(len_a>len_b)
    {
       longer = a;
       shorter = b;
       len_longer = len_a;
       len_shorter = len_b;
    }

    int is_match = 0;
    int j = 0;
    /* 不回头的遍历 */
    for(int i = 0; i<len_shorter;i++)
    {
        for(;j < len_longer;j++)
        { 
            
            if(shorter[i] == longer[j]) 
            {
                is_match ++;
               
                break;
            }
        }
        if (shorter[i] == longer[j])
        {
            j++;
        }
        if (is_match == len_shorter)
        {
            return 1;
        }
    }
    return 0;
}
/* 打印保存在指针里的值(传入指针p,元素个数n) */
void print_pointer_int_element(int *p,int n)
{
    for(int i = 0;i<n;i++)
    {
        printf("%d ",*(p+i));
    }
    printf("\n");
}
/* 用指针读入并保存n个整数数,如果读取结束/出错,返回0,如果读取成功,返回1 */
int read_int_pointer(int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        
        if(scanf("%d", p + i) == EOF)
        {
            return 0;
        }
    }
    return 1;
}
//配合使用:  实现连续测试.
//     while (read_int_pointer(p, 10))
//     {
//         deal(p, 10);
//         print(p, 10);
//     }
/* 判断润年 */
int is_leap_year(int year)
{
    /* 每一百年少润一次(一天)(每第25次时不润) 
    设定闰年的意义在于对当前时间(日期)的粗略计算做一次修正,使得偏差减小
    每积累四年的偏差(少于实际时间),用闰年多出的一天修正一下.(误差在于,还没有满一年,我们提前把它算作一年.(相差
    大概(略少于1/4天),于是每四年就等上一天,这样纠正了24次后(差不多每次闰年会多等待一些时间1/25天),导致时间比实际时间
    要慢了将近一天(估计是3/4 天),于是在每百年的第25次"闰年"要跳过例行的等待,追赶上实际时间(但又赶过头了1/4天左右).这样的二次修正还不够,(前两轮的修正执行了400年后
    又会快了一天,每400年还要在等上一天*/
    /*总之:400的整数倍肯定是闰年;(与400不是公倍数的整百年年份(或者说不被400整除的整百年年份)则一定不是闰年)
    4年一次大调整;100年一次中调整;400年一次小调整*/
    if ((year % 4 == 0 && year % 100 != 0)/*到此还不满足(第一类)条件,还有第二类条件的机会)*/ 
        || year % 400 == 0)/*前后量类条件不可能同时满足(两类闰年不相交);整百年的年份若是闰年则必须且只能满足第二类条件(能够被400整除)*/
    {
        return 1;
    }
    return 0;
}

/* 监测号码中的不吉利数 */
int is_bad_num(int *num, int n)
{
    /* 由于一下两个标准边界不一 */
    /* 监测4 */
    for (int j = 0; j < n; j++)
    {
        if (num[j] == 4)
            return 1;
    }

    /* 监测38 (朴素算法)*/
    for (int i = 0; i < n - 1; i++)/*小心越界.*/
    {
        if ((num[i] == 3) && (num[i + 1] == 8))
        {
            return 1;
        }
    }

    return 0;
}
/* 取出 读入的数据的数码存至num_char,并且返回这个数的位数cnt: */
int fetch_num_char(int n, int *num_char)
{
    int i = 0;
    int cnt = 0;/* 累计这个数的位数 */
    for (; n > 0;)
    {
        num_char[i++] = n % 10;/* 取出数码并保存 ,但还是低位到高位的顺序写入的.*/
        n /= 10;/* 迭代被处理的数 */
        cnt++;
    }
    /* 在cnt++t统计结果出来之前无法直接逆序 :*/
    /* 借助cnt 调整顺序:逆序 
    测试：（1+5）/2=3；（1+6)/2=3；从1开始编码索引（1，2，3.。）
    (0+5)/2=2;(0+6)/2=3 ;从0，开始编码索引（0，1，2，3。。。）（两中结果一样）
    发现如果通过索引决定交换次数不够直接，考虑直接从待逆序元素个数cnt的角度来处理这件事
    当然注意从第0个元素开始对调
    (i = 0; i < cnt / 2; i++)或者（i=1;i<=cnt/2;i++)*/
    for (i = 0; i < cnt / 2; i++)/*另外整除号在正数范围内时向下取整的;在负数范围内向上取整;总之,去掉小数部分啦.*/
    {
        /*如果是偶数个元素的序列,那么首位两两对调;如果是奇数个元素的话,中间元素保持不动其余的前后两两对调.*/
        int temp;
        temp = num_char[i];
        num_char[i] = num_char[cnt - 1 - i];
        num_char[cnt - 1 - i] = temp;
    }
    return cnt;
}
/* 按照 元素大小降序提取出 某组数据(均为正数的)的在原数组下的索引 (数据有cnt个,原始数据存在weights数组中,提取出的索引序列保存在sort数组中) */
void sort_link(int *weights, int *sort, int cnt)
{
    int max_index = 0;

    for (int i = 0; i < cnt; i++) //控制扫描次数
    {
        max_index = 0;

        for (int j = 0; j < cnt; j++) //每次都从头到尾扫描
        {
            if (weights[max_index] < weights[j])
            {
                max_index = j;
            }
        }//内层for

        sort[i] = max_index;     //保存该次扫描中的max_index;
        weights[max_index] = -1; //以此实现迭代
    }//外层for
}
/* 判断是否为素数 i * i < n + 1;版 */
int isprime_ii(int n) /*n为自然数*/
{
    /*n=0,1单独否定*/
    if (n == 0 || n == 1)
    {
        return 0;
    }
    /* i*i 阶段只可处理n>=4(才会进入for) 的部分. */
    for (int i = 2; i * i < n + 1; i++)/*eg.n=4,5,6,7,8,时,i=2;n=9~15时,i = 2,3*/
    {
        if (n % i == 0)
            return 0;  
    }
    /*默认返回是1:  n=2,3 也直接返回是所以只需特殊处理n=0,1即可.*/
    return 1; 
}
/* 判断素数(原始 i < n;版)(三出口)*/
int isprime_i(int n)
{
    if (n == 0 || n == 1)
        return 0;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}
/* 又一种 isprime(双出口) */
int isprime(int n)
{
    int i=2;
    for(;i<n;i++)
    {
        if(n%i==0)
        break;//当然这并不必要,可以直接返回0(否则默认直接返回1)
    }
    /*由于0,1均小于2(<i的初始值),会直接return 0;*/
    if (i == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* 生成给定区间内的 素数 数组 */
int Prime(int m, int n, int *prime_array)
{
    int k = 0;
    /* 第一个for规定判断区间 */
    for (int i = m; i <= n; i++)
    {
        /* 接着针对区间中的某个元素判断是否素数并将是素数的数写入到prime_array数组中 */
        int j = 2;
        if (i == 0 || i == 1)
        {
            continue;
        }
        else if (i == 2 || i == 3)
        {
            prime_array[k++] = i;
        }

        else
        {
            for (; j * j < i + 1; j++)
            {
                if (i % j == 0)
                {
                    break;
                }
            }
            /* 关键的安排和判断 */
            if (j * j >= i + 1) /* 若为正常退出上面的循环而非break出来的时候:该i就为素数. */
                prime_array[k++] = i;
        }
    }
    return k; //k是从0开始的.返回本次调用写入了多少个素数
}
/* 字符串排序 ,基于指针数组作为参数的*/
void sort_string(char **string, int n) //作为形参:char **string 等价于 char *string[](指针数组类型) --> ((char*)*) string
{
    /* 冒泡版 */
    int i = 0, j = 0;
    char buf[200];
    char *buf_p = string[0];/*指针数组的元素string[i]都是一个个指针变量在这里这些指针都是指向char类型变量,而在复杂的数据结构中可以指向更复杂的变量类型的变量.*/
    //int len = strlen(string);
    /* 
    
    '*'切换到列指针(第i行的第零列地址):(*(string + i)) 
    (*(string + i) + j)第i行第j列的地址;
    *(*(string + i) + j)第i行第j列的元素.

    */
    /* 原本打算在内部计算n(字符串个数)那么需要注意:需要对参数有初始化要求.
    如果有必要对整个字符串进行比较,当然是用strcmp()函数,但
        如果比较第一个字符足以/或可以转化为比较其他属性(长度strlen()函数),则不必 */
    //for(n = 0;len != 0;n++);/* 原本打算再内部计算n(字符串个数)不保证正确性. */

    /* 冒泡排序算法 */
    for (i = 0; i < n - 1; i++)
    {
        /*左元素的索引取值范围j∈[0,n-2]*/
        for (j = 0; j <= n - 2 - i; j++)
        {  /*if()中的RHS的索引取值范围则不那么重要,只需知道与LHS的关系是:RHS=LHS+1即可啦 */
            /* 如果前者大于后者.交换位置使得最大者尽量靠后
            [min,max];界限往前缩小. */
            if (strcmp(string[j], string[j + 1]) > 0)
            {
                
                /* 调用strcpy(),可以使得字符串的排序和赋值项整数那样利索. */
                //strcpy(buf,string[j]);
                buf_p = string[j];
                //这是个指针变量作为右值，这时候，就将指针变量所保存的变量地址赋值给作为左值的指针
                string[j] = string[j + 1];
                string[j + 1] = buf_p;
            }
        }//for
 
    }//for
}//sotr_string()

/* 进制转换 10进制转n进制（以逆序的状态存入字符数组）*/
void number_system_converter_10_to_n(int num, int n_sys, char *buf_return)
{
    /*int quotient;    商（除法所得的结果）商数/quotinet [ˈkwoʊʃnt] 返回商的整数部分 */
    int remainder;  /* 余数 */
    int i = 0;
    for (; num > 0; i++) 
    {
        
        remainder = num % n_sys;
        num /= n_sys;
        /* 收集余数,逆序填充 */
        buf_return[i] = remainder + 48; //从数字转换为字符
        /*更新num*/
        
    }
    buf_return[i] = '\0'; //截断该字符串for的i++已将位置下移
    /*可以用于逆序打印,则能正确显示.*/
}
/* n进制转换为10进制(比较简答,参数为保存在字符数组的n进制数num ).需要再外部传入基数（建议另设变量int n_sys */
int number_system_converter_n_10(char *num, int n_sys)
{

    int sys_10 = 0; /*保存十进制数值 */
    int len = strlen(num);
    for (int i = 0; i < len; i++)
    {/*从低位到高位*/
        sys_10 += (num[len - 1 - i] - 48) * pow(n_sys, i);
    }
    return sys_10;
}
/*将保存在数组中的数码转化为十进制数(需要指明数组中有多少个待转化的数码)*/
int To_dec(int* num, int n)
{
    /*从低位开始处理的好处在于如果最高位是"0",也能正确处理.*/
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s = s + num[n - 1 - i] * pow(10, i);
    }
    return s;
}
/* 根据传入的索引来确定需要(表达逆序的区间 注意时下标索引 */
void Reverse_index_string(int index1, int index2, char *str)
{
    for (int i = 0; i < (index2 - index1 + 1) / 2; i++)
    {
        /* swap() */
        char temp;
        temp = str[index1 + i];
        str[index1 + i] = str[index2 - i];
        str[index2 - i] = temp;

        /* 在纸上画 */
    }
}
/* 在数组的层面上作逆序操作: (比如要判断逆序/作比较(当然,你可能要拷贝一下源字符串(可以用strcpy)))*/
void reverse_string(char *str)
{
    /*直接对调的话不需要额外的辅助变量*/
    int len = strlen(str); //the lenth of string,it is not the same with the index.
    /* len 为奇数/偶数都可以使用此for;关键在于对调的次数上的控制. */
    for (int i = 0; i < len / 2; i++) /* 画个图,算出len的值,标上两端及中间的关于(len的表达式),将会一目了然 
                                      两种*/
    {
        char temp;
        temp = str[len - 1 - i];
        str[len - 1 - i] = str[i];
        str[i] = temp;
    }

}

/* 递归法求组合数:效率低. */
int zh(int m, int n) //m是组合数的下标,n是组合数的上标;(即第一个位置传入下标,第二个位置传入上标)
{
    //从简单的情况(即追钟出口(当然可能不止一个)判断走:
    if (n == 0)
    {
        //zh(m,n) = 0;//表达式必须是可修改的左值
        return 1; //之歌情况下的直接返回函数值.
    }
    else if (n == 1)
    {
        return m;
    }

    else if (n > m - n)
    {
        return zh(m, m - n);
    }
    else
    {
        return zh(m - 1, n - 1) + zh(m - 1, n); //推到小规模的函数计算,知道结果显然
    }
}
/* 选择排序法_实数排序: (升序版）
有助于增强理解的特征:最大比较区间的次数为n-1次 ;最小长度比较区间比较的次数为1次.*/
void sort_select_float(float *a,int n_elements)/*排序实数范围内(整数/浮点数均可)*/
{
    int min = 0 ;
    int j = 0;
    float temp = 0;
    /*LHS表示关系表达式的左边;RHS表示关系表达式的右边; 排序:每趟排序只共用同一个LHS;单趟排序中:*/
    for(int i = 0;i < n_elements - 1;i++)
    {
        min = i;
        /* 找到最小元素所在位置,这里比较边界是将左边界收缩,而右边界不变. */
        /*每一趟:外重循环从LHS∈[0,n-2]中选定一个LHS,
        内重循环使这个LHS与RHS∈[LHS+1,n-1]全部依次作比较 */
        for( j = i+1 ; j < n_elements ;j++)
        {
            //if(a[i] > a[j])/* 傻乎乎这样写这就是没有没打草的危害,即便之前写过多次该算法 */
            /* 即便是写错了,当发现结果异常你有如下选择:
            1.调试(先选用简答的小规模的倒序数据测试) 
            2.检查算法/检擦代码是否和脑海中的一致(比如角标是否混淆(这一点不容易察觉))
          不清晰的头脑下的潜意识来写尤其如此;当然减少这种失误的手段是优点(对正确的算法及其写法作特征的归纳,这样在自己编写的时候就有检查的重点
            就比如这里的选择法,特点之一是每个if(中都由下标min/max,而不是a[i]和a[j]来比较.))
            */
            if(a[min] > a[j])
            {
                min = j;
            }
        }
        /* 交换元素 */
        if(min != i)/* 最终的得到的min和初始值i比较,看是否变化了,当然,也可不比较直接交换. */
        {
            /* 注意不是a[i]和a[j]交换(bubble才这样.) */
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
        
        /*监视每一趟的排序结果. 其它排序法在检查正确性的时候也可以在每一趟结束后打印排序成果来检验过程的正确性. 
        for (int i = 0; i < n_elements - 1; i++)
        {
            printf("%f ", a[i]);
        }
        printf("\n\n");
        */
    }//for()
}
/* (选择法.)排序字符串里的字符 */
void sort_string_char(char *str)
{
    void swap_char_pointer(char *a, char *b);/*此处必须用指针版swap()*/
    int min;/*辅助变量不是必须的,但应用它可以减少交换次数.*/
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < strlen(str); j++)
        {
            if (str[min] > str[j])
            {
                min = j;
            }
        }//内层for
        //确认了该趟的最小元素所在下标后,执行元素(这里是字符)位置交换操作,嵌套调用swap()
        swap_char_pointer(&str[i], &str[min]);
    }//外层for
}
/*  字符指针版swap() 交换字符的位置 */
void swap_char_pointer(char *a, char *b)
{
    char str;
    str = *a;
    *a = *b;
    *b = str;
}

/* 届时补充字符串版swap()(又有指针版和字符数组版) */

/* 数字版指针swap() */
void swap_int_pointer(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/* 指针版冒泡排序(整数版) (两重for,一个if_swap();
关于选择排序和冒泡排序(掌握这两个简单排序法,关键在于对控制条件的边界(起点和终点,遍历的过程中,
可以类比成一个箭头针,从某一个起点,比较到终点;还有一组与之对应的被比较元素);
注意,随着比交的趟次增加,两组边界都是单边收缩的变化,(一般使得右边界收缩)
即又一边始终不变(每一趟都要从那个定边界开始比较,一个检查排序写法错误的指标就是利用是否单边收缩.) 
*/
/* 注意到,冒泡法一般先将序列的后面(从后往前排)
选择法则往往从前往后排;
但不管从前还还是从后开始,升序和降序都是可以做到的,(在于if(里的时表达式)) */
void bubble_int_sort(int *p, int n)
{
    void swap_int_pointer(int *a, int *b);
    /*冒泡法不需要设立最值flag. */
    for (int i = 0; i < n - 1; i++)
    {
        /*外重循环从LHS∈[0,n-2]选出一个元素;
        RHS = LHS+1 ∈ [1,n-1]
        单趟比较中:*/
        for (int j = 0; j <= n - 2 - i; j++)/*内重循环控制各趟排序的一系列比较中:控制LHS从[0,n-2-i]从0取遍n-2-i(i由外重循环弹出的表示现在是第i趟排序) */
        {
            /*通过改变'<'为'>',可以从降序转为升序; 通过监视*(p+j)和*(p+j+1)可以知道当前(第j组)相邻量的值的情况 */
            if (*(p + j) < *(p + j + 1)) /*或者写作if(p[j] < p[j+1])也可以*/
            {
                swap_int_pointer(p + j, p + j + 1);
            }
        }
    }
}
/* 判断字符是否为文英文字符 */
int is_English_character(char a)
{
    if (a >= 'A' && a <= 'Z' || a >= 'a' && a <= 'z') //'Z'和'a'之间还有许多符号[]等;
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/* 返回num的因子之和:(不要求式质因子) ,不会有重复加的问题*/
int factor_sum(int num)
{
    int sum = 0;                  //计数器一定要初始化.
    for (int i = 1; i < num; i++) /* 不包括num本身的因子 */
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}
/*//(短除法gcd函数: */
int gcd_short_division(int a,int b)
{
    int s = 1;/* 累乘初始化为1,累加初始化为0 (即它们各自运算的 幺元!) */
    for(int i = 2;i <= a && i <= b;i++)//这里的a,b会不会受到内部值更改的影响呢?
    {
        //int gcd = 1;//名称变量名和函数名取一样,可否?
        //int s = 1;定义在这里看不见的,无法实现累乘
        if(a%i == 0 && b%i == 0)
        {
            //gcd *= i;
            s *= i;
            /* 迭代:*/
            a /= i;
            b /= i;
            /* 迭代: */
            i = 2;//K&R的手法,这句话使得上头的for可以重复利用(迭代 递归.)从头开始怼
        }
        
    }
    return s;
} 
/* gcd函数 (欧几里得递归法)Euclid
1.简单入手(里头有最终的出口)
2.核心return.(迭代的关键)
*/
int gcd_Euclid(int a, int b)
{

    //如果a,b本身就可以整除或被整除:那么其中一个就是它两的gcd,并且这时候退出递归函数是刚好合适的.
    //同时运气好的话,(a>b),直接输出结果gcd = b;
    if (a % b == 0)/* 简单入手 */
        return b;//最终的出口.
    //当一其中的任何一方作为gcd多不可得,那说明两者的较小者还是太大了.需要减小gcd的测试值
    //什么样的测试值合适呢,就落在了余数上(取两者某个顺序的模作为新的除数,)
    /* 
        如果调个顺序就能整除或根本无法直接整除,(现尝试将它们统一起来处理):
        调换位置(a = b;b = a % b(前者好理解,后者:a < b,那么a%b就是a 本身.
        其中的两层用意:调换a,b的在函数处理时的相对位置(能够如此简洁地同一器两种情况是a%b的特性好)
        */
    else
        return gcd_Euclid(b, a % b); //传入的参数(b,a%b)是递归得以正确推进的关键(它们必须是会变化的表达式).
}

//整数逆序函数(eg.123->321;120->21
int inv(int n)
{
    int inv = 0;/*辅助变量inv;保存生成的逆序数*/
    for (; n > 0;)
    {
        /* 迭代:(一个*和一个% ) 
        添加新的数码前,先把之前的部分*10,此时最低位(个位被空出(为0)),以便加上新的数码(加在尾部(个位))*/
        inv = inv * 10 + n % 10;
        n /= 10;
    }

    return inv;
}

/* 判断给定的数是否为素数prime函数,若是,则返回这个数,否则返回0(默认它是个素数.) */
int prime(int n)
{
    if (n == 1 || n == 0)
    {
        return 0;
    }
    // 判断4及之后的自然数 4之前默认使prime
    for (int i = 2; i * i < n + 1; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return n;
}
/* 数字大小排序 */

/* 字符串内部字符排序 */