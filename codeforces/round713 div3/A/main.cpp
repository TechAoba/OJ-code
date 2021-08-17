#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main() {
    int T, N, ans, t, A[105];
    cin>>T;
    while(T--) {
        cin>>N;
        for(int i=0;i<N;i++) {
            scanf("%d", &A[i]);
        }
        for(int i=1;i<N;i++) {
            if(A[i] != A[i-1]) {
                if(i-2>=0) {
                    if(A[i] == A[i-2]) printf("%d\n", i);
                    else printf("%d\n", i+1);
                    break;
                }
                else {
                    if(A[i] == A[i+1]) printf("%d\n", i);
                    else printf("%d\n", i+1);
                    break;
                }
            }
        }
    }
    return 0;
}
