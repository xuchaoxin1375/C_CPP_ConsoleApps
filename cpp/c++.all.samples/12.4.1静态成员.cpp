//program 12.4.1.cpp  ��̬��Ա��Ӧ�þ���
#include <iostream>
using namespace std;
/*�ۼ����о��εĸ����Լ�����ܺ�:*/
class CRectangle
{
	private:/*˽�л���̬����,ʹ�����ȫ,����������ĺ���/ȫ�ֺ����Ķ�*/
   		int w, h;
	     static int totalArea;  //���������
   		static int totalNumber; //��������
	public:
	     CRectangle(int w_,int h_);
		 /*��������~CRectangle()*/
   		 ~CRectangle();
		 /*��̬��Ա����:*/
	     static void PrintTotal();  
		 /*�򲹶�:*/
		CRectangle(CRectangle & r);/*ע���Ա�����в�Ҫ(Ҳ����Ҫ)�����޶���CRectangle::*/
};
/*�Զ���ĸ��ƹ��캯��*/
CRectangle::CRectangle(CRectangle& r)
{

	totalNumber++; 
	totalArea += r.w * r.h;
	w = r.w;
	h = r.h;

}
CRectangle::CRectangle(int w_,int h_)
{
    w = w_;  h = h_;
    totalNumber ++;        //�ж�����������������
    totalArea += w * h;    //�ж������������������
}
CRectangle::~CRectangle()
{
    totalNumber --;      //�ж����������������
    totalArea -= w * h;  //�ж�����������������
}
/*��ͨ��Ա����PrintTotal()*/
void CRectangle::PrintTotal()
{
    cout << totalNumber << "," <<  totalArea << endl; 
}
/*
�����ڶ�������ļ��жԾ�̬��Ա��������һ���������ʼ����
���������ͨ�������Ӳ���ͨ����*/

int CRectangle::totalNumber = 0;
int CRectangle::totalArea = 0;

int main()
{
	/*���岢��ʼ����������.r1,r2 */
	CRectangle 
		r1(3,3), 
		r2(2,2);
   //cout << CRectangle::totalNumber; // ����, totalNumber��˽�е� 
	CRectangle::PrintTotal();
	r1.PrintTotal();
	/*��Ҫ�˳�main����,����ʼ����.*/
	return 0;
}
/*�������Ļ���˼���ǣ�CRectangle��ֻ�ṩһ�����캯������ô����CRectangle�������ɵ�ʱ����Ҫ��������캯����ʼ���������������캯�����������������������ֵ���ɣ�������CRectangle��������ʱ����ִ���������������������������м������������������ֵ���ɡ�
��7�к͵�8�е�������Ա����������¼���������о��ζ�������������ǵ�����C ����������ֵ��Ȼ����ÿ������ά���Լ���һ�ݣ���Ӧ����һ-��ֻ��һ-�ݡ���Ȼ������ȫ�ֱ���������� ����ֵҲ���ԣ����������޷�����ʽ��һ�ۿ���������ȫ�ֱ�����CRectangle��Ľ�����ϵ��Ҳ�Ϳ�����������ȫ�ֱ���������Щ�����б����ʡ�������д��CRectangle��ľ�̬��Ա��������������ӭ�ж����ˡ��������������������ĺ���PrintTotalû��д��ȫ�ֺ���������д��CRectangle��ľ�̬��Ա����������Ҳ��һ-���ġ�
I��̬��Ա�����������ඨ�������ר����-������������ʱ������ǰ��ӡ����������������29�к͵�30�С�������ͬʱ����Գ�ʼ�������û����������ô��������ʱ����Ȼ���ᱨ�����ǵ����ӣ�ink���׶λᱨ�桰��ʶ���Ҳ���������֮�ǲ�������.exe�ļ�����36�����û��ע�͵��Ļ�����������ġ���ΪtotalNumber��˽�г�Ա]�����ڳ�Ա����������ʡ�
��37�к͵�38����������ͬ��˵�������ǵȼ۵ģ���Ϊ��̬��Ա����������������ĳ���������Ծ�̬��Ա�����ڲ����ܷ��ʷǾ�̬��Ա������Ҳ���ܵ��÷Ǿ�̬��Ա������

��������У�CRectangle���д�������Ͽ�û��ʲô���⣬ʵ��������bug�ġ�
ԭ����ǲ������е�CRectangle�������ɵ�ʱ�򶼻��ó����е��Ǹ����캯����ʼ�������ʹ�ø���ĳ�����΢����һЩ��������CRectangle����Ϊ�����ĺ�������CRectangle����Ϊ����ֵ�ĺ�����������ˡ�CRectangle rl��r2����"
��������䣬��ô����һЩCRectangle��������Ĭ�ϸ��ƹ��캯�����������ù��캯��CRectangle��intw_��inth_�����г�ʼ���ˡ�
��Щ�������ɵ�ʱ��û������totalNumber��totalArea��ֵ����������ʱ��ȴ�����ˣ�������ˣ�
totalNumber��totalArea��ֵ������Ȼ�ͻ���bug�ġ�����İ취����ΪCRectangle���д���¸��ƹ��캯����
CRectangle����CRectang1e��CRectangle&r��
*/

