#include <iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 2e5+10;
ll nums[MAXN], maxAdd[MAXN];
int cnt = 0;

void solve() {
    int N, Q, q;
    scanf("%d %d", &N, &Q);
    if(N<0) {
        for(int i=0;i<Q;i++) scanf("%d", &q);
        return;
    }
    ll maxVal = -0x3f3f3f3f, index, sum = 0;
    for(int i=1;i<=N;i++) {
        scanf("%lld", &nums[i]);
        sum += nums[i];
        maxAdd[i] = max()
    }
    ll sum = add[N];
    // printf("\ncnt = %d\n", ++cnt);
    for(int i=0;i<Q;i++) {
        //printf("此时i=%d Q = %d\n", i, Q);
        scanf("%d", &q);
        if(q>maxVal && sum<=0) {
            printf("-1 ");
            continue;
        }
        // 在一轮内完成
        if(q<=maxVal) {
            for(int j=1;j<=N;j++) {
                if(add[j]>=q) {
                    printf("%d ", j-1);
                    break;
                }
            }
        }
        // 不能一次完成
        else {
            ll ans = index - 1;
            q -= maxVal;
            ll circle = q / sum;
            q -= sum * circle;
            ans += circle * N;
            if(q==0) {
                printf("%lld ", ans);
                continue;
            }
            q -= add[N] - add[index];
            ans += N - index;
            for(int j=1;j<=index;j++) {
                q -= nums[j];
                ans ++;
                if(q <= 0) {
                    printf("%lld ", ans);
                    break;
                }
            }
        }
    }
    putchar('\n');
}

int main() {
    int T;
    add[0] = 0;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}