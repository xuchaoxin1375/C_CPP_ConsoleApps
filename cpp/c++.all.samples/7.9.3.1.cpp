//program 7.9.3.1.cpp  �ַ��������÷�
#include <iostream>
#include <cstring> 
using namespace std;
int main()  
{
	char s1[100] = "12345";
	char s2[100] = "abcdefg";
	char s3[100] = "ABCDE";
	strncat(s1,s2,3); // s1 = "12345abc
	cout << "1) " << s1 << endl; //��� 1) 12345abc
	strncpy(s1,s3,3); // s3��ǰ�����ַ�������s1,s1="ABC45abc"
	cout << "2) " << s1 << endl; //��� 2) ABC45abc
	strncpy(s2,s3,6); // s2 = "ABCDE"
	cout << "3) " << s2 << endl; //��� 3) ABCDE
	cout << "4) " << strncmp(s1,s3,3) << endl; 
	//�Ƚ�s1��s3��ǰ�����ַ����ȽϽ������ȣ���� 4) 0
	char * p = strchr(s1,'B'); //��s1�в��� 'B'��һ�γ��ֵ�λ��
	if( p ) // �ȼ��� if( p!= NULL) 
		cout << "5) " << p - s1 <<"," << *p << endl; //��� 5) 1,B
	else
		cout << "5) Not Found" << endl;
	p = strstr( s1,"45a"); //��s1�в����ִ� "45a"��s1="ABC45abc"
	if( p )
		cout << "6) " << p - s1 << "," << p << endl; //��� 6) 3,45abc
	else
		cout << "6) Not Found" << endl;
	//������ʾstrtok�÷���
	cout << "strtok usage demo:" << endl;
	char str[] ="- This, a sample string, OK.";
	//����Ҫ��str�����ȡ����" ,.-"�⼸���ַ��ָ����ִ�
	p = strtok (str," ,.-"); 
	while ( p != NULL) //ֻҪp��ΪNULL����˵���ҵ���һ���Ӵ�
	{
		cout << p << endl;
		p = strtok(NULL, " ,.-");//�������ã���һ������������NULL
	}
    return 0;
}

