#include <iostream>
#define ll long long
const int MAXN = 2e5+10;
using namespace std;

void solve() {
    int w, h, n;
    scanf("%d %d %d", &w, &h, &n);
    ll ans = 1;
    while(w%2==0) {
        ans *=2;
        w>>=1;
    }
    while(h%2==0) {
        ans *=2;
        h>>=1;
    }
    if(ans>=n) printf("YES\n");
    else printf("NO\n");
}

int main() {
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
