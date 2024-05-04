//program 12.1.2.1.cpp  构造函数和数组
#include <iostream>
using namespace std;
class CSample {
public: 	
	CSample() { //构造函数1(默认构造函数)
		cout << "Constructor 1 Called" << endl;
  	}
	CSample(int n ) { //构造函数2
		cout << "Constructor 2 Called" << endl;
  	}
};
int main(){
	CSample array1[2];
	cout << "step1"<<endl;
	CSample array2[2] = {4,5};
	cout << "step2"<<endl;
	
	cout << "step3"<<endl;
	CSample * array4 = new CSample[2];//调用自定义的无参构造函数.这里采用了new 类型名[数组大小表达式]的方式动态的申请一块内存,返回的地址由该类型的指针变量来接受,这个指针变量相当于申请来的数组的名字
    delete [] array4;/*在释放数组内存时,采用delete [] 数组名(动态new返回的指针*/

	CSample array3[2] = {3};//在单步(逐语句)调试array3[1]时,会试图进入编译器内部的默认结构函数来初始化,一般无法进入,而用逐过程调试可以跳过进入编译器创建的构造函数.
	return 0;
}

