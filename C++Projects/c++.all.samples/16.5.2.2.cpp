//program 16.5.2.2.cpp  ��cin.getline��ȡ�ļ�ȫ������
#include <iostream>
using namespace std;
const int MAX_LINE_LEN = 10000;   //�����ļ���һ���10000���ַ�
int main()
{
 	char szBuf[MAX_LINE_LEN + 10]; 
 	freopen("test.txt","r",stdin);   //����׼�����ض���Ϊtest.txt 
 	while(cin.getline(szBuf,MAX_LINE_LEN + 5)) 
			 cout << szBuf << endl;
    return 0;
}
