//program 19.8.1.cpp  ��ֵ�㷨ʾ��
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;
void Modify( int & lst) { lst *= lst; }
int Square(int n) { return n * n; }
int Zero() { return 0; }
int One() { return 1; }
bool Even(int n) { return !(n % 2); } //�ж�n�Ƿ���ż�� 
int main()  
{
	int a[6] = { 1,2,3,4,5,6}; 
	int b[6];
	copy(a,a+6,b);
	ostream_iterator<int> oit(cout,",");//������������ĵ�����
	cout << "1) "; copy(b,b+6,oit); cout << endl;
		//��� 1) 1,2,3,4,5,6,
	copy_backward(b,b+4,b+5); //����[b,b+4)��[b+1,b+5)
	cout << "2) "; copy(b,b+6,oit); cout << endl;
		//��� 2) 1,1,2,3,4,6,
	list<int> lst(5); //lstҪ���㹻�ռ���֧�ֺ���Ŀ���
	transform(a,a+5,lst.begin(),Square); 
		//��a��Ԫ�ص�ƽ��������lst��a�е�Ԫ�ز���ı�
	cout << "3) "; copy(lst.begin(),lst.end(),oit); cout << endl;
		//��� 3) 1,4,9,16,25,
	cout << "4) "; copy(a,a+6,oit); cout << endl;
		//���4) 1,2,3,4,5,6, ˵��a��Ԫ��û��
	swap_ranges(lst.begin(),lst.end(),b);//����lst��b������
	cout << "5) ";copy(lst.begin(),lst.end(),oit); cout << endl;
		//��� 5) 1,1,2,3,4,
	fill(b,b+6,0); //b��� 0 0 0 0 0 0
	fill_n(b+2,3,1); //b��� 0 0 1 1 1 0
	cout << "6) ";copy(b,b+6,oit); cout << endl;
		//��� 6) 0,0,1,1,1,0,
	copy(a,a+6,b); //b ��� 1 2 3 4 5 6
	generate(b,b+6,Zero); //b��� 0 0 0 0 0 0
	generate_n(b+1,3,One); //b��� 0 1 1 1 0 0
	cout << "7) "; copy(b,b+6,oit); cout << endl;
		//��� 7) 0,1,1,1,0,0,
	replace(b,b+6,1,3); //��b�е�1���滻��3
	cout << "8) "; copy(b,b+6,oit); cout << endl;
		//��� 8) 0,3,3,3,0,0,
	replace_if(b,b+6,Even,11); //��b�е�ż�����滻��11
	cout << "9) "; copy(b,b+6,oit); cout << endl;
		//��� 9) 11,3,3,3,11,11,
	replace_copy(a,a+6,b,3,30);
		//����a��b,���ǿ��������лὫ3�滻��30,a����
	cout << "10) "; copy(b,b+6,oit); cout << endl;
		//��� 10) 1,2,30,4,5,6,
	replace_copy_if(a,a+6,b,Even,7);
		//����a��b,���ǿ���������ż�������滻��7��a����
	cout << "11) "; copy(b,b+6,oit); cout << endl;
		//��� 11) 1,7,3,7,5,7,
	return 0;
}

