//��������,�����������֮��Ĺ�ϵ(�Թ���������������Ϊ������������.
#include<iostream>
using namespace std;

class CMaster;//��ǰ��������CMaster;
/*��д��֮ǰӦ����һ�����ܶ�λ(�Ա��д���е����Ժͷ�������)
����:
����:
���ù�������
���й�������
����:
��ӡ���Լ�������
��ӡ�����˵�����(�޷�ֱ��ͨ����������,�����Լ�ӵ�ͨ�����������������ִ�ӡ����.)*/
class CDog {
	string name;
	CMaster * pm;/*��������ĳ�Ա�������ܹ�����CMaster�ĳ�Ա;���ָ������͵����������н����޸�.*/
	//friend class CMaster;/*��Ԫ��friend class;���ڱ���ʱ��Ȼ���ʲ���CMaster�ĳ�Ա����*/
	/*������ȫ�ֺ���*/
	friend void printDogsMaster(const CDog& dog);
public:
	//void printItsMaster()
	//{
	//	cout << "the dog's master is:";
	//	//pm->printTheMasterName();(����ʱ����������CMaster�ĳ�Ա�����³���.)
	//}
	void setName(const string name_)
	{
		name = name_;
	}
	void printTheDogName()
	{
		cout << name;
	}
	/*����������ָ��,�Ա��������ҵ���ֻ��,�Ӷ�Ϊ��ֻ���޸Ĺ���(����ָ��)*/
	CMaster *& getMasterPtr()
	{
		return pm;
	}

};


/*��д��֮ǰӦ����һ�����ܶ�λ(�Ա��д���е����Ժͷ�������)
������Ӧ����
����:
��������,�������ֵ�����;
����:
�������˵�����
��ӡ���˱��˵�����
������,
ָ�����������Ĺ������˵�ָ��pm(ָ��������Լ�)
��ӡ��������,
��ӡ��������,
�ķ���*/
class CMaster {
	int numberOfDogs = 0;
	string name;
	CDog* dogs[10];/*��������˿�������ʮ����.*/
public :
	void setName(const string name_ )
	{
		name = name_;
	}
	void printTheMasterName()
	{
		cout << name << endl;
	}
	void getDog( CDog* ptr)/*������β�����Ϊconst CDog* ptr,��ô�ᵼ��ptr��ָ�Ķ�����Ĺ�����Ա���������ܹ�ʹ��*/
	{
		dogs[numberOfDogs] = (CDog*)ptr;
		numberOfDogs++;
		/*�����������pmָ������Ϊָ��������˶���ĵ�ַ.*/
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
/*ȫ�ֺ�����Ҫ����:((ͨ������,���ݹ������ӡ���˵�����))*/
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
	/*����haha��baba*/
	m1.getDog(&dog1);
	m1.getDog(&dog2);
	cout << "ͨ��ȫ�ַ�������ӡ�������˵�����" << endl;
	printDogsMaster(dog1);
	printDogsMaster(dog2);
	cout << "ͨ�����˴�ӡ��������" << endl;
	m1.printNamesOfDogs();
	m1.printTheNumberOfHisDogs();

}