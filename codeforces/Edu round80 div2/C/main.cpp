#include <iostream>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll mod = 1e9+7;
int n, m;
ll dp[22][1002];

void solve() {
    cin>>n>>m;
    m*=2;
    for(int i=1;i<=n;i++) dp[1][i] = 1;
    for(int i=2;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            for(int k=1;k<=j;k++) {
                dp[i][j] = (dp[i][j] + dp[i-1][k]) % mod;
            }
            // printf("dp[%d][%d] = %lld\n", i, j, dp[i][j]);
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++) ans = (ans + dp[m][i]) % mod;
    printf("%lld\n", ans);
}

int main() {
    memset(dp, 0, sizeof (dp));
    solve();
    return 0;
}
