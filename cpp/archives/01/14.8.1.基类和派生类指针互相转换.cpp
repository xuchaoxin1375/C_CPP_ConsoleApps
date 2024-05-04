//program 14.8.1.cpp �����������ָ�뻥��ת��
#include <iostream>
using namespace std;
class CBase 
{
	protected:	
		int n;
	public:
		CBase(int i):n(i)  { } //constructor_CBase
		void Print() { cout << "CBase:n=" << n << endl; }
};
class CDerived:public CBase  
{
	public:
		int v;
		CDerived(int i):CBase(i),v(2 * i) { } //constructor_CDerived
		/*member_function_CDerived*/
		void Func() { } ;
		void Print() 
		{ 
			cout << "CDerived:n=" << n << endl;/*nΪ�����protected��Ա����*/
			cout << "CDerived:v=" << v << endl;
		}
};
int main()  
{  	
	/*Ϊ�������ͷֱ���һ������*/
	CDerived objDerived(3); //n=3;v = 6;
	CBase objBase(5);//n=3;

	CBase * pBase = & objDerived ; // ʹ�û���ָ��ָ�����������
	//pBase->Func(); //��, CBase��û��Func()��Ա����
	//pBase->v = 5;  //�� CBase��û��v��Ա����
	pBase->Print(); //��������������CBase * pBase,������������pBase�����ָ��CBase��(����)������������������Derived�����
	cout << "1)------------" <<endl;
	//CDerived * pDerived = & objBase; //�����ܽ�����ָ�븳ֵ��������ָ�� 
	CDerived * pDerived = (CDerived *)(& objBase); /*����ļ����Ա���������Ҫǿ;������(����ֵʱ)��ֻ�ܽ���������,��������ֵ�Ǽ��ܹ����ܻ���,Ҳ�ܹ�����������;���ʹ��ǿ������ת��,������ǿ��ת��������,�ӽ���Ͽ�,"�����Ӹ�ֵ��������"*/
	pDerived->Print();  //���ã����ܳ��ֲ���Ԥ�ڵĴ�������ĵĴ��������ڣ�pDerived��ָ���Ǹ�������CBase���͵Ķ���objBase����objBase�еĶ�����û���������в��еĳ�Ա����v(��ʱ��ӡ�����ı���ʹ�������ģ������ڱ�������������϶����Ե�ʣ�pDerived�����������CDerived��ȥ���ʸ���ĳ�Ա��;
	/*pDerived�������CDerived��ȥ���ʳ�Ա��*/
	cout << "2)------------" <<endl;		
	objDerived.Print();
	cout << "3)------------" <<endl;				
	/*����....�ռ䷢���仯��*/
	cout << "sizeof(CBase)=" << sizeof(CBase) << endl;
	cout << "sizeof(objCBase)=" << sizeof(objBase) << endl;
	cout << "sizeof(CDerived)=" << sizeof(CDerived) << endl;
	cout << "sizeof(*pDerived)=" << sizeof(*pDerived) << endl;

	//pDerived->v= 128;  //�����˵Ŀռ���д�����ݣ���������:Stack around the variable 'objBase' was corrupted.
	//objDerived.Print();
	//(*pDerived).Print();
	pDerived->Print();
	
	return 0;
}

/*����ָ�� pbaseָ����������� objderived�����ǺϷ��ġ���Ȼִ�����
������ pbaseָ�������������󣬾��ܻ���������඼�� Print������Ա���������� pbaseָ�������������󣬱�����Ȼִ�е���
����� Print������Ա������������һ�������
���������������ĸ����ָ�룬��ô�ͻ���Ϊͨ
�������ʵģ���Ӧ�����ĸ���ĳ�Ա�������������������ָ�뵽��ָ����ǻ��������
���������*/

/*ͨ��ǿ������ת����ʹ���������ָ�� pderivedָ���˻������ objbase��
pDerived���õ� Print���� CDerived���Pint�������з��յ���䡣
�� Cderived�����У���Ա�����ͽ�����Ա����n��ţ�

��ôִ�� pDerived�`>Print(��ʱ����Ȼ pderivedָ�����һ��������󣬵��ⲻӰ��
��Ա����v�ĵ�ַ���㷽ʽ��
*/
/*
���vλ�ò�������objBase���󣬿�������������������ֵ�ǲ�ȷ���Ҳ���Ԥ��ģ�
�˴����ʲô����ͬ�������Ĵ���취��ͬ��
�����λ���ǲ���ϵͳ�涨���ɷ��ʵ�������ô����Ϳ������ڳ������ֹ
��ͬ��������ջ�Ϸ��þֲ������ķ�ʽ������ͬ���� DevC++���뱾������������δ�����
*/