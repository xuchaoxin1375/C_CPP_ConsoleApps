//program 3.1.2.cpp  �ж�����Ƿ��ǽ���������ʮ���������
#include <iostream>
using namespace std;
int main()
{
	int year;
	cin >> year;
	if( year <= 0) 
		cout << "Illegal year." ;
	else {
		cout << "Legal year." << endl;
		if( year > 1949 && (year - 1949) % 10 == 0 )     //������ʮ����
			cout << "Luky year.";
		else if( year > 1921 && !((year - 1921) % 10))   //������ʮ����
			cout << "Good year.";		 
		else if( year % 4 == 0 && year % 100 || year % 400 == 0 )  //����
			cout << "Leap year";
		else
			cout << "Common year.";
	}
	return 0;
}

