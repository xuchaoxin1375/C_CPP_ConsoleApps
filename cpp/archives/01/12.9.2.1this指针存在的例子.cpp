//program 12.9.2.1.cpp  this指针存在的证明
#include <iostream>
using namespace std;
class A
{ 	
		 int i;
   public: 
   	 void Hello() { 
        // cout << i << endl;引发崩溃
         cout << "hello" << endl; 
     } /*成员函数Hello()不访问具体具体对象的成员允许这样直接调用类这种的成员函数；否则会引发崩溃。*/
};
int main() 
{ 
  	A * p = NULL;
  	p->Hello();
}
