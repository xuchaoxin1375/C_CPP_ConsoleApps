//program 2.7.1.3.cpp  �����Լ������
#include <iostream>
using namespace std;
int main()
{
	int n1 ,  n2 = 5;
	n2 ++;  // n2���6
	++ n2;  // n2��� 7
	n1 = n2 ++;  // n2���8,n1���7
	cout << n1 << "," << n2 << endl;  //��� 7,8
	n1 = ++ n2;  //n1��n2�����9
	cout << n1 << "," << n1 << endl;  //��� 9,9
	return 0;
}

