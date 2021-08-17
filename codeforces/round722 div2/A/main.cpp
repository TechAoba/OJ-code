#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;
const int MAXN = 105;
int n, nums[MAXN];

void solve() {
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &nums[i]);
    }
    int k = *min_element(nums, nums+n);
    int cnt = 0;
    for(int i=0;i<n;i++) {
        if(k == nums[i]) cnt++;
    }
    printf("%d\n", n - cnt);
}

int main() {
    int T;
    cin>>T;
    while (T--) {
        solve();
    }
    return 0;
}
