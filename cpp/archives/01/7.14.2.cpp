//program 7.14.2.cpp  ��������ⷨ1
#include <iostream>
#include <cstring>
using namespace std;
const  int WORD_NUM  = 10000;
const int  WORD_LEN = 100;
char words[WORD_NUM + 10][WORD_LEN+10];
//������΢����һ��û����,������ڱ߽紦���õ��³���
int MyCompare( const void * e1, const void * e2)
{
	char * str1 = ( char *) e1;//str1��ָ��һ������
	char * str2 = ( char *) e2;//str2��ָ��һ������
	return strcmp(str1,str2);//strcmp���ַ����ȽϿ⺯��
}
int main()  
{
	int n;
	cin >> n;
	for( int i = 0;i < n;++i ) 
			cin >> words[i]; //wordsÿ�д��һ������
	qsort(words,n,sizeof(words[0]),MyCompare);
	for( int i = 0;i < n;++i ) 
			cout << words[i] << endl;
	return 0;
}

