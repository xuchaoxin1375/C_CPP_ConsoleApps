//program 20.4.6.cpp bad_alloc�쳣
#include <iostream>
#include <stdexcept>
using namespace std;
int main () 
{
  try  {
    char * p = new char[0x7fffffff]; //�޷�������ô��ռ䣬���׳��쳣
  }
  catch (bad_alloc & e)  {
    cerr << e.what() << endl;
  }
  return 0;
}

