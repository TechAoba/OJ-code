#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
int num[MAXN];

void solve() {
    int N, maxVal;
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d", &num[i]);
        maxVal = max(maxVal, num[i]);
    }
    int add=0, sub=0;
    bool haveZero = false;
    for(int i=1;i<N;i++) {
        if(num[i] == num[i-1]) {
            if(add || sub) {
                printf("-1\n");
                return;
            }
            haveZero = true;
        }
        else if(num[i]>num[i-1]) {
            if(haveZero || add!=0 && add!=num[i] - num[i-1]) {
                printf("-1\n");
                return;
            }
            add = num[i] - num[i-1];
        }
        else {
            if(haveZero || sub!=0 && sub!=num[i] - num[i-1]) {
                printf("-1\n");
                return;
            }
            sub = num[i] - num[i-1];
        }
    }
    if(!sub || !add) {
        printf("0\n");
        return;
    }
    if(add-sub <= maxVal) {
        printf("-1\n");
        return;
    }
    printf("%d %d\n", add-sub, add);
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
