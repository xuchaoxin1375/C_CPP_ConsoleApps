//program 16.2.1.cpp 输出重定向
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()  
{
    int x,y;
    cout << "输入被除数 除数:" << endl;
    cin >> x >> y;
    /*将本该输出在stdout的内容输到指定目录下(根据模式"w",创建指定目录下的文件,再将内容写入)*/
    freopen("C:\\users\\xuchaoxin\\desktop\\test.txt","w",stdout);  /*将标准输出重定向到 指定路径下,会创建test.txt文件并写入内容;与普通windows路径相比,需要在出现\的地方打成"\\"才行;*/

    if( y == 0 )  //除数为0则输出错误信息
    {
        cerr << "error.(you can define the context by yourself here.)" << endl;
        /*不过写作cout<<"error"<<endl效果好像亦一样;只是cout可以被重定向;cerr不能被重定向;*/
    }
    else  
	    cout << x /y ;
 	return 0;
}

