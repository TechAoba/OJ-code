#include <iostream>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
const int MAXN = 2e5+10;
int r[MAXN];

int main() {
    int T, N, c, r1, c1, r2, c2, cha1, cha2;
    scanf("%d", &T);
    while(T--) {
        vector<pair<int, int>> vec;
        vec.push_back({1, 1});
        int ans = 0;
        scanf("%d", &N);
        for(int i=0;i<N;i++) scanf("%d", &r[i]);
        for(int i=0;i<N;i++) {
            scanf("%d", &c);
            vec.push_back({r[i], c});
        }
        sort(vec.begin(), vec.end());
        for(int i=1;i<=N;i++) {
            r1 = vec[i-1].first, c1 = vec[i-1].second;
            r2 = vec[i].first, c2 = vec[i].second;
            cha1 = r1-c1;
            cha2 = r2-c2;
            if(cha1 == cha2) {
                if(((r1+c1) & 1) == 0) ans += r2 - r1;
            }
            else {
                if(cha1&1) {
                    ans++;
                    cha1+=1;
                }
                ans += (cha2 - cha1) >> 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
