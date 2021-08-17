#include <iostream>
#include<cmath>
using namespace std;
int n, d;

void solve() {
    cin>>n>>d;
    int en = sqrt(d) + 5;
    if(n>=d) {
        printf("YES\n");
        return;
    }
    for(int i=1;i<en;i++) {
        if(i + ceil(1.0 * d / (i + 1)) <= n) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
