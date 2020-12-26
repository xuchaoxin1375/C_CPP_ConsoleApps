/*ʵ���� ������Ӧ��
������������ַ���ɵ��������У����硰������abcd�����䳣���������������Ĳ��ҡ����ıȽϵȡ���ʵ��ʵ�ִ�������һЩ���Ӧ�á�
��1��ʵ��Ŀ��
��2�����մ��ĳ��ò������磺���Ĳ��ҡ����ıȽϵȣ�
��3�����մ���Ӧ�á�
��4��ʵ������
��5������ʵ��
Ŀ�꣺����һ�ִ������ݽṹ���ͣ���ʵ���䳣���㷨��
��6���㷨��գ����ݹ�����ʾ�������»��ߴ��Ĵ��롣
��7�����������͵Ķ���
������Ӧ�Ľṹ���������ͣ�������ʾ����һ���ݽṹ����*/

#define _CRT_SECURE_NO_WARNINGS
#define   EMPTY_QUEUE_ERROR   -999999
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLEN 100
/*���崮�ṹ,��ֱ��ʹ���ַ����鲻ͬ����,���ṹ�����ֱ�Ӷ�ȡ���ĳ���,���Ҵ��ṹ�б����ַ��������й�'\0'���Դ��ĳ��Ȳ���ӡ��,д���lengthֵ��Ψһ����ֵ*/
typedef struct {
	char* ch;   // ������Ŵ����ַ���  ��̬����
	int length;  // ��¼���ĳ���
}MString;
/*��8����ʼ����
��ʹ�ô�֮ǰ����ʼ����Ϊһ���մ�������ͨ��һ������ʵ�ָò�������������һ������ʼ���Ĵ��ĵ�ַ��Ϊ������*/
void InitString(MString* s)
{
	/**********************************************************
	��ʼ��sָ��Ĵ�Ϊ�մ�
	*********************************************************/

	s->ch = 0;  // ���ô��洢�ռ�Ϊ��
	s-> length= 0;  // ���ô��ĳ���Ϊ0���մ�

	return;
}
/*��9������ֵ(���߽���վɴ��������´�,
����ֵ������ ����һ���µ�  �ַ����С�*/
void AssignString(MString* s, char* cs)
{
	/**********************************************************
	��  csָ����ַ���  ����sָ��Ĵ�����
	*********************************************************/
	int len = strlen(cs);

	if (s->length != len) { // ������ռ����ַ�����С��ͬ�������¿ռ�
		if (s->length) { // �������ԭ��  �ռ�ǿգ���Ҫ�ͷ��Ͽռ�
			free(s->ch);
		}
		s->ch = (char*)malloc(sizeof(char) * len); // �����µĴ��洢�ռ�
	}
	/*memcpy():�ڴ濽������������ԭ��Ϊvoid *memcpy(void *destin, void *source, unsigned n)��
	�����Ĺ����Ǵ�Դ�ڴ��ַ����ʼλ�ÿ�ʼ  �������ɸ��ֽ�  ��Ŀ���ڴ��ַ�У�����Դsource�п���n���ֽڵ�Ŀ��destin�С�*/
	memcpy(s->ch, cs, sizeof(char) * len); // ���ַ���������
		/*��realloc()�Ƚ���:
		reallocԭ����extern 
		void *realloc(void *mem_address, unsigned int newsize);
		void *realloc(void *ptr, size_t size) �������µ���֮ǰ���� malloc �� calloc ������� ptr(�� mem_address) ��ָ����ڴ��Ĵ�С
		�﷨: ָ����=����������*��realloc��Ҫ�ı��ڴ��С��ָ�������µĴ�С����
�µĴ�С�ɴ��С������µĴ�С����ԭ�ڴ��С�����·��䲿�ֲ��ᱻ��ʼ��,ԭ�е����ݻ�õ�����(�ᱻ����ճ�������ڴ�ռ�)������µĴ�СС��ԭ�ڴ��С�����ܻᵼ�����ݶ�ʧ*/
	
	s->length = len; // ���ô��ĳ���
}
/*��10���Ƚϴ�(�൱��stringcmp()
����������S��T������S > T��S = T��S < T���ֱ𷵻� ��ֵ��0����ֵ��
ֻ�����,��ͷ�һ�˼���*/
int CompareString(MString* S, MString* T)
{
	/**********************************************************
	�Ƚ�S��T��ָ���������
	*********************************************************/
	int i,
		//cmpSize_gt = ((S->length >= T->length ? S->length : T->length)),
		cmpSize = (S->length <= T->length ? S->length : T->length);/*cmpSize�����ʱ�ַ���S,T��  ��С�ߵĳ���.*/

	// 1. ���������ķ�Χ�ڣ���ǰ��������Ƚ�S��T�е�ÿ���ַ���
	// ������ĳ���ַ����ȣ����S�еĸ��ַ�<T�еĸ��ַ������� S<T�����򷵻�S>T(����S > T��S = T��S < T���ֱ𷵻� ��ֵ��0����ֵ��)
	{
		/*for (int i = 0; i < cmpSize_gt; i++)
		{}*/
			for (int i = 0; i < cmpSize; i++)
			{
				if (S->ch[i] < T->ch[i])
				{
					return S->ch[i] - T->ch[i];
				}
				else if(S->ch[i] > T->ch[i])
				{
					return S->ch[i] - T->ch[i];
				}
				else
				{
					/*pass*/
				}
			}
			return S->length - T->length;
		
	}

	// 2. ����  �������ķ�Χ�ڣ���Ӧ�ַ�����ȡ������ݴ��ĳ����ж�
	// �������Ĵ�С
	if (S->length == T->length)
		return 0;
	else if (S->length < T->length)
		return -1;
	else
		return 1;
}
/*��11������
ʹ���������������������룬���в����Գ���*/
void main_1()
{
	MString s, t;  // ��������������

	// 1. ��ʼ�����������������
	{
		InitString(&s);
		InitString(&t);

	}

	// 2. �ֱ𽫡�hello, string���͡�ni hao, string������s��t
	{
		AssignString(&s, "hello,string");
		AssignString(&t, "ni hao, string");
		
	}

	// 3. �Ƚ��������Ĵ�С��������ȽϽ������Ȼ�˭��˭С
	{
		printf("�ֱ𽫡�hello, string���͡�ni hao, string������s��t:\n");
		int a = CompareString(&s, &t);
		if (a > 0)
		{
			printf("��S > T.\n");
		}
		else if (a == 0)
		{
			printf("��S = T.\n");
		}
		else
		{
			printf("��S < T.\n");
		}
	}


}
//��12���㷨��ϰ�����ݹ�����ʾ��ʵ���㷨��
/*��13����ȡ�����ַ�
��ȡ���е�ĳ���ַ�����ȡλ�ñ����ڴ��ĳ��ȷ�Χ֮�ڣ���[1, length]��lengthΪ�����ַ����еĳ��ȡ�����ԭ�����£�
*/
/**********************************************************
��ȡsָ��Ĵ��е�i��λ�ô����ַ�
*********************************************************/
char StrAt(MString* s, int i)
{
	if (i<0 || i >s->length)
	{
		printf("�Ƿ���ȡ:\n");
		exit(1);
	}
	return s->ch[i];
}


/*��14����ȡ�Ӵ�
����һ�����������ַ����е�ĳ��λ�ÿ�ʼ����ȡ���ɸ��ַ����γɸô���һ���Ӵ�������ȡ�ɹ�������1�����򣬷���0������ԭ�����£�
*/
/**********************************************************
�ӵ�i���ַ���ʼ����sָ��Ĵ��ж�ȡlen���ַ����γ�һ���Ӵ�����
�洢��subָ��Ĵ���
*********************************************************/
void Print_string(MString* s)
{
	//printf("\n");
	for (int i = 0; i < s->length; i++)
	{
		putchar(s->ch[i]);
	}
	printf("\n");
}

int SubString(MString* sub, MString* s, int i, int len)/*i��1����*/
{
	/*��i�Ǵ�1����*/
	if (i<1 || i + len -1 > s->length)
	{
		printf("��ȡ��ʼλ�÷Ƿ�:\n");
		return 0;
	}

	sub->length = len;
	sub->ch = (char*)malloc(len * sizeof(char));/*��Ҫ�����ڴ��������ʹ��*/
	int j = 0;/*j��s���ĵ�j���ַ�λ��*/
	/*д���������������һ��ʾ��ͼ:*/
	for ( j = i; j < i+len; j++)/* j<i+len ����  j <= i+len-1 �����*/
	{
		sub->ch[j - i] = s->ch[j-1];/*��������,λ�ò���-1*/
	}
	//Print_string(sub);�������������������㷨�Ĳ��ҹ���.
	return i;
}
/*��15���ϲ��ַ���
����������S1��S2��ͨ����S2�е��ַ�����׷����S1�е��ַ�����֮�󣬺ϲ������������Ѻϲ�����ַ����з����´�T�С�
�㷨ʵ����ʾ��1��
��鴮T�Ŀռ��Ƿ���ϲ�����ַ����и�����ȡ��粻�ȣ�ΪT�����µĴ��ռ䣻
2�����ΰ�S1��S2�е��ַ����п�����T�Ĵ��ռ��С�����ԭ�����£�
*/
/**********************************************************
�ϲ�S1��S2��ָ���������������   �ϲ�����洢��Tָ��Ĵ���
*********************************************************/
void ConcatString(MString* T, MString* S1, MString* S2)
{
	/*��鴮T�Ŀռ��Ƿ���ϲ�����ַ����и�����ȡ��粻�ȣ�ΪT�����µĴ��ռ䣻
	��Ϊ�����T�������µ�Ҳ�����Ǿɵ�.*/
	int ret = 0;
	//int sum_len_S12 = 0;
	ret = T->length == S1->length + S2->length;/*K&R*/
	T->length = S1->length + S2->length;
	if (!ret)
	{
		T->ch = (char*)malloc(sizeof(char) * T->length);
	}
	
	for (int i = 0; i < T->length; i++)
	{
		if (i < S1->length)
		{
			T->ch[i] = S1->ch[i];
		}
		else
		{
			T->ch[i] = S2->ch[i - S1->length];
		}
	}
}
/*��16����մ�
��������ʹ��ʱ����Ҫ�ͷ����еĶ�̬�����ڴ棬��ͨ�����º���ʵ�֣�
*/
/**********************************************************
�ͷ�sָ��Ĵ��������ڴ�ռ�
*********************************************************/
void ClearString_temp(MString* s)/*���ڴ˴���ΪClearString()*/
{
	free(s->ch);
}

/*��17������
�����������ݣ����������е����������в��������в����Գ���*/
//(18)Ӧ��


/*��19�������Ӵ�//�����㷨
��������������S��T���û����������ַ��������ֱ𸳸���S��T��
ʵ���㷨���Ӵ�S�е��ַ����е�ĳ��ָ��λ�ÿ�ʼ������  ��T��ȵ��Ӵ���
�����ҳɹ�����ӡ����һ���������Ӵ���S�е�λ�ã������ӡ����ʧ��
�������Ӵ����㷨��ͨ�����º���ʵ�֣�
*/
/**********************************************************
��Sָ��Ĵ��ĵ�i���ַ���ʼ��������T��ȵ��Ӵ���
�����ҳɹ������ص�һ���������Ӵ���S�е�λ�ã����򷵻�0
*********************************************************/

int SubIndex(MString* S, MString* T, int i)/*i��1����*/
{
	
	int j;
	MString sub;/*�����ʱSubindex()�ڲ������,ʹ������ʱ��Ҫ&sub*/

	// �Ӵ�S�еĵ�i���ַ���ʼ(j = i)����ȡ�봮T������ȵ� �Ӵ���
	// �Ƚϸ��Ӵ��Ƿ���T��ȡ�����ȣ����ҳɹ���
	// ���򣬴ӵ�i+1���ַ���ʼ��������ȡ�Ӵ�����T�Ƚ�
// ��������������ֱ�����ҳɹ����Ӵ���ȡʧ��Ϊֹ
	InitString(&sub);

	for (j = i; j <= S->length; j++) {
		// �ڴ�S�дӵ�j���ַ���ʼ��ȡ����ΪT->length���Ӵ�
		// ���洢�ڴ�sub��
		if (!SubString(&sub,S,j,T->length)) { // ��ȡ�Ӵ�����ʧ��
			return 0;
		}
		if (CompareString(&sub,T) == 0) { // �Ƚ���ȡ���Ӵ��ʹ�T�������
			return j;
		}
	}
	ClearString(&sub);

	return 0;
}
/*void Print_string(MString* s)
{
	//printf("\n");
	for (int i = 0; i < s->length; i++)
	{
		putchar(s->ch[i]);
	}
	printf("\n");
}*/
void Print_string(MString* s);
int SubIndex(MString* S, MString* T, int i);
int main_2()
{
	MString s, t,
		sub,
		str_cat;  // ���崮����

	// 1. ��ʼ�����������������

	InitString(&s);
	InitString(&t);
	InitString(&sub);//�����ݽṹ��ͬʱ(ʹ��ǰ)Ҫ�����ʼ��,��������;

	// 2. �ֱ𽫡�hello, string���͡�ni hao, string������s��t

	/*
	printf("�ֱ𽫡�hello, string���͡�ni hao, string������s��t:\n");
	AssignString(&s, "hello,string");	AssignString(&t, "ni hao, string");*/
	printf("�ֱ�\"nia1123o\"��\"12\"����s��t:\n");
	AssignString(&s, "nia1123o");	AssignString(&t, "12");

/*
	printf("����AssignString():\n");
	Print_string(&s);
	Print_string(&t);

	
	printf("����StrAt(&s, 4);\n");
	putchar(StrAt(&s, 4)); printf("\n");

	printf("����SubString(&sub, &s, 3, 4);\n");
	SubString(&sub, &s, 3, 4);
	Print_string(&sub);

	printf("����ConcatString(&str_cat, &s, &t):\n");
	ConcatString(&str_cat, &s, &t);
	Print_string(&str_cat);
*/	
	/**/
	printf("����SubIndex(&s, &t, 1):\
		\n��%d��λ�ó��ֵ�һ���Ӵ�.(0��ʾû���Ӵ�)\n", SubIndex(&s, &t, 1));
		/*��Sָ��Ĵ��ĵ�i���ַ���ʼ��������T��ȵ��Ӵ��������ҳɹ������ص�һ���������Ӵ���S�е�λ�ã����򷵻�0*/
	

}
/*�������Ӵ������㷨ʱ�临�ӶȲ��������ŵģ�����ڽ϶���ַ��ظ��Ƚϡ�
KMP��Knuth - Morris - Pratt���㷨��һ�ָ�Ч���ַ���ƥ���㷨����ѯ������ϣ���Ⲣ����ʵ�ָ��㷨��
��20���ۺ���ϰ
ʵ��һ���򵥵Ĵ�����ϰ���򡣻���Ҫ�����£�
��21�����ı��ļ��ж�ȡ�ο��ı����ݣ����洢��һ���������У�
��22������һ���򵥵Ŀɽ���ϵͳ��Ҫ��
��23���ο��ı����ݸ�����ʾ��
��24�����ϵ��£��û�������ʾ��ÿ�вο��ı���������ȷ���ַ������������ϵͳ����ʾ����
��25���û������ÿ���ַ���ʾ�ڶ�Ӧ�Ĳο��ı��е����棻
ÿ����ϰ��ɺ�ͳ�Ʋ���ӡ����ϰ����ȷ�ʡ�
*/

#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* �洢�ռ��ʼ������ */

typedef int Status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;	/* ElemType���͸���ʵ������������������Ϊint */

typedef char String[MAXSIZE + 1]; /*  0�ŵ�Ԫ��Ŵ��ĳ��� */

/* ����һ����ֵ����chars�Ĵ�T */
Status StrAssign(String T, char* chars)
{
	int i;
	if (strlen(chars) > MAXSIZE)
		return ERROR;
	else
	{
		T[0] = strlen(chars);
		for (i = 1; i <= T[0]; i++)
			T[i] = *(chars + i - 1);
		return OK;
	}
}

Status ClearString(String S)
{
	S[0] = 0;/*  ���Ϊ�� */
	return OK;
}

/*  ����ַ���T�� */
void StrPrint(String T)
{
	int i;
	for (i = 1; i <= T[0]; i++)
		printf("%c", T[i]);
	printf("\n");
}

/*  ���Next����ֵ�� */
void NextPrint(int next[], int length)
{
	int i;
	for (i = 1; i <= length; i++)
		printf("%d", next[i]);
	printf("\n");
}

/* ���ش���Ԫ�ظ��� */
int StrLength(String S)
{
	return S[0];
}

/* ���ص�ģʽƥ�䷨ */
int Index(String S, String T, int pos)
{
	int i = pos;	/* i��������S�е�ǰλ���±�ֵ����pos��Ϊ1�����posλ�ÿ�ʼƥ�� */
	int j = 1;				/* j�����Ӵ�T�е�ǰλ���±�ֵ */
	while (i <= S[0] && j <= T[0]) /* ��iС��S�ĳ��Ȳ���jС��T�ĳ���ʱ��ѭ������ */
	{
		if (S[i] == T[j]) 	/* ����ĸ�������� */
		{
			++i;
			++j;
		}
		else 				/* ָ��������¿�ʼƥ�� */
		{
			i = i - j + 2;		/* i�˻ص��ϴ�ƥ����λ����һλ */
			j = 1; 			/* j�˻ص��Ӵ�T����λ */
		}
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}

/* ͨ�����㷵���Ӵ�T��next���顣 */
void get_next(String T, int* next)
{
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i < T[0])  /* �˴�T[0]��ʾ��T�ĳ��� */
	{
		if (j == 0 || T[i] == T[j]) 	/* T[i]��ʾ��׺�ĵ����ַ���T[j]��ʾǰ׺�ĵ����ַ� */
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];	/* ���ַ�����ͬ����jֵ���� */
	}
}

/* �����Ӵ�T������S�е�pos���ַ�֮���λ�á��������ڣ���������ֵΪ0�� */
/*  T�ǿգ�1��pos��StrLength(S)�� */
int Index_KMP(String S, String T, int pos)
{
	int i = pos;		/* i��������S�е�ǰλ���±�ֵ����pos��Ϊ1�����posλ�ÿ�ʼƥ�� */
	int j = 1;			/* j�����Ӵ�T�е�ǰλ���±�ֵ */
	int next[255];		/* ����һnext���� */
	get_next(T, next);	/* �Դ�T���������õ�next���� */
	while (i <= S[0] && j <= T[0]) /* ��iС��S�ĳ��Ȳ���jС��T�ĳ���ʱ��ѭ������ */
	{
		if (j == 0 || S[i] == T[j]) 	/* ����ĸ�����������������㷨������j=0�ж� */
		{
			++i;
			++j;
		}
		else 			/* ָ��������¿�ʼƥ�� */
			j = next[j];/* j�˻غ��ʵ�λ�ã�iֵ���� */
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}

/* ��ģʽ��T��next��������ֵ����������nextval */
void get_nextval(String T, int* nextval)
{
	int i, j;
	i = 1;
	j = 0;
	nextval[1] = 0;
	while (i < T[0])  /* �˴�T[0]��ʾ��T�ĳ��� */
	{
		if (j == 0 || T[i] == T[j]) 	/* T[i]��ʾ��׺�ĵ����ַ���T[j]��ʾǰ׺�ĵ����ַ� */
		{
			++i;
			++j;
			if (T[i] != T[j])      /* ����ǰ�ַ���ǰ׺�ַ���ͬ */
				nextval[i] = j;	/* ��ǰ��jΪnextval��iλ�õ�ֵ */
			else
				nextval[i] = nextval[j];	/* �����ǰ׺�ַ���ͬ����ǰ׺�ַ��� */
											/* nextvalֵ��ֵ��nextval��iλ�õ�ֵ */
		}
		else
			j = nextval[j];			/* ���ַ�����ͬ����jֵ���� */
	}
}

int Index_KMP1(String S, String T, int pos)
{
	int i = pos;		/* i��������S�е�ǰλ���±�ֵ����pos��Ϊ1�����posλ�ÿ�ʼƥ�� */
	int j = 1;			/* j�����Ӵ�T�е�ǰλ���±�ֵ */
	int next[255];		/* ����һnext���� */
	get_nextval(T, next);	/* �Դ�T���������õ�next���� */
	while (i <= S[0] && j <= T[0]) /* ��iС��S�ĳ��Ȳ���jС��T�ĳ���ʱ��ѭ������ */
	{
		if (j == 0 || S[i] == T[j]) 	/* ����ĸ�����������������㷨������j=0�ж� */
		{
			++i;
			++j;
		}
		else 			/* ָ��������¿�ʼƥ�� */
			j = next[j];/* j�˻غ��ʵ�λ�ã�iֵ���� */
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}

int main_3_kmp()
{
	int i, * p;
	String s1, s2;

	StrAssign(s1, "abcdex");
	printf("�Ӵ�Ϊ: ");
	StrPrint(s1);
	i = StrLength(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	get_next(s1, p);
	printf("NextΪ: ");
	NextPrint(p, StrLength(s1));
	printf("\n");

	StrAssign(s1, "abcabx");
	printf("�Ӵ�Ϊ: ");
	StrPrint(s1);
	i = StrLength(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	get_next(s1, p);
	printf("NextΪ: ");
	NextPrint(p, StrLength(s1));
	printf("\n");

	StrAssign(s1, "ababaaaba");
	printf("�Ӵ�Ϊ: ");
	StrPrint(s1);
	i = StrLength(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	get_next(s1, p);
	printf("NextΪ: ");
	NextPrint(p, StrLength(s1));
	printf("\n");

	StrAssign(s1, "aaaaaaaab");
	printf("�Ӵ�Ϊ: ");
	StrPrint(s1);
	i = StrLength(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	get_next(s1, p);
	printf("NextΪ: ");
	NextPrint(p, StrLength(s1));
	printf("\n");

	StrAssign(s1, "ababaaaba");
	printf("   �Ӵ�Ϊ: ");
	StrPrint(s1);
	i = StrLength(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	get_next(s1, p);
	printf("   NextΪ: ");
	NextPrint(p, StrLength(s1));
	get_nextval(s1, p);
	printf("NextValΪ: ");
	NextPrint(p, StrLength(s1));
	printf("\n");

	StrAssign(s1, "aaaaaaaab");
	printf("   �Ӵ�Ϊ: ");
	StrPrint(s1);
	i = StrLength(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	get_next(s1, p);
	printf("   NextΪ: ");
	NextPrint(p, StrLength(s1));
	get_nextval(s1, p);
	printf("NextValΪ: ");
	NextPrint(p, StrLength(s1));

	printf("\n");

	StrAssign(s1, "00000000000000000000000000000000000000000000000001");
	printf("����Ϊ: ");
	StrPrint(s1);
	StrAssign(s2, "0000000001");
	printf("�Ӵ�Ϊ: ");
	StrPrint(s2);
	printf("\n");
	printf("�������Ӵ��ڵ�%d���ַ����״�ƥ�䣨����ģʽƥ���㷨��\n", Index(s1, s2, 1));
	printf("�������Ӵ��ڵ�%d���ַ����״�ƥ�䣨KMP�㷨�� \n", Index_KMP(s1, s2, 1));
	printf("�������Ӵ��ڵ�%d���ַ����״�ƥ�䣨KMP�����㷨�� \n", Index_KMP1(s1, s2, 1));

	return 0;
}

