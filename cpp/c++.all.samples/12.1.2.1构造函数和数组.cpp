//program 12.1.2.1.cpp  ���캯��������
#include <iostream>
using namespace std;
class CSample {
public: 	
	CSample() { //���캯��1(Ĭ�Ϲ��캯��)
		cout << "Constructor 1 Called" << endl;
  	}
	CSample(int n ) { //���캯��2
		cout << "Constructor 2 Called" << endl;
  	}
};
int main(){
	CSample array1[2];
	cout << "step1"<<endl;
	CSample array2[2] = {4,5};
	cout << "step2"<<endl;
	
	cout << "step3"<<endl;
	CSample * array4 = new CSample[2];//�����Զ�����޲ι��캯��.���������new ������[�����С���ʽ]�ķ�ʽ��̬������һ���ڴ�,���صĵ�ַ�ɸ����͵�ָ�����������,���ָ������൱�������������������
    delete [] array4;/*���ͷ������ڴ�ʱ,����delete [] ������(��̬new���ص�ָ��*/

	CSample array3[2] = {3};//�ڵ���(�����)����array3[1]ʱ,����ͼ����������ڲ���Ĭ�Ͻṹ��������ʼ��,һ���޷�����,��������̵��Կ���������������������Ĺ��캯��.
	return 0;
}

