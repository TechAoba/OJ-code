#include <iostream>
#include<map>
#define ll long long
using namespace std;
const int MAXN = 2e5+10;
int a, b, k;
int male[MAXN], female[MAXN];

void solve() {
    scanf("%d %d %d", &a, &b, &k);
    for(int i=0;i<k;i++) {
        scanf("%d", &male[i]);
    }
    for(int i=0;i<k;i++) {
        scanf("%d", &female[i]);
    }
    map<int,int> Map1, Map2;
    Map1.clear(), Map2.clear();
    for(int i=0;i<k;i++) {
        Map1[male[i]]++;
        Map2[female[i]]++;
    }
    ll ans = 0;
//    printf("male1 = %d, female1 = %d\n", Map1[1], Map2[1]);
    for(int i=0;i<k;i++) {
        ans += k - Map1[male[i]] - Map2[female[i]] + 1;
    }
    printf("%lld\n", ans / 2);
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}
