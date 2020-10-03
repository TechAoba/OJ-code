#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int ans[1000010], N, M, cur=0;
bool vis[1005][1005];
int val[1005][1005];  //val用来存i，j元素对应的序号cur
char A[1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct Node{
	int x, y;
};

void bfs(int X, int Y) {
	queue<Node> Q;
	Q.push(Node{X, Y});
	vis[X][Y] = true;
	val[X][Y] = cur;
	int cnt = 1;
	while(!Q.empty()) {
		Node tmp = Q.front(); Q.pop();
		for(int i=0;i<4;i++) {
			int nx = tmp.x+dx[i];
			int ny = tmp.y+dy[i];
			if(nx<1||nx>N||ny<1||ny>N || vis[nx][ny]) continue;
			if(A[tmp.x][tmp.y] == A[nx][ny]) continue;
			cnt++;
			val[nx][ny] = cur;
			vis[nx][ny] = true;
			Q.push(Node{nx, ny});
		}
	}
	ans[cur] = cnt;
}

int main()
{
	cin>>N>>M;
	int i, j, x, y;
	for(i=1;i<=N;i++) {
		scanf("%s", A[i]+1);
	}
	for(i=1;i<=N;i++) {
		for(j=1;j<=N;j++) {
			if(!vis[i][j]) {
				bfs(i, j);
				cur++;
			}
		}
	}
	for(i=1;i<=M;i++) {
		scanf("%d %d", &x, &y);
		printf("%d\n", ans[val[x][y]]);
	}
	return 0;
}
