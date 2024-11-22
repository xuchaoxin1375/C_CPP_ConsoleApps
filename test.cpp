#include <iostream>
using namespace std;

/*  求小数转换为二进制后的数码 方法1:递推 */
void d1(float f, int r)
{
  while (f > 0)
  {
    int k;
    f *= r;     // 小数点往右挪一位
    k = (int)f; // 获取整数位
    cout << k;  // 打印整数位作为数码
    f -= k;     // 取f的小数部分,用类似方操作计算下一位数码,形如递推
  }
}

/*  求小数转换为二进制后的数码 方法2:通项 */
void d2(float f, int r)
{
  int k = 0;
  while (f - (int)f)
  {
    f *= r;
    k = (int)f % r;
    cout << k;
    // if (f - (int)f == 0)//小数部分为0时退出
    //   break;
  }
}
void intr1(float f, int r)
{
  int n = (int)f;
  int k = 0;
  // 由于求整数部分的数码是从低位到高位,这里使用递归的方式逆序打印
  if (n == 0)
  {
    return;
  }
  k = n % r;
  n = (n - k) / r;
  intr1(n, r);
  cout << k;//打印语句放在递归调用后才可以逆序打印
  // 以下是从低位到高位打印的方案
  // while (n)
  // {
  //   k = n % r;
  //   cout << k;
  //   f /= r;
  //   n = (n - k) / r;

  // }
}
void intr2(float f, int r)
{
  int n = (int)f;
  int k = 0;
  k = n % r;      // 不要立刻打印k,留到递归调用后打印,才可以逆序打印
  n = int(n / r); // 这里的int可以不写,C/C++自动截取整数,因为n是int型
  if (n)
  {
    intr2(n, r);
  }

  cout << k;
}
int main()
{

  int r = 8;//要将数转换为r进制表示
  float f = 0;
  cout << "input a number(decimal),such as 4.625: ";
  cin >> f;
  intr2(f, r);
  cout << '.';
  d2(f - (int)f, r);
  cout << endl;
  return 0;
}
