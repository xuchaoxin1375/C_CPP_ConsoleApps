//program 19.2.1.2.cpp ��vectorʵ�ֶ�ά����
#include <iostream>
#include <vector>
using namespace std;
int main()  
{	
vector<vector<int> > v(3); //v��3��Ԫ�أ�ÿ��Ԫ�ض���vector<int> ����
    for( int i = 0;i < v.size(); ++i)
    	 	for( int j = 0; j < 4; ++j)
    	 		  v[i].push_back(j);
    for( int i = 0;i < v.size(); ++i) {
    	 for( int j = 0; j < v[i].size(); ++j)
    		 	  cout << v[i][j] << " ";
 	      cout << endl;
    }
return 0;
}
