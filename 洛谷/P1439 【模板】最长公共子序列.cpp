#include<iostream>
#include<cstdio>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define res register int
using namespace std;
const int MAXN = 100000+5;
int N, A[MAXN], B[MAXN], Map[MAXN], dp[MAXN], len=1;

inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

int main()
{
	N = read();
	res i, j;
	for(i=1;i<=N;i++) A[i] = read(), Map[A[i]]=i;
	for(i=1;i<=N;i++) B[i] = read();
	dp[1] = Map[B[1]];
	for(i=2;i<=N;i++) {
		if(Map[B[i]]>dp[len]) dp[++len] = Map[B[i]];
		else {
			int l=1, r=len, mid;
			while(l<r) {
				mid = (l+r)>>1;
				if(dp[mid]>Map[B[i]]) r=mid;
				else l = mid+1;
			}
			dp[l] = Min(dp[l], Map[B[i]]);
		} 
	}
	printf("%d\n", len);
	return 0;
}
