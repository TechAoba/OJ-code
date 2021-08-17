#include <iostream>
#include <algorithm>
#include<cstring>
#include <vector>
#define ll long long
const int MAXN = 2e5+10;
using namespace std;
int n;

void solve() {
    scanf("%d", &n);
    vector<int> odd, even;
    int a;
    for(int i=0;i<n;i++) {
        scanf("%d", &a);
        if(a&1) odd.emplace_back(a);
        else even.emplace_back(a);
    }
    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());
    ll ans = 0;
    int l = 0, r = 0, len1 = even.size(), len2 = odd.size();
    int oper = 0;
    while(l<len1 || r<len2) {
        if(l==len1) {  // 只能选奇数
            if(oper == 1) {
                ans -= odd[r];
            }
            r++;
        }
        else if(r==len2) {  // 只能选偶数
            if(oper == 0) {
                ans += even[l];
            }
            l++;
        }
        else {
            if(oper == 1) { //bob选
                if(even[l] > odd[r]) {
                    l++;
                }
                else {
                    ans -= odd[r++];
                }
            }
            else {  //Alice选
                if(even[l] > odd[r]) {
                    ans += even[l++];
                }
                else {
                    r++;
                }
            }
        }
        oper = 1 - oper;
    }
    if(ans>0) printf("Alice\n");
    else if(ans<0) printf("Bob\n");
    else printf("Tie\n");
}

int main() {
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
