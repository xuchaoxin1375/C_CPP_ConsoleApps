//program 3.9.1.cpp  freopen�÷�ʾ��
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
 	freopen("d:\\onedrive\\c++\\test_3.9.1.txt","r",stdin); // �ַ����е�"\"Ҫд���� 
	int n;
	cin >> n;
	while( n -- ) {
		   int a,b;
		   cin >> a >> b;
		   cout << (a>b?a:b) << endl;
    }
}

/*
���ʹ�ó����ٵȴ��Ӽ����������ݣ�����ֱ�Ӵ�"c:\tmp\test.txt"�ļ���
��������:(�ļ���������)
4
2 5
4 3
12 90
8 7
��������(��Ļ��)����ǣ�
5
4
90
8
*/