//program 3.9.1.cpp  freopen用法示例
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
 	freopen("d:\\onedrive\\c++\\test_3.9.1.txt","r",stdin); // 字符串中的"\"要写两次 
	int n;
	cin >> n;
	while( n -- ) {
		   int a,b;
		   cin >> a >> b;
		   cout << (a>b?a:b) << endl;
    }
}

/*
语句使得程序不再等待从键盘输人数据，而是直接从"c:\tmp\test.txt"文件中
读入数据:(文件内容如下)
4
2 5
4 3
12 90
8 7
则程序输出(屏幕上)结果是：
5
4
90
8
*/