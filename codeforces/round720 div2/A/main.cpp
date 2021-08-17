#include <iostream>
#include<cstring>
#define ll long long
using namespace std;

ll a, b;

void solve() {
    cin>>a>>b;
    if(b==1) {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    printf("%lld %lld %lld\n", a, a*b, a*b+a);
}

int main() {
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}
