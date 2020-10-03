#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
#define res register int
using namespace std;
int T, R, C, ans, A[8][8]; 
bool vis[10][10];

inline bool ok(int rr, int cc) {
	for(res r=rr-1;r<=rr+1;r++) {
		for(res c=cc-1;c<=cc+1;c++) {
			if(vis[r][c]) return 0;
		}
	}
	return 1;
}

void dfs(int r, int c, int val) {
	ans = Max(ans, val);
	if(c>C) {
		c=1;
		r++;
		if(r>R) return;
	}
	if(ok(r, c)) {  //选择这个点 
		vis[r][c] = 1;
		//printf("选择%d %d\n", r, c); 
		dfs(r, c+1, val+A[r][c]);
		vis[r][c] = 0;
		//printf("放回%d %d\n", r, c); 
	}
	dfs(r, c+1, val);
}

int main()
{
	res r, c;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &R, &C);
		for(r=1;r<=R;r++) {
			for(c=1;c<=C;c++) {
				scanf("%d", &A[r][c]);
			}
		}
		memset(vis, 0, sizeof(vis)); 
		ans = 0;
		dfs(1, 2, 0); //不选 
		vis[1][1] = 1;
		dfs(1, 2, A[1][1]);  //选 
		printf("%d\n", ans);
	}
	return 0;
}
