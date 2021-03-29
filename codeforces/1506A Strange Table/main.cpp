#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
    ll R, C, r, c, val;
    int T;
    cin>>T;
    while(T--) {
        cin>>R>>C>>val;
        c = (val - 1)/R + 1;
        r = (val - 1)%R;
        //cout<<"r="<<r<<" c="<<c<<endl;
        cout<<r*C + c<<endl;
    }
    return 0;
}
