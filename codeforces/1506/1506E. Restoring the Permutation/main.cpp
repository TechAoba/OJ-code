#include <iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 2e5+10;
int num[MAXN];
bool use[MAXN];

int main() {
    int T, N;
    cin>>T;
    while(T--) {
        priority_queue<int> que;
        memset(use, false, sizeof(use));
        scanf("%d", &N);
        for(int i=1;i<=N;i++) scanf("%d", &num[i]);
        int cur = 1;
        // output minimal permutation
        for(int i=1;i<=N;i++) {
            if(num[i] != num[i-1]) {
                printf("%d ", num[i]);
                use[num[i]] = true;
            }
            else {
                while(use[cur]) {
                    cur++;
                }
                printf("%d ", cur++);
            }
        }
        printf("\n");
        // output maximal permutation
//        memset(use, false, sizeof (use));
//        cur = 1;
//        for(int i=1;i<=N;i++) {
//            if(num[i] != num[i-1]) {
//                printf("%d ", num[i]);
//                use[num[i]] = true;
//                cur = num[i] - 1;
//            }
//            else {
//                while(use[cur] && cur>0) {
//                    cur--;
//                }
//                use[cur] = true;
//                printf("%d ", cur--);
//            }
//        }

        cur = 1;
        for(int i=1;i<=N;i++) {
            if(num[i] != num[i-1]) {
                printf("%d ", num[i]);
                while(cur<num[i]) {
                    que.push(cur++);
                }
                cur = num[i] + 1;
            }
            else {
                printf("%d ", que.top());
                que.pop();
            }
        }

        printf("\n");
    }
    return 0;
}
