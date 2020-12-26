//program 9.1.2.cpp ��������
#include <iostream> 
#include <string>
using namespace std;
const int LETTER_NUM = 5;
bool taken[10]; //��־���飬taken[i]��ʾ����i�Ƿ��ѱ������滻ĳ����ĸ������ռ��
int val[LETTER_NUM]; 
//val[0]��ʾ'A'���滻�ɵ����֣�val[1]��ʾ'B'���滻�ɵ����֣��Դ�����
int StringToInt( const string & s)
{  //���ַ�����s��ĸ���滻�����ֺ���������
	if( s.length() > 1 &&  val[s[0]-'A'] == 0)
		return -1;  //��ǰ��0�򷵻�-1��ʾs���Ϸ�
	int intVal = 0;
	for(int i = 0; i < s.length(); ++i)
		intVal = intVal * 10 + val[s[i]-'A'];
	return intVal;
}
int main()
{
	int n;
    string s1,s2,s3;
	cin >> n;
	while(n--) {
		cin >> s1 >> s2 >> s3;
		for(val[0] = 0; val[0] <= 9; ++ val[0]) { //������ĸA�������滻��
			taken[val[0]] = true; //�������val[0]�Ѿ���ռ�ã������������滻������ĸ
			for(val[1] = 0; val[1] <= 9; ++ val[1]) { //������ĸB�������滻��
				if( taken[val[1]]) 
					continue; //������val[1]�Ѿ���ռ�ã����������滻��ĸB 
				taken[val[1]] = true;
				for(val[2] = 0; val[2] <= 9; ++ val[2]) {
					if( taken[val[2]])
						continue;
					taken[val[2]] = true;
					for(val[3] = 0; val[3] <= 9; ++ val[3]) {
						if( taken[val[3]])
							continue;
						for(val[4] = 0; val[4] <= 9; ++ val[4]) {
							if( taken[val[4]])
								continue;
							int n1 = StringToInt(s1);
							int n2 = StringToInt(s2);
							int n3 = StringToInt(s3);
							if( n1 >= 0 && n2 >= 0 && n3 >= 0 && n1 + n2 == n3 ) {
								cout << n1 << "+" << n2 << "=" << n3 << endl;
								goto Found;
							}
						}		
						taken[val[3]] = false;
					}
					taken[val[2]] = false;
				}
				taken[val[1]] = false; //����һ������ǰ��Ҫ���������val[1]��ռ��
			} 
			taken[val[0]] = false; //����һ������ǰ��Ҫ���������val[0]��ռ��
		}
		cout << "No Solution" << endl;
Found: ;
	}
	return 0;
}

