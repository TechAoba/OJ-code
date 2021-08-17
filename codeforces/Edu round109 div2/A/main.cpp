#include <iostream>
#include<algorithm>
using namespace std;
int n;

void solve() {
    cin>>n;
    int gcd = __gcd(n, 100);
    printf("%d\n", 100/gcd);
}

int main() {
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}
