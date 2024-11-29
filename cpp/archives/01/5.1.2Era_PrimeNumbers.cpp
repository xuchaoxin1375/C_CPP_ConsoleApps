/* 筛法求素数

 */
#include <iostream>
#include <cmath>
using namespace std;

const int MAX_NUM = 1e7;	// 假设我们要找出1000(1e3)以内的素数
bool isPrime[MAX_NUM + 10]; // 最终如果isPrime[i]为true，则表示i是素数

int main()
{
	int cnt = 0;
	for (int i = 2; i <= MAX_NUM; ++i) // 初始化状态:开始假设所有数都是素数
		isPrime[i] = true;
	for (int i = 2; i <= MAX_NUM; ++i)
	{ // 每次将一个素数的所有倍数标记为非素数
		if (isPrime[i])
		{
			++cnt;
			// cout << i << endl; // 直接打印素数
			// 素数的倍数(2倍以上)标记位非素数
			for (int j = 2 * i; j <= MAX_NUM; j += i)
			{

				isPrime[j] = false; // 将素数 i 的倍数标记为非素数
			}
		}
	}
	// 集中输出所有素数
	// for (int i = 2; i <= MAX_NUM; ++i)
	// 	if (isPrime[i])
	// 		cout << i << endl;
	cout << "prime number count in [2," << MAX_NUM << "]:" << cnt << endl;
	return 0;
}
