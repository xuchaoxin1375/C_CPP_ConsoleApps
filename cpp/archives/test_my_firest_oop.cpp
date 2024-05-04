#include<iostream>
using namespace std;
class Crectangle
{
public:
	int w, h;//定义成员变量
	void Init(int w_, int h_);//声明成员函数;
	int area();
	int perimeter();

};

void Crectangle::Init(int w_, int h_)/*定义类Crectangle的操作(函数)*/
{
	w = w_;
	h = h_;

}
int Crectangle::area()
{
	return w * h;
}
int Crectangle::perimeter()
{
	return 2 * (w + h);
}
int main()
{
	int w, h;
	Crectangle r;//用类Crectangle实例化出一个Crectangle类型的对象r;
	cout << "Enter lenth and width:" << endl;
	cin >> w >> h;
	r.Init(w, h);//对象r下调用成员函数(恰到好处的函数作用域)
	cout << "It's area is " << r.area() << endl;
	cout << "It's perimetere is " << r.perimeter()<<endl;
	cout << "sizeof(Crectangle)= "<<sizeof(Crectangle) << endl;
	return 0;
}