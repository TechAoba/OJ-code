#include <iostream>
#include <algorithm>
#include<cstring>
#define ll long long
const int MAXN = 2e5+10;
using namespace std;
int nums[MAXN], n;
int dp[MAXN];

void solve() {
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &nums[i]);
    }
    int ans = -1;
    for(int i=n-1;i>=0;i--) {
        dp[i] = nums[i];
        int index = i+nums[i];
        if(index<n) dp[i] += dp[index];
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
}

int main() {
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
