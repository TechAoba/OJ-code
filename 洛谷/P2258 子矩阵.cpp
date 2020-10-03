#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#define Min(a,b) (a<b?a:b)
using namespace std;
int A[17][17], hang[17], N, M, R, C, dp[17][17];  //dp[i][j]����ǰi��ѡ��j�н��м������Сֵ 
const int INF = 0x3f3f3f3f;
int ans = INF;

inline int add1(int a, int b) {  //a, b�к���Ĳ� 
	int sum=0;
	for(int i = 1; i <= R; i++) {
		sum += abs(A[hang[i]][a] - A[hang[i]][b]);
	}
	return sum;
}

inline int add2(int a) {  //a������Ĳ� 
	int sum=0;
	for(int i = 1; i < R; i++) {
		sum += abs(A[hang[i]][a] - A[hang[i+1]][a]);
	}
	return sum;
}

void fun() {  //dp����C�� 
	int i, j, k;
	for(i=1;i<=17;i++) {  //��ʼ��Ϊ����� 
		for(j=1;j<=17;j++) {
			dp[i][j] = INF;
		}
	}
	for(i=1;i<=M;i++) {  //ǰM��  
		for(j=1;j<=C;j++) {  //ѡ��j�� 
			if(j==1) {
				dp[i][j] = add2(i);
			}
			else {
				for(k=j-1;k<i;k++) {
					dp[i][j] = Min(dp[i][j], dp[k][j-1]+add1(k, i)+add2(i));
				}
			}
		}
	}
	/*if(hang[1]==3 && hang[2]==5) {
		for(i=1;i<=M;i++) {
			for(j=1;j<=C;j++) {
				cout<<i<<"  "<<j<<"  "<<dp[i][j]<<endl;
			}
		}
	}*/
	for(i=C;i<=M;i++) {
		//if(dp[i][C]==0) cout<<hang[1]<<"  "<<hang[2]<<"   "<<i<<"   "<<C<<endl;
		ans = Min(ans, dp[i][C]);
	}
}

void dfs(int cur, int cnt, int tar) {  //ѡ��R�� 
	if(cur>N && cnt<tar) return;  //δ��� 
	if(cnt==tar) {  //��� 
		fun();
		return;
	}
	for(int i=cur;i<=N;i++) {
		hang[cnt+1] = i;
		dfs(i+1, cnt+1, tar);
	}
}

int main()
{
	memset(A, 0, sizeof(A));
	cin>>N>>M>>R>>C;
	int i, j;
	for(i=1;i<=N;i++) {
		for(j=1;j<=M;j++) {
			scanf("%d", &A[i][j]);
		}
	}
	dfs(1, 0, R);
	cout<<ans<<endl;
	return 0;
} 
