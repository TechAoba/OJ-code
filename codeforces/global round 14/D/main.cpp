#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#define ll long long
using namespace std;
const int MAXN = 2e5+10, INF = 2e9;
int n, l, r;

void solve() {
    scanf("%d %d %d", &n, &l, &r);
    int cha = abs(l-r);
    vector<int> color1(l), color2(r), color3, color4;
    for(int i=0;i<l;i++) {
        scanf("%d", &color1[i]);
    }
    for(int i=0;i<r;i++) {
        scanf("%d", &color2[i]);
    }
    sort(color1.begin(), color1.end());
    sort(color2.begin(), color2.end());
    int i=0, j=0;
    while(i<l&&j<r) {
        if(i<l && color1[i] < color2[j]) {
            while(i<l && color1[i] < color2[j]) color3.emplace_back(color1[i++]);
        }
        else if(j<r && color1[i] > color2[j]) {
            while(j<r && color1[i] > color2[j]) color4.emplace_back(color2[j++]);
        }
        else {
            while(i<l&&j<r && color1[i] == color2[j]) i++, j++;
        }
    }
    while(i<l) color3.emplace_back(color1[i++]);
    while(j<r) color4.emplace_back(color2[j++]);
//    for(int i=0;i<color3.size();i++) printf("%d ", color3[i]); printf("ddd\n");
//    for(int i=0;i<color4.size();i++) printf("%d ", color4[i]); printf("aaa\n");
    int ans = max(color3.size(), color4.size());
    int pai = 0, cnt = 0;
    if(l>r) {
        cnt = 1;
        for(int i=1;i<color3.size();i++) {
            if(color3[i] == color3[i-1]) cnt++;
            else {
                pai += cnt / 2;
                cnt = 1;
            }
        }
        pai += cnt/2;
    }
    else {
        cnt = 1;
        for(int i=1;i<color4.size();i++) {
            if(color4[i] == color4[i-1]) cnt++;
            else {
                pai += cnt / 2;
                cnt = 1;
            }
        }
        pai += cnt/2;
    }
    printf("%d\n", ans - min(cha/2, pai));
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}
