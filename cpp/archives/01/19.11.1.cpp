//program 19.11.1.cpp �����㷨ʾ��
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int main()  
{
	ostream_iterator<int> oit(cout,",");
	int a[5] = { 4, 5, 3, 1, 2 };
	int b[5];
	memcpy(b,a,sizeof(a));//����a��b
	partial_sort(b,b+3,b+5);//ʹǰ3��Ԫ�ؾ�λ 
	cout << "1) "; copy(b,b+5,oit); cout << endl; //��� 1) 1,2,3,5,4,
	memset(b,0,sizeof(b)); //b���ȫ0 
	partial_sort_copy(a,a + 4,b,b+3);//��[a,a+4)��������ǰ3��������b 
	cout << "2) "; copy(a,a+5,oit); cout << endl; //a���� ��� 2) 4,5,3,1,2, 
	cout << "3) "; copy(b,b+5,oit); cout << endl; //��� 3) 1,3,4,0,0,
	int c[8] = { 4,1,2,6,5,3,7,0};
	nth_element(c,c+3,c+8);
	cout << "4) "; copy(c,c+8,oit); cout << endl; //��� 4) 0,1,2,3,5,6,7,4, 
	memcpy(b,a,sizeof(a));
	make_heap(b,b+5); //��b���һ����
	cout << "5) "; copy(b,b+5,oit); cout << endl;//��� 5) 5,4,3,1,2, 
	vector<int> v(b,b+5); //��Ϊb�Ǹ��ѣ�����vҲ�Ǹ���
	v.push_back(9); //����v�����һ��Ԫ�غ�v�Ϳ��ܲ��Ƕ��� 
	push_heap(v.begin(),v.end()); //��v�ָ��ɶ� 
	cout << "6) "; copy(v.begin(),v.end(),oit); cout << endl; //��� 6) 9,4,5,1,2,3
	pop_heap(v.begin(),v.end());  //���߶Ѷ���Ԫ�� 
	cout << "7) "; copy(v.begin(),v.end(),oit); cout << endl; //��� 7) 5,4,3,1,2,9 
	sort_heap(v.begin(),v.end()-1);//���� 
	cout << "8) "; copy(v.begin(),v.end()-1,oit); cout << endl; //��� 8) 1,2,3,4,5, 
	return 0;
}

