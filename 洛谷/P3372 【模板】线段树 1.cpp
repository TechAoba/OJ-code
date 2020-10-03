#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
const int MAXN = 100001;
inline LL read() {
	LL x=0, f=1;
	char c = getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

LL A[MAXN], ans[MAXN*4], tag[MAXN*4], N, M;

inline LL lc(LL a) {  //返回左孩子 
	return a<<1;
}
inline LL rc(LL a) {  //返回右孩子 
	return a<<1|1;
}

inline void push_up(LL p) {  //p节点向上推 
	ans[p] = ans[lc(p)] + ans[rc(p)];
}

void build(LL l, LL r, LL p) {  //建树 
	if(l==r) {ans[p] = A[l];return;}
	LL mid = (l+r)>>1;
	build(l, mid, lc(p));
	build(mid+1, r, rc(p));
	push_up(p);
}

inline void add(LL l, LL r, LL p, LL d) {
	ans[p] += d*(r-l+1);
	tag[p] += d;
}

inline void push_down(LL l, LL r, LL p) {
	LL mid = (l+r)>>1;
	add(l, mid, lc(p), tag[p]);
	add(mid+1, r, rc(p), tag[p]);
	tag[p] = 0;
}

inline void update(LL L, LL R, LL l, LL r, LL p, LL d) {  //L 和 R为目标范围 
	if(l>=L && r<=R) {
		add(l, r, p, d);
		return;
	}
	LL mid = (l+r)>>1;
	push_down(l, r, p);
	if(L<=mid) update(L, R, l, mid, lc(p), d);
	if(mid+1<=R) update(L, R, mid+1, r, rc(p), d);
	push_up(p);
}

inline LL get(LL L, LL R, LL l, LL r, LL p) {
	if(l>=L && r<=R) return ans[p];
	LL sum = 0, mid = (l+r)>>1;
	push_down(l, r, p);
	if(L<=mid) sum += get(L, R, l, mid, lc(p));
	if(mid+1<=R) sum += get(L, R, mid+1, r, rc(p));
	return sum;
}

int main()
{
	N = read(), M = read();
	int i, op, l, r, d;
	for(i=1;i<=N;i++) A[i] = read();
	build(1, N, 1);
	for(i=1;i<=M;i++) {
		op = read();
		if(op==1) {  //加 
			l=read(), r=read(), d=read();
			update(l, r, 1, N, 1, d);
		}
		else {  //查询 
			l=read(), r=read();
			printf("%lld\n", get(l, r, 1, N, 1));
		}
	}
	return 0;
}
