#include <iostream>
#define ll long long
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
using namespace std;
const int MAXN = 2e5+10;
int n, school[MAXN];


void solve() {
    scanf("%d", &n);
    ll sco;
    vector<ll> skill[n+1];
    for(int i=1;i<=n;i++) scanf("%d", &school[i]);
    for(int i=1;i<=n;i++) {
        scanf("%lld", &sco);
        skill[school[i]].emplace_back(sco);
    }
    for(int i=1;i<=n;i++) sort(skill[i].rbegin(), skill[i].rend());
    vector<vector<ll>> sum(n+1);
    for(int i=1;i<=n;i++) {
        ll tmp = 0;
        for(int j=0;j<skill[i].size();j++) {
            tmp += skill[i][j];
            sum[i].emplace_back(tmp);
        }
    }
    vector<pair<int, int>> ord(n+1);
    for(int i=1;i<=n;i++) {
        ord.push_back({sum[i].size(), i});
    }
    sort(ord.rbegin(), ord.rend());
    for(int k = 1;k<=n;k++) {
        ll ans = 0;
        for(int j=0;j<n;j++) {
            int i = ord[j].second;
            int pre = (sum[i].size()/k) * k;
            if(pre>0) ans += sum[i][pre-1];
            else break;
        }
        printf("%lld ", ans);
    }
    putchar('\n');
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}

