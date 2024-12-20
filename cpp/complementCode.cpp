/* 
利用这段代码来学习和检验你对机器数中的补码的理解
并且可以看到负数情况下,补码移位运算后补0还是补1
 */
// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <bitset>
#include <iomanip>

using namespace std;
int main()
{
    // 指定你想要的机器字长位数(最高位为符号位)
    size_t const bits = 4;//设bits=n ,则最高位为符号位,剩余n-1位是数值位,合理的取值应该是2以上,但也不能无限大,结合实际的话可以是8,16,32或64(此时类型建议用long long)
    int numbers = pow(2, bits);
    int width = ceil(log(numbers) / log(10))+1;//可以考虑正负号再加1
    // cout << width << endl;

    // return 0;
    for (short unsigned i = 0; i < numbers; i++)
    {

        short x = i - pow(2, bits - 1);
        bitset<bits> b(x);

        cout << showbase << "x = " << dec << "[" << setw(width) <<showpos<< x << "]" << ";" << "\t0b" << b << ";\t"  << hex << x << endl;
    }
    return 0;
}
