#include<iostream>
using namespace std;
class Crectangle
{
public:
	int w, h;//�����Ա����
	void Init(int w_, int h_);//������Ա����;
	int area();
	int perimeter();

};

void Crectangle::Init(int w_, int h_)/*������Crectangle�Ĳ���(����)*/
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
	Crectangle r;//����Crectangleʵ������һ��Crectangle���͵Ķ���r;
	cout << "Enter lenth and width:" << endl;
	cin >> w >> h;
	r.Init(w, h);//����r�µ��ó�Ա����(ǡ���ô��ĺ���������)
	cout << "It's area is " << r.area() << endl;
	cout << "It's perimetere is " << r.perimeter()<<endl;
	cout << "sizeof(Crectangle)= "<<sizeof(Crectangle) << endl;
	return 0;
}