//program 19.9.1.cpp remove�÷�ʾ��
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
	int a[5] = { 1,2,3,2,5};
	int b[6] = { 1,2,3,2,5,6};
	ostream_iterator<int> oit(cout,",");
	int * p = remove(a,a+5,2);
	cout << "1) "; copy(a,a+5,oit); cout << endl; //��� 1) 1,3,5,2,5,
	cout << "2) " << p - a << endl;               //��� 2) 3
	vector<int> v(b,b+6);
	remove(v.begin(),v.end(),2);
	cout << "3) ";copy(v.begin(),v.end(),oit);cout << endl; //��� 3) 1,3,5,6,5,6,
	cout << "4) "; cout << v.size() << endl;      //v�е�Ԫ��û�м���,��� 4) 6
	return 0;
}

