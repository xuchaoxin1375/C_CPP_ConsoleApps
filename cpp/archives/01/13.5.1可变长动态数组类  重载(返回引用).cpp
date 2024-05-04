//program 13.5.1.cpp  �ɱ䳤��̬������
/*
��1�������Ԫ�ظ��������ڳ�ʼ���ö����ʱ��ָ����
��2�����Զ�̬�����������Ԫ�ء�
��3��ʹ�ø����ʱ���ò��Ķ�̬�ڴ���䡢�ͷ�����
��4���ܹ���ʹ������������ʹ�ö�̬��������������ͨ���±���������Ԫ�ء�*/
#include <iostream>
#include <cstring>
using namespace std;
/*//class CArray�ɱ䳤��̬������,�����б���������*/
class  CArray
{
     int size; //����Ԫ�صĸ���
     int *ptr; //ָ��̬���������
public:
   CArray(int s = 0);     //s��������Ԫ�صĸ���
	CArray(CArray & a);//copy_constructor
	~CArray();//destructor

	void push_back(int v); //����������β�����һ��Ԫ��v

	CArray & operator=( const CArray & a); //������������ĸ�ֵ

	int length() { return size; } //��������Ԫ�ظ���

	/*����[]�����:(�Ƕ������൱�е���Ϊ��Ա������),����ֱ�ӷ������(˽��)��Ա����(ָ�����ptr)*/
	int & operator[](int i) /*������������,ʹ֮�ܹ���Ϊ��ֵ.(����ֵ�Ļ�int��int & ������.)*/
	{//����֧�ָ����±��������Ԫ�أ���a[i] = 4;��n = a[i]���������
		return ptr[i]; 
	} 
};//class CArray�ɱ䳤��̬������.
/*��������
initial_constructor:����s��int���ڴ�*/
CArray::CArray(int s):size(s) //����Ĭ��ֵ�ڶ��������������һ��˵������,��Ҫ������˵��Ĭ��ֵ.
{ 
 	if( s == 0)
	 	ptr = NULL;
	else	   
		ptr = new int[s]; 
}  //CArray(int s){}
/*copy_constructor*/
CArray::CArray(CArray & a)
{
	if( !a.ptr) {//���a.ptrΪ��
		ptr = NULL;
		size = 0;
		return;
	}
	ptr = new int[a.size];
	memcpy( ptr, a.ptr, sizeof(int ) * a.size);
	size = a.size;
}//copy_constructor(CArray &){}
/*destructor*/
CArray::~CArray() 
{
	/*�����ǰ�Ķ����е�ptr��NULL(��),�Ž����ͷŲ���*/
 		if( ptr) delete [] ptr;
} //~CArray(){}
/*overload_operator_of_=*/
CArray & CArray::operator=( const CArray & a)
{ //������ ��ֵ�ŵ������� ʹ"="��߶������ŵ����飬��С�����ݶ����ұߵĶ���һ��
	/*�ڸ���ǰ,��Ҫִ��һЩ�ж�(һ��)�;��ڴ�����(���Ҫ�Ļ�)*/
	if (ptr == a.ptr) //��ֹa=a�����ĸ�ֵ���³���(ptr�ǵ�һ��������,a.ptr�ǵڶ���������)
	{
		return *this;
	}
   /*���a����������ǿյ�*/
   if( a.ptr == NULL) {  
	   if (ptr)
	   {
		   delete[] ptr;
	   }
		ptr = NULL;
		size = 0;

		return * this;
	}
   /*ԭ�пռ�С��Ҫ��Ĵ�С,��������.*/
 	if( size < a.size) { //���ԭ�пռ乻�󣬾Ͳ��÷����µĿռ�
		/*�ڷ����¿ռ�ǰ,һ�㶼��Ҫ�����пռ��Ƿ�Ϊ��(NULL),����,��ʱ�ͷŵ�*/
		if (ptr)
		{
			delete[] ptr;
		}
		/*Ȼ������¿ռ�*/
        ptr = new int[a.size];
	}
	/*ʹ"="��߶������ŵ����飬��С�����ݶ����ұߵĶ���һ��*/
	memcpy( ptr,a.ptr,sizeof(int)*a.size);	/*��memcpy()����strcpy()*/
	size = a.size;
 	return * this;
}
/*������β�����һ��Ԫ��*/
void CArray::push_back(int v)
{  
	if (ptr) {
		int* tmpPtr = new int[size + 1]; //���·���ռ�;����ÿ��ֻ����һ��(size��û�б仯,�Ա�memcpy() )
		memcpy(tmpPtr, ptr, sizeof(int) * size); //memcpy()��������ԭ��������;ԭ������������size��Ԫ��
		delete[] ptr; /*��ʱ�ͷŵ�������Ŀռ�.*/
		ptr = tmpPtr; /*ָ����������ڴ�ռ�*/
	}
	else  //���鱾���ǿյ�
	{
		ptr = new int[1];
	};

	ptr[size++] = v; //�����µ�����Ԫ��;�����ַ���һ����׷�ӵ�����β����,��size++����;
}//������β�����һ��Ԫ��


int main()
{
   CArray a; //��ʼ��������ǿյ�
   /*��1,2,3,4,5���β������������a�е������Ա��β��.*/
   for (int i = 0; i < 5; )
   {
	   a.push_back(i);
	   i++;
   }

   CArray a2,a3;
   /*��a��������Ƶ�a2��:*/
   a2 = a;
   /*��ӡ���ƵĽ��:*/
   for (int i = 0; i < a.length(); ++i)
   {
	   cout << a2[i] << " ";
   }
   a2 = a3; //a2�ֱ���ǿյ�
   
   for (int i = 0; i < a2.length(); ++i) //a2.length()����0
   {
	   cout << a2[i] << " ";
   }
   cout << endl;/*������ӡ����.*/
   a[3] = 100;/*���غ��[]������,��Ȼreturn�ı��ʽ��ptr(Ϊint*����),������ֵ���ͱ�����Ϊ��������int& ��Ҳ������Ϊ��ֵ*/
   CArray a4(a);	
   for (int i = 0; i < a4.length(); ++i)
   {
	   cout << a4[i] << " ";
   }
   return 0;
}
/*
[]��˫Ŀ�����6������������һ�������棬һ�������档
���ʽ��a[i]���ȼ��ڡ�a.operator[]��i����.
���ա�[]��ԭ�е����ԣ���a[i]����Ӧ���ܹ���Ϊ��ֵʹ�õģ�����.
"operator��[] �������Ӧ�÷�����������.
*/