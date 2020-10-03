#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
using namespace std;
const int MAXN = 105;
int deep[MAXN], num[MAXN], head[MAXN], N, cnt=0, fa[MAXN][15], maxDeep=0, maxWidth=0;
struct Edge{
	int to, Next;
}edge[MAXN];
void add(int a, int b) {
	edge[++cnt].to = b;
	edge[cnt].Next = head[a];
	head[a] = cnt;
}

void dfs(int now, int father) {
	deep[now] = deep[father]+1;  //处理深度
	fa[now][0] = father;
	int i;
	for(i=1;i<10 && deep[now]>(1<<i);i++) {  //倍增的灵魂 
		fa[now][i] = fa[fa[now][i-1]][i-1];
	}
	for(i=head[now];i!=0;i=edge[i].Next) {
		int to = edge[i].to;
		if(to!=father) {
			dfs(to, now);
		}
	}
}

int LCA(int a, int b) {  //使用倍增获得公共祖先 
	if(deep[a]<deep[b]) swap(a, b);  //a的深度>b的深度
	int i;
	for(i=10;i>=0;i--) {
		if(deep[a]-(1<<i)>=deep[b]) {
			a = fa[a][i];
		}
	} 
	if(a==b) return a;
	for(i=10;i>=0;i--) {  //一起爬树  
		if(fa[a][i] != fa[b][i]) {
			a = fa[a][i];
			b = fa[b][i];
		}
	}
	return fa[a][0];
}

int main()
{
	scanf("%d", &N);
	int i, a, b;
	for(i=1;i<N;i++) {
		scanf("%d %d", &a, &b);
		add(a, b);
		add(b, a);
	}
	dfs(1, 0);
	for(i=1;i<=N;i++) maxDeep = Max(maxDeep, deep[i]);  //得到最大的深度
	for(i=1;i<=N;i++) num[deep[i]]++;  //统计宽度
	for(i=1;i<=maxDeep;i++) maxWidth = Max(maxWidth, num[i]);  //得到最大的宽度 
	scanf("%d %d", &a, &b);
	int lca = LCA(a, b);
	printf("%d\n%d\n%d\n", maxDeep, maxWidth, 2*(deep[a]-deep[lca])+(deep[b]-deep[lca]));
	return 0;
}
