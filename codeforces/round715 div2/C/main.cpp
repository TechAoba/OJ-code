#include <iostream>
#include <cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 2005;
ll dp[MAXN][MAXN], speed[MAXN];

int main() {
    int n, r;
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%lld", &speed[i]);
    sort(speed+1, speed+1+n);
    // for(int i=1;i<=n;i++) dp[i][i] = speed[i];
    for(int j=2;j<=n;j++) {
        for(int l=n-j+1;l>=1;l--) {
            r = l + j - 1;
            dp[l][r] = min(dp[l+1][r], dp[l][r-1]) + speed[r] - speed[l];
            // printf("l=%d, r=%d, dp=%lld\n", l, r, dp[l][r]);
        }
    }
    printf("%lld\n", dp[1][n]);
    return 0;
}
