#define _CRT_SECURE_NO_WARNINGS
//program 13.2.1.cpp  重载"="
#include <iostream>
#include <cstring>
using namespace std;
class String {
	private:  
        char * str;
	public:
		/*利用初始化列表来建立构造函数(无参默认构造函数String(),该函数讲str初始化为NULL.*/
		String ():str(NULL) { }
		/*返回值str的 类型是const char* 常量指针.(即str所指的字符串不能够通过这个str指针来更改(保证安全). */
		const char * c_str()
		{
			return str;/*返回成员变量str字符指针的值(是一个指向字符的地址)*/
		};/*c_str()是函数体都写在类中的内联函数.*/
		/*声明 名为operator = () 的运算符重载函数*/
		char * operator = (const char * s);/*const char* 的类型比char *的范围更广些 */
		/*声明析构函数.*/
		~String( );
};//class String{}

/* "="被重载为string类的(重载运算符)成员函数*/
char * String::operator = (const char * s) //重载"="以使得 obj = "hello"能够成立
{
	/*区分清楚成员变量str和参数s (两者连类型都不一样char *和const char* )*/
	/*如果string类对象的成员变量str=NULL*/
	/*三个并列分支只会进入其一(但判断可能都比过去)*/
	if (str) //str为NULL跳过delete 操作
	{
		delete[] str;/*delete并不会讲str指向NULL*/
	}/*如果不delete 旧有的内容,str在接受新的new到的内存的地址后,旧空间还是会被占用的.(通过内存监视可知)*/
	if(s) {  //s不为NULL才会执行拷贝(或者说才有拷贝的意义/需要,否则拷贝后和没拷贝结果都一样,不如不拷贝) 
		str = new char[strlen(s)+1];/*通过new申请一块满足新字符串内存要求的空间大小的内存,下面调用字符数组的字符串复制函数,所以空间多申请一个char保存'\0'*/
		strcpy( str, s);
	}
	else
	{
		str = NULL;
	}
	return str;
}
/*析构函数*/
String::~String( ) 
{ 
    if( str)  
		delete [] str; /*话说delete只能够删除new得到的空间*/
};

int main()
{
	  String s;
	  s = "Good Luck," ; //等价于 s.operator=("Good Luck,");
	  cout << s.c_str() << endl;
      // String s2 = "hello!";   //这条语句要是不注释掉就会出错
	  s = "Shenzhou 8!"; //等价于 s.operator=("Shenzhou 8!");
	  cout << s.c_str() << endl;
	  return 0;
}
/*c_str()函数返回了指向String对象内部动态分配的存储空间的指针，
但是不希望外部得到这个指针后，去修改其指向的字符串的内容，因此，将返回值设为const char*。s对象内部的字符串就不会轻易地从外部被修改了：
这样，假定s是String对象，那么下面两条语句编译时都会报错，

char wp = s.c.，str（）；strcpy（s.c_str（），"Tiangong 1"）；
第一条语句出错是因为“="左边是char*类型，右边是const char*类型，两边类型不匹配；
第二条语句出错是因为strepy函数的第一个形参是char关类型的，而这里实参给的却是constchar#类型的，同样类型不匹配。

如果没有对“=”的重载，“s ="Good Luck，"肯定会因为类型不匹配而编译出错。 字符串常量"Good Luck,"的类型:const char * ;const char* 的类型不能够赋值给char* 变量


经过重载后，“s ="Good Luck，"等价于“s.operator =（"Good Luck，"）；”，就没有问题
了。
在operator=函数中，要先判断str是否已经指向动态分配的存储空间，如果是，那么要先释放那片空间，然后重新分配片空间，再将参数s指向的内容复制过去，这样，对象中.
存放的字符串就和s指向的字符串一样了。
分配空间的时候要考虑到字符串结尾的“\0'，所以分配的字节数要比strlen（s）多1。

需要注意一点，即使对“一”做了重载，"Strings2 ="hello！"，，”还是会编译出错的，
因为这是条初始化语句要用到构造函数，而不是赋值号“=”。
String类没有编写 参数类型为char*的 构造函数，因此编译不能通过。*/
