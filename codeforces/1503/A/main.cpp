#include <iostream>
using namespace std;

int main() {
    int T, N;
    cin>>T;
    while(T--) {
        string a = "", b = "", s;
        cin>>N;
        cin>>s;
        bool flag = false;
        int cntA = 0, cntB = 0;
        for(int i=0;i<N;i++) {
            if(s[i] == '1') {
                a += '(';
                b += '(';
                cntA ++;
                cntB ++;
            }
            else {
                if(cntA>cntB) {
                    a += ')';
                    b += '(';
                    cntA--;
                    cntB++;
                    if(cntA<0) {  // error
                        flag = true;
                        break;
                    }
                }
                else {
                    a += '(';
                    b += ')';
                    cntA++;
                    cntB--;
                    if(cntB<0) {  // error
                        flag = true;
                        break;
                    }
                }
            }
        }
        if(flag || cntA!=cntB || (cntA&1)) {
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=N-1;i>=0 && cntB;i--) {
            if(s[i]=='1') {
                a[i] = ')';
                b[i] = ')';
                cntB-=2;
            }
        }
        bool ok = true;
        cntA = 0;
        cntB = 0;
        for(int i=0;i<N;i++) {
            if(a[i]=='(') {
                cntA++;
            }
            else {
                cntA--;
                if(cntA<0) {
                    ok = false;
                    break;
                }
            }
            if(b[i]=='(') {
                cntB++;
            }
            else {
                cntB--;
                if(cntB<0) {
                    ok = false;
                    break;
                }
            }
        }
        if(!cntB && ok) cout<<"YES"<<endl<<a<<endl<<b<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
