#include <iostream>
using namespace std;

int main()
{
     struct A
     {
          int a;
          char b;
          short c;
     };
     struct B
     {
          char b;
          int a;
          short c;
     };
     cout << "sizeof(A)=" << sizeof(A) << endl
          << "sizeof(B)=" << sizeof(B) << endl;
}
