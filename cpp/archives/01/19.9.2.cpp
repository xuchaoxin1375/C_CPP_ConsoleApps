//program 19.9.2.cpp  ɾ���㷨ʾ��
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset�����ڴ�����
#include <iterator>
using namespace std;
bool LessThan4( int n) { return n < 4; }
int main()
{
	int a[5] = { 1,2,3,2,5};
	int b[6] = { 1,2,5,2,5,6};
	int c[6] = { 0,0,0,0,0,0};
	ostream_iterator<int> oit(cout,",");
	remove_if(b,b+6,LessThan4);//ɾ��С��4��Ԫ��
	cout << "1) "; copy(b,b+6,oit); cout << endl; 	//��� 1) 5,5,6,2,5,6,
	int * p = remove_copy(a,a+5,c,2); //����2��Ԫ�ز�����
	cout << "2) " << p - c << endl; 		         //��� 2) 3
	cout << "3) "; copy(c,c+6,oit); cout << endl; //��� 3) 1,3,5,0,0,0,
	cout << "4) "; copy(a,a+5,oit); cout << endl; //��� 4) 1,2,3,2,5,
	                                              //˵��remove_copy���ı�Դ����
	memset(c,0,sizeof(c)); //�� c ��Ϊȫ0
	remove_copy_if(a,a+5,c,LessThan4); //С��4��Ԫ�ز�����
	cout << "5) "; copy(c,c+6,oit); cout << endl; //��� 5) 5,0,0,0,0,0
	int d[7] = { 1,2,2,2,3,3,4 };
	vector<int> v;
	v.insert(v.begin(),d,d+7);
	unique(d,d+7); 
	cout << "6) "; copy(d,d+7,oit); cout << endl;	//��� 6) 1,2,3,4,3,3,4,
	memset(d,0,sizeof(d));
	unique_copy(v.begin(),v.end(),d);
	cout << "7) ";copy( d,d+7,oit);		         //��� 7) 1,2,3,4,0,0,0,
	return 0;
}

