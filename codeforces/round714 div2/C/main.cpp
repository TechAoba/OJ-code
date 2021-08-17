#include <iostream>
#include<cstring>
#define ll long long
using namespace std;
const int mod = 1e9+7;
const int MAXN = 2e5+20;
ll dp[MAXN];

void init() {
    for(int i=1;i<=9;i++) dp[i] = 1;
    dp[10] = 2;
    for(int i=11;i<MAXN;i++) {
        dp[i] = (dp[i-9] + dp[i-10]) % mod;
    }
}

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    ll ans = 0;
    while(n) {
        ans = (ans+dp[m+n%10]);
        n/=10;
    }
    printf("%lld\n", ans%mod);
}

int main() {
    int T;
    scanf("%d", &T);
    init();
    while(T--) {
        solve();
    }
    return 0;
}
