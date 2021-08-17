#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#define ll long long
using namespace std;
const int MAXN = 2e5+10, INF = 2e9;
int n, m, nums[MAXN];

void solve() {
    scanf("%d %d", &n, &m);
    int sum = 0, maxVal = 0;
    for(int i=0;i<n;i++) {
        scanf("%d", &nums[i]);
        sum += nums[i];
        maxVal = max(maxVal, nums[i]);
    }
    if(sum == m) {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    int tmp = 0;
    for(int i=0;i<n;i++) {
        if(tmp + nums[i] == m) {
            swap(nums[i], nums[i+1]);
        }
        tmp += nums[i];
        printf("%d ", nums[i]);
    }
    putchar('\n');
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}
