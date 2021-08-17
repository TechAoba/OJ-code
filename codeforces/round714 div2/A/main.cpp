#include <iostream>
#include<cstring>
#include<string>
using namespace std;
int N, K;
const int MAXN = 1005;
int num[MAXN];

void solve() {
    cin>>N>>K;
    if(K > (N-1)/2) printf("-1\n");
    else {
        memset(num, -1, sizeof(num));
        int maxVal = N, index = 1;
        for(int i=1;i<=K;i++) {
            num[i*2] = maxVal--;
        }
        for(int i=1;i<=N;i++) {
            while(num[index]!=-1) index++;
            num[index] = i;
        }
        for(int i=1;i<=N;i++) printf("%d ", num[i]);
        printf("\n");
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
