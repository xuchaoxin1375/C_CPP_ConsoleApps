#include <iostream>
#include <cmath>
#include <bitset>
#include <iomanip>
using namespace std;
int main(int argc, char const *argv[])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                int n = i * 100 + j * 10 + k;
                if (pow(i, 3) + pow(j, 3) + pow(k, 3) == n && n>100)
                {
                    /* code */
                    cout << n << endl;
                }
            }
        }
    }
    return 0;
}

// 判断一个数是否是水仙花数
bool isNarcissistic(int number)
{
    int originalNumber = number;
    int sum = 0;
    int digits = 0;

    // 计算位数
    int temp = number;
    while (temp > 0)
    {
        digits++;
        temp /= 10;
    }

    // 计算每个位上的数字的 n 次幂之和
    temp = number;
    while (temp > 0)
    {
        int digit = temp % 10;
        sum += std::pow(digit, digits);
        temp /= 10;
    }

    // 如果和等于原数，则是水仙花数
    return sum == originalNumber;
}