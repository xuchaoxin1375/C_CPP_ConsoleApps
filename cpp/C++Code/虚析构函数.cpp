//program 15.5.1.Cpp
#include < iostream >
#define TO_VERSION_NEW 1/*根据需要是否将(基类)虚构函数编译为虚析构函数(virtual版)*/
using namespace std;
class CShape
{
public:
	
#if TO_VERSION_NEW
	virtual ~CShape()
#else
	~CShape()
#endif
	{
		cout << "CShape: :destrutor" << endl;
	};
};
class CRectangle : public CShape
{
public:
	int W, h;	//宽和高
	/*如果基类的析构函数是虚函数,派生类的析构函数也自动会变成虚函数(如果没有特地加virtual的话)*/
	~CRectangle() { cout << "CRectangle:: destrutor" << endl; }
}; 
int main()
{
	CShape* p = new CRectangle;/*派生类对象的内存地址赋值给基类指针,如果析构函数不是虚函数,那么p所指的内存被释放掉后,编译器只知道p的(定义时)的类型是基类型CShape,调用的析构函数也到CShape中去找(因为编译器不知道p所指的那个对象那个对象是基类型本身的对象还是基类型所派生的类型的对象.)*/
	delete p;/*如果没有delete就不会触发任何析构函数.*/
	return 0;
}
/*程序的输出结果:
CShape::destrutor
*/

/*输出的结果说明执行“delete p;" 只引发了CShape 类的析构函数被调用，没有引发CRectangle类的析构函数调用。
这是因为该语句是静态联编的，编译器编译到此时,不可能知道此时p到底指向那个类型的对象,
它只根据 p的类型 是CShape*,来决定应该调用CShape类的析构函数。
但按理说,“delete p;”导致一个CRectangle类的对象消亡,应该调
用CRectangle类的析构函数才符合逻辑，否则有可能引发程序的bug。

例如，假设程序需要对CRetangle对象进行计数,那么此处不调用CRetangle类的析构函数,就会导致计数不正确(如果借助析构函数来计数)。
再如,假设CRectangle对象存续期间进行了动态内存分配，而释放内存的操作都是在析构函数中进行的,那么此处不调用CRetangle类的析构函数,就会导致被delete的对象中的动态分配的内存以后再也没有机会回收。
综上所述,希望“delete p;”这样的语句,能够聪明地根据p所指向的对象,来执行相应的析构函数。实际上,这也是多态。
为了在这种情况下实现多态,C++规定,需要将基类的析构函数声明为虚函数，即虚析构函数。将上面的程序中的CShape类改写,在析构函数前加“virtual"关键字,将其声明为虚函数:
class CShape
{
public:
virtual ~ CShape() { cout << " CShape: destrutor"<< endl; }
};
则程序的输出结果变成:
CRectangle:: destrutor
CShape :: destrutor
说明CRetangle类的析构函数被调用了。
实际上,派生类的析构函数,会自动调用基类的析构函数(是自下而上的)。而且,
只要基类的析构函数是虛函数,那么派生类的析构函数不论是否用“virtual"关键字声明,都自动成为虚析构函数。(不同类的析构函数名显然不同,其实这里不需要同名同参数)

一般来说,一个类如果定义了虛函数，
则最好将析构函数也定义成虚函数。(使得
*/

/*版本_2*/
