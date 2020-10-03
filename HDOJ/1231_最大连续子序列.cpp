#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b)(a>b?a:b)
using namespace std;
int N, A[10005], st[10005], dp[10005];

inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

int main()
{
	while(1) {
		N = read();
		if(N<1) break;
		int i, Tmax=-1;
		memset(dp, 0, sizeof(dp));
		memset(st, 0, sizeof(st));
		for(i=1;i<=N;i++) {
			A[i] = read();
			Tmax=Max(Tmax, A[i]);
			st[i] = i;
		}
		if(Tmax<0) {  //全为负数 
			printf("0 %d %d\n", A[1], A[N]);
			continue;
		}
		dp[1] = A[1];
		int ans_st=1, ans_en=1;
		Tmax = A[1];
		for(int i=2;i<=N;i++) {
			if(dp[i-1]>0) {  //加上前面的 
				dp[i] = dp[i-1]+A[i];
				st[i] = st[i-1];
			}
			else {
				dp[i] = A[i];
			}
			if(dp[i]>Tmax) {
				ans_st = st[i];
				ans_en = i;
				Tmax = dp[i];
			}
		}
		printf("%d %d %d\n", Tmax, A[ans_st], A[ans_en]);
	}
	return 0;
}
