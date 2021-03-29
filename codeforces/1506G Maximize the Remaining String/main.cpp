#include<bits/stdc++.h>

using namespace std;
const int MAXN = 2e5+5;

int getCnt(string s) {
    sort(s.begin(), s.end());
    return unique(s.begin(), s.end()) - s.begin();
}

string filter(string &s, char ch) {
    bool first = false;
    string ans = "";
    for(char c:s) {
        if(first && c != ch) ans += c;
        else if(c == ch) first = true;
    }
    return ans;
}

void solve() {
    string s;
    cin>>s;
    int cnt = getCnt(s);
    //从大到小排的set
    set<char, greater<char>> charSet(s.begin(), s.end());
    string ans = "";
    while(cnt) {
        char ch = -1;
        bool find = false;
        for(char c:charSet) {
            if(getCnt(filter(s, c)) == cnt - 1) {
                ch = c;
                find = true;
                break;
            }
        }
        ans += ch;
        s = filter(s, ch);
        charSet.erase(ch);
        cnt--;
    }
    cout<<ans<<endl;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
