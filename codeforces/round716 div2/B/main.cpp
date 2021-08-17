#include <iostream>
#include<cstring>
#include <algorithm>
#define ll long long
using namespace std;
const int INF = 2e9;
const int MAXN = 2e5+10;
const int mod = 1e9+7;
ll n, m;

ll myPow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b&1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}

void solve() {
    scanf("%lld %lld", &n, &m);
    printf("%lld\n", myPow(n, m));
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
