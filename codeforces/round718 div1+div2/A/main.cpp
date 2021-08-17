#include <iostream>
#define ll long long
using namespace std;
ll n;

void solve() {
    cin>>n;
    ll div = n / 2050;
    if(div*2050 != n) {
        printf("-1\n");
        return;
    }
    int ans = 0;
    while(div) {
        ans += div%10;
        div /= 10;
    }
    printf("%d\n", ans);
}

int main() {
    int T;cin>>T;while(T--) solve();
    return 0;
}
