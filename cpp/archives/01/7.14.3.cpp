//program 7.14.3.cpp  ��������ⷨ2
#include <iostream>
using namespace std;
const int WORD_NUM = 10000;
const int WORD_LEN = 100;
char * words[WORD_NUM + 10];//������΢����һ�㣬����
int MyCompare( const void * e1, const void * e2)
{
	char ** p1 = ( char **) e1;
	char ** p2 = ( char **) e2;
	return strcmp(*p1,*p2); //*p1��*p2ָ����Ƚϵ���������
}
int main()  
{
	int n;
	char word[120];
	cin >> n;
	for( int i = 0;i < n;++i ) {
			cin >> word;
			words[i] = new char[strlen(word)+1];//Ҫ������ĩβ'\0'�Ŀռ�
			strcpy(words[i],word);
	}
	qsort(words,n,sizeof(char *),MyCompare);
	for( int i = 0;i < n;++i ) {
			cout << words[i] << endl;
			delete [] words[i]; //��Ҫ�����ͷſռ�
	}
	return 0;
}

