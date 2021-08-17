#include <iostream>
#include<cstring>
using namespace std;
const int MAXN = 505;
int matri[MAXN][MAXN], n;

int main() {
    memset(matri, -1, sizeof (matri));
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &matri[i][i]);
    for(int i=1;i<n;i++) {
        for(int c = 1;c<=n-i+1;c++) {
            int r = c+i-1;
            if(matri[r][c]<=i) continue;
            // to left
            if(c>1 && matri[r][c-1] == -1) matri[r][c-1] = matri[r][c];
            else { // to down
                matri[r+1][c] = matri[r][c];
            }
        }
    }
    for(int r = 1;r<=n;r++) {
        for(int c = 1;c<=r;c++) printf("%d ", matri[r][c]);
        putchar('\n');
    }
    return 0;
}
