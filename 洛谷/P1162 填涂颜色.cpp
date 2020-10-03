#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
int A[35][35], N;
bool ok[35][35], vis[35][35], flag;
struct Node{
	int x, y;
};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int x, int y) {
	queue<Node> Q;
	Q.push(Node{x, y});
	while(!Q.empty()) {
		ok[x][y] = vis[x][y] = true;
		Node tmp = Q.front(); Q.pop();
		for(int i=0;i<4;i++) {
			int nx = tmp.x+dx[i];
			int ny = tmp.y+dy[i];
			if(nx<1||nx>N||ny<1||ny>N || A[nx][ny]==1 || vis[nx][ny]) continue;
			if(nx==1 || nx==N || ny==1 || ny==N) {
				flag = false;
			}
			ok[nx][ny] = vis[nx][ny] = true;
			Q.push(Node{nx, ny});
		}
	}
}

int main()
{
	int i, j;
	cin>>N;
	for(i=1;i<=N;i++) {
		for(j=1;j<=N;j++) {
			cin>>A[i][j];
		}
	}
	for(i=1;i<=N;i++) {
		for(j=1;j<=N;j++) {
			if(A[i][j]==1 || ok[i][j]) continue;
			memset(vis, false, sizeof(vis));
			flag = true;
			bfs(i, j);
			if(flag) break;
		}
		if(flag) break;
	}
	for(i=1;i<=N;i++) {
		for(j=1;j<=N;j++) {
			if(vis[i][j]) printf("2%c", j==N?'\n':' ');
			else printf("%d%c", A[i][j], j==N?'\n':' ');
		}
	}
	return 0;
}
