//program 12.8.2.1.cpp ��Ԫ��
class CCar
{
 	  private:
		int price;
      	friend class CDriver; //��CCar������CDriverΪ����Ԫ��,CDriver�ĳ�Ա�����Ϳ��Է���CCar��˽�б���
};
class CDriver
{
 	public:
       CCar myCar;
	   void ModifyCar()  //��װ���� 
	   { 
	   	 myCar.price += 1000;//��CDriver��CCar����Ԫ�࣬�ʴ˴����Է�����(CCar�����myCar��)˽�г�Աprice
	   }
};
int main()
{
	 return 0;
}

