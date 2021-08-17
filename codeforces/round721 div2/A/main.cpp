#include <iostream>
#include<cmath>
using namespace std;
int n;

void solve() {
    cin>>n;
    printf("%d\n", (1 << (int)(log2(n))) - 1);
}

int main() {
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}
