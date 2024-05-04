#include <iostream>
#include <cstdio>
using namespace std;
bool isPrime(int n)
{
	if (n < 2)
	{
		return false;
	}
	for (int i = 2; i < n; ++i)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 2; i < n; ++i)
	{
		if (n % i == 0 && isPrime(i))
		{
			cout << i << endl;
		}
	}
	return 0;
}
