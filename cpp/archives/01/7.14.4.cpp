//program 7.14.4.cpp ��������ⷨ��
#include <iostream>
#include <string>    //Ҫʹ��string������������ͷ�ļ�
#include <algorithm> //Ҫʹ�������㷨sort ���������ͷ�ļ�
using namespace std;
const int WORD_NUM = 10000;
string words[WORD_NUM + 10];
int main()  
{
	int n;
	cin >> n;
	for( int i = 0;i < n;++i ) 
		cin >> words[i]; //wordsÿ��Ԫ�ش��һ������
	sort(words,words+n); //����C++��׼ģ��sort��������
	for( int i = 0;i < n;++i ) 
		cout << words[i] << endl;
	return 0;
}

