//program 12.8.1.1.cpp   ��Ԫ����
#include <iostream>
using namespace std;
class CCar ; //��ǰ���� CCar�࣬�Ա�����CDriver��ʹ��
class CDriver
{
 	public:
	   void ModifyCar( CCar * pCar) ; //��װ���� 
};
class CCar
{
 	  private:
		  int price;
      friend int MostExpensiveCar( CCar cars[], int total); //������Ԫ
      friend void CDriver::ModifyCar(CCar * pCar);		    //������Ԫ
};
void CDriver::ModifyCar( CCar * pCar) 
{
	pCar->price += 1000; //������װ���ֵ���� 
}
int MostExpensiveCar( CCar cars[],int total) //����������ļ۸� 
{
 	 int tmpMax = -1;
 	 for( int i = 0;i < total; ++i )
 	 	  if( cars[i].price > tmpMax)
 	 	  	  tmpMax = cars[i].price;
	 return tmpMax;
}
int main()
{
	 return 0;
}

