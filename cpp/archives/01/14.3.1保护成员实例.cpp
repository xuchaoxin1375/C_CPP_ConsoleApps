//program 14.3.1.cpp ������Աʾ��
#include<iostream>
using namespace std;
class CBase {
	  private:
		  int nPrivate;   //˽�г�Ա
      public: 
		  int nPublic;    //���г�Ա


      protected: 
		  int nProtected;   // ������Ա
};
class CDerived :public CBase
{
	/*�ӻ���̳й��������г�Ա:
	  private:
		  int nPrivate;   //˽�г�Ա(�޷���������ĳ�Ա�������ʵ�
      public: 
		  int nPublic;    //���г�Ա
      protected: //�Ƽ�
		  int nProtected;   // ������Ա*/

public:
	/*CDerived��һ��������.*/
	void AccessBase () /*���ʻ���*/
	{
		/*��֪:*/
		nPublic = 1;      // OK
       // nPrivate = 1;    // �����ܷ��ʻ���˽�г�Ա 

		/*protected���ص�1:*/
		nProtected = 1;  // OK�����ʴӻ���̳е�protected��Ա
		/*protected���ص�2:*/
		CBase f;/*��ʹ��CDerived��Ϊ�����;*/
		//f.nProtected = 1;
		/*��f���Ǻ��������õĶ���
		��Ϊf����thisָ����ָ��Ķ��󣬼����� Accessbase����������
		�Ķ������Բ��ܷ����䱣����Ա*/

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
	d.AccessBase();/*���������d��b�м̳������г�Ա*/
	//int n = b.nProtected ;  //�������������Ա�����ڣ����ܷ��ʻ��ౣ����Ա
	//n = d.nPrivate;  //���˴����ܷ���������d��˽�г�Ա 
	return 0;
}

