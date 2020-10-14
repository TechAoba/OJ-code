#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define LL long long
#define Max(a,b) (a>b?a:b)
using namespace std;
const int MAXN = 55;
LL A[MAXN], K1, K, N, ans=0;

int main()
{
	cin>>N>>K1;
	LL i, j, l, r, fang, na;
	for(i=1;i<=N;i++) scanf("%lld", &A[i]);
	for(K=0;K<=K1;K++) {
		for(l=0;l<=K;l++) {
			for(r=0;r<=K-l && l+r<=N;r++) {
				vector<int> V;
				for(i=1;i<=l;i++) V.push_back(A[i]);
				for(j=0;j<r;j++) V.push_back(A[N-j]);
				sort(V.begin(), V.end());
				LL num = 0;
				fang = K-l-r;
				for(i=fang;i<V.size();i++) {
					num+=V[i];
				}
				ans = Max(ans, num);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
