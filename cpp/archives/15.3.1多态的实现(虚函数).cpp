//program 15.3.1. cpp��̬���������
# include < iostream>
using namespace std;
class A
{
public:
	int i;
	virtual void func() { }
	virtual void func2() { }
};
class B :public A
{
	int j;
	virtual void func() { }

};
int main()
{
	cout << "sizeof(A)="<<sizeof(A) << endl
		<< "sizeof(B)="<<sizeof(B); //���8,12;
	/*������B���ڼ̳��˻���A�����г�Ա,������������ǳ�������ĳ�Ա������,��Ҫ���ϻ���ĳ�Ա*/
	/*�Աȷ���,�����麯���Ժ�,����������û���麯��ʱ����4���ֽڡ�
	ʵ����,�κ���̓�������༰��������Ķ���,
	��������������4���ֽ�,��4���ֽھ���ʵ�ֶ�̬�Ĺؼ�,
	��λ�ڶ���洢�ռ����ǰ�ˣ������ŵ����麯����ĵ�ַ��
*/
	return 0;
}