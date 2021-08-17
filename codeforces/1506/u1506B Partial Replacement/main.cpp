#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int dp[MAXN];

int main() {
    int Kase, n, k, st, en;
    string s;
    cin>>Kase;
    while(Kase--) {
        cin>>n>>k;
        cin>>s;
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<n;i++) {
            if(s[i] == '*') {
                st = i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--) {
            if(s[i] == '*') {
                en = i;
                break;
            }
        }
        dp[st] = 1;
        for(int i=st+1;i<=en;i++) {
            if(s[i] == '.') continue;
            dp[i] = 0x3f3f3f3f;
            for(int j = max(i-k, st);j<i;j++) {
                if(s[j]=='*') dp[i] = min(dp[i], dp[j] + 1);
            }
            //cout<<i<<" "<<dp[i];
        }
        cout<<dp[en]<<endl;
    }
    return 0;
}
