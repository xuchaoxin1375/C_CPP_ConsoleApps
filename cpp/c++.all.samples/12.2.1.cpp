//program 12.2.1.cpp  ��������
#include <iostream>
using namespace std;
class CDemo {
    public:
	~CDemo()  //��������
    {  
        cout<< "Destructor called" << endl; 
    } 
};
int main () {
	CDemo array[2];        //���캯������2��
	CDemo  * pTest = new CDemo;  //���캯������
	delete pTest;          //������������
	cout << "-----------------------" << endl;
     pTest = new CDemo[2]; //���캯������2��
	delete [] pTest;      //������������2�� 
	cout << "Main ends." << endl;    
	return 0;
}

