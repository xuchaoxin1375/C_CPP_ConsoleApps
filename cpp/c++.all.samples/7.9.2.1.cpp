//program 7.9.2.1.cpp  string�����char*ָ���ϵ
#include <iostream>
#include <cstring> 
#include <string>
using namespace std;
int main()  
{
	string s;
	char str1[20] = "The Flowers Of War";
	char str2[20] = ""; //str2�ǿմ�
	char * p = str1; 
	s = p; // s ��� "The Flowers Of War"
	strcat(str2,s.c_str()); //��s���������ӵ�str2
	cout << str2 << endl;   //���  The Flowers Of War
	return 0;
}

