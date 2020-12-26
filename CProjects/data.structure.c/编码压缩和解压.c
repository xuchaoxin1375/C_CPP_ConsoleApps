
#define _CRT_SECURE_NO_WARNINGS
#define   EMPTY_QUEUE_ERROR   -999999
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLEN 100
/*��29������������
3. ���ݴʻ��Huffman����  �����¾���  ���� ���� ѹ���ͽ�ѹ����
��love is love, this commandment is always said by Marbury, which means that one person always love any other person.��
��Ҫ��ͳ��һ�¸����ʵĴ�Ƶ,������������,�õ�ÿ�����ʵ�Huffman����,�ٸ��ݸ����ľ���(��������(���ظ�))���ζ�Ӧ�ı�����������
*/
/*
��ʾ����α��桰0����1�����ı����ʡ�ռ䣿
������������ 0100��1011��������ַ����鱣����Ҫ8���ֽڣ�
������ö����Ʊ�ʾΪ��0100 1011��������һ���ַ���K��(��ASCII��Ϊ75��75�Ķ�����Ϊ�� 01001011��)���ɱ�ʾ���������롣
������λ�����ѹ��Ϊ�����ַ���
*/
/*Ϊ�˽��������ѹ��������,��Ҫ��д��������ת��Ϊʮ������,�Ա�ת��ΪASCII,�̶�ͨ��putchar()��ASCII�뽫����ѹ��������ݱ������*/
/*�෴��,Ϊ��ʵ�ֽ���,���ַ����ĸ��ַ���ASCIIת��Ϊ01���봮����*/

 //Huffman���Ĵ洢�ṹ
#define n 15					//Ҷ����Ŀ
#define m 2*n-1					//���н������
#define ZIP_bits 7 //ѹ�������λ��
/*��������ʵ�ֵľ�̬������˫�׽����������ݽṹ*/
/*Huffman���Ļ����������(��㱾���Ȩ�Լ������������������/��ϵ*/
typedef struct					//�������(Ҷ�ӽڵ�)
{
	float weight;				//Ȩֵ��������Ȩֵ��������(������ֵ)
	int lchild, rchild, parent;	//���Һ��Ӽ�˫��ָ��
}HTNode;
/*Huffman����Ľṹ��(�ڵ�������͵�����),ֻ���(��Ȩ��)Ҷ�ӽڵ�*/
typedef HTNode HuffmanTree[m];	//HuffmanTree����������/*��������������(���Ҳ������������������)Ԫ����Ŀ��Huffman���Ľ������m*/

/*Huffuman���ĸ��������ĸ��ӱ�����Ϣ*/
typedef struct
{
	char str[MAXLEN];					//�洢�ַ�������
	char bits[n + 1];		//��� ����λ��(0,1����)
}CodeNode;
/*huffman�������� ��������Ϣ����*/
typedef CodeNode HuffmanCode[n];/*��������������(���Ҳ������������������)Ԫ����Ŀ��Huffman����Ҷ�ӽڵ���Ŀn*/

int To_letter(char* str_01)
{
	int len = strlen(str_01);
	int sum = 0;
	for (int i = len-1; i >= 0; i--)
	{
		sum = sum + (int)str_01[i] * pow(2, len - 1 - i);
	}
	return sum;
}
int To_char_Ascii_7bit(char* str_01)
{
	int sum = 0;
	for (int i = 0; i < ZIP_bits; i++)
	{
		//sum = sum + (int)(*(str_01 + i)) * pow(2, 7 - i);
		sum = sum + (*(str_01 + i)-48) * pow(2, ZIP_bits-1 - i);
	}
	return sum;
}
void InitHuffmanTree(HuffmanTree T);	//��ʼ��Huffman��
void InputWeight(HuffmanTree T);		//����Ȩֵ
void SelectMin(HuffmanTree T, int i, int* p1, int* p2);
/*huffman��*/
void main()/*������㹻�ߵĻ�,�ַ�(����)�ı�����̳��ȿ��Գ���1*/
{
	/*�ڲ�������������:*/
	/*���ǵ���!!!1*/
	void CreateHuffmanTree(HuffmanTree T);	//����:����Huffman���ĺ���
	void CharSetHuffmanEncoding(HuffmanTree T, HuffmanCode H); //����:������ڵ�Ĺ���������,����������ڲ���H�еĺ���.
	/*��������Huffman�����͵ı���(��ʼ�ǽ�����͵�����)*/
	HuffmanTree T;
	HuffmanCode H;

	CreateHuffmanTree(T);/*main()�к������Ⱥ���������߼���ϵ��,ǰ��ĺ������ÿ��ܶԺ�����õĺ�����
						 ����������Ӱ������ʼ���ݽṹ/������ݽṹ..�Ա����ĵ��ÿ�����ȷ����*/
	CharSetHuffmanEncoding(T, H);
}
/*�����Ķ���¼(ʾ��):
* 700->713->715
*/

void CreateHuffmanTree(HuffmanTree T)//main()_1����(����Huffman��,���Ϻ���)
{ 	//����Huffman����T[m-1]Ϊ������
	int i, p1, p2;
	InitHuffmanTree(T);		//��T��ʼ��
	InputWeight(T);			//����Ҷ��Ȩֵ��T[0..n-1]��weight��

	for (i = n; i < m; i++)		/*������n-1�κϲ����½�����δ���T[i]��;��n->m��Щ�ڵ��Ƿ�Ҷ�ӽڵ�(���ڹ������Ǵ����n��Ҷ��)���ǵ�Ȩֵ
								�����Ҷ�ӽڵ�ϲ��õ�,֮��Ҳ�ɳ�Ϊ���ϲ��Ķ���,����T����(ÿ�ϲ�һ��,T�еĽ��ͻ���һ��:(����һ���½��,���������ɽ��)
								��Ȼ���𱣴������Ϣ�� ����H �еĽ�㲻�ᱻɾ��*/
	{
		SelectMin(T, i - 1, &p1, &p2);
		//��T[0..i-1]��ѡ�� ���� Ȩ��С�� ����㣬����ŷֱ�Ϊp1��p2
		T[p1].parent = T[p2].parent = i;/*i�ǵ�ǰ����T�����һ��������һ����λ������,�൱�ڰ�p1��p2�ҽӵ��ô�*/
		/*������СȨ���ʹ�СȨ�����ҹ�ϵ*/
		T[i].lchild = p1;		//��СȨ�ĸ������ �½�������
		T[i].rchild = p2;		//��СȨ�ĸ������ �½����Һ���
		/*�½���T[i].parent ��ʱ��Ȼ���ڱ�InitHuffman��ʼ����NULL(���ĳ���½���T[i].parent����û�б��޸�(����ΪNULL)�����T[i]����Huffman�����ܸ����*/
		T[i].weight = T[p1].weight + T[p2].weight;/*�½���Ȩֵ*/
	}
}

void InitHuffmanTree(HuffmanTree T)/*��ʼ��Huffman��*/
{
	int i;
	for (i = 0; i < m; i++)/*��Huffman�������н��λ�ö����г�ʼ��( m = 2n-1)*/
	{
		T[i].weight = 0;
		T[i].lchild = T[i].rchild = T[i].parent = NULL;/*������ϵ(����)ָ�붼��ʼ��ΪNULL��: (void*)0  */
	}
}

void InputWeight(HuffmanTree T)//����Ȩֵ(��������n��Ҷ�ӽڵ���)
{
	int i;
	for (i = 0; i < n; i++)/*�����n��ǰ��ĺ궨��,ֵΪ5,(��Ȼ�����ô�дN�ȽϺ���)*/
	{
		printf("�������%d��Ȩֵ��", i + 1);
		scanf("%f", &T[i].weight);/*Ȩ д��������T��ǰn�������*/
	}
}
/*��T[0..i]��ѡ�� ������δ�ϲ��� Ȩ��С�� �����(��ЩҶ�ӽڵ㶼����һ����,��Ҷ�ӱ�����Ǹ�)������ŷֱ�Ϊp1��p2(���ü�Ӵ���,�Ա㱣���޸Ľ��)*/
void SelectMin(HuffmanTree T,
	int i,/*ɨ��/�жϵķ�Χ:������i��Ϊ��(��0~i)(Ϊ���������Ч�ʵĸ��Ӳ���(����ͬʱҲ�Ǳ�Ҫ��)*/
	int* p1, /*��С*/
	int* p2)/*��С*/ //��T[0..i-1]��ѡ�� ���� Ȩ��С�� ����㣬����ŷֱ�Ϊp1��p2(���ü�Ӵ���,�Ա㱣���޸Ľ��)
{
	//��T��ѡ������Ȩ��С�ĸ����
	int j;
	float min1,/*��С*/
		min2;/*��С*/
	min1 = min2 = -1;

	for (j = 0; j <= i; j++)/*��0��i��ȡ�ü���������Ҷ�ӽڵ�*/
		/*���T[j]��δ���ϲ�,T[j].parent���Ǳ��ֳ�ʼ��NULL*/
		if (T[j].parent == NULL)/*���T[j].parent != NULL,˵����֮ǰ�Ѿ������ںϲ���(��������,��ô��T�����оͲ����ٲ���ϲ�,Ҳ�Ͳ��ɸ��������е���СȨ����*/
		{
			/*����min1*/
			if (T[j].weight < min1 /*�ȵ�ǰΪֹ��С��Ȩ��С,�����T[j]�����µ���СȨ�ڵ�.*/
				|| min1 == -1)/*Ϊ�˿���������һ���ж�,�������нڵ��Ȩ��Ϊ�����޷�����Ƚ�*/
			{
				if (min1 != -1)/*���min1֮ǰ�ѱ��޸�.�ͱ�Ҫ����min2��p2,��ȻҲ���Բ��ж�,һ��geng'xin����.�����*/
				{
					/*�޸�min1��*p1ǰ,�����ݸ��Ƶ�min2��*p2*/
					min2 = min1;
					*p2 = *p1;
				}
				/*�޸�min1��*p1*/
				min1 = T[j].weight;
				*p1 = j;
			}
			else
				if (T[j].weight < min2 || min2 == -1)
				{
					min2 = T[j].weight;
					*p2 = j;
				}
		}
}
/*�����ռ������ַ�,˳���ȡ.*/
void CharSetHuffmanEncoding(HuffmanTree T, HuffmanCode H)/*main()_2����(��������)*/
{	//����Huffman��T ��Huffman�����H
	int c,/*childλ��*/
		p,/*parentλ��.*/
		i;				//c��p�ֱ�ָʾ T��(������)  ���Ӻ�˫�׵�λ��
	char cd[n + 1];			//��ʱ��ű���/*���������һ��λ��:cd[n]���������ַ���������'\0'.����ȷ�������ַ���Huffman����ĳ��Ȳ��ᳬ��n

	int start;				//ָʾ������cd�е���ʼλ��
	cd[n] = '\0';				//���������

	printf("�����뵥���ַ���\n");
	//getchar();/*Ӧ��ʱ����֮ǰ�������µĻ���.(������Ȼ�Ͳ���Ҫ����getchar()�ķ���ֵ��)*/

	/*������ֱ�ӿ�for()(ǰͷ����ĸ������������ſ�),����;������ʶ���Ļ��������ͣ�����漴�ɿ�������(����ж���ʱ��ע��Ҳ����ʾ����.*/
	for (i = 0; i < n; i++)		//������ Ҷ��T[i] �ı���
	{
		scanf("%s", H[i].str);	//����Ҷ��T[i]��Ӧ�ĵ���

		start = n;			//������ʼλ��  �ĳ�ֵ
		c = i;/*��ʼ��Ϊi*/				//�� Ҷ��T[i] ��ʼ ����/*(yin'wei)��Ϊ�������Ҷ�ӽڵ�,��ȻҪ���� '����'��
		while ((p = T[c].parent) != NULL)/*//ֱ�� ���ݵ�T[c]������ Ϊֹ;�ռ�0,1�ַ����봮.�����ڵ�ĸ��ڵ�ָ��ΪNULL
			(��Ȼ,�����϶����ǳ�ʼ�����n��Ҷ�ӽڵ���,������;�ϲ����½ڵ�(��Щ��Ҷ�ӽڵ�ֻ��λ��,û�нڵ�ı�?).*/
		{	//��T[c]��T[p]�����ӣ������ɴ���0���������ɴ���1
			cd[--start] = (T[p].lchild == c) ? '0' : '1';/*�ռ����ַ��ǴӺ���ǰд,˳�ŶȾͿ��Ի�ôӸ��ڵ㵽Ҷ�ӽڵ�ı�������.
														 (start=n;��λ�ñ�д��'\0',Ҫǰ��һ��λ����д��(--start)
														 (Ȼ���̱���ǣͷ�ֿ�(��)����,�Һ�start����ָʾ���������￪ʼ��ȡ�ַ�,
														 ��ǰͷ�Ѿ���cd[n]����ʼ��Ϊ������'\0'*/
			c = p;			//��������/*��Ϊ����������Ծ,����c��ֱ����i���.*/
		}
		/*Ҷ�ӽڵ������Ϣ����H.*/
		strcpy(H[i].bits, &cd[start]);		//���Ʊ���λ��(д�뵽��ӦҶ�ӽ����ʽ��������)
		/*ѹ������*/
		/*�����ַ������ռ���*/
		;
	}/*�ڵ��ϵ���ͽڵ������Ϣ�����ѽ�����*/
	
	
	/*��ӡ����������:*/
	for (i = 0; i < n; i++)/*�ڵ��Ȩ�ͽڵ�����Ƶ� ���Ե��Ⱥ��ϵ��һһ��Ӧ��.*/
		printf("��%d���ַ�%s�ı���Ϊ%s\n", i + 1, H[i].str, H[i].bits);

	/*��������Ľڵ���������,���εز��ұ���,���ռ�����*/
	printf("����Ľڵ���������,���εز��ұ���,���ռ�����:\n");
	char temp[MAXLEN];
	char collect_encode[2 * MAXLEN];
	collect_encode[0] = '\0';
	while (scanf("%s", temp) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			if (!strcmp(temp, H[i].str))
			{
				strcat(collect_encode, H[i].bits);
				break;
			}

		}
	}
	/*���ռ������ر������߸��ֽ�ӳ�䵽һ���ַ���(�˸��ػ��е��ӡ��������),�ռ��ַ�����ӡ���*/
	printf("���ռ������ı������߸��ֽ�ӳ�䵽һ���ַ���(�˸��ػ��е��ӡ��������),�ռ��ַ�����ӡ���:\n");
	//int i = 0;
	for ( i = 0; i < strlen(collect_encode); i += ZIP_bits)
	{
		putchar(To_char_Ascii_7bit(&collect_encode[i]));
		printf("|");
	}
	putchar(To_letter(&collect_encode[i - ZIP_bits]));
	printf("\n");
}


