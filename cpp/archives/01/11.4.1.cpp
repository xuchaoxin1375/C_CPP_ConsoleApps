//program 11.4.1.cpp  ������
#include <iostream>
using namespace std;
class CRectangle
{
	public:
		int w, h; //��Ա��������͸�
		void Init( int w_,int h_ ); //��Ա���������ÿ�͸� 
		int area(); //��Ա������ ����� 
		int perimeter(); //��Ա���������ܳ� 

}; //�����зֺ�
void CRectangle::Init( int w_,int h_ )//��Ľӿ�.
{ 
	w = w_;  h = h_;
}
int CRectangle::area() 
{ 
	return w * h;      
}
int CRectangle::perimeter()
{ 
	return 2 * ( w + h);  
}
int main( ) 
{
	 int w,h;
	 CRectangle  r;  //r��һ������
	 cin >> w >> h;
	 r.Init( w,h);
	 cout << "It's area is " << r.area() << endl;
	 cout << "It's perimeter is " << r. perimeter();
  	 cout << sizeof(CRectangle) << endl;
	 return 0;
}

