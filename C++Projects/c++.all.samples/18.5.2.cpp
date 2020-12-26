//program 18.5.2.cpp����ģ����Ϊ��ģ�����Ԫ
#include <iostream>
#include <string>
/*��ģ��Pair<T1,T2>*/
using namespace std;
template <class T1, class T2>
class Pair
{
private:
	T1 key;    //�ؼ���
	T2 value;  //ֵ
public:
	/*constructor:*/
	Pair(T1 k, T2 v) :key(k), value(v) { };
	/*overload_operator_= */
	bool operator < (const Pair<T1, T2>& p) const;
	/*�����ص�ȫ�ֺ���"<<"(����ȡ�����)����Ϊ��Ԫ;ͨ������������������ø����������:*/
	template <class T3, class T4>
	friend
		ostream& operator<< (ostream& o, const Pair<T3, T4>& p);
};
/*����"<"��Ա����ģ��*/
template<class T1, class T2>
bool Pair<T1, T2>::operator < (const Pair<T1, T2>& p) const
{ //"С"����˼���ǹؼ���С
	return key < p.key;
}

/*��������ȡ�����"<<";*/
template <class T1, class T2>
ostream& operator<< (ostream& o, const Pair<T1, T2>& p)
{
	/*����ģ��Pair<T1,T2>ʵ����ΪPair<int,double>ģ�庯��;ͬʱ������һ�������͵ĳ�Ա����obj(ͬʱ�����ʼ��Ϊ(12,3.14)*/
	Pair<int, double> obj(12, 3.14);
	/*���ڸú���ģ������ģ�����Ԫ����ģ��,�ʿ��Է��ʵ��ó�Ա�����˽�г�Ա����*/
//obj.key = 4; 		(�Ϸ�)

/*ָ�����غ�������ʽ:*/
	o << "(" << p.key << "," << p.value << ")";
	return o;//Ϊ��ʵ���������;
}
int main()
{
	/*��ģ��Pair<T1,T2>������ʵ��������*/
	Pair<string, int> student("Tom", 29), student_2("jack", 30);/*T<j(��д��ĸ<Сд��ĸ)*/
	/*��һ��ʵ����*/
	Pair<int, double> obj(12, 3.14);
	/*�������غ������ȡ�����"<<"��Ч��:(����������ͬ��Ķ���)*/
	cout << student << endl << obj << endl;
	/*����֮��ĳ�Ա����"<"��Ч��(ֻ�ܹ���������ͬ�����֮��;��ֻ�ܹ��Ƚ�ͬһ��ģ������ʵ�����³�����)*/
	cout << "�����(key)��С���Ǹ�Ԫ��" << endl << (student < student_2 ? student : student_2) << endl;


	return 0;
}

/*
������ģ��operator<<����ΪPair��ģ�����Ԫ��

���뱾����ʱ�o�������Զ�����������operator<<���������ǵ�ԭ�ͷֱ�����
ostream & operator <<( ostream & o,const Pair<string,int> &p);
ostream & operator <<( ostream & o, const Pair<int, double> & p);

��Visual Studio�У�������Ҳ�����������д�����:
friend ostream & operator <<T1,2>( ostream &o��const Pair<T1,12>& p);
���� Dev C++�У������ͱ��벻���ˡ�



*/