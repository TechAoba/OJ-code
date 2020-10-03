#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
using namespace std;
int N, ans;
char A[10][10];
bool vis[10][10];

bool ok(int r, int c) {
	int i;
	/* 上 */
	for(i=r-1;i>=1 && A[i][c]=='.';i--) {
		if(vis[i][c]) return false;
	}
	/* 下 */
	for(i=r+1;i<=N && A[i][c]=='.';i++) {
		if(vis[i][c]) return false;
	}
	/* 左 */
	for(i=c-1;i>=1 && A[r][i]=='.';i--) {
		if(vis[r][i]) return false;
	}
	/* 右 */
	for(i=c+1;i<=N && A[r][i]=='.';i++) {
		if(vis[r][i]) return false;
	}
	return true;
}

void dfs(int r, int c, int cnt) {
	if(r==N && c==N) {  //结束 
		ans = Max(ans, cnt);
		return;
	}
	int nc = c+1, nr = r;
	if(nc>N) nc = 1, nr++;
	if(A[nr][nc] =='.' && ok(nr, nc)) {  //可选 
		vis[nr][nc] = 1;
		//printf("选择%d %d\n", nr, nc);
		dfs(nr, nc, cnt+1);
		vis[nr][nc] = 0;
		//printf("退选 %d %d\n", nr, nc);
	}
	dfs(nr, nc, cnt);
}

int main()
{
	int i;
	while(scanf("%d", &N) != EOF && N) {
		ans = 0;
		for(i=1;i<=N;i++) scanf("%s", A[i]+1);
		memset(vis, 0, sizeof(vis));
		if(A[1][1] == '.') {
			vis[1][1] = 1;
			dfs(1, 1, 1);  //选 
		}
		memset(vis, 0, sizeof(vis));
		dfs(1, 1, 0);  //不选 
		printf("%d\n", ans);
	}
	return 0;
}
