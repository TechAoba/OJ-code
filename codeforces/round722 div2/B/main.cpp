#include <iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e5+10, inf = 1e9;
int nums[MAXN], n;

void solve() {
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &nums[i]);
    sort(nums, nums+n);
    int ans = 0, minVal = -1, interval = inf;
    for(int i=0;i<n;i++) {
        if(nums[i]<=0) {
            ans++;
            if(i>0) interval = min(interval, nums[i] - nums[i-1]);
        }
        else if(minVal<0) minVal = nums[i];
    }
    if(minVal<=interval && minVal>0) ans++;
    printf("%d\n", ans);
}

int main() {
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}
