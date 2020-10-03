#include<iostream>
#include<vector>
#define Max(a,b) (a>b?a:b)
#include<iostream>
using namespace std;
const int maxn = 10000+100;
int dp[maxn], N, K;
bool vis[maxn];

int main()
{
	int i, st, tim;
	cin>>N>>K;
	vector<int> V[N+1];
	for(i=0;i<K;i++) {
		cin>>st>>tim;
		vis[st] = true;
		V[st].push_back(st+tim);
	}
	for(i=N;i>=1;i--) {
		if(!vis[i]) dp[i] = dp[i+1]+1;
		else {
			int Tmax = -1;
			for(int j=0;j<V[i].size();j++) {
				Tmax = Max(Tmax, dp[V[i][j]]);
			}
			dp[i] = Tmax;
		}
	}
	//for(i=1;i<=N;i++) cout<<i<<"  "<<dp[i]<<endl;
	cout<<dp[1];
	return 0;
}
