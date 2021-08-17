#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int nums[MAXN], ans[MAXN], N;

void dfs(int left, int right, int deep) {
    if(left>right) return;
    if(left==right) {
        ans[left] = deep;
        return;
    }
    int maxVal=-1, index = -1;
    for(int i=left;i<=right;i++) {
        if(nums[i]>maxVal) {
            maxVal = nums[i];
            index = i;
        }
    }
    ans[index] = deep;
    dfs(left, index - 1, deep + 1);
    dfs(index+1, right, deep+1);
}

void solve() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++) scanf("%d", &nums[i]);
    dfs(1, N, 0);
    for(int i=1;i<=N;i++) printf("%d ", ans[i]);
    putchar('\n');
}

int main() {
    int T;
    cin>>T;
    while (T--) {
        solve();
    }
    return 0;
}
