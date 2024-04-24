#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* 数字版指针swap() */
void swap_int_pointer(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
}
void bubble_int_sort(int *p, int n);

int main()
{
     printf("test\n");
    int n;
    while (1)
    {
        /* 读取输入: */
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        int TianJiHorseSpeeds[1000], KingHorseSpeeds[1000];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &TianJiHorseSpeeds[i]);
        }
        for (int i = 0; i < n; i++)
        {

            scanf("%d", &KingHorseSpeeds[i]);
        }
        int winCounts = 0;
        //int draw = 0;
        /* 一下算法是通过小规模的输入示例总结出来的（将问题拆成更细的问题(有时却不是很有必要,如果若干个子问题比较好解决(或者是自己较为熟练掌握的),可以这么考虑拆问题) */
        /* 排序两人的马(从慢到快) */
        bubble_int_sort(TianJiHorseSpeeds, n);
        bubble_int_sort(KingHorseSpeeds, n);
        //先计算出田忌能够赢得的最多的场数(输或平局都无法为田忌争取更高的分值(这里认为是没有扣分的机制))
        for (int i = 0; i < n; i++)
        { //King
            int j = 0;
            
                for (j; j < n; j++)
                {
                    //Yuanzi(TianJi)
                    int delta = TianJiHorseSpeeds[j] - KingHorseSpeeds[i];
                    if (delta > 0)
                    {
                        winCounts++;
                        //将马的速度标记为1,标识该马不能够再次参赛.
                        TianJiHorseSpeeds[j] = -1;
                        KingHorseSpeeds[i] = -1;
                        break;
                    }
                }
        }

        //考虑平局的情况才行:
        //然而,我们亲手那个实例用该粗略的算法演示一下发现,平局的情况不能轻易确定,
        //由于所有比赛情况不外乎三种,那就退一步看输掉的情况:

        /* 考虑平局和输的情况: */
        int loseCounts = 0; //统计田忌输掉的场数(也就是齐王赢得场数.)
        int tempOfKingHorseIndex = 0;
        int i = 0;
        int j = 0;
        for (; i < n; i++)
        { //yuanzi(TianJi)
            int indexOfYuan = n - 1 - i;
            if (TianJiHorseSpeeds[indexOfYuan] == -1)
            {
                continue;
            }

            /* 由于数组内部有许多-1,无法只通过一个循环解决*/
            for (; j < n; j++)
            { //king
                /* 从后往前遍历田忌的马(由好到差);齐王的马则由差倒好, 
                可以知道,此时齐王最差的马都不会慢于此时田忌最好的马,
                所以这时,田忌要么平局,要么输给齐王,所以田忌只能争取尽量多的平局.*/

                if (KingHorseSpeeds[j] == -1)
                {
                    continue;
                }

                {
                    if (TianJiHorseSpeeds[indexOfYuan] < KingHorseSpeeds[j])
                    {
                        loseCounts++;
                    }
                    else
                    {
                        //平局:
                    }
                    //比赛后，将这一对马置为无效马。
                    TianJiHorseSpeeds[indexOfYuan] = -1;
                    KingHorseSpeeds[j] = -1;
                    break;
                }

                /* 要直接统计平局的也可以 */
            }
        }
        /* 判断田忌赢得阐述和输的场数,来判断田忌最终否赢得比赛(而不是其他两种情况:NO) */
        if (winCounts > loseCounts)
        {
            printf("%s", "YES\n");
        }
        else
        {
            printf("%s", "NO\n");
        }
    }
    return 0;
}

void bubble_int_sort(int* p, int n)
{
    void swap_int_pointer(int* a, int* b);
    /*冒泡法不需要设立最值flag. */
    for (int i = 0; i < n - 1; i++)
    {
        /*外重循环从LHS∈[0,n-2]选出一个元素;
        RHS = LHS+1 ∈ [1,n-1]
        单趟比较中:*/
        for (int j = 0; j <= n - 2 - i;
            j++)
        {
            /*内重循环控制各趟排序的一系列比较中:控制LHS从[0,n-2-i]从0取遍n-2-i(i由外重循环弹出的表示现在是第i趟排序) */
            /*通过改变'<'为'>',可以从降序转为升序; 通过监视*(p+j)和*(p+j+1)可以知道当前(第j组)相邻量的值的情况 */
            if (*(p + j) > *(p + j + 1))
            {
                /*或者写作if(p[j] < p[j+1])也可以*/
                swap_int_pointer(p + j, p + j + 1);
            }
        }
    }
}