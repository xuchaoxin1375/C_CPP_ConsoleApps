//program 20.6.2.cpp unordered_mapʾ��
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
     unordered_map<string,int> turingWinner; //ͼ�齱������
	turingWinner.insert(make_pair("Dijkstra",1972));
	turingWinner.insert(make_pair("Scott",1976));
	turingWinner.insert(make_pair("Wilkes",1967));
	turingWinner.insert(make_pair("Hamming",1968));
     turingWinner["Ritchie"] = 1983;
	string name;
	cin >> name; //��������
	unordered_map<string,int>::iterator p = turingWinner.find(name);//���������ʱ��
	if( p != turingWinner.end())
		cout << p->second;
	else
		cout << "Not Found" << endl;
	return 0;
}

