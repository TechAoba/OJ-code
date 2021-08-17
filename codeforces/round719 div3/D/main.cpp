#include <iostream>
#include<map>
#define ll long long
using namespace std;
const int MAXN = 2e5+10;
int n, nums[MAXN];

ll getans(int n) {
    ll ans = 1ll * (1 + n) * n / 2;
    return ans;
}

void solve() {
    scanf("%d", &n);
    map<int, int> Map;
    for(int i=1;i<=n;i++) {
        scanf("%d", &nums[i]);
        Map[nums[i] - i]++;
    }
    ll ans = 0;
    for(auto [i, j]:Map) {
        ans+=getans(j-1);
    }
    printf("%lld\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) solve();
    return 0;
}
