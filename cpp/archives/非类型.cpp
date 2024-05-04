#include<iostream>
using namespace std;

template<class T,int size>
class test
{
	T array[size];
public:
	test() {
		cout << "constructor was called!" << endl;
	}
	T* getArray()
	{
		return array;
	}
	void print()
	{
		cout << "array:" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}
};
int main()
{
	/*对类模板进行实例化:test<float,40>,得到模板类(名):test<float,40>*/
	test<float,3> n;
	float k = 1.11;
	for (int i = 0; i < 3; i++)
	{
		n.getArray()[i] = k * i;
	}
	n.print();

}