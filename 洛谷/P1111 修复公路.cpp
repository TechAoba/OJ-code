#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int parent[1005], N, M;
struct Edge{
	int u, v, t;
	bool operator<(const Edge &a)const{
		return t<a.t;
	}
}edge[100005];

inline int read() {
	int x=0, f=1;
	char c = getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

int find(int a) {
	int pa=a, i=parent[a];
	while(parent[pa]!=pa) pa = parent[pa];
	while(i!=pa) {
		i=parent[a];
		parent[a] = pa;
		a = i;
	}
	return pa;
}

bool Union(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if(pa==pb) return false;
	parent[pa] = pb;
	return true;
}

int main()
{
	N=read(),M=read();
	int i, cnt = N-1, ans=-1;
	for(i=1;i<=N;i++) parent[i] = i;
	for(i=1;i<=M;i++) {
		edge[i].u = read();
		edge[i].v = read();
		edge[i].t = read();
	}
	sort(edge+1, edge+1+M);
	for(i=1;i<=M;i++) {
		//cout<<"Á´½Ó"<<edge[i].u<<"  " <<edge[i].v<<endl; 
		if(Union(edge[i].u, edge[i].v)) cnt--;
		if(cnt<=0) {
			ans = edge[i].t;
			break;
		}
	}
	cout<<ans;
	return 0;
}
