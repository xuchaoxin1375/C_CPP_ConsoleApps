//program 19.4.2.1.cpp  multiset���÷�
#include <iostream>
#include <set>  //ʹ��multiset��������ļ�
using namespace std;
template <class T>
void Print(T first, T last)
{
	for(;first != last ; ++first)
		cout << * first << " ";
	cout << endl;
}
class A 
{
	private:	
		int n;
	public:
	  A(int n_ ) { n = n_; }
      friend bool operator< ( const A & a1, const A & a2 ) 
	  {	return a1.n < a2.n; }
      friend ostream &  operator<< ( ostream & o, const A & a2 )
	  {	o << a2.n;    return o; }
	  friend class MyLess;  
};
class MyLess 
{
public:
	bool operator()( const A & a1, const A & a2) //����λ���ȴ�С
    { return ( a1.n % 10 ) < (a2.n % 10);  }
};
typedef multiset<A> MSET1; 			//MSET1�� "<"�Ƚϴ�С
typedef multiset<A,MyLess> MSET2;     //MSET2�� MyLess::operator()�Ƚϴ�С
int main()  
{
	const int SIZE = 6;
	A a[SIZE] = { 4,22,19,8,33,40 };
	MSET1 m1;   	
	m1.insert(a,a+SIZE);   
	m1.insert(22);
	cout << "1) " << m1.count(22) << endl; //���1) 2
	cout << "2) "; Print(m1.begin(),m1.end()); //��� 2) 4 8 19 22 22 33 40
	MSET1::iterator pp =  m1.find(19);
	if( pp != m1.end() ) //����Ϊ��˵���ҵ�
		cout << "found" << endl; //���лᱻִ�У���� found
	cout << "3) "; cout << * m1.lower_bound(22) << "," <<* m1.upper_bound(22)<< endl;  
       //��� 3) 22,33
	pp = m1.erase(m1.lower_bound(22),m1.upper_bound(22));//ppָ��ɾԪ�ص���һ��Ԫ��
	cout << "4) "; Print(m1.begin(),m1.end()); //��� 4) 4 8 19 33 40
	cout << "5) "; cout << * pp << endl;       //��� 5) 33
	MSET2 m2; // m2���Ԫ�ذ�n�ĸ�λ����С������
	m2.insert(a,a+SIZE);
	cout << "6) "; Print(m2.begin(),m2.end()); //��� 6) 40 22 33 4 8 19
	return 0;
}

