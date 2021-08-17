#include <iostream>
#include <cmath>
using namespace std;
int n, val;

void solve() {
    scanf("%d", &n);
    int minVal = 2e9, idx = -1;
    for(int i=1;i<=n;i++) {
        scanf("%d", &val);
        if(val<minVal) {
            idx = i;
            minVal = val;
        }
    }
    cout<<n-1<<endl;
    for(int i=1;i<=n;i++) {
        if(i==idx) continue;
        printf("%d %d %d %d\n", i, idx, minVal+abs(i-idx), minVal);
    }
}

int main() {
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
