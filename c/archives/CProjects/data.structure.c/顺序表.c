/*��8������
�����������ݣ����������е����������в��������в����Գ���

��3��˼��
��1����̬����(��̬����)
�ڵ�ǰ��˳����������Ͷ����У�����ʹ�þ�̬���������Ԫ�أ����һ��˳������ֻ�ܴ��MAXLEN��Ԫ�ء�
Ϊ�˴�Ÿ���Ԫ�أ�����Ҫ�ܹ��Դ�ſռ������չ��Ϊ��ʵ����һĿ�꣬���ǿ���ʹ�ö�̬���������Ԫ�ء�
��ʱ��˳������ݽṹ���Ϳ��Զ������£� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct
{
    int* elem; // ָ��������ű�Ԫ�صĶ�̬����ռ�
    int size;  // ������̬����ռ�Ĵ�С
    int n;          // ����һ����������¼������ʵ�ʴ�ŵ�Ԫ�صĸ���
} intVec;
// /* ��ʼ��ʱ��Ϊ˳�����һ���̶���С������ռ䡣��������Ԫ��ʱ��
// �����洢�ռ������������¿���һ�����������ռ䣨ͨ��Ϊԭ�ռ��������С����
// ��ԭ����ռ��д洢��Ԫ�ؿ�����������ռ��У�����������ռ����ԭ����ռ���Ϊ˳���Ĵ洢�ռ䣬
// �������԰���Ԫ�ط��뵽˳����С�

// ����ʵ�ֻ��ڶ�̬�����˳����䳣���㷨��
// ��2��˳����Ӧ��
// Ŀ�꣺�ܹ�����˳��������һЩʵ��Ӧ�����⡣

// ��1��������
// ��������˳������LA��LB���û��������������������ݣ����ֱ����β��뵽˳���LA��LB�С�

// ʵ���㷨���ϲ�LA��LB�е����ݣ����Ѻϲ�������ݴ�ŵ�LA�С�
//������ζ�ȡ�����LA�е�����Ԫ�ء�
void againMalloc(intVec* L);
void initList(intVec* L, int ms);
void insert_last_list(intVec* L, int x);
int search(intVec* LA, int e);
void UnionSet(intVec* LA, intVec* LB);
void batchInsertList(intVec* L);
void print(intVec* L);
void intersectionSet(intVec* LA, intVec* LB, intVec* LC);

int main()
{
    intVec LA, LB;
    intVec LC;
    printf("LA�������Ϊ:1 2 3 4 5 6 -1\n");
    batchInsertList(&LA);
    printf("LB�������Ϊ:3 4 5 6 7 8 9 -1 \n");
    batchInsertList(&LB);

    printf("���Բ�������UnionSet()\n");
    UnionSet(&LA, &LB);
    printf("�������LA:\n");
    print(&LA);

    //printf("���Խ�������intersection()\n");
    //initList(&LC,5);/*������ʼ��LC��*/
    //intersectionSet(&LA, &LB, &LC);
    //printf("�������LC:\n");
    //print(&LC);
    
}
//˳�����������������Ҫ��Щ.
void print(intVec* L)
{
    int i = 0;
    for (i = 0; i < L->n; i++)
    {
        printf("%d ", L->elem[i]);
    }
}
/*��������(��ʼ�����ȴ���������)Ԫ�ص�˳�����*/
void batchInsertList(intVec* L)
{
    int ms = 20;
    int i=0;
    initList(L, ms);
    printf("��˳��������Ԫ��:\n");
    scanf("%d", &i);
    while (i != -1)/* -1��Ϊ��������ı�־ */
    {
        insert_last_list(L, i);
        scanf("%d", &i);
    }
}
/* �����Ա�L�е�pos��Ԫ�ز���x,������ɹ�����1,���򷵻�0 */
int insertPosList(intVec* L, int pos, int x)/* ��insert_last_list()ʹ�÷�Χ�����ǿ�� */
{
    int i;
    /* �Ƿ�Խ�� */
    if (pos < 1 || pos > L->n + 1)
    {
        /* "posԽ��,����ʧ��,����0; */
        return 0;
    }
    /* �Ƿ�Ҫ�ؿ�ռ� */
    if (L->n == L->size)
    {
        againMalloc(L);
    }/* ȷ���ռ��㹻/��Ȼ�������������������.againmalloc */

    for (i = L->n - 1; i >= pos - 1; i--)
    {
        L->elem[i + 1] = L->elem[i];
    }/* �Ѿ��ڳ�λ���� */
    L->elem[pos - 1] = x;/* ִ�в��� */
    L->n++;/* ������ */
    return 1;/* ����ɹ�����1 */
}
// �ϲ�����˳�����㷨��ͨ�����º���ʵ�֣� */
void UnionSet(intVec* LA, intVec* LB)
{
    /**********************************************************
    �ϲ�LA��LB��ָ�������˳�������е����ݣ����Ѻϲ�������ݴ����LA��
    *********************************************************/
    int nA, nB, i, e;

    nA = LA->n; // ˳���LA�е�Ԫ�ظ���
    nB = LB->n; // ˳���LB�е�Ԫ�ظ���

    // �����ȡLB�е�Ԫ�أ�����Ԫ�ز���LA�У���Ѹ�Ԫ�ز��뵽LA��
    for (i = 1; i <= nB; i++)/* ���ѭ����������Ϊ������Ԫ�����ڼ���(����)��Ԫ�ظ��� */
    {
        e = LB->elem[i - 1]; // ��ȡLB�еĵ�i��Ԫ��
        if (search(LA, e) == -1)/*ʱ�临�Ӷ�ΪO(n)*/
        {
            // ����Ԫ�ز���LA��
            insert_last_list(LA, e);     // �Ѹ�Ԫ�ز��뵽LA�ı�β
            nA++; // ��¼LA�е�ǰ��Ԫ�ظ���
        }
    }
}
/*�����󽻼�:*/
void intersectionSet(intVec* LA, intVec* LB, intVec* LC)
{
    int i = 0;
    for (i = 0; i < LA->n; i++)
    {
        if (search(LB, LA->elem[i]) != -1)
        {
            insert_last_list(LC, LA->elem[i]);
        }
    }
}
void insert_last_list(intVec* L, int x)
{
    /* �����β�Ļ������ж�Խ��.����ȻҪ�жϿռ��Ƿ��㹻. */
    if (L->n == L->size)
    {
        againMalloc(L);/* ��Ҫ���·������ռ� */
    }
    L->elem[L->n] = x;/* ��x���뵽��β */
    L->n++;/* ���Ա���+1 */
}
void againMalloc(intVec* L)
{
    int* p = (int*)realloc(L->elem, 2 * L->size * sizeof(int));
    if (!p)
    {
        printf("reallo failured !");
        exit(1);
    }
    L->elem = p;/* ʹ��ͷָ��ָ���·��������ռ� */
    L->size = 2 * L->size;
}
void initList(intVec* L, int ms)/* ����L��ʱ��main()��ͷ����һ��intVec���͵ı���L,Ȼ�󽫸ñ����ĵ�ַ&L����initlist�������� */
{
    if (ms < 0)
    {
        printf("maxsize is illegal");
    }
    L->elem = (int*)malloc(ms * sizeof(int));
    if (!L->elem)
    {
        printf("malloc failured");
        exit(1);
    }
    L->size = ms;/* �������Ա�Ŀռ��СΪms */
    L->n = 0; /*��������Ԫ����Ϊ0 */
}
int search(intVec* LA, int e)
{
    int i = 0;
    for (i = 0; i < LA->n; i++)
    {
        if (LA->elem[i] == e)
        {
            return i;
        }
    }
    return -1;
}

// /* 
// ��2��������
// ���Ƶأ����Ա�д���������󽻳��򡣶�������˳������LA��LB��
// �û��������������������ݣ����ֱ����β��뵽˳���LA��LB�С�ʵ���㷨����LA��LB�е����ݽ����󽻣�
// ���������ŵ�һ���µ�˳������LC�С�������ζ�ȡ�����LC�е�����Ԫ�ء�����˳�������㷨��ͨ�����º���ʵ�֣� */
// /**********************************************************
// 	��LA��LB��ָ�������˳����е����ݽ����󽻣���������LC��
// *********************************************************/
// void IntersectSet(intVec *LA, intVec *LB, intVec *LC);
// /* ��3���ۺ���ϰ
// �ھ���Ӧ�ó����У�����ʹ��˳������洢�͹������ݡ����Ҫ��ʵ��һ���򵥵��������ݹ���ϵͳ������Ҫ�����£�
// ��4������һ���򵥵Ŀɽ���ϵͳ���û�������ϵͳ�в��롢ɾ���Ͳ�������������ͳ��ϵͳ�е�����������
// ��5��ʹ��˳������洢�������ݣ� */
