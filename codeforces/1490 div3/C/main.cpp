#include <iostream>
#include<unordered_set>
#define ll long long
using namespace std;
ll MAXN = 1e12;

unordered_set<ll> Set;

void solve() {
    ll sum;
    scanf("%lld", &sum);
    for(auto val : Set) {
        ll b = sum - val;
        if(Set.count(b)) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main() {
    // cout<<MAXN;
    for(ll i = 1;;i++) {
        ll tmp = i*i*i;
        if(tmp>=MAXN) break;
        Set.insert(tmp);
    }
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
