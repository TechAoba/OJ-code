#include <iostream>
#include<algorithm>
#define lowbit(x) (-x&x)
#define ll long long
using namespace std;


int main() {
    int T;
    ll n;
    cin>>T;
    while(T--) {
        cin>>n;
        if(lowbit(n) == n) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
