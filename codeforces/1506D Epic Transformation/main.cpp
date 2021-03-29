#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+10;
int num[MAXN], T, N;
priority_queue<int> que;

void getCnt() {
    int add = 1;
    for(int i=1;i<N;i++) {
        if(num[i] != num[i-1]) {
            que.push(add);
            //cout<<"push "<<add<<endl;
            add = 1;
        }
        else add++;
    }
    que.push(add);
    //cout<<"push "<<add<<endl;
}

bool cmp(int a, int b) {
    return a>b;
}

int main() {
    cin>>T;
    while(T--) {
        while(!que.empty()) que.pop();
        scanf("%d", &N);
        for(int i=0;i<N;i++) {
            scanf("%d", &num[i]);
        }
        sort(num, num+N);
        getCnt();
        int ans = N;
        while(que.size()>=2) {
            int a = que.top();
            //cout<<"a="<<a<<endl;
            que.pop();
            int b = que.top();
            //cout<<"b="<<b<<endl;
            que.pop();
            a--, b--;
            ans -= 2;
            if(a) que.push(a);
            if(b) que.push(b);
        }
        cout<<ans<<endl;
    }
    return 0;
}
