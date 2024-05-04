#include<iostream>
using namespace std;

int main()
{
    int array1[]={1,2,3};
    //int array2[] =array1;//C++不允许直接用另一个数组来初始另一个数组;
    int array2[3];
    int*array3=array1;//那当然是可以了；
    for(int i =0;i<3;i++)
    {
        array2[i] = array1[i];
        cout<<"array2[i]="<<array2[i]<<endl;
    }
}