/*
 * @Description: 
 * @Version: 2.0
 * @Author: xuchaoxin
 * @Date: 2021-01-02 15:32:58
 * @LastEditors: xuchaoxin
 * @LastEditTime: 2021-01-02 16:36:25
 */


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//�ڴ��·������Զ��庯��������:
/**
 * @description: 
 * @param {int} a
 * @param {int} b
 * @param {int} c
 * @return {*}
 * @author: xuchaoxin
 */
void Multi(int a[][3], int b[][2], int c[][2]);
//������main
int main()
{

    int a[2][3], b[3][2], c[2][2];
    /* ��������ѭ���������� */
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
/* ����ִ�о������ĺ��� */
    Multi(a, b, c);
    /* ����������ӡ���� */
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            /* ���е����һ��Ԫ��������2,�Ǿ�����2֮ǰ��Ԫ�ؿ��Ը�һ���ո� */
            printf("%d", c[i][j]);
            if (j < 1)
            {
                printf(" ");
            }
        }
        //printf("%d\n");//������Ȥ��:��ӡ��ֵ
        printf("\n");
    }

    return 0;
}
//����������.
//���·���д�Զ��庯��:
void Multi(int a[][3], int b[][2], int c[][2])
{

    /* mxk , kxn ;������������mxn*/
    int m = 2; /* ����A������ */
    int n = 2; /* ����B������ */

    int p = 3; /* ����A����������;���B��������ͬ,����ֵ��Ϊk */
    /* ��������ÿһ��Ԫ��ֵ��һ��k��ʽ�ĺ� */

    /* �ǵ���c�е�Ԫ���ۼ�ֵ֮ǰ��ʼ��c  */
    /* �ɽ������C�Ĺ��m*n��֪,Ӧ��������ѭ����������C�����к��зֱ���m,n */
    for (int i = 0; i < m; i++) /* �����б���(����A��) */
    {
        for (int j = 0; j < n; j++) /* �����б���(����B����) */
        {
            c[i][j] = 0;                //��ʼ���ۼӼ�����
            for (int k = 0; k < p; k++) /* k��Ϊ����Ԫ�ص�������(Ϊ��������������(������,����A�������,����B�������)) */
            {
                c[i][j] += a[i][k] * b[k][j]; //������b ����
            }
        }
    }
}
