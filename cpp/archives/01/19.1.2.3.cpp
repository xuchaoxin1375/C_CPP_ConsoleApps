//program 19.1.2.3.cpp  ���������������÷�
#include <list>
#include <iostream>
#include <algorithm> //Ҫʹ�ò����������ĺ���ģ����Ҫ�������ļ�
using namespace std;
int main()  
{
	int a[5] = { 1,2,3,4,5 };
	list<int> lst(a,a+5);
	list<int>::iterator p = lst.begin ();
	advance(p,2);  // p�����������ָ��3
	cout << "1) " << * p << endl; //��� 1) 3
	advance(p,-1); // p������һ����ָ��2
	cout << "2) " << * p << endl; //��� 2) 2
	list<int>::iterator q = lst.end();
	q --; //qָ��5
	cout << "3) " << distance(p,q) << endl; //��� 3) 3
	iter_swap(p,q); // 2��5����
	cout << "4) " ;
	for( p = lst.begin(); p != lst.end(); ++ p)
		cout << * p << " " ;
	return 0;
} 
