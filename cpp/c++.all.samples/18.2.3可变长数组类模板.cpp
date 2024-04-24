//program 18.2.3.cpp  可变长数组类模板
#include <iostream>
#include <cstring>
using namespace std;
/*类模板CArray*/
template <class T>//T可以被实例化为int/double/float;
class  CArray
{
//public:
	int size; //数组元素的个数
     T * ptr; //指向动态分配的数组
public:
	/*普通成员函数声明*/
		/*构建连个构造函数(重载构造函数)*/
   CArray(int s = 0);  //s代表数组元素的个数
	CArray(CArray & a);
	~CArray();//析构函数
	/*成员函数模板声明*/
	void push_back(const T & v); //用于在数组尾部添加一个元素v
	/*CArray也是模板类型*/
	CArray & operator=( const CArray & a); //用于数组对象间的赋值
	/*内联成员函数(模板中的声明不需要写模板名CArray<T>)*/
	int length() { return size; } 
		/*成员函数模板(返回类型是模板类型T)*/
	T & operator[](int i) //重载"[]"
	{//用以支持根据下标访问数组元素，如a[i] = 4;和n = a[i]这样的语句
		return ptr[i]; 
	} 
	
	void print() /*const*/ //非成员函数上不允许使用类型限定符(此处指const)
	{
		cout << "数组里的元素如下:" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << ptr[i] << " ";
		}
		cout << endl;
	}
	/*声明全局函数模板为友元*/
	template<class T>
	friend void print(const CArray<T>& x) /*const*/;
	
};//类模板CArray<T>结束;


/*打印函数(全局);全局函数并不是通过对象来调用的.而是通过将对象作为参数传给全局函数*/
template<class T>//必不可少
void print(const CArray<T>& x)
{
	cout << "test_global" << endl;
	cout << "数组里的元素如下:" << endl;
	for (int i = 0; i < x.size; i++)
	{
		cout << x.ptr[i] << " ";
	}
	cout << endl;
}
/*constructor_1:为数组类对象申请指定大小s的数组的空间*/
template<class T>
CArray<T>::CArray(int s):size(s) //零size=s;//在类中的声明中已经指定了s的默认值为0;在外部定义的时候没有(也无须也不可以在指定一次默认值了)
{ 
 	if( s == 0)
	 	ptr = NULL;
	else	   
		ptr = new T[s]; 
}  
/*copy_constructor_2:分析传入的对象里的数组是否为空*/
template<class T>
CArray<T>::CArray(CArray & a)/*用另一个CArray对象a来初始当前对象*/
{
	if( !a.ptr) {//如果为空
		ptr = NULL;//将指向动态数组的指针置为NULL
		size = 0;//长度置为0;
		return;
	}
	/*然后再执行:*/
	ptr = new T[a.size];
	memcpy( ptr, a.ptr, sizeof(T ) * a.size);
	size = a.size;
}
/*destructor*/
template <class T>
CArray<T>::~CArray() 
{
	if (ptr) 
	{
		delete[] ptr;
	}
} 

/*overload_operator_=(返回类型为CArray<T>& (引用)*/
template <class T>
CArray<T> &     CArray<T>::operator=( const CArray & a)
{ //赋值号的作用是  使"="左边对象里存放的数组，大小和内容 都和右边的对象一样
	if (ptr == a.ptr) //防止a=a这样的赋值导致出错
	{
		return *this;
	}
   /*源数组是空的话,不用复制了,但是还是需要为目标数组LHS设置一个值:NULL使得目标数组的值(和复制源数组RHS一样为空(NULL)*/
   if( a.ptr == NULL) 
   {  //如果a里面的数组是空的
	   if (ptr)
	   {
		   delete[] ptr;
	   }
	   /*置为NULL,同时,数组类CArray中还包含数组长度的信息(xin'xi)*/
		ptr = NULL;
		size = 0;
		return * this;//返回值为当前这个对象
	}
 	if( size < a.size) { //如果原有空间够大，就不用分配新的空间
		if (ptr)
		{
			delete[] ptr;
		}
        ptr = new T[a.size];
	}
	memcpy( ptr,a.ptr,sizeof(T)*a.size);	
	size = a.size;
 	return * this;
}
/*//在数组尾部添加一个(T类型的)元素,同时(每压入一个元素,便要更新一下数组长度值size)*/
template <class T>
void CArray<T>::push_back(const T & v)
{  
   if( ptr) { 
   	   T * tmpPtr = new T[size+1]; //重新分配空间
   	   memcpy(tmpPtr,ptr,sizeof(T)*size); //拷贝原数组内容
	   /*记得删除旧空间,以免成为内存垃圾*/
   	   delete [] ptr; 
   	   ptr = tmpPtr; 
   }
   else  //数组本来是空的
   {
	   ptr = new T[1];
   }
	ptr[size++] = v; //加入新的数组元素(同时通过size++更新了数组长度信息)
}

/*CArray类模板提供了两种"复制"数组的途径:
1.在初始化的时候调用(带参,且参数是本类的引用)的复制构造函数构造函数
2.第二种途径是使用重载的"="运算符,实现"复制"(这种方式更自由)
*/

//
int main()
{
   CArray<int> a;//定义一个CArray可变长数组类对象a;
   for (int i = 0; i < 3; ++i)//为数组a填充3个值
   {
	   a.push_back(i);//数组类型一旦确定,里面存储的数据的类型就固定下来了(尽管数组长度可以变化,元素的类型是不可以变的)
   }
   /*测试当类模板实例化为浮点类型是的效果:*/
   CArray<float> b,e;
   float k = 2.121;
   for (int i = 0; i < 4; ++i)
   {
	   b.push_back(k+=1);
   }
   /*测试两种复制方式的效果:*/
   CArray<int> 
	   c(a),/*测试复制构造函数*/
	   d=a;/*测试重载"="*/
   e = b;
   /*测试重载的"[]"运算符的随机访问效果
   cout << "a[2]=" << a[2] << endl;
   cout << "b[1]=" << b[1] << endl;*/
   /*成员函数pirnt()的效果:*/
   a.print();
   b.print();
   c.print();
   d.print();
   e.print();
   /*全局友元函数模板实例化后的效果*/
   print(a);
   print(b);
   print(c);
   print(d);
   /*打印数组中的各个元素
   for (int i = 0; i < a.length(); ++i)//数组长度:a.length()
   {
	   cout << a[i] << " ";
   }*/
   return 0;
}
