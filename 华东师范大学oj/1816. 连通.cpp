#include<iostream>
#include<cstdio>
#include<cstring>
#define res register int
using namespace std;

const int MAXN = 1e6+10;
int head[MAXN], cnt=0, N, M;
bool vis[MAXN];

struct Edge{
	int to, Next;
}edge[MAXN];

void add(int a, int b) {
	edge[++cnt].to = b;
	edge[cnt].Next = head[a];
	head[a] = cnt;
}

inline int read() {
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x;
}

void dfs(int a) {
	if(vis[a]) return;
	vis[a] = 1;
	cnt++;
	for(res i=head[a];i!=0;i=edge[i].Next) {
		dfs(edge[i].to);
	}
}

int main()
{
	N = read(), M = read();
	res i;
	int a, b;
	for(i=1;i<=M;i++) {
		a = read(), b = read();
		add(a, b), add(b, a);
	}
	cnt = 0;
	dfs(1);
	if(cnt==N) printf("yes\n");
	else printf("no\n");
	return 0;
}
