#include <iostream>
using namespace std;
int nums[55], n;

void solve() {
    cin>>n;
    bool ok = true;
    for(int i=1;i<=n;i++) {
        cin>>nums[i];
        if(i!=nums[i]) ok = false;
    }
    if(ok) {
        printf("0\n");
        return;
    }
    if(nums[1]==1 || nums[n]==n) printf("1\n");
    else if(nums[1]==n && nums[n]==1) printf("3\n");
    else printf("2\n");
}

int main() {
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}
