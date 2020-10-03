#include<iostream>
#include<cstdio>
#define Min(a,b) (a<b?a:b)
#include<string>
using namespace std;
const int MAXN = 100005; 
int A[MAXN], ans[MAXN*4], M, N, ans1;

inline int lc(int a) {
	return a<<1;
}
inline int rc(int a) {
	return a<<1|1;
}

inline void push_up(int p) {
	ans[p] = Min(ans[lc(p)], ans[rc(p)]);
}

void build(int p, int l, int r) {
	if(l==r) {
		ans[p] = A[l];
		return;
	}
	int mid = (l+r)>>1;
	build(lc(p), l, mid);
	build(rc(p), mid+1, r);
	push_up(p);
}

void get(int l, int r, int L, int R, int p) {
	if(l>=L && r<=R) {
		ans1 = Min(ans1, ans[p]);
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=L) get(l, mid, L, R, lc(p));
	if(mid+1<=R) get(mid+1, r, L, R, rc(p));
}

int main()
{
	scanf("%d %d", &N, &M);
	int i, l, r;
	for(i=1;i<=N;i++) scanf("%d", &A[i]);
	build(1, 1, N);
	bool ok = 0;
	while(M--) {
		scanf("%d %d", &l, &r);
		if(ok) putchar(' ');
		ok = 1;
		ans1 = 0x3f3f3f3f;
		get(1, N, l, r, 1);
		printf("%d", ans1);
	}
	return 0;
} 
