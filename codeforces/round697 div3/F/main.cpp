#include <iostream>
using namespace std;
const int MAXN = 1005;
int n;
char arr1[MAXN][MAXN], arr2[MAXN][MAXN];
int xorArr[MAXN][MAXN];

void operR(int r) {
    for(int i=0;i<n;i++) xorArr[r][i] ^= 1;
}
void operC(int c) {
    for(int i=0;i<n;i++) xorArr[i][c] ^= 1;
}

void print() {
    for(int r=0;r<n;r++) {
        for (int c = 0; c < n; ++c) {
            printf("%d ", xorArr[r][c]);
        }
        putchar('\n');
    }
}

void solve() {
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%s", arr1[i]);
    for(int i=0;i<n;i++) scanf("%s", arr2[i]);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            xorArr[i][j] = arr1[i][j]!=arr2[i][j]?1:0;
        }
    }
    for(int c=0;c<n;c++) {
        if(xorArr[0][c] == 1) operC(c);
    }
    //print();
    for(int r=1;r<n;r++) {
        int cnt = 0;
        for(int c=0;c<n;c++) {
            if(xorArr[r][c]==1) cnt++;
        }
        //printf("r=%d, cnt=%d\n", r, cnt);
        if(cnt!=0 && cnt!=n) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

int main() {
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
