#include<iostream>
#include<cstdio>
#include<cstring>
#define Min(a,b) (a<b?a:b)
using namespace std;
int ans=0, N, M, bl, wh;
int head[200005], cnt=0;
bool vis[20005], col[20005];
struct Edge{
	int to, next;
}edge[200005];

void add(int a, int b) {  //前向星建图 
	edge[++cnt].to = b;
	edge[cnt].next = head[a];
	head[a] = cnt;
}

bool dfs(int a, int color) {
	if(vis[a]) {
		if(col[a]==color) return true;
		else return false;
	}
	vis[a] = true;
	col[a] = color;
	if(color) wh++;
	else bl++;
	bool flag = true;
	for(int i=head[a];i!=0&&flag;i=edge[i].next) {  //遍历前向星 
		flag = dfs(edge[i].to, 1-color);
	}
	return flag;
}

int main()
{
	memset(head, 0, sizeof(head));
	int i, a, b;
	scanf("%d %d", &N, &M);
	for(i=0;i<M;i++) {
		scanf("%d %d", &a, &b);
		add(a, b), add(b, a);
	}
	for(i=1;i<=N;i++) {
		if(vis[i]) continue;
		bl = wh = 0;
		if(!dfs(i, 0)) {  //不符合 
			printf("Impossible\n");
			return 0;
		}
		ans += Min(bl, wh);
	}
	printf("%d", ans);
 	return 0;
}
