#include <iostream>
#define ll long long
using namespace std;
const int MAXN = 2e5+10;
int odd[MAXN], even[MAXN];

void solve() {
    int n, s1=0, s2=0, height;
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &height);
        if(height&1) odd[s1++] = height;
        else even[s2++] = height;
    }
    for(int i=0;i<s1;i++) printf("%d ", odd[i]);
    for(int i=0;i<s2;i++) printf("%d ", even[i]);
    putchar('\n');
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) solve();
    return 0;
}
