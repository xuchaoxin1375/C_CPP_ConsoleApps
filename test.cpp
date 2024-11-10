#include <iostream>
#include <iomanip> //提供非十进制数形式输出
using namespace std;

void print_int_bin(int number);

int main()
{
  long long l = 123456789011LL;
  long long l1 = 123456789011;
  long long l2 = 0xffff000000000001;
  long long l3 = 0xffff000080000000;
  long long l4 = 0x0000000000000001;

  int i1 = l1;
  int i2 = l2;
  int i3 = l3;
  int n = -1;
  int b = 0b1010;
  cout << "l=" << l << endl
       << "l1=" << l1 << endl
       << "l2=" << l2 << endl // l2=-281474976710655
       << "l3=" << l3 << endl // l3=-281472829227008
       << "l4=" << l4 << endl // l4=1
       //  << "i1=" << i1 << endl
       << "i2=" << i2 << endl                                       // i2=1
       << "i3=" << i3 << endl;                                      // i3=-2147483648=-2^{31}
  cout << "i2=" << setw(8) << setfill('0') << hex << i2 << endl     // i2=00000001
       << "i3=" << setw(8) << setfill('0') << hex << i3 << endl;    // i3=80000000
  cout << "n=-1=0x" << setw(8) << setfill('0') << hex << n << endl; // 查看-1的补码
  cout << "b=" << dec << b << endl<<endl;                                 // b=10

  print_int_bin(i2);
  print_int_bin(i3);

  return 0;
}

void print_int_bin(int number)
{
  for (int i = 31; i >= 0; --i)
  {
    std::cout << ((number >> i) & 1);
  }
  std::cout << std::endl;
}
