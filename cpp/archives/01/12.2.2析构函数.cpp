//program 12.2.2.cpp ��������
#include <iostream>
using namespace std;
class CDemo {
	public:
	~CDemo() { cout << "destructor" << endl; }/*��������:  ~����*/
};

void Func(CDemo obj ) /*��������Զ���Ϊ�����ĺ���,���������ƹ��캯���ĵ���(������õ��Ǳ��������ɵ�Ĭ�ϸ��ƺ���*/
{
	cout << "func" << endl;
}

CDemo d1;/*ȫ�ֵ�CDemo���Ͷ���,���������������Ҳ������*/
CDemo Test( ) 
{
	cout << "test" << endl;
	return d1;
}

int main(){
	CDemo d2;/*����Ĭ�Ϲ��캯��*/
	Func(d2);/*�����˸��ƹ��캯��,�뿪�˺�����d2�ĸ�������(��������obj)����_1*/
	Test();/*���ص���ʱ�����ڵ��øú�����������������_2*/
	cout << "after test" << endl;
	return 0;/*������������d2��������_3*/
}
/*�����������,d1��������_4;��,c++��,main����������,���ܻ���һЩ�ƺ���*/

