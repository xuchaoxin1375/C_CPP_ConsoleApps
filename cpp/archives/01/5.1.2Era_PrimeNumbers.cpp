/* ɸ��������

 */
#include <iostream>
#include <cmath>
using namespace std;

const int MAX_NUM = 1e7;	// ��������Ҫ�ҳ�1000(1e3)���ڵ�����
bool isPrime[MAX_NUM + 10]; // �������isPrime[i]Ϊtrue�����ʾi������

int main()
{
	int cnt = 0;
	for (int i = 2; i <= MAX_NUM; ++i) // ��ʼ��״̬:��ʼ������������������
		isPrime[i] = true;
	for (int i = 2; i <= MAX_NUM; ++i)
	{ // ÿ�ν�һ�����������б������Ϊ������
		if (isPrime[i])
		{
			++cnt;
			// cout << i << endl; // ֱ�Ӵ�ӡ����
			// �����ı���(2������)���λ������
			for (int j = 2 * i; j <= MAX_NUM; j += i)
			{

				isPrime[j] = false; // ������ i �ı������Ϊ������
			}
		}
	}
	// ���������������
	// for (int i = 2; i <= MAX_NUM; ++i)
	// 	if (isPrime[i])
	// 		cout << i << endl;
	cout << "prime number count in [2," << MAX_NUM << "]:" << cnt << endl;
	return 0;
}
