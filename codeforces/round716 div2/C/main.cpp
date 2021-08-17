#include <iostream>
#include<cstring>
#include <algorithm>
#include<vector>
#define ll long long
using namespace std;
const int INF = 2e9;
const int MAXN = 1e5+10;
int n;
bool vis[MAXN];

int gcd(int a, int b) {
    return a%b==0?b:gcd(b, a%b);
}

bool isPrime_usual(int x)
{
    if(x==1)
        return false;
    for(int i=2; i*i<=x; i++)
        if(x%i==0)
            return false;
    return true;
}

void solve() {
    if(n==2) {
        printf("1\n1\n");
        return;
    }
    if(isPrime_usual(n)) {
        printf("%d\n", n-2);
        for(int i=1;i<n-1;i++) {
            printf("%d ", i);
        }
        printf("\n");
        return;
    }
    ll mul = 1;
    for(int i=2;i<n-1;i++) {
        if(vis[i]) continue;
        if(gcd(i, n) != 1) {
            for(int j=1;j*i<n;j++) vis[i*j] = true;
        }
    }
    int cnt = 0;
    vector<int> ans;
    for(int i=1;i<n-1;i++) {
        if(!vis[i]) {
            cnt++;
            mul = (mul * i) % n;
            ans.push_back(i);
        }
    }
    if(mul != 1) {
        ans.push_back(n-1);
    }
    printf("%d\n", ans.size());
    for(int i=0;i<ans.size();i++) {
        printf("%d ", ans[i]);
    }
}

int main() {
//    for(int i=2;i<50;i++) {
//        memset(dp, 0, sizeof (dp));
//        for(int i=1;i<MAXN;i++) vec[i].clear();
//        printf("i = %d:\n", i);
//        n = i;
//        solve();
//    }
    scanf("%d", &n);
    solve();
    return 0;
}
