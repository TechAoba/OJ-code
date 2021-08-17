#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN = 2e5+10;
int n, val;
int dp[MAXN], cnt[MAXN];

void solve() {
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &val);
        cnt[val]++;
    }
    for(int i=1;i<MAXN;i++) {
        dp[i] += cnt[i];
        for(int j=i*2;j<MAXN;j+=i) {
            dp[j] = max(dp[j], dp[i]);
        }
    }
    printf("%d\n", n - *max_element(dp, dp+MAXN));
}


int main() {
    int T;
    cin>>T;
    while(T--) {
        memset(dp, 0, sizeof (dp));
        memset(cnt, 0, sizeof (cnt));
        solve();
    }
    return 0;
}
