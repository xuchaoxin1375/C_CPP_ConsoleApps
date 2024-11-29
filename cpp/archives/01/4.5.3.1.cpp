/* 
引用传参
返回引用的函数调用可以作为左值
 */
#include <iostream>
#include "4.5.3.1.h"
using namespace std;
int n = 10;
void Swap_inner(int a, int b)
{
	int tmp;
	// 以下三行将a,b值互换
	tmp = a;
	a = b;
	b = tmp;
	cout << "In Swap: a=" << a << " b=" << b << endl;
}
void Swap_ref(int &a, int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
void Swap_ptr(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
int &GetValueRef()
{
	return n;
}
int GetValue()
{
	return n;
}

void test_ref_leftvalue()
{
    GetValueRef() = 1;
    int &r = GetValueRef();
    cout << r << endl;
}

void test_param_swap(int &a, int &b)
{
	cout << "Before swaping: a=" << a << " b=" << b << endl;
	// Swap_inner(a, b);
	// Swap_ref(a, b);
	Swap_ptr(&a, &b);
	cout << "After swaping: a=" << a << " b=" << b;
}

int main()
{
	int a = 4, b = 5;
	// test_param_swap(a, b);
	// GetValue()=1;
    test_ref_leftvalue();
    return 0;
}