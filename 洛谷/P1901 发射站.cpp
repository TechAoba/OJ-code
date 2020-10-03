#include<iostream>
#include<cstdio>
#define Max(a,b) (a>b?a:b)
using namespace std;
const int MAXN = 1e6+10;
int H[MAXN], V[MAXN], N, ans=0;

int main()
{
	scanf("%d", &N);
	register int i;
	for(i=1;i<=N;i++) scanf("%d %d", &H[i], &V[i]);
	for(i=1;i<=N;i++) {
		int t = 0;
		if(H[i-1]<H[i]) t+=V[i-1];
		if(H[i+1]<H[i]) t+=V[i+1];
		ans = Max(ans, t);
	}
	cout<<ans<<endl;
	return 0;
}
