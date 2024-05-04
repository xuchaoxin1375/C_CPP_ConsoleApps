#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ���ְ�ָ��swap() */
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
        /* ��ȡ����: */
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
        /* һ���㷨��ͨ��С��ģ������ʾ���ܽ�����ģ��������ɸ�ϸ������(��ʱȴ���Ǻ��б�Ҫ,������ɸ�������ȽϺý��(�������Լ���Ϊ�������յ�),������ô���ǲ�����) */
        /* �������˵���(��������) */
        bubble_int_sort(TianJiHorseSpeeds, n);
        bubble_int_sort(KingHorseSpeeds, n);
        //�ȼ��������ܹ�Ӯ�õ����ĳ���(���ƽ�ֶ��޷�Ϊ�����ȡ���ߵķ�ֵ(������Ϊ��û�п۷ֵĻ���))
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
                        //������ٶȱ��Ϊ1,��ʶ�����ܹ��ٴβ���.
                        TianJiHorseSpeeds[j] = -1;
                        KingHorseSpeeds[i] = -1;
                        break;
                    }
                }
        }

        //����ƽ�ֵ��������:
        //Ȼ��,���������Ǹ�ʵ���øô��Ե��㷨��ʾһ�·���,ƽ�ֵ������������ȷ��,
        //�������б���������������,�Ǿ���һ������������:

        /* ����ƽ�ֺ�������: */
        int loseCounts = 0; //ͳ���������ĳ���(Ҳ��������Ӯ�ó���.)
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

            /* ���������ڲ������-1,�޷�ֻͨ��һ��ѭ�����*/
            for (; j < n; j++)
            { //king
                /* �Ӻ���ǰ������ɵ���(�ɺõ���);�����������ɲ��, 
                ����֪��,��ʱ�����������������ڴ�ʱ�����õ���,
                ������ʱ,���Ҫôƽ��,Ҫô�������,�������ֻ����ȡ�������ƽ��.*/

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
                        //ƽ��:
                    }
                    //�����󣬽���һ������Ϊ��Ч��
                    TianJiHorseSpeeds[indexOfYuan] = -1;
                    KingHorseSpeeds[j] = -1;
                    break;
                }

                /* Ҫֱ��ͳ��ƽ�ֵ�Ҳ���� */
            }
        }
        /* �ж����Ӯ�ò�������ĳ���,���ж�������շ�Ӯ�ñ���(�����������������:NO) */
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
    /*ð�ݷ�����Ҫ������ֵflag. */
    for (int i = 0; i < n - 1; i++)
    {
        /*����ѭ����LHS��[0,n-2]ѡ��һ��Ԫ��;
        RHS = LHS+1 �� [1,n-1]
        ���˱Ƚ���:*/
        for (int j = 0; j <= n - 2 - i;
            j++)
        {
            /*����ѭ�����Ƹ��������һϵ�бȽ���:����LHS��[0,n-2-i]��0ȡ��n-2-i(i������ѭ�������ı�ʾ�����ǵ�i������) */
            /*ͨ���ı�'<'Ϊ'>',���Դӽ���תΪ����; ͨ������*(p+j)��*(p+j+1)����֪����ǰ(��j��)��������ֵ����� */
            if (*(p + j) > *(p + j + 1))
            {
                /*����д��if(p[j] < p[j+1])Ҳ����*/
                swap_int_pointer(p + j, p + j + 1);
            }
        }
    }
}