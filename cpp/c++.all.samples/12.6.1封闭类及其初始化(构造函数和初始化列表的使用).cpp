//program 12.6.1.cpp  封闭类
#include <iostream>
using namespace std;
class CTyre //轮胎类
{
 	  private:
	  	int radius;	//半径  
	  	int width;    //宽度
	  public:	
		  /*非封闭类也可以使用 初始化列表 来初始化本类的成员变量。*/
        CTyre(int r/*传给本类的成员变量radius*/,int w/*传给成员变量width*/):radius(r),width(w)/*这系普通类初始化的另一种方式*/
		{ 
			cout << "CTyre(int r,int w） was called！" << endl;
			cout << "radius = " << radius << "," << "width = " << width << endl;
		}
};
class CEngine //引擎类
{
public:
	CEngine()
	{
		cout << "The defult constructor function CEngine() was called!" << endl;
	}
};
class CCar {  //汽车类
	private:
		int price;  //价格（原生基础类型成员）
		CTyre tyre;/*引入其他类实例化的对象，它的初始化需要调用对应的外部类的构造函数*/
		CEngine engine;/*这个成员对象同理*/
	public:
   		CCar(int p,int tr,int tw );
};

/*类名(指封闭类名）::封闭类的构造函数名（参数表）：成员变量1（参数表），成员变量2（参数表），..*/
/*封闭类CCar的构造函数CCar(...)； 初始化列表 ：（可以只添加部分）*/
CCar::CCar(int p/*用于初始化price成员变量*/,
	int tr,int tw/*用来初始化tyre成员对象的*/
		/*没有为CEngine类型的 engine成员对象提供初始化参数，那么编译器会尝试用默认CEngine类的无参默认构造函数去初始化engine成员对象*/):
	/*初始化列表：*/
	price(p)/*price成员是CCar对象的原生基础类型成员,本语句使得本类的price成员变量值=p*/,
	tyre(tr, tw)//初始化列表结束。
{
	cout << "完成对封闭类的各成员变量和成员对象的初始化" << endl;
};//封闭类CCar的构造函数CCar(...)
int main()
{	
	CCar car(20000,17,225); 
 	return 0;
}
/*CCar是个封闭类，有tyre和engine两个成员对象。编译器需要弄明白，car对象中的tyre和engine成员对象该如何初始化。
编译器已经知道这里的car对象是用上面的CCar（int p，int tr，int tw）构造函数初始化的；
那么tyre和engine这两个引自外部的成员对象该如何初始化，就要看CCar（int p，int tr，int tw）后面的：初始化列表  了。

初始化：初始化某个类一般指的是初始化类当中的 成员变量以及成员对象
封闭类的初始化列表（位于构造函数后）的目的主要是为了处理后者（成员对象），
当然普通的基础类型成员变量也能一并处理，列在初始化列表中
该初始化列表中交待了，tyre应以tr和tw作为参数调用CTyre（int r，int w）构造函数初始化，但是没有交待engine该怎么处理;
这种情况下，编译器就认为engine应该用CEngine类的无参构造丽数初始化。
而CEngine类确有一个编译器自动生成的默认无参构造丽数，因此，整个car对象的初始化问题就解决了。*/