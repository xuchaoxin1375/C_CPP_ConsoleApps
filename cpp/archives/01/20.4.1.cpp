//program 20.4.1.cpp �쳣����
#include <iostream>
using namespace std;
int main()  
{
	double m ,n;
	cin >> m >> n;
	try {
		cout << "before dividing." << endl;
		if( n == 0)
			throw -1; //�׳�int�����쳣
		else
			cout << m / n << endl;
		cout << "after dividing." << endl;
	}
	catch(double d) {
		cout << "catch(double) " << d <<  endl;
	}
	catch(int e) {
		cout << "catch(int) " << e << endl;
	}
	cout << "finished" << endl;
	return 0;
}

