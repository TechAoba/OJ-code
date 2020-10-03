#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio> 
#define res register int
#define lowbit(i) (-i&i)
using namespace std;
const int MAXN = 1e6+10;
int num[MAXN], tree[MAXN], pos[MAXN], ans[MAXN], N, M;

int read() {
	int x=0, f=1;
	char c=getchar();
	while(c<'0' || c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
struct Node{
	int l, r, pos;
	bool operator<(const Node &a) const{
		return r<a.r;
	}
}node[MAXN];

void add(int poi, int a) {
	while(poi<=N) {
		tree[poi] += a;
		poi += lowbit(poi);
	}
}

int sum(int poi) {
	int q = 0;
	while(poi) {
		q += tree[poi];
		poi -= lowbit(poi);
	}
	return q;
}

int main()
{
	res i, j, st=1;
	N = read();
	for(i=1;i<=N;i++) {
		num[i] = read();
	}
	M = read();
	for(i=1;i<=M;i++) {
		node[i].l = read();
		node[i].r = read();
		node[i].pos = i;
	}
	sort(node+1, node+1+M);
	for(i=1;i<=M;i++) {  //M次询问 
		for(j=st;j<=node[i].r;j++) {
			int val = num[j];
			if(pos[val]) {  //若这个值已经被加过 
				add(pos[val], -1);
			}
			add(j, 1);
			pos[val] = j;
		}
		st = node[i].r+1;
		ans[node[i].pos] = sum(node[i].r) - sum(node[i].l-1);
	}
	for(i=1;i<=M;i++) printf("%d\n", ans[i]);
	return 0;
 } 
