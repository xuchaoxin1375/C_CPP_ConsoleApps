//8.2.2.cpp  ������ģ��Ĵ���
#include <iostream>
using namespace std;
union Register
{
	unsigned int word; // word��Ϊ�����������"��"����˼����ʾ32λ
	struct {
		unsigned short L;  //�Ĵ����ĵ�16λ
		unsigned short H;  //�Ĵ����ĸ�16λ
	}data;
};
int main()
{
	Register AX;
	AX.word = 0x12345678;
	AX.data.H = 0x9999;
	cout << hex << AX.word << "," << AX.data.L << "," << AX.data.H;
}

