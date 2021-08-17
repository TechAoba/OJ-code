#include <iostream>
using namespace std;
int nums[2005];

void solve() {
    int xorNum = 0, n;
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &nums[i]);
        xorNum ^= nums[i];
    }
    if(xorNum == 0) {
        printf("YES\n");
        return;
    }
    int newxor = 0;
    if(n>=3) {
        for(int i=0;i<n-2;i++) {
            newxor ^= nums[i];
            if(newxor == xorNum) {
                int xor1 = 0;
                for(int j = i+1;j<n-1;j++) {
                    xor1 ^= nums[j];
                    if(xor1 == newxor) {
                        printf("YES\n");
                        return;
                    }
                }
            }
        }
    }
    printf("NO\n");
}

int main() {
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}
