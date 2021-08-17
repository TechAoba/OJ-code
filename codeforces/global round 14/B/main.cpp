#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include<cmath>
#define lowbit(x) (-x&x)
#include<set>
#define ll long long
using namespace std;
const ll MAXN = 2e5+10, INF = 1e9;
int n, m, nums[MAXN];

bool is(int a) {
    int t = sqrt(a);
    if(t*t == a) return true;
    return false;
}

void solve() {
    scanf("%lld", &n);
    if(n==1 || n&1) {
        printf("NO\n");
        return;
    }
    if(is(n/2) || (n%4==0 && is(n/4))) {
        printf("YES\n");
    }
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