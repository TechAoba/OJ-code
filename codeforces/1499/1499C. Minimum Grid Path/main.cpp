#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2e5+10;
int N;
ll num[MAXN];

void solve() {
    ll ans = N * (num[0] + num[1]);
    ll x = num[0], y = num[1];
    ll sum = x + y;
    ll temp;
    for(int i=2;i<N;i++) {
        sum+=num[i];
        // 奇数
        if(i&1) {
            y = min(y, num[i]);
            temp = sum + (N - 1 - i/2) * y + (N - 1 - i/2) * x;
            ans = min(ans, temp);
        }
        else {
            x = min(x, num[i]);
            temp = sum + (N - i/2) * y + (N - 1 - i/2) * x;
            ans = min(ans, temp);
        }
    }
    cout<<ans<<endl;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        scanf("%d", &N);
        for(int i=0;i<N;i++) {
            scanf("%lld", &num[i]);
        }
        solve();
    }
    return 0;
}
