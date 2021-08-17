#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define  ll long long
using namespace std;
const int MAXN = 2e5+10;
pair<ll, int> nums[MAXN];
bool ans[MAXN];
int N;

void solve() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++) {
        scanf("%lld", &nums[i].first);
        nums[i].second = i;
    }
    sort(nums+1, nums + N + 1);
    int start = 0;
    ll sum = 0;
    for(int i=1;i<N;i++) {
        sum += nums[i].first;
        if(sum<nums[i+1].first) start = i;
    }

    for(int i=start+1;i<=N;i++) {
        ans[nums[i].second] = true;
    }
    printf("%d\n", N-start);
    for(int i=1;i<=N;i++) {
        if(ans[i]) printf("%d ", i);
    }
    putchar('\n');
}

int main() {
    int T;
    cin>>T;
    while (T--) {
        memset(ans, false, sizeof (ans));
        solve();
    }
    return 0;
}
