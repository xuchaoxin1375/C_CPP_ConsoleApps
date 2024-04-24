//program 16.3.1.cpp 流操纵算子
#include <iostream>
#include <iomanip>/*流算子在iomanip中被定义*/
using namespace std;
int main()
{
    int n = 141;
	//1) 分别以十六进制、十进制、八进制先后输出 n  
   cout << "1) " << hex << n << " " 
	   << dec << n << " " 
	   << oct << n << endl;


	double x = 1234567.89,y = 12.34567;
	//2) 保留5位有效数字 setprecision(5)位数较多,则可能将之表示为科学计数法(e之前有5位)
	/*precision英 [prɪˈsɪʒn]n. 精度，[数] 精密度；精确adj. 精密的，精确的*/
	cout << "2) " << setprecision(5) << x << " " 
		<< y << " " << endl;
	//3) 保留小数点后面5位;
	cout << "3) " << fixed << setprecision(5) <<  x << " " 
		<< y << endl ;
	//4) 科学计数法输出，且保留小数点后面5位 
	cout << "4) " << scientific << setprecision(5) <<  x << " " 
		<< y << endl ;

	//5) 非负数要显示正号showpos:即show_positive_sign，输出宽度为12字符，宽度不足则用'*'填补 
	cout << "5) " << showpos << fixed << setw(12) << setfill('*') << 12.1 << endl;
	//6) 非负数不显示正号，输出宽度为12字符，宽度不足则右边用填充字符填充 
	cout << "6) " << noshowpos << setw(12) << left << 12.1 << endl;

	//7) 输出宽度为12字符，宽度不足则左边用填充字符填充 
	cout << "7) " << setw(12) << right << 12.1 << endl;
	//8) 宽度不足时，负号和数值分列左右，中间用填充字符填充 
	cout << "8) " << setw(12) << internal << -12.1 << endl;
	cout << "9) " << 12.1 << endl;
 	return 0;
}
/*
1) 8d 141 215
2) 1.2346e+06 12.346
3) 1234567.89000 12.34567  保留小数点后面5位
4) 1.23457e+06 1.23457e+01
5) ***+12.10000
6) 12.10000****
7) ****12.10000
8) -***12.10000
9) 12.10000
*/
/*
* 
*dec
以十进制形式输出整数
hex
以十六进制形式输出整数
oct
以八进制形式输出整数
fixed
以普通小数形式输出浮点数
scientific
以科学计数法形式输出浮点数
left
左对齐即在宽度不足时将填充字符添加到右边
* right
右对齐，即在宽度不足时将填充字符添加到左边
setbase( b)
设置输出整数时的进制，b= 8、10或16
setw( w)//一次性
指定输出宽度为w个字符或输人字符串时读人w个字符
在指定输出宽度的情况下,输出的宽度不足时用字符c填充(默认的情况是用空

setfill(c)//设置一次,能够影响后续
在指定输出宽度的情况下，输出的宽度不足时用字符c填充（默认的情况是用空格填充）

setprecision(n)//设置一次,能够影响后续
设置输出浮点数的精度为n。在非fixed且非scientific 方式输出的情况下,意味
着最多保留n位有效数字
如果有效数字位数超过n,则小数部分四舍五入或自动变为科学计数法输出并保留-共n位有效数字:
在fixed方式和scientific 方式输出的情况下n是小数点后面应保留的位数

setiosflags(标志)
将某个输出格式标志置为1
resetiosflags(标志)
将某个输出格式标志置为0
*/