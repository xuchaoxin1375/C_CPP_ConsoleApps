//program 18.4.1.cpp 类模板从类模板派生
/*类模板A<T1,T2>*/
#include<iostream>
using namespace std;
template <class T1,class T2>
class A 
{
protected:
   T1 v1; T2 v2;	
public:
    A(T1 v1_=0,T2 v2_=0):v1(v1_),v2(v2_)
    {
        cout << "A::constructor was called !" << endl;
    }
    void print()
    {
         cout << "v1=" << v1 << " ";
         cout << "v2=" << v2 << " ";
      
    }
};
//类模板B从类模板A<T2,T1>派生而来;
template <class T01,class T02>
class B:public A<T02,T01>  //对于A<T02,T01>,这里的参数取自B<T01,T02>的模板类型;T01,T02顺序对调与否是有差别的
{
    /*先将A<T02,T01>类的成员继承到此处*/
protected:
   T01 v3;
   T02 v4;
public:
    B(T02 v1_ = 0, T01 v2_ = 0,T01 v3_ = 0,T02 v4_ =0) :A<T02,T01>(v1_,v2_),v3(v3_),v4(v4_)
    {
        cout << "B::constructor was called !" << endl;
    }
    /*先调用A<T02,T01>中的print*/
    // A<T02,T01>::
   void print()
   {
      /* cout << "v1=" << v1 << " ";
       cout << "v2=" << v2 << " ";*/
       cout << "v3=" << v3 << " ";
       cout << "v4=" << v4 << " ";
       cout << endl;
   }
};

template <class T>
class C:public B<T,T>//直接基类需要传入两个模板类型参数;
{
   T v5;
public:
     C(T v1_,T v2_,T v3_,T v4_,T v5_):B<T,T>(v1_,v2_,v3_,v4_),v5(v5_)
    {
        cout << "C::constructor was called !" << endl;
    }
    void print()
    {
        cout << "v5=" << v5 << endl;
    }
    
};
int main()
{
 	B<int,double> /*为类模板B<T1,T2>实例化为模板类B<int,double>*/
        obj1(4,5.67,7.9,9); /*实例化一个B<int,double>类型的变量obj1;*/
    obj1.A<double, int>::print();
    //obj1.A<T02, T01>::print;//限定名A<T02, T01>::不是B<int,double>或其基类的成员
   // obj1.A<int,double >::print();//调换A<>中的int,double的顺序也是不行的:不是B<int,double>或其基类的成员
    obj1.print();
    /*
    * B<int,double> 将类模板B<T1,T2>实例化为模板类B<int,double>的效果:
    class B<int, double> : public A<double, int>
    {

	    int v3; double v4;
    };
    B<int,double>的基类是A<double,int>;
    A<double,int>的替换效果:
    class A <double,int>
    {
        double v1;
        int v2;
    }
*/
	C<int> obj2(9,7,8,9,10);//类型都是int,但值不一定一样;
    obj2.A<int, int>::print();
    obj2.B<int, int>::print();
    obj2.print();
 	return 0;
}

/*
* 运行结果:
A::constructor was called !
B::constructor was called !
v1=4 v2=5 v3=7 v4=9
A::constructor was called !
B::constructor was called !
C::constructor was called !
v1=9 v2=7 v3=8 v4=9
v5=10
*/