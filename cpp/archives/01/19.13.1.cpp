//program 19.13.1.cpp string��Ĳ��ҳ�Ա����
#include <iostream>
#include <string> 
using namespace std;
int main()  
{
	string s1("Source Code");
	int n;
	if( (n = s1.find('u')) != string::npos ) //����u���ֵ�λ��
		cout <<"1) "<< n << "," << s1.substr (n) << endl;  //��� 1) 2,urce Code 
	if( (n = s1.find("Source", 3)) == string::npos ) //���±�3��ʼ����"Source",�Ҳ���
		cout <<"2) "<< "Not Found" << endl;   //��� 2) Not Found
	if(( n = s1.find("Co")) != string::npos )  //�����Ӵ� "Co",���ҵ�������"Co"λ��
		cout <<"3) "<< n << ","<< s1.substr(n) << endl; //��� 3) 7,Code
	if( (n = s1.find_first_of("ceo")) != string::npos )
         //���ҵ�һ�γ�����'c'��'e'��'o'��λ��
		cout <<"4) "<< n << ","<< s1.substr(n) << endl; //��� 4) 1,ource Code
	if( (n = s1.find_last_of('e')) != string::npos )     //�������һ��'e'��λ��
		cout <<"5) "<< n << ","<< s1.substr(n)<< endl;  //��� 5) 10,e
	if( (n = s1.find_first_not_of("eou",1)) != string::npos) 	
         //���±�1��ʼ���ҵ�һ�γ��ַ�'e'��'o'��'u'�ַ���λ��
		cout <<"6) "<< n << ","<< s1.substr(n)<< endl;  //��� 6) 3,rce Code
	return 0;
}

