//program 14.10.1.cpp ������͸�ֵ�����
#include <iostream>
using namespace std;
class CBase 
{
	int a;
	public:
		CBase(int a_=0) :a(a_)
		{
			cout << "constructor_of_CBase is called!" << endl;
			cout << "a=" << a << endl;
		}//defult_Args_constructor
		CBase(CBase& c)
		{
			cout << "CBase::copy constructor called" << endl;
		}
		/*overload_constructor;a=b(a,b����CBase���͵�ֵ)��Ч����Ϊ:a.operator=(b)*/
		CBase& operator=(const CBase& b)	//
		{
			cout << "CBase::opeartor= called" << endl;
			//*this = b;������CBase�Ķ���,�������·����������ص�"="
			this->a = b.a;
			return *this;
			
		}
};
class CDerived:public CBase 
{  

	/*�ڴ�֮ǰ,�Ѿ���CBase����̳й������еĳ�Ա.
	(����һ��CDerived����ȻҲ���ȵ��û���CBase�Ĺ��캯��.*/
	int b;
public:/*����ʽ����Ϊ���еĻ�,���޷�ʵ���������ʱ���޷���ʼ���������޲�/Ĭ�ϲ�����constructorҲ���У�*/
	CDerived(int a_=0,int b_ = 0) :b(b_),CBase(a_)
	{
		cout << "\tconstructor_of_CDerived is called!" << endl;
		cout << "\t\tb=" << b << endl;
	}

	CDerived(CDerived& objBeCopyed)//copy_constructor_of_CDerived(��������Ϊ����,���Ч��)
	{
		cout << "copy_constructor_of_CDerived is called!" << endl;
		/*��CDerived����"="û�б�����,��CBase����"="������;���ӻ���̳й�������Щ��Ա����������"="������ڻ���CBase�������к��"="(��operator=()����),���������ж��еĳ�Ա��������"="��ֻ����ͨ��"="����;(��Щ��ֵ�ڵ��Թ����л�ĬĬ��ִ�е�);
		���ǿ��Կ����Ĺ��̾������غ��"="��"����"����(����"="�����غ����ı�д���,δ���������ƹ���))*/
		*this = objBeCopyed;//��ʱ*this��CDerived���͵Ķ���,����CDerived�ǻ���CBase������������,�ڻ����ж�"="���������������,.(��Ҫ�����ڸ��ƹ��캯��)

		/*�������ж��еĳ�Ա��������"="��ֻ����ͨ��"="����;(��Щ��ֵ�ڵ��Թ����л�ĬĬ��ִ�е�);*/
	}

};
int main()  
{  		
	CDerived 
		d1(1,1),
		d2(2,2);
	d2 = d1;  //��CDerived����"="û�б�����,��CBase����"="������;���ӻ���̳й�������Щ��Ա����������"="������ڻ���CBase�������к��"="(��operator=()����),���������ж��еĳ�Ա��������"="��ֻ����ͨ��"="����;(��Щ��ֵ�ڵ��Թ����л�ĬĬ��ִ�е�)


	/*��һ���������ƹ��캯�������:��һ������ȥ��ʼ����һ������.;(�����ڶ��Զ���Ϊ�����ĺ����ĵ��õ����)*/
	CDerived d3(d2); /*d3��ʼ�������л����CBase�ิ�ƹ��캯��;
					 �ȵ��û����еĹ��캯�����ӻ����м̳й������ǲ��ֳ�Ա���г�ʼ��
					 
					 ���ǿ��Կ����Ĺ��̾������غ��"="��"����"����(����"="�����غ����ı�д���,δ���������ƹ���));�������ж��еĳ�Ա��������"="��ֻ����ͨ��"="����;(��Щ��ֵ�ڵ��Թ����л�ĬĬ��ִ�е�);*/
	
	return 0;
}
/*�����Ҫ����һ����ʱCDerived�����:
����һ����ʱ��������Ҫ���ù��캯�����г�ʼ��,����CDerived��һ��CBase��������,�ȵ��û����еĹ��캯�����ӻ����м̳й������ǲ��ֳ�Ա���г�ʼ��*/
