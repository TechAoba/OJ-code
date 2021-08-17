#include <iostream>
#define ll long long
using namespace std;
ll a, b;

void solve() {
    cin>>a>>b;
    ll tmp = 9, mul = 0;
    while(tmp<=b) {
        mul ++;
        tmp = tmp*10+9;
    }
    ll ans = mul * a;
    printf("%lld\n", ans);
}

int main() {
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
