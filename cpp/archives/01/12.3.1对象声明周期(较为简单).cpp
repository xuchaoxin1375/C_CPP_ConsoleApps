//program 12.3.1.cpp  ���캯�������������ͱ���������
#include <iostream>
using namespace std;
class Demo {
	int id;/*�����ļ�¼��,Ĭ����private.*/
public:	
	 Demo(int i) 	 
     {
		id = i;
		cout << "id=" << id << " constructed" << endl;
	 }
	~Demo()  
     {
		cout << "id=" << id << " destructed" << endl;
	 }
};
Demo d1(1);/*ȫ�ֱ�����main()֮ǰ�ͱ���ʼ�����,Ӧ�����ȹ�עȫ�ֶ���*/
void Func()  /*ȫ�ֺ���Func()*/
{
	static Demo d2(2);
	Demo d3(3);
	cout << "func" << endl;
}
int main ()  
{
	Demo d4(4);
	d4 = 6;
	cout << "main" << endl;
	{    Demo d5(5); 	
     }
	Func();
	cout << "main ends" << endl;
	return 0;
}

