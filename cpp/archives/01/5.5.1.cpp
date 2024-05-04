//program 5.5.1.cpp   ��������
#include <iostream>
using namespace std;
void InsertionSort(int a[] ,int size)
{//��������
	 int i; //������������һ��Ԫ�ص�λ��
	 for( i = 0; i < size - 1; ++ i ) {
	    int tmp = a[i+1];//tmp�Ǵ����뵽���������Ԫ��
		int j = i;
		while( j >= 0 && tmp < a[j] ) { //Ѱ�Ҳ����λ��
			a[j+1] = a[j];//��tmp��Ķ�������
			j --;
		}
		a[j+1] = tmp; 
	 }
}
void PrintArray(int a[][5],int rows)
{//�����ά����,rows������
 	for( int i = 0;i < rows; ++i ) {
 	 	 for( int j = 0; j < 5; ++j )
 	 	  	   cout << a[i][j] << " ";
          cout << endl;
	}
}
int main() 
{
 	int b[5] = { 50,30,20,10,40 };
	int a2d[3][5] = {{5,3,2,1,4},{10,20,50,40,30},{100,120,50,140,30}};
 	InsertionSort(b,5);
	for( int i = 0;i < 5; ++ i )
		    cout << b[i] << " " ;
	cout << endl;
	for( int i = 0;i < 3;++i)
		    InsertionSort(a2d[i],5);
	PrintArray(a2d,3);
    return 0;
}

