#include<iostream>
#include<cstring>
#define Max(a,b) (a>b?a:b)
using namespace std;
int dp[206][205];

int main() 
{
	int R, r, C, c;
	cin>>R>>C;
	for(r=0;r<205;r++) {
		for(c=0;c<205;c++) {
			dp[r][c] = r==0?0:-0x3f3f3f3f;
		}
	}
	for(r=1;r<=R;r++) {
		for(c=1;c<=C;c++) {
			cin>>dp[r][c];
			dp[r][c] += Max(dp[r-1][c-1], Max(dp[r-1][c], dp[r-1][c+1]));
		}
	}
	cout<<Max(dp[R][C/2], Max(dp[R][C/2+2], dp[R][C/2+1]) )<<endl;
	return 0;
}
