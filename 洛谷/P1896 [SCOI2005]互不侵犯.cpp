#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
LL N, K, num[500], add[500], cnt=0, dp[10][500][200];

LL fun1(int a) {
	LL ans = 0;
	while(a) {
		if(a&1) ans++;
		a>>=1; 
	} 
	return ans;
}

int main()
{
	memset(dp, 0, sizeof(dp));
	scanf("%lld %lld", &N, &K);
	LL i, j, k, l;
	for(i=0;i<(1<<N);i++) {
		if(!(i&(i<<1))) {
			num[cnt] = i;
			add[cnt] = fun1(i);
			//printf("符合情况的为%d,1的个数为%d\n", num[cnt], add[cnt]);
			cnt++;
		}
	}
	for(i=0;i<cnt;i++) {
		dp[1][i][add[i]] = 1;
	}
	for(k=2;k<=N;k++) {
		for(i=0;i<cnt;i++) {  //这一排布局的情况 
			for(j=0;j<cnt;j++) {  //上一排布局的情况
				if(!(num[i]&num[j]) && !((num[i]<<1)&num[j]) && !((num[j]<<1)&num[i])) {  //符合情况 
					//printf("第%d和%d\n", i, j);
					for(l=0;l<=K;l++) {
						dp[k][i][l+add[i]] += dp[k-1][j][l];
					}
				}
			}
		}
	}
	LL ans = 0;
	for(i=0;i<cnt;i++) ans += dp[N][i][K];
	printf("%lld\n", ans);
	return 0;
} 
