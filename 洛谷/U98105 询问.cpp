#include<iostream>
#include<map>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 1e6+10;
int parent[MAXN];

inline int read() {
	int x=0, f=1;
	char c = getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

int find(int a) {
	if(parent[a]!=a) parent[a] = find(parent[a]);
	return parent[a];
}

bool Union(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if(pa==pb) return 0;
	parent[pa] = pb;
	return 1;
}

int main()
{
	int N, M, a, b, ans;
	N= read(), M=read();
	for(register int i=1;i<=N;i++) parent[i] = i;
	ans = N;
	while(M--) {
		a = read(), b = read();
		if(Union(a, b)) ans--;
	} 
	printf("%d\n", ans);
	return 0;
}
