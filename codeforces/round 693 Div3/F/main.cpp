#include <iostream>
#include <algorithm>
#include<cstring>
#include <vector>
#define ll long long
const int MAXN = 2e5+10;
using namespace std;
int n, m, start[3], cnt=0;

bool check(int i, int poi) {
    if(start[poi] > i) return false;
    if(start[1] == start[2]) {
        start[poi] = i+1;
        start[3-poi] = i;
    }
    else {
        if((start[poi]&1) != (i&1)) return false;
        start[1] = start[2] = i+1;
    }
    return true;
}

void solve() {
    scanf("%d %d", &n, &m);
    vector<pair<int,int>> vec;
    int a, b;
    for(int i=0;i<m;i++) {
        scanf("%d %d", &a, &b);
        vec.push_back({b, a});
    }
    if(m&1) {
        printf("NO\n");
        return;
    }
    sort(vec.begin(), vec.end());
    for(int i=0;i<m;i++) {
        if(!check(vec[i].first, vec[i].second)) {
            printf("NO\n");
            return;
        }
        //printf("start[1] = %d start[2] = %d\n", start[1], start[2]);
    }
    printf("YES\n");
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        start[1] = start[2] = 1;
        solve();
    }
    return 0;
}
