//program 20.4.2.cpp  �����κ��쳣��catch��
#include <iostream>
using namespace std;
int main()  
{
	double m ,n;
	cin >> m >> n;
	try {
		cout << "before dividing." << endl;
		if( n == 0)
			throw -1; //�׳������쳣
		else if( m == 0 )
			throw -1.0; //�׳�double���쳣
		else
			cout << m / n << endl;
		cout << "after dividing." << endl;
	}
	catch(double d) {
		cout << "catch(double) " << d <<  endl;
	}
	catch(...) {
		cout << "catch(...) " << endl;
	}
	cout << "finished" << endl;
	return 0;
}

