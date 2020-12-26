//program 19.4.5.1.cpp  map���÷�ʾ��
#include <iostream>
#include <map>  //ʹ��map��Ҫ������ͷ�ļ�
using namespace std;
template <class T1,class T2>
ostream & operator <<( ostream & o,const pair<T1,T2> & p)
{ //��pair�������Ϊ (first,second)��ʽ
	o << "(" << p.first  << "," << p.second << ")";
	return o;
}
template<class T>
void Print( T first,T last)
{//��ӡ����[first,last)
	for( ; first != last; ++ first)
		cout <<  * first << " ";
	cout << endl;
}
typedef map<int,double,greater<int> > MYMAP; //�������ؼ��������ͣ�
                                            //Ԫ�ذ��ؼ��ִӴ�С���� 
int main()  
{
	MYMAP mp;
	mp.insert(MYMAP::value_type(15,2.7));
	pair<MYMAP::iterator,bool> p = mp.insert(make_pair(15,99.3)); 
	if( ! p.second )
		cout << * (p.first) << " already exists" << endl; //�����
	cout << "1) " << mp.count(15) << endl; //��� 1) 1
	mp.insert(make_pair(20,9.3));
	cout << "2) " << mp[40] << endl;//���û�йؼ���Ϊ40��Ԫ�أ������һ��
	cout << "3) ";Print(mp.begin(),mp.end());//�����3) (40,0)(20,9.3)(15,2.7)
	mp[15] = 6.28; //�ѹؼ���Ϊ15��Ԫ��ֵ�ĳ�6.28
	mp[17] = 3.14; //����ؼ���Ϊ17��Ԫ�أ�������ֵ��Ϊ3.14
	cout << "4) ";Print(mp.begin(),mp.end());
	return 0;
}

