#include <iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e6+10;
int n;
char s[MAXN];

void solve() {
    scanf("%d %s", &n, s);
    int cnt = 0;
    for(int i=0;i<n;i++) if(s[i]=='*') cnt++;
    int left = 0, right = cnt;
    ll ans = 0;
    for(int i=0;i<n;i++) {
        if(s[i]=='.') {
            ans += min(left, right);
        }
        else {
            left++;
            right--;
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
