
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void search(char *s1, char *s2, char *s3);
int split(char string_words[][50], char *string);
// 主函数main
int main()
{

    char s1[100]; // 根据需要分配更大的维数
    char s2[100];
    char longest_word[100];

    while (gets(s1) && gets(s2)) // while(scanf("%s",str) != EOF , str == " xxx")判断读到了什么
    {

        search(s1, s2, longest_word);
        printf("%s\n", longest_word); // puts(longest_word);
    }
    return 0;
}
// 主函数结束.
// 在下方编写自定义函数:
void search(char *s1, char *s2, char *s3)
{
    int split(char string_words[][50], char *string);

    char words_of_s1[50][50];
    char words_of_s2[50][50];
    int num_of_the_same_words = 0;
    int num_of_words_s1 = split(words_of_s1, s1);
    int num_of_words_s2 = split(words_of_s2, s2);
    char the_same_words[50][50];
    /* 比较出相同的字符串. */
    for (int i = 0, k = 0; i < num_of_words_s1; i++)
    {
        for (int j = 0; j < num_of_words_s2; j++)
        {
            if (strcmp(words_of_s1[i], words_of_s2[j]) == 0)
            {
                strcpy(the_same_words[k++], words_of_s2[j]); /* i和j莫高混了,这是值得标记小心的 */
                num_of_the_same_words++;
                break;
            }
        }
    }

    /* 比较出最长的the_same_word */
    int longest = strlen(the_same_words[0]); /* 此为初始化一个值 */
                                             /* 不可太过随意 ,当然这里可先设为0    如果再你可以确定地范围内可以简单些用常数初始化 */
    int longest_word_index = 0;              /* 记录最大元素下标 */

    for (int i = 1; i < num_of_the_same_words; i++)
    {
        int len_i = strlen(the_same_words[i]);

        if (len_i > longest)
        {
            // longest_word_index = len_i;//god,i写成len_i了
            longest_word_index = i;
        }
    }

    strcpy(s3, the_same_words[longest_word_index]);
}
int split(char string_words[][50], char *string)
{
    int len = strlen(string);

    // 对于比较曲折的操作,多写些情况分类的标题注释,帮助我们记住初心
    int k = 0, j = 0;
    for (int i = 0; i < len; i++)
    {
        /* for(int j = 0;j<) */
        /* 先针对一个(同一个)字符 */
        /* 遇到非空格字符时 */
        if (string[i] != ' ')
        {
            /* 顺便处理/判断单词切换(这个模块的安排比较讲究.容易绕弯路.)
            初始化新的单词所在数组行*/
            if (i > 0 && string[i - 1] == ' ') /*  */
            {
                string_words[k][j++] = '\0';
                k++;
                j = 0; /* 换行的时候别忘了把指针移到该行首;
                 (调试的时候无法直接看到string_word[k]?,我方可以通过表达式监视来达到查看买的目的,
                 最好能连同k值一起监视) */
            }
            /* 填充第k个单词的第j个字符. */
            string_words[k][j++] = string[i];
        }

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
    }
    string_words[k][j++] = '\0';
    return (k + 1);
}
