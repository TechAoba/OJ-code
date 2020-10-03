#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int st = 2, en = 13, MAXN = 10005;
bool vis[30], edge[30][30], ok;
char s[MAXN];

void dfs(int u) {
	if(u==en || ok) {
		ok = true;
		return;
	}
	vis[u] = true;
	for(int i=1;i<27;i++) {
		if(edge[u][i] && !vis[i]) {
			dfs(i);
			if(ok) return;
		}
	}
}

int main()
{
	while(scanf("%s", s) != EOF) {
		memset(vis, 0, sizeof(vis));
		memset(edge, 0, sizeof(edge));
		int len = strlen(s);
		edge[s[0]-96][s[len-1]-96] = 1;
		while(scanf("%s", s) != EOF) {
			if(strcmp("0", s) == 0) break;
			len = strlen(s);
			edge[s[0]-96][s[len-1]-96] = 1;
		}
		ok = false;
		dfs(st);
		if(ok) printf("Yes.\n");
		else printf("No.\n");
	}
	return 0;
}
