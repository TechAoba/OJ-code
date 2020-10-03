#include<iostream>
#include<cstring>
#define Max(a,b) (a>b?a:b)
using namespace std;
int A[205], dp[205][205];

int main()
{
	int ans = -1, i, j, k, N, st, en, len;
	cin>>N;
	for(i=1;i<=N;i++) {
		cin>>A[i];
		A[i+N] = A[i];
	}
	for(len=2;len<=N;len++) {  //len代表长度 
		for(st=1;st<2*N && st+len-1<2*N;st++) {  //st代表开头 
			en = st+len-1;
			//cout<<st<<"      "<<en<<endl;
			for(k=st;k<en;k++) {
				dp[st][en] = Max(dp[st][en], dp[st][k]+dp[k+1][en]+A[st]*A[k+1]*A[en+1]);
			}
		} 
	}
	//cout<<dp[1][2]<<endl;
	for(i=1;i<=N;i++) {
		ans = Max(ans, dp[i][i+N-1]);
	}
	cout<<ans<<endl;
	return 0;
 } 
