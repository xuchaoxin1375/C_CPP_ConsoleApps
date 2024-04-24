//program 19.3.2.cpp   ��������Ӧ����accumulate
#include <iostream>
#include <vector>
#include <numeric> //accumulate �ڴ�ͷ�ļ�����
using namespace std;
template <class T>
void PrintInterval(T first, T last)
{ //�������[first,last)�е�Ԫ��
	for( ; first != last; ++ first)
		cout << * first << " ";
	cout << endl;
}
int SumSquares( int total, int value)
{
	return total + value * value;
}
template<class T> 
class SumPowers
{
	private:
		int power; 
	public:
		SumPowers(int p):power(p) { }
		const T  operator() ( const T & total, const T & value) 
		{
		 	T v = value;
			for( int i = 0;i < power -1; ++ i)
				 v = v * value;  
	 		return total + v; 
		}
};
int main()  
{
	const int SIZE = 10;	
	int a1[] = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> v(a1,a1+SIZE);
	cout << "1) "; PrintInterval(v.begin(),v.end());
	int result = accumulate(v.begin(),v.end(),0,SumSquares);
	cout << "2) ƽ���ͣ�" << result << endl;
	result = accumulate(v.begin(),v.end(),0,SumPowers<int>(3));  
	cout << "3) �����ͣ�" << result << endl;
	result = accumulate(v.begin(),v.end(),0,SumPowers<int>(4));  
	cout << "4) 4�η��ͣ�" << result;
	return 0;
}

