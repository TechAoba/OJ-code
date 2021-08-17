#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 5005;
int nums0[MAXN], nums1[MAXN], n, cnt0=0, cnt1=0, val;
int dp[MAXN];

int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%d", &val);
        if(val == 1) nums1[++cnt1] = i;
        else nums0[++cnt0] = i;
    }
    // printf("cnt1 = %d\n", cnt1);
    fill(dp+1, dp+1+n, 0x3f3f3f3f);
    for(int i=1;i<=cnt0;i++) {
        for(int j = min(i, cnt1);j>=1;j--) {
            dp[j] = min(dp[j], dp[j-1] + abs(nums1[j] - nums0[i]));
        }
    }
    printf("%d\n", dp[cnt1]);
    return 0;
}
