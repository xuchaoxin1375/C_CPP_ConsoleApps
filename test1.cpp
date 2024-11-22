#include <iostream>
using namespace std;

int main()
{
    // int number = 42;
    short int number = 32768;

    cout << -3 / 5 << endl
         << -5 / 5 << endl;

    // cout << (-3) % 5 << 3 % (-5) << 5 % (-3) << (-5) % 3 << endl //-
    //      << 3 % 5 << 5 % 3 << endl;
    cout << "Modulus of -3 by 5: " << (-3) % 5 << endl
         << "Modulus of 3 by -5: " << 3 % (-5) << endl
         << "Modulus of 5 by -3: " << 5 % (-3) << endl
         << "Modulus of -5 by 3: " << (-5) % 3 << endl
         << "Modulus of 3 by 5: " << 3 % 5 << endl
         << "Modulus of 5 by 3: " << 5 % 3 << endl
         << "modules of 21 by -5:" << 21 % (-5) << endl;
    return 0;
}
