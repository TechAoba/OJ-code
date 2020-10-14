#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 100005;
bool vis[MAXN];
int V[105], N[105], num[MAXN];  //num用来保存使用硬币的数量 

int main()
{
	int T, t, n, m, i, j;
	scanf("%d", &T);
	for(t=1;t<=T;t++) {
		int ans = 0;
		memset(vis, false, sizeof(vis));
		vis[0] = 1;
		scanf("%d %d", &n, &m);
		for(i=0;i<n;i++) scanf("%d", &V[i]);  //价值 
		for(i=0;i<n;i++) scanf("%d", &N[i]);  //数量 
		for(i=0;i<n;i++) {  //i表示硬币的编号 
			memset(num, 0, sizeof(num));
			for(j=V[i];j<=m;j++) {  //j代表价值 
				if(!vis[j] && vis[j-V[i]] && num[j-V[i]]<N[i]) {
					num[j] = num[j-V[i]] + 1;
					vis[j] = true;
					ans++;
				}
			}
		}
		printf("Case %d: %d\n", t, ans);
	}
	return 0;
}
