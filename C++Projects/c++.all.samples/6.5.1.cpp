//program 6.5.1.cpp  ��ȡ�ַ����еķ������ַ�
#include <iostream>
#include <cstring>
using namespace std;
int main()  
{
	cout << strlen( "�й�") << endl;  //��� 4 
	char str[] = "���Ƕ�ϲ�� Micheal Jackson �ĸ���\"Who's bad\"";
	for( int i = 0; str[i]; ++ i ) //��ȡstr�з����ĵĲ������
		if( str[i] > 0) //���λΪ0���ֽڣ�һ����������
			cout << str[i];
    return 0;
}

