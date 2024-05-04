//你中有我,我中有你的类之间的关系(以狗和领养它的主人为例构建两个类.
#include<iostream>
using namespace std;

class CMaster;//提前声明有类CMaster;
/*编写类之前应该有一个功能定位(以便编写该有的属性和方法函数)
狗类:
属性:
设置狗的名字
具有狗的名字
方法:
打印狗自己的名字
打印其主人的名字(无法直接通过狗类做到,但可以间接的通过其主人来将其名字打印出来.)*/
class CDog {
	string name;
	CMaster * pm;/*但在下面的成员函数不能够访问CMaster的成员;这个指针变量就等在主人类中进行修改.*/
	//friend class CMaster;/*友元类friend class;但在编译时仍然访问不到CMaster的成员函数*/
	/*再试下全局函数*/
	friend void printDogsMaster(const CDog& dog);
public:
	//void printItsMaster()
	//{
	//	cout << "the dog's master is:";
	//	//pm->printTheMasterName();(编译时做不到访问CMaster的成员而导致出错.)
	//}
	void setName(const string name_)
	{
		name = name_;
	}
	void printTheDogName()
	{
		cout << name;
	}
	/*返回主人类指针,以便让主人找到这只狗,从而为这只狗修改归属(主人指针)*/
	CMaster *& getMasterPtr()
	{
		return pm;
	}

};


/*编写类之前应该有一个功能定位(以便编写该有的属性和方法函数)
主人类应该有
属性:
狗的数量,狗的名字的属性;
方法:
设置主人的名字
打印主人本人的名字
领养狗,
指定他所领养的狗的主人的指针pm(指向此主人自己)
打印狗的数量,
打印狗的名字,
的方法*/
class CMaster {
	int numberOfDogs = 0;
	string name;
	CDog* dogs[10];/*假设该主人可以领养十条狗.*/
public :
	void setName(const string name_ )
	{
		name = name_;
	}
	void printTheMasterName()
	{
		cout << name << endl;
	}
	void getDog( CDog* ptr)/*如果将形参设置为const CDog* ptr,那么会导致ptr所指的对象里的公开成员方法都不能够使用*/
	{
		dogs[numberOfDogs] = (CDog*)ptr;
		numberOfDogs++;
		/*将狗对象里的pm指针设置为指向这个主人对象的地址.*/
		ptr->getMasterPtr() = this;
	}
	void printTheNumberOfHisDogs()
	{
		cout << "the master's number of dogs:" <<numberOfDogs << endl;
	}
	void printNamesOfDogs()
	{
		for (int i = 0; i < numberOfDogs; i++)
		{
			cout << "Dog" << i << ":";
			dogs[i]->printTheDogName();
			cout << endl;
		}
	}

};
/*全局函数需要参数:((通过传参,根据狗对象打印主人的名字))*/
void printDogsMaster(const CDog& dog)
{
	cout << "the dog's master is:";
	dog.pm->printTheMasterName();
}

int main()
{
	CMaster m1;
	m1.setName("master1");
	CDog dog1, dog2;
	dog1.setName("haha");
	dog2.setName("baba");
	/*领养haha和baba*/
	m1.getDog(&dog1);
	m1.getDog(&dog2);
	cout << "通过全局方法来打印狗的主人的名字" << endl;
	printDogsMaster(dog1);
	printDogsMaster(dog2);
	cout << "通过主人打印狗的名字" << endl;
	m1.printNamesOfDogs();
	m1.printTheNumberOfHisDogs();

}