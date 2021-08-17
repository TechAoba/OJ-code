#include <iostream>
#include<string>
using namespace std;

int main() {
    int T, a, b;
    string s;
    cin>>T;
    while(T--) {
        cin>>a>>b;
        cin>>s;
        int n = s.size();
        if(a+b!=n || (n&1==0) && (a&1)) {
            printf("-1\n");
            continue;
        }
        bool err = false;
        for(int i=0;i<n/2;i++) {
            int j = n-i-1;
            if(s[i]!='?' && s[j]!='?' && s[i]!=s[j]) {
                printf("-1\n");
                err = true;
                break;
            }
            if(s[i]!='?') {
                s[j] = s[i];
            }
            if(s[j]!='?') s[i] = s[j];
        }
        if(err) continue;
        for(int i=0;i<n;i++) {
            if(s[i]=='0') a--;
            else if(s[i]=='1') b--;
        }
        if(a<0 || b<0) {
            printf("-1\n");
            continue;
        }
        for(int i=0;i<n/2;i++) {
            if(s[i]=='?') {
                if(a>1) {
                    a-=2;
                    s[i] = s[n-i-1] = '0';
                }
                else {
                    b-=2;
                    s[i] = s[n-i-1] = '1';
                    if(b<0) {
                        printf("-1\n");
                        err = true;
                        break;
                    }
                }
            }
        }
        if(err) continue;
        if((n&1) && s[n/2]=='?') {
            if(a) s[n/2] = '0';
            else s[n/2] = '1';
        }
        cout<<s<<endl;
    }
    return 0;
}
