//program 18.5.1.cpp �������ࡢ��ĳ�Ա������Ϊ ��ģ�����Ԫ
#include<iostream>
using namespace std;

template <class T>
class Tmpl;

/*ȫ�ֺ���ģ��:Func1()*/
template <class T>
void Func1(Tmpl<T> &x)
{
	
	cout << "this is a global function :Func1()" << endl<<"\t";
	x.print();

}
/*ģ����B*/
template <class T>
class B
{
public:
	void Func(Tmpl<T>& x);
};
/*��ģ��Tmpl*/
template <class T>
class Tmpl 
{
	T a;
public:
   friend void Func1();//ȫ����Ԫ����
   friend class A;//��Ԫ��A

   template<class T>
   friend void B<T>::Func(Tmpl<T>&);//��B�ĳ�Ա������Ϊ ��ģ��Tmpl����Ԫ;
   Tmpl(T a_=0):a(a_)//���캯��
   {
	   cout << "the Tmpl<T>::constructor was called!" << endl;
   }
   void print()
   {
	   cout << "a=" << a << endl;
   }
};

class A
{
	Tmpl<double> obj_in_A;
public:
	void printA()
	{
		cout << "this is a function of class A" << endl;
		
	}
	A(double a_):obj_in_A(a_)
	{
		//obj_in_A.a = a_;
		cout << "����Ԫ��A(��ͨ��A)�з���Tmpl<T>��˽�г�Աa:" <<endl;
		cout << "a=" << obj_in_A.a << endl;
	}
};

template<class T>//������
void B<T>:: Func(Tmpl<T>& x)
{
	cout << "this is a function of class B:" << endl;
	cout << "����Ԫ����(��ģ��B<T>�ĺ���Func(Tmpl<T>& x))�з���Tmpl<T>��˽�г�Աa:" << endl;
	cout << "x.a=" << x.a<< endl;
}

int main()
{
 	Tmpl<int> i(7); 
	i.print();
	Func1(i);//ȫ����Ԫ����

	Tmpl<double> f(7.889);
	f.print();

	A obj1(3.14);//��A����Tmpl<double>��ĳ�Ա����,���ȵ���Tmpl<double>�Ĺ��캯��.
	B<double> obj2;
	obj2.Func(f);

	B<int> obj3;
	obj3.Func(i);

}
