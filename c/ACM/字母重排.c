/*问题F：字母重排
题目描述
输入一个字典（用******结尾），然后再输入若干单词。
每输入 一个单词W ,你都需要在字典中找出所有可以 用w的字母 重排后得到的单词(排列组合出所有可能的新序列)，
并按照字典序（按字母a〜Z）从小到大的顺序在一行中输出，如果不 存在就输出  ":("    
输入单词之间用空格或空行隔开，且所有输入单词都由不超过6个小写字母组成
注意， 字典中的单词不一定按字典序排列。

输入
输入一行字典，即很多单词（相当于自定义），
再输入一行结束标记******
多行，
在一行中的单词之间用空格间隔），
直至文件结束	最后输入若干单词（可能有

输出
在字典中找出所有可以用输入单词的字母重排后得到的单词，并按照字典序（按字母a〜z）从小到大的顺 序在一行中输出，如果不存在就输出:（
样例输入
tarp given score refund only trap work earn course pepper part
******
resco nfudre aptr sett oresuc


tips:其中:sett这个单词将输出:(
样例输出
score
refund
part tarp trap
:(
course

tips:
思路一:排列组合模式串(难点)+双重遍历匹配
思路二:二重循环判断一个输入单词w中的所有字母与字典中的一个单词是否具有一样的字母组成,再来一个for和字典的所以有单词匹配判断.
思路三:将字典中的单词的字母序列分别排序,再把输入单词的字母序列排序,这样就可以直接用strcmp()直接判断是否匹配,(需要一个副本保存原始字典里的单词),通俗易懂;
*/
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*配合qsort()排序字符*/
int cmp_char(const void* _a, const void* _b)
{
    char* a = (char*)_a;
    char* b = (char*)_b;
    return *a - *b;
}

int main()
{

	char word[1000][15],/*存储原始字典,至多保存1000个长度均在10以内地单词*/
		sorted[1000][15];/*sorted[][]数组作为有序的备份数组*/
    int n = 0;/*计数读入的单词数*/
    int i;

    /*制作字典:读入输入数据到二维数组word[][]的第n行word[n]中*/
    for (;;)
    {
        scanf("%s", word[n]);
        if (word[n][0] == '*')
            break;
        n++;
    }
    /*制作单词内有序的字典副本:将字典一行行地拷贝到副本sort[][]中;再及时对副本sorted[][]的字符数组(各单词的字母序列)*/
    for (i = 0; i < n; i++)
    {
        strcpy(sorted[i], word[i]);
        /*单词内部排序(单词被破坏,所以再副本中执行)*/
        qsort(sorted[i], strlen(sorted[i]), sizeof(char), cmp_char);
    }
    /***************************************************/
    char s[15];/*保存输入单词w(每次一个单词字符串)*/
    /*测试输入数据:(可连续处理多个输入单词)*/
    while (scanf("%s", s) == 1)/*连续读入一个个的单词w(待查找单词),存在s数组中,单词长度<=10;并及时判断输出*/
    {
        /*对输入的单词w作字母序列排序:*/
        qsort(s, strlen(s), sizeof(char), cmp_char);
        int found = 0;/*flag作用的标志*/
        /*遍历有序字典副本中的所有单词:进行匹配操作*/
        for (i = 0; i < n; i++)
        {
            if (strcmp(sorted[i], s) == 0)
            {
                found = 1;
                printf("%s ", word[i]);/*从原始二维数组中打印*/
            }
        }//for
        /*改输入(单词w)再字典中没有匹配项*/
        if (!found)
            printf(":(");

        printf("\n");
    }//while
    return 0;
}
/*彩蛋:*/
/*配合qsort()排序字符串
int cmp_string(const void* _a, const void* _b)
{
    char* a = (char*)_a;
    char* b = (char*)_b;
    return strcmp(a, b);//字典排序
}
*/
/*对字符串(单词)在二维数组中的位置进行排序,几个单词的先后顺序排序,单个单词本身的字母未改变
qsort(word, n, sizeof(word[0]), cmp_string);*/
/*处理n个单词:*/