#include <iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#define ll long long
using namespace std;
const int MAXN = 2e5+10;
const int mod = 1e9+7;
int num[MAXN];
ll fac[MAXN];

void solve() {
    int N, maxVal = -1;
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d", &num[i]);
        maxVal = max(maxVal, num[i]);
    }
    int wei;
    if(maxVal==0) wei = 1;
    else wei = log2(maxVal)+1;
    // cout<<"wei = "<<wei<<endl;
    vector<int> pan;
    for(int i=0;i<wei;i++) {
        int cntZero = 0;
        int yu = 1<<i;
        // cout<<"与"<<yu<<"与"<<endl;
        for(int j=0;j<N;j++) {
            if(!(num[j] & yu)) cntZero++;
        }
        // cout<<"zero="<<cntZero<<endl;
        if(cntZero==1) {
            printf("0\n");
            return;
        }
        if(cntZero>1) pan.emplace_back(i);
    }
    if(pan.size()==0) {
        printf("%lld\n", fac[N]);
    }
    else {
        ll candi = 0;
        int yu;
        int llll = pan.size();
        for(int i=0;i<N;i++) {
            bool ok = true;
            for(int j=0;j<llll;j++) {
                yu = 1<<pan[j];
                if(num[i] & yu) {
                    ok = false;
                    break;
                }
            }
            if(ok) candi++;
        }
        ll ans = (candi * (candi-1));
        ans = (ans * fac[N-2]) % mod;
        printf("%lld\n", ans);
    }
}

int main() {
    fac[0] = 1;
    for(int i=1;i<MAXN;i++) {
        fac[i] = i*fac[i-1]%mod;
    }
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}
