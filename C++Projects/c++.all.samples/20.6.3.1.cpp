//program 20.6.3.1.cpp ������ʽ
#include <iostream>
#include <regex> //ʹ��������ʽ��������ļ�
using namespace std;
int main()
{
	regex reg("b.?p.*k");
	cout << regex_match("bopggk",reg) <<endl;
	cout << regex_match("boopgggk",reg) <<endl;
	cout << regex_match("b pk",reg) <<endl;
	regex reg2("\\d{3}([a-zA-Z]+).(\\d{2}|N/A)\\s\\1"); 
	string correct="123Hello N/A Hello";
	string incorrect="123Hello 12 hello"; 
	cout << regex_match(correct,reg2) <<endl;
	cout << regex_match(incorrect,reg2) << endl;
}
/*
. ��������һ���ַ�
*  �ظ���λ�����
+ �ظ�һ�λ�����
?  �ظ���λ�һ��
*/
