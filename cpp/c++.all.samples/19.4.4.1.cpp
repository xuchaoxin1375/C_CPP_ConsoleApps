//program 19.4.4.1 ��multimapʵ�ֵ�ѧ����Ϣ�������
#include <iostream>
#include <map> //ʹ��multimap��Ҫ������ͷ�ļ�
#include <string>
using namespace std;
class CStudent
{
public:	
		struct CInfo //����ڲ������Զ�����
		{
			int id;
			string name;
		};
		int score;
		CInfo info; //ѧ����������Ϣ
};
typedef multimap<int,CStudent::CInfo> MAP_STD;
int main()    
{
	
	MAP_STD mp;
	CStudent st;
	string cmd;
	while( cin >> cmd ) {
		if( cmd == "Add") {
			cin >> st.info.name >> st.info.id >> st.score ;
			mp.insert(MAP_STD::value_type(st.score,st.info ));
		}
		else if( cmd == "Query" ){
			int score;
			cin >> score;
			MAP_STD::iterator p = mp.lower_bound (score);
			if( p!= mp.begin()) { 
				--p;
				score = p->first; //��Ҫ��ѯ�����͵���߷�
				MAP_STD::iterator maxp = p; 
				int maxId = p->second.id; 
				for( ; p != mp.begin() && p->first == score; --p) {
					//�������гɼ���score��ȵ�ѧ��
					if( p->second.id > maxId ) {
						maxp = p;
						maxId = p->second.id ;
					}
				}
				if( p->first == score) { //�������ѭ������Ϊ p == mp.begin()
                                           // ����ֹ����pָ���Ԫ�ػ�Ҫ����
					if( p->second.id  > maxId ) {
						maxp = p;
						maxId = p->second.id ;
					}
				}
				cout << maxp->second.name << " " << maxp->second.id << " " 
                                          << maxp->first << endl;
			}
			else //lower_bound�Ľ������ begin��˵��û�˷����Ȳ�ѯ������
				cout << "Nobody" << endl;
		}
	}
	return 0;
}  

