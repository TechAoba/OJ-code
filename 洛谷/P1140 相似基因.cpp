#include<iostream>
#include<string>
#define Max(a,b) (a>b?a:b)
using namespace std;
int A[105], B[105], dp[105][105];

int sc[7][7] = {
	{0, 0, 0, 0, 0, 0},
	{0,5,-1,-2,-1,-3},
	{0,-1,5,-3,-2,-4},
	{0,-2,-3,5,-2,-2},
	{0,-1,-2,-2,5,-1},
	{0,-3,-4,-2,-1,0}
};

int main()
{
	int i, j, l1, l2;
	for(i=1;i<=100;i++)
		for(j=1;j<=100;j++) 
			dp[i][j] = -0x3f3f3f3f;
	string s1, s2;
	cin>>l1>>s1>>l2>>s2;
	for(i=0;i<l1;i++) {
		if(s1[i]=='A') A[i+1]=1;
        if(s1[i]=='C') A[i+1]=2;
        if(s1[i]=='G') A[i+1]=3;
        if(s1[i]=='T') A[i+1]=4;
	}
	for(i=0;i<l2;i++) {
		if(s2[i]=='A') B[i+1]=1;
        if(s2[i]=='C') B[i+1]=2;
        if(s2[i]=='G') B[i+1]=3;
        if(s2[i]=='T') B[i+1]=4;
	}
	for(i=1;i<=l1;i++)
		dp[i][0] = dp[i-1][0] + sc[A[i]][5];
	for(i=1;i<=l2;i++)
		dp[0][i] = dp[0][i-1] + sc[5][B[i]];
	 for(int i=1;i<=l1;i++) {
        for(int j=1;j<=l2;j++) {
            dp[i][j] = Max(dp[i][j], dp[i-1][j] + sc[A[i]][5]);
            dp[i][j] = Max(dp[i][j], dp[i][j-1] + sc[5][B[j]]);
            dp[i][j] = Max(dp[i][j], dp[i-1][j-1] + sc[A[i]][B[j]]);
        }
    }
    cout<<dp[l1][l2]<<endl;
	return 0;
}
