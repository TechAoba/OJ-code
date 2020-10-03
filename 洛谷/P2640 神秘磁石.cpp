#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 1e4+10;
int pp[MAXN], cnt = 0, N, K;
bool vis[MAXN], prime[MAXN];

void Init() {
	for(int i=2;i<MAXN;i++) {
		if(!vis[i]) pp[cnt++]=i, prime[i] = 1;
		for(int j=0;j<cnt && i*pp[j]<MAXN;j++) {
			vis[i*pp[j]] = 1;
			if(i%pp[j]==0) break;
		}
	}
}

int main()
{
	Init();
	scanf("%d %d", &N, &K);
	bool ok = 0;
	for(int i=0;i<cnt;i++) {
		int now = pp[i];
		if(now+K>N) break;
		if(prime[now+K]) printf("%d %d\n", now, now+K), ok=1; 
	}
	if(!ok) puts("empty");
	return 0;
}
