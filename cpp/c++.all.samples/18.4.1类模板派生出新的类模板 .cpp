//program 18.4.1.cpp ��ģ�����ģ������
/*��ģ��A<T1,T2>*/
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
    void setA(T1 a,T2 b)
    {
        v1 = a;
        v2 = b;
    }
};

/*��ģ��B����ģ��A<T2,T1>��������;B<T01,T02>�ڼ̳�A<T1,T2>��ʱ��Ὣģ��A<T1,T2>ʵ����ΪA<T02,T01>;����,ʵ����B<T01,T02>ʱ��һͬ�پ���ʵ����A<T02,T01>*/
template <class T01,class T02>
class B:public A<T02,T01>  //����A<T02,T01>,����Ĳ���ȡ��B<T01,T02>��ģ������;T01,T02˳��Ե�������в���;���������ʵ����A<T02,T01>,����B��ģ�����޷����̷��ʵ�A�ĳ�Ա;
{
    /*�Ƚ�A<T02,T01>��ĳ�Ա�̳е��˴�*/
protected:
   T01 v3;
   T02 v4;
public:
    B(T02 v1_ = 0, T01 v2_ = 0,T01 v3_ = 0,T02 v4_ =0) :A<T02,T01>(v1_,v2_),v3(v3_),v4(v4_)
    {
        cout << "B::constructor was called !" << endl;
    }
    /*�ȵ���A<T02,T01>�е�print*/
    // A<T02,T01>::
   void print()
   {
      /* 
       cout << "v1=" << v1 << " ";
       cout << "v2=" << v2 << " ";*/
       cout << "v3=" << v3 << " ";
       cout << "v4=" << v4 << " ";
       cout << endl;
   }
   void setB(T01 m, T02 n)
   {
       v3 = m; v4 = n;
   }
};

/*testing:
cout << "v1=" << v1 << " ";B��Ļ���A<T1,T2>��ָ����ģ������֮��(��ʵ����Ϊ����ĺ���ģ��֮���ǿ��Ա���ͨ����;
*/
//template <class T01, class T02>
//class B :public A<double,int>  //����A<T02,T01>,����Ĳ���ȡ��B<T01,T02>��ģ������;T01,T02˳��Ե�������в���
//{
//    /*�Ƚ�A<T02,T01>��ĳ�Ա�̳е��˴�*/
//protected:
//    T01 v3;
//    T02 v4;
//public:
//    B(double v1_ = 0, int v2_ = 0, T01 v3_ = 0, T02 v4_ = 0) :A<double, int>(v1_, v2_), v3(v3_), v4(v4_)
//    {
//        cout << "B::constructor was called !" << endl;
//    }
//    /*�ȵ���A<T02,T01>�е�print*/
//    // A<T02,T01>::
//    void print()
//    {
//        /**/
//         cout << "v1=" << v1 << " ";
//         cout << "v2=" << v2 << " ";
//        cout << "v3=" << v3 << " ";
//        cout << "v4=" << v4 << " ";
//        cout << endl;
//    }
//    void setB(T01 m, T02 n)
//    {
//        v3 = m; v4 = n;
//    }
//};

template <class T>
class C:public B<T,T>//ֱ�ӻ�����Ҫ��������ģ�����Ͳ���;
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
 	B<int,double> /*Ϊ��ģ��B<T1,T2>ʵ����Ϊģ����B<int,double>*/

        obj1(5.67,4 ,9,7.9); /*ʵ����һ��B<int,double>���͵ı���obj1;ǰ��λ�ǳ�ʼ��v1,v2*/
    obj1.A<double, int>::print();obj1.print();//����ֻдA

    //obj1.A<T02, T01>::print;//�޶���A<T02, T01>::����B<int,double>�������ĳ�Ա
   // obj1.A<int,double >::print();//����A<>�е�int,double��˳��Ҳ�ǲ��е�:����B<int,double>�������ĳ�Ա
    
    /*
    * B<int,double> ����ģ��B<T1,T2>ʵ����Ϊģ����B<int,double>��Ч��:
    class B<int, double> : public A<double, int>
    {

	    int v3; double v4;
    };
    B<int,double>�Ļ�����A<double,int>;
    A<double,int>���滻Ч��:
    class A <double,int>
    {
        double v1;
        int v2;
    }
*/
    cout << "atfter set:" << endl;
    obj1.setA(4.5, 7);
    obj1.setB(90, 7.234);
    obj1.A<double, int>::print(); obj1.print();

	C<int> obj2(9,7,8,9,10);//���Ͷ���int,��ֵ��һ��һ��;
    /* �ڶ���class B:public A<T02,T01> ʱA<T02,T01>Ҫ������ʵ����Ϊ����,�����������ſ���ִ��;*/
    obj2.A<int, int>::print();
    obj2.B<int, int>::print();

    obj2.print();
 	return 0;
}

/*
* ���н��:
A::constructor was called !
B::constructor was called !
v1=5.67 v2=4 v3=9 v4=7.9
atfter set
v1=4.5 v2=7 v3=90 v4=7.234
A::constructor was called !
B::constructor was called !
C::constructor was called !
v1=9 v2=7 v3=8 v4=9
v5=10
*/