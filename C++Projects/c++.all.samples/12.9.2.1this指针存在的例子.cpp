//program 12.9.2.1.cpp  thisָ����ڵ�֤��
#include <iostream>
using namespace std;
class A
{ 	
		 int i;
   public: 
   	 void Hello() { 
        // cout << i << endl;��������
         cout << "hello" << endl; 
     } /*��Ա����Hello()�����ʾ���������ĳ�Ա��������ֱ�ӵ��������ֵĳ�Ա���������������������*/
};
int main() 
{ 
  	A * p = NULL;
  	p->Hello();
}
