#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1005;
ll mod = 1e9+7;
ll dp[MAXN][MAXN][2];
int n, tim;

ll solve(int cur, int t, int dir) {
    if(t == 1) return 1;

    if(dp[cur][t][dir] != -1) return dp[cur][t][dir];
    int ans = 2;  // me and relection

    if(dir == 1) {          // toward to right
        if(cur < n) {       // go ahead to the right
            ans += solve(cur + 1, t, 1) - 1;
        }
        ans %= mod;
        if(cur > 1) {         // there is a relection to the left
            ans += solve(cur - 1, t - 1, 0) - 1;
        }
        ans %= mod;
    }
    else {                  //toward to left
        if(cur > 1) {       // go ahead to the left
            ans += solve(cur - 1, t, 0) - 1;
        }
        ans %= mod;
        if(cur < n) {         // there is a relection to the right
            ans += solve(cur + 1, t - 1, 1) - 1;
        }
        ans %= mod;
    }
    return dp[cur][t][dir] = ans;
}

int main() {

    int T;
    cin>>T;
    while(T--) {
        memset(dp, -1, sizeof (dp));
        scanf("%d %d", &n, &tim);
        cout<<solve(1, tim, 1)<<endl;
    }
    return 0;
}
