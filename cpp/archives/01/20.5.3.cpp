//program 20.5.3.cpp  ���ֿռ������
#include <iostream>
using namespace std;
class A { };
class B { };
namespace graphics
{
	class A	{ int v; };
	A a0; //graphics���ֿռ��A
	B b;  //ȫ�����ֿռ��B 
}
using namespace graphics;	
int main()
{
	A a1;            //�����Դ��󣬲�֪�����ĸ����ֿռ��A
	graphics::A a2;  //����graphics���ֿռ��A
	::A a3;          //����ȫ�����ֿռ��A
	return 0;
}

