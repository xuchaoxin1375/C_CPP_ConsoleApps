//program 18.2.3.cpp  �ɱ䳤������ģ��
#include <iostream>
#include <cstring>
using namespace std;
/*��ģ��CArray*/
template <class T>//T���Ա�ʵ����Ϊint/double/float;
class  CArray
{
//public:
	int size; //����Ԫ�صĸ���
     T * ptr; //ָ��̬���������
public:
	/*��ͨ��Ա��������*/
		/*�����������캯��(���ع��캯��)*/
   CArray(int s = 0);  //s��������Ԫ�صĸ���
	CArray(CArray & a);
	~CArray();//��������
	/*��Ա����ģ������*/
	void push_back(const T & v); //����������β�����һ��Ԫ��v
	/*CArrayҲ��ģ������*/
	CArray & operator=( const CArray & a); //������������ĸ�ֵ
	/*������Ա����(ģ���е���������Ҫдģ����CArray<T>)*/
	int length() { return size; } 
		/*��Ա����ģ��(����������ģ������T)*/
	T & operator[](int i) //����"[]"
	{//����֧�ָ����±��������Ԫ�أ���a[i] = 4;��n = a[i]���������
		return ptr[i]; 
	} 
	
	void print() /*const*/ //�ǳ�Ա�����ϲ�����ʹ�������޶���(�˴�ָconst)
	{
		cout << "�������Ԫ������:" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << ptr[i] << " ";
		}
		cout << endl;
	}
	/*����ȫ�ֺ���ģ��Ϊ��Ԫ*/
	template<class T>
	friend void print(const CArray<T>& x) /*const*/;
	
};//��ģ��CArray<T>����;


/*��ӡ����(ȫ��);ȫ�ֺ���������ͨ�����������õ�.����ͨ����������Ϊ��������ȫ�ֺ���*/
template<class T>//�ز�����
void print(const CArray<T>& x)
{
	cout << "test_global" << endl;
	cout << "�������Ԫ������:" << endl;
	for (int i = 0; i < x.size; i++)
	{
		cout << x.ptr[i] << " ";
	}
	cout << endl;
}
/*constructor_1:Ϊ�������������ָ����Сs������Ŀռ�*/
template<class T>
CArray<T>::CArray(int s):size(s) //��size=s;//�����е��������Ѿ�ָ����s��Ĭ��ֵΪ0;���ⲿ�����ʱ��û��(Ҳ����Ҳ��������ָ��һ��Ĭ��ֵ��)
{ 
 	if( s == 0)
	 	ptr = NULL;
	else	   
		ptr = new T[s]; 
}  
/*copy_constructor_2:��������Ķ�����������Ƿ�Ϊ��*/
template<class T>
CArray<T>::CArray(CArray & a)/*����һ��CArray����a����ʼ��ǰ����*/
{
	if( !a.ptr) {//���Ϊ��
		ptr = NULL;//��ָ��̬�����ָ����ΪNULL
		size = 0;//������Ϊ0;
		return;
	}
	/*Ȼ����ִ��:*/
	ptr = new T[a.size];
	memcpy( ptr, a.ptr, sizeof(T ) * a.size);
	size = a.size;
}
/*destructor*/
template <class T>
CArray<T>::~CArray() 
{
	if (ptr) 
	{
		delete[] ptr;
	}
} 

/*overload_operator_=(��������ΪCArray<T>& (����)*/
template <class T>
CArray<T> &     CArray<T>::operator=( const CArray & a)
{ //��ֵ�ŵ�������  ʹ"="��߶������ŵ����飬��С������ �����ұߵĶ���һ��
	if (ptr == a.ptr) //��ֹa=a�����ĸ�ֵ���³���
	{
		return *this;
	}
   /*Դ�����ǿյĻ�,���ø�����,���ǻ�����ҪΪĿ������LHS����һ��ֵ:NULLʹ��Ŀ�������ֵ(�͸���Դ����RHSһ��Ϊ��(NULL)*/
   if( a.ptr == NULL) 
   {  //���a����������ǿյ�
	   if (ptr)
	   {
		   delete[] ptr;
	   }
	   /*��ΪNULL,ͬʱ,������CArray�л��������鳤�ȵ���Ϣ(xin'xi)*/
		ptr = NULL;
		size = 0;
		return * this;//����ֵΪ��ǰ�������
	}
 	if( size < a.size) { //���ԭ�пռ乻�󣬾Ͳ��÷����µĿռ�
		if (ptr)
		{
			delete[] ptr;
		}
        ptr = new T[a.size];
	}
	memcpy( ptr,a.ptr,sizeof(T)*a.size);	
	size = a.size;
 	return * this;
}
/*//������β�����һ��(T���͵�)Ԫ��,ͬʱ(ÿѹ��һ��Ԫ��,��Ҫ����һ�����鳤��ֵsize)*/
template <class T>
void CArray<T>::push_back(const T & v)
{  
   if( ptr) { 
   	   T * tmpPtr = new T[size+1]; //���·���ռ�
   	   memcpy(tmpPtr,ptr,sizeof(T)*size); //����ԭ��������
	   /*�ǵ�ɾ���ɿռ�,�����Ϊ�ڴ�����*/
   	   delete [] ptr; 
   	   ptr = tmpPtr; 
   }
   else  //���鱾���ǿյ�
   {
	   ptr = new T[1];
   }
	ptr[size++] = v; //�����µ�����Ԫ��(ͬʱͨ��size++���������鳤����Ϣ)
}

/*CArray��ģ���ṩ������"����"�����;��:
1.�ڳ�ʼ����ʱ�����(����,�Ҳ����Ǳ��������)�ĸ��ƹ��캯�����캯��
2.�ڶ���;����ʹ�����ص�"="�����,ʵ��"����"(���ַ�ʽ������)
*/

//
int main()
{
   CArray<int> a;//����һ��CArray�ɱ䳤���������a;
   for (int i = 0; i < 3; ++i)//Ϊ����a���3��ֵ
   {
	   a.push_back(i);//��������һ��ȷ��,����洢�����ݵ����;͹̶�������(�������鳤�ȿ��Ա仯,Ԫ�ص������ǲ����Ա��)
   }
   /*���Ե���ģ��ʵ����Ϊ���������ǵ�Ч��:*/
   CArray<float> b,e;
   float k = 2.121;
   for (int i = 0; i < 4; ++i)
   {
	   b.push_back(k+=1);
   }
   /*�������ָ��Ʒ�ʽ��Ч��:*/
   CArray<int> 
	   c(a),/*���Ը��ƹ��캯��*/
	   d=a;/*��������"="*/
   e = b;
   /*�������ص�"[]"��������������Ч��
   cout << "a[2]=" << a[2] << endl;
   cout << "b[1]=" << b[1] << endl;*/
   /*��Ա����pirnt()��Ч��:*/
   a.print();
   b.print();
   c.print();
   d.print();
   e.print();
   /*ȫ����Ԫ����ģ��ʵ�������Ч��*/
   print(a);
   print(b);
   print(c);
   print(d);
   /*��ӡ�����еĸ���Ԫ��
   for (int i = 0; i < a.length(); ++i)//���鳤��:a.length()
   {
	   cout << a[i] << " ";
   }*/
   return 0;
}
