#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 1e4+10;
bool prime[MAXN], vis[MAXN];
int cnt, pp[MAXN];

void primeSelect(int N) {
	int i, j;
	cnt = 0;
	for(i=2;i<=N;i++) {
		if(!vis[i]) prime[i] = true, pp[cnt++] = i;
		for(j=0;j<cnt&&i*pp[j]<=N;j++) {
			vis[i*pp[j]] = true;
			if(i%pp[j]==0) break;
		}
	}
}

int main()
{
	int N;
	cin>>N;
	primeSelect(N);
	for(int i=0;i<cnt;i++) printf("%d%c", pp[i], i==cnt-1?'\n':' ');
	return 0;
}
