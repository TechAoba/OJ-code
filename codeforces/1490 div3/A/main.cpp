#include <iostream>
#include<algorithm>
using namespace std;
const int MAXN = 55;
int nums[MAXN], N;

void solve() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) scanf("%d", &nums[i]);
    int ans = 0;
    int maxVal, minVal;
    for(int i=0;i<N-1;i++) {
        maxVal = max(nums[i], nums[i+1]);
        minVal = nums[i] + nums[i+1] - maxVal;
        double tmp = 1.0 * maxVal / minVal / 2;
        while(tmp>1.0) {
            ans ++;
            tmp /= 2;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
