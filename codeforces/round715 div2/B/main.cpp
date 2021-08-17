#include <iostream>
using namespace std;
const int MAXN = 1e5+10;
int n;
char s[MAXN];

void solve() {
    scanf("%d %s", &n, s);
    if(s[n-1]=='M') {
        printf("NO\n");
        return;
    }
    int cntM = 0, cntT = 0, now = 0;
    for(int i=0;i<n;i++) {
        if(s[i] == 'T') {
            cntT ++;
            now++;
        }
        else {
            cntM ++;
            now--;
            if(now<0) {
                printf("NO\n");
                return;
            }
        }
    }
    if(cntM * 2 != cntT) {
        printf("NO\n");
        return;
    }
    now = 0;
    for(int i=n-1;i>=0;i--) {
        if(s[i] == 'T') {
            now++;
        }
        else {
            now--;
            if(now<0) {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}
