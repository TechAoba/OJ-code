#include<cstring>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 2e5+10;
const int INF = 1e9;
int N;

inline int read() {
    int f = 1, x = 0;
    char ch = getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') f = -1;ch = getchar();}
    while(ch>='0' && ch<='9') x = (x<<1) + (x<<3) + (ch^48), ch = getchar();
    return f * x;
}

void solve() {
    map<int, int> Map;
    scanf("%d", &N);
    int val;
    for(int i=0;i<N;i++) {
        scanf("%d", &val);
        Map[val] ++;
    }
    map<int,int> cntGroup;
    for(auto [x, cnt] : Map) {
        cntGroup[cnt] ++;
    }
    int ans = INF;
    int rightCnt = Map.size();
    for(auto [high, width] : cntGroup) {
        ans = min(ans, N - rightCnt * high);
        rightCnt -= width;
    }
    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
