//program 3.6.2.cpp   ���ֵ���
#include <iostream>
using namespace std;
int main()
{	
	int n,m;
	cin >> n >> m;
	int a = m + 1,b = m + 1;  //a,b������¼�Ѿ��ҵ�������ֵ�����a�ǵ�����b������
	for( int i = n; i < m ; ++i )  { //ȡ��������m-n��ȡ��
		 if( i > (a + b)/2 + 1) 
		 	 break;  // ��������ѭ�� 
		 for( int j = i + 1; j <= m; ++j ) {  //ȡ����
		 	  if( i + j > a + b )
		 	  	  break;  // ��������ѭ�� 
		 	  if( i * j % (i + j) == 0 ) {  //�����ֵ���
			  	  if( i + j < a + b) {  //���ֺ͸�С���ֵ���
				  	  a = i;  b = j; //�������ҵ�������ֵ���
				  }
			  	  else if( i + j == a + b && i < a) { //���ֺ���ͬ��������С���ֵ���
				  	   a = i; b = j;  //�������ҵ�������ֵ���
			      }
			  }
	     }	  
    }
    if( a == m + 1 )  //û�ҵ��ֵ���
        cout << "No solution.";
   	else
	    cout << a << "," << b ;
	return 0;
}

