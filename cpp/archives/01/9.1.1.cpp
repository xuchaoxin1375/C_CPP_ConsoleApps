//program 9.1.1.cpp //����ѭ����˻ʺ�����
#include <iostream> 
#include <cmath>
using namespace std;
bool Valid(int row,int pos[]) //��row�лʺ�İڷ����Ƿ��ǰ��ĳ�ͻ
{
	for( int i = 0; i < row; ++ i)
			if( pos[row] == pos[i] || abs(row-i) == abs(pos[row]-pos[i]))
				return false; //��ͻ
	return true; //����ͻ
}
int main()
{
	int pos[8]; // 8 ���ʺ�ڷŵ�λ��,���ж���0��ʼ��
	for(pos[0] = 0;pos[0] < 8; ++ pos[0]) 
		for(pos[1] = 0;pos[1] < 8; ++ pos[1]) {
			if( !Valid(1,pos)) //����ǰ�ڷ��Ѿ���ǰ��Ļʺ��ͻ��������һ�ڷ�
				continue;
			for(pos[2] = 0;pos[2] < 8; ++ pos[2]) {
				if( !Valid(2,pos))
					continue;
				for(pos[3] = 0;pos[3] < 8; ++ pos[3]) {
					if( !Valid(3,pos))
						continue;
					for(pos[4] = 0;pos[4] < 8; ++ pos[4]) {
						if( !Valid(4,pos))
							continue;
						for(pos[5] = 0;pos[5] < 8; ++ pos[5]) {
							if( !Valid(5,pos))
								continue;
							for(pos[6] = 0;pos[6] < 8; ++ pos[6]) {
								if( !Valid(6,pos))
									continue;
								for(pos[7] = 0;pos[7] < 8; ++ pos[7]) {
									if( Valid(7,pos)) {
										for(int k = 0;k < 8; ++k)
											cout << pos[k] << " " ;
										cout << endl;
									}
								}
							}
						}
					}
				}
			}
		}
	return 0;
}

