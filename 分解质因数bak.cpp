/**
 * 找出整数n的所有质因数
 */
#include <stdio.h>
// #include <stdbool.h>

//判断n是否为质数
// bool isPrime(int n) {
// 	if (n<2)
// 		return false;
// 	for (int i=2;i<n;i++) {
// 		if (n%i==0)
// 			return false;
// 	}
// 	return 1;
// }
int isPrime(int n) {
	if (n < 2)
		return 0;
	for (int i = 2; i < n; i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int main() {
	int n=0;
	printf("分析给定整数的所有质因数(构成的集合)\n");
	printf("input a integer:");
	scanf("%d",&n);
	for (int i=2; i<n; i++) {
		if (n%i==0) { //如果i能整除n
			if (isPrime(i)) { //并且i是质数
				printf("%d\n",i);
			}
		}
	}
	return 0;
}

