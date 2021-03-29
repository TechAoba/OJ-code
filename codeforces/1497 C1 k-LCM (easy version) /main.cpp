#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin>>N>>K;
    for(int i=3;i<K;i++) cout<<"1 ";
    N-=K-3;
    if(N&1) {
        cout<<"1 "<<N/2<<" "<<N/2<<endl;
    }
    else {
        int tmp = N>>1;
        if(tmp&1) {
            cout<<"2 "<<(N-2)/2<<" "<<(N-2)/2<<endl;
        }
        else {
            cout<<N/2<<" "<<N/4<<" "<<N/4<<endl;
        }
    }
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
