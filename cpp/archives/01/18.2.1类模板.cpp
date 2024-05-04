//program 18.2.1.cpp Pair类模板
/* 
类模板看上去很像-一个类。下面以Pair类模板为例来说明类模板的写法和用法。
实践中常常会碰到,某项数据记录由两部分组成,一部分是关键字key,另一部分是值value。
(关键字用来对记录进行排序和检索,根据关键字能查到值。)
例如本例子，学生Student记录由两部分组成,
一部分是学号(作为key),另一部分是绩点(作为value)。即学号就是关键字，绩点就是值。
要能根据学号对学生进行排序，以便根据学号能方便地检索到绩点,
每个学生的信息可以用元组(key,value)来表示;用Pair代表这样的元组(泛型);
下面的Pair类模板(实例化出一个具体的模板类Pair<String,int> ;再用这个模板类去定义一定数量的该类型的对象Student
就可用来处理这样的数据记录:

 */
#include <iostream>
#include <string>
using namespace std;

template <class T1,class T2>
class Pair/*模板类和普通类相比,在定义的时候,多了牵头的 模板类型的声明:template<>*/
{
public:
	T1 key;  //关键字
	T2 value;  //值
	Pair(T1 k,T2 v):key(k),value(v) { };
	/* 在类模板中重载"<"号运算符,而且是常量成员函数,不会(也不允许)更改对象的成员 */
	bool operator < ( const Pair<T1,T2> & p) const; 
};
/* 类模板中的成员函数,在类模板定义 外面 编写函数体时的语法:(分为两部分:
template<类型参数表>
返回值类型 类模板名<类型参数名列表> ::成员函数名(参数表)//其实就中间的 <类型参数名列表>这一部分在形式和普通成员函数定义时有所增加;然后就是头顶有相应的template<类型参数表>(毕竟是泛型,模板类型) */
//Pair的成员函数 operator <
template<class T1,class T2>//生明模板类型
bool Pair<T1,T2> ::operator < ( const Pair<T1,T2> & p) const/* 这里的参数类型是const Pair<T1,T2> &;由于这个函数是属于类模板的"成员函数",形参参数对象的类型自然就是泛型类模板名,在实例化类模板的时候,Pair<T1,T2>就会被替换为具体的类名(模板类名);比如Pair<String,int>是一个整体名字(类模板名以及其后所跟着的参数类型表))  */
{ //"小"的意思就是关键字小
	return value < p.value;//对对象的键值进行比较
}

int main()
{
	//实例化出一个类 Pair<string,int>
 	Pair<string,int>/* 类模板名<真实类型参数表>;其实也就<真实类型参数表>与之前的定义对象的形式上有所增加(这么一个<真实类型参数表>) */
	  student1/* 对象名 */
	  ("Tom",19);/* 含参构造函数实际参数表 ;如果类模板有无参构造函数,那么按需求可以没有(构造函数的)实际参数表*/

	  Pair<string,int>   student2("jack",17);

	   
 	//cout << student1.key << " " << student1.value; 
	 cout<<"student1<student2="<<(student1<student2)<<endl;
 	return 0;
}

/* 
实例化-一个类模板的时候，真实类型参数表中的参数  是  具体的类型名，如string、int或其他类的名字(如CStudent等),
它们用来一一对应地替换类模板定义中“类型参数表"里面的类型参数。
“类模板名<真实类型参数表>”就成为一个具体的类的名字。编译器会用“string”替换Pair模板中的T1,用int替换T2,其余部分原样照抄,
这样就自动生成了一个新的类，这个类的名字可以认为就是“Pair<string,int>”,
也可以说,student对象的类型就是Pair<string,int>
Pair < string,int>类的成员函数自然也是通过替换Pair 模板的成员函数中的T1,T2 :
得到的。

编译器由类模板生成类的过程,称为类模板的实例化。由类模板实例化得到的类,称为
模板类。]

 */