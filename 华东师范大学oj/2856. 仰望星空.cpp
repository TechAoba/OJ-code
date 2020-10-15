#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool vis[1005][85];
char Map[1005][85];
int R, C, ans;

void dfs(int r, int c) {
	vis[r][c] = true;
	for(int nr=r-1;nr<=r+1;nr++) {
		if(nr<0 || nr>=R) continue;
		for(int nc=c-1;nc<=c+1;nc++) {
			if(nc<0 || nc>=C) continue;
			if(!vis[nr][nc] && Map[nr][nc]=='*') dfs(nr, nc);
		}
	}
}

int main()
{
	int r, c;
	while(scanf("%d %d", &C, &R) != EOF) {
		memset(vis, false, sizeof(vis));
		ans = 0;
		for(r=0;r<R;r++) scanf("%s", Map[r]);
		for(r=0;r<R;r++) {
			for(c=0;c<C;c++) {
				if(!vis[r][c] && Map[r][c] == '*') {
					ans++;
					dfs(r, c);
				}
			} 
		}
		cout<<ans<<endl;
	}
	
	
	return 0; 
}
