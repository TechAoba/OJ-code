#include <iostream>
#define lowbit(x) (x&-x)
#include<cmath>
using namespace std;
const int MAXN = 1005;
char s[MAXN];
int n;

bool is() {
    bool ok = true;
    for(int i=0;i<n/2;i++) {
        int j = n - i - 1;
        if(s[i] != s[j]) return false;
    }
    return true;
}

void solve1() {
    int cnt0 = 0;
    for(int i=0;i<n;i++) if(s[i]=='0') cnt0++;
    if(cnt0&1) {
        if(cnt0 == 1) printf("BOB\n");
        else printf("ALICE\n");
    }
    else {
        printf("BOB\n");
    }
}

void solve() {
    scanf("%d %s", &n, s);
    if(is()) {
        solve1();
        return;
    }
    int cnt0 = 0, ans = 0;
    for(int i=0;i<n/2;i++) {
        int j = n-i-1;
        if(s[i] != s[j]) {
            ans ++;
        }
        else if(s[i]=='0') {
            cnt0+=2;
        }
    }
    if((n&1) && s[n/2]=='0') cnt0++;
    if(cnt0&1) {
        if(cnt0 == 1) ans--;
        else ans++;
    }
    else if(cnt0>0) {
        ans-=0;
    }
    if(ans>0) printf("ALICE\n");
    else if(ans==0) printf("DRAW\n");
    else printf("BOB\n");
}

int main() {
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
