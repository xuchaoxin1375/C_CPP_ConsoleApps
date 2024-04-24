//program 14.1.1.cpp 简单学生管理程序 类的派生和继承
#include <iostream>
#include <string>
using namespace std;
class CStudent/*最基础的学生类(包括了所有学生的必有特性:Class_Student*/
{
    private:
		string name;/*string的大小在不同的实现原理下有着不同的大小;有的是4,有的是28/....;*/
		string id;  //学号
		char gender; //性别,'F'代表女，'M'代表男
		int age;
	public:
		void PrintInfo();
		void SetInfo( const string & name_,const string & id_, int age_,char gender_ );
        string GetName() {  return name;  }
};
class CUndergraduateStudent:public CStudent  //本科生类CUndergraduateStudent，继承了CStudent类
{
	/*在派生类独有的成员变量定义之前,基类的所有成员已经导入*/
	private:
		string department; //学生所属的系的名称(教基类新添加的成员变量
	public:
		/*派生类特有函数:保研操作函数*/
		void QulifiedForBaoyan() {//给予保研资格
			cout << "qulified for baoyan" << endl;
		}
		/*在派生类中修改基类中的PrintInfo()函数,以便还能够打印出专业名称.*/
		void PrintInfo() {
			CStudent::PrintInfo(); //调用基类的PrintInfo
			cout << "Department:" << department <<endl;
		}
		/*在派生类中修改基类中的SetInfo()函数,以便设置专业department这一成员变量.*/
		/*先调用基类中的SetInfo(),完成继承自基类部分的成员变量; 发现此函数名和基类中的成员函数名一致,则需注意调用前注意声明一下基类,以突破同名覆盖效应(否则成递归了)*/
		void SetInfo( const string & name_,const string & id_,
			int age_,char gender_ ,const string & department_) 
		{
			CStudent::SetInfo(name_,id_,age_,gender_); //调用基类的SetInfo
			department = department_;
		}
};
/*基类的PrintInfo()*/
void CStudent::PrintInfo()
{
	cout << "Name:" << name << endl;
	cout << "ID:" << id << endl;
	cout << "Age:" << age << endl;
	cout << "Gender:" << gender << endl;
}
/*基类的SetInfo*/
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
	/*调用QulifiedForBaoyan ()表示赋予s2保研的资格:*/
	s2.QulifiedForBaoyan ();
	/*打印s2的信息:*/
	s2.PrintInfo ();
	cout << "sizeof(char)" << sizeof(char) << endl;
	cout << "sizeof(int)" << sizeof(int) << endl;
	cout << "sizeof(string)=" << sizeof(string) << endl;
	cout << "sizeof(CStudent)=" << sizeof(CStudent) << endl;
    cout << "sizeof(CUndergraduateStudent)=" << sizeof(CUndergraduateStudent) << endl;
	/*
	sizeof(string)=28
	sizeof(CStudent)=64 //照理说是61,但这里为了对齐,补了三个字节给它(该cpu(64位)一次传输8字节,补成8字节的整
	sizeof(CUndergraduateStudent)=92
*/
	/*按理说，对象体积等于各成员变量体积之和，那么sizeof（CStudent）的值应该为61，但输出结果却是“sizeof（CStudent）=64"，这是为什么呢？
	由于计算机在CPU和内存之间传送数据都是以4字节（对32位计算机）或
	8字节（对64位计算机）为单位进行的，
	因此出于传输效率的考虑，应该尽量使对象的成员变量的地址是4或8的整数倍，这称为对齐。*/
	return 0;
}
/*CUndergraduateStudent类还重新编写了从基类继承的两个成员函数SetInfo和PrintInfo。在基类和派生类有同名成员（可以是成员变量，也可以是成员函数）的情况下，在派生类的成员函数中访问同名成员，或通过派生类对象访问同名成员，除非有特别指明，访问的就是派生类的成员，这种情况称为“覆盖”即派生类的成员覆盖基类的同名成员。
如果要访问基类的同名成员，那么需要在成员名前面加“基类名：：”。例如，假设s2是CUndergraduateStudent类的对象，p是CUndergraduateStudent类的指针，
那么以下写法就调用了基类的成员函数：s2.CStudent:：Pr intInfo（）；p-> CStudent:：PrintInfo（）；

派生类的PrintInfo成员函数，先调用基类的PrintInfo输出基类部分的成员信息，然后再输出新增的department成员信息。

基类和派生类有同名成员函数，完成类似的功能，在派生类的同名成员函数中，先调用基类的同名成员函数完成基类部分的功能，然后再执行自已的代码完成派生类部分的功能，这种做法非常常见（但并非必须）。
派生类和基类有同名成员函数很常见但,一般不会在派生类中定义和基类同名的成员变量，这样做会很让人困惑。*/
