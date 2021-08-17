#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#define ll long long
using namespace std;
const int MAXN = 2e5+10, INF = 2e9;
int n, m, x, nums[MAXN];
int ans[MAXN];
typedef pair<int,int> node_pair;

void solve() {
    scanf("%d %d %d", &n, &m, &x);
    vector<pair<int, int> > vec;
    for(int i=0;i<n;i++) {
        scanf("%d", &nums[i]);
        vec.push_back({nums[i], i});
    }
    sort(vec.rbegin(), vec.rend());
    priority_queue<node_pair,vector<node_pair>,greater<node_pair> > sum;
    for(int i=1;i<=m;i++) sum.push({0, i});
    int maxVal = -1;
    for(int i=0;i<n;i++) {
        auto pa = sum.top(); sum.pop();
        ans[vec[i].second] = pa.second;
        pa.first += vec[i].first;
        maxVal = max(maxVal, pa.first);
        sum.push(pa);
    }
    int minVal = sum.top().first;
    if(maxVal - minVal<=x) {
        printf("YES\n");
        for(int i=0;i<n;i++) printf("%d ", ans[i]);
    }
    else printf("NO\n");
    putchar('\n');
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        // memset(ans, -1, sizeof (ans));
        solve();
    }
    return 0;
}
