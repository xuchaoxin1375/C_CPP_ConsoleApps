//program 14.11.1.1.cpp ʹ�ö�̳е�Ա���������
#include <iostream>
#include <string>
using namespace std;
class CEmployee
{
		string name;
		int age;
		char gender;
	public:
	CEmployee() { cout << "CEmployee constructor" <<endl; }
	void PrintBasicInfo() 
	{
		cout << "Name:" << name << endl;
		cout << "Age:" << age << endl;
		cout << "Gender:" << gender << endl;
	};
	void SetBasicInfo(const string & name_,int age_,int gender_)
	{
		name = name_; age = age_; gender = gender_;
	}
};
class CSalesman: public CEmployee
{
protected:
	int salesVolume; //���۶�
};
class CManager: public  CEmployee
{
protected:
	int totalSubordinates; //��������
};
class CSalesManager: public CSalesman, public CManager
{
	public:
		void setInfo( int sv,int sn)
		{
			salesVolume = sv;
			totalSubordinates = sn;
		}
		void PrintInfo() 
		{
			CSalesman::PrintBasicInfo(); //����ָ�����ĸ����������
                                           //ִ�� PrintBasicInfo
			cout << "Sales Volume:" << salesVolume <<endl;
			cout << "Total Subordinates:" << totalSubordinates <<endl;
		}
};
int main()  
{  	
	CSalesManager sm;
	sm.CSalesman::SetBasicInfo("Tom",24,'M'); //����ָ�����ĸ����������
                                              //ִ�� SetBasicInfo
	sm.setInfo ( 100000,20);
	sm.PrintInfo();
	return 0;
}

