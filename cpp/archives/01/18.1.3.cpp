//program 18.1.3.cpp  ��������ģ���������ƥ��˳��ʾ��
#include <iostream>
using namespace std;
/*��һ������ģ��*/
template <class T> //����һ��ģ������T
T Max( T a, T b)
{
	cout << "Template Max 1" <<endl;
	cout<<"Max="<<(a>b?a:b)<<endl;
	return 0;
};
/*�ڶ�������ģ��(�����ǶԵ�һ������ģ�������,�������б����˱仯)*/
//template <class T,class T> //previous declaration as 'class T'//��ͬ����û��Ҫ��������;
/* ����ģ�����������һ��(�β�����һ���ǲ���������ģ�������);���µĴ��� */
//template <class T>//'template<class T> T Max(T, T)' previously declared here
//template <class T2>//'template<class T> T Max(T, T)' previously declared here

/* */
/*��ͬģ�����Ͷ������֮��������ֶȵĻ����������ģ�����͵ĸ�����!;��ͬ���ֵ�ģ������ֻ����ͬһ��ģ�����Ͷ�������в������ֶ�*/
template <class T,class T2> //����������ͬ��ģ������ T��T2;(ͬһ��ģ�嶨������г��ּ�����ͬ�����־ͻ��������ģ������)
T Max( T a, T2 b)
{
	cout << "Template Max 2" <<endl;
	cout<<"Max="<<(a>b?a:b)<<endl;
	return 0;
}
 
double Max(double a, double b){
	cout << "Function Max" << endl;
	cout<<"Max="<<(a>b?a:b)<<endl;
	return 0;
}
int main() {
	int i=4, j=5;
	cout<<(i<j?i:j)<<endl;
	Max(1.2,3.4);  //����Max����
	Max(i,j);     //���õ�һ��Maxģ�����ɵĺ���
	Max(1.2,3);   //���õڶ���Maxģ�����ɵĺ���
	return 0;  
}
/* ���ж�������ͺ���ģ��������ͬ������£�
һ������������䣬����Ӧ�ñ�ƥ��ɶ��ĸ���������ĸ�ģ��ĵ����أ�
C++��������ѭ��������˳��
��1�����Ҳ�����ȫƥ�����ͨ����������ģ��ʵ�������õĺ�������
��2�����Ҳ�����ȫƥ���ģ�庯����
��3��Ȼ����ʵ���������Զ�����ת�����ܹ�ƥ�����ͨ������
��4������Ķ��Ҳ������򱨴� */
/* 
����ѳ����е���ͨ���� Max(double a, double b)�͵ڶ���Maxģ�嶼ȥ��,
����������˵��4��ƥ�����,
��Max(1. 2,3) ;������ʱ�ͻᱨ��
��Ϊ�ӵ�һ��Maxģ��û��������֮������ȫƥ���ģ�庯��Max(double,int)��
��Ȼ�Ӹ�Maxģ���������int Max(int, int)��double Max( double, doube) ,
���ǵ���Ӧ�ð�1.2�Զ�ת����int����Ȼ�����ǰ��,
����Ӧ�ð�3�Զ�ת����double����Ȼ����ú���,
����ȥ�����ԣ��������ж����Եġ���˱������ᱨ�� */
