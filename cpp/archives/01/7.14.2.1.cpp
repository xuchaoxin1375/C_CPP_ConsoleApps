//program 7.14.2.1.cpp  �ö������ļ�����ѧ����¼
#include <iostream>
#include <fstream>
using namespace std;
class CStudent 
{
	public:
		char szName[20];
		int age;
};
int main()
{
	CStudent s;		
	ofstream outFile("students.dat",ios::out|ios::binary);
	while( cin >> s.szName >> s.age ) 
		outFile.write( (char *) & s, sizeof(s));
	outFile.close();
	return 0;
}

