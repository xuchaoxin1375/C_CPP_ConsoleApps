//program 10.2.2.cpp  ��̬�ֲ�����Ӧ��
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
bool GetWord(const char * str,char * word)
{
	static const char * p; //���ε��ʵ�Ѱ�����
	int i;
	if( str ) //str��Ϊ�գ�˵��Ҫ��һ���µ��ַ������ҵ���
		p = str;
	for( i = 0; !isalpha(p[i]) && p[i]; ++ i) ;//�ҵ�һ����ĸ,isalpha�ǿ⺯��
	if( p[i] == 0 ) //�Ѿ����˽�β��'\0'��˵��û�е�����
		return false;
	p +=  i; //�ߵ���˵���ҵ���ĸ��,��pָ�򵥴ʵ���ʼλ��
	for( i = 0;isalpha(p[i]) && p[i]; ++ i) ;//����һ���ָ��ַ�
	strncpy(word,p,i); //��������
	word[i] = 0;  //��ӵ���ĩβ�� '\0'
	p += i; //��p��Ϊ��һ�����ʵ�Ѱ�����
	return true;
}
int main()
{
	char * sentence = "To be or not to be,is a problem.";
	char word[100]; //���赥�ʳ��Ȳ��ᳬ��99
 	bool b = GetWord( sentence,word );//��sentence��ȡ��һ�����ʣ�����word
	while( b ) { //GetWord����ֵΪtrue˵��ȡ���˵��ʣ�Ϊfalse˵�����޵��ʿ�ȡ
		cout << word << endl;
		b = GetWord(NULL,word);
	}
}

