//program 19.2.2.2.cpp  ��list���Լɪ������
#include <list>
#include <iostream>
using namespace std;
int main()
{
	list<int> monkeys;
	int n,m;
	while(true) {
		cin >> n >> m ;
		if( n == 0 && m == 0)
			break;
		monkeys.clear();  //���list����
		for( int i = 1;i <= n; ++i)  //�����ӵı�ŷ���list
			monkeys.push_back(i);
		list<int>::iterator it = monkeys.begin ();
		while( monkeys.size() > 1 ) { //ֻҪ���в�ֹһֻ���ӣ���Ҫ��һֻ�����������
			for( int i = 1; i < m ; ++i) { //����
				++it;
				if( it == monkeys.end())
					it = monkeys.begin ();
			}
			it = monkeys.erase(it); //ɾ��Ԫ�غ󣬵�����ʧЧ��
								 //Ҫ�����õ�����ָ��ɾԪ�صĺ���
			if( it == monkeys.end())
				it = monkeys.begin();
		}
		cout << monkeys.front() << endl; //front���ص�һ��Ԫ�ص�����
	}
	return 0;
}
