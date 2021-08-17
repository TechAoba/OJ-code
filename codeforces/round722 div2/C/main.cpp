#include <iostream>
#include <vector>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
const int MAXN = 1e5+10;
ll n, choice[MAXN][2], dp[MAXN][2];
vector<int> edge[MAXN];

void dfs(int u, int p = -1) {
    dp[u][0] = dp[u][1] = 0;
    for(auto& v:edge[u]) {
        if(v==p) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0] + abs(choice[u][0]-choice[v][0]), dp[v][1] + abs(choice[u][0]-choice[v][1]));
        dp[u][1] += max(dp[v][0] + abs(choice[u][1]-choice[v][0]), dp[v][1] + abs(choice[u][1]-choice[v][1]));
    }
}

void solve() {
    scanf("%lld", &n);
    fill(edge+1, edge+1+n, vector<int>());
    int a, b;
    for(int i=1;i<=n;i++) scanf("%lld %lld", &choice[i][0], &choice[i][1]);
    for(int i=1;i<n;i++) {
        scanf("%d %d", &a, &b);
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);
    }
    dfs(1);
    printf("%lld\n", max(dp[1][0], dp[1][1]));
}

int main() {
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}
