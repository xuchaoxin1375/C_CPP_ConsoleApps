#include <iostream>
#include <cmath>
#include <bitset>
#include <iomanip>
using namespace std;
int main(int argc, char const *argv[])
{

    extern int get_bit_shift(int x, int n);
    extern int get_bit_mod(int x, int n);
    int (*func)(int, int);
    int n = 124;
    // 借助函数指针来引用不同的同结构函数
    func = get_bit_mod;
    // func = get_bit_shift;

    for (int i = 0; i < 32; i++)
    {
        // 从高位开始打印
        cout << func(n, 31 - i) << " ";
    }
    cout << endl;
    cout << hex << "0x" << setfill('0') << setw(8) << n << endl;
    return 0;
}

/**
 * @brief Given a number x, return the n-th bit (from the right, counting from 0)
 *        using bitwise shift operation.
 *
 * @param x The number whose n-th bit is queried.
 * @param n The index of the bit to query, from the right.
 *
 * @return 1 if the n-th bit is 1, 0 otherwise.
 */
int get_bit_shift(int x, int n)
{
    return (x >> n) & 1;
}

/**
 * @brief Get the n-th digit of a number x in the r-base number system.
 *
 * @param x The number whose n-th digit is queried.
 * @param n The index of the digit to query, from the right.
 * @param r The radix of the number system, default to 2 (binary).
 *
 * @return The value of the n-th digit of x in r-base number system.
 */
int get_digit_com(int x, int n, int r = 2)
{
    return (int)(x / pow(r, n)) % r;
}
int get_bit_mod(int x, int n)
{
    return get_digit_com(x, n, 2);
}
