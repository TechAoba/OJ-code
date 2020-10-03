#include<iostream>
#include<cstdio>
#define lowbit(i) (-i&i) 
using namespace std;
const int MAXN = 5e5+10;
int N, M, tree[MAXN];

void add(int a, int x) {
	while(a<=N) {
		tree[a] += x;
		a += lowbit(a);
	}
}

int sum(int a) {
	int ans = 0;
	while(a!=0) {
		ans += tree[a];
		a -= lowbit(a);
	}
	return ans;
}

int main()
{
	int i, t, op, a, b;
	scanf("%d %d", &N, &M);
	for(i=1;i<=N;i++) {
		scanf("%d", &t);
		add(i, t);
	}
	for(i=1;i<=M;i++) {
		scanf("%d %d %d", &op, &a, &b);
		if(op==1) {
			add(a, b);
		}
		else if(op==2) {
			printf("%d\n", sum(b)-sum(a-1));
		}
	}
	return 0;
}
