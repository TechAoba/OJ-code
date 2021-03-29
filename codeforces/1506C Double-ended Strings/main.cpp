#include <bits/stdc++.h>
using namespace std;
const int MAXN = 25;
int dp[MAXN][MAXN];

int main() {
    string a, b;
    int T;
    cin>>T;
    while(T--) {
        memset(dp, 0, sizeof(dp));
        cin>>a>>b;
        int n = a.size();
        int m = b.size();
        int maxLen = 0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(a[i-1]==b[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }
        cout<<m+n-2*maxLen<<endl;
    }
    return 0;
}
