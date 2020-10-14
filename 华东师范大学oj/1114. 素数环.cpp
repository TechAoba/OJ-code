#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define res register int
using namespace std;
const int MAXN = 40;
int pp[MAXN], cnt=0, A[20], N;
bool prime[MAXN], vis[MAXN];
vector<int> V[MAXN];

void dfs(int now) {
	res i, j, t;
	if(now==N) {
		for(i=2;i<=N;i++) {
			if(!vis[i] && prime[i+A[N-1]] && prime[i+1]) {
				for(j=1;j<N;j++) printf("%d ", A[j]);
				printf("%d\n", i);
			}
		}
		return;
	}
	for(i=0;i<V[A[now-1]].size();i++) {
		t = V[A[now-1]][i];
		if(!vis[t]) {
			vis[t] = 1;
			A[now] = t;
			dfs(now+1);
			vis[t] = 0;
		}
	}
}

int main()
{
	res i, j;
	scanf("%d", &N);
	//for(i=1;i<=N;i++) A[i] = i;
	for(i=2;i<MAXN;i++) {
		if(!vis[i]) prime[i] = true, pp[cnt++] = i;
		for(j=0;j<cnt && i*pp[j]<MAXN;j++) {
			vis[i*pp[j]] = true;
			if(i%pp[j]==0) break;
		}
	}
	for(i=1;i<=N;i++) {
		for(j=1;j<=N;j++) {
			if(i!=j && prime[i+j] && j!=1) V[i].push_back(j);
		}
	}
	memset(vis, 0, sizeof(vis));
	A[1] = 1;
	dfs(2);
	return 0;
}
