#include <iostream>
#include <cstring>
#include <queue>//include the STL to help us write the program.

/* 500��ǰ��Jesse���ҹ���׿Խ�Ľ��͡���Ӣ�����������һ��ǹ���^_^��

ͻȻ��һ�죬Jesse�İ��Ĺ�����ħ��������һ���޴���Թ��С�Jesse��˵�����Ϣ�Ѿ��������Ժ��ˣ���֪���������Թ��л��ܼ��T�죬����æ�ϵ��Թ�����ʼ����Ѱ�ҹ��������䡣 ʱ��һ��һ��Ĺ�ȥ��Jesse�����޷��ҵ�������������ҵ�������ʱ�������Ĺ����Ѿ����ˡ��Ӵ�Jesse�����ѻ����跹��˼��һ���׷�湫����ȥ�ˡ�T_T 500���Ľ��죬Jesse���θ��㣬ϣ��������ж�һ�µ������Ƿ��л����ڸ�����ʱ�����ҵ�������
����Ϊ���ṩ�Թ��ĵ�ͼ�Լ���ʣ��ʱ��T�������ж����Ƿ��ܾȳ��İ��Ĺ�����

��Ŀ��������������ݡ� ÿ�������������������N,M,T(00)��ͷ���ֱ�����Թ��ĳ��͸ߣ��Լ������ܼ�ֵ������� ��������M�У�N���ַ�����"."��"*"��"P"��"S"��ɡ����� "." �����ܹ����ߵĿյء� "*" ����ǽ�ڣ�Jesse���ܴӴ�ͨ���� "P" �ǹ������ڵ�λ�á� "S" ��Jesse����ʼλ�á� ÿ��ʱ�����Jesseֻ��ѡ���ϡ��¡����ҡ�����һ������һ���� ������0 0 0������

������ڹ涨ʱ���ھȳ����������YES�������������NO����

��������:

4 4 10
....
....
....
S**P
�������:

YES
����˼·:

���ö���ʵ�ֹ������������

ʵ��3������,
mapһ�����������ͼ��λ�õ����(map)

һ������������Ƿ����(visit)

���һ�����������ߵ�����ľ���(distance) */
using namespace std;
int dir[4][2] = { 0,1,0,-1,-1,0,1,0 };   //��,��,��,��(direction)

char mmap[101][101];//simulate the positions of the map.
int visited[101][101];//record the point(position) whether has been visited.
int dis[101][101];//
struct step
{
	int x;
	int y;
};
 
int main() {
	
	queue<step> qque;
	int n, m, k;  
	cin >> n >> m >> k; //n���,m��,k��ʱ��
	memset(mmap, 0, sizeof(mmap));
	memset(visited, 0, sizeof(visited));
	memset(dis, 0, sizeof(dis));
	bool flag = false;
 
	int sx, sy;  //��ʼλ��
	int px, py;
 
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> mmap[i][j];
			if (mmap[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			if (mmap[i][j] == 'P') {
				px = i;
				py = j;
			}
		}
	}
 
	//��ʼԪ�����
	step statPoint{ sx,sy };
	visited[sx][sy] = true;
	qque.push(statPoint);
 
	while (!qque.empty()) {
		step currentPoint = qque.front();
		qque.pop();
		//ȥ����������ĸ���
		for (int i = 0; i < 4; ++i) {
			int nextX = currentPoint.x + dir[i][0];
			int nextY = currentPoint.y + dir[i][1];
 
			if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && mmap[nextX][nextY] != '*' && !visited[nextX][nextY]) {
				 dis[nextX][nextY] = dis[currentPoint.x][currentPoint.y] + 1;
				 step nextPoint{ nextX,nextY };
				 visited[nextX][nextY] = true;
				 qque.push(nextPoint);
			}
		}
	}
	
	if (dis[px][py] > k || dis[px][py] == 0) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
 
	return 0;
}