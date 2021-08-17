#include <iostream>
#include<algorithm>
#include<cstring>
#define lowbit(x) (-x&x)
using namespace std;
const int MAXN = 2e5+10;
const int INF = 2e6;
bool dp[MAXN];
int nums[MAXN], n;

void solve1() {  // use gcd
    int gcdNum = 0;
    for(int i=0;i<n;i++) gcdNum = __gcd(gcdNum, nums[i]);
    for(int i=0;i<n;i++) nums[i] /= gcdNum;
    for(int i=0;i<n;i++) {
        if(nums[i]&1) {
            printf("1\n%d\n", i+1);
            break;
        }
    }
}

void solve2() { // use lowbit
    int poi = n+1, minVal = INF;
    for(int i=0;i<n;i++) {
        if(lowbit(nums[i]) < minVal) {
            poi = i+1;
            minVal = lowbit(nums[i]);
        }
    }
    printf("1\n%d\n", poi);
}

int main() {
    int sum = 0;
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &nums[i]);
        sum += nums[i];
    }
    if(sum&1) {
        printf("0\n");
        return 0;
    }
    int target = sum >> 1;
    memset(dp, false, sizeof (dp));
    dp[0] = true;
    for(int i=0;i<n;i++) {
        for(int j=target;j>=nums[i];j--) {
            if(dp[j-nums[i]]) dp[j] = true;
        }
    }
    if(!dp[target]) {
        printf("0\n");
        return 0;
    }
    // solve1();
    solve2();
    return 0;
}
