#define _CRT_SECURE_NO_WARNINGS
//program 13.2.1.cpp  ����"="
#include <iostream>
#include <cstring>
using namespace std;
class String {
private:
	char* str;

public:
	/*���ó�ʼ���б����������캯��(�޲�Ĭ�Ϲ��캯��String(),�ú�����str��ʼ��ΪNULL.*/
	String() :str(NULL) { }
	/*���ι��캯��:*/
	String( const char* str_)
	{
		str = (char*)str_;
	}
	/*
	����ֵstr�� ������const char* ����ָ��,�Ա��ӡ(��Ҫ��str��Ա��˽�е�ʱ��ֻ��ͨ��ͬ���Ա���������ʵ�str)
	(��str��ָ���ַ������ܹ�ͨ�����strָ��������(��֤��ȫ). */
	const char* c_str()
	{
		return str;/*���س�Ա����str�ַ�ָ���ֵ(��һ��ָ���ַ��ĵ�ַ)*/
	};

	/*���� ��Ϊoperator = () ����������غ���'
	��������غ����ķ���ֵ���β������н���.*/
	String & operator = (const String & s);/*const char* �����ͱ�char *�ķ�Χ����Щ */
	/*������������.*/

	/*��������*/
	//~String()/*��������û�в���,��ʵ�����и�thisָ��.(���ж���������������)*/
	//{
	//	if (str)/*ԭ����NULL,���б�Ҫ����if���ͷ��ڴ�*/
	//	{
	//		/*����delete��������:(�������ͷ�s1��s2ʱ�����Ĵ���,����str��ָ������ͨ��new�����ڴ�.*/
	//		delete[] str;
	//	}
	//};
};//class String{}

/* "="������Ϊstring���(���������)��Ա����,��������Ƶ�����"=";
* ʹ��˵��:
Ҫ�����Ƶ�����λ�ڲ�������s��.,���Ƶ�Ŀ�����*this��(���ڴ��ڸ��Ƶ�ʱ������) */
String & String::operator = (const String& s) //����"="��ʹ�� obj = "hello"�ܹ�����
{
	/*s����������ᱻ�޸�,*this�ᱻ�޸�*/
	if (str == s.str)/*str����������������������operator= ���Ǹ�����ĳ�Ա(Ҳ����˵��ʱ�� *this �ǵ�һ��������);s.str���뺯���ĵڶ�����������s�ĳ�Ա����(ͬʱ��������s�ǵڶ���������))*/
	{
		return *this;
	}
	if (str)/*this->str*/
	{
		delete[] str;
	}
	if (s.str)
	{
		str = new char[strlen(s.str) + 1];/*Ϊ����������ַ�����Ŀ������������ַ������ڴ�*/
		strcpy(str, s.str);
	}
	else
	{
		str = NULL;
	}
	return *this;/*���ص�ǰ������*/
}


int main()
{
	String s;
	String s1("test");/*���ô��ι��캯��*/
	String s2 = "testAgain";/*������ʱ����,���ô��ι��캯��(��������"="�ĵ���)*/
	s = s1;
	cout << s.c_str() << endl;
	//delete[] s.c_str();ֻ��Ҫ�����һ�θ��ƺ��ͷż���.
	s = s2;
	cout << s.c_str() << endl;
	delete[] s.c_str();
	return 0;
}

