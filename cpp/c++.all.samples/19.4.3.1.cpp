//program 19.4.3.1.cpp  set���÷���
#include <iostream>
#include <set>  //ʹ��set��������ļ�
using namespace std;
int main()  
{
	typedef set<int>::iterator IT;
	int a[5] = { 3,4,6,1,2 };
	set<int> st(a,a+5);    // st���� 1 2 3 4 6
	pair< IT,bool> result;
	result = st.insert(5); // st���  1 2 3 4 5 6
	if( result.second )    //����ɹ������������Ԫ��
		cout << * result.first  << " inserted" << endl; //���: 5 inserted
	if( st.insert(5).second ) 
		cout << * result.first  << endl;
	else
		cout << * result.first << " already exists" << endl; //��� 5 already exists
	pair<IT,IT> bounds = st.equal_range(4);
	cout << * bounds.first << "," << * bounds.second ; //�����4,5
	return 0;
}

