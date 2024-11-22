#include <iostream>
#include <bitset>
using namespace std;
int main()
{
    int number = 42;
    bitset<32> binary1(number);
    cout << binary1 << endl;
    return 0;
}