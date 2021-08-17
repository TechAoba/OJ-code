#include <iostream>
#include <map>
#include<vector>
#define ll long long
using namespace std;
const int MAXN = 1e5+10;
int n, nums[MAXN];

void solve() {
    scanf("%d", &n);
    ll ans = 0, sum = 0;
    map<ll,ll> cntMap;
    for(int i=0;i<n;i++) {
        scanf("%d", &nums[i]);
        sum += cntMap[nums[i]];
        cntMap[nums[i]] += i + 1;
        ans += sum;
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
