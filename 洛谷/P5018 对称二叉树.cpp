#include<iostream>
#include<cstdio>
#define Max(a,b) (a>b?a:b)
using namespace std;
const int MAXN = 1e6+10;
int val[MAXN], lson[MAXN], rson[MAXN], N, num[MAXN], ans=0;  //num[i]代表i号节点的子树所有节点个数 

inline int read(){
	int x=0, f=1;
	char c = getchar();
	while(c<'0' || c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

inline int dfs(int x) {
	num[x]=1;
	if(lson[x]!=-1) {
		num[x]+=dfs(lson[x]);
	}
	if(rson[x]!=-1) {
		num[x]+=dfs(rson[x]);
	}
	return num[x];
}

inline bool check(int a, int b) {  //检查以a和b为根的子树是否对称 
	if(a==-1 && b==-1) return true;
	if(a!=-1 && b!=-1 && val[a]==val[b] && check(lson[a], rson[b]) && check(rson[a], lson[b])) return true;
	return false;
}

int main()
{
	N=read();
	int i;
	for(i=1;i<=N;i++) val[i]=read();
	for(i=1;i<=N;i++) lson[i]=read(),rson[i]=read();
	dfs(1);
	for(i=1;i<=N;i++) {
		if(check(lson[i], rson[i])) ans = Max(ans, num[i]);
	}
	cout<<ans<<endl;
	return 0;
}
