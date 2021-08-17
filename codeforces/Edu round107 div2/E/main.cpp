#include <iostream>
#include <string>
#define ll long long
using namespace std;
const int mod = 99824435;

ll getMul(ll a, ll N) {
    ll ans = 1;
    while(N) {
        if(N&1) ans = (ans * a) % mod;
        N>>=1;
        a = (a*a) % mod;
    }
    return ans;
}

int main() {
    int R, C;
    scanf("%d %d", &R, &C);
    string a, b;
    cin>>b;
    ll sum = 0;
    ll add = 0;
    if(b[0]=='o') sum++;
    for(int i=1;i<C;i++) {
        if(b[i]=='o') sum++;
        if(b[i]=='o' && b[i-1]=='o') add++;
    }
    for(int j=1;j<R;j++) {
        a = b;
        cin>>b;
        if(b[0]=='o') sum++;
        for(int i=1;i<C;i++) {
            if(b[i]=='o') sum++;
            if(b[i]=='o' && b[i-1]=='o') add++;
        }
        for(int i=0;i<C;i++) if(a[i]=='o' && b[i]=='o') add++;
    }
    cout<<"sum = "<<sum<<" add = "<<add<<endl;
    ll mul = getMul(2, sum-2);
    printf("%lld\n", (add%mod) * mul % mod);
    return 0;
}
