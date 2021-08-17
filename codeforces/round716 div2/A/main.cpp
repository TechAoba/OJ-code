#include <iostream>
#include<cstring>
#include <algorithm>
#include<set>
#define ll long long
using namespace std;
const int INF = 2e9;
const int MAXN = 2e5+10;
int n, val;

set<int> perfec;
void solve() {
    cin>>n;
    bool ans = true;
    for(int i=0;i<n;i++) {
        scanf("%d", &val);
        if(!perfec.count(val)) ans = false;
    }
    if(ans) printf("NO\n");
    else printf("YES\n");
}

int main() {
    int T;
    for(int i=1;i*i<=10000;i++) {
        perfec.insert(i*i);
    }
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
