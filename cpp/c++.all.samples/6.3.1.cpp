//program 6.3.1.cpp  �����ַ�������
#include <iostream>
#include <cstring> //Ҫʹ���ַ����⺯����Ҫ������ͷ�ļ�
using namespace std;
void PrintSmall( char s1[],char s2[])
{
	if( strcmp( s1,s2) <= 0) //���s1С�ڵ���s2
			cout << s1 ;
	else
			cout << s2;
}
int main()  
{
	char s1[30];
	char s2[40];
	char s3[100];
	strcpy( s1,"Hello"); // ���� "Hello" ��s1 �� s1 = "Hello"
	strcpy( s2,s1);      // ����s1��s2, s2 = "Hello"
	cout << "1) " << s2 << endl;  //��� 1) Hello
	strcat( s1,",world"); // ���� ",world"��s1β����s1 = "Hello,world"
	cout << "2) " << s1 << endl;  //��� 2) Hello,world
	cout << "3) "; PrintSmall("abc",s2); cout << endl; //��� 3) Hello
	cout << "4) "; PrintSmall("abc","aaa"); cout << endl;  //��� 4) aaa
	int n = strlen( s2 ); //��s2����
	cout <<"5) " << n << "," << strlen("abc") << endl; //��� 5) 5,3
	strupr(s1);  // ��s1��ɴ�д��s1 = "HELLO,WORLD"
	cout <<"6) " << s1 << endl; //��� 6) HELLO,WORLD
	return 0;
}

