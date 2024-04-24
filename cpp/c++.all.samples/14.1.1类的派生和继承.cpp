//program 14.1.1.cpp ��ѧ��������� ��������ͼ̳�
#include <iostream>
#include <string>
using namespace std;
class CStudent/*�������ѧ����(����������ѧ���ı�������:Class_Student*/
{
    private:
		string name;/*string�Ĵ�С�ڲ�ͬ��ʵ��ԭ�������Ų�ͬ�Ĵ�С;�е���4,�е���28/....;*/
		string id;  //ѧ��
		char gender; //�Ա�,'F'����Ů��'M'������
		int age;
	public:
		void PrintInfo();
		void SetInfo( const string & name_,const string & id_, int age_,char gender_ );
        string GetName() {  return name;  }
};
class CUndergraduateStudent:public CStudent  //��������CUndergraduateStudent���̳���CStudent��
{
	/*����������еĳ�Ա��������֮ǰ,��������г�Ա�Ѿ�����*/
	private:
		string department; //ѧ��������ϵ������(�̻�������ӵĳ�Ա����
	public:
		/*���������к���:���в�������*/
		void QulifiedForBaoyan() {//���豣���ʸ�
			cout << "qulified for baoyan" << endl;
		}
		/*�����������޸Ļ����е�PrintInfo()����,�Ա㻹�ܹ���ӡ��רҵ����.*/
		void PrintInfo() {
			CStudent::PrintInfo(); //���û����PrintInfo
			cout << "Department:" << department <<endl;
		}
		/*�����������޸Ļ����е�SetInfo()����,�Ա�����רҵdepartment��һ��Ա����.*/
		/*�ȵ��û����е�SetInfo(),��ɼ̳��Ի��ಿ�ֵĳ�Ա����; ���ִ˺������ͻ����еĳ�Ա������һ��,����ע�����ǰע������һ�»���,��ͻ��ͬ������ЧӦ(����ɵݹ���)*/
		void SetInfo( const string & name_,const string & id_,
			int age_,char gender_ ,const string & department_) 
		{
			CStudent::SetInfo(name_,id_,age_,gender_); //���û����SetInfo
			department = department_;
		}
};
/*�����PrintInfo()*/
void CStudent::PrintInfo()
{
	cout << "Name:" << name << endl;
	cout << "ID:" << id << endl;
	cout << "Age:" << age << endl;
	cout << "Gender:" << gender << endl;
}
/*�����SetInfo*/
void CStudent::SetInfo( const string & name_,const string & id_, int age_,char gender_ )
{
	name = name_;
	id = id_;
	age = age_;
	gender = gender_;
}
int main()
{
	CStudent s1;
	CUndergraduateStudent s2;
	s2.SetInfo(
		"Harry Potter",
		"118829212",
		19,
		'M',
		"Computer Science");
	cout <<  s2.GetName() << " " ;
	/*����QulifiedForBaoyan ()��ʾ����s2���е��ʸ�:*/
	s2.QulifiedForBaoyan ();
	/*��ӡs2����Ϣ:*/
	s2.PrintInfo ();
	cout << "sizeof(char)" << sizeof(char) << endl;
	cout << "sizeof(int)" << sizeof(int) << endl;
	cout << "sizeof(string)=" << sizeof(string) << endl;
	cout << "sizeof(CStudent)=" << sizeof(CStudent) << endl;
    cout << "sizeof(CUndergraduateStudent)=" << sizeof(CUndergraduateStudent) << endl;
	/*
	sizeof(string)=28
	sizeof(CStudent)=64 //����˵��61,������Ϊ�˶���,���������ֽڸ���(��cpu(64λ)һ�δ���8�ֽ�,����8�ֽڵ���
	sizeof(CUndergraduateStudent)=92
*/
	/*����˵������������ڸ���Ա�������֮�ͣ���ôsizeof��CStudent����ֵӦ��Ϊ61����������ȴ�ǡ�sizeof��CStudent��=64"������Ϊʲô�أ�
	���ڼ������CPU���ڴ�֮�䴫�����ݶ�����4�ֽڣ���32λ���������
	8�ֽڣ���64λ�������Ϊ��λ���еģ�
	��˳��ڴ���Ч�ʵĿ��ǣ�Ӧ�þ���ʹ����ĳ�Ա�����ĵ�ַ��4��8�������������Ϊ���롣*/
	return 0;
}
/*CUndergraduateStudent�໹���±�д�˴ӻ���̳е�������Ա����SetInfo��PrintInfo���ڻ������������ͬ����Ա�������ǳ�Ա������Ҳ�����ǳ�Ա������������£���������ĳ�Ա�����з���ͬ����Ա����ͨ��������������ͬ����Ա���������ر�ָ�������ʵľ���������ĳ�Ա�����������Ϊ�����ǡ���������ĳ�Ա���ǻ����ͬ����Ա��
���Ҫ���ʻ����ͬ����Ա����ô��Ҫ�ڳ�Ա��ǰ��ӡ������������������磬����s2��CUndergraduateStudent��Ķ���p��CUndergraduateStudent���ָ�룬
��ô����д���͵����˻���ĳ�Ա������s2.CStudent:��Pr intInfo������p-> CStudent:��PrintInfo������

�������PrintInfo��Ա�������ȵ��û����PrintInfo������ಿ�ֵĳ�Ա��Ϣ��Ȼ�������������department��Ա��Ϣ��

�������������ͬ����Ա������������ƵĹ��ܣ����������ͬ����Ա�����У��ȵ��û����ͬ����Ա������ɻ��ಿ�ֵĹ��ܣ�Ȼ����ִ�����ѵĴ�����������ಿ�ֵĹ��ܣ����������ǳ������������Ǳ��룩��
������ͻ�����ͬ����Ա�����ܳ�����,һ�㲻�����������ж���ͻ���ͬ���ĳ�Ա�����������������������*/
