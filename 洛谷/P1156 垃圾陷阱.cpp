#include<iostream>
#include<cstring>
#include<algorithm>
#define Max(a,b) (a>b?a:b)
using namespace std;
int D, G, dp[105][200];
struct Node{
	int T, F, H;  //投入时间  维持生命  高度 
	bool operator <(const Node &a)const {
		return T<a.T;
	}
}node[105];

int main()
{
	memset(dp, -1, sizeof(dp));
	cin>>D>>G;  //D为井的高度 
	int i, j;
	node[0].T=node[0].F=node[0].H=0;
	for(i=1;i<=G;i++) {  //G个垃圾 
		cin>>node[i].T>>node[i].F>>node[i].H;
	}
	sort(node+1, node+1+G);
	dp[0][0] = 10;
	for(i=0;i<G;i++) {  //i代表商品序号 
		for(j=0;j<D;j++) {  //j代表高度 
			if(dp[i][j]<0) continue;  //死亡则剔除
			if(j+node[i+1].H>=D && dp[i][j]-(node[i+1].T-node[i].T)>=0) {  //可以逃出去 
				cout<<node[i+1].T;
				return 0;
			} 
			if(dp[i][j]-(node[i+1].T-node[i].T)>=0) {
				dp[i+1][j+node[i+1].H] = Max(dp[i+1][j+node[i+1].H], dp[i][j]-(node[i+1].T-node[i].T));//不吃 
				dp[i+1][j] = Max(dp[i+1][j], dp[i][j]-(node[i+1].T-node[i].T)+node[i+1].F);  //吃 
			}
		}
	}
	int e=0, ans=10;
	for(i=1;i<=G;i++) {
		if(node[i].T>ans) break;
		ans+=node[i].F;
	}
	cout<<ans<<endl;
	return 0;
} 
