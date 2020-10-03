#include<iostream>
using namespace  std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int N, M, T, tarX, tarY, ans = 0;
bool vis[10][10];

void dfs(int x, int y) {
	if(x==tarX && tarY==y) {
		ans++;
		return;
	}
	for(int i=0;i<4;i++) {
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx<1||nx>N||ny<1||ny>M || vis[nx][ny]) continue;
		vis[nx][ny] = true;
		dfs(nx, ny);
		vis[nx][ny] = false;
	}
}

int main()
{
	cin>>N>>M>>T;
	int X, Y, i, tx, ty;
	cin>>X>>Y>>tarX>>tarY;
	vis[X][Y] = true;
	for(i=0;i<T;i++) {
		cin>>tx>>ty;
		vis[tx][ty] = true;
	}
	dfs(X, Y);
	cout<<ans;
	return 0;
}
