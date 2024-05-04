#define _CRT_SECURE_NO_WARNINGS
//program 13.2.1.cpp  ����"="
#include <iostream>
#include <cstring>
using namespace std;
class String {
	private:  
        char * str;
	public:
		/*���ó�ʼ���б����������캯��(�޲�Ĭ�Ϲ��캯��String(),�ú�����str��ʼ��ΪNULL.*/
		String ():str(NULL) { }
		/*����ֵstr�� ������const char* ����ָ��.(��str��ָ���ַ������ܹ�ͨ�����strָ��������(��֤��ȫ). */
		const char * c_str()
		{
			return str;/*���س�Ա����str�ַ�ָ���ֵ(��һ��ָ���ַ��ĵ�ַ)*/
		};/*c_str()�Ǻ����嶼д�����е���������.*/
		/*���� ��Ϊoperator = () ����������غ���*/
		char * operator = (const char * s);/*const char* �����ͱ�char *�ķ�Χ����Щ */
		/*������������.*/
		~String( );
};//class String{}

/* "="������Ϊstring���(���������)��Ա����*/
char * String::operator = (const char * s) //����"="��ʹ�� obj = "hello"�ܹ�����
{
	/*���������Ա����str�Ͳ���s (���������Ͷ���һ��char *��const char* )*/
	/*���string�����ĳ�Ա����str=NULL*/
	/*�������з�ֻ֧�������һ(���жϿ��ܶ��ȹ�ȥ)*/
	if (str) //strΪNULL����delete ����
	{
		delete[] str;/*delete�����ὲstrָ��NULL*/
	}/*�����delete ���е�����,str�ڽ����µ�new�����ڴ�ĵ�ַ��,�ɿռ仹�ǻᱻռ�õ�.(ͨ���ڴ���ӿ�֪)*/
	if(s) {  //s��ΪNULL�Ż�ִ�п���(����˵���п���������/��Ҫ,���򿽱����û���������һ��,���粻����) 
		str = new char[strlen(s)+1];/*ͨ��new����һ���������ַ����ڴ�Ҫ��Ŀռ��С���ڴ�,��������ַ�������ַ������ƺ���,���Կռ������һ��char����'\0'*/
		strcpy( str, s);
	}
	else
	{
		str = NULL;
	}
	return str;
}
/*��������*/
String::~String( ) 
{ 
    if( str)  
		delete [] str; /*��˵deleteֻ�ܹ�ɾ��new�õ��Ŀռ�*/
};

int main()
{
	  String s;
	  s = "Good Luck," ; //�ȼ��� s.operator=("Good Luck,");
	  cout << s.c_str() << endl;
      // String s2 = "hello!";   //�������Ҫ�ǲ�ע�͵��ͻ����
	  s = "Shenzhou 8!"; //�ȼ��� s.operator=("Shenzhou 8!");
	  cout << s.c_str() << endl;
	  return 0;
}
/*c_str()����������ָ��String�����ڲ���̬����Ĵ洢�ռ��ָ�룬
���ǲ�ϣ���ⲿ�õ����ָ���ȥ�޸���ָ����ַ��������ݣ���ˣ�������ֵ��Ϊconst char*��s�����ڲ����ַ����Ͳ������׵ش��ⲿ���޸��ˣ�
�������ٶ�s��String������ô��������������ʱ���ᱨ��

char wp = s.c.��str������strcpy��s.c_str������"Tiangong 1"����
��һ������������Ϊ��="�����char*���ͣ��ұ���const char*���ͣ��������Ͳ�ƥ�䣻
�ڶ�������������Ϊstrepy�����ĵ�һ���β���char�����͵ģ�������ʵ�θ���ȴ��constchar#���͵ģ�ͬ�����Ͳ�ƥ�䡣

���û�жԡ�=�������أ���s ="Good Luck��"�϶�����Ϊ���Ͳ�ƥ���������� �ַ�������"Good Luck,"������:const char * ;const char* �����Ͳ��ܹ���ֵ��char* ����


�������غ󣬡�s ="Good Luck��"�ȼ��ڡ�s.operator =��"Good Luck��"����������û������
�ˡ�
��operator=�����У�Ҫ���ж�str�Ƿ��Ѿ�ָ��̬����Ĵ洢�ռ䣬����ǣ���ôҪ���ͷ���Ƭ�ռ䣬Ȼ�����·���Ƭ�ռ䣬�ٽ�����sָ������ݸ��ƹ�ȥ��������������.
��ŵ��ַ����ͺ�sָ����ַ���һ���ˡ�
����ռ��ʱ��Ҫ���ǵ��ַ�����β�ġ�\0'�����Է�����ֽ���Ҫ��strlen��s����1��

��Ҫע��һ�㣬��ʹ�ԡ�һ���������أ�"Strings2 ="hello��"���������ǻ�������ģ�
��Ϊ��������ʼ�����Ҫ�õ����캯���������Ǹ�ֵ�š�=����
String��û�б�д ��������Ϊchar*�� ���캯������˱��벻��ͨ����*/
