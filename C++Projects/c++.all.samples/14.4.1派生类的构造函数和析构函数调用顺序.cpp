//program 14.4.1.cpp ������Ĺ��캯����������������˳��
#include <iostream>
#include <string>
using namespace std;
class CBug  {
		int legNum,color;
		int No ;
	public:
		/*���ó�ʼ���б���ָ������Ĺ��캯��;�Լ�Ϊ�������ĳЩ��Ա��������ʼ��
		�������в�constructor��,��������������Ĭ���޲�constructor��;��ô�����ʱ�������޲ι��캯���ͻ����!!!*/
		CBug (int ln, int cl,int No_):legNum/*��Ĭ��ֵ�Ĳ������뼯�п�ĳһ��,���ܹ��������м�,�������һ��,(ע�⴫��ʱ��˳�򼴿�)*/(ln),color(cl),No(No_)
		{
			/*���ڳ�ʼ���б����Ѿ���Ա����ָ���˳�ʼ��ֵ,�������������ڲ��Ͳ���Ҫ�ٴ��صر�д��ʼ����Ա���������*/
			cout << "CBug Constructor" <<endl;
		};
		~CBug() 
		{
			cout << "CBug Destructor" ;
			cout << ":" << No<<endl;
		}
		void PrintInfo() 
		{
			cout << legNum << "," << color <<endl;
		}

};
class CFlyingBug: public CBug 
{
		int wingNum;
	public:
		/*���ó�ʼ���б���ָ������Ĺ��캯��;�Լ�Ϊ�������ĳЩ��Ա��������ʼ��*/
		// CFlyingBug( ) { } ����ע�͵����������;��Ϊ�������в�constructor��,��������������Ĭ���޲�constructor��;��ô�����ʱ�������޲ι��캯���ͻ����!
		CFlyingBug ( int ln, int cl,int No_, int wn):CBug(ln,cl,No_),wingNum(wn) 
		{
			cout << "CFlyingBug Constructor" <<endl;
			
		}
		~CFlyingBug() 
		{
			cout << "CFlyingBug Destructor" << endl;
			cout << "\t";
		}

};
int main() {
	CBug bug1(1,2,1);
	CFlyingBug fb(2,3,2,4);//ִ��constructor(��ִ�л���CBug��constructor,Ȼ��ִ��������CFlyingBug��constructor
	CBug bug2(3,4,3);
	fb.PrintInfo ();
	return 0;
	/*ִ��destructor(����һ�������������,
	��ִ��������CFlyingBug��destructor,��ִ�л���CBug��destructor)*/
	/*��������ڳ�����ͬʱ�������������ͻ������,��ô�ĸ�����������Ҫȡ���ڶ���˳��,�����������(ÿ�������͵Ķ����������Լ���destructor����·��;
	* 
	��������г�Ա(����˽�г�Ա,��˽�г�Ա���޷���(ֻ����)������ķ��������ʵ�,������Ҫ�����ж�Ӧ�ķ������ܹ���ӷ��ʶ��һ���ķ������ǹ����Ĳſ�.)�Զ���Ϊ������ĳ�Ա��*/
}

