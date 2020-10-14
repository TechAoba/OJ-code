#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 10005;
int K, N, pp[MAXN], cnt=0, add[MAXN];
bool prime[MAXN], vis[MAXN];

struct Node{
	int l, r, num;
}node[MAXN];

bool cmp(Node a, Node b) {
	if(a.num<b.num) return 1;
	else if(a.num>b.num) return 0;
	else return a.l==b.l?a.r<b.r:a.l<b.l;
}

int main()
{
	scanf("%d", &K);
	int i, j;
	for(i=2;i<MAXN;i++) {
		if(!vis[i]) pp[cnt++]=i, prime[i]=1;
		for(j=0;j<cnt && i*pp[j]<MAXN;j++) {
			vis[i*pp[j]] = 1;
			if(i%pp[j]==0) break;
		}
	}
	for(i=1;i<MAXN;i++) add[i] = add[i-1]+prime[i];  //Ç°×ººÍ 
	for(int kase=0;kase<K;kase++) {
		scanf("%d", &N);
		for(i=0;i<N;i++) {
			scanf("%d %d", &node[i].l, &node[i].r);
			node[i].num = add[node[i].r] - add[node[i].l-1];
		}
		sort(node, node+N, cmp);
		printf("case #%d:\n", kase);
		for(i=0;i<N;i++) printf("%d %d\n", node[i].l, node[i].r);
	}
	return 0;
}
