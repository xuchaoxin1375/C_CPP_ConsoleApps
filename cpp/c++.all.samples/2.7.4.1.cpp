//program 2.7.4.1.cpp  �߼������
#include <iostream>
using namespace std;
int main()
{
  	int a = 0,b = 1;
	bool n = a ++ && b ++ ;  // b++�������� 
	cout << a << "," << b << endl; //��� 1,1 
	n =  a ++ && b ++ ;  // a++��b++��Ҫ���� 
	cout << a << "," << b << endl; //��� 2,2 
	n =  a ++ || b ++ ;	//b++�������� 
	cout << a << "," << b << endl; //��� 3,2 
    return 0;
}

