//program 19.2.1.1.cpp  vector�����÷�
#include <iostream>
#include <vector> //ʹ��vector��Ҫ������ͷ�ļ�
using namespace std;
template<class T>
void PrintVector( const vector<T> & v)
{ //�������vector������ȫ��Ԫ�صĺ���ģ��
	typename vector<T>::const_iterator i; 
//typename����˵�� vector<T>::const_iterator�Ǹ����� ,��VS 2008�в�дҲ���� 
	for( i  = v.begin(); i != v.end(); ++i)	
		cout << * i << " ";
	cout << endl;
}
int main()  
{	
	int a[5] = { 1,2,3,4,5 };    
	vector<int> v(a,a+5);  //������a�����ݷ���v
cout << "1) " << v.end()  - v.begin() << endl; //������������������������� 1) 5
	cout << "2) "; PrintVector(v); //�����2) 1 2 3 4 5
	v.insert( v.begin() + 2, 13 ); //��begin()+2λ�ò��� 13
	cout << "3) "; PrintVector(v); //�����3) 1 2 13 3 4 5
	v.erase( v.begin() + 2);       //ɾ��λ�� begin() + 2��Ԫ�� 
	cout << "4) "; PrintVector(v); //�����4) 1 2 3 4 5
	vector<int> v2(4,100);  //v2 ��4��Ԫ�أ�����100
	v2.insert( v2.begin(),v.begin()+ 1,v.begin()+3);//��v��һ�β���v2��ͷ
	cout << "5) v2: "; PrintVector(v2); //���: 5) v2: 2 3 100 100 100 100
	v.erase( v.begin() + 1, v.begin() + 3); //ɾ�� v �ϵ�һ������,�� 2,3 
	cout << "6) "; PrintVector(v); //���: 6) 1 4 5
	return 0;
}
