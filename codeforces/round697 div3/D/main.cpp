#include <iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
const int MAXN = 2e5+10;
ll n, m, a[MAXN], b;

void solve() {
    vector<int> score1, score2;
    scanf("%lld %lld", &n, &m);
    ll sum = 0;
    for(int i=0;i<n;i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    for(int i=0;i<n;i++) {
        scanf("%lld", &b);
        if(b==1) {
            score1.emplace_back(a[i]);
        }
        else {
            score2.emplace_back(a[i]);
        }
    }
    if(sum<m) {
        printf("-1\n");
        return;
    }
    sort(score1.rbegin(), score1.rend());
    sort(score2.rbegin(), score2.rend());
    int en1 = score1.size(), en2 = score2.size();
    sum = 0;
    int left = 0, right = 0, need = 0;
    for(;right<en2 && sum<m;right++) {
        sum += score2[right];
        need += 2;
    }
//    printf("right = %d\n", right);
    right--;
    if(sum<m) {  // not enough
        for(;left<en1 && sum<m;left++) {
            sum+=score1[left];
            need += 1;
        }
    }
//    printf("left = %d\n", left);
    int ans = need;
//    printf("need = %d, sum = %lld\n", need, sum);
    for(;right>=0;right--) {
        need -= 2;
        sum -= score2[right];
        while(left<en1 && sum<m) {
            sum += score1[left++];
            need += 1;
        }
        if(sum>=m) {
            ans = min(ans, need);
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
