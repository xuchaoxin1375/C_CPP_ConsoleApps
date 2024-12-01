#include <iostream>
#include <cmath>
#include <bitset>
#include <iomanip>
using namespace std;
int main(int argc, char const *argv[])
{
    extern int decToBin(int x);
    decToBin(-1022);
    cout << endl;
    decToBin(5);
    cout << endl;
    decToBin(-5);
    cout << endl;
    decToBin(0);

    return 0;
}

/**
 * Recursively converts a non-negative integer to its binary representation.
 * The function prints the binary digits in order.
 *
 * @param x The integer to convert, expected to be non-negative.
 *          If a negative value is passed, it is converted to positive using abs().
 */
int decToBinaryAbs(int x)
{
    x = abs(x);

    if (x > 0)
    {
        int b = x % 2;
        decToBinaryAbs(x / 2);
        // 打印数码
        cout << b;
    }

    return 0;
}
int decToBin(int x)
{
    if (x < 0)
    {
        cout << "-";
    }
    else if (x == 0)
    {
        cout << "0";
        return 0;
    }
    decToBinaryAbs(x);
    return 0;
}