//program 14.7.1.cpp ���������ĸ�ֵ���ݹ���
#include<iostream>
using namespace std;
class A
{
	int a = 0;
public:
	void print()
	{
		cout << "a=" << a << endl;
	}
protected:
	void modify()
	{
		a += 2;
	}
};
class B:public A //��������
{
	int b = 100;
public:
	void print()
	{
		cout << "Class B" << endl;
		A::print();
	}
	void modify()
	{
		A::modify();/*ͨ�����û���Ĺ��г�Ա�������ﵽ��ӷ��ʻ����˽�г�Ա.;����ע��,modify()�����޸ĵ���B������еĳ�Ա�����a,��Ӱ�쵽��������Ļ�������еĳ�Ա����*/
		cout << "modified!" << endl;
	}
	
};
int main()
{
   A a;
   B b;
   b.print();
   b.modify();
   /*��֮,����Թ����������е���ļ�����*/
   a = b; //���������ֵ��������� (��Ҳֻ�ǽ������������еĳ�Ա������һ��ֵ����ĸ���(��ֵ),�������������еĳ�Ա�����ǲ���Ի����������.
   A& r = b; //����������ʼ���������� 
   A * pa = & b; //����������ַ��ֵ������ָ�� 
   B * pb = & b; 
   pa = pb; //������ָ�븳ֵ������ָ�� 
   return 0;
}
