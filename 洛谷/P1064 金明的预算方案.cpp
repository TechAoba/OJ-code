#include<iostream>
#define Max(a,b) (a>b?a:b)
using namespace std;
int dp[32010], v[65][3], w[65][3], N, M;  //N元  M个物品 

int main()
{
	cin>>N>>M;
	int i, j, money, val, q;
	for(i=1;i<=M;i++) {
		cin>>money>>val>>q;
		if(!q) {  //主 
			v[i][0] = money;
			w[i][0] = money*val;
		}
		else {
			if(!v[q][1]) {  //第一个附件 
				v[q][1] = money;
				w[q][1] = money*val;
			}
			else {
				v[q][2] = money;
				w[q][2] = money*val;
			}
		}
	}
	for(i=1;i<=M;i++) {
		for(j=N;j>=0;j--) {
			int need = v[i][0];
			if(need<=j) {  //只买主件 
				dp[j] = Max(dp[j], dp[j-need]+w[i][0]);
			}
			need = v[i][0]+v[i][1];
			if(need<=j) {  //买主件 和 附件1 
				dp[j] = Max(dp[j], dp[j-need]+w[i][0]+w[i][1]);
			}
			need = v[i][0]+v[i][2];
			if(need<=j) {  //买主件 和 附件2 
				dp[j] = Max(dp[j], dp[j-need]+w[i][0]+w[i][2]);
			}
			need = v[i][0]+v[i][1]+v[i][2];
			if(need<=j) {  //买主件 和 附件1  2
				dp[j] = Max(dp[j], dp[j-need]+w[i][0]+w[i][1]+w[i][2]);
			}
		}
	}
	cout<<dp[N];
	return 0;
}
