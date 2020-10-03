#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm> 
using namespace std;
int parent[5005];

struct Edge{
	int u, v, l;
	Edge(int u, int v, int l):u(u),v(v),l(l){}
};
vector<Edge> V;
bool cmp(Edge a,Edge b) {
	return a.l<b.l;
}

int read() {
	bool flag = false;
	char c = getchar();
	int num = 0;
	while((c<'0'||c>'9') && c!='-') c = getchar();
	if(c=='-') flag = true, c=getchar();
	while(c>='0'&&c<='9') num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return flag?-num:num;
}

int find(int a) {
	int pa=a, i;
	while(parent[pa]!=pa) pa=parent[pa];
	while(a!=pa) {
		i=parent[a];
		parent[a] = pa;
		a=i;
	}
	return pa;
}

bool Union(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if(pa==pb) return false;  //属于同一棵树 
	parent[pa]=pb;
	return true;
}

int main()
{
	int i, N, M, cnt=0, ans=0, a, b, l;
	N=read(), M=read();  //M条边 
	for(i=1;i<=N;i++) parent[i] = i;
	for(i=0;i<M;i++) {
		a=read(), b=read(), l=read();
		V.push_back(Edge(a,b,l));
	}
	sort(V.begin(),V.end(),cmp);
	for(i=0;i<M;i++) {
		if(Union(V[i].u, V[i].v)) {
			cnt++;
			ans+=V[i].l;
		}
		if(cnt==N-1) break;
	}
	cout<<ans<<endl;
	return 0;
}
