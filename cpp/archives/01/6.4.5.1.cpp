//program 6.4.5.1.cpp  string �����÷�
#include <iostream>
#include <string> //Ҫʹ��string������������ͷ�ļ�
using namespace std;
int main()  
{
	string s1 = "123",s2; // s2�ǿմ�
	s2 += s1;             // s1 = "223"
	s1 = "abc";		   // s1 = "abc"
	s1 += "def";		   // s1 = "abcdef"
	cout << "1) " << s1 << endl;  //��� 1) abcdef 
	if( s2 < s1 )
		cout << "2) s2 < s1" <<endl;
	else
		cout << "2) s2 >= s1" <<endl;
	s2[1] = 'A';	       // s2 = "1A3"
	s1 = "XYZ" + s2;	  // s1 = "XYZ1A3";
	string s3 = s1 + s2; // s3 = "XYZ1A31A3"
	cout << "3) " << s3 << endl;  //��� 3) XYZ1A31A3
	cout << "4) " << s3.size() << endl;  //��s3���ȣ���� 4) 9 
	string s4 = s3.substr(1,3);   //��s3���±�1��ʼ������Ϊ3���Ӵ�
	cout << "5) " << s4 << endl;  //��� 5) YZ1
	char str[20];
	strcpy( str,s4.c_str());      //����s4�е��ַ�����str
	cout << "6) " << str << endl; //��� 6) YZ1
	return 0;
}

