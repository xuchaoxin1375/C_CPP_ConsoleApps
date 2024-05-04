//program 13.5.1.cpp  可变长动态数组类
/*
（1）数组的元素个数可以在初始化该对象的时候指定。
（2）可以动态往数组中添加元素。
（3）使用该类的时候不用操心动态内存分配、释放问题
（4）能够像使用数组那样来使用动态数组类对象，如可以通过下标来访问其元素。*/
#include <iostream>
#include <cstring>
using namespace std;
/*//class CArray可变长动态数组类,数组中保存整形数*/
class  CArray
{
     int size; //数组元素的个数
     int *ptr; //指向动态分配的数组
public:
   CArray(int s = 0);     //s代表数组元素的个数
	CArray(CArray & a);//copy_constructor
	~CArray();//destructor

	void push_back(int v); //用于在数组尾部添加一个元素v

	CArray & operator=( const CArray & a); //用于数组对象间的赋值

	int length() { return size; } //返回数组元素个数

	/*重载[]运算符:(是定义在类当中的做为成员函数的),可以直接访问类的(私有)成员变量(指针变量ptr)*/
	int & operator[](int i) /*返回引用类型,使之能够作为左值.(作右值的话int和int & 都可以.)*/
	{//用以支持根据下标访问数组元素，如a[i] = 4;和n = a[i]这样的语句
		return ptr[i]; 
	} 
};//class CArray可变长动态数组类.
/*析构函数
initial_constructor:申请s块int型内存*/
CArray::CArray(int s):size(s) //参数默认值在定义或者声明出有一处说明即可,不要两处都说明默认值.
{ 
 	if( s == 0)
	 	ptr = NULL;
	else	   
		ptr = new int[s]; 
}  //CArray(int s){}
/*copy_constructor*/
CArray::CArray(CArray & a)
{
	if( !a.ptr) {//如果a.ptr为空
		ptr = NULL;
		size = 0;
		return;
	}
	ptr = new int[a.size];
	memcpy( ptr, a.ptr, sizeof(int ) * a.size);
	size = a.size;
}//copy_constructor(CArray &){}
/*destructor*/
CArray::~CArray() 
{
	/*如果当前的对象中的ptr非NULL(空),才进行释放操作*/
 		if( ptr) delete [] ptr;
} //~CArray(){}
/*overload_operator_of_=*/
CArray & CArray::operator=( const CArray & a)
{ //此重载 赋值号的作用是 使"="左边对象里存放的数组，大小和内容都和右边的对象一样
	/*在复制前,需要执行一些判断(一定)和旧内存清理(如果要的话)*/
	if (ptr == a.ptr) //防止a=a这样的赋值导致出错(ptr是第一个操作数,a.ptr是第二个操作数)
	{
		return *this;
	}
   /*如果a里面的数组是空的*/
   if( a.ptr == NULL) {  
	   if (ptr)
	   {
		   delete[] ptr;
	   }
		ptr = NULL;
		size = 0;

		return * this;
	}
   /*原有空间小于要求的大小,再做分配.*/
 	if( size < a.size) { //如果原有空间够大，就不用分配新的空间
		/*在分配新空间前,一般都需要检查就有空间是否为空(NULL),若是,及时释放掉*/
		if (ptr)
		{
			delete[] ptr;
		}
		/*然后分配新空间*/
        ptr = new int[a.size];
	}
	/*使"="左边对象里存放的数组，大小和内容都和右边的对象一样*/
	memcpy( ptr,a.ptr,sizeof(int)*a.size);	/*用memcpy()代替strcpy()*/
	size = a.size;
 	return * this;
}
/*在数组尾部添加一个元素*/
void CArray::push_back(int v)
{  
	if (ptr) {
		int* tmpPtr = new int[size + 1]; //重新分配空间;不过每次只增大一格(size还没有变化,以便memcpy() )
		memcpy(tmpPtr, ptr, sizeof(int) * size); //memcpy()函数拷贝原数组内容;原来的数组中有size个元素
		delete[] ptr; /*及时释放掉旧数组的空间.*/
		ptr = tmpPtr; /*指向新数组的内存空间*/
	}
	else  //数组本来是空的
	{
		ptr = new int[1];
	};

	ptr[size++] = v; //加入新的数组元素;由于字符是一个个追加到数组尾部的,故size++即可;
}//在数组尾部添加一个元素


int main()
{
   CArray a; //开始里的数组是空的
   /*将1,2,3,4,5依次插入数组类对象a中的数组成员的尾部.*/
   for (int i = 0; i < 5; )
   {
	   a.push_back(i);
	   i++;
   }

   CArray a2,a3;
   /*将a的内容深复制到a2中:*/
   a2 = a;
   /*打印复制的结果:*/
   for (int i = 0; i < a.length(); ++i)
   {
	   cout << a2[i] << " ";
   }
   a2 = a3; //a2又变成是空的
   
   for (int i = 0; i < a2.length(); ++i) //a2.length()返回0
   {
	   cout << a2[i] << " ";
   }
   cout << endl;/*单纯打印换行.*/
   a[3] = 100;/*重载后的[]函数中,虽然return的表达式是ptr(为int*类型),但返回值类型被定义为引用类型int& 故也可以作为左值*/
   CArray a4(a);	
   for (int i = 0; i < a4.length(); ++i)
   {
	   cout << a4[i] << " ";
   }
   return 0;
}
/*
[]是双目运算符6两个操作数，一个在里面，一个在外面。
表达式“a[i]”等价于“a.operator[]（i）”.
按照“[]”原有的特性，“a[i]”是应该能够作为左值使用的，所以.
"operator”[] 这个函数应该返回引用类型.
*/