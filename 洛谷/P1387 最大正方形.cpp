#include<iostream>
#include<cstring>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
using namespace std;
int A[105][105], dp[105][105], R, C;

int main()
{
	memset(dp,0,sizeof(dp));
	int ans = -1;
	int r, c;
	cin>>R>>C;
	for(r=1;r<=R;r++) {
		for(c=1;c<=C;c++) {
			cin>>A[r][c];
			if(A[r][c]) dp[r][c] = Min(Min(dp[r-1][c], dp[r][c-1]), dp[r-1][c-1])+1;
			ans = Max(ans, dp[r][c]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
