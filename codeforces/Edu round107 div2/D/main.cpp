#include <iostream>
#include<string>
#include<cstring>
using namespace std;
int N, k;
int cnt[27][27];

void solve() {
    scanf("%d %d", &N, &k);
    string one = "a";
    char ch;
    for(int i=k-1;i>1;i--) {
        ch = 'a'+i;
        one += ch;
        one += ch;
        one += 'a';
    }
    if(k>1) one += "b";
    int now = 1;
    for(;now<k-1;now++) {
        one += 'a'+now;
        for(int i=k-1;i>now+1;i--) {
            one += 'a' + i;
            one += 'a' + now;
        }
    }
    for(int i=k-1;i>=0;i--) {
        one += 'a' + i;
    }
    string ans = "";
    int len = one.size();
    printf("a");
    N--;
    while(N>=len) {
        ans += one;
        N -= len;
    }
    ans += one.substr(0, N);
    //cout<<one.size()<<endl;
    //cout<<one<<endl;
    cout<<ans<<endl;
//    cout<<one<<endl;
}

int main() {
//    int T;
//    scanf("%d", &T);
//    while(T--) {
        memset(cnt, 0, sizeof (cnt));
        solve();
//    }
    return 0;
}
