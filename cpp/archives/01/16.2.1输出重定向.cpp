//program 16.2.1.cpp ����ض���
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()  
{
    int x,y;
    cout << "���뱻���� ����:" << endl;
    cin >> x >> y;
    /*�����������stdout�������䵽ָ��Ŀ¼��(����ģʽ"w",����ָ��Ŀ¼�µ��ļ�,�ٽ�����д��)*/
    freopen("C:\\users\\xuchaoxin\\desktop\\test.txt","w",stdout);  /*����׼����ض��� ָ��·����,�ᴴ��test.txt�ļ���д������;����ͨwindows·�����,��Ҫ�ڳ���\�ĵط����"\\"����;*/

    if( y == 0 )  //����Ϊ0�����������Ϣ
    {
        cerr << "error.(you can define the context by yourself here.)" << endl;
        /*����д��cout<<"error"<<endlЧ��������һ��;ֻ��cout���Ա��ض���;cerr���ܱ��ض���;*/
    }
    else  
	    cout << x /y ;
 	return 0;
}

