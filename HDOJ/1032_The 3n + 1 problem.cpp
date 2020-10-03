#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define LL long long
#define Max(a,b) (a>b?a:b)
using namespace std;
const int MAXN = 1000005;
//int A[MAXN], dp[MAXN][21];

/*void Init() {  //处理长度 
	A[1] = 1;
	dp[1][0] = 1;
	for(int i=2;i<=1000000;i++) {
		//printf("%d ", i);
		LL ans=1, now = i;
		while(now != 1)  {
			if(now&1) now = now*3+1;
			else now >>= 1;
			if(now<=1000000 && A[now]) {
				ans += A[now];
				break;
			}
			ans++;
		}
		A[i] = ans;
		dp[i][0] = ans;
	}
}

void RMQ() {
	for(int j=1;j<21;j++) {
		for(int i=1;i+(1<<j)<=1000000;i++) {
			dp[i][j] = Max(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
		}
	}
}

int Query(int a, int b) {
	int q = log2(b-a);
	return Max(dp[a][q], dp[b-(1<<q)+1][q]);
}*/

inline int get(int t) {
	LL now = (LL)t;
	int ans = 1;
	while(now != 1)  {
		if(now&1) now = now*3+1;
		else now >>= 1;
		ans++;
	}
	return ans;
}

int main()
{
	//Init();
	//cout<<1;
	//RMQ();
	int l, r;
	while(scanf("%d %d", &l, &r) != EOF) {
		int ans = 0, Tmin, Tmax;
		if(l>r) Tmin=r, Tmax=l;
		else Tmin=l, Tmax=r;
		//cout<<l<<"  "<<r<<endl;
		for(register int i=Tmin;i<=Tmax;i++) {
			ans = Max(ans, get(i));
		}
		printf("%d %d %d\n", l, r, ans);
	}
	return 0;
}
