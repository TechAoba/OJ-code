#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char s[55];

int main()
{
	while(scanf("%s", s) != EOF) {
		int len = strlen(s);
		int i, ans=1, dp[55];
		dp[0] = 1;
		for(i=1;i<len;i++) {
			if(s[i]==s[i-1]) {
				dp[i] = 1;
			}
			else {
				dp[i] = dp[i-1] + 1;
				ans = max(ans, dp[i]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
