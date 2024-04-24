//program 12.6.2.cpp  封闭类的结构函数和析构函数的调用顺序.
#include <iostream>
using namespace std;
class CTyre {
     public:
		CTyre() {  cout << "CTyre constructor" << endl; }
		~CTyre() { cout << "CTyre destructor" << endl; }
};
class CEngine {
     public:
		CEngine() { cout << "CEngine constructor" << endl; }/*constructor n. 构造函数；构造器；建造者*/
		~CEngine() { cout << "CEngine destructor" << endl; }/*destructor 美: [dɪ'strʌktə] 析构函数；解构式；析构器；破坏器；爆破装置*/
};
/*封闭类*/
class CCar {
	private:
		/*根据成员变量的定义顺序来决定那个类的构造函数写执行*/
		CEngine engine;  
		CTyre tyre;
	public:
		/*封闭类的无参默认析构函数CCar(),任然还是要调用成员对象的构造函数,然后才能够进入CCar()的函数体(这里是打印CCar constructor*/
		/*封闭类CCar的构造函数*/
		CCar( )	{ cout << "CCar constructor" << endl; }
		~CCar() { cout << "CCar destructor" << endl; }
};
int main(){
		CCar car; 
		return 0;
}
/*封闭类对象生成时，先执行所有成员对象的构造函数，然后才执行封闭类自己的构造函数。
成员对象构造函数的执行次序和成员对象在类
的定义中的次序一致，与它们在构造函数初始化列表中出现的次序无关。
当封闭类对象消亡时，先执行封闭类的析构函数，然后再执行成员对象的析构函数;
析构函数的执行次序和构造函数的执行次序相反，即先 构造 后 析构，
这是C++语言处理此类次序问题的一般规律。*/
