//program 18.1.2.cpp  求数组最大元素的MaxElement函数模板 
#include <iostream>
using namespace std;
/*类型参数 T;
从MaxElement模板的写法可以看出，
在函数模板中，类型参数不但可以用来  定义参数的类型，
还能用于  定义  局部变量和函数模板的  返回值的类型。
*/
template <class T>
T MaxElement(T a[],/*类型T的数组(名)*/
	int size) //size是数组元素个数(整形)
{
	T tmpMax = a[0];
	for( int i = 1;i < size;++i)
	{
		if (tmpMax < a[i])
		{
			tmpMax = a[i];
		}
	}
	return tmpMax;
}
class CFraction //分数类
{
	/* 分子分母都为整形数 */
	int numerator;   //分子;numerator英 [ˈnjuːməreɪtə(r)]美 [ˈnuːməreɪtər]n. 分子；计算者；计算器
	int denominator; //分母;denominator 美: [dɪ'nɑmɪ.neɪtər] 英: [dɪ'nɒmɪ.neɪtə(r)] n. 分母
public:
	CFraction(int n,int d):numerator(n),denominator(d) { };
	/*比大小的算法:利用作差法,分数(n1/d1-n2/d2 = (n1d2-n2d1)/(d1d2))和0比较,如果差值>0(则等价于说明n1/d1 > n2/d2;若判断得到d1d2>0;则又等价于n1d2>n2d1);...
	这里重载的是"<"号,实现的功能是要输入两个分数(对象)若LHS<RHS,则返回1,否则返回0(返回值定义为bool类型的值);
	这样,当外部对两个CFraction类型的对象做"<"运算的时候,就会调用该运算符重载函数了*/
	bool operator <( const CFraction & f) const/*常量成员函数/重载了<关系运算符;第一个操作对象是当前调用这个函数的对象,第二个对象通过参数传入*/
	{//为避免除法产生的浮点误差，用乘法判断两个分数的大小关系:比如a/b
		if( denominator * f.denominator > 0 ) //如果两个分数对象的分母同号;
			return numerator * f.denominator < denominator * f.numerator ;//返回是/否
		else
			return numerator * f.denominator > denominator * f.numerator ;
	}
	bool operator == ( const CFraction & f) const/* 重载关系运算符"==" */
	{//为避免除法产生的浮点误差，用乘法判断两个分数是否相等(算法:等价于判断表达式:n1d2==n2d1是否为真
		return numerator * f.denominator == denominator * f.numerator;
	}

	/*重载 << 使得分数对象可以通过cout输出 */
	friend ostream & operator <<( ostream & o,const CFraction & f);
};
/*重载输出<<符注意第一个参数形参和实参都是固定的,第二个参数才是我们做文章的地方;通过修改第二个参数的类型,并编写相应的函数体,扩充<<的RHS表达式的类型范围.*/
ostream & operator <<(ostream & o,const CFraction & f)//<==> cout.operator<<(f); f是CFraction;第一参数o总是用cout作为实参
{//重载 << 使得分数对象可以通过cout输出
	o << f.numerator << "/" << f.denominator; //输出"分子/分母" 形式
	return o;
}
int main()
{
	int a[5] = { 1,5,2,3,4 };
	CFraction f[4] = { CFraction(8,6),CFraction(-8,4),
                       CFraction(3,2), CFraction( 5,6)};

	cout << MaxElement(a,5) << endl;//函数模板MaxElement(T a[])
	/*重点是下面的分数比大小(找到并按形式打印分数对象数组f中的最大者)*/
	cout << MaxElement(f,4) << endl;
	return 0;
}

