#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100005;
int Left[MAXN], Right[MAXN];

void Link(int a, int b) {
	Right[a] = b; Left[b] = a;
}

int main()
{
	int N, M, kase = 0, i, op, inv, X, Y;
	while(scanf("%d%d", &N, &M)==2) {
		for(i=1;i<=N;i++) {
			Left[i] = i-1;
			Right[i] = i+1;
		}
		Right[N] = 0; Right[0]=1; Left[0] = N;
		inv = 0;
		
		while(M--) {
			scanf("%d", &op);
			if(op==4) inv = !inv;
			else {
				scanf("%d %d", &X, &Y);
				if(op==3 && Right[Y]==X) swap(X, Y);
				if(op!=3 && inv) op = 3-op;
				if(op==1 && X==Left[Y] || op==2  && X==Right[Y]) continue;
				
				int LX=Left[X], RX = Right[X], LY = Left[Y], RY = Right[Y];
				if(op==1) Link(LX, RX), Link(LY, X), Link(X, Y);
				else if(op==2) Link(LX, RX), Link(Y, X), Link(X, RY);
				else if(op==3) {
					if(Right[X]==Y) Link(LX, Y), Link(Y, X), Link(X, RY);
					else Link(LX, Y), Link(Y, RX), Link(LY, X), Link(X, RY); 
				} 
			}
		}
		int b = 0;
		long long ans=0;
		for(i=1;i<=N;i++) {
			b = Right[b];
			if(i&1) ans+=b;
		}
		if(inv && N%2==0) ans = (long long)N*(N+1)/2 - ans;
		printf("Case %d: %lld\n", ++kase, ans);
	}
	return 0;
 } 
