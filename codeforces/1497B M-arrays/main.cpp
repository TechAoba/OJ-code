#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
int num[MAXN];

void solve() {
    int N, M, a;
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++) {
        scanf("%d", &a);
        num[a % M] ++;
    }
    int ans = 0;
    if(num[0]) ans ++;
    for(int i=1;i<=(M>>1);i++) {
        int j = M-i;
        if(i == j) {
            if(num[i]) ans ++;
        }
        else {
            if(num[i]==0 || num[j]==0) ans += max(num[i], num[j]);
            else {
                ans ++;
                ans += num[i] + num[j] - 2*min(num[i], num[j]);
                if(num[i] != num[j]) ans --;
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        memset(num, 0, sizeof(num));
        solve();
    }
    return 0;
}
