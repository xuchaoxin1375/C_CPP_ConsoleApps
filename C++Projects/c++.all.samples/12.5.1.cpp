//program 12.5.1.cpp ������Ա����
#include <iostream>
using namespace std;
class Sample
{
	int a;

public:
	Sample() : a(-1) {}	   //constructor;
	/* ������Ա�����������޸ĳ�Ա����;���г�Ա�������ڳ�����Ա��������ֻ��(�����ɸ�д��) */
	void GetValue() const; //������Ա��������
	/*��ͨ��Ա����*/
	void test(){
		cout<<"test() was called!"<<endl;
		cout<<"obj.a="<<a<<endl;
		
	};
};
void Sample::GetValue() const
{
	cout << "GetValue() const  was called!" << endl;
	//a += 5;/* ���г�Ա�������ڳ�����Ա��������ֻ��(�����ɸ�д��)  */
	cout<<"obj.a="<<a<<endl;
	
}

int main()
{
	const Sample obj; //����Sample��һ����������obj
	obj.GetValue();			//���������Ͽ���ִ�г�����Ա����
	//obj.test(); ��������ܾ���ͨ��Ա�����ķ���;
	return 0;
}
/*���������Ͽ���ִ�г�����Ա����������Ϊ������Ա����ȷ�������޸��κηǾ�̬��Ա������ֵ��������������ֳ�����Ա�����ڳ������п����޸ķǾ�̬��Ա��������䣬�ͻᱨ����ˣ����ó�Ա�����ڲ�Ҳ���������ͬ��������ǳ��ó�Ա��������̬��Ա�������⣩��*/