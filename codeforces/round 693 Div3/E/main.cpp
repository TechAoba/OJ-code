#include <iostream>
#include <algorithm>
#include<cstring>
#include <vector>
#define ll long long
const int MAXN = 2e5+10;
const int INF = 2e9;
using namespace std;
int n, ans[MAXN], nextIdx[MAXN];

struct Node{
    int w, h, idx;
    Node(int w, int h, int idx):w(w),h(h),idx(idx){}
    bool operator< (const Node& a)const{
        return a.w == w ? h>a.h : w<a.w;
    }
};

void solve() {
    scanf("%d", &n);
    int a, b;
    vector<Node> vec;
    for(int i=1;i<=n;i++) {
        scanf("%d %d", &a, &b);
        if(a>b) swap(a, b);
        vec.push_back(Node(a, b, i));
    }
    sort(vec.begin(), vec.end());
    int minH = INF, minIndex = -1;
    for(int i=0;i<n;i++) {
        int h = vec[i].h;
        int id = vec[i].idx;
        if(h>minH) {
            ans[id] = minIndex;
        }
        else if(h<minH) {
            minH = h;
            minIndex = id;
        }
    }
    for(int i=1;i<=n;i++) printf("%d ", ans[i]);
    putchar('\n');
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        memset(ans, - 1, sizeof(ans));
        solve();
    }
    return 0;
}
