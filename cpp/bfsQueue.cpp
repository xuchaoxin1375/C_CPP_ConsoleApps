#include <iostream>
#include <cstring>
#include <queue>//include the STL to help us write the program.

/* 500年前，Jesse是我国最卓越的剑客。他英俊潇洒，而且机智过人^_^。

突然有一天，Jesse心爱的公主被魔王困在了一个巨大的迷宫中。Jesse听说这个消息已经是两天以后了，他知道公主在迷宫中还能坚持T天，他急忙赶到迷宫，开始到处寻找公主的下落。 时间一点一点的过去，Jesse还是无法找到公主。最后当他找到公主的时候，美丽的公主已经死了。从此Jesse郁郁寡欢，茶饭不思，一年后追随公主而去了。T_T 500年后的今天，Jesse托梦给你，希望你帮他判断一下当年他是否有机会在给定的时间内找到公主。
他会为你提供迷宫的地图以及所剩的时间T。请你判断他是否能救出心爱的公主。

题目包括多组测试数据。 每组测试数据以三个整数N,M,T(00)开头，分别代表迷宫的长和高，以及公主能坚持的天数。 紧接着有M行，N列字符，由"."，"*"，"P"，"S"组成。其中 "." 代表能够行走的空地。 "*" 代表墙壁，Jesse不能从此通过。 "P" 是公主所在的位置。 "S" 是Jesse的起始位置。 每个时间段里Jesse只能选择“上、下、左、右”任意一方向走一步。 输入以0 0 0结束。

如果能在规定时间内救出公主输出“YES”，否则输出“NO”。

样例输入:

4 4 10
....
....
....
S**P
样例输出:

YES
解题思路:

利用队列实现广度优先搜索法

实现3个矩阵,
map一个用来保存地图各位置的情况(map)

一个用来保存点是否访问(visit)

最后一个用来保存走到各点的距离(distance) */
using namespace std;
int dir[4][2] = { 0,1,0,-1,-1,0,1,0 };   //上,下,左,右(direction)

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
	cin >> n >> m >> k; //n表宽,m表长,k表时间
	memset(mmap, 0, sizeof(mmap));
	memset(visited, 0, sizeof(visited));
	memset(dis, 0, sizeof(dis));
	bool flag = false;
 
	int sx, sy;  //初始位置
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
 
	//初始元素入队
	step statPoint{ sx,sy };
	visited[sx][sy] = true;
	qque.push(statPoint);
 
	while (!qque.empty()) {
		step currentPoint = qque.front();
		qque.pop();
		//去访问下面的四个点
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