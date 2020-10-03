#include<iostream>
#include<cstdio>
#define res register int
#include<cstring>
using namespace std;
const int MAXN = 400005;
int N, M, K, cnt=0, parent[MAXN], head[MAXN], broke[MAXN], ans[MAXN];
bool Broke[MAXN];

struct Edge{
	int from, to, Next;
}edge[MAXN];

void add(int a, int b) {
	edge[++cnt].to = b;
	edge[cnt].from = a;
	edge[cnt].Next = head[a];
	head[a] = cnt;
}

inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
} 

int find(int a) {
	if(parent[a]!=a) parent[a] = find(parent[a]);
	return parent[a];
}

bool Union(int a, int b) {
	int pa = find(a), pb = find(b);
	if(pa==pb) return 0;
	parent[pa] = pb;
	return 1;
}

int main()
{
	N = read(), M = read();
	res i, j;
	for(i=0;i<N;i++) parent[i] = i;
	int a, b;
	for(i=1;i<=M;i++) {
		a = read(), b = read();
		add(a, b), add(b, a);
	}
	M*=2;
	K = read();
	int num = N - K;
	for(i=1;i<=K;i++) broke[i] = read(), Broke[broke[i]]=1;  //破坏点
	for(i=1;i<=M;i++) {  //M条边 
		if(!Broke[edge[i].from] && !Broke[edge[i].to] && Union(edge[i].from, edge[i].to)) num--;
	}
	ans[K+1] = num;
	for(i=K;i>=1;i--) {  //从最后一个点往前建造 
		Broke[broke[i]] = 0;  //修复 
		num++;
		for(j=head[broke[i]];j!=0;j=edge[j].Next) {
			int to = edge[j].to;
			if(!Broke[to] && Union(broke[i], to)) num--;
		}
		ans[i] = num;
	}
	for(i=1;i<=K+1;i++) printf("%d\n", ans[i]);
	return 0;
}
