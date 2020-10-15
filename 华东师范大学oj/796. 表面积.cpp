#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 1005;
int n, m, dp[MAXN][MAXN];

struct node{
	int radius, height, sur1, sur2;
	bool operator < (const node& a) const{
		return radius<a.radius;
	}
}nodes[MAXN];

int main()
{
	memset(dp, 0, sizeof(dp));
	cin>>n>>m;
	int i, j, k, ans=0;
	for(i=0;i<n;i++) {
		scanf("%d %d", &nodes[i].radius, &nodes[i].height);
		nodes[i].sur1 = nodes[i].radius*nodes[i].radius;
		nodes[i].sur2 = 2 * nodes[i].radius * nodes[i].height;
	}
	sort(nodes, nodes+n);		// ���ݰ뾶�������� 
	//for(i=0;i<n;i++) cout<<nodes[i].radius<<endl;
	for(i=0;i<n;i++) dp[i][1] = nodes[i].sur1 + nodes[i].sur2;
	for(i=1;i<n;i++) {				// ��i����Ʒ 
		for(j=2;j<=m && j<=i;j++) { // ѡ����j�� 
			for(k=j-2;k<i;k++) {
				dp[i][j] = max(dp[i][j], dp[k][j-1] + nodes[i].sur1);
			}
		}
	}
	for(i=0;i<n;i++) ans = max(ans, dp[i][m]);
	printf("%d\n", ans);
	return 0;
}
