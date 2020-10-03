#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
#define lowbit(i) (-i&i)
using namespace std;
const int MAXN = 500005;
LL tree[MAXN], A[MAXN], N, M;

inline LL read() {
	LL x=0, f=1;
	char c = getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

void add(int a, int x) {
	while(a<=N) {
		tree[a] += x;
		a += lowbit(a);
	}
}

LL sum(LL a) {
	LL ans=0;
	while(a!=0) {
		ans += tree[a];
		a -= lowbit(a);
	}
	return ans;
}

int main()
{
	LL i, a, b, x, op;
	N = read(), M = read();
	for(i=1;i<=N;i++) {
		A[i] = read();
		add(i, A[i]-A[i-1]);
	}
	for(i=1;i<=M;i++) {
		op = read();
		if(op==1) {
			a = read(), b = read(), x = read();
			add(a, x), add(b+1, -x);
		}
		else if(op==2) {
			a = read();
			printf("%lld\n", sum(a));
		}
	}
	return 0;
}
