#include <iostream>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
const int MAXN = 3e5+10;
int poi[55];

void solve() {
    int N, Q, a, q;
    scanf("%d %d", &N, &Q);
    for(int i=1;i<=N;i++) {
        scanf("%d", &a);
        if(poi[a]==-1) poi[a] = i;
    }
    for(int i=0;i<Q;i++) {
        scanf("%d", &q);
        printf("%d ", poi[q]);
        for(int i=1;i<=50;i++) {
            if(i!=q && poi[i] < poi[q]) poi[i]++;
        }
        poi[q] = 1;
    }
    printf("\n");
}

int main() {
    int T;
        memset(poi, -1, sizeof (poi));
        solve();
    return 0;
}
