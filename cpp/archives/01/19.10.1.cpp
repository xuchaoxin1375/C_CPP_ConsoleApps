//program 19.10.1.cpp �����㷨ʾ��
#include <iostream>
#include <algorithm>
#include <ctime>
#include <iterator>
using namespace std;
bool LessThan4(int n) { return n < 4; }
int main()
{
	ostream_iterator<int> oit(cout,",");
	int a[5] = { 1,2,3,4,5};
	reverse(a,a+5); //a��Ϊ 5 4 3 2 1
	cout << "1) "; copy(a,a+5,oit); cout << endl; //��� 1) 5,4,3,2,1,
	int b[5] = {0,0,0,0,0};
	reverse_copy(a,a+5,b); 
	cout << "2) "; copy(b,b+5,oit); cout << endl; //��� 2) 1,2,3,4,5,
	cout << "3) "; copy(a,a+5,oit); cout << endl; //��� 3) 5,4,3,2,1,
	bool result = prev_permutation(a,a+5); 
	cout << "4) "; copy(a,a+5,oit); cout << endl; //��� 4) 5,4,3,1,2,
	result = next_permutation(a,a+5);
	cout << "5) "; copy(a,a+5,oit); cout << endl; //��� 5) 5,4,3,2,1,
	result = next_permutation(a,a+5);
	cout << "6) " << result << endl;  //"54321" ��������У�û��һ��������, ��� 6) 0,
	srand(time(0));//�����������
	random_shuffle(a,a+5);
	cout << "7) "; copy(a,a+5,oit); cout << endl;  //��� 7) 5,2,4,1,3,
	partition(a,a+5,LessThan4);	//��С��4��Ԫ�ض���ǰ��
	cout << "8) "; copy(a,a+5,oit); cout << endl;  //��� 8) 3,2,1,4,5,
	random_shuffle(a,a+5);
	cout << "9) "; copy(a,a+5,oit); cout << endl;  //��� 9) 1,3,5,2,4,
	stable_partition(a,a+5,LessThan4); //��С��4 ��Ԫ�ض���ǰ�棬��Ҫ����
	cout << "10) "; copy(a,a+5,oit); cout << endl; //��� 10) 1,3,2,5,4,
	return 0;
}

