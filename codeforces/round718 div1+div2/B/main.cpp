#include <iostream>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 2e9;
int n, m;

void solve() {
    scanf("%d %d", &n, &m);
    deque<int> dq[105];
    int val;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d", &val);
            dq[i].push_back(val);
        }
        sort(dq[i].begin(), dq[i].end());
    }
    vector<int> ans[105];
    for(int i=0;i<m;i++) {
        int minVal = INF, poi = -1;
        for(int j=0;j<n;j++) {
            if(dq[j][0] < minVal) {
                minVal = dq[j][0];
                poi = j;
            }
        }
        for(int j=0;j<n;j++) {
            if(j==poi) {
                ans[j].emplace_back(dq[j][0]);
                dq[j].pop_front();
            }
            else {
                ans[j].emplace_back(dq[j][m-i-1]);
                dq[j].pop_back();
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            printf("%d ", ans[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
