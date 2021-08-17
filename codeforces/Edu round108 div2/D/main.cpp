#include <iostream>
#define ll long long
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
using namespace std;
const int MAXN = 5005;
int n;
ll dp[MAXN][MAXN], A[MAXN], B[MAXN];

void solve() {
    ll ans = 0;
    for(int i=1;i<=n;i++) scanf("%lld", &A[i]);
    for(int i=1;i<=n;i++) {
        scanf("%lld", &B[i]);
        ans += A[i] * B[i];
    }
    if(n==1) {
        printf("%lld\n", ans);
        return;
    }
    ll sum = ans;
    for(int i=1;i<=n;i++) dp[i][i] = ans;
    for(int i=n-1;i>=1;i--) {
        dp[i][i+1] = sum - A[i]*B[i]-A[i+1]*B[i+1] + A[i]*B[i+1] + A[i+1]*B[i];
        ans = max(ans, dp[i][i+1]);
    }
    for(int interval = 2;interval<n;interval++) {
        for(int l = 1;l+interval<=n;l++) {
            int r = l+interval;
            dp[l][r] = dp[l+1][r-1] - A[l]*B[l]-A[r]*B[r] + A[l]*B[r] + A[r]*B[l];
            ans = max(ans, dp[l][r]);
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &n);
    solve();
    return 0;
}