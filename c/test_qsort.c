#include <stdio.h>
#include <stdlib.h>

int values[] = { 88, 56, 100, 2, 25 };

int cmpfunc(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int n;

    printf("����֮ǰ���б�\n");
    for (n = 0; n < 5; n++) {
        printf("%d ", values[n]);
    }

    qsort(values, 5, sizeof(int), cmpfunc);

    printf("\n����֮����б�\n");
    for (n = 0; n < 5; n++) {
        printf("%d ", values[n]);
    }

    return(0);
}
//�����Ǳ��벢��������ĳ����⽫�������½����
//
//����֮ǰ���б�
//88 56 100 2 25
//����֮����б�
//2 25 56 88 100

