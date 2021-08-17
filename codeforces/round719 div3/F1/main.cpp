#include <iostream>
using namespace std;
int n, t, k;

void solve(int l, int r, int k) {
    if(l==r) {
        printf("! %d\n", l);fflush(stdout);
        return;
    }
    int mid = (l+r)>>1, sum;
    printf("? %d %d\n", l, mid);fflush(stdout);
    cin>>sum;
    if((mid - l + 1) - sum < k) {
        solve(mid+1, r, k - (mid - l + 1) + sum);
    }
    else {
        solve(l, mid, k);
    }
}

int main() {
    cin>>n>>t>>k;
    solve(1, n, k);
    return 0;
}
