#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 3e4+10;
int N;

void solve() {
    scanf("%d", &N);
    int avl = N / 3;
    int num, yu;
    vector<int> vec(3, 0);
    for(int i=0;i<N;i++) {
        scanf("%d", &num);
        yu = num%3;
        vec[yu] ++;
    }
    int ans = 0;
    while(*min_element(vec.begin(), vec.end()) != avl) {
        for(int i=0;i<3;i++) {
            if(vec[i] > avl) {
                int add = vec[i] - avl;
                ans += add;
                vec[i] -= add;
                vec[(i+1) % 3] += add;
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
