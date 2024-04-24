//program 12.8.2.1.cpp 友元类
class CCar
{
 	  private:
		int price;
      	friend class CDriver; //在CCar中声明CDriver为其友元类,CDriver的成员函数就可以访问CCar的私有变量
};
class CDriver
{
 	public:
       CCar myCar;
	   void ModifyCar()  //改装汽车 
	   { 
	   	 myCar.price += 1000;//因CDriver是CCar的友元类，故此处可以访问其(CCar类对象myCar的)私有成员price
	   }
};
int main()
{
	 return 0;
}

