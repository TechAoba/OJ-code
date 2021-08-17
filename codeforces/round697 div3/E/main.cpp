#include <iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
const int MAXN = 1005, mod = 1e9+7;
int n, k, nums[MAXN], C[MAXN][MAXN];

bool cmp(int a, int b) {
    return a>b;
}

void solve() {
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++) scanf("%d", &nums[i]);
    sort(nums, nums+n, cmp);
    vector<int> vec;
    int cnt = 1;
    for(int i=1;i<n;i++) {
        if(nums[i] == nums[i-1]) cnt++;
        else {
            vec.emplace_back(cnt);
            cnt = 1;
        }
    }
    vec.emplace_back(cnt);
    for(int i=0;i<vec.size();i++) {
        if(k>vec[i]) k-=vec[i];
        else {
            printf("%d\n", C[vec[i]][k]);
            return;
        }
    }
}

int main() {
    C[0][0] = 1;
    for(int i=1;i<MAXN;i++) C[i][0] = C[i][i] = 1;
    for(int i=2;i<MAXN;i++) {
        for(int j=1;j<i;j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
        }
    }
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}
