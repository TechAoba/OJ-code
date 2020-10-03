#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 10000000+5;
bool prime[MAXN], vis[MAXN];
int pp[MAXN], cnt=0;

int main()
{
	int i, j, N, M, a;
	cin>>N>>M;
	for(i=2;i<=N;i++) {
		if(!vis[i]) pp[cnt++]=i,prime[i]=true;
		for(j=0;j<cnt&&i*pp[j]<=N;j++) {
			vis[i*pp[j]]=true;
			if(i%pp[j]==0) break;
		}
	}
	while(M--) {
		scanf("%d", &a);
		if(prime[a]) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
