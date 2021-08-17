#include <iostream>
#define ll long long
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int MAXN = 2e5+10;
ll a, b, d;

void solve() {
    scanf("%lld %lld %lld", &a, &b, &d);
    if(a>b) swap(a, b);
    if(a*(1+d) < b) {
        printf("NO\n");
    }
    else printf("YES\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}
