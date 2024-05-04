//program 18.6.1.cpp ��ģ���еľ�̬��Ա
#include <iostream>
using namespace std;

template <class T>
class A
{
 private:
	static int count;//��̬��Ա����count
public:
 	A() { 
		cout << "A::constructor was called!" << endl;
		count ++;  }
	~A() { count -- ; };

	A( A & ) { count ++ ; }	//copy_constructor
	/*static member function:only can visit the static variable !
	there,it can visit the static variable :count */
	static void PrintCount() { cout << "count="<<count << endl; }
};
/*�� ��̬��Ա���� �����ⲿ�����������Ǳ����:
���ⲿ����ģ��A�ֱ�ʵ����ΪA<int>,A<double> ���ֱ����еľ�̬��Ա����count(ȫ�ֱ���)��ֵΪ0;�����������ȿ�ʼִ�е����*/
//template<class T> int A<int>::count = 0;//A<int> ������ģ��;
template<> int A<int>::count = 0;
template<> int A<double>::count = 10;
/*
vs��,���Լ�д��:
 int A<int>::count = 0;
 int A<double>::count = 10;
*/
int main()
{
 	A<int> ia;
	cout << "ia:";
	ia.PrintCount();
	
 	A<double> da;

	cout << "ia:";
 	ia.PrintCount();
	cout << "da:";
 	da.PrintCount();
	return 0;
}

