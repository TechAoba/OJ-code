#include<iostream>
#include<cstring>
#include<cstdio>
#define Max(a,b) (a>b?a:b)
using namespace std;
int N, S, M, A[25], ans=0;
bool sel[25], dp[2005];

void fun() {
	memset(dp, 0, sizeof(dp));
	dp[0] = true;
	int i, j, T=0, tot=0;
	for(i=1;i<=N;i++) {
		if(sel[i]) continue;
		tot += A[i];
		for(j=tot;j>=A[i];j--) {
			if(!dp[j] && dp[j-A[i]]) T++, dp[j]=true;
		}
	}
	ans = Max(ans, T);
}

void dfs(int cur, int cnt) {
	if(cur>N && cnt<M) return;
	if(cnt==M) {
		fun();
		return;
	}
	for(int i=cur;i<=N;i++) {
		sel[i] = true;
		dfs(i+1, cnt+1);
		sel[i] = false;
	}
}

int main()
{
	cin>>N>>M;
	S = N-M;
	int i;
	for(i=1;i<=N;i++) cin>>A[i];
	dfs(1, 0);
	cout<<ans<<endl;
	return 0;
}
