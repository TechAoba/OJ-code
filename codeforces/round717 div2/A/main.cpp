#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 105;
int n, m, nums[MAXN];

void solve() {
   scanf("%d %d", &n, &m);
   for(int i=1;i<=n;i++) scanf("%d", &nums[i]);
   int start = 1;
   while(start<n && m>0) {
       m--;
       while(start<n && nums[start] == 0) start++;
       nums[start]--;
       nums[n]++;
   }
   for(int i=1;i<=n;i++) printf("%d ", nums[i]);
   putchar('\n');
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}
