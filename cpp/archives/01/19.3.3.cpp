//program 19.3.3.cpp  ����������sort�е�Ӧ��
#include <iostream>
#include <algorithm> //sort�ڴ�ͷ�ļ��ж���
using namespace std;
template <class T>
void PrintInterval( T first,T last)
{ //�������[first,last)�е�Ԫ��
	for( ; first != last ; ++ first )
		cout << * first << " ";
	cout << endl;
}
class A
{
public:
	int v;	   
	A(int n):v(n) { }
};
bool operator <(const A & a1,const A & a2)
{//���س�A��const��Ա����Ҳ���ԣ����سɷ�const��Ա������ĳЩ�������ϲ���
 	 return a1.v < a2.v;
}
bool GreaterA( const A & a1, const A & a2)
{//vֵ���Ԫ����С�� 
	return a1.v > a2.v;
}
struct LessA
{
	bool operator() ( const A & a1, const A & a2)
	{//��v�ĸ�λ��С��Ԫ�أ�����С��
		return (a1.v % 10) < (a2.v % 10);
	}
};
ostream & operator<<( ostream & o,const A & a)
{
	o << a.v;
	return o;
}
int main()
{
	int a1[4] = { 5,2,4,1};
	A a2[5] = {13,12,9,8,16};
	sort(a1,a1+4);
	cout << "1) "; PrintInterval(a1,a1+4); //��� 1) 1 2 4 5
	sort(a2,a2+5); // ��v��ֵ��С��������
	cout << "2) "; PrintInterval(a2,a2+5); //��� 2) 8 9 12 13 16
	sort(a2,a2+5,GreaterA); //��v��ֵ�Ӵ�С����
	cout << "3) "; PrintInterval(a2,a2+5); //��� 3) 16 13 12 9 8
	sort(a2,a2+5,LessA()); //��v�ĸ�λ����С��������
	cout << "4) "; PrintInterval(a2,a2+5); //��� 4) 12 13 16 8 9
	return 0;
}

