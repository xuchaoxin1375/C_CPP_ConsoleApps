//program 19.5.1.1.cpp  stack����ת��ʮ��������k������
#include <iostream>
#include <stack> //ʹ��stack��Ҫ������ͷ�ļ�
using namespace std;
int main()
{
	int n,k;
	stack<int> stk;
	cin >> n >> k;  //��nת��Ϊk������ 
	if( n == 0) {
		cout << 0;
		return 0;
	}
	while( n ) {
		stk.push( n % k);
		n /= k;
	}
	while( ! stk.empty ()) {
		cout << stk.top();
		stk.pop();
	}
	return 0;
}

