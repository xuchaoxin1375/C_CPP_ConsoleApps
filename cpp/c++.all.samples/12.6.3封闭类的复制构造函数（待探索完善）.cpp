//program 12.6.3.cpp  �����ĸ��ƹ��캯��
#include <iostream>
using namespace std;
class A
{
public:
	int x = 0;
public:
	/*constructor*/
	A() {
		x = 10;
		cout << "default constructor_A" << endl;
	}
	/*copy_constructor*/
	A(A& a) { 
		/*�Լ���д���ƹ��캯��,�������͸�����ص���,������ܳ����βκ�ʵ�β��ȵ����.*/
		/*��ȷ��ֵ����ֵ:*/
		x = a.x;
		cout << "copy_constructor_of_A_class(defined by me)" << endl;
	}
};
/*�����B*/
class B
{
	/*Ϊ���ڱȽ�,���趨�������ͱ���*/
	int p;
		A a;/*��ָ�����÷�Χ,Ĭ����private*/
		

public:/*��Ա�����������,���³���;:����tmp����  �����privateҲ�����;.*/
		/*B���Ĭ�Ϲ��캯��:*/
		B() {
			/*���뺯����ǰ���ȵ���A()*/
			a.x = 100;
			cout << "default constructor_B" << endl;
		}
		/*B��ĸ��ƹ��캯��:*/
		//B(B& b_)
		//{
		//	a = b_.a;/*ͬ�����֮������ֵ��������Ҫ���Ʋ�����������ݣ���һ����Ա�Ĳ��渳ֵ���ɣ����������Ա����ĳ�Ա�︳ֵ*/
		//	cout << "copy_constructor_of_B_class(defined by me)" << endl;
		//}
};
int main()
{
		B b1,/*��һ������b1*/
			b2(b1);/*�ڶ���������b1��������ʼ��,������B�ĸ��ƹ��캯��.*/
		return 0;
}
/*˵��b2.a������A�ĸ��ƹ��캯����ʼ���ģ����ҵ��ø��ƹ��캯��ʱ��ʵ�ξ���
b1.a��
�Լ���д���ƹ��캯����Ҫע��:
	�������ɵ��¶����еĳ�Ա�����ͳ�Ա����Ӧ�õõ���ֵ!*/