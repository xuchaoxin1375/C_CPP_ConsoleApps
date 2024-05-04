//program 14.4.1.cpp 派生类的构造函数和析构函数调用顺序
#include <iostream>
#include <string>
using namespace std;
class CBug  {
		int legNum,color;
		int No ;
	public:
		/*利用初始化列表来指定基类的构造函数;以及为派生类的某些成员变量做初始化
		定义了有参constructor后,编译器不在生成默认无参constructor了;那么如果此时欲调用无参构造函数就会出错!!!*/
		CBug (int ln, int cl,int No_):legNum/*有默认值的参数必须集中靠某一侧,不能够出现在中间,这个调整一下,(注意传参时的顺序即可)*/(ln),color(cl),No(No_)
		{
			/*由于初始化列表中已经成员变量指定了初始化值,所以析构函数内部就不需要再次特地编写初始化成员变量的语句*/
			cout << "CBug Constructor" <<endl;
		};
		~CBug() 
		{
			cout << "CBug Destructor" ;
			cout << ":" << No<<endl;
		}
		void PrintInfo() 
		{
			cout << legNum << "," << color <<endl;
		}

};
class CFlyingBug: public CBug 
{
		int wingNum;
	public:
		/*利用初始化列表来指定基类的构造函数;以及为派生类的某些成员变量做初始化*/
		// CFlyingBug( ) { } 若不注释掉则会编译出错;因为定义了有参constructor后,编译器不在生成默认无参constructor了;那么如果此时欲调用无参构造函数就会出错!
		CFlyingBug ( int ln, int cl,int No_, int wn):CBug(ln,cl,No_),wingNum(wn) 
		{
			cout << "CFlyingBug Constructor" <<endl;
			
		}
		~CFlyingBug() 
		{
			cout << "CFlyingBug Destructor" << endl;
			cout << "\t";
		}

};
int main() {
	CBug bug1(1,2,1);
	CFlyingBug fb(2,3,2,4);//执行constructor(先执行基类CBug的constructor,然后执行派生类CFlyingBug的constructor
	CBug bug2(3,4,3);
	fb.PrintInfo ();
	return 0;
	/*执行destructor(对于一个派生类的消亡,
	先执行派生类CFlyingBug的destructor,再执行基类CBug的destructor)*/
	/*但是如果在程序中同时存在派生类对象和基类对象,那么哪个对象先消亡要取决于定义顺序,后定义的先消亡(每个种类型的对象又尤其自己的destructor调用路线;
	* 
	基类的所有成员(包括私有成员,但私有成员是无法被(只属于)派生类的方法所访问到,还是需要基类有对应的方法才能够间接访问而且基类的方法得是公开的才可.)自动成为派生类的成员。*/
}

