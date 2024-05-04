//program 17.4.2.3.cpp   �ļ���������
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char * argv[])
{
	if( argc != 3 ) {
		cout << "File name missing!" << endl;
		return 0;
	}
	ifstream inFile(argv[1],ios::binary|ios::in); //�����ƶ�ģʽ��
	if( ! inFile ) {
		cout << "Source file open error." << endl;
		return 0;
	}
	ofstream outFile(argv[2],ios::binary|ios::out); //������дģʽ��
	if( !outFile) {
		cout << "New file open error." << endl;
		inFile.close(); //�򿪵��ļ�һ��Ҫ�ر�
		return 0;
	}
	char c;
	while( inFile.get(c))    //ÿ�ζ�ȡһ���ַ�
		outFile.put(c);	  //ÿ��д��һ���ַ�
	outFile.close();  
	inFile.close();
	return 0;
}

