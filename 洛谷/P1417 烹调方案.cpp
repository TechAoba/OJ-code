#include<iostream>
#include<cstring>
#include<algorithm>
#define Max(a,b) (a>b?a:b)
#define LL long long
using namespace std;
const int MAXN = 100005;
LL dp[MAXN], ans=-1;

struct Node{
	LL a, b, c;
}node[55];

bool cmp(Node q, Node w) {
	return q.c * w.b < w.c * q.b;
}

int main()
{
	memset(dp,0,sizeof(dp));
	int T, N, i, j;
	cin>>T>>N;
	for(i=1;i<=N;i++)  cin>>node[i].a;
	for(i=1;i<=N;i++)  cin>>node[i].b;
	for(i=1;i<=N;i++)  cin>>node[i].c;
	sort(node+1, node+N+1, cmp);
	for(i=1;i<=N;i++) {
		for(j=T;j>=node[i].c;j--) {
			dp[j] = Max(dp[j], dp[j-node[i].c]+node[i].a-j*node[i].b);
		}
	}
	for(i=1;i<=T;i++) {
		ans = Max(ans, dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
