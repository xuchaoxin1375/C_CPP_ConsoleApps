//program 11.6.1.cpp  ��ҵԱ���������
#include <iostream>
#include <cstring>
using namespace std;
class CEmployee  {
    private:	
	    char szName[30]; //����
    public :
	    int salary; //����
	    void setName(char * name); 
	    void getName(char * name);
	    void averageSalary(CEmployee e1,CEmployee e2);
};
void CEmployee::setName( char * name)  {	
    strcpy( szName, name); //ok
}
void CEmployee::getName( char * name)  {	
	strcpy( name,szName); //ok
}
void CEmployee::averageSalary(CEmployee e1,CEmployee e2)
{
 	 salary = (e1.salary + e2.salary )/2;
}
int main()
{
    CEmployee e;
    strcpy(e.szName,"Tom1234567889"); //��������ܷ���˽�г�Ա
    e.setName( "Tom"); // ok
    e.salary = 5000; //ok
    return 0;	
}

