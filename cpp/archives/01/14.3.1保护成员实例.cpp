//program 14.3.1.cpp 保护成员示例
#include<iostream>
using namespace std;
class CBase {
	  private:
		  int nPrivate;   //私有成员
      public: 
		  int nPublic;    //公有成员


      protected: 
		  int nProtected;   // 保护成员
};
class CDerived :public CBase
{
	/*从基类继承过来的所有成员:
	  private:
		  int nPrivate;   //私有成员(无法被派生类的成员函数访问到
      public: 
		  int nPublic;    //公有成员
      protected: //推荐
		  int nProtected;   // 保护成员*/

public:
	/*CDerived是一个派生类.*/
	void AccessBase () /*访问基类*/
	{
		/*易知:*/
		nPublic = 1;      // OK
       // nPrivate = 1;    // 错，不能访问基类私有成员 

		/*protected的特点1:*/
		nProtected = 1;  // OK，访问从基类继承的protected成员
		/*protected的特点2:*/
		CBase f;/*又使得CDerived成为封闭类;*/
		//f.nProtected = 1;
		/*错，f不是函数所作用的对象
		因为f不是this指针所指向的对象，即不是 Accessbase函数所作用
		的对象，所以不能访问其保护成员*/

		cout << "nPublic=" << nPublic<<endl;
		cout << "nProtected=" << nProtected << endl;
	}

	CDerived()
	{
		cout << "test" << endl;
	}
};
int main()
{
	CBase b;
	CDerived d;
	d.AccessBase();/*派生类对象d从b中继承了所有成员*/
	//int n = b.nProtected ;  //错，不在派生类成员函数内，不能访问基类保护成员
	//n = d.nPrivate;  //错，此处不能访问派生类d的私有成员 
	return 0;
}

