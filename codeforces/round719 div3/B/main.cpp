#include <iostream>
#define ll long long
using namespace std;
ll n;

void solve() {
    cin>>n;
    ll ans = 0;
    for(ll i=1;i<10;i++) {
        ll tmp = i;
        while(tmp<=n) {
            ans++;
            tmp = 10*tmp + i;
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}
