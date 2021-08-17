#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e5+10;

ll gcd(ll a, ll b) {
    return a%b==0?b:gcd(b, a%b);
}

inline ll getNum(ll n) {
    ll sum = 0;
    ll temp = n;
    while(temp) {
        sum+=temp%10;
        temp/=10;
    }
    return gcd(sum, n);
}

void solve() {
    ll N;
    cin>>N;
    for(ll i=N;;i++) {
        if(getNum(i) != 1) {
            cout<<i<<endl;
            return;
        }
    }
}

void test() {
    static char *str[] = {"angry", "joyful", "good", "merry"};
    char **ptr[] = {str + 3, str+2, str+1, str}, ***pstr;

    pstr = ptr;
    ++pstr;
    cout<<**pstr+1<<endl;
}

int main() {
    test();
//    int T;
//    cin>>T;
//    while(T--) {
//        solve();
//    }
    return 0;
}