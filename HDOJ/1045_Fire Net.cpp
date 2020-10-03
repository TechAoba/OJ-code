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
	/* �� */
	for(i=r-1;i>=1 && A[i][c]=='.';i--) {
		if(vis[i][c]) return false;
	}
	/* �� */
	for(i=r+1;i<=N && A[i][c]=='.';i++) {
		if(vis[i][c]) return false;
	}
	/* �� */
	for(i=c-1;i>=1 && A[r][i]=='.';i--) {
		if(vis[r][i]) return false;
	}
	/* �� */
	for(i=c+1;i<=N && A[r][i]=='.';i++) {
		if(vis[r][i]) return false;
	}
	return true;
}

void dfs(int r, int c, int cnt) {
	if(r==N && c==N) {  //���� 
		ans = Max(ans, cnt);
		return;
	}
	int nc = c+1, nr = r;
	if(nc>N) nc = 1, nr++;
	if(A[nr][nc] =='.' && ok(nr, nc)) {  //��ѡ 
		vis[nr][nc] = 1;
		//printf("ѡ��%d %d\n", nr, nc);
		dfs(nr, nc, cnt+1);
		vis[nr][nc] = 0;
		//printf("��ѡ %d %d\n", nr, nc);
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
			dfs(1, 1, 1);  //ѡ 
		}
		memset(vis, 0, sizeof(vis));
		dfs(1, 1, 0);  //��ѡ 
		printf("%d\n", ans);
	}
	return 0;
}
