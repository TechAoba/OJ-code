#include <iostream>
#include<cstring>
using namespace std;
int n;
char s[55];

void solve() {
    scanf("%d %s", &n, s);
    int have[26];
    memset(have, false, sizeof (have));
    have[s[0] - 'A'] = true;
    for(int i=1;i<n;i++) {
        if(s[i]!=s[i-1]) {
            if(have[s[i] - 'A']) {
                printf("NO\n");
                return;
            }
            have[s[i] - 'A'] = true;
        }
    }
    printf("YES\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) solve();
    return 0;
}
