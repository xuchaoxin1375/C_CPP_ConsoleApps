//program 19.13.3.cpp  ��STL�㷨����string����
#include <iostream>
#include <algorithm>
#include <string> 
using namespace std;
int main()  
{
   string s("afgcbed");
   string::iterator p = find(s.begin(),s.end(),'c');
   if( p != s.end())
	   	cout << p - s.begin() << endl; //��� 3
   sort(s.begin(),s.end());
   cout << s << endl; //��� abcdefg
   next_permutation(s.begin(),s.end());
   cout << s << endl; //��� abcdegf
   return 0;
}

