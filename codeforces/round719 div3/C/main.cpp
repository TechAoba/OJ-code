#include <iostream>
using namespace std;
int n;
int ans[105][105];

void solve() {
    cin>>n;
    if (n == 1) {
        cout << "1" << endl;
        return;
    }
    if (n == 2) {
        cout << "-1" << endl;
        return;
    }
    int idx = 1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if((i+j)&1) ans[i][j] = idx++;
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(((i+j)&1) == 0) ans[i][j] = idx++;
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            printf("%d ", ans[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}
