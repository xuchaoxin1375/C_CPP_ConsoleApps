//program 12.6.1.cpp  �����
#include <iostream>
using namespace std;
class CTyre //��̥��
{
 	  private:
	  	int radius;	//�뾶  
	  	int width;    //���
	  public:	
		  /*�Ƿ����Ҳ����ʹ�� ��ʼ���б� ����ʼ������ĳ�Ա������*/
        CTyre(int r/*��������ĳ�Ա����radius*/,int w/*������Ա����width*/):radius(r),width(w)/*��ϵ��ͨ���ʼ������һ�ַ�ʽ*/
		{ 
			cout << "CTyre(int r,int w�� was called��" << endl;
			cout << "radius = " << radius << "," << "width = " << width << endl;
		}
};
class CEngine //������
{
public:
	CEngine()
	{
		cout << "The defult constructor function CEngine() was called!" << endl;
	}
};
class CCar {  //������
	private:
		int price;  //�۸�ԭ���������ͳ�Ա��
		CTyre tyre;/*����������ʵ�����Ķ������ĳ�ʼ����Ҫ���ö�Ӧ���ⲿ��Ĺ��캯��*/
		CEngine engine;/*�����Ա����ͬ��*/
	public:
   		CCar(int p,int tr,int tw );
};

/*����(ָ���������::�����Ĺ��캯����������������Ա����1������������Ա����2����������..*/
/*�����CCar�Ĺ��캯��CCar(...)�� ��ʼ���б� ��������ֻ��Ӳ��֣�*/
CCar::CCar(int p/*���ڳ�ʼ��price��Ա����*/,
	int tr,int tw/*������ʼ��tyre��Ա�����*/
		/*û��ΪCEngine���͵� engine��Ա�����ṩ��ʼ����������ô�������᳢����Ĭ��CEngine����޲�Ĭ�Ϲ��캯��ȥ��ʼ��engine��Ա����*/):
	/*��ʼ���б�*/
	price(p)/*price��Ա��CCar�����ԭ���������ͳ�Ա,�����ʹ�ñ����price��Ա����ֵ=p*/,
	tyre(tr, tw)//��ʼ���б������
{
	cout << "��ɶԷ����ĸ���Ա�����ͳ�Ա����ĳ�ʼ��" << endl;
};//�����CCar�Ĺ��캯��CCar(...)
int main()
{	
	CCar car(20000,17,225); 
 	return 0;
}
/*CCar�Ǹ�����࣬��tyre��engine������Ա���󡣱�������ҪŪ���ף�car�����е�tyre��engine��Ա�������γ�ʼ����
�������Ѿ�֪�������car�������������CCar��int p��int tr��int tw�����캯����ʼ���ģ�
��ôtyre��engine�����������ⲿ�ĳ�Ա�������γ�ʼ������Ҫ��CCar��int p��int tr��int tw������ģ���ʼ���б�  �ˡ�

��ʼ������ʼ��ĳ����һ��ָ���ǳ�ʼ���൱�е� ��Ա�����Լ���Ա����
�����ĳ�ʼ���б�λ�ڹ��캯���󣩵�Ŀ����Ҫ��Ϊ�˴�����ߣ���Ա���󣩣�
��Ȼ��ͨ�Ļ������ͳ�Ա����Ҳ��һ���������ڳ�ʼ���б���
�ó�ʼ���б��н����ˣ�tyreӦ��tr��tw��Ϊ��������CTyre��int r��int w�����캯����ʼ��������û�н���engine����ô����;
��������£�����������ΪengineӦ����CEngine����޲ι���������ʼ����
��CEngine��ȷ��һ���������Զ����ɵ�Ĭ���޲ι�����������ˣ�����car����ĳ�ʼ������ͽ���ˡ�*/