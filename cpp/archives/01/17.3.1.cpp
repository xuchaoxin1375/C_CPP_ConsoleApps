//program 17.3.1.cpp  ������Ĺ��캯�����ļ�
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
 	ifstream inFile;
    inFile.open( "c:\\tmp\\test.txt",ios::in);
 	if(inFile) //����������˵���ļ��򿪳ɹ�
    		inFile.close();
     else
   		cout << "test.txt doesn't exist" << endl;
	ofstream oFile;
	oFile.open( "test1.txt", ios::out);
	if( !oFile) //����������˵���ļ��򿪳���
		cout << "error 1" << endl;
	else
		oFile.close();
	oFile.open( "tmp\\test2.txt",ios::out | ios::in);
	if( oFile) //����������˵���ļ��򿪳ɹ�
		oFile.close();
	else
		cout << "error 2" << endl;
	fstream ioFile;
    ioFile.open( "..\\test3.txt", ios::out | ios::in | ios::trunc );
	if(!ioFile)
		cout << "error 3" << endl;		
	else
		ioFile.close();
	return 0;
}

