#include <iostream>
#define ll long long
using namespace std;
const int MAXN = 2e5+10;
int num[MAXN];

void solve() {
    int N;
    scanf("%d", &N);
    int ans = 0;
    for(int i=0;i<N;i++) {
        scanf("%d", &num[i]);
        if(num[i]!=2) ans++;
    }
    printf("%d\n", ans);
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
