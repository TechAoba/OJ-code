#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool vis[100000];
int ans = 0;

void dfs(int n, int cnt) {
	if(n==0) {
		if(!vis[cnt]) ans++;
		vis[cnt] = 1;
		return;
	}
	for(int i=n;i>=1;i--) {
		dfs(n-i, cnt+(n-i)*i);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	dfs(n, 0);
	printf("%d\n", ans);
	return 0;
}
