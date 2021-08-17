#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll num[200005];

void solve() {
    int N;
    unordered_set<ll> Set;
    Set.clear();
    scanf("%d", &N);
    N+=2;
    ll sum = 0;
    for(int i=0;i<N;i++) {
        scanf("%lld", &num[i]);
        sum+=num[i];
        Set.insert(num[i]);
    }
    ll t1, t2;
    bool ok = false;
    for(auto val:Set) {
        ll tmp = sum - val;
        if(!(tmp&1) && Set.count(tmp/2)) {
            t1 = val;
            t2 = tmp/2;
            ok = true;
            break;
        }
    }
    if(!ok) {
        cout<<-1<<endl;
        return;
    }
    int leftArr = -1, rightArr = -1;
    if(t1==t2) {
        int cnt1 = 2;
        for(int i=0;i<N;i++) {
            if(num[i]==t1) {
                cnt1--;
                if(leftArr==-1) leftArr = i;
                else rightArr = i;
                if(!cnt1) break;
            }
        }
        if(cnt1) {
            printf("-1\n");
            return;
        }
    }
    else {
        for(int i=0;i<N;i++) {
            if(num[i]==t1) {
                leftArr = i;
            }
            else if(num[i]==t2) {
                rightArr = i;
            }
        }
    }


    for(int i=0;i<N;i++) {
        if(i!=leftArr && i!= rightArr) printf("%d ", num[i]);
    }
    putchar('\n');
}

int main() {
    int T, N;
    cin>>T;
    while (T--) {
        solve();
    }
    return 0;
}
