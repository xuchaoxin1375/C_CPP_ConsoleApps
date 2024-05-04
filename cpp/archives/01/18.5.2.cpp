//program 18.5.2.cpp函数模板作为类模板的友元
#include <iostream>
#include <string>
/*类模板Pair<T1,T2>*/
using namespace std;
template <class T1, class T2>
class Pair
{
private:
	T1 key;    //关键字
	T2 value;  //值
public:
	/*constructor:*/
	Pair(T1 k, T2 v) :key(k), value(v) { };
	/*overload_operator_= */
	bool operator < (const Pair<T1, T2>& p) const;
	/*将重载的全局函数"<<"(流提取运算符)声明为友元;通过传入参数对象来调用该重载运算符:*/
	template <class T3, class T4>
	friend
		ostream& operator<< (ostream& o, const Pair<T3, T4>& p);
};
/*重载"<"成员函数模板*/
template<class T1, class T2>
bool Pair<T1, T2>::operator < (const Pair<T1, T2>& p) const
{ //"小"的意思就是关键字小
	return key < p.key;
}

/*重载流提取运算符"<<";*/
template <class T1, class T2>
ostream& operator<< (ostream& o, const Pair<T1, T2>& p)
{
	/*将类模板Pair<T1,T2>实例化为Pair<int,double>模板函数;同时定义了一个该类型的成员对象obj(同时将其初始化为(12,3.14)*/
	Pair<int, double> obj(12, 3.14);
	/*由于该函数模板是类模板的友元函数模板,故可以访问到该成员对象的私有成员变量*/
//obj.key = 4; 		(合法)

/*指定重载后的输出格式:*/
	o << "(" << p.key << "," << p.value << ")";
	return o;//为了实现连续输出;
}
int main()
{
	/*类模板Pair<T1,T2>的两种实例化举例*/
	Pair<string, int> student("Tom", 29), student_2("jack", 30);/*T<j(大写字母<小写字母)*/
	/*另一种实例化*/
	Pair<int, double> obj(12, 3.14);
	/*测试重载后的流提取运算符"<<"的效果:(可以作用域不同类的对象)*/
	cout << student << endl << obj << endl;
	/*重载之后的成员函数"<"的效果(只能够够作用域同类对象之间;即只能够比较同一个模板类下实例化下出对象)*/
	cout << "输出键(key)最小的那个元组" << endl << (student < student_2 ? student : student_2) << endl;


	return 0;
}

/*
将函数模板operator<<声明为Pair类模板的友元。

编译本程序时﹐编译器自动生成了两个operator<<函数，它们的原型分别如下
ostream & operator <<( ostream & o,const Pair<string,int> &p);
ostream & operator <<( ostream & o, const Pair<int, double> & p);

在Visual Studio中，这两行也可以用下面的写法替代:
friend ostream & operator <<T1,2>( ostream &o，const Pair<T1,12>& p);
但在 Dev C++中，替代后就编译不过了。



*/