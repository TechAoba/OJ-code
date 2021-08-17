#include <iostream>
#define ll long long
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int MAXN = 2e5+10;
int n, m, k, nums[MAXN];

void solve() {
    scanf("%d %d %d", &n, &m, &k);
    int val = n-1 + n*(m-1);
    if(val==k) printf("YES\n");
    else printf("NO\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}
