//program 19.7.1.cpp  ���������㷨ʾ��
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
void Print( int v)
{
	cout << "<" << v << ">";
}
bool LessThen4( int n)
{
	return n < 4;
}
int main()  
{
	cout << "1) " << min(3,4) << "," << max(2.5,8.3) << endl; //��� 1) 3,8.3
	int a[9] = { 1,2,3,4,5,3,4,4,4 }; 
	cout << "2) " << * min_element(a,a+9) <<","<< * max_element(a,a+9)<<endl; 
     //��� 2) 1,5
	cout << "3) " << count(a,a+9,4) << endl; //����4�ĸ�������� 3) 4
	cout << "4) " << count_if(a,a+9,LessThen4) << endl; 
     //����С��4��Ԫ�ظ�������� 4) 4
	list<int> lst(a,a+9);
	int b[2] = {4,3};
	vector<int> v(b,b+2);// v �� 4,3
	list<int>::iterator p;
	p = find_first_of(lst.begin(),lst.end(),b,b+2); // �� 4,3�е���һԪ��
	cout << "5) " << distance(lst.begin(),p) << endl; //�ҵ���3 ��� 5) 2
	reverse(v.begin(),v.end()); //�㷨reverse��ǰ��ߵ����䣬v��� 3,4
	int * ptr = find_end(a,a+9,v.begin(),v.end());
     //������ "3 4"������a�������ֵ�λ��
	cout << "6) " << distance(a,ptr) << endl; //��� 6) 5 
	p = adjacent_find(lst.begin(),lst.end()); //��lst������������ͬ��Ԫ��
	cout << "7) " << * p << "," << distance(lst.begin(),p) << endl; //��� 7) 4,6
	p = search(lst.begin(),lst.end(),v.begin(),v.end());//������ "3 4"
	cout << "8) " << distance(lst.begin(),p) << endl;   //��� 8) 2
	ptr = search_n(a,a+9,2,4); //������2��4���ֵ�λ��
	cout << "9) " << distance(a,ptr) << endl; //��� 9) 6
	cout << boolalpha ;// �Ժ�true,false���ַ�����ʽ���
	cout << "10) " << equal(v.begin(),v.end(),a+2) << endl; 
     //�Ƚ�v��a+2��ʼ��2��Ԫ�أ������, ��� 10) true
	int c[6] = { 1,2,3,9,7,8 };
	pair<int *, int * > result;
	result = mismatch(c,c+6,a);
	cout << "11) " << * result.first  << "," << * result.second << endl;//��� 11) 9,4
	cout << "12) " << lexicographical_compare(a,a+9,c,c+6) << endl; //��� 12) true
     for_each(a,a+3,Print); //��[a,a+3)�е�ÿ��Ԫ��Ϊ����������Print, ��� <1><2><3>
	return 0;
}

