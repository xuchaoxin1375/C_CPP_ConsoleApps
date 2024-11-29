#include <bits/stdc++.h>
/*
演示负数补码移位操作,空位填充
向左移动数值绝对值变大,空位出现在低位,和原码一样填补0
向右移动数值绝对值变小,空位出现在高位,和反码一样填补1
 */
using namespace std;
int main(int argc, char const *argv[])
{
    int a = -2;
    // a << 1;
    // int c = 0x8fffffff;
    int c = 0x80000000;
    int c1 = c << 1;
    int c2 = c >> 1;
    int const bits = 4;
    bitset<bits> b(a);
    bitset<bits> b1(a >> 1);
    bitset<bits> b2(a << 1);
    cout << (a << 1) << ';' << "0b" << b2 << endl
         << a << ';' << "0b" << b << endl
         << (a >> 1) << ';' << "0b" << b1 << endl;
    cout << "c=" << dec << c << ";" << showbase << hex << c << endl
         << "(c<<1)=" << dec << c1 << ";" << showbase << hex << c1 << endl
         << "(c>>1)=" << dec << c2 << ";" << showbase << hex << c2 << endl;
    return 0;
}
