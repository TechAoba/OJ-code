#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
#define ll long long
using namespace std;
int N, M;
vector<int> ans;
const ll DIV = 1e5;

// the long version of ceil
inline ll lceil(ll a, ll b) {
    return (a + b - 1) / b;
}

void print() {
    printf("%d", ans[1]);
    for(int i=2;i<=M;i++) printf(" %d", ans[i]);
    putchar('\n');
}

int main() {
    scanf("%d %d", &N, &M);
    ans.resize(M + 1, -1);
    ans[0] = 0;
    vector<tuple<int, ll, int> > data;
    data.emplace_back(0, 0, 0);
    int t1, y1;
    ll x1;
    for(int i=1;i<=N;i++) {
        scanf("%d %lld %d", &t1, &x1, &y1);
        data.emplace_back(t1, x1, y1);
    }
    // pair记录（当前时间， 微波炉的香蕉个数）
    queue<pair<int, ll> > que;
    que.push({0, 0});

    while(!que.empty()) {
        auto [now, num] = que.front();
        // printf("当前第%d步操作,有%d根香蕉\n", now, num);
        que.pop();
        now++;
        if(now > N) break;
        int t = get<0>(data[now]);
        ll x = get<1>(data[now]);
        int y = get<2>(data[now]);
        auto oper = [&] (ll &val) {
            if(t == 1) {
                val += lceil(x, DIV);
            }
            else {
                val = lceil(val * x, DIV);
            }
        };
        que.push({now, num});
        for(int i=1;i<=y;i++) {
            oper(num);
            if(num>M) break;
            if(ans[num] != -1) break;     // the key to AC!
            ans[num] = now;
            que.push({now, num});
        }
    }

    print();
    return 0;
}
