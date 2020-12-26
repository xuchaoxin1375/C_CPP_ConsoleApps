//program 19.8.3.cpp copy��ostream_iterator���
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>  
using namespace std;
template<class T>
class My_ostream_iterator
{
 private:
 	 string sep; //�ָ���
 	 ostream & os;
 public:
 	My_ostream_iterator(ostream & o, string s):sep(s),os(o)	{ }
	void operator ++() { }; // ++ֻ��Ҫ�ж��弴�ɣ�����Ҫ��ʲô
	My_ostream_iterator & operator * ()
	{	 return * this; 	}
	 My_ostream_iterator & operator = ( const T & val)
	{ 	os << val << sep;    return * this; 	}
};
int main()
{
	int a[4] = { 1,2,3,4 };	
	My_ostream_iterator<int> oit(cout,"*");
	copy( a,a+4,oit); //��� 1*2*3*4*
	ofstream oFile("test.txt",ios::out);
	My_ostream_iterator<int> oitf(oFile,"*");
	copy(a,a+4,oitf);//��test.txt�ļ���д�� 1*2*3*4*
	oFile.close();
	return 0;
}

