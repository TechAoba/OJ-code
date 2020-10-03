#include<iostream>
#include<cstdio>
#define Min(a,b) (a<b?a:b)
using namespace std;
int dp[55][55][2], N, M, poi[55], con[55], dis[55], add[55];
const int INF = 0x3f3f3f3f;

int main()
{
	scanf("%d %d", &N, &M);
	int l, r, T, i, j;
	for(i=1;i<=N;i++) {
		scanf("%d %d", &poi[i], &con[i]);
		dis[i] = poi[i] - poi[i-1];  //如dis[2]表示1到2的距离 
		add[i] = add[i-1] + con[i];
	}
	for(i=0;i<55;i++) {
		for(j=0;j<55;j++) {
			dp[i][j][0]=dp[i][j][1]=INF;
		}
	}
	T = add[N] - con[M];
	dp[M-1][M+1][0] = T*dis[M];
	dp[M-1][M+1][1] = T*dis[M+1];
	for(l=M-1;l>0;l--) {
		for(r=M+1;r<=N;r++) {
			T = add[N]-add[r-1]+add[l];
			//cout<<T<<endl;
			if(r-1>=M+1) dp[l][r][0] = Min(dp[l][r][0], dp[l][r-1][1]+(poi[r-1]-poi[l])*T);
			if(l+1<=M-1) dp[l][r][0] = Min(dp[l+1][r][0]+dis[l+1]*T, dp[l][r][0]);
			if(l+1<=M-1) dp[l][r][1] = Min(dp[l][r][1], dp[l+1][r][0]+(poi[r]-poi[l+1])*T);
			if(r-1>=M+1) dp[l][r][1] = Min(dp[l][r-1][1]+dis[r]*T, dp[l][r][1]);
			//cout<<l<<"   "<<r<<"   "<<dp[l][r][0]<<"   "<<dp[l][r][1]<<endl;
		}
	}
	for(r=M+1;r<=N;r++) {
		T = add[N]-add[r-1];
		dp[0][r][1] = Min(dp[0][r][1], dp[1][r][0]+(poi[r]-poi[1])*T);
		if(r-1>=M+1) dp[0][r][1] = Min(dp[0][r][1], dp[0][r-1][1]+dis[r]*T);
		//cout<<l<<"   "<<r<<"   "<<dp[l][r][0]<<"   "<<dp[l][r][1]<<endl;
	}
	for(l=M-1;l>0;l--) {
		T = add[l];
		dp[l][N+1][0] = Min(dp[l][N+1][0], dp[l][N][1]+(poi[N]-poi[l])*T);
		if(l+1<=M-1) dp[l][N+1][0] = Min(dp[l][N+1][0], dp[l+1][N+1][0]+dis[l+1]*T);
		//cout<<l<<"   "<<r<<"   "<<dp[l][r][0]<<"   "<<dp[l][r][1]<<endl;
	}
	cout<<Min(dp[0][N][1], dp[1][N+1][0]);
	return 0;
 } 
