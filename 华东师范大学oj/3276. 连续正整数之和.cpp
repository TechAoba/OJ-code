#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int k, i, kase, N, M;
	scanf("%d", &N);
	for(kase=1;kase<=N;kase++) {
		scanf("%d", &M);
		int ans = 0, en = M/2+1;
		for(k=2;k<=en;k++) {
			if((M*2)%k) continue;
			i = M*2/k+1-k;
			if(i>0 && !(i&1)) /*cout<<k<<endl,*/ans++;
		}
		printf("Case %d: %d\n", kase, ans);
	}
	return 0;
}
