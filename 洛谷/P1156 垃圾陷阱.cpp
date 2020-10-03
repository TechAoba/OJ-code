#include<iostream>
#include<cstring>
#include<algorithm>
#define Max(a,b) (a>b?a:b)
using namespace std;
int D, G, dp[105][200];
struct Node{
	int T, F, H;  //Ͷ��ʱ��  ά������  �߶� 
	bool operator <(const Node &a)const {
		return T<a.T;
	}
}node[105];

int main()
{
	memset(dp, -1, sizeof(dp));
	cin>>D>>G;  //DΪ���ĸ߶� 
	int i, j;
	node[0].T=node[0].F=node[0].H=0;
	for(i=1;i<=G;i++) {  //G������ 
		cin>>node[i].T>>node[i].F>>node[i].H;
	}
	sort(node+1, node+1+G);
	dp[0][0] = 10;
	for(i=0;i<G;i++) {  //i������Ʒ��� 
		for(j=0;j<D;j++) {  //j����߶� 
			if(dp[i][j]<0) continue;  //�������޳�
			if(j+node[i+1].H>=D && dp[i][j]-(node[i+1].T-node[i].T)>=0) {  //�����ӳ�ȥ 
				cout<<node[i+1].T;
				return 0;
			} 
			if(dp[i][j]-(node[i+1].T-node[i].T)>=0) {
				dp[i+1][j+node[i+1].H] = Max(dp[i+1][j+node[i+1].H], dp[i][j]-(node[i+1].T-node[i].T));//���� 
				dp[i+1][j] = Max(dp[i+1][j], dp[i][j]-(node[i+1].T-node[i].T)+node[i+1].F);  //�� 
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
