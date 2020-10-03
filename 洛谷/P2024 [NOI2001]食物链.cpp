#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 5e4+5;
int parent[MAXN*3], N, K;

inline int read() {
	int x=0;
	char c = getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x;
}

int find(int a) {
	if(parent[a]!=a) parent[a] = find(parent[a]);
	return parent[a];
}
void Union(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	parent[pa] = pb;
}

int main()
{
	N = read(); K = read();
	int i, op, a, b, ans=0, en=3*N;
	for(i=1;i<=en;i++) parent[i] = i;
	for(i=0;i<K;i++) {
		op = read(), a = read(), b = read();
		if(a>N || b>N) {ans++;continue;}
		if(op==1) {  //a和b是同类 
			if(find(a+N)==find(b) || find(a+2*N)==find(b)) {ans++;continue;}
			Union(a, b), Union(a+N, b+N), Union(a+2*N, b+2*N);
		}
		else if(op==2) {
			if(a==b || find(a)==find(b) || find(a+2*N)==find(b)) {ans++;continue;}
			Union(b, a+N), Union(b+N, a+2*N), Union(b+2*N, a);
		}
	}
	printf("%d\n", ans);
	return 0;
}
