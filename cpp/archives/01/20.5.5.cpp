//program 20.5.5.cpp ����ʹ�����ֿռ��е�����
#include <iostream>
#include <vector>
using std::cout;
using std::vector;
using std::endl;
int main()
{
   vector<int> v; //ǰ�潻������vector������std��
   vector<int>::iterator i = v.begin();
   cout << "Hello" << endl; //ǰ�潻������cout��endl������std��
   cout << "World" << endl;
   return 0;
}
