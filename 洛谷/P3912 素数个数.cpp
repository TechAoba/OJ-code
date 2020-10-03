#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int MAXN = 1e8+10;
int pp[5800000], cnt=0, N;
bool vis[MAXN];

void fun1() {
	register int i, j;
	for(i=2;i<=N;i++) {
		if(!vis[i]) pp[++cnt] = i;
		for(j=1;j<=cnt && i*pp[j]<=N;j++) {
			vis[i*pp[j]] = 1;
			if(i%pp[j]==0) break;
		}
	}
}

/*void fun2() {
	int m = sqrt(MAXN+0.5);
	for(int i=2;i<=m;i++) if(!prime[i])
		for(int j=i*i;j<MAXN;j+=i) prime[j] = 1;
}*/

int main()
{
	int ans = 0;
	scanf("%d", &N);
	fun1();
	printf("%d\n", cnt);
	return 0;
}
