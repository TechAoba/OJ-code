#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1048580;
int N, M, num[MAXN];

void solve() {
    int ans = 1;
    int use = 0;
    while(N--) {
        bool flag = false;
        for(int i=19;i>=0;i--) {
            int width = 1<<i;
            if(!num[width] || use+width>M) continue;
            use += width;
            num[width]--;
            flag = true;
            // cout<<"第"<<ans<<"层使用"<<width<<endl;
            break;
        }
        if(!flag) {
            ans ++;
            use = 0;
            N++;
        }
    }
    cout<<ans<<endl;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        scanf("%d %d", &N, &M);
        memset(num, 0, sizeof (num));
        int a;
        for(int i=0;i<N;i++) {
            scanf("%d", &a);
            num[a] ++;
        }
        solve();
    }
    return 0;
}