#include <iostream>
#include <algorithm>
#define ll long long
const int MAXN = 2e5+10;
using namespace std;
int nums[MAXN], n;

void solve() {
    scanf("%d", &n);
    int sum = 0, cnt_1=0, cnt_2=0;
    for(int i=0;i<n;i++) {
        scanf("%d", &nums[i]);
        sum+=nums[i];
        if(nums[i]==1) cnt_1++;
        else cnt_2++;
    }
    if(sum&1) {
        printf("NO\n");
        return;
    }
    int half = sum>>1;
    half -= min(half>>1, cnt_2) * 2;
    if(half<=cnt_1) printf("YES\n");
    else printf("NO\n");
}

int main() {
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
