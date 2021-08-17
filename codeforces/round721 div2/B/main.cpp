#include <iostream>
#define lowbit(x) (x&-x)
#include<cmath>
using namespace std;
const int MAXN = 1005;
char s[MAXN];
int n;

void solve() {
    scanf("%d %s", &n, s);
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

int main() {
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
