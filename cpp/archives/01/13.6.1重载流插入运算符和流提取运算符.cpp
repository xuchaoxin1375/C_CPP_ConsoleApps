//program 13.6.1.cpp  重载 << 和 >>
/*假定 c是Complex复数类的对象，
现在希望
编写“cout<< c；”，就能以“a+bi”的形式输出c的值；

编写"cin>> c；”，就能从键盘接受“a+bi”形式的输入，
便得c.real=a ; c.imag=b; 
*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class Complex 
{
	  double real,imag;	   
public:
      Complex( double r=0, double i=0):real(r),imag(i){ }; //initial_construcotr
      friend ostream & operator<<( ostream & os,const Complex & c);//friend_overload_operator_<<
      friend istream & operator>>( istream & is,Complex & c);      //friend_overload_operator_>>
};//class Complex{};
/*全局运算符的重载.*/
/*引用iostream中的ostream类*/
ostream & operator<<( ostream & os,const Complex & c)
{
    /*os类似于cout,都是ostream类的对象;这里os形参是用来接受cout对象的*/
	os << c.real << "+" << c.imag << "i"; //以"a+bi"的形式输出 
	return os;
} 
istream & operator>>( istream & is,Complex & c)
{
    string s;
    is >> s;  //将"a+bi"作为字符串读入, "a+bi" 中间不能有空格(a,b可能都是多位数)
    /*解析读入s的字符串*/
    int pos = s.find("+",0); /*string类的find()查找函数,返回"+"的位置*/

    string sTmp = s.substr(0,pos); //分离出代表实部的字符串 
    c.real = atof(sTmp.c_str());//atof库函数能将const char*指针指向的内容转换成 float 

    sTmp = s.substr(pos+1, s.length()-pos-2);   //分离出代表虚部的字符串
    c.imag = atof(sTmp.c_str());
	return is;
}
int main()
{
  	Complex c;
  	int n; 
  	cin >> c >> n; /*输入一个虚数和一个实数:13.2+133.4i 87*/
  	cout << c << "," << n;
  	return 0;
}
/*因为没有办法修改ostream类和istream类，所以只能将“<<”和“>>”重载为全局函数的形式。
由于这两个函数需要访问Complex类的私有成员因此在Complex类定义中将它们声明为友元，“cout<< c”会被解释成operator<<(cout,c)，"那么编写operator<<函数时，它的两个参数就不难确定。
参数OS只能是ostream的引用，而不能是ostream对象，因为ostream的复制构造函数是私有的，没有办法生成ostream参数对象。
operator<<<函数的返回值类型设为ostream&，并且返回os，就能够实现“< <”的连续使用，如“cout << c<<5”。
“cout<< <c”进人operator<<后，OS引用的就是cout

用cin读入复数时，对应的输人必须是“a+ bi”的格式，而且中间不能有空格，如输入“13.2+33.4i”。“is>> s；”
读入一个字符串。读入后需要将字符串中的实部a和虚部b分离出来，分离的办法就是找出被“+”隔开的两个子串，然后将两个字串转换成浮点数。
调用了标准库函数atof 来将字符串转换为浮点数。该函数原型是：float atof（const char*），在cstdlib头文件中声明。*/
