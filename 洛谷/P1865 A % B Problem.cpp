#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN = 1000000+5;
int pp[MAXN], num[MAXN], cnt=0;
bool prime[MAXN], vis[MAXN];

int main()
{
	memset(num,0,sizeof(num));
	int l, r, m, K, i, j;
	cin>>K>>m;
	for(i=2;i<=m;i++) {
		if(!vis[i]) prime[i]=true,pp[cnt++]=i;
		for(j=0;j<cnt&&i*pp[j]<=m;j++) {
			vis[i*pp[j]]=true;
			if(i%pp[j]==0) break;
		}
	}
	for(i=2;i<MAXN;i++) num[i] = prime[i]?num[i-1]+1:num[i-1];
	while(K--) {
		cin>>l>>r;
		if(l<1||l>m||r<1||r>m) printf("Crossing the line\n");
		else if(l>r) printf("0\n");
		else {
			printf("%d\n", prime[l]?num[r]-num[l]+1:num[r]-num[l]);
		}
	}
	return 0;
}
