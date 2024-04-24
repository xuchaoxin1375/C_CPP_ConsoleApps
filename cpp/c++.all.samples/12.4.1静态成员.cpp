//program 12.4.1.cpp  静态成员的应用举例
#include <iostream>
using namespace std;
/*累计所有矩形的个数以及面积总和:*/
class CRectangle
{
	private:/*私有化静态变量,使其更安全,不被其他类的函数/全局函数改动*/
   		int w, h;
	     static int totalArea;  //矩形总面积
   		static int totalNumber; //矩形总数
	public:
	     CRectangle(int w_,int h_);
		 /*析构函数~CRectangle()*/
   		 ~CRectangle();
		 /*静态成员函数:*/
	     static void PrintTotal();  
		 /*打补丁:*/
		CRectangle(CRectangle & r);/*注意成员声明中不要(也不需要)出现限定名CRectangle::*/
};
/*自定义的复制构造函数*/
CRectangle::CRectangle(CRectangle& r)
{

	totalNumber++; 
	totalArea += r.w * r.h;
	w = r.w;
	h = r.h;

}
CRectangle::CRectangle(int w_,int h_)
{
    w = w_;  h = h_;
    totalNumber ++;        //有对象生成则增加总数
    totalArea += w * h;    //有对象生成则增加总面积
}
CRectangle::~CRectangle()
{
    totalNumber --;      //有对象消亡则减少总数
    totalArea -= w * h;  //有对象消亡则减少总面积
}
/*普通成员函数PrintTotal()*/
void CRectangle::PrintTotal()
{
    cout << totalNumber << "," <<  totalArea << endl; 
}
/*
必须在定义类的文件中对静态成员变量进行一次声明或初始化。
否则编译能通过，链接不能通过。*/

int CRectangle::totalNumber = 0;
int CRectangle::totalArea = 0;

int main()
{
	/*定义并初始化两个对象.r1,r2 */
	CRectangle 
		r1(3,3), 
		r2(2,2);
   //cout << CRectangle::totalNumber; // 错误, totalNumber是私有的 
	CRectangle::PrintTotal();
	r1.PrintTotal();
	/*将要退出main函数,对象开始消亡.*/
	return 0;
}
/*这个程序的基本思想是：CRectangle类只提供一个构造函数，那么所有CRectangle对象生成的时候都需要用这个构造函数初始化，因此在这个构造函数中增加总数和总面积的数值即可：而所有CRectangle对象消亡时都会执行析构函数，所以在析构函数中减少总数和总面积的数值即可。
第7行和第8行的两个成员变量用来记录程序中所有矩形对象的总数和它们的总面C 积。这两个值显然不能每个对象都维护自己的一份，而应该是一-共只有一-份。虽然用两个全局变量来存放这 两个值也可以，但那样就无法从形式上一眼看出这两个全局变量和CRectangle类的紧密联系，也就看不出这两个全局变量会在哪些函数中被访问。把它们写成CRectangle类的静态成员变量，这个问题就迎刃而解了。输出矩形总数和总面积的函数PrintTotal没有写成全局函数，而是写成CRectangle类的静态成员函数，道理也是一-样的。
I静态成员变量必须在类定义的外面专门作-下声明，声明时变量名前面加“类名：：”，如第29行和第30行。声明的同时电可以初始化。如果没有声明，那么程序编译的时候虽然不会报错，但是到链接（ink）阶段会报告“标识符找不到”，总之是不能生成.exe文件。第36行如果没有注释掉的话，编译会出错的。因为totalNumber是私有成员]不能在成员函数外面访问。
第37行和第38行输出结果相同，说明二者是等价的，因为静态成员函数不具体作用于某个对象，所以静态成员函数内部不能访问非静态成员变量，也不能调用非静态成员函数。

上面程序中，CRectangle类的写法表面上看没有什么问题，实际上是有bug的。
原因就是并非所有的CRectangle对象生成的时候都会用程序中的那个构造函数初始化。如果使用该类的程序稍微复杂一些，包含以CRectangle对象为参数的函数或以CRectangle对象为返回值的函数，或出现了“CRectangle rl（r2）；"
这样的语句，那么就有一些CRectangle对象是用默认复制构造函数，而不是用构造函数CRectangle（intw_，inth_）进行初始化了。
这些对象生成的时候没有增加totalNumber和totalArea的值，而消亡的时候却减少了）（多减了）
totalNumber和totalArea的值，这显然就会有bug的。解决的办法就是为CRectangle类编写如下复制构造函数：
CRectangle：：CRectang1e（CRectangle&r）
*/

